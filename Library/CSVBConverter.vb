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
''' Class	 : NetVert.CSVBConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts C# code to VB.NET code.
''' </summary>
''' <example> This sample shows how to convert C# code to VB.NET code.
''' You need a TextBox named <b>TxtFromCs</b> that contains the C# code and a
''' TextBox named <b>TxtToVb</b> where the resulting VB.NET will be filled in.
''' <code lang="Visual Basic">
'''     Sub ConvertCode()
'''       Dim TmpConv As CSVBConverter = CSVBConverter.Convert(TxtFromCs.Text)
'''       TxtToVb.Text = TmpConv.VBSource
'''       If TmpConv.HasError Then
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
'''       End If
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertCode()
'''       CSVBConverter TmpConv = CSVBConverter.Convert(TxtFromCs.Text);
'''       TxtToVb.Text = TmpConv.VBSource;
'''       if (TmpConv.HasError) {
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
'''       }
'''     }
''' </code>
''' This sample converts the same text, but only statements.
''' <code lang="Visual Basic">
'''     Sub ConvertStatements()
'''       Dim TmpConv As CSVBConverter = CSVBConverter.ConvertMethodBody(TxtFromCs.Text)
'''       TxtToVb.Text = TmpConv.VBSource
'''       If TmpConv.HasError Then
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
'''       End If
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertStatements()
'''       CSVBConverter TmpConv = CSVBConverter.ConvertMethodBody(TxtFromCs.Text);
'''       TxtToVb.Text = TmpConv.VBSource;
'''       if (TmpConv.HasError) {
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
'''       }
'''     }
''' </code>
''' </example>
''' <remarks>
''' Results of the <b>Convert</b>-Functions are returned as instances of this class.
''' </remarks>
''' <history>
'''   [esen]  15.07.2005  created
''' 	[esen]	17.10.2005	v1.0
''' 	[esen]	29.12.2005	v1.1
'''   [esen]  21.03.2006  v2.0
'''   [esen]  18.08.2006  v2.1
''' </history>
''' -----------------------------------------------------------------------------
Public NotInheritable Class CSVBConverter
  Implements INetVertConverter

  'NESTED CLASSES
#Region "CLASS:PreParseResult"

  Private Class PreParseResult

    'DECLARATIONS
    Public ResultString As String
    Public OriginalSourceLines As String()
    Public FirstLinesComments As String()
    Public LineShifts As New ArrayList

    'PUBLIC
    Public Function GetShift(ByVal lineNr As Int32) As Int32
      Dim RetI As Int32 = 0

      'Returns the amount of LineShift for the Codeline 'lineNr'
      For I As Int32 = 0 To LineShifts.Count - 1
        If CType(LineShifts(I), Int32) < lineNr Then
          RetI += 1
        End If
      Next
      Return RetI
    End Function

  End Class

#End Region

  'ENUMERATIONS
#Region "ENUM:CommentAreaKinds"

  Private Enum CommentAreaKinds
    Supported
    Unsupported
  End Enum

#End Region

  'DECLARATIONS
  Private FHasError As Boolean = False
  Private FErrorText As String = ""
  Private FResultSource As String = ""
  Private FOverloadableOperators() As String = Split("+ - IsFalse IsTrue Not + - * / \ & ^ >> << <> > < >= <= And Like Mod Or Xor CType", " ")
  Private SkipHandlingOfLines As New List(Of Int32)

  'SHARED
#Region "Convert Functions"

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Converts one or many namespaces, classes or methods.
  ''' </summary>
  ''' <param name="csSource">The C# source code.</param>
  ''' <param name="fixNamespaces">Comma-sepearated list of namespaces to fix (default is none).</param>
  ''' <returns>New instance of class CSVBConverter</returns>
  ''' <remarks>
  ''' Supported is any code that can be compiled with C# compiler, standing in a single .cs file.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Shared Function Convert(ByVal csSource As String, _
                                 Optional ByVal fixNamespaces As String = "", _
                                 Optional ByVal unwrapNamespace As String = "") As CSVBConverter
    Dim TmpPreResult As PreParseResult = Nothing
    Dim TmpVBSrc As String
    Dim doRetry As Boolean
    Dim RetConv As New CSVBConverter

    Do
      RetConv.FHasError = False
      RetConv.FErrorText = ""
      doRetry = False
      Try
        TmpPreResult = RetConv.PreParse(csSource, unwrapNamespace)
        TmpVBSrc = RetConv.ConvertSource(TmpPreResult.ResultString, TmpPreResult)
        RetConv.FResultSource = RetConv.PostParse(TmpVBSrc, TmpPreResult, fixNamespaces)
#If DEBUG Then
        'catch only internal exceptions
      Catch ex As NetVertException
        RetConv.FHasError = True
        RetConv.FErrorText = ex.Message
#Else
      'catch all exceptions
    Catch ex As Exception
      RetConv.FHasError = True
      RetConv.FErrorText = ex.Message
#End If
        If TypeOf ex Is NetVertException AndAlso _
           TmpPreResult IsNot Nothing Then
          With CType(ex, NetVertException)
            If .ErrorLine > 0 AndAlso _
               .ErrorLine <= TmpPreResult.OriginalSourceLines.Length AndAlso _
               RetConv.IsCommentOrEmptyLine(TmpPreResult.OriginalSourceLines(.ErrorLine - 1)) AndAlso _
               Not RetConv.SkipHandlingOfLines.Contains(.ErrorLine) Then
              RetConv.SkipHandlingOfLines.Add(.ErrorLine)
              doRetry = True
            End If
          End With
        End If
      End Try
    Loop While doRetry
    Return RetConv
  End Function

  ''' -----------------------------------------------------------------------------
  ''' <summary>
  ''' Converts codesnippets and simple statements.
  ''' </summary>
  ''' <param name="csMethodBody">C# source code of a function or procedure.</param>
  ''' <returns>New instance of class CSVBConverter</returns>
  ''' -----------------------------------------------------------------------------
  Public Shared Function ConvertMethodBody(ByVal csMethodBody As String) As CSVBConverter
    Dim TmpCSSrc As String = ""
    Dim TmpLines() As String
    Dim TmpConv As CSVBConverter

    'wrap BorderSub around the method body
    If csMethodBody <> "" Then
      TmpCSSrc = "void BorderSub() {" & vbCrLf & csMethodBody & vbCrLf & "}"
    End If
    'convert source
    TmpConv = Convert(TmpCSSrc)
    If Not TmpConv.HasError Then
      If csMethodBody <> "" Then
        'remove BorderSub
        Dim iStart As Int32 = TmpConv.FResultSource.IndexOf("BorderSub()") + 13
        Dim iEnd As Int32 = TmpConv.FResultSource.LastIndexOf("End Sub") - 2
        If iEnd > iStart Then
          TmpConv.FResultSource = TmpConv.FResultSource.Substring(iStart, iEnd - iStart)
        End If
        'TmpConv.FResultSource = TmpConv.FResultSource.Substring(19, TmpConv.FResultSource.Length - 30)
        'decrese indention (left-trimm 2 spaces)
        If TmpConv.FResultSource.IndexOf(vbCrLf) > -1 Then
          'Linebreak by CR-LF
          TmpLines = Split(TmpConv.FResultSource, vbCrLf)
        Else
          'Linebreak by LF
          TmpLines = Split(TmpConv.FResultSource, vbLf)
        End If
        For I As Int32 = 0 To TmpLines.Length - 1
          If (TmpLines(I).Length > 2) AndAlso _
             (TmpLines(I).Substring(0, 2) = "  ") Then
            TmpLines(I) = TmpLines(I).Substring(2, TmpLines(I).Length - 2)
          End If
        Next
        TmpConv.FResultSource = Join(TmpLines, vbCrLf)
      End If
    End If
    Return TmpConv
  End Function

  Public Shared Sub PostParseFilePair(ByRef mainFileSource As String, ByRef designerFileSource As String)
    'BEGIN EventHandler-Mapping
    'EventHandler-Mapping (.designer-File):
    '   "Me.Button1.Click += New System.EventHandler(Me.Button1_Click)"
    '     -> "AddHandler Me.Button1.Click, AddressOf Me.Button1_Click"
    Dim lastAssignPos As Int32 = 0
    Do
      lastAssignPos = designerFileSource.IndexOf(" += New System.EventHandler(", lastAssignPos + 1)
      If lastAssignPos = -1 Then
        Exit Do
      Else
        'process line
        Dim lineEnd As Int32 = designerFileSource.IndexOf(vbCrLf, lastAssignPos)
        If lineEnd = -1 Then Exit Do 'abort (must have end-of-line)
        Dim lineStart As Int32 = designerFileSource.Substring(0, lastAssignPos).LastIndexOf(vbCrLf)
        If lineStart = -1 Then lineStart = 0
        Dim handlerPos As Int32 = designerFileSource.IndexOf("Me.", lineStart)
        If handlerPos > lastAssignPos OrElse handlerPos = -1 Then Continue Do 'skip (must start with "Me.")
        Dim handlerDecl As String = designerFileSource.Substring(handlerPos, lastAssignPos - handlerPos).TrimEnd(" "c)
        If handlerDecl.Contains(" ") Then Continue Do 'skip (must not contain white-space)
        Dim closeBracePos As Int32 = designerFileSource.IndexOf(")", lastAssignPos)
        If closeBracePos > lineEnd OrElse closeBracePos < lastAssignPos + 28 Then Continue Do 'skip (must close the brace on same line)
        Dim eventDecl As String = designerFileSource.Substring(lastAssignPos + 28, closeBracePos - lastAssignPos - 28)
        'REPLACE CODE-LINE IN DESIGNER-FILE NOW
        designerFileSource = designerFileSource.Substring(0, handlerPos) & _
                             "AddHandler " & handlerDecl & ", AddressOf " & eventDecl & _
                             designerFileSource.Substring(closeBracePos + 1)
      End If
    Loop
    'END EventHandler-Mapping
  End Sub

#End Region

  'CONSTUCTOR
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
  ''' The result VB.NET source code.
  ''' </summary>
  ''' <returns></returns>
  ''' <remarks>
  ''' Returns the converted VB.NET source code, if no errors are detected.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property VBSource() As String Implements INetVertConverter.OutputSource
    Get
      Return FResultSource
    End Get
  End Property

#End Region

  'PRIVATE
#Region "Parse Process Functions"

  Private Function PreParse(ByVal csSrc As String, ByVal unwrapNamespace As String) As PreParseResult
    Dim TmpLines As String()
    Dim TmpLine As String
    Dim TmpFirstComments As String = ""
    Dim TmpBeforeCode As Boolean
    Dim TmpInClass As Boolean
    Dim TmpUnsupportedRangeCloseLine As Int32 = -1
    Dim TmpInCommentArea As CommentAreaKinds = CommentAreaKinds.Supported
    Dim TmpBorderCloseLine As Int32
    Dim TmpI As Int32
    Dim TmpI2 As Int32
    Dim RetRes As New PreParseResult

    'store original source lines
    If csSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      RetRes.OriginalSourceLines = Split(csSrc, vbCrLf)
    Else
      'Linebreak by LF
      RetRes.OriginalSourceLines = Split(csSrc, vbLf)
    End If
    'Replace TAB's with 2 spaces
    csSrc = csSrc.Replace(Chr(9), "  ")
    If ProviderHasParserFlag(ProviderParserFlags.HandleComments) Then
      'convert multiline comment-ranges to singleline comments
      'begin search on first sign (TmpI is current search position)
      TmpI = 0
      Do While (TmpI > -1) AndAlso (csSrc.IndexOf("/*", TmpI) > -1)
        'loop through every comment-range
        TmpI = csSrc.IndexOf("/*", TmpI)
        TmpI2 = csSrc.IndexOf("*/", TmpI + 2)
        If TmpI2 > -1 Then
          'check if this range-start is not allready a commentline
          If Not ((TmpI > 0) AndAlso (csSrc.Substring(TmpI - 1, 1) = "/")) Then
            'TmpI is the start of the commentrange
            If csSrc.IndexOf(vbCrLf) > -1 Then
              'Linebreak by CR-LF
              TmpLines = Split(csSrc.Substring(TmpI, TmpI2 - TmpI + 2), vbCrLf)
            Else
              'Linebreak by LF
              TmpLines = Split(csSrc.Substring(TmpI, TmpI2 - TmpI + 2), vbLf)
            End If
            'only modify comment-range if it has more than one line, otherwise skip
            If TmpLines.Length > 1 Then
              'only one line
              '  TmpLines(0) = "//" & TmpLines(0).Substring(2, TmpLines(0).Length - 4)
              'Else
              'multiple lines
              For L As Int32 = 0 To TmpLines.Length - 1
                If L = 0 Then
                  'first line
                  TmpLines(L) = "//" & TmpLines(L).Substring(2, TmpLines(L).Length - 2)
                ElseIf L = TmpLines.Length - 1 Then
                  'last line
                  TmpLines(L) = "//" & TmpLines(L).Substring(0, TmpLines(L).Length - 2)
                Else
                  'middle lines
                  TmpLines(L) = "//" & TmpLines(L)
                End If
              Next
              'store modified range
              csSrc = csSrc.Substring(0, TmpI) & _
                      Join(TmpLines, vbCrLf) & _
                      csSrc.Substring(TmpI2 + 2, csSrc.Length - TmpI2 - 2)
            Else
              'jump to next line
              TmpI2 = csSrc.IndexOf(vbCrLf, TmpI)
            End If
          Else
            'this range-start is a commentline, jump to next line
            TmpI2 = csSrc.IndexOf(vbCrLf, TmpI)
          End If
        End If
        'jump to TmpI2
        TmpI = TmpI2
      Loop
    End If 'ProviderHasParserFlag(ProviderParserFlags.HandleComments)
    'get all lines of code
    If csSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      TmpLines = Split(csSrc & vbCrLf, vbCrLf)
    Else
      'Linebreak by LF
      TmpLines = Split(csSrc & vbLf, vbLf)
    End If
    'process each line
    TmpBeforeCode = True
    TmpBorderCloseLine = TmpLines.Length - 1
    For I As Int32 = 0 To TmpLines.Length - 1
      If Me.SkipHandlingOfLines.Contains(I + 1) Then
        'this line is skipped from handling, because of error before
        Continue For
      End If
      'get line without leading spaces
      TmpLine = StrTrimmLeft(StrTrimmLeft(TmpLines(I), " ", True), Chr(9).ToString, True)
      If TmpLine.Length = 0 Then
        'empty line
        If ProviderHasParserFlag(ProviderParserFlags.HandleEmptyLines) Then
          If TmpInClass AndAlso _
             (TmpInCommentArea = CommentAreaKinds.Supported) AndAlso _
             ProviderHasParserFlag(ProviderParserFlags.HandleComments) Then
            TmpLines(I) = "string EmptyLineVar;"
          End If
        End If
      Else
        If (TmpLine.Length > 1) AndAlso _
           (TmpLine.Substring(0, 2) = "//") Then
          If ProviderHasParserFlag(ProviderParserFlags.HandleComments) Then
            'current line is a comment
            If TmpBeforeCode Then
              TmpFirstComments &= TmpLine & vbCrLf
            ElseIf TmpInClass AndAlso (TmpUnsupportedRangeCloseLine = -1) Then
              If (TmpInCommentArea = CommentAreaKinds.Supported) AndAlso _
                 NextCodeLineHasNoneOfKeywords(TmpLines, I, New String() {"get", "set"}) Then
                TmpLines(I) = "string CommentVar = """ & TmpLine.Replace("""", "§§").Replace("\", "§$") & """;"
              End If
            End If
          End If
        ElseIf TmpLine.Substring(0, 1) = "#" Then
          If ProviderHasParserFlag(ProviderParserFlags.HandleComments) Then
            'current line is a compilerarg or region
            If TmpBeforeCode Then
              TmpFirstComments &= TmpLine & vbCrLf
            ElseIf TmpInClass AndAlso (TmpInCommentArea = CommentAreaKinds.Supported) Then
              TmpLines(I) = "string RegionVar = """ & TmpLine.Replace("""", "§§").Replace("\", "§$") & """;"
            End If
          End If
        Else
          TmpBeforeCode = False
          If ((TmpLine.Length > 6) AndAlso (TmpLine.Substring(0, 6).ToLower = "using ")) Then
            'before add border class (USING statement)
          ElseIf (TmpLine.ToLower.IndexOf("assembly: ") > -1) Then
            'before add border class (ASSEMBLY statement)
          ElseIf ((TmpLine.Length > 10) AndAlso (TmpLine.Substring(0, 10).ToLower = "namespace ")) Then
            'before add border class (NAMESPACE statement)
            Dim removeNamespace As Boolean = False
            If TmpLine.Length > 10 + unwrapNamespace.Length + 1 AndAlso _
               TmpLine.Substring(0, 10 + unwrapNamespace.Length + 1).ToLower() = "namespace " & unwrapNamespace.ToLower() & "." Then
              'trim namespace
              TmpLines(I) = "namespace " & TmpLine.Substring(10 + unwrapNamespace.Length + 1)
            Else
              'remove namespace
              removeNamespace = True
              TmpLines(I) = ""
            End If
            If TmpLine.IndexOf("{") > -1 Then
              TmpI = GetCloseTagLine(TmpLines, I)
              If removeNamespace Then
                TmpLines(TmpI) = ""
              End If
            Else
              TmpI = GetCloseTagLine(TmpLines, I + 1)
              If removeNamespace Then
                TmpLines(I + 1) = ""
                TmpLines(TmpI) = ""
              End If
            End If
            If TmpI > -1 Then
              TmpBorderCloseLine = TmpI
            End If
            If (I < TmpBorderCloseLine) Then
              If TmpLine.IndexOf("{") > -1 Then
                'add borderclass now after current line
                TmpI = I
              Else
                'add borderclass now after next line witch should be '{'
                TmpI = I + 1
              End If
              TmpInClass = True
              TmpLines(TmpI) = TmpLines(TmpI) & vbCrLf & "class BorderClass" & vbCrLf & "{"
              TmpLines(TmpBorderCloseLine) = "}" & vbCrLf & TmpLines(TmpBorderCloseLine)
              RetRes.LineShifts.Add(RetRes.GetShift(TmpI) + TmpI)
              RetRes.LineShifts.Add(RetRes.GetShift(TmpI) + TmpI + 1)
              RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine)
            End If
          Else
            If (I >= TmpBorderCloseLine) Then
              TmpInClass = False
            Else
              If Not TmpInClass Then
                For J As Int32 = I + 1 To TmpLines.Length - 1
                  If (TmpLines(J).ToLower.IndexOf("namespace") > -1) Then
                    TmpBorderCloseLine = J - 1
                    Exit For
                  End If
                Next
                'add borderclass now before current line
                TmpInClass = True
                TmpLine = "class BorderClass" & vbCrLf & "{" & vbCrLf & TmpLines(I)
                TmpLines(I) = TmpLine
                TmpLines(TmpBorderCloseLine) = TmpLines(TmpBorderCloseLine) & vbCrLf & "}" '& vbCrLf
                RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                RetRes.LineShifts.Add(RetRes.GetShift(I) + I + 1)
                RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine)
              End If
            End If
            If ProviderHasParserFlag(ProviderParserFlags.HandleSomeNet2LangFeatures) Then
              If KeywordInLine(TmpLine, "partial ") > -1 Then
                'support for .NET 2.0 Language keywords: "Partial" classes
                TmpLines(I) = TmpLine.Replace("partial ", "").TrimEnd(" "c) & "PartialClassConverted"
              End If
              If KeywordInLine(TmpLine, "operator ") > -1 Then
                'support for VB.NET 2.0 Language keywords: "Operator overloading" (C# supports operator overloading since v1.0)
                For iOp As Int32 = 0 To FOverloadableOperators.Length - 1
                  TmpLines(I) = TmpLine.Replace("operator " & FOverloadableOperators(iOp), "Operator_" & iOp.ToString)
                Next
              End If
            End If
          End If
          If TmpUnsupportedRangeCloseLine = I Then
            TmpUnsupportedRangeCloseLine = -1
            TmpInCommentArea = CommentAreaKinds.Supported
          ElseIf (KeywordInLine(TmpLine, "interface ") > -1) Then
            If TmpLine.LastIndexOf("{") > KeywordInLine(TmpLine, "interface ") Then
              TmpI = I
            Else
              TmpI = I + 1
            End If
            TmpUnsupportedRangeCloseLine = GetCloseTagLine(TmpLines, TmpI)
            TmpInCommentArea = CommentAreaKinds.Unsupported
          ElseIf (KeywordInLine(TmpLine, "enum ") > -1) Then
            If TmpLine.LastIndexOf("{") > KeywordInLine(TmpLine, "enum ") Then
              TmpI = I
            Else
              TmpI = I + 1
            End If
            TmpUnsupportedRangeCloseLine = GetCloseTagLine(TmpLines, TmpI)
            TmpInCommentArea = CommentAreaKinds.Unsupported
          End If
        End If
      End If 'TmpLine.Length = 0
    Next
    'assign first comments
    RetRes.FirstLinesComments = Split(TmpFirstComments, vbCrLf)
    'assign result string
    RetRes.ResultString = Join(TmpLines, vbCrLf)
    Return RetRes
  End Function

  Private Function ConvertSource(ByVal csSrc As String, ByVal preResult As PreParseResult) As String
    Dim TmpRefactoryProvider As IRefactoryProvider
    Dim TmpI As Int32
    Dim TmpLine As Int32
    Dim TmpLines As String()
    Dim TmpS As String
    Dim RetS As String = ""

    'get current RefacotryProvider
    TmpRefactoryProvider = SettingsManager.CurrentRefactoryProvider
    'convert with the RefactoryProvider
    Try
      RetS = TmpRefactoryProvider.ConvertCStoVB(csSrc)
    Catch ex As NetVertException
      'parser error, modify text and re-throw exception
      TmpS = ex.Message.Substring(8, ex.Message.Length - 9)
      TmpI = TmpS.IndexOf(" ")
      TmpLine = Int32.Parse(TmpS.Substring(0, TmpI))
      TmpLine -= preResult.GetShift(TmpLine)
      If TmpLine = 0 Then TmpLine = 1
      TmpS = "Line " & TmpLine.ToString & TmpS.Substring(TmpI, TmpS.Length - TmpI)
      TmpLines = preResult.OriginalSourceLines
      If TmpLine > 1 Then
        If TmpLine > 2 Then
          TmpS &= vbCrLf & "==== " & TmpLines(TmpLine - 3)
        End If
        TmpS &= vbCrLf & "==== " & TmpLines(TmpLine - 2)
      End If
      If TmpLines.Length >= TmpLine Then
        TmpS &= vbCrLf & "==>> " & TmpLines(TmpLine - 1)
        If TmpLines.Length > TmpLine Then
          TmpS &= vbCrLf & "==== " & TmpLines(TmpLine)
          If TmpLines.Length > (TmpLine + 1) Then
            TmpS &= vbCrLf & "==== " & TmpLines(TmpLine + 1)
          End If
        End If
      End If
      Throw New NetVertException(TmpS, TmpLine)
    End Try
    Return RetS
  End Function

  Private Function PostParse(ByVal vbSrc As String, _
                             ByVal preResult As PreParseResult, _
                             ByVal fixNamespaces As String) As String
    Dim TmpLines As String()
    Dim TmpLine As String
    Dim TmpB As Boolean = False
    Dim TmpStart As Int32
    Dim TmpI As Int32
    Dim TmpS As String
    Dim TmpS2 As String
    Dim TmpS3 As String
    Dim TmpBorderClassIndent As Int32 = -1
    Dim TmpInOperator As Boolean = False
    Dim TmpInSelect As Boolean = False
    Dim RetS As String

    'Replace TAB's with 2 spaces
    vbSrc = vbSrc.Replace(Chr(9), "  ")
    'repair string-append syntax 'str += "blabla"' --> 'str &= "blabla"'
    vbSrc = vbSrc.Replace(" += """, " &= """)
    'get all lines of code
    If vbSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      TmpLines = Split(vbSrc, vbCrLf)
    Else
      'Linebreak by LF
      TmpLines = Split(vbSrc, vbLf)
    End If
    'process each line (fix parser bugs)
    For Y As Int32 = 0 To TmpLines.Length - 1
      If ProviderHasParserFlag(ProviderParserFlags.HandleICSharpCodeParserBugs) Then
        'repair Parser-Bug "wrong enumumeration declarations" (remove incorrect 'private' prefix)
        If TmpB Then
          If TmpLines(Y).ToLower.IndexOf("end enum") > -1 Then
            TmpB = False
          Else
            TmpLines(Y) = TmpLines(Y).Replace("Private ", "")
          End If
        Else
          If KeywordInLine(TmpLines(Y), "enum ") > -1 Then
            TmpB = True
          End If
        End If
        'repair Parser-Bug "wrong indexvariable incrementation in 'while' and 'for' statements"
        'System.Math.Min(System.Threading.Interlocked.Increment(I),I-1) -->  I += 1
        TmpStart = TmpLines(Y).ToLower.IndexOf("system.math.min(system.threading.interlocked.increment(")
        If TmpStart > -1 Then
          TmpS = TmpLines(Y).Substring(TmpStart + 55)
          TmpI = TmpS.IndexOf(")")
          If TmpI > -1 Then
            'store code after statement in TmpS2
            If TmpS.Length > (5 + (TmpI * 2)) Then
              TmpS2 = TmpS.Substring((5 + (TmpI * 2)), TmpS.Length - (5 + (TmpI * 2)))
            Else
              TmpS2 = ""
            End If
            'store I-variable in TmpS
            TmpS = TmpS.Substring(0, TmpI)
            'overwrite current line
            TmpLines(Y) = TmpLines(Y).Substring(0, TmpStart) & TmpS & " += 1" & TmpS2
          End If
        End If
        'repair Parser-Bug "wrong explicit typecast"
        'CType(ConversionHelpers.AsWorkaround(myvalue, GetType(mytype)), mytype) --> CType(myvalue, mytype)
        TmpStart = TmpLines(Y).ToLower.IndexOf("ctype(conversionhelpers.asworkaround(")
        If TmpStart > -1 Then
          TmpS = TmpLines(Y).Substring(TmpStart + 37)
          TmpI = TmpS.IndexOf(",")
          If TmpI > -1 Then
            'store value in TmpS2
            TmpS2 = TmpS.Substring(0, TmpI)
            TmpI = TmpS.IndexOf("(")
            If TmpI > -1 Then
              TmpS = TmpS.Substring(TmpI, TmpS.Length - TmpI)
              TmpI = TmpS.IndexOf(")")
              If TmpI > -1 Then
                'store code after statement in TmpS3
                If TmpS.Length > (5 + (TmpI * 2)) Then
                  TmpS3 = TmpS.Substring((5 + (TmpI * 2)), TmpS.Length - (5 + (TmpI * 2)))
                Else
                  TmpS3 = ""
                End If
                'store type in TmpS
                TmpS = TmpS.Substring(0, TmpI)
                'overwrite current line
                TmpLines(Y) = TmpLines(Y).Substring(0, TmpStart) & "CType(" & TmpS2 & ", " & TmpS & ")" & TmpS3
              End If
            End If
          End If
        End If
        'repair Parser-Bug "multiple attributes on multiple lines have only one < on first and one > on last line"
        '<MyAttrX()> _[CRLF]<MyAttrY()> _[CRLF]<MyAttrZ()>  -->  <MyAttrX(), _[CRLF] MyAttrY(), _[CRLF] MyAttrZ()>
        If (TmpLines(Y).Length > 3) AndAlso _
           (TmpLines(Y).Substring(TmpLines(Y).Length - 3, 3) = "> _") AndAlso _
           (TmpLines.Length > Y + 1) Then
          'store next line without leading SPACE and TAB in TmpLine
          TmpLine = StrTrimmLeft(StrTrimmLeft(TmpLines(Y + 1), Chr(9).ToString), " ")
          If (TmpLine.Length > 1) AndAlso _
             (TmpLine.Substring(0, 1) = "<") Then
            'preserve Spaces before TmpLine in TmpS
            If TmpLines(Y + 1).Length > TmpLine.Length Then
              TmpS = TmpLines(Y + 1).Substring(0, TmpLines(Y + 1).Length - TmpLine.Length)
            Else
              TmpS = ""
            End If
            'replace "> _" with ", _" at end of this line
            TmpLines(Y) = TmpLines(Y).Substring(0, TmpLines(Y).Length - 3) & ", _"
            'replace "<" with " " at begin of next line
            TmpLines(Y + 1) = TmpS & " " & TmpLine.Substring(1, TmpLine.Length - 1)
          End If
        End If
      End If 'ProviderHasParserFlag(ProviderParserFlags.HandleICSharpCodeParserBugs)
    Next
    'Lines -> String (Add Prefix: CRLF)
    vbSrc = vbCrLf & Join(TmpLines, vbCrLf)
    'fix namespaces (remove)
    If fixNamespaces <> "" Then
      For Each ns As String In Split(fixNamespaces, ",")
        vbSrc = vbSrc.Replace(vbCrLf & "Imports " & ns & vbCrLf, vbCrLf)
      Next
    End If
    'get all lines of code: String -> Lines (Remove Prefix: CRLF)
    TmpLines = Split(vbSrc.Substring(2, vbSrc.Length - 2), vbCrLf)
    'process each line (restore comments and regions)
    For I As Int32 = 0 To TmpLines.Length - 1
      If (TmpBorderClassIndent > -1) AndAlso _
         (TmpLines(I).Length >= TmpBorderClassIndent + 9) AndAlso _
         (TmpLines(I).Substring(TmpBorderClassIndent, 9) = "End Class") Then
        'remove end of BorderClass
        TmpBorderClassIndent = -1
        'mark line with KILL if its not last line
        If (TmpLines.Length > I + 1) Then
          TmpLines(I) = "KILL"
        End If
      ElseIf TmpLines(I).IndexOf("Class BorderClass") > -1 Then
        'remove begin of BorderClass
        TmpLine = StrTrimmLeft(TmpLines(I), " ", True)
        TmpBorderClassIndent = TmpLines(I).Length - TmpLine.Length
        TmpLines(I) = "KILL"
        If (I > 0) AndAlso _
           (TmpLines(I - 1) = "") Then
          'remove empty line before BorderClass (mark with KILL)
          TmpLines(I - 1) = "KILL"
        End If
        'mark next line after BorderClass with KILL if its empty and not last line
        If (TmpLines.Length > I + 1) AndAlso _
           (TmpLines(I + 1) = "") Then
          TmpLines(I + 1) = "KILL"
        End If
      Else
        If (TmpBorderClassIndent > -1) AndAlso _
           (TmpLines(I).Length > 2) AndAlso _
           (StrTrimmLeft(TmpLines(I).Substring(0, 2), " ") = "") Then
          'correct indention (remove 2 spaces because of BorderClass)
          TmpLines(I) = TmpLines(I).Substring(2, TmpLines(I).Length - 2)
        End If
        'get line without leading spaces
        TmpLine = StrTrimmLeft(TmpLines(I), " ", True)
        'preserve spaces
        TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
        If TmpLine.Length > 0 Then
          'skip empty lines
          If (TmpLine.Length > 25) AndAlso _
             (TmpLine.Substring(0, 25).ToLower = "dim commentvar as string ") Then
            'convert comment
            TmpLines(I) = TmpS & CSharpToVbComment(TmpLine.Substring(28, TmpLine.Length - 29))
            'mark next line with KILL if its empty and not last line
            If (TmpLines.Length > I + 1) AndAlso _
               (TmpLines(I + 1) = "") Then
              TmpLines(I + 1) = "KILL"
            End If
          ElseIf (TmpLine.Length > 29) AndAlso _
             (TmpLine.Substring(0, 29).ToLower = "private commentvar as string ") Then
            'convert comment
            TmpLines(I) = TmpS & CSharpToVbComment(TmpLine.Substring(32, TmpLine.Length - 33))
            'mark next line with KILL if its empty and not last line
            If (TmpLines.Length > I + 1) AndAlso _
               (TmpLines(I + 1) = "") Then
              TmpLines(I + 1) = "KILL"
            End If
          ElseIf (TmpLine.Length > 24) AndAlso _
                 (TmpLine.Substring(0, 24).ToLower = "dim regionvar as string ") Then
            'convert region or compilerarg
            TmpLines(I) = CSharpToVbComment(TmpLine.Substring(27, TmpLine.Length - 28))
          ElseIf (TmpLine.Length > 28) AndAlso _
                 (TmpLine.Substring(0, 28).ToLower = "private regionvar as string ") Then
            'convert region or compilerarg
            TmpLines(I) = CSharpToVbComment(TmpLine.Substring(31, TmpLine.Length - 32))
          ElseIf (TmpLine Like "* EmptyLineVar As String*") Then
            'Empty Line
            TmpLines(I) = ""
          ElseIf TmpLine.IndexOf("PartialClassConverted") > -1 Then
            'restore Partial class (new .NET 2.0 feature)
            TmpLines(I) = TmpLines(I).Replace("PartialClassConverted", "").Replace("Class ", "Partial Class ")
            ''restore Partial class (new .NET 2.0 feature)
            'TmpLines(i) = TmpS & "Partial " & TmpLine.Replace("PartialClassConverted", "")
          ElseIf TmpLine.IndexOf("Operator_") > -1 Then
            'restore "Operator Overloading" Part1 (new .NET 2.0 feature for VB.NET)
            For iOp As Int32 = 0 To FOverloadableOperators.Length - 1
              TmpLines(I) = TmpLines(I).Replace("Function Operator_" & iOp.ToString, "Operator " & FOverloadableOperators(iOp))
              TmpInOperator = True
            Next
          ElseIf TmpLine Like "Select Case *" Then
            'begin of SELECT CASE
            TmpInSelect = True
          ElseIf (TmpLine Like "Exit Select*") AndAlso _
                 TmpInSelect Then
            'inside SELECT CASE
            'delete EXIT SELECT, if next statement is CASE
            If NextCodeLineHasNoneOfKeywords(TmpLines, I, New String() {"Case"}) Then
              TmpLines(I) = "KILL"
            End If
          ElseIf (TmpLine = "End Select") AndAlso _
                 TmpInSelect Then
            'end of SELECT CASE
            TmpInSelect = False
          ElseIf (TmpLine = "End Function") AndAlso _
                 TmpInOperator Then
            'restore "Operator Overloading" Part2 (new .NET 2.0 feature for VB.NET)
            'End Function -> End Operator
            TmpLines(I) = TmpS & "End Operator"
          ElseIf TmpLine Like "*If * = Nothing*" Then
            'repair compiration of Nothing (must be "is" instead of "=")
            TmpLines(I) = TmpS & TmpLine.Replace("= Nothing", "Is Nothing")
          ElseIf TmpLine Like "*If * <> Nothing*" Then
            'repair compiration of Not-Nothing (must be "is" instead of "=")
            TmpLines(I) = TmpS & TmpLine.Replace("<> Nothing", "Is Nothing").Replace("If ", "If Not ")
          End If
        End If
      End If
    Next
    'get first lines comments and regions
    TmpS = ""
    For I As Int32 = 0 To preResult.FirstLinesComments.Length - 1
      If preResult.FirstLinesComments(I) <> "" Then
        TmpS &= CSharpToVbComment(preResult.FirstLinesComments(I)) & vbCrLf
      End If
    Next
    'insert first lines at beginning
    RetS = TmpS & Join(TmpLines, vbCrLf) & vbCrLf
    'remove all lines that are marked with KILL
    RetS = RetS.Replace("KILL" & vbCrLf, "")
    Return RetS
  End Function

#End Region

#Region "Helper Functions"

  Private Function NextCodeLineHasNoneOfKeywords(ByVal codeLines() As String, _
                                                 ByVal currentLine As Int32, _
                                                 ByVal keywords() As String) As Boolean
    Dim TmpS As String
    Dim RetB As Boolean = True

    TmpS = GetNextCodeLine(codeLines, currentLine)
    For I As Int32 = 0 To keywords.Length - 1
      If (KeywordInLine(TmpS, keywords(I) & " ") > -1) OrElse _
         ((KeywordInLine(TmpS, keywords(I)) > -1) AndAlso TmpS.EndsWith(keywords(I))) Then
        RetB = False
        Exit For
      End If
    Next
    Return RetB
  End Function

  Private Function GetNextCodeLine(ByVal codeLines() As String, _
                                   ByVal currentLine As Int32) As String
    Dim TmpLine As String
    Dim RetS As String = ""

    For I As Int32 = currentLine + 1 To codeLines.Length - 1
      TmpLine = StrTrimmLeft(StrTrimmLeft(codeLines(I), " ", True), Chr(9).ToString, True)
      If (TmpLine.Length > 0) AndAlso _
         (TmpLine.Substring(0, 1) <> "/") AndAlso _
         (TmpLine.Substring(0, 1) <> "#") AndAlso _
         (TmpLine.TrimEnd(" "c) <> "{") AndAlso _
         (TmpLine.TrimEnd(" "c) <> "}") Then
        'codeLines(I) is a valid codeline (not empty, not a comment, not a compiler-arg or region, not a braket)
        RetS = codeLines(I)
        Exit For
      End If
    Next
    Return RetS
  End Function

  Private Function KeywordInLine(ByVal codeLine As String, ByVal keyWordWithSufix As String) As Int32
    Dim TmpS As String
    Dim RetI As Int32

    RetI = codeLine.ToLower.IndexOf(keyWordWithSufix)
    If RetI > 0 Then
      'check if sign before keyword is SPACE ot TAB
      TmpS = codeLine.Substring(RetI - 1, 1)
      If (TmpS <> " ") AndAlso _
         (TmpS <> Chr(9).ToString) Then
        RetI = -1
      End If
    End If
    Return RetI
  End Function

  Private Function LineInSource(ByVal sourceString As String, _
                                ByVal codeLine As String) As Boolean
    Dim TmpI As Int32
    Dim RetB As Boolean = False

    TmpI = sourceString.IndexOf(codeLine & vbCrLf)
    If TmpI = 0 Then
      RetB = True
    ElseIf TmpI > 0 Then
      Do
        TmpI -= 1
        If sourceString.Substring(TmpI - 1, 2) = vbCrLf Then
          RetB = True
          Exit Do
        End If
      Loop While (sourceString.Substring(TmpI, 1) = " ")
    End If
    Return RetB
  End Function

  Private Function GetCloseTagLine(ByVal codeLines() As String, ByVal openTagLine As Int32) As Int32
    Dim TmpOpenCount As Int32 = 1
    Dim RetI As Int32 = -1

    For I As Int32 = openTagLine + 1 To codeLines.Length - 1
      For Isign As Int32 = 0 To codeLines(I).Length - 1
        If codeLines(I).Substring(Isign, 1) = "{" Then
          TmpOpenCount += 1
        ElseIf codeLines(I).Substring(Isign, 1) = "}" Then
          TmpOpenCount -= 1
        End If
        If TmpOpenCount = 0 Then
          Exit For
        End If
      Next
      If TmpOpenCount = 0 Then
        RetI = I
        Exit For
      End If
    Next
    Return RetI
  End Function

  Private Function CSharpToVbComment(ByVal commentLine As String) As String
    Dim RetS As String = ""

    commentLine = commentLine.Replace("§§", """").Replace("§$", "\")
    If commentLine.Length > 1 Then
      If (commentLine.Length > 2) AndAlso _
         commentLine.Substring(0, 3) = "///" Then
        'line is a docu-comment (xml)
        RetS = "'''" & commentLine.Substring(3, commentLine.Length - 3)
      ElseIf commentLine.Substring(0, 2) = "//" Then
        'line is a comment
        RetS = "'" & commentLine.Substring(2, commentLine.Length - 2)
      ElseIf (commentLine.Length > 7) AndAlso _
             (commentLine.Substring(0, 7).ToLower = "#region") Then
        'Region
        RetS = "#Region """ & commentLine.Substring(8, commentLine.Length - 8) & """"
      ElseIf (commentLine.Length >= 10) AndAlso _
             (commentLine.Substring(0, 10).ToLower = "#endregion") Then
        'End Region
        RetS = "#End Region"
      ElseIf (commentLine.Length > 3) AndAlso _
             (commentLine.Substring(0, 3).ToLower = "#if") Then
        '#If
        RetS = "#If " & ConvertIfStatement(commentLine.Substring(3, commentLine.Length - 3)) & " Then"
      ElseIf (commentLine.Length >= 6) AndAlso _
            (commentLine.Substring(0, 6).ToLower = "#endif") Then
        '#End If
        RetS = "#End If"
      ElseIf commentLine.Substring(0, 1) = "#" Then
        'something else with a leading #
        RetS = commentLine
      End If
    End If
    Return RetS
  End Function

  Private Function StrTrimmLeft(ByVal sourceString As String, _
                               ByVal leftTrimmString As String, _
                               Optional ByVal trimmRecursive As Boolean = True) As String
    Dim RetS As String

    If (sourceString.Length >= leftTrimmString.Length) AndAlso _
       (Left(sourceString, leftTrimmString.Length).ToLower = leftTrimmString.ToLower) Then
      RetS = Right(sourceString, sourceString.Length - leftTrimmString.Length)
      If trimmRecursive Then
        RetS = StrTrimmLeft(RetS, leftTrimmString, True)
      End If
    Else
      RetS = sourceString
    End If
    Return RetS
  End Function

  Private Function ConvertIfStatement(ByVal ifStatement As String) As String
    Dim TmpRefactoryProvider As IRefactoryProvider
    Dim TmpSrc As String
    Dim TmpI As Int32
    Dim RetS As String = ""

    'get current RefacotryProvider
    TmpRefactoryProvider = SettingsManager.CurrentRefactoryProvider
    'wrap BorderClass, BorderSub and If-Block around the ifStatement
    TmpSrc = "class BorderClass {" & vbCrLf & _
             "void BorderSub() {" & vbCrLf & _
             "if " & ifStatement & " { }" & vbCrLf & _
             "}" & vbCrLf & _
             "}"
    Try
      'convert with the RefactoryProvider
      RetS = TmpRefactoryProvider.ConvertCStoVB(TmpSrc)
      'remove all wrapped Borders
      TmpI = RetS.IndexOf("If")
      RetS = RetS.Substring(TmpI + 3, RetS.IndexOf("Then", TmpI) - TmpI - 4)
    Catch ex As Exception
      'could not convert statement, return orginal
      RetS = ifStatement
    End Try
    Return RetS
  End Function

  Private Function ProviderHasParserFlag(ByVal parserFlag As ProviderParserFlags) As Boolean
    Return (SettingsManager.CurrentRefactoryProvider.PreAndPostParseFlags And parserFlag) = parserFlag
  End Function

  Private Function IsCommentOrEmptyLine(ByVal codeLine As String) As Boolean
    Dim truncLine As String = codeLine.TrimStart(" "c, Chr(9))
    Return (truncLine.StartsWith("//") OrElse truncLine.Length = 0)
  End Function

#End Region

End Class
