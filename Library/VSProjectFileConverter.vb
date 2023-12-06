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
Imports System.Collections.Generic

''' -----------------------------------------------------------------------------
''' Project	 : Econ.NetVert
''' Class	 : NetVert.VSProjectFileConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts Visual Studio projects between VB.NET and C#.
''' </summary>
''' <remarks>
''' Supported are Microsoft Visual Studio .NET 2002/2003 and Visual Studio 2005 projects.
''' </remarks>
''' <example> This sample converts all VB.NET Projects from "C:\VBProjects" to "C:\CSharpProjects".
''' <code lang="Visual Basic">
'''     Sub ConvertProjects()
'''       Dim TmpConv As New VSProjectFileConverter(ConverterLanguages.VBNetToCSharp, AddressOf OutputText)
'''       TmpConv.ConvertProjects("C:\VBProjects", "", "C:\CSharpProjects", True, True)
'''     End Sub
'''     Private Sub OutputText(ByVal textLine As String)
'''       'TODO: write textLine to output window or logfile here
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertProjects()
'''     {
'''       CodeFileConverter TmpConv = new VSProjectConverter(ConverterLanguages.VBNetToCSharp, new OutputProcedureDelegate(OutputText));
'''       TmpConv.ConvertProjects("C:\\VBProjects", "", "C:\\CSharpProjects", true, true);
'''     }
'''     private void OutputText(string textLine)
'''     {
'''       //TODO: write textLine to output window or logfile here
'''     }
''' </code>
''' </example>
''' <history>
'''   [esen]  22.12.2005  created
''' 	[esen]	30.12.2005	v1.1
'''   [esen]  21.03.2006  v2.0
''' </history>
''' -----------------------------------------------------------------------------
Public NotInheritable Class VSProjectFileConverter

#Region "NESTED"

  Private Class PairedCodeFile
    'PUBLIC PROPERTIES
    Public Property MainFilePath As String = ""
    Public Property DesignerFilePath As String = ""
  End Class

#End Region

  'DECLARATIONS
  Private FLanguage As ConverterLanguages
  Private FFileConverter As CodeFileConverter
  Private FAspxFileConverter As ASPXFileConverter
  Private FTotalProjectsCount As Int32 = 0
  Private FCopyFilesCount As Int32 = 0
  Private FFixNamespaces As String = "Microsoft.VisualBasic,System,System.Collections,System.Data,System.Diagnostics,System.Drawing,System.Windows.Forms"

  'EVENTS
#Region "PUBLIC Events"

  ''' <summary>
  ''' This event is raised for each file, before the conversion procedure.
  ''' </summary>
  ''' <param name="sender"></param>
  ''' <param name="e"></param>
  ''' <remarks></remarks>
  Public Event BeforeFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)

  ''' <summary>
  ''' This event is raised for each file, after the conversion procedure.
  ''' </summary>
  ''' <param name="sender"></param>
  ''' <param name="e"></param>
  ''' <remarks></remarks>
  Public Event AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)

#End Region

  'CONSTRUCTOR
  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Create new VSProjectFileConverter instance.
  ''' </summary>
  ''' <param name="language">An enumeration value. Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.</param>
  ''' <remarks>
  ''' The property <b>language</b> could not be changed on existing instances.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Sub New(ByVal language As ConverterLanguages)
    FLanguage = language
    FFileConverter = New CodeFileConverter(language)
    FAspxFileConverter = New ASPXFileConverter(language)
    AddHandler FFileConverter.AfterFileProcessed, AddressOf FileConverter_AfterFileProcessed
    AddHandler FFileConverter.BeforeFileProcessed, AddressOf FileConverter_BeforeFileProcessed
    AddHandler FAspxFileConverter.AfterFileProcessed, AddressOf FileConverter_AfterFileProcessed
    AddHandler FAspxFileConverter.BeforeFileProcessed, AddressOf FileConverter_BeforeFileProcessed
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Default wildcard to search for projects. Allways "*.vbproj" or "*.csproj"
  ''' </summary>
  ''' <returns>"*.vbproj" for VBNetToCSharp, "*.csproj" for CSharpToVBNet</returns>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property DefaultWildcard() As String
    Get
      Dim RetS As String = ""
      Select Case FLanguage
        Case ConverterLanguages.VBNetToCSharp
          RetS = "*.vbproj"
        Case ConverterLanguages.CSharpToVBNet
          RetS = "*.csproj"
      End Select
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the extension for converted projects. Allways "csproj" or "vbproj"
  ''' </summary>
  ''' <returns>"csproj" for VBNetToCSharp, "vbproj" for CSharpToVBNet</returns>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property OutputFileExtension() As String
    Get
      Dim RetS As String = ""
      Select Case FLanguage
        Case ConverterLanguages.VBNetToCSharp
          RetS = "csproj"
        Case ConverterLanguages.CSharpToVBNet
          RetS = "vbproj"
      End Select
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the total number of projects that matched the wildcard.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property TotalProjectsCount() As Int32
    Get
      Return FTotalProjectsCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the total number of copied files that where found in projects.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property CopyFilesCount() As Int32
    Get
      Return FCopyFilesCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the total number of codefiles that where found in projects.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property TotalCodeFilesCount() As Int32
    Get
      Return FFileConverter.TotalFilesCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the number of codefiles that are converted without errors.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property ConvertedCodeFilesCount() As Int32
    Get
      Return FFileConverter.ConvertedFilesCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the number of codefiles that failed converting, because of errors.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property FailedCodeFilesCount() As Int32
    Get
      Return FFileConverter.FailedFilesCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the summary text.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property SummaryText() As String
    Get
      Dim RetS As String
      RetS = "Converted Projects: " & TotalProjectsCount.ToString & vbCrLf & _
             "Copied Files: " & CopyFilesCount.ToString & vbCrLf & _
             "Processed Code-Files: " & TotalCodeFilesCount.ToString & vbCrLf & _
             "Converted Code-Files: " & ConvertedCodeFilesCount.ToString & vbCrLf & _
             "Failed Code-Files: " & FailedCodeFilesCount.ToString & vbCrLf
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Specifies a comma-sepearated list of default namespaces to fix.<br/>
  ''' If the <b>FixNamespace</b> parameter of the <b>Convert</b>-Methods is enabled, the converter appends using-statements at
  ''' beginning of C#-Files if converting from VB.NET to C# or removes import-statements from VB.NET-files if they are one of the
  ''' here specified namespaces.<br/>
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public Property FixNamespaces() As String
    Get
      Return FFixNamespaces
    End Get
    Set(ByVal value As String)
      FFixNamespaces = value
    End Set
  End Property

#End Region

#Region "Convert Funtions"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert multiple Visual Studio projects.
  ''' </summary>
  ''' <param name="sourceDir">The full path to the source directory.</param>
  ''' <param name="wildcards">One or multiple wildcards or filenames to search for in sourceDir (default is <b>VSProjectConverter.DefaultWildcard</b>).<br/>
  ''' When using multiple wildcards, use comma as delimiter. For example: <b>a*.vbproj,b*.vbproj,c*.vbproj</b> to convert all projectfiles beginning with a, b or c.</param>
  ''' <param name="targetDir">The full path to the destination directory (default is same than sourceDir).</param>
  ''' <param name="recurseSubDirs">True if subdirectories should be included (default is false).</param>
  ''' <param name="overwriteExistingFiles">True if existing files should be overwriten (default is false).</param>
  ''' <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property (default is false).</param>
  ''' -----------------------------------------------------------------------------
  Public Sub ConvertProjects(ByVal sourceDir As String, _
                             Optional ByVal wildcards As String = "", _
                             Optional ByVal targetDir As String = "", _
                             Optional ByVal recurseSubDirs As Boolean = False, _
                             Optional ByVal overwriteExistingFiles As Boolean = False, _
                             Optional ByVal fixNamespaces As Boolean = False)
    Dim TmpWildcards() As String
    Dim TmpFiles() As String
    Dim TmpTarget As String

    If wildcards = "" Then
      'use default wildcard
      wildcards = DefaultWildcard
    End If
    If targetDir = "" Then
      'use source-dir as target-dir by default
      targetDir = sourceDir
    End If
    TmpWildcards = Split(wildcards, ",", Compare:=CompareMethod.Text)
    If TmpWildcards.Length > 0 Then
      'get files for the first wildcard in wildcards and save in TmpFiles
      TmpFiles = Directory.GetFiles(sourceDir, TmpWildcards(0))
      For iW As Int32 = 1 To TmpWildcards.Length - 1
        'get files for wildcard 1-n in wildcards and append to TmpFiles
        With Directory.GetFiles(sourceDir, TmpWildcards(iW))
          If .Length > 0 Then
            Array.Resize(TmpFiles, TmpFiles.Length + .Length)
            .CopyTo(TmpFiles, TmpFiles.Length - .Length)
          End If
        End With
      Next
      For I As Int32 = 0 To TmpFiles.Length - 1
        TmpTarget = Path.Combine(targetDir, Path.GetFileNameWithoutExtension(TmpFiles(I)) & "." & OutputFileExtension)
        ConvertProject(TmpFiles(I), TmpTarget, overwriteExistingFiles, fixNamespaces)
      Next
      If recurseSubDirs Then
        For Each SF As String In Directory.GetDirectories(sourceDir)
          ConvertProjects(SF, wildcards, Path.Combine(targetDir, Path.GetFileName(SF)), True, overwriteExistingFiles, fixNamespaces)
        Next
      End If
    Else
      Throw New ArgumentException("missing wildcards")
    End If
  End Sub

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert single Visual Studio project.
  ''' </summary>
  ''' <param name="sourceFile">The full path and filename to the source project file.</param>
  ''' <param name="targetFile">The full path and filename to the destination project file (default is same than sourceFile with changed extension).</param>
  ''' <param name="overwriteExistingFile">True if existing file should be overwriten (default is false).</param>
  ''' <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property (default is false).</param>
  ''' -----------------------------------------------------------------------------
  Public Sub ConvertProject(ByVal sourceFile As String, _
                            Optional ByVal targetFile As String = "", _
                            Optional ByVal overwriteExistingFile As Boolean = False, _
                            Optional ByVal fixNamespaces As Boolean = False)
    Dim TmpSrcDir As DirectoryInfo
    Dim TmpTarDir As DirectoryInfo
    Dim TmpProjStr As String
    Dim TmpFiles As New ArrayList
    'Dim TmpRel As String
    'Dim TmpFSrc As String
    'Dim TmpFDest As String = ""
    Dim TmpE As ProcessedFileEventArgs
    Dim TmpI As Int32
    Dim TmpI2 As Int32
    Dim TmpNSImport As String

    Try
      'get default Target-File
      If targetFile = "" Then
        targetFile = Path.ChangeExtension(sourceFile, "." & OutputFileExtension)
      End If
      If File.Exists(targetFile) AndAlso _
         Not overwriteExistingFile Then
        'Skipped, file exists
        'OLD: OutputText("Skipped, file exists " & targetFile)
        'RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(sourceFile, 0, targetFile, 0, ProcessedFileEventArgs.FileStatus.Skipped_Exists, FLanguage, ""))
        RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.VSProjectFile, _
                                                                     sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Exists, FLanguage, ""))
      Else
        'file does not exist or overwriteExistingFile is true
        'get source and destination directory
        TmpSrcDir = Directory.GetParent(sourceFile)
        TmpTarDir = Directory.GetParent(targetFile)
        'create target dir if not exists
        If Not TmpTarDir.Exists Then
          'OLD: OutputText("Creating directory " & TmpTarDir.FullName)
          TmpTarDir.Create()
        End If
        'read project source stream
        With New StreamReader(New FileStream(sourceFile, FileMode.Open), System.Text.Encoding.Default)
          TmpProjStr = .ReadToEnd
          .Close()
        End With
        'create EventArgs
        TmpE = New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.VSProjectFile, _
                                          sourceFile, TmpProjStr, targetFile, "", ProcessedFileEventArgs.ConverterOperations.Before_Conversion, FLanguage, "")
        RaiseEvent BeforeFileProcessed(Me, TmpE)
        'increment total project count
        FTotalProjectsCount += 1
        If FLanguage = ConverterLanguages.VBNetToCSharp Then
          'extract individual NS-Imports of VB-Proj
          TmpNSImport = ""
          'VS2003 NS-Import
          TmpI = 0
          TmpI2 = 0
          Do
            TmpI = TmpProjStr.IndexOf("<Import Namespace = """, TmpI + 1)
            If TmpI > -1 Then
              TmpI2 = TmpProjStr.IndexOf(""" />", TmpI)
              If TmpNSImport <> "" Then TmpNSImport &= ","
              TmpNSImport &= TmpProjStr.Substring(TmpI + 21, TmpI2 - TmpI - 21)
            End If
          Loop While TmpI > -1
          'VS2005 NS-Import
          TmpI = 0
          TmpI2 = 0
          Do
            TmpI = TmpProjStr.IndexOf("<Import Include = """, TmpI + 1)
            If TmpI > -1 Then
              TmpI2 = TmpProjStr.IndexOf(""" />", TmpI)
              If TmpNSImport <> "" Then TmpNSImport &= ","
              TmpNSImport &= TmpProjStr.Substring(TmpI + 19, TmpI2 - TmpI - 19)
            End If
          Loop While TmpI > -1
          If TmpNSImport <> "" Then
            'set custom NS-fix
            FFileConverter.FixNamespaces = TmpNSImport
          Else
            'set current default-NS-fix
            FFileConverter.FixNamespaces = FFixNamespaces
          End If
        Else
          'set current default-NS-fix
          FFileConverter.FixNamespaces = FFixNamespaces
        End If
        'get root-namespace
        Dim rootNs As ArrayList = GetAllSubStrings(TmpProjStr, "<RootNamespace>", "</RootNamespace>")
        If rootNs.Count > 0 Then
          FFileConverter.WrapNamespace = rootNs(0)
        Else
          FFileConverter.WrapNamespace = ""
        End If
        'get all 2002/2003 files (RelPath=") or (RelPath = ")
        TmpFiles.AddRange(GetAllSubStrings(TmpProjStr, "RelPath=""", """"))
        TmpFiles.AddRange(GetAllSubStrings(TmpProjStr, "RelPath = """, """"))
        'get all 2005 files (Include=") or (Include = ")
        TmpFiles.AddRange(GetAllSubStrings(TmpProjStr, "Include=""", """"))
        TmpFiles.AddRange(GetAllSubStrings(TmpProjStr, "Include = """, """"))
        'seperate regular and designer-files
        Dim noneDesignerFiles As New List(Of String)
        Dim designerFiles As New List(Of String)
        For Each f As String In TmpFiles
          Dim fullPath As String = Path.Combine(TmpSrcDir.FullName, f)
          If File.Exists(fullPath) Then
            If f.ToLower() Like "*.designer.*" Then
              designerFiles.Add(f)
            Else
              noneDesignerFiles.Add(f)
            End If
          End If
        Next
        'create 3 lists:
        ' - 1 with standalone code-files
        ' - 1 with codefiles and associated designer-file
        ' - 1 with other files
        Dim singleFiles As New List(Of String)
        Dim pairedFiles As New List(Of PairedCodeFile)
        Dim otherFiles As New List(Of String)
        For Each f As String In noneDesignerFiles
          If f Like FFileConverter.DefaultWildcard Then
            'f is code file
            Dim designerFile As String = Path.ChangeExtension(f, ".Designer" & Path.GetExtension(f))
            Dim isPaired As Boolean = False
            For Each df As String In designerFiles
              If df.ToLower() = designerFile.ToLower() Then
                isPaired = True
                designerFiles.Remove(df)
                Exit For
              End If
            Next
            If isPaired Then
              Dim pcf As New PairedCodeFile
              pcf.MainFilePath = f
              pcf.DesignerFilePath = designerFile
              pairedFiles.Add(pcf)
            Else
              singleFiles.Add(f)
            End If
          Else
            'f is other file
            otherFiles.Add(f)
          End If
        Next
        'add rest of designer-files to single-file-list because no associated code-file found to create a pair
        For Each f As String In designerFiles
          singleFiles.Add(f)
        Next
        'convert all paired codefiles
        For Each pcf As PairedCodeFile In pairedFiles
          'a codefile to convert
          Dim fullPathSrc As String = Path.Combine(TmpSrcDir.FullName, pcf.MainFilePath)
          Dim fullPathDst As String = Path.ChangeExtension(Path.Combine(TmpTarDir.FullName, pcf.MainFilePath), "." & FFileConverter.OutputFileExtension)
          Dim fullPathSrc2 As String = Path.Combine(TmpSrcDir.FullName, pcf.DesignerFilePath)
          Dim fullPathDst2 As String = Path.ChangeExtension(Path.Combine(TmpTarDir.FullName, pcf.DesignerFilePath), "." & FFileConverter.OutputFileExtension)
          'convert codefile-pair now
          FFileConverter.ConvertFilePair(fullPathSrc, fullPathSrc2, fullPathDst, fullPathDst2, overwriteExistingFile, fixNamespaces)
        Next
        'convert all single codefiles
        For Each f As String In singleFiles
          'a codefile to convert
          Dim fullPathSrc As String = Path.Combine(TmpSrcDir.FullName, f)
          Dim fullPathDst As String = Path.ChangeExtension(Path.Combine(TmpTarDir.FullName, f), "." & FFileConverter.OutputFileExtension)
          'convert codefile now
          FFileConverter.ConvertFile(fullPathSrc, fullPathDst, overwriteExistingFile, fixNamespaces)
        Next
        'process all other files
        For Each f As String In otherFiles
          Dim fullPathSrc As String = Path.Combine(TmpSrcDir.FullName, f)
          Dim fullPathDst As String = Path.Combine(TmpTarDir.FullName, f)
          If (f Like "*.aspx") OrElse _
             (f Like "*.ascx") OrElse _
             (f Like "*.asmx") Then
            'a ASP.NET file to convert
            If TmpSrcDir.FullName = TmpTarDir.FullName Then
              fullPathDst = Path.ChangeExtension(Path.Combine(TmpTarDir.FullName, f), ".converted" & Path.GetExtension(f))
            End If
            'convert aspxfile now
            FAspxFileConverter.ConvertFile(fullPathSrc, fullPathDst, overwriteExistingFile)
          Else
            'a file to copy (if choosen targetdir does not equal sourcedir)
            If TmpSrcDir.FullName <> TmpTarDir.FullName Then
              With Directory.GetParent(fullPathDst)
                If Not .Exists Then
                  'OLD: OutputText("Creating directory " & .FullName)
                  .Create()
                End If
              End With
              If (Not File.Exists(fullPathDst)) OrElse overwriteExistingFile Then
                'message out and increment copy files count
                'OutputText("Copy file " & TmpFDest)
                RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.OtherFile, _
                                                                             fullPathSrc, "", fullPathDst, "", ProcessedFileEventArgs.ConverterOperations.FlatCopy, FLanguage, ""))
                FCopyFilesCount += 1
                'copy file now
                Try
                  File.Copy(fullPathSrc, fullPathDst, True)
                Catch ex As Exception
                  'filecopy error
                  RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.OtherFile, _
                                                                               fullPathSrc, "", fullPathDst, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
                End Try
              End If
            End If
          End If
        Next
        'VS2002/2003: replace <VisualBasic with <CSHARP
        'VS2005: replace "$(MSBuildBinPath)\Microsoft.VisualBasic.targets" with "$(MSBuildBinPath)\Microsoft.CSharp.targets"
        'and replace all extensions (.vb") -> (.cs") and (.vb<) -> (.cs<)
        'and replace ProjectTypeGUIDs:
        'Windows (C#) 	{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}
        'Windows (VB.NET) 	{F184B08F-C81C-45F6-A57F-5ABD9991F28F}
        'Legacy (2003) Smart Device (C#) 	{20D4826A-C6FA-45DB-90F4-C717570B9F32}
        'Legacy (2003) Smart Device (VB.NET) 	{CB4CE8C6-1BDB-4DC7-A4D3-65A1999772F8}
        'Smart Device (C#) 	{4D628B5B-2FBC-4AA6-8C16-197242AEB884}
        'Smart Device (VB.NET) 	{68B1623D-7FB9-47D8-8664-7ECEA3297D4F}
        'Workflow (C#) 	{14822709-B5A1-4724-98CA-57A101D1B079}
        'Workflow (VB.NET) 	{D59BE175-2ED0-4C54-BE3D-CDAA9F3214C8}
        'SharePoint (VB.NET) 	{EC05E597-79D4-47f3-ADA0-324C4F7C7484}
        'SharePoint (C#) 	{593B0543-81F6-4436-BA1E-4747859CAAE2}
        Select Case FLanguage
          Case ConverterLanguages.VBNetToCSharp
            TmpProjStr = TmpProjStr.Replace("<VisualBasic", "<CSHARP").Replace( _
                                            "Path)\Microsoft.VisualBasic.targets""", "Path)\Microsoft.CSharp.targets""").Replace( _
                                            "Path)\Microsoft.VisualBasic.Targets""", "Path)\Microsoft.CSharp.Targets""").Replace( _
                                            ".vb""", ".cs""").Replace( _
                                            ".vb<", ".cs<").Replace( _
                                            "{F184B08F-C81C-45F6-A57F-5ABD9991F28F}", "{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}").Replace( _
                                            "{CB4CE8C6-1BDB-4DC7-A4D3-65A1999772F8}", "{20D4826A-C6FA-45DB-90F4-C717570B9F32}").Replace( _
                                            "{68B1623D-7FB9-47D8-8664-7ECEA3297D4F}", "{4D628B5B-2FBC-4AA6-8C16-197242AEB884}").Replace( _
                                            "{D59BE175-2ED0-4C54-BE3D-CDAA9F3214C8}", "{14822709-B5A1-4724-98CA-57A101D1B079}").Replace( _
                                            "{EC05E597-79D4-47f3-ADA0-324C4F7C7484}", "{593B0543-81F6-4436-BA1E-4747859CAAE2}")
            'Add Refference : <Reference Include="Microsoft.VisualBasic" ...
            If Not TmpProjStr.Contains("<Reference Include=""Microsoft.VisualBasic""") Then
              'VS 2005/2008
              TmpProjStr = TmpProjStr.Replace("<Reference Include=""System"" />", _
                                                "<Reference Include=""Microsoft.VisualBasic"" />" & vbCrLf & _
                                                "<Reference Include=""System"" />")
              'VS 2010
              TmpProjStr = TmpProjStr.Replace("<Reference Include=""System"">", _
                                                "<Reference Include=""Microsoft.VisualBasic"">" & vbCrLf & _
                                                "  <Name>Microsoft.VisualBasic</Name>" & vbCrLf & _
                                                "</Reference>" & vbCrLf & _
                                                "<Reference Include=""System"">")
            End If
          Case ConverterLanguages.CSharpToVBNet
            TmpProjStr = TmpProjStr.Replace("<CSHARP", "<VisualBasic").Replace( _
                                            "Path)\Microsoft.CSharp.targets""", "Path)\Microsoft.VisualBasic.targets""").Replace( _
                                            "Path)\Microsoft.CSharp.Targets""", "Path)\Microsoft.VisualBasic.Targets""").Replace( _
                                            ".cs""", ".vb""").Replace( _
                                            ".cs<", ".vb<").Replace( _
                                            "{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}", "{F184B08F-C81C-45F6-A57F-5ABD9991F28F}").Replace( _
                                            "{20D4826A-C6FA-45DB-90F4-C717570B9F32}", "{CB4CE8C6-1BDB-4DC7-A4D3-65A1999772F8}").Replace( _
                                            "{4D628B5B-2FBC-4AA6-8C16-197242AEB884}", "{68B1623D-7FB9-47D8-8664-7ECEA3297D4F}").Replace( _
                                            "{14822709-B5A1-4724-98CA-57A101D1B079}", "{D59BE175-2ED0-4C54-BE3D-CDAA9F3214C8}").Replace( _
                                            "{593B0543-81F6-4436-BA1E-4747859CAAE2}", "{EC05E597-79D4-47f3-ADA0-324C4F7C7484}")
        End Select
        If File.Exists(targetFile) Then
          TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Overwriting)
          File.Delete(targetFile)
        Else
          TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Creating)
        End If
        TmpE.OutputSource = TmpProjStr
        RaiseEvent AfterFileProcessed(Me, TmpE)
        'save new project stream
        Try
          With File.CreateText(TmpE.OutputFile)
            .Write(TmpE.OutputSource)
            .Close()
          End With
        Catch ex As Exception
          TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, ex.Message)
          RaiseEvent AfterFileProcessed(Me, TmpE)
        End Try
      End If

#If DEBUG Then
    Catch ex As NetVertException
      'common error
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.VSProjectFile, _
                                                                   sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
#Else
    Catch ex As Exception
      'common error
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.VSProjectFile, _
                                                                   sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
#End If
    End Try

  End Sub

#End Region

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Reset all Count properties.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public Sub ResetCounters()
    FTotalProjectsCount = 0
    FCopyFilesCount = 0
    FFileConverter.ResetCounters()
  End Sub

  'PRIVATE
  'Private Sub OutputText(ByVal textLine As String)
  '  If Not FOutputFunction Is Nothing Then
  '    FOutputFunction.Invoke(textLine & vbCrLf)
  '  End If
  'End Sub

  Private Function GetAllSubStrings(ByVal ofString As String, _
                                    ByVal startTag As String, _
                                    ByVal endTag As String) As ArrayList
    Dim TmpStart As Int32
    Dim TmpEnd As Int32
    Dim TmpS As String
    Dim RetLst As New ArrayList

    TmpStart = 0
    Do
      'search startTag
      TmpStart = ofString.IndexOf(startTag, TmpStart)
      If TmpStart > -1 Then
        'search endTag
        TmpEnd = ofString.IndexOf(endTag, TmpStart + startTag.Length)
        If TmpEnd > -1 Then
          'get substring
          TmpS = ofString.Substring(TmpStart + startTag.Length, TmpEnd - TmpStart - startTag.Length)
          'add to RetLst
          RetLst.Add(TmpS)
          'set new start position
          TmpStart = TmpEnd + endTag.Length
        Else
          'endTag not found
          TmpStart = -1
        End If
      End If
    Loop While TmpStart > -1
    Return RetLst
  End Function

  Private Sub FileConverter_BeforeFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    RaiseEvent BeforeFileProcessed(Me, e)
  End Sub

  Private Sub FileConverter_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    RaiseEvent AfterFileProcessed(Me, e)
  End Sub

End Class
