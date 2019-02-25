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

Imports System.Text
Imports System.IO

Public Class FrmStatus
  Implements SingleInstance.ISingleInstanceForm

  'DECLARATIONS
  Private FTargetRoot As String = ""
  Private FTargetHistory As String = ""
  Private FFileList As New Queue
  Private FFileListHistory As New ArrayList
  Private FHandleKeys As Boolean = False
  Private FProcessing As Boolean = True

#If Win32Only Then
  'BEGIN Win32 Only

  'Win32-API
  Private Declare Function SetForegroundWindow Lib "user32" (ByVal hwnd As Long) As Long
  Private Declare Function SetActiveWindow Lib "user32" Alias "SetActiveWindow" (ByVal hwnd As Long) As Long
  Private Declare Function SetFocus Lib "user32" Alias "SetFocus" (ByVal hwnd As Long) As Long

#Region "SingleInstance Handler"

  Public Event WndProc2(ByVal m As System.Windows.Forms.Message, ByRef Cancel As Boolean) Implements SingleInstance.ISingleInstanceForm.WndProc

  Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message)
    Dim bCancel As Boolean = False
    RaiseEvent WndProc2(m, bCancel)
    Try
      If Not bCancel Then MyBase.WndProc(m)
    Catch ex As Exception
#If DEBUG Then
        Debug.WriteLine("Unhandled Exception: " & ex.Message, "Econ Framework Core")
#End If
    End Try
  End Sub

  Public ReadOnly Property hWnd() As System.IntPtr Implements SingleInstance.ISingleInstanceForm.Handle
    Get
      Return Handle
    End Get
  End Property

  'Public Sub HandleCommand(ByVal strCmd As String) Implements SingleInstance.ISingleInstanceForm.HandleCommand
  '  Dim arrCmd() As String
  '  Try
  '    arrCmd = SerialHelper.DeserializeFromBase64String(strCmd)
  '    HandleCommand(arrCmd)
  '  Catch ex As Exception
  '    MsgBox("Could not handle commandline arguments, Error: " & ex.ToString, MsgBoxStyle.Exclamation, "Error")
  '  Finally
  '    Erase arrCmd
  '  End Try
  'End Sub

  Public Sub SetToForeground() Implements SingleInstance.ISingleInstanceForm.SetToForeground
    Me.Focus()
    'hmmm... not working (why)
    'SetActiveWindow(Me.Handle.ToInt32)
    'SetForegroundWindow(Me.Handle.ToInt32)
    'SetFocus(Me.Handle.ToInt32)
  End Sub

#End Region

  'END Win32 Only
#End If

  'PUBLIC
  Public Overridable Sub HandleCommand(ByVal strArgs As String) Implements SingleInstance.ISingleInstanceForm.HandleCommand
    Dim TmpFile As String

    If strArgs <> "" Then
      TmpFile = strArgs.TrimStart("?"c).TrimEnd(Chr(0))
      ConvertFile(TmpFile)
      'check if conversion is still running
      If Not FProcessing Then
        'choose new destination
        If strArgs.StartsWith("?") Then
          If Not SetDestination(TmpFile.Substring(0, TmpFile.Length - Path.GetFileName(TmpFile).Length - 1)) Then
            'user abort
            Exit Sub
          End If
        End If
        'restart the conversion
        FProcessing = True
        BtnCancel.Text = "Cancel"
        Me.AcceptButton = Nothing
        StartConversion(True)
      End If
    End If
  End Sub

  Public Function SetDestination(ByVal currentFolder As String) As Boolean
    Dim TmpDlg As FolderBrowserDialog
    Dim RetB As Boolean = False

    If FTargetRoot = "" Then
      'ask user
      TmpDlg = New FolderBrowserDialog
      TmpDlg.ShowNewFolderButton = True
      TmpDlg.SelectedPath = currentFolder
      TmpDlg.Description = "Choose destination Path for converted files."
      If TmpDlg.ShowDialog() = Windows.Forms.DialogResult.OK Then
        FTargetRoot = TmpDlg.SelectedPath
        FTargetHistory = FTargetRoot
        RetB = True
      End If
    Else
      'already set
      RetB = True
    End If
    Return RetB
  End Function

  Public Sub ConvertFile(ByVal srcFile As String)
    FFileList.Enqueue(srcFile)
    FFileListHistory.Add(srcFile)
  End Sub

  Public Sub StartConversion(Optional ByVal appendConversion As Boolean = False)
    Dim TmpConvVBCS As CodeFileConverter
    Dim TmpConvCSVB As CodeFileConverter
    Dim TmpProjConvVBCS As VSProjectFileConverter
    Dim TmpProjConvCSVB As VSProjectFileConverter
    Dim TmpAspxConv As ASPXFileConverter
    Dim TmpConv As CodeFileConverter
    Dim TmpProjConv As VSProjectFileConverter
    Dim TmpSrcFile As String
    Dim TmpTargetFile As String
    Dim TmpErrCount As Int32 = 0

    If Not appendConversion Then
      'clear output-TextBox
      TxtStatus.Text = ""
    End If
    OutputMessage("Converting..." & vbCrLf)
    'create all converts
    TmpConvVBCS = New CodeFileConverter(ConverterLanguages.VBNetToCSharp)
    TmpConvCSVB = New CodeFileConverter(ConverterLanguages.CSharpToVBNet)
    TmpProjConvVBCS = New VSProjectFileConverter(ConverterLanguages.VBNetToCSharp)
    TmpProjConvCSVB = New VSProjectFileConverter(ConverterLanguages.CSharpToVBNet)
    TmpAspxConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.Autodetect)
    'add event-handlers
    AddHandler TmpConvVBCS.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
    AddHandler TmpConvCSVB.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
    AddHandler TmpProjConvVBCS.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
    AddHandler TmpProjConvCSVB.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
    AddHandler TmpAspxConv.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
    'wait for all events
    System.Windows.Forms.Application.DoEvents()
    'start execution-loop
    Do While FFileList.Count > 0
      If Not FProcessing Then
        'user-abort
        FTargetRoot = ""
        OutputMessage("--------------------------------------" & vbCrLf)
        OutputMessage("--------------------------------------" & vbCrLf)
        OutputMessage("Abort by user!" & vbCrLf)
        If SettingsManager.AutoCloseStatusDialogs Then
          System.Windows.Forms.Application.DoEvents()
          'wait 2 seconds
          System.Threading.Thread.Sleep(2000)
          End 'Application.Exit()
        Else
          BtnRestart.Visible = True
          BtnCancel.Text = "Close"
          Me.AcceptButton = BtnCancel
          BtnCancel.Focus()
        End If
        Exit Sub
      End If
      'reset previous converter
      TmpConv = Nothing
      TmpProjConv = Nothing
      'get next file of queue
      TmpSrcFile = FFileList.Dequeue
      Select Case Path.GetExtension(TmpSrcFile).ToLower
        Case ".vb"
          TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "cs")
          TmpConv = TmpConvVBCS
          OutputMessage("Converting Codefile '" & Path.GetFileName(TmpSrcFile) & "' from VB.NET to C#..." & vbCrLf)
        Case ".cs"
          TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "vb")
          TmpConv = TmpConvCSVB
          OutputMessage("Converting Codefile '" & Path.GetFileName(TmpSrcFile) & "' from C# to VB.NET..." & vbCrLf)
        Case ".vbproj"
          TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "csproj")
          TmpProjConv = TmpProjConvVBCS
          OutputMessage("Converting Visual Studio Project '" & Path.GetFileName(TmpSrcFile) & "' from VB.NET to C#..." & vbCrLf)
        Case ".csproj"
          TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "vbproj")
          TmpProjConv = TmpProjConvCSVB
          OutputMessage("Converting Visual Studio Project '" & Path.GetFileName(TmpSrcFile) & "' from C# to VB.NET..." & vbCrLf)
        Case ".aspx", ".ascx", "*.asmx"
          TmpTargetFile = TmpSrcFile 'Path.ChangeExtension(TmpSrcFile, "converted" & Path.GetExtension(TmpSrcFile))
          OutputMessage("Converting ASP.NET File '" & Path.GetFileName(TmpSrcFile) & "'..." & vbCrLf)
        Case Else
          'not supported extension
          TmpTargetFile = ""
      End Select
      If TmpTargetFile <> "" Then
        If FTargetRoot <> "" Then
          'set manual destination path
          TmpTargetFile = Path.Combine(FTargetRoot, Path.GetFileName(TmpTargetFile))
        End If
        If TmpTargetFile = TmpSrcFile Then
          'destination equals source, add ".converted" to filename
          TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "converted" & Path.GetExtension(TmpSrcFile))
        End If
        If Not TmpConv Is Nothing Then
          'convert CodeFile
          TmpConv.ConvertFile(TmpSrcFile, TmpTargetFile, True, True)
        ElseIf Not TmpProjConv Is Nothing Then
          'convert VSProject
          TmpProjConv.ConvertProject(TmpSrcFile, TmpTargetFile, True, True)
        Else
          'convert ASPXFile
          TmpAspxConv.ConvertFile(TmpSrcFile, TmpTargetFile, True)
        End If
      End If
      'wait for all events
      System.Windows.Forms.Application.DoEvents()
    Loop
    'conversion finished
    FTargetRoot = ""
    FProcessing = False
    If TmpConvVBCS.TotalFilesCount > 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Summary for Code Files: VB.NET -> C#" & vbCrLf)
      OutputMessage(TmpConvVBCS.SummaryText)
      TmpErrCount += TmpConvVBCS.FailedFilesCount
    End If
    If TmpConvCSVB.TotalFilesCount > 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Summary for Code Files: C# -> VB.NET" & vbCrLf)
      OutputMessage(TmpConvCSVB.SummaryText)
      TmpErrCount += TmpConvCSVB.FailedFilesCount
    End If
    If TmpProjConvVBCS.TotalProjectsCount > 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Summary for VS Projects: VB.NET -> C#" & vbCrLf)
      OutputMessage(TmpProjConvVBCS.SummaryText)
      TmpErrCount += TmpProjConvVBCS.FailedCodeFilesCount
    End If
    If TmpProjConvCSVB.TotalProjectsCount > 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Summary for VS Projects: C# -> VB.NET" & vbCrLf)
      OutputMessage(TmpProjConvCSVB.SummaryText)
      TmpErrCount += TmpProjConvCSVB.FailedCodeFilesCount
    End If
    If TmpAspxConv.TotalFilesCount > 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Summary for ASP.NET Files" & vbCrLf)
      OutputMessage(TmpAspxConv.SummaryText)
      TmpErrCount += TmpAspxConv.FailedFilesCount
    End If
    If TmpErrCount = 0 Then
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("All Conversions Successfull" & vbCrLf)
      If SettingsManager.AutoCloseStatusDialogs Then
        System.Windows.Forms.Application.DoEvents()
        'wait 2 seconds
        System.Threading.Thread.Sleep(2000)
        End 'Application.Exit()
      End If
    Else
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("--------------------------------------" & vbCrLf)
      OutputMessage("Conversionerror in " & TmpErrCount.ToString & " files" & vbCrLf)
      BtnRestart.Visible = True
    End If
    BtnCancel.Text = "Close"
    Me.AcceptButton = BtnCancel
    BtnCancel.Focus()
  End Sub

  'PRIVATE
  Private Sub OutputMessage(ByVal textLine As String)
    TxtStatus.AppendText(textLine)
    TxtStatus.SelectionStart = TxtStatus.Text.Length
    TxtStatus.ScrollToCaret()
    'wait for user mouse-events
    System.Windows.Forms.Application.DoEvents()
  End Sub

  Private Sub OnRestartConversion()
    If FFileListHistory.Count > 0 Then
      For Each s As String In FFileListHistory
        FFileList.Enqueue(s)
      Next
      FTargetRoot = FTargetHistory
      'restart the conversion
      FProcessing = True
      BtnCancel.Text = "Cancel"
      Me.AcceptButton = Nothing
      StartConversion()
    End If
  End Sub

#Region "GUI Events"

  Private Sub Converter_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    Try
      OutputMessage(e.ToString(Directory.GetParent(e.InputFile).FullName, _
                               Directory.GetParent(e.OutputFile).FullName) & vbCrLf)
    Catch ex As Exception
    End Try
  End Sub

  Private Sub BtnCancel_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCancel.Click
    If FProcessing Then
      FProcessing = False
    Else
      End 'Application.Exit()
    End If
  End Sub

  Private Sub ChkAutoClose_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ChkAutoClose.CheckedChanged
    SettingsManager.AutoCloseStatusDialogs = ChkAutoClose.Checked
  End Sub

  Private Sub FrmStatus_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
    ChkAutoClose.Checked = SettingsManager.AutoCloseStatusDialogs
  End Sub

  Private Sub FrmStatus_FormClosed(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles Me.FormClosed
    End 'Application.Exit()
  End Sub

  Private Sub BtnRestart_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnRestart.Click
    BtnRestart.Visible = False
    Me.Refresh()
    OnRestartConversion()
  End Sub

#End Region

End Class