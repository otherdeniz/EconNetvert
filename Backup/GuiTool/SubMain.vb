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

Imports System.IO
Imports System.Threading

Module ModuleMain

  'ENTRY POINT
  <STAThread()> _
  Sub Main(ByVal argumentList() As String)
    Dim TmpFrm As FrmMain

    System.Windows.Forms.Application.EnableVisualStyles()
    'for each p as  system.Diagnostics.Process.GetCurrentProcess.ProcessName
    If argumentList.Length = 0 Then
      'no arguments, show FrmMain
      Application.Run(New FrmMain)
    Else
      'arguments are passed
      If argumentList(0) = "/?" Then
        'show FrmAbout
        Application.Run(New FrmAbout)
      Else
        'check if first argument is a file
        If File.Exists(argumentList(0)) Then
          If (argumentList.Length > 1) AndAlso _
             (argumentList(1).ToLower = "/t") Then
            'convert shell-command
            ShellCommandConvert(argumentList(0), True)
          ElseIf (argumentList.Length > 1) AndAlso _
             (argumentList(1).ToLower = "/c") Then
            'convert-to shell-command
            ShellCommandConvert(argumentList(0), False)
          Else
            'show gui
            If argumentList(0).EndsWith(".vb") Then
              'open the .vb-file
              TmpFrm = New FrmMain
              TmpFrm.TabMain.SelectedIndex = 0
              With New StreamReader(File.OpenRead(argumentList(0)))
                TmpFrm.TxtFromVb.Text = .ReadToEnd()
                .Close()
              End With
              Application.Run(TmpFrm)
            ElseIf argumentList(0).EndsWith(".cs") Then
              'open the .cs-file
              TmpFrm = New FrmMain
              TmpFrm.TabMain.SelectedIndex = 1
              With New StreamReader(File.OpenRead(argumentList(0)))
                TmpFrm.TxtFromCS.Text = .ReadToEnd()
                .Close()
              End With
              Application.Run(TmpFrm)
            Else
              MsgBox("Not supported codefile '" & argumentList(0) & "'", MsgBoxStyle.Exclamation)
            End If
          End If

        Else
          MsgBox("Argument '" & argumentList(0) & "' is not an existing file.", MsgBoxStyle.Exclamation)
        End If
      End If
    End If
  End Sub

  Private Sub ShellCommandConvert(ByVal srcFile As String, _
                                  ByVal convertTo As Boolean)
    'Dim TmpInst As ShellConverterInstance
    'Dim TmpT As Thread
    Dim TmpFrm As FrmStatus
    Dim TmpPrefix As String = ""

    'check for previous instance
    If SingleInstance.IsFirstInstance Then
      'first instance
      TmpFrm = New FrmStatus
      SingleInstance.SetMainForm(TmpFrm)
      TmpFrm.ConvertFile(srcFile)
      TmpFrm.Show()
      If convertTo Then
        If Not TmpFrm.SetDestination(Left(srcFile, srcFile.Length - Path.GetFileName(srcFile).Length - 1)) Then
          'cancel
          Exit Sub
        End If
      End If
      TmpFrm.StartConversion()
      'TmpInst = New ShellConverterInstance(srcFile, convertTo)
      'TmpT = New Thread(AddressOf TmpInst.StartConverterThread)
      'TmpT.Start()
      Application.Run()
    Else
      'previous instance exists
      If convertTo Then TmpPrefix = "?"
      SingleInstance.NotifyPreviousWindow(TmpPrefix & srcFile)
    End If
  End Sub

  'Private Class ShellConverterInstance

  '  'DELCARATIONS
  '  Private FSrcFile As String
  '  Private FConvertTo As Boolean

  '  'CONSTRUCTOR
  '  Public Sub New(ByVal srcFile As String, ByVal convertTo As Boolean)
  '    FSrcFile = srcFile
  '    FConvertTo = convertTo
  '  End Sub

  '  <STAThread()> _
  '  Public Sub StartConverterThread()
  '  End Sub

  'End Class

End Module
