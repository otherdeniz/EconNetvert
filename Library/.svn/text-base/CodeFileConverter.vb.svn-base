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

''' -----------------------------------------------------------------------------
''' Project	 : Econ.NetVert
''' Class	 : NetVert.CodeFileConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts codefiles between VB.NET and C#.
''' </summary>
''' <example> This sample converts all VB.NET Files from "C:\VBFiles" to "C:\CSharpFiles".
''' <code lang="Visual Basic">
'''     Sub ConvertFiles()
'''       Dim TmpConv As New CodeFileConverter(ConverterLanguages.VBNetToCSharp, AddressOf OutputText)
'''       TmpConv.ConvertFiles("C:\VBFiles", "", "C:\CSharpFiles", True, True)
'''     End Sub
'''     Private Sub OutputText(ByVal textLine As String)
'''       'TODO: write textLine to output window or logfile here
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertFiles()
'''     {
'''       CodeFileConverter TmpConv = new CodeFileConverter(ConverterLanguages.VBNetToCSharp, new OutputProcedureDelegate(OutputText));
'''       TmpConv.ConvertFiles("C:\\VBFiles", "", "C:\\CSharpFiles", true, true);
'''     }
'''     private void OutputText(string textLine)
'''     {
'''       //TODO: write textLine to output window or logfile here
'''     }
''' </code>
''' </example>
''' <history>
'''   [esen]  15.07.2005  created
''' 	[esen]	17.10.2005	v1.0
''' 	[esen]	30.12.2005	v1.1
'''   [esen]  21.03.2006  v2.0
''' </history>
''' -----------------------------------------------------------------------------
Public NotInheritable Class CodeFileConverter

  'DECLARATIONS
  Private FLanguage As ConverterLanguages
  Private FTotalCount As Int32 = 0
  Private FConvertedCount As Int32 = 0
  Private FFailedCount As Int32 = 0
  Private FFixNamespaces As String = "System,System.Collections,System.Data,System.Diagnostics"

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
  ''' Create new CodeFileConverter instance.
  ''' </summary>
  ''' <param name="language">An enumeration value. Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.</param>
  ''' <remarks>
  ''' The property <b>language</b> could not be changed on existing instances.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Sub New(ByVal language As ConverterLanguages)
    FLanguage = language
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Default wildcard to search for files. Allways "*.vb" or "*.cs"
  ''' </summary>
  ''' <returns>"*.vb" for VBNetToCSharp, "*.cs" for CSharpToVBNet</returns>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property DefaultWildcard() As String
    Get
      Dim RetS As String = ""
      Select Case FLanguage
        Case ConverterLanguages.VBNetToCSharp
          RetS = "*.vb"
        Case ConverterLanguages.CSharpToVBNet
          RetS = "*.cs"
      End Select
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the extension for converted files. Allways "cs" or "vb"
  ''' </summary>
  ''' <returns>"cs" for VBNetToCSharp, "vb" for CSharpToVBNet</returns>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property OutputFileExtension() As String
    Get
      Dim RetS As String = ""
      Select Case FLanguage
        Case ConverterLanguages.VBNetToCSharp
          RetS = "cs"
        Case ConverterLanguages.CSharpToVBNet
          RetS = "vb"
      End Select
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the total number of files that matched the wildcard.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property TotalFilesCount() As Int32
    Get
      Return FTotalCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the number of files that are converted without errors.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property ConvertedFilesCount() As Int32
    Get
      Return FConvertedCount
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Returns the number of files that failed converting, because of errors.
  ''' </summary>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property FailedFilesCount() As Int32
    Get
      Return FFailedCount
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
      RetS = "Processed Files: " & TotalFilesCount.ToString & vbCrLf & _
             "Converted: " & ConvertedFilesCount.ToString & vbCrLf & _
             "Failed: " & FailedFilesCount.ToString & vbCrLf
      Return RetS
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Specifies a comma-sepearated list of namespaces to fix.<br/>
  ''' If the <b>FixNamespace</b> parameter of the <b>Convert</b>-Methods is enabled, the converter appends using-statements at
  ''' beginning of C#-Files if converting from VB.NET to C# or removes import-statements from VB.NET-files if they are one of the
  ''' here specified namespaces.
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

#Region "Convert Functions"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert multiple codefiles.
  ''' </summary>
  ''' <param name="sourceDir">The full path to the source directory.</param>
  ''' <param name="wildcards">One or multiple wildcards or filenames to search for in sourceDir (default is <b>CodeFileConverter.DefaultWildcard</b>).<br/>
  ''' When using multiple wildcards, use comma as delimiter. For example: <b>a*.vb,b*.vb,c*.vb</b> to convert all codefiles beginning with a, b or c.</param>
  ''' <param name="targetDir">The full path to the destination directory (default is same than sourceDir).</param>
  ''' <param name="recurseSubDirs">True if subdirectories should be included (default is false).</param>
  ''' <param name="overwriteExistingFiles">True if existing files should be overwriten (default is false).</param>
  ''' <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property (default is false).</param>
  ''' -----------------------------------------------------------------------------
  Public Sub ConvertFiles(ByVal sourceDir As String, _
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
        ConvertFile(TmpFiles(I), TmpTarget, overwriteExistingFiles, fixNamespaces)
      Next
      If recurseSubDirs Then
        For Each SF As String In Directory.GetDirectories(sourceDir)
          ConvertFiles(SF, wildcards, Path.Combine(targetDir, Path.GetFileName(SF)), True, overwriteExistingFiles, fixNamespaces)
        Next
      End If
    Else
      Throw New ArgumentException("missing wildcards")
    End If
  End Sub

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert single codefile.
  ''' </summary>
  ''' <param name="sourceFile">The full path and filename to the source codefile.</param>
  ''' <param name="targetFile">The full path and filename to the destination codefile (default is same than sourceFile with changed extension).</param>
  ''' <param name="overwriteExistingFile">True if existing file should be overwriten (default is false).</param>
  ''' <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property (default is false).</param>
  ''' -----------------------------------------------------------------------------
  Public Sub ConvertFile(ByVal sourceFile As String, _
                         Optional ByVal targetFile As String = "", _
                         Optional ByVal overwriteExistingFile As Boolean = False, _
                         Optional ByVal fixNamespaces As Boolean = False)
    Dim TmpConv As INetVertConverter
    Dim TmpS As String
    Dim TmpE As ProcessedFileEventArgs
    Dim TmpFixNS As String = ""

    Try

      If targetFile = "" Then
        targetFile = Path.ChangeExtension(sourceFile, "." & OutputFileExtension)
      End If
      With Directory.GetParent(targetFile)
        If Not .Exists Then
          'create directory
          'OLD: OutputText("Creating directory " & .FullName)
          .Create()
        End If
      End With
      FTotalCount += 1
      If File.Exists(targetFile) AndAlso _
         Not overwriteExistingFile Then
        'Skipped, file exists
        'OLD: OutputText("Skipped, file exists " & targetFile)
        'RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(sourceFile, 0, targetFile, 0, ProcessedFileEventArgs.FileStatus.Skipped_Exists, FLanguage, ""))
        RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, _
                                                                     sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Exists, FLanguage, ""))
      Else
        With New StreamReader(New FileStream(sourceFile, FileMode.Open), System.Text.Encoding.Default)
          TmpS = .ReadToEnd
          .Close()
        End With
        'create EventArgs
        TmpE = New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, _
                                          sourceFile, TmpS, targetFile, "", ProcessedFileEventArgs.ConverterOperations.Before_Conversion, FLanguage, "")
        RaiseEvent BeforeFileProcessed(Me, TmpE)
        'set Namespaces to fix
        If fixNamespaces Then
          TmpFixNS = FFixNamespaces
        End If
        'create Converter instance with apropreate language
        If FLanguage = ConverterLanguages.VBNetToCSharp Then
          TmpConv = VBCSConverter.Convert(TmpE.InputSource, TmpFixNS)
        ElseIf FLanguage = ConverterLanguages.CSharpToVBNet Then
          TmpConv = CSVBConverter.Convert(TmpE.InputSource, TmpFixNS)
        Else
          Throw New Exception("Converter-Language not supported")
        End If
        If TmpConv.HasError Then
          'has an error
          FFailedCount += 1
          'OLD: OutputText("Error in " & sourceFile & vbCrLf & TmpConv.ErrorText)
          TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, TmpConv.ErrorText)
          RaiseEvent AfterFileProcessed(Me, TmpE)
        Else
          'no error
          FConvertedCount += 1
          If File.Exists(targetFile) Then
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Overwriting)
            File.Delete(targetFile)
          Else
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Creating)
          End If
          TmpE.OutputSource = TmpConv.OutputSource
          RaiseEvent AfterFileProcessed(Me, TmpE)
          'save new stream to file
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

      End If

#If DEBUG Then
    Catch ex As NetVertException
      'common error
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, _
                                                                   sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
#Else
    Catch ex As Exception
      'common error
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, _
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
    FTotalCount = 0
    FConvertedCount = 0
    FFailedCount = 0
  End Sub

  'PRIVATE
  'Private Sub OutputText(ByVal textLine As String)
  '  If Not FOutputFunction Is Nothing Then
  '    FOutputFunction.Invoke(textLine & vbCrLf)
  '  End If
  'End Sub

End Class
