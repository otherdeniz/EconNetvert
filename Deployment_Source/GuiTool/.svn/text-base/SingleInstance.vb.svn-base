'=================================
'Deniz Esen
'Econ Dimension GmbH
'http://www.econdimension.com
'd.esen@econdimension.com
'=================================
' You are free to use, change and
' redistribute this class or parts
' of it.
' No Support.
'=================================

Imports System.Windows.Forms
Imports System.Diagnostics
Imports System.Runtime.InteropServices
Imports System.Text
Imports System.Runtime.Serialization.Formatters.Binary
Imports System.IO

#If Win32Only Then
'BEGIN Win32 Only

#Region "SerialHelper CLASS"

Public Class SerialHelper
  Public Shared Function SerializeToBase64String(ByVal o As Object) As String
    Dim formatter As New BinaryFormatter
    Dim serialMemoryStream As New MemoryStream
    formatter.Serialize(serialMemoryStream, o)
    Dim bytes() As Byte = serialMemoryStream.ToArray()
    Return Convert.ToBase64String(bytes).Trim()
  End Function

  Public Shared Function DeserializeFromBase64String(ByVal base64String As String) As Object
    Dim formatter As New BinaryFormatter
    base64String = base64String.Trim(ControlChars.NullChar)
    Dim bytes() As Byte = Convert.FromBase64String(base64String)
    Dim serialMemoryStream As New MemoryStream(bytes)
    Return formatter.Deserialize(serialMemoryStream)
  End Function
End Class

#End Region

'--------------------------------------------------------------------

#Region "SingleInstance CLASS"

Public Class SingleInstance
  Public Interface ISingleInstanceForm
    Delegate Sub _WndProc(ByVal m As Message, ByRef Cancel As Boolean)
    Event WndProc As _WndProc
    ReadOnly Property Handle() As IntPtr
    Sub HandleCommand(ByVal strCmd As String)
    Sub SetToForeground()
  End Interface
#Region "API"
  Private Const WM_COPYDATA As Integer = &H4A

  <StructLayout(LayoutKind.Sequential)> _
  Private Structure COPYDATASTRUCT
    Public dwData As Integer
    Public cbData As Integer
    Public lpData As Integer
  End Structure

  Private Declare Auto Function GetProp Lib "user32" (ByVal hWnd As Integer, ByVal lpString As String) As Integer
  Private Declare Auto Function SetProp Lib "user32" (ByVal hWnd As Integer, ByVal lpString As String, ByVal hData As Integer) As Integer

  Private Delegate Function EnumWindowsProc(ByVal hWnd As Integer, ByVal lParam As Integer) As Integer
  Private Declare Function EnumWindows Lib "user32" (ByVal lpEnumFunc As EnumWindowsProc, ByVal lParam As Integer) As Integer

  Private Declare Auto Function SendMessage Lib "user32" (ByVal hWnd As Integer, ByVal wMsg As Integer, ByVal wParam As Integer, ByVal lParam As IntPtr) As Integer
#End Region

#Region "EnumWindows"
  Private Shared _EWP As New EnumWindowsProc(AddressOf EWP)
  Private Shared Function EWP(ByVal hWnd As Integer, ByVal lParam As Integer) As Integer
    ' Customised windows enumeration procedure.  Stops
    ' when it finds another application with the Window
    ' property set, or when all windows are exhausted.
    Try
      If IsThisApp(hWnd) Then
        _hWnd = hWnd
        Return 0
      Else
        Return 1
      End If
    Catch
      Return 0
    End Try
  End Function
  Private Shared Function IsThisApp(ByVal hWnd As Long) As Boolean
    ' Check if the windows property is set for this
    ' window handle:
    If GetProp(hWnd, _mcThisAppID & "_APPLICATION") = 1 Then
      Return True
    End If
  End Function

  Private Shared Function FindWindow() As Boolean
    If _hWnd = -1 Then
      EnumWindows(_EWP, 0)
      If _hWnd = -1 Then
        Return False
      Else
        Return True
      End If
    Else
      Return True
    End If
  End Function

  Private Shared Function SendCDSToWindow(ByVal CD As COPYDATASTRUCT) As Boolean
    Try
      Dim lpCD As IntPtr = Marshal.AllocHGlobal(Len(CD))
      Marshal.StructureToPtr(CD, lpCD, False)
      SendMessage(_hWnd, WM_COPYDATA, _hWnd, lpCD)
      Marshal.FreeHGlobal(lpCD)

      Return True
    Catch
      Return False
    End Try
  End Function

  Private Shared Function SendMessageToWindow(ByVal strCmd As String) As Boolean
    If _hWnd = -1 Then Return False
    If Len(strCmd) = 0 Then
      Try
        Dim CD As COPYDATASTRUCT
        With CD
          .dwData = 0
          .cbData = 0
          .lpData = 0
        End With
        Return SendCDSToWindow(CD)
      Catch
        Return False
      End Try
    Else
      Try
        Dim B() As Byte = Encoding.Default.GetBytes(strCmd)
        Dim lpB As IntPtr = Marshal.AllocHGlobal(B.Length)
        Marshal.Copy(B, 0, lpB, B.Length)

        Dim CD As COPYDATASTRUCT
        With CD
          .dwData = 0
          .cbData = B.Length
          .lpData = lpB.ToInt32
        End With
        Erase B

        Try
          If SendCDSToWindow(CD) Then
            Return True
          Else
            Return False
          End If
        Catch
          Return False
        Finally
          Marshal.FreeHGlobal(lpB)
        End Try

      Catch
        Return False
      End Try
    End If
  End Function
  Private Shared Function SendMessageToWindow(ByVal oCmd As Object) As Boolean
    Try
      Dim strCmd As String = SerialHelper.SerializeToBase64String(oCmd)
      Return SendMessageToWindow(strCmd)
    Catch
      Return False
    End Try
  End Function
#End Region

  Private Shared _hWnd As Integer = -1
  Private Shared _mcThisAppID As String
  Private Shared oMutex As Threading.Mutex
  Private Shared _MutexOwned As Boolean = False
  Private Shared WithEvents MainForm As ISingleInstanceForm

  Shared Sub New()
    _mcThisAppID = System.Reflection.Assembly.GetExecutingAssembly().FullName
    oMutex = New Threading.Mutex(True, _mcThisAppID & "_APPLICATION_MUTEX", _MutexOwned)
    If Not _MutexOwned Then
      'modified DE
      'try to find window for 5 secs
      _MutexOwned = True
      Dim TmpStart As Date = Now
      Do
        If FindWindow() Then
          'another window found
          _MutexOwned = False
          Exit Do
        End If
        Threading.Thread.Sleep(250)
      Loop While (DateDiff(DateInterval.Second, DateAdd(DateInterval.Second, 5, TmpStart), Now) < 0)
    End If
    AddHandler AppDomain.CurrentDomain.ProcessExit, AddressOf OnExit
  End Sub
  Private Shared Sub OnExit(ByVal sender As Object, ByVal e As EventArgs)
    Try
      If Not oMutex Is Nothing Then
        oMutex.ReleaseMutex()
        CType(oMutex, IDisposable).Dispose()
        oMutex = Nothing
      End If
    Catch
      'Do Nothing
    End Try
  End Sub

  Public Shared ReadOnly Property IsFirstInstance() As Boolean
    Get
      Return _MutexOwned
    End Get
  End Property

  Public Shared Function NotifyPreviousWindow() As Boolean
    Return SendMessageToWindow("")
  End Function
  Public Shared Function NotifyPreviousWindow(ByVal strText As String) As Boolean
    Return SendMessageToWindow(strText)
  End Function
  Public Shared Function NotifyPreviousWindow(ByVal oCmd As Object) As Boolean
    Return SendMessageToWindow(oCmd)
  End Function

  Public Shared Sub SetMainForm(ByVal frm As ISingleInstanceForm)
    MainForm = frm
    Try
      Dim hWnd As Integer = frm.Handle.ToInt32
      SetProp(hWnd, _mcThisAppID & "_APPLICATION", 1)
    Catch
      MainForm = Nothing
    End Try
  End Sub

  Private Shared Sub MainForm_WndProc(ByVal m As System.Windows.Forms.Message, ByRef Cancel As Boolean) Handles MainForm.WndProc
    Select Case m.Msg
      Case WM_COPYDATA
        Dim B() As Byte
        Try
          Dim CD As COPYDATASTRUCT = m.GetLParam(GetType(COPYDATASTRUCT))
          ReDim B(CD.cbData)
          Dim lpData As IntPtr = New IntPtr(CD.lpData)
          Marshal.Copy(lpData, B, 0, CD.cbData)
          Dim strData As String = Encoding.Default.GetString(B)
          MainForm.HandleCommand(strData)
          MainForm.SetToForeground()
          Cancel = True
        Catch
          Cancel = False
        Finally
          Erase B
        End Try

      Case Else
        Cancel = False
    End Select
  End Sub
End Class

#End Region

'END Win32 Only
#Else
  'BEGIN NO-Win32

Public Class SingleInstance

  Public Interface ISingleInstanceForm
    Sub HandleCommand(ByVal strCmd As String)
  End Interface

  'PUBLIC SHARED
  Public Shared ReadOnly Property IsFirstInstance() As Boolean
    Get
      Return True
    End Get
  End Property

  Public Shared Sub SetMainForm(ByVal frm As ISingleInstanceForm)
    'nothing to do
  End Sub

  Public Shared Function NotifyPreviousWindow() As Boolean
    Return True
  End Function

  Public Shared Function NotifyPreviousWindow(ByVal strText As String) As Boolean
    Return True
  End Function

  Public Shared Function NotifyPreviousWindow(ByVal oCmd As Object) As Boolean
    Return True
  End Function

End Class

  'END NO-Win32
#End If
