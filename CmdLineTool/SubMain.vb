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

Module ModuleMain

  'DECLARATIONS
  Private cAppName As String = "Econ NetVert v" & System.Reflection.Assembly.GetExecutingAssembly.GetName.Version.ToString
  Private FOutputLevel As Int32 = 2
  Private FSourceDir As String = ""
  Private FTargetDir As String = ""

  'ENTRY POINT
  Sub Main(ByVal argumentList() As String)
    Dim TmpConv As CodeFileConverter = Nothing
    Dim TmpProjConv As VSProjectFileConverter = Nothing
    Dim TmpAspxConv As ASPXFileConverter = Nothing
    Dim TmpWildcard As String = ""
    'Dim TmpSource As String
    'Dim TmpTarget As String = ""
    Dim TmpRecurse As Boolean = False
    Dim TmpOverwrite As Boolean = False
    Dim TmpFixNs As Boolean = False
    'Dim TmpOutDelegate As OutputProcedureDelegate
    Dim TmpS As String

    If argumentList.Length > 1 Then
      'get arguments
      For I As Int32 = 2 To argumentList.Length - 1
        TmpS = argumentList(I)
        If (TmpS.Length > 3) AndAlso (TmpS.Substring(0, 3).ToUpper = "/F=") Then
          'argument: /F
          TmpWildcard = TmpS.Substring(3, TmpS.Length - 3)
        ElseIf (TmpS.Length = 4) AndAlso (TmpS.Substring(0, 3).ToUpper = "/L=") Then
          'argument: /L
          Select Case TmpS.Substring(3, 1)
            Case "0"
              FOutputLevel = 0
            Case "1"
              FOutputLevel = 1
            Case "2"
              FOutputLevel = 2
            Case "3"
              FOutputLevel = 3
            Case Else
              'Invalid parameter message
              Console.WriteLine(cAppName)
              Console.WriteLine("")
              Console.WriteLine("Invalid level of output: " & TmpS)
              Console.WriteLine("")
              ShowInfo(False)
              Exit Sub 'cancel
          End Select
        ElseIf TmpS.ToUpper = "/R" Then
          'argument: /R
          TmpRecurse = True
        ElseIf TmpS.ToUpper = "/W" Then
          'argument: /W
          TmpOverwrite = True
        ElseIf TmpS.ToUpper = "/N" Then
          'argument: /N
          TmpFixNs = True
        ElseIf (TmpS.Length > 1) AndAlso (I = 2) Then
          'argument: OUTPUT_FOLDER
          If TmpS.Substring(0, 1) = """" Then
            FTargetDir = Path.Combine(Directory.GetCurrentDirectory, TmpS.Substring(1, TmpS.Length - 2))
          Else
            FTargetDir = Path.Combine(Directory.GetCurrentDirectory, TmpS)
          End If
        Else
          'Invalid parameter message
          Console.WriteLine(cAppName)
          Console.WriteLine("")
          Console.WriteLine("Invalid argument: " & TmpS)
          Console.WriteLine("")
          ShowInfo(False)
          Exit Sub 'cancel
        End If
      Next
      'level of output
      'If FOutputLevel > 0 Then TmpOutDelegate = AddressOf OutputText
      'create converter class for choosen LANGUAGE-Mode
      Select Case argumentList(0).ToUpper
        Case "VBTOCS"
          TmpConv = New CodeFileConverter(ConverterLanguages.VBNetToCSharp)
        Case "CSTOVB"
          TmpConv = New CodeFileConverter(ConverterLanguages.CSharpToVBNet)
        Case "VBTOCSPROJ"
          TmpProjConv = New VSProjectFileConverter(ConverterLanguages.VBNetToCSharp)
        Case "CSTOVBPROJ"
          TmpProjConv = New VSProjectFileConverter(ConverterLanguages.CSharpToVBNet)
        Case "ASPX"
          TmpAspxConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.Autodetect)
        Case "ASPXVBTOCS"
          TmpAspxConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.VBNetToCSharp)
        Case "ASPXCSTOVB"
          TmpAspxConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.CSharpToVBNet)
        Case Else
          'Invalid parameter message
          Console.WriteLine(cAppName)
          Console.WriteLine("")
          Console.WriteLine("Parameter LANGUAGE is not a supported value: " & argumentList(0))
          Console.WriteLine("")
          ShowInfo(False)
          Exit Sub 'cancel
      End Select
      'get src dir
      FSourceDir = Path.Combine(Directory.GetCurrentDirectory, argumentList(1))
      If Not Directory.Exists(FSourceDir) Then
        'Invalid parameter message
        Console.WriteLine(cAppName)
        Console.WriteLine("")
        Console.WriteLine("Parameter FOLDER is not a existing directory: " & argumentList(1))
        Console.WriteLine("")
        ShowInfo(False)
        Exit Sub 'cancel
      End If
      If FTargetDir = "" Then
        'set default target-dir
        FTargetDir = FSourceDir
      End If
      If FOutputLevel > 1 Then
        Console.WriteLine(cAppName)
        Console.WriteLine("Using Baseconverter: " & SettingsManager.CurrentRefactoryProvider.Name)
        Console.WriteLine("Source Directory: " & FSourceDir)
        Console.WriteLine("Target Directory: " & FTargetDir)
        Console.WriteLine("Wildcards: " & TmpWildcard)
      End If
      If Not TmpProjConv Is Nothing Then
        'copy projects and convert files
        AddHandler TmpProjConv.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
        'convert projects now
        TmpProjConv.ConvertProjects(FSourceDir, TmpWildcard, FTargetDir, TmpRecurse, TmpOverwrite, TmpFixNs)
        'finished
        If FOutputLevel > 1 Then
          Console.Write(TmpProjConv.SummaryText)
          'Console.WriteLine("Converted Projects: " & TmpProjConv.TotalProjectsCount.ToString)
          'Console.WriteLine("Copied Files: " & TmpProjConv.CopyFilesCount.ToString)
          'Console.WriteLine("Processed Code-Files: " & TmpProjConv.TotalCodeFilesCount.ToString)
          'Console.WriteLine("Converted Code-Files: " & TmpProjConv.ConvertedCodeFilesCount.ToString)
          'Console.WriteLine("Failed Code-Files: " & TmpProjConv.FailedCodeFilesCount.ToString)
        End If
      ElseIf Not TmpConv Is Nothing Then
        'convert files
        AddHandler TmpConv.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
        'convert codefiles now
        TmpConv.ConvertFiles(FSourceDir, TmpWildcard, FTargetDir, TmpRecurse, TmpOverwrite, TmpFixNs)
        'finished
        If FOutputLevel > 1 Then
          Console.Write(TmpProjConv.SummaryText)
        End If
      ElseIf Not TmpAspxConv Is Nothing Then
        'convert files
        AddHandler TmpAspxConv.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
        'convert codefiles now
        TmpAspxConv.ConvertFiles(FSourceDir, TmpWildcard, FTargetDir, TmpRecurse, TmpOverwrite)
        'finished
        If FOutputLevel > 1 Then
          Console.Write(TmpProjConv.SummaryText)
        End If
      End If
    Else
      ShowInfo(True)
    End If
  End Sub

  'PRIVATE
  Private Sub ShowInfo(ByVal fullInfo As Boolean)
    If fullInfo Then
      Console.WriteLine(cAppName)
      Console.WriteLine("by Deniz Esen, 2006-2011, econnetvert.codeplex.com")
      Console.WriteLine("")
      Console.WriteLine("Convert source files, ASP.NET files or Visual Studio projects")
      Console.WriteLine("between VB.NET and C#.")
      Console.WriteLine("")
      Console.WriteLine("(Press a key to continue)")
      Console.ReadKey()
      Console.Clear()
      Console.WriteLine(cAppName)
    End If
    Console.WriteLine("Usage:")
    Console.WriteLine("netvertcmd LANGUAGE FOLDER [OUTPUT_FOLDER] [/F=Wildcard] [/R] [/W] [/N] [L=#]")
    If fullInfo Then
      Console.WriteLine(" LANGUAGE       = Use VBTOCS to convert codefiles from Visual Basic to C#")
      Console.WriteLine("                  or CSTOVB to convert codefiles from C# to Visual Basic")
      Console.WriteLine("                  or VBTOCSPROJ to convert projects from Visual Basic to C#")
      Console.WriteLine("                  or CSTOVBPROJ to convert projects from C# to Visual Basic")
      Console.WriteLine("                  or ASPX to convert ASP.NET files with language autodetection")
      Console.WriteLine("                  or ASPXCSTOVB or ASPXVBTOCS to convert ASP.NET files")
      Console.WriteLine(" FOLDER         = Source Folder")
      Console.WriteLine(" OUTPUT_FOLDER  = (Optional) Target folder (Default is same as source folder)")
      Console.WriteLine(" /F=Wildcards   = (Optional) Filename(s) or wildcard(s)")
      Console.WriteLine("                  Default is *.vb for VBTOCS or *.cs for CSTOVB")
      Console.WriteLine("                  or *.vbproj for VBTOCSPROJ or *.csproj for CSTOVBPROJ")
      Console.WriteLine("                  or *.aspx,*.ascx,*.asmx for ASPX, ASPXCSTOVB and ASPXVBTOCS")
      Console.WriteLine(" /R             = (Optional) Recurse subdirectories")
      Console.WriteLine(" /W             = (Optional) Overwrite existing files")
      Console.WriteLine(" /N             = (Optional) Fix Namespace import statements")
      Console.WriteLine(" /L=#           = (Optional) Level of display output (Default L=2)")
      Console.WriteLine("                  0 : No output")
      Console.WriteLine("                  1 : Only all files")
      Console.WriteLine("                  2 : Title, parameters, all files, summary")
      Console.WriteLine("                  3 : Title, parameters, only files with errors, summary")
      Console.WriteLine("(Press a key to continue)")
      Console.ReadKey()
      Console.Clear()
      Console.WriteLine(cAppName)
      Console.WriteLine("Examples:")
      Console.WriteLine("")
      Console.WriteLine("netvertcmd VBTOCS ""C:\VBFiles"" ""C:\ConvertedCSFiles"" /F=*.vb /R /L=0")
      Console.WriteLine("netvertcmd VBTOCSPROJ ""C:\VBProjects"" /F=Project1.vbproj;Project2.vbproj /W")
      Console.WriteLine("")
      Console.WriteLine("(Press a key to continue)")
      Console.ReadKey()
    End If
  End Sub

  'Private Sub OutputText(ByVal text As String)
  '  'is like delegate: Econ.NetVert.CodeFileConverter.OutputProcedureDelegate 
  '  Console.Write(text)
  'End Sub

  Private Sub Converter_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    Select Case FOutputLevel
      Case 1, 2 'output all files
        Console.WriteLine(e.ToString(FSourceDir, FTargetDir))
      Case 3 'output only files with error
        If e.ConverterOperation = ProcessedFileEventArgs.ConverterOperations.Skipped_Error Then
          Console.WriteLine(e.ToString(FSourceDir, FTargetDir))
        End If
    End Select
  End Sub

End Module
