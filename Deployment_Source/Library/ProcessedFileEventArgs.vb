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

''' <summary>
''' Contains informations about the conversion of a file.
''' </summary>
Public Class ProcessedFileEventArgs
  Inherits EventArgs

  Public Enum ConverterFileTypes
    CodeFile
    VSProjectFile
    ASPXFile
    OtherFile
  End Enum

  Public Enum ConverterOperations
    Before_Conversion = 0
    Success_Creating = 10
    Success_Overwriting = 11
    FlatCopy = 15
    Skipped_Exists = 20
    Skipped_Error = 21
    'Common_Error = 99
  End Enum

  'DECLARATIONS
  Private FFileType As ConverterFileTypes
  Private FInputFile As String
  Private FInputSource As String
  Private FOutputFile As String
  Private FOutputSource As String
  Private FOperation As ConverterOperations
  Private FConverterLanguage As ConverterLanguagesAutodetectable
  Private FConverterError As String

  'CONSTRUCTOR
  Friend Sub New(ByVal fileType As ConverterFileTypes, _
                 ByVal inFile As String, _
                 ByVal inSource As String, _
                 ByVal outFile As String, _
                 ByVal outSource As String, _
                 ByVal convOperation As ConverterOperations, _
                 ByVal convLang As ConverterLanguagesAutodetectable, _
                 ByVal convError As String)
    FFileType = fileType
    FInputFile = inFile
    FInputSource = inSource
    FOutputFile = outFile
    FOutputSource = outSource
    FOperation = convOperation
    FConverterLanguage = convLang
    FConverterError = convError
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  Public ReadOnly Property FileType() As ConverterFileTypes
    Get
      Return FFileType
    End Get
  End Property

  Public ReadOnly Property InputFile() As String
    Get
      Return FInputFile
    End Get
  End Property

  Public Property InputSource() As String
    Get
      Return FInputSource
    End Get
    Set(ByVal value As String)
      FInputSource = value
    End Set
  End Property

  Public ReadOnly Property InputLinesOfCode() As Int32
    Get
      Return Split(FInputSource, vbCrLf).Length
    End Get
  End Property

  Public Property OutputFile() As String
    Get
      Return FOutputFile
    End Get
    Set(ByVal value As String)
      FOutputFile = value
    End Set
  End Property

  Public Property OutputSource() As String
    Get
      Return FOutputSource
    End Get
    Set(ByVal value As String)
      FOutputSource = value
    End Set
  End Property

  Public ReadOnly Property OutputLinesOfCode() As Int32
    Get
      Return Split(FOutputSource, vbCrLf).Length
    End Get
  End Property

  Public ReadOnly Property ConverterOperation() As ConverterOperations
    Get
      Return FOperation
    End Get
  End Property

  Public ReadOnly Property ConverterLanguage() As ConverterLanguagesAutodetectable
    Get
      Return FConverterLanguage
    End Get
  End Property

  Public ReadOnly Property ConverterError() As String
    Get
      Return FConverterError
    End Get
  End Property

#End Region

  Public Overloads Overrides Function ToString() As String
    Return Me.ToString("", "")
  End Function

  Public Overloads Function ToString(ByVal inputRootPath As String, _
                                     ByVal outputRootPath As String) As String
    Dim TmpFT As String = ""
    Dim TmpOutLng As String = ""
    Dim RetS As String = ""

    Select Case FFileType
      Case ConverterFileTypes.CodeFile
        TmpFT = "Codefile"
      Case ConverterFileTypes.ASPXFile
        TmpFT = "ASP.NET File"
        Select Case FConverterLanguage
          Case ConverterLanguagesAutodetectable.VBNetToCSharp
            TmpOutLng = " [C#]"
          Case ConverterLanguagesAutodetectable.CSharpToVBNet
            TmpOutLng = " [VB.NET]"
        End Select
      Case ConverterFileTypes.VSProjectFile
        TmpFT = "Visual Studio Project"
      Case ConverterFileTypes.OtherFile
        TmpFT = "File"
    End Select
    Select Case FOperation
      Case ConverterOperations.Before_Conversion
        RetS = "Reading " & TmpFT & " '" & TrimmPath(FInputFile, inputRootPath) & "' (" & InputLinesOfCode.ToString & " lines, " & InputSource.Length.ToString & " bytes)"
      Case ConverterOperations.Skipped_Error
        RetS = "Error in " & TmpFT & " '" & TrimmPath(FInputFile, inputRootPath) & "'" & vbCrLf & FConverterError
      Case ConverterOperations.Skipped_Exists
        RetS = "Skipped, " & TmpFT & " exists '" & TrimmPath(FOutputFile, outputRootPath) & "'"
      Case ConverterOperations.Success_Creating
        RetS = "Creating " & TmpFT & TmpOutLng & " '" & TrimmPath(FOutputFile, outputRootPath) & "' (" & OutputLinesOfCode.ToString & " lines, " & OutputSource.Length.ToString & " bytes)"
      Case ConverterOperations.Success_Overwriting
        RetS = "Overwriting " & TmpFT & TmpOutLng & " '" & TrimmPath(FOutputFile, outputRootPath) & "' (" & OutputLinesOfCode.ToString & " lines, " & OutputSource.Length.ToString & " bytes)"
      Case ConverterOperations.FlatCopy
        RetS = "Copy " & TmpFT & " '" & TrimmPath(FOutputFile, outputRootPath) & "'"
    End Select
    Return RetS
  End Function

  'FRIEND
  Friend Sub ModifyStatus(ByVal convStatus As ConverterOperations, _
                          Optional ByVal convError As String = "", _
                          Optional ByVal convLang As ConverterLanguagesAutodetectable = ConverterLanguagesAutodetectable.Autodetect)
    FOperation = convStatus
    FConverterError = convError
    If convLang <> ConverterLanguagesAutodetectable.Autodetect Then
      FConverterLanguage = convLang
    End If
  End Sub

  'PRIVATE
  Private Function TrimmPath(ByVal fullPath As String, _
                             ByVal removePath As String) As String
    Dim RetS As String

    If (removePath <> "") AndAlso _
       (fullPath.Length > removePath.Length) AndAlso _
       (fullPath.Substring(0, removePath.Length).ToLower = removePath.ToLower) Then
      RetS = fullPath.Substring(removePath.Length, fullPath.Length - removePath.Length).TrimStart("\"c)
    Else
      RetS = fullPath
    End If
    Return RetS
  End Function

End Class
