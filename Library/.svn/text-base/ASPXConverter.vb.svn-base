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
''' Class	 : NetVert.ASPXConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts ASP.NET code.
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
''' <remarks>
''' Results of the <b>Convert</b>-Functions are returned as instances of this class.
''' </remarks>
''' <history>
'''   [esen]  20.04.2006  created
''' </history>
''' -----------------------------------------------------------------------------
Public Class ASPXConverter
  Implements INetVertConverter

  'DECLARATIONS
  Private FHasError As Boolean = False
  Private FErrorText As String = ""
  Private FConverterLanguage As ConverterLanguagesAutodetectable = ConverterLanguagesAutodetectable.Autodetect
  Private FResultSource As String = ""

  'SHARED
#Region "Convert Functions"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Convert ASP.NET code using language-autodetection.
  ''' </summary>
  ''' <param name="aspxSource">The ASPX source code.</param>
  ''' <returns>New instance of class ASPXConverter</returns>
  ''' <remarks>
  ''' Supported is only ASP.NET code with inline serverside code of the languages Visual Basic .NET or C#.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Shared Function Convert(ByVal aspxSource As String, _
                                 Optional ByVal converterLanguage As ConverterLanguagesAutodetectable = ConverterLanguagesAutodetectable.Autodetect) As ASPXConverter
    Dim RetConv As New ASPXConverter
    Dim TmpStart As Int32
    Dim TmpEnd As Int32
    Dim TmpLastEnd As Int32
    Dim TmpDirective As String
    Dim TmpComment As String = ""
    Dim TmpCodeLines As String
    Dim TmpConvertCode As String = ""
    Dim TmpHtmlBlocks As New ArrayList
    Dim TmpS As String

    Try

      'set language
      If converterLanguage = ConverterLanguagesAutodetectable.Autodetect Then
        RetConv.FConverterLanguage = SearchLanguage(aspxSource)
      Else
        RetConv.FConverterLanguage = converterLanguage
      End If

      'get Before-Convert-Comment-Sign
      Select Case RetConv.FConverterLanguage
        Case ConverterLanguagesAutodetectable.CSharpToVBNet
          TmpComment = "//"
        Case ConverterLanguagesAutodetectable.VBNetToCSharp
          TmpComment = "'"
      End Select

      'for each <%...%> block
      TmpStart = -1
      TmpLastEnd = 0
      Do
        'search "<%"
        TmpStart = aspxSource.IndexOf("<%", TmpStart + 1)
        If TmpStart > -1 Then
          'search "%>"
          TmpEnd = aspxSource.IndexOf("%>", TmpStart + 2)
          If TmpEnd > -1 Then

            If aspxSource.Substring(TmpStart + 2, 1) = "@" Then
              'if @: replace language-attribute and codebehind file extension
              TmpDirective = aspxSource.Substring(TmpStart, TmpEnd - TmpStart + 2)
              Select Case RetConv.FConverterLanguage
                Case ConverterLanguagesAutodetectable.CSharpToVBNet
                  TmpDirective = TmpDirective.Replace("""c#""", """vb""").Replace( _
                                                      ".cs""", ".vb""").Replace( _
                                                      "=cs ", "=vb ").Replace( _
                                                      "=c# ", "=vb ").Replace( _
                                                      """cs""", """vb""")
                Case ConverterLanguagesAutodetectable.VBNetToCSharp
                  TmpDirective = TmpDirective.Replace("""vb""", """c#""").Replace( _
                                                      ".vb""", ".cs""").Replace( _
                                                      "=vb ", "=c# ")
              End Select
              aspxSource = aspxSource.Substring(0, TmpStart) & _
                           TmpDirective & _
                           aspxSource.Substring(TmpEnd + 2, aspxSource.Length - TmpEnd - 2)
            Else
              'else: convert statements
              TmpHtmlBlocks.Add(aspxSource.Substring(TmpLastEnd, TmpStart - TmpLastEnd + 2))
              TmpConvertCode &= TmpComment & "HTMLBLOCK-" & TmpHtmlBlocks.Count.ToString & "." & vbCrLf
              TmpCodeLines = aspxSource.Substring(TmpStart + 2, TmpEnd - TmpStart - 2)
              TmpS = TmpCodeLines.TrimStart(Char.Parse(" "), Chr(9), Chr(10), Chr(13)) 'StrTrimmLeft(TmpCodeLines, New String() {" ", Chr(9).ToString, vbCrLf})
              If (TmpS <> "") AndAlso _
                 (TmpS.Substring(0, 1) = "=") Then
                'Add Temporary Out-Variable-Prefix
                TmpCodeLines = "NETVERTASPNETOUT " & TmpS
              End If
              Try

              Catch ex As Exception

              End Try
              'if StrTrimmLeft(StrTrimmLeft(StrTrimmLeft(tmpcodelines," "), chr(9).ToString)
              TmpConvertCode &= TmpCodeLines & vbCrLf
              TmpLastEnd = TmpEnd
            End If

          End If 'TmpEnd
        End If 'TmpStart
      Loop While TmpStart > -1
      'Append last HTML-Block
      If aspxSource.Length > TmpLastEnd Then
        TmpHtmlBlocks.Add(aspxSource.Substring(TmpLastEnd, aspxSource.Length - TmpLastEnd))
        TmpConvertCode &= TmpComment & "HTMLBLOCK-" & TmpHtmlBlocks.Count.ToString & "." & vbCrLf
      End If
      'Convert Code
      Select Case RetConv.FConverterLanguage
        Case ConverterLanguagesAutodetectable.CSharpToVBNet
          With CSVBConverter.ConvertMethodBody(TmpConvertCode)
            If .HasError Then
              Throw New NetVertException(.ErrorText)
            Else
              'success
              TmpConvertCode = .VBSource
            End If
          End With
          'get After-Convert-Comment-Sign
          TmpComment = "'"
        Case ConverterLanguagesAutodetectable.VBNetToCSharp
          With VBCSConverter.ConvertMethodBody(TmpConvertCode)
            If .HasError Then
              Throw New NetVertException(.ErrorText)
            Else
              'success
              TmpConvertCode = .CSharpSource
            End If
          End With
          'get After-Convert-Comment-Sign
          TmpComment = "//"
      End Select

      'Remove Temporary Out-Variable-Prefix
      TmpConvertCode = TmpConvertCode.Replace("NETVERTASPNETOUT ", "")
      'Insert HTML-Blocks
      For iBlock As Int32 = 0 To TmpHtmlBlocks.Count - 1
        TmpConvertCode = TmpConvertCode.Replace(TmpComment & "HTMLBLOCK-" & (iBlock + 1).ToString & ".", _
                                                TmpHtmlBlocks(iBlock))
      Next

      'set result
      RetConv.FResultSource = TmpConvertCode

#If DEBUG Then
      'catch only internal exceptions
    Catch nEx As NetVertException
      RetConv.FHasError = True
      RetConv.FErrorText = nEx.Message
#Else
      'catch all exceptions
    Catch ex As Exception
      RetConv.FHasError = True
      RetConv.FErrorText = ex.Message
#End If
    End Try
    Return RetConv
  End Function

#End Region

  'CONSTRUCTOR
  Private Sub New()
    'hidden .cstr
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Is an error detected.
  ''' </summary>
  ''' <returns>True if an error is detected.</returns>
  ''' <remarks>
  ''' If an error is detected the property <b>ErrorText</b> contains the details about the error.<br/>
  ''' If no error is detected,the property <b>CSharpSource</b> contains the result.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property HasError() As Boolean Implements INetVertConverter.HasError
    Get
      Return FHasError
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Error description.
  ''' </summary>
  ''' <returns></returns>
  ''' <remarks>
  ''' If the error is a parser error, 5 codelines are returned as well to show the position of error.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property ErrorText() As String Implements INetVertConverter.ErrorText
    Get
      Return FErrorText
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' The result ASPX code.
  ''' </summary>
  ''' <returns></returns>
  ''' <remarks>
  ''' Returns the converted ASP.NET source code, if no errors are detected.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property ASPXOutputSource() As String Implements INetVertConverter.OutputSource
    Get
      Return FResultSource
    End Get
  End Property

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' The used language for the conversion procedure.
  ''' </summary>
  ''' <returns></returns>
  ''' <remarks>
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property ConverterLanguage() As ConverterLanguagesAutodetectable
    Get
      Return FConverterLanguage
    End Get
  End Property

#End Region

  'PRIVATE SHARED
#Region "ASP.NET Parsing Methods"

  Private Shared Function SearchLanguage(ByVal aspxSource As String) As ConverterLanguages
    Dim TmpAspxLower As String
    Dim TmpPageStart As Int32
    Dim TmpPageEnd As Int32 = -1
    Dim TmpPageString As String
    Dim RetLng As ConverterLanguages

    TmpAspxLower = aspxSource.ToLower
    'search for page-directive
    TmpPageStart = TmpAspxLower.IndexOf("<%@ page")
    'search for control-directive if no page-directive was found
    If TmpPageStart = -1 Then TmpPageStart = TmpAspxLower.IndexOf("<%@ control")
    'search close-tag
    If TmpPageStart > -1 Then TmpPageEnd = TmpAspxLower.IndexOf("%>", TmpPageStart)
    If TmpPageEnd > -1 Then
      TmpPageString = TmpAspxLower.Substring(TmpPageStart, TmpAspxLower.Length - TmpPageEnd)
      If (TmpPageString.IndexOf(" language=""vb""") > -1) OrElse _
         (TmpPageString.IndexOf(" language=vb") > -1) Then
        'found VB.NET
        RetLng = ConverterLanguages.VBNetToCSharp
      ElseIf (TmpPageString.IndexOf(" language=""c#""") > -1) OrElse _
             (TmpPageString.IndexOf(" language=c#") > -1) OrElse _
             (TmpPageString.IndexOf(" language=cs") > -1) OrElse _
             (TmpPageString.IndexOf(" language=""cs""") > -1) Then
        'found C#
        RetLng = ConverterLanguages.CSharpToVBNet
      Else
        'no language= attribute found or language is not support
        Throw New NetVertException("The Page-Directive does not provide a supported language. The LANGUAGE attribute in the line '<%@ Page Language=""xx"" %>' must provide a supported value. Only the value 'VB' or 'CS' is supported at the placeholder 'xx'.")
      End If
    Else
      'no page-directive found
      Throw New NetVertException("Page-Directive not found. The line '<%@ Page Language=""xx"" %>' must be present in ASP.NET files.")
    End If
    Return RetLng
  End Function

#End Region

  '#Region "Helper Functions"

  '  Private Overloads Shared Function StrTrimmLeft(ByVal sourceString As String, _
  '                                          ByVal leftTrimmStrings() As String, _
  '                                          Optional ByVal trimmRecursive As Boolean = True) As String
  '    Dim RetS As String = sourceString
  '    Dim TmpB As Boolean

  '    Do
  '      'replace all strings
  '      For Each s As String In leftTrimmStrings
  '        RetS = StrTrimmLeft(sourceString, s, trimmRecursive)
  '      Next
  '      'look if still some strings are at the beginning
  '      TmpB = False
  '      For Each s As String In leftTrimmStrings
  '        If RetS.StartsWith(s) Then
  '          TmpB = True
  '          Exit For
  '        End If
  '      Next
  '    Loop While TmpB
  '    Return RetS
  '  End Function

  '  Private Overloads Shared Function StrTrimmLeft(ByVal sourceString As String, _
  '                                          ByVal leftTrimmString As String, _
  '                                          Optional ByVal trimmRecursive As Boolean = True) As String
  '    Dim RetS As String

  '    If (sourceString.Length >= leftTrimmString.Length) AndAlso _
  '       (Left(sourceString, leftTrimmString.Length).ToLower = leftTrimmString.ToLower) Then
  '      RetS = Right(sourceString, sourceString.Length - leftTrimmString.Length)
  '      If trimmRecursive Then
  '        RetS = StrTrimmLeft(RetS, leftTrimmString, True)
  '      End If
  '    Else
  '      RetS = sourceString
  '    End If
  '    Return RetS
  '  End Function

  '#End Region

End Class
