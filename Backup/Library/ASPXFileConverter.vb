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
''' Class	 : NetVert.ASPXFileConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts ASP.NET files.
''' </summary>
''' <example>...
''' <code lang="Visual Basic">
''' </code>
''' <code lang="C#">
''' </code>
''' ...
''' <code lang="Visual Basic">
''' </code>
''' <code lang="C#">
''' </code>
''' </example>
''' <history>
'''   [esen]  01.05.2006  created
''' </history>
''' -----------------------------------------------------------------------------
Public NotInheritable Class ASPXFileConverter

  'DECLARATIONS
  Private FLanguage As ConverterLanguagesAutodetectable
  Private FTotalCount As Int32 = 0
  Private FConvertedCount As Int32 = 0
  Private FFailedCount As Int32 = 0

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
  ''' Create new ASPXFileConverter instance.
  ''' </summary>
  ''' <param name="language">An enumeration value. Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.</param>
  ''' <remarks>
  ''' The property <b>language</b> could not be changed on existing instances.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Sub New(Optional ByVal language As ConverterLanguagesAutodetectable = ConverterLanguagesAutodetectable.Autodetect)
    FLanguage = language
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

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

#End Region

#Region "Convert Functions"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert multiple ASPX files.
  ''' </summary>
  ''' <param name="sourceDir">The full path to the source directory.</param>
  ''' <param name="wildcards">One or multiple wildcards or filenames to search for in sourceDir (default is <b>*.aspx,*.ascx</b>).<br/>
  ''' When using multiple wildcards, use comma as delimiter.</param>
  ''' <param name="targetDir">The full path to the destination directory (default is same than sourceDir).</param>
  ''' <param name="recurseSubDirs">True if subdirectories should be included (default is false).</param>
  ''' <param name="overwriteExistingFiles">True if existing files should be overwriten (default is false).</param>
  ''' -----------------------------------------------------------------------------
  ''' <remarks>
  ''' If the targetDir equals to sourceDir, the converted filenames get modified as follow: "(file).converted.(ext)"<br/>
  ''' For example: "default.aspx" (VB.NET) will be converted to "default.converted.aspx" (C#)
  ''' </remarks>
  Public Sub ConvertFiles(ByVal sourceDir As String, _
                          Optional ByVal wildcards As String = "", _
                          Optional ByVal targetDir As String = "", _
                          Optional ByVal recurseSubDirs As Boolean = False, _
                          Optional ByVal overwriteExistingFiles As Boolean = False)
    Dim TmpWildcards() As String
    Dim TmpFiles() As String
    Dim TmpTarget As String

    If wildcards = "" Then
      'use default wildcard
      wildcards = "*.aspx,*.ascx,*.asmx"
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
        If targetDir = sourceDir Then
          TmpTarget = Path.Combine(targetDir, Path.GetFileNameWithoutExtension(TmpFiles(I)) & ".converted" & Path.GetExtension(TmpFiles(I)))
        Else
          TmpTarget = Path.Combine(targetDir, Path.GetFileName(TmpFiles(I)))
        End If
        ConvertFile(TmpFiles(I), TmpTarget, overwriteExistingFiles)
      Next
      If recurseSubDirs Then
        For Each SF As String In Directory.GetDirectories(sourceDir)
          ConvertFiles(SF, wildcards, Path.Combine(targetDir, Path.GetFileName(SF)), True, overwriteExistingFiles)
        Next
      End If
    Else
      Throw New ArgumentException("missing wildcards")
    End If
  End Sub

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert single ASPX file.
  ''' </summary>
  ''' <param name="sourceFile">The full path and filename to the source ASPX file.</param>
  ''' <param name="targetFile">The full path and filename to the destination ASPX file.</param>
  ''' <param name="overwriteExistingFile">True if existing file should be overwriten (default is false).</param>
  ''' -----------------------------------------------------------------------------
  Public Sub ConvertFile(ByVal sourceFile As String, _
                         ByVal targetFile As String, _
                         Optional ByVal overwriteExistingFile As Boolean = False)
    Dim TmpConv As ASPXConverter
    Dim TmpS As String
    Dim TmpE As ProcessedFileEventArgs

    Try

      With Directory.GetParent(targetFile)
        If Not .Exists Then
          'create directory
          .Create()
        End If
      End With
      FTotalCount += 1
      If File.Exists(targetFile) AndAlso _
         Not overwriteExistingFile Then
        'Skipped, file exists
        RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, _
                                                                     sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Exists, FLanguage, ""))
      Else
        With New StreamReader(New FileStream(sourceFile, FileMode.Open), System.Text.Encoding.Default)
          TmpS = .ReadToEnd
          .Close()
        End With
        'create EventArgs
        TmpE = New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, _
                                          sourceFile, TmpS, targetFile, "", ProcessedFileEventArgs.ConverterOperations.Before_Conversion, FLanguage, "")
        RaiseEvent BeforeFileProcessed(Me, TmpE)
        'convert now
        TmpConv = ASPXConverter.Convert(TmpS, FLanguage)
        If TmpConv.HasError Then
          'has an error
          FFailedCount += 1
          TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, TmpConv.ErrorText, TmpConv.ConverterLanguage)
          RaiseEvent AfterFileProcessed(Me, TmpE)
        Else
          'no error
          FConvertedCount += 1
          If File.Exists(targetFile) Then
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Overwriting, "", TmpConv.ConverterLanguage)
            File.Delete(targetFile)
          Else
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Creating, "", TmpConv.ConverterLanguage)
          End If
          TmpE.OutputSource = TmpConv.ASPXOutputSource
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
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, _
                                                                   sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
#Else
    Catch ex As Exception
      'common error
      RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, _
                                                                   sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message))
#End If
    End Try


    'With Directory.GetParent(targetFile)
    '  If Not .Exists Then
    '    OutputText("Creating directory " & .FullName)
    '    .Create()
    '  End If
    'End With
    'FTotalCount += 1
    'If File.Exists(targetFile) AndAlso _
    '   Not overwriteExistingFile Then
    '  OutputText("Skipped, file exists " & targetFile)
    'Else

    '  TmpReader = File.OpenText(sourceFile)
    '  TmpS = TmpReader.ReadToEnd
    '  TmpReader.Close()
    '  'TmpError = ""
    '  TmpConv = ASPXConverter.Convert(TmpS, FLanguage)
    '  If TmpConv.HasError Then
    '    'has an error
    '    FFailedCount += 1
    '    OutputText("Error in " & sourceFile & vbCrLf & TmpConv.ErrorText)
    '  Else
    '    'no error
    '    If File.Exists(targetFile) Then
    '      OutputText("Overwriting " & targetFile)
    '    Else
    '      OutputText("Creating " & targetFile)
    '    End If
    '    FConvertedCount += 1
    '    TmpWriter = File.CreateText(targetFile)
    '    TmpWriter.Write(TmpConv.ASPXOutputSource)
    '    TmpWriter.Close()
    '  End If

    'End If
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
