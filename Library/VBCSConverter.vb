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
''' Class	 : NetVert.VBCSConverter
''' -----------------------------------------------------------------------------
''' <summary>
''' Converts VB.NET code to C# code.
''' </summary>
''' <example> This sample shows how to convert VB.NET code to C# code.
''' You need a TextBox named <b>TxtFromVb</b> that contains the VB.NET code and a
''' TextBox named <b>TxtToCs</b> where the resulting C# will be filled in.
''' <code lang="Visual Basic">
'''     Sub ConvertCode()
'''       Dim TmpConv As VBCSConverter = VBCSConverter.Convert(TxtFromVb.Text)
'''       TxtToCs.Text = TmpConv.CSharpSource
'''       If TmpConv.HasError Then
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
'''       End If
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertCode()
'''       VBCSConverter TmpConv = VBCSConverter.Convert(TxtFromVb.Text);
'''       TxtToCs.Text = TmpConv.CSharpSource;
'''       if (TmpConv.HasError) {
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
'''       }
'''     }
''' </code>
''' This sample converts the same text, but only statements.
''' <code lang="Visual Basic">
'''     Sub ConvertStatements()
'''       Dim TmpConv As VBCSConverter = VBCSConverter.ConvertMethodBody(TxtFromVb.Text)
'''       TxtToCs.Text = TmpConv.CSharpSource
'''       If TmpConv.HasError Then
'''         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
'''       End If
'''     End Sub
''' </code>
''' <code lang="C#">
'''     void ConvertStatements()
'''       VBCSConverter TmpConv = VBCSConverter.ConvertMethodBody(TxtFromVb.Text);
'''       TxtToCs.Text = TmpConv.CSharpSource;
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
Public NotInheritable Class VBCSConverter
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
    TopOfClass
    BetweenPropertyMethods
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
  ''' <param name="vbSource">The VB.NET source code.</param>
  ''' <param name="fixNamespaces">Comma-sepearated list of namespaces to fix (default is none).</param>
  ''' <returns>New instance of class VBCSConverter</returns>
  ''' <remarks>
  ''' Supported is any code that can be compiled with VB.NET compiler, standing in a single .vb file.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Shared Function Convert(ByVal vbSource As String, _
                                 Optional ByVal fixNamespaces As String = "", _
                                 Optional ByVal wrapNamespace As String = "") As VBCSConverter
    Dim TmpPreResult As PreParseResult = Nothing
    Dim TmpCSSrc As String
    Dim doRetry As Boolean
    Dim RetConv As New VBCSConverter

    Do
      RetConv.FHasError = False
      RetConv.FErrorText = ""
      doRetry = False
      Try
        TmpPreResult = RetConv.PreParse(vbSource, wrapNamespace)
        TmpCSSrc = RetConv.ConvertSource(TmpPreResult.ResultString, TmpPreResult)
        RetConv.FResultSource = RetConv.PostParse(TmpCSSrc, TmpPreResult, fixNamespaces)
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
            'If .ErrorLine > 0 AndAlso _
            '   .ErrorLine <= TmpPreResult.OriginalSourceLines.Length AndAlso _
            '   RetConv.IsCommentOrEmptyLine(TmpPreResult.OriginalSourceLines(.ErrorLine - 1)) AndAlso _
            '   Not RetConv.SkipHandlingOfLines.Contains(.ErrorLine) Then
            If .ErrorLine > 0 AndAlso _
               .ErrorLine <= TmpPreResult.OriginalSourceLines.Length AndAlso _
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
  ''' <param name="vbMethodBody">VB.NET source code of a function or procedure.</param>
  ''' <returns>New instance of class VBCSConverter</returns>
  ''' <remarks>
  ''' Supported are single or multiple lines of code that can be placed inside a procedure.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public Shared Function ConvertMethodBody(ByVal vbMethodBody As String) As VBCSConverter
    Dim TmpVBSrc As String = ""
    Dim TmpLines() As String
    Dim TmpConv As VBCSConverter

    If vbMethodBody <> "" Then
      'wrap BorderSub around the method body
      TmpVBSrc = "Sub BorderSub()" & vbCrLf & vbMethodBody & vbCrLf & "End Sub"
    End If
    'convert source
    TmpConv = Convert(TmpVBSrc)
    If (Not TmpConv.HasError) AndAlso _
       (vbMethodBody <> "") Then
      'remove BorderSub
      Dim iStart As Int32 = TmpConv.FResultSource.IndexOf("{") + 3
      Dim iEnd As Int32 = TmpConv.FResultSource.LastIndexOf("}") - 2
      If iEnd > iStart Then
        TmpConv.FResultSource = TmpConv.FResultSource.Substring(iStart, iEnd - iStart)
      End If
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
    Return TmpConv
  End Function

  Public Shared Sub PreParseFilePair(ByRef mainFileSource As String, ByRef designerFileSource As String)
    'BEGIN C# spezification
    'C# spezification: "partial" keyword must be spezified on all class declarations
    Dim iDStart As Int32 = designerFileSource.IndexOf("Partial Class ")
    If iDStart > -1 Then
      Dim iDEnd As Int32 = designerFileSource.IndexOf(vbCrLf, iDStart)
      Dim className As String = designerFileSource.Substring(iDStart + 14, iDEnd - iDStart - 14)
      Dim iMStart As Int32 = mainFileSource.IndexOf("Class " & className & vbCrLf)
      If iMStart > -1 Then
        Dim iMLineEnd As Int32 = iMStart + 6 + className.Length
        Dim mainBlocks() As String = New String() {"", "", ""}
        Dim preStartSrc As String = mainFileSource.Substring(0, iMStart)
        Dim iMLineStart As Int32 = preStartSrc.LastIndexOf(vbCrLf)
        If iMLineStart = -1 Then
          mainBlocks(1) = mainFileSource.Substring(0, iMLineEnd)
        Else
          mainBlocks(0) = mainFileSource.Substring(0, iMLineStart + 2)
          mainBlocks(1) = mainFileSource.Substring(iMLineStart + 2, iMLineEnd - iMLineStart - 2)
        End If
        mainBlocks(2) = mainFileSource.Substring(iMLineEnd)
        If Not mainBlocks(1).Contains("Partial ") Then
          mainBlocks(1) = "Partial " & mainBlocks(1)
        End If
        mainFileSource = mainBlocks(0) & mainBlocks(1) & mainBlocks(2)
      End If
    End If
    'END C# spezification
    'BEGIN EventHandler-Mapping
    'EventHandler-Mapping: "Handles Button1.Click" -> "Button1.Click += New System.EventHandler(Me.button1_Click)"
    Dim lastHandlesStart As Int32 = 0
    Do
      lastHandlesStart = mainFileSource.IndexOf(" Handles ", lastHandlesStart + 1)
      If lastHandlesStart = -1 Then
        Exit Do
      Else
        'Parse Main-File "Handles"-Code
        Dim lineEnd As Int32 = mainFileSource.IndexOf(vbCrLf, lastHandlesStart)
        If lineEnd = -1 Then Exit Do 'must have end-of-line
        Dim lineStart As Int32 = mainFileSource.Substring(0, lastHandlesStart).LastIndexOf(vbCrLf)
        If lineStart = -1 Then lineStart = 0
        Dim subPos As Int32 = mainFileSource.IndexOf("Sub ", lineStart)
        If subPos = -1 Then Continue Do
        Dim argsPos As Int32 = mainFileSource.IndexOf("(", subPos)
        If argsPos = -1 Then Continue Do
        Dim subName As String = mainFileSource.Substring(subPos + 4, argsPos - subPos - 4)
        If subName.Contains(" ") Then Continue Do
        Dim eventDeclMulti As String() = Split(mainFileSource.Substring(lastHandlesStart + 9, lineEnd - lastHandlesStart - 9), ",")
        For Each eventDecl As String In eventDeclMulti
          eventDecl = eventDecl.TrimStart(" "c).TrimEnd(" "c)
          If eventDecl.Contains(" ") Then Continue Do
          If Not eventDecl.Contains(".") Then Continue Do
          Dim objectName As String = eventDecl.Substring(0, eventDecl.IndexOf("."))
          Dim eventName As String = eventDecl.Substring(eventDecl.LastIndexOf(".") + 1)
          'Search in Designer-File for target position
          Dim objectDeclStart As Int32 = 0
          Do
            objectDeclStart = designerFileSource.IndexOf(objectName & vbCrLf, objectDeclStart + 1)
            If objectDeclStart = -1 Then
              Exit Do 'not found any more
            Else
              Dim dLineEnd As Int32 = designerFileSource.IndexOf(vbCrLf, objectDeclStart)
              If dLineEnd = -1 Then Exit Do 'must have end-of-line
              Dim dLineStart As Int32 = designerFileSource.Substring(0, objectDeclStart).LastIndexOf(vbCrLf)
              If dLineStart = -1 Then dLineStart = 0
              Dim lineCode As String = designerFileSource.Substring(dLineStart, dLineEnd - dLineStart)
              If lineCode.Replace(vbCrLf, "").Replace(" ", "").Replace(vbTab, "") = "'" & objectName Then
                'Object-Decl. start-position Comment found, search forward to first code-line
                objectDeclStart = designerFileSource.IndexOf("Me." & objectName & ".", objectDeclStart)
                If objectDeclStart = -1 Then Exit Do 'must have at least one existing code-line
                'INSERT STATEMENT TO DESIGNER-FILE NOW
                designerFileSource = designerFileSource.Substring(0, objectDeclStart) & _
                                     "Me." & objectName & "." & eventName & " += New System.EventHandler(Me." & subName & ")" & vbCrLf & _
                                     designerFileSource.Substring(objectDeclStart)
                'REMOVE STATEMENT FROM MAIN-FILE NOW
                mainFileSource = mainFileSource.Substring(0, lastHandlesStart) & _
                                 mainFileSource.Substring(lineEnd)
              End If
            End If
          Loop
        Next
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
  ''' Result-Property: Is an error detected.
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
  ''' Result-Property: Error description.
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
  ''' Result-Property: The converted C# source code.
  ''' </summary>
  ''' <returns></returns>
  ''' <remarks>
  ''' Returns the converted C# source code, if no errors are detected.
  ''' </remarks>
  ''' -----------------------------------------------------------------------------
  Public ReadOnly Property CSharpSource() As String Implements INetVertConverter.OutputSource
    Get
      Return FResultSource
    End Get
  End Property

#End Region

  'PRIVATE
#Region "Parse Process Functions"

  Private Function PreParse(ByVal vbSrc As String, ByVal wrapNamespace As String) As PreParseResult
    Dim TmpLines As String()
    Dim TmpLine As String
    Dim TmpFirstComments As String = ""
    Dim TmpBeforeCode As Boolean
    Dim TmpInClass As Boolean = False
    Dim TmpInInterface As Boolean = False
    Dim TmpInCommentArea As CommentAreaKinds = CommentAreaKinds.Supported
    Dim TmpBorderCloseLine As Int32
    Dim TmpI As Int32
    Dim TmpB As Boolean
    Dim TmpS As String
    Dim TmpStart As Int32
    Dim TmpEnd As Int32
    Dim TmpName As String
    Dim TmpArgs As String
    Dim RetRes As New PreParseResult

    'store original source lins
    If vbSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      RetRes.OriginalSourceLines = Split(vbSrc, vbCrLf)
    Else
      'Linebreak by LF
      RetRes.OriginalSourceLines = Split(vbSrc, vbLf)
    End If
    If ProviderHasParserFlag(ProviderParserFlags.HandleCommonLanguagePreparation) Then
      '== CommonLanguagePreparation ==
      'replace lowercase identifiers to PascalCase
      vbSrc = vbSrc.Replace("function ", "Function ").Replace("sub ", "Sub ").Replace( _
                            "class ", "Class ").Replace("imports ", "Imports ").Replace( _
                            "module ", "Module ").Replace("namespace", "Namespace").Replace( _
                            "partial ", "Partial ")
      'prepair source that Parser-Bug not happens "some Language-Keyword could also be a Method or Propertyname"
      'following keywords must be allowed as identifiers: 'Override', 'Select', 'Single', 'Global', 'Shared', 'Default', 'ReadOnly'
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Override")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Select")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Single")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Shared")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Default")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "ReadOnly")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Next")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Compare")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Resume")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Imports")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Option")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Handles")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Finally")
      vbSrc = UseKeywordAsIdentifier(vbSrc, "Custom")
      'ASP.NET Global.asax CodeBehind-Problem: Class Global -> "Global" must be interpreted as Identifier
      vbSrc = vbSrc.Replace("Class Global" & vbCrLf, "Class [Global]" & vbCrLf)
      'and the coresponding instance variable declarations of Class "Global"
      vbSrc = vbSrc.Replace("New Global" & vbCrLf, "New [Global]" & vbCrLf).Replace( _
                            "New Global(", "New [Global](").Replace( _
                            "As Global" & vbCrLf, "As [Global]" & vbCrLf)
      'repair string-append syntax 'str &= "blabla"' --> 'str += "blabla"'
      vbSrc = vbSrc.Replace(" &= """, " += """)
      'disable WinForms App-Framework special code (not supported in C#)
      vbSrc = vbSrc.Replace(vbCrLf & "#If _MyType = ""WindowsForms"" Then" & vbCrLf, _
                            vbCrLf & "#If False Then" & vbCrLf)
    End If
    'get all lines of code
    If vbSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      TmpLines = Split(vbSrc, vbCrLf)
    Else
      'Linebreak by LF
      TmpLines = Split(vbSrc, vbLf)
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
      TmpLine = TmpLines(I).TrimStart(" "c, Chr(9)) 'StrTrimmLeft(StrTrimmLeft(TmpLines(I), " ", True), Chr(9).ToString, True)
      If TmpLine.Length = 0 Then
        'empty line
        If ProviderHasParserFlag(ProviderParserFlags.HandleEmptyLines) Then
          If TmpInClass AndAlso _
             TmpInCommentArea = CommentAreaKinds.Supported Then
            TmpLines(I) = "dim EmptyLineVar as string"
          End If
        End If
      Else
        Select Case TmpLine.Substring(0, 1)
          Case "#", "'" 'current line is a comment or compilerarg or region
            If ProviderHasParserFlag(ProviderParserFlags.HandleComments) Then
              If TmpBeforeCode Then
                TmpFirstComments &= TmpLine & vbCrLf
              Else
                'If GetNextCodeLine(TmpLines, I).ToLower Like "*class *" Then
                '  'add border-class now and close after "End Class"
                '  For J As Int32 = I + 1 To TmpLines.Length - 1
                '    If (TmpLines(J).TrimStart(" "c, Chr(9)).ToLower Like "end class*") Then
                '      TmpBorderCloseLine = J
                '      Exit For
                '    End If
                '  Next
                '  If (I < TmpBorderCloseLine) Then
                '    'add borderclass now before current line
                '    TmpInClass = True
                '    TmpLines(I) = "Class BorderClass" & vbCrLf & TmpLines(I)
                '    TmpLines(TmpBorderCloseLine) = TmpLines(TmpBorderCloseLine) & vbCrLf & "End Class"
                '    RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                '    RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine)
                '  End If
                'End If
                If TmpLine.Substring(0, 1) = "'" Then
                  'comment
                  TmpS = "Comment"
                Else
                  'compilerarg or region
                  TmpS = "Region"
                End If
                If TmpInClass Then
                  TmpB = True
                  Select Case TmpInCommentArea
                    Case CommentAreaKinds.Unsupported
                      TmpB = False
                      'If TmpInInterface Then
                      '  'wrap BorderClass around current line (comment or CompilerArg)
                      '  TmpLines(I) = "Class BorderClass" & vbCrLf & _
                      '                "dim " & TmpS & "Var as string = """ & TmpLine.Replace("""", "§§").Replace("\", "§$") & """" & vbCrLf & _
                      '                "End Class"
                      '  'Shift 2 lines
                      '  RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                      '  RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                      'End If
                    Case CommentAreaKinds.TopOfClass
                      With GetNextCodeLine(TmpLines, I).ToLower
                        If .IndexOf("implements ") > -1 Then
                          TmpB = False
                        ElseIf .IndexOf("inherits ") > -1 Then
                          TmpB = False
                        End If
                      End With
                    Case CommentAreaKinds.BetweenPropertyMethods
                      With GetNextCodeLine(TmpLines, I).ToLower
                        If .IndexOf("get") > -1 Then
                          TmpB = False
                        ElseIf .IndexOf("set") > -1 Then
                          TmpB = False
                        End If
                      End With
                  End Select
                  If TmpB Then
                    Dim thisLineOnly As String = TmpLine
                    Dim thisLinesNext As String = ""
                    Dim lineSepIdx As Integer = TmpLine.IndexOf(vbCrLf)
                    If lineSepIdx > -1 Then
                      thisLineOnly = TmpLine.Substring(0, lineSepIdx)
                      thisLinesNext = TmpLine.Substring(lineSepIdx)
                    End If
                    TmpLines(I) = "dim " & TmpS & "Var as string = """ & thisLineOnly.Replace("""", "§§").Replace("\", "§$") & """" & thisLinesNext
                  End If 'TmpB
                Else  'TmpInClass
                  If GetNextCodeLine(TmpLines, I).ToLower Like "<assembly:*>*" Then
                    TmpLines(I) = "<Assembly: Temp" & TmpS & "Convert(""" & TmpLine.Replace("""", "§§").Replace("\", "§$") & """)>"
                  Else
                    If Not (GetNextCodeLine(TmpLines, I).ToLower Like "imports *") Then
                      'wrap BorderClass around current line (comment or CompilerArg)
                      TmpLines(I) = "Class BorderClass" & vbCrLf & _
                                    "dim " & TmpS & "Var as string = """ & TmpLine.Replace("""", "§§").Replace("\", "§$") & """" & vbCrLf & _
                                    "End Class"
                      'Shift 2 lines
                      'TmpI = RetRes.GetShift(I) + I + 2
                      RetRes.LineShifts.Add(RetRes.GetShift(I) + I + 1)
                      RetRes.LineShifts.Add(RetRes.GetShift(I + 1) + I + 2)
                    End If
                  End If
                End If 'TmpInClass
              End If 'TmpBeforeCode
            End If 'ProviderHasParserFlag(ProviderParserFlags.HandleComments)
          Case Else

            TmpBeforeCode = False
            If ((TmpLine.Length > 8) AndAlso (TmpLine.Substring(0, 8).ToLower = "imports ")) Then
              'before add broder class (IMPORTS statement)
            ElseIf (TmpLine.ToLower.IndexOf("assembly: ") > -1) Then
              'before add broder class (ASSEMBLY statement)
            ElseIf ((TmpLine.Length > 7) AndAlso (TmpLine.Substring(0, 7).ToLower = "option ")) Then
              'before add broder class (OPTION statement)
            ElseIf ((TmpLine.Length > 10) AndAlso (TmpLine.Substring(0, 10).ToLower = "namespace ")) Then
              'before add broder class (NAMESPACE statement)
              'Wrap namespace around
              If Not String.IsNullOrEmpty(wrapNamespace) Then
                TmpLines(I) = TmpLines(I).Substring(0, 10) & wrapNamespace & "." & TmpLines(I).Substring(10)
              End If
              'Search for end of namespace
              For J As Int32 = I + 1 To TmpLines.Length - 1
                If (TmpLines(J).TrimStart(" "c, Chr(9)).ToLower Like "end namespace*") Then
                  TmpBorderCloseLine = J
                  Exit For
                End If
              Next
              If (I < TmpBorderCloseLine) Then
                'add borderclass now after current line
                TmpInClass = True
                TmpLines(I) = TmpLines(I) & vbCrLf & "Class BorderClass"
                TmpLines(TmpBorderCloseLine) = "End Class" & vbCrLf & TmpLines(TmpBorderCloseLine)
                RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine)
              End If
            Else
              'any other statement line in code
              If (TmpInCommentArea = CommentAreaKinds.BetweenPropertyMethods) OrElse _
                 (TmpInCommentArea = CommentAreaKinds.TopOfClass) Then
                'leaving possible unsupported CommentArea
                TmpInCommentArea = CommentAreaKinds.Supported
              End If

              If (I >= TmpBorderCloseLine) Then
                TmpInClass = False
              Else
                If Not TmpInClass Then
                  For J As Int32 = I + 1 To TmpLines.Length - 1
                    If KeywordInLine(TmpLines(J), "namespace ") > -1 Then
                      TmpBorderCloseLine = J - 1
                      Exit For
                    End If
                  Next
                  'add borderclass now before current line
                  TmpInClass = True
                  If String.IsNullOrEmpty(wrapNamespace) Then
                    TmpLine = "Class BorderClass" & vbCrLf & TmpLines(I)
                    TmpLines(I) = TmpLine
                    TmpLines(TmpBorderCloseLine) = TmpLines(TmpBorderCloseLine) & vbCrLf & "End Class"
                    RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                    RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine + 1)
                  Else
                    TmpLine = "Namespace " & wrapNamespace & vbCrLf & _
                              "Class BorderClass" & vbCrLf & _
                              TmpLines(I)
                    TmpLines(I) = TmpLine
                    TmpLines(TmpBorderCloseLine) = TmpLines(TmpBorderCloseLine) & vbCrLf & _
                                                   "End Class" & vbCrLf & _
                                                   "End Namespace"
                    RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                    RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                    RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine + 1)
                    RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine + 1)
                  End If
                End If
              End If

              If (KeywordInLine(TmpLine, "partial ") > -1) AndAlso _
                 ProviderHasParserFlag(ProviderParserFlags.HandleSomeNet2LangFeatures) Then
                'support for .NET 2.0 Language keywords: "Partial" classes
                TmpLines(I) = TmpLine.Replace("Partial ", "").Replace("partial ", "").TrimEnd(" "c) & "PartialClassConverted"
              ElseIf (KeywordInLine(TmpLine, "operator ") > -1) AndAlso _
                 ProviderHasParserFlag(ProviderParserFlags.HandleSomeNet2LangFeatures) Then
                'support for VB.NET 2.0 Language keywords: "Operator overloading" (C# supports operator overloading since v1.0)
                For iOp As Int32 = 0 To FOverloadableOperators.Length - 1
                  TmpLines(I) = TmpLine.Replace("Operator " & FOverloadableOperators(iOp), "Function Operator_" & iOp.ToString).Replace( _
                                                "operator " & FOverloadableOperators(iOp), "Function Operator_" & iOp.ToString)
                Next
              ElseIf (KeywordInLine(TmpLine, "property ") > -1) AndAlso _
                     TmpInInterface AndAlso _
                     ProviderHasParserFlag(ProviderParserFlags.HandleICSharpCodeParserBugs) Then
                'create missing property accessors for properties in interfaces, append spezial Tag to Property-Name for PostParser
                'store type of accessors in TmpS
                If KeywordInLine(TmpLine, "readonly ") > -1 Then
                  TmpS = "ConvertingPropertyRead"
                ElseIf KeywordInLine(TmpLine, "writeonly ") > -1 Then
                  TmpS = "ConvertingPropertyWrite"
                Else
                  TmpS = "ConvertingPropertyFull"
                End If
                TmpI = KeywordInLine(TmpLine, "property ")
                TmpStart = TmpLine.IndexOf("(", TmpI)
                If TmpStart = -1 Then
                  TmpStart = TmpLine.ToLower.IndexOf(" as ", TmpI)
                End If
                If TmpStart = -1 Then
                  'Property-Name is the last string
                  TmpLines(I) = TmpLine.TrimEnd(" "c) & TmpS
                Else
                  TmpLines(I) = TmpLine.Substring(0, TmpStart) & TmpS & TmpLine.Substring(TmpStart, TmpLine.Length - TmpStart)
                End If
              ElseIf (KeywordInLine(TmpLine, "event ") > -1) AndAlso _
                      ProviderHasParserFlag(ProviderParserFlags.HandleICSharpCodeParserBugs) Then
                'create event-delegate if event-arguments are directly behind the event-statement
                TmpI = KeywordInLine(TmpLine, "event ")
                TmpStart = TmpLine.IndexOf("(", TmpI)
                If TmpStart > -1 Then
                  TmpEnd = TmpLine.LastIndexOf(")")
                  If TmpEnd > TmpStart Then
                    'store event-name in TmpName
                    TmpName = TmpLine.Substring(TmpI + 6, TmpStart - TmpI - 6)
                    'store event-arguments in TmpArgs
                    TmpArgs = TmpLine.Substring(TmpStart, TmpEnd - TmpStart + 1)
                    'replace arguments with delegate in current line and append new line with event-delegate
                    TmpLines(I) = TmpLine.Substring(0, TmpStart) & " As " & TmpName & "EventHandler" & vbCrLf & _
                                  TmpLine.Substring(0, TmpI) & "Delegate Sub " & TmpName & "EventHandler" & TmpArgs
                    'Shift 1 line
                    RetRes.LineShifts.Add(RetRes.GetShift(I) + I)
                  End If
                End If
              End If
              '=======================================================================================
              'It is not wise to translate functions from "Microsoft.VisualBasic" namespace to
              'native .NET functions.
              'Best case is to include the "Microsoft.VisualBasic" namespace in C# projects witch are
              'converted from VB.NET, if such functions are used in code.
              '=======================================================================================
              'TmpI = KeywordInLine(TmpLine, "msgbox(")
              'If (TmpI > -1) AndAlso (TmpLine.Length > TmpI + 7) Then
              '  'convert VB-Specific function to native .NET-Framework function: -msgbox
              '  TmpLines(I) = TmpLine.Substring(0, TmpI) & "MessageBox.Show(" & TmpLine.Substring(TmpI + 7, TmpLine.Length - TmpI - 7)
              'End If
            End If

            If (TmpLine.ToLower Like "end interface*") Then
              'end of unsupported range (comments are supported)
              TmpInCommentArea = CommentAreaKinds.Supported
              'leaving interface
              TmpInInterface = False
            ElseIf (TmpLine.ToLower Like "end enum*") Then
              'end of unsupported range (comments are supported)
              TmpInCommentArea = CommentAreaKinds.Supported
            ElseIf (KeywordInLine(TmpLine, "interface ") > -1) Then
              'start of unsupported range (comments are not supported)
              TmpInCommentArea = CommentAreaKinds.Unsupported
              'entering interface
              TmpInInterface = True
            ElseIf (KeywordInLine(TmpLine, "enum ") > -1) Then
              'start of unsupported range (comments are not supported)
              TmpInCommentArea = CommentAreaKinds.Unsupported
            ElseIf (TmpInCommentArea = CommentAreaKinds.Supported) AndAlso _
                   ((KeywordInLine(TmpLine, "class ") > -1) OrElse _
                    (TmpLine.ToLower Like "implements *") OrElse _
                    (TmpLine.ToLower Like "inherits *")) Then
              'possible unsupported area 'TopOfClass'
              TmpInCommentArea = CommentAreaKinds.TopOfClass
            ElseIf (TmpInCommentArea = CommentAreaKinds.Supported) AndAlso _
                   ((KeywordInLine(TmpLine, "property ") > -1) OrElse _
                    (TmpLine.ToLower Like "end get*")) Then
              'possible unsupported area 'BetweenPropertyMethods'
              TmpInCommentArea = CommentAreaKinds.BetweenPropertyMethods
            End If
        End Select
      End If
    Next
    'assign first comments
    If TmpFirstComments.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      RetRes.FirstLinesComments = Split(TmpFirstComments, vbCrLf)
    Else
      'Linebreak by LF
      RetRes.FirstLinesComments = Split(TmpFirstComments, vbLf)
    End If
    'assign result string
    RetRes.ResultString = Join(TmpLines, vbCrLf)
    Return RetRes
  End Function

  Private Function ConvertSource(ByVal vbSrc As String, ByVal preResult As PreParseResult) As String
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
      RetS = TmpRefactoryProvider.ConvertVBtoCS(vbSrc)
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
    Catch ex As Exception
      'other exception
      TmpS = "Error: " & ex.Message
      Throw New NetVertException(TmpS)
    End Try
    Return RetS
  End Function

  Private Function PostParse(ByVal csSrc As String, _
                             ByVal preResult As PreParseResult, _
                             ByVal fixNamespaces As String) As String
    Dim TmpLines As String()
    Dim TmpLine As String
    Dim TmpBorderClassIndent As Int32 = -1
    Dim TmpS As String
    Dim TmpNSImport As String = ""
    Dim RetS As String

    'Replace TAB's with 2 spaces
    csSrc = csSrc.Replace(Chr(9), "  ")
    'repair Parser-Bug "wrong structdeclaration"
    csSrc = csSrc.Replace("[][0] ", "[] ")
    'get all lines of code
    If csSrc.IndexOf(vbCrLf) > -1 Then
      'Linebreak by CR-LF
      TmpLines = Split(csSrc, vbCrLf)
    Else
      'Linebreak by LF
      TmpLines = Split(csSrc, vbLf)
    End If
    'process each line (restore comments and regions)
    For I As Int32 = 0 To TmpLines.Length - 1
      If (TmpBorderClassIndent > -1) AndAlso _
         (TmpLines(I).Length = TmpBorderClassIndent + 1) AndAlso _
         (TmpLines(I).Substring(TmpBorderClassIndent, 1) = "}") Then
        'remove end of BorderClass
        TmpBorderClassIndent = -1
        TmpLines(I) = "KILL"
      ElseIf TmpLines(I).IndexOf("class BorderClass") > -1 Then
        'remove begin of BorderClass and following "{"-Line
        TmpLine = StrTrimmLeft(TmpLines(I), " ", True)
        TmpBorderClassIndent = TmpLines(I).Length - TmpLine.Length
        TmpLines(I) = "KILL"
        TmpLines(I + 1) = "KILL"
      Else
        If (TmpBorderClassIndent > -1) AndAlso _
           (TmpLines(I).Length > 2) AndAlso _
           (StrTrimmLeft(TmpLines(I).Substring(0, 2), " ") = "") Then
          'correct indention (remove 2 spaces because of BorderClass)
          TmpLines(I) = TmpLines(I).Substring(2, TmpLines(I).Length - 2)
        End If
        'get line without leading spaces
        TmpLine = StrTrimmLeft(TmpLines(I), " ", True)
        If TmpLine.Length > 0 Then
          'skip empty lines
          If (TmpLine.Length > 18) AndAlso _
             (TmpLine.Substring(0, 18) = "string CommentVar ") Then
            'preserve spaces
            TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
            'convert comment
            TmpLines(I) = TmpS & VbToCSharpComment(TmpLine.Substring(21, TmpLine.Length - 23))
            'mark next line with KILL if its empty and not last line
            If (TmpLines.Length > I + 1) AndAlso _
               (TmpLines(I + 1) = "") Then
              TmpLines(I + 1) = "KILL"
            End If
          ElseIf (TmpLine.Length > 17) AndAlso _
                 (TmpLine.Substring(0, 17) = "string RegionVar ") Then
            'convert region or compilerarg
            TmpLines(I) = VbToCSharpComment(TmpLine.Substring(20, TmpLine.Length - 22))
          ElseIf TmpLine Like "[[]assembly: TempRegionConvert(""*"")*" Then
            'convert region or compilerarg
            TmpLines(I) = VbToCSharpComment(TmpLine.Substring(30, TmpLine.Length - 33))
          ElseIf TmpLine Like "[[]assembly: TempCommentConvert(""*"")*" Then
            'convert comment
            TmpLines(I) = VbToCSharpComment(TmpLine.Substring(31, TmpLine.Length - 34))
          ElseIf (TmpLine.Length > 27) AndAlso _
                 (TmpLine.Substring(0, 27) = "abstract string CommentVar ") Then
            'preserve spaces
            TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
            'convert comment
            TmpLines(I) = TmpS & VbToCSharpComment(TmpLine.Substring(30, TmpLine.Length - 32))
            'mark next line with KILL if its empty and not last line
            If (TmpLines(I + 1) = "") AndAlso _
               (TmpLines.Length > I + 1) Then
              TmpLines(I + 1) = "KILL"
            End If
          ElseIf (TmpLine.Length > 26) AndAlso _
                 (TmpLine.Substring(0, 26) = "abstract string RegionVar ") Then
            'convert region or compilerarg
            TmpLines(I) = VbToCSharpComment(TmpLine.Substring(29, TmpLine.Length - 31))
          ElseIf TmpLine Like "*string EmptyLineVar;" Then
            'Empty Line
            TmpLines(I) = ""
          ElseIf TmpLine.IndexOf("PartialClassConverted") > -1 Then
            'restore Partial class (new .NET 2.0 feature)
            TmpLines(I) = TmpLines(I).Replace("PartialClassConverted", "").Replace("class ", "partial class ")
            ''preserve spaces
            'TmpS = TmpLines(i).Substring(0, TmpLines(i).Length - TmpLine.Length)
            'TmpLines(I) = TmpS & "partial " & TmpLine.Replace("PartialClassConverted", "")
          ElseIf TmpLine.IndexOf("ConvertingPropertyFull") > -1 Then
            'preserve spaces
            TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
            'create missing property accessors for properties in interfaces, remove spezial Tag from Property-Name
            'and create get- and set-accessors on next line
            TmpLines(I) = TmpLines(I).Replace("ConvertingPropertyFull", "") & vbCrLf & _
                          TmpS & "  get; set;"
          ElseIf TmpLine.IndexOf("ConvertingPropertyRead") > -1 Then
            'preserve spaces
            TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
            'create missing property accessors for properties in interfaces, remove spezial Tag from Property-Name
            'and create get-accessor on next line
            TmpLines(I) = TmpLines(I).Replace("ConvertingPropertyRead", "") ' & vbCrLf & TmpS & "  get;"
          ElseIf TmpLine.IndexOf("ConvertingPropertyWrite") > -1 Then
            'preserve spaces
            TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length)
            'create missing property accessors for properties in interfaces, remove spezial Tag from Property-Name
            'and create set-accessor on next line
            TmpLines(I) = TmpLines(I).Replace("ConvertingPropertyWrite", "") ' & vbCrLf & TmpS & "  set;"
          ElseIf TmpLine.IndexOf("Operator_") > -1 Then
            'restore "Operator Overloading" (new .NET 2.0 feature for VB.NET)
            For iOp As Int32 = 0 To FOverloadableOperators.Length - 1
              TmpLines(I) = TmpLines(I).Replace("Operator_" & iOp.ToString, "operator " & FOverloadableOperators(iOp) & " ")
            Next
          End If
        End If
      End If
    Next
    'get first lines comments and regions
    TmpS = ""
    For I As Int32 = 0 To preResult.FirstLinesComments.Length - 1
      If preResult.FirstLinesComments(I) <> "" Then
        TmpS &= VbToCSharpComment(preResult.FirstLinesComments(I)) & vbCrLf
      End If
    Next
    'get namespace-fix
    If fixNamespaces.Length > 0 Then
      For Each ns As String In Split(fixNamespaces, ",")
        If Not LineInSource(csSrc, "using " & ns & ";") Then
          TmpNSImport &= "using " & ns & ";" & vbCrLf
        End If
      Next
    End If
    'If TmpNSImport <> "" Then
    '  TmpNSImport = vbCrLf & TmpNSImport
    'End If
    'set Result to: first lines (TmpS), namespace-fix, AllLines
    RetS = TmpS & TmpNSImport & Join(TmpLines, vbCrLf) & vbCrLf
    'remove Lines that are marked with KILL
    RetS = RetS.Replace("KILL" & vbCrLf, "")
    Return RetS
  End Function

#End Region

#Region "Helper Functions"

  Private Function GetNextCodeLine(ByVal codeLines() As String, ByVal currentLine As Int32) As String
    Dim TmpLine As String
    Dim RetS As String = ""

    For I As Int32 = currentLine + 1 To codeLines.Length - 1
      TmpLine = StrTrimmLeft(StrTrimmLeft(codeLines(I), " ", True), Chr(9).ToString, True)
      If (TmpLine.Length > 0) AndAlso _
         (TmpLine.Substring(0, 1) <> "'") AndAlso _
         (TmpLine.Substring(0, 1) <> "#") Then
        'codeLines(I) is a valid codeline (not empty, not a comment, not a compiler-arg or region)
        RetS = codeLines(I)
        Exit For
      End If
    Next
    Return RetS
  End Function

  Private Function KeywordInLine(ByVal codeLine As String, _
                                 ByVal keywordWithSufix As String) As Int32
    Dim TmpS As String
    Dim RetI As Int32

    RetI = codeLine.ToLower.IndexOf(keywordWithSufix)
    If RetI > 0 Then
      'check if sign before keyword is SPACE or TAB or CR or LF
      TmpS = codeLine.Substring(RetI - 1, 1)
      If (TmpS <> " ") AndAlso _
         (TmpS <> Chr(9).ToString) AndAlso _
         (TmpS <> Chr(10).ToString) AndAlso _
         (TmpS <> Chr(13).ToString) Then
        RetI = -1
      End If
    End If
    Return RetI
  End Function

  Private Function UseKeywordAsIdentifier(ByVal vbSrc As String, ByVal pascalCaseKeyWord As String) As String
    Dim TmpS As String = pascalCaseKeyWord.ToLower
    'a keyword (PascalCase or lowercase) is not allowed in use for properties and variable names,
    'therefore they must be included in [ and ] brackets
    Return vbSrc.Replace("." & pascalCaseKeyWord & ".", ".[" & pascalCaseKeyWord & "].").Replace( _
                         "." & pascalCaseKeyWord & " ", ".[" & pascalCaseKeyWord & "] ").Replace( _
                         " " & pascalCaseKeyWord & ".", " [" & pascalCaseKeyWord & "].").Replace( _
                         "(" & pascalCaseKeyWord & ".", "([" & pascalCaseKeyWord & "].").Replace( _
                         "." & pascalCaseKeyWord & ")", ".[" & pascalCaseKeyWord & "])").Replace( _
                         "." & pascalCaseKeyWord & "(", ".[" & pascalCaseKeyWord & "](").Replace( _
                         ", " & pascalCaseKeyWord & " ", ", [" & pascalCaseKeyWord & "]").Replace( _
                         " " & pascalCaseKeyWord & " As ", " [" & pascalCaseKeyWord & "] As ").Replace( _
                         " " & pascalCaseKeyWord & ")", " [" & pascalCaseKeyWord & "])").Replace( _
                         "(" & pascalCaseKeyWord & ")", "([" & pascalCaseKeyWord & "])").Replace( _
                         "(" & pascalCaseKeyWord & " ", "([" & pascalCaseKeyWord & "] ").Replace( _
                         "." & pascalCaseKeyWord & vbCrLf, ".[" & pascalCaseKeyWord & "]" & vbCrLf).Replace( _
                         "." & TmpS & ".", ".[" & TmpS & "].").Replace( _
                         "." & TmpS & " ", ".[" & TmpS & "] ").Replace( _
                         " " & TmpS & ".", " [" & TmpS & "].").Replace( _
                         "(" & TmpS & ".", "([" & TmpS & "].").Replace( _
                         "." & TmpS & ")", ".[" & TmpS & "])").Replace( _
                         "." & TmpS & "(", ".[" & TmpS & "](").Replace( _
                         ", " & TmpS & " ", ", [" & TmpS & "] ").Replace( _
                         " " & TmpS & " As ", " [" & TmpS & "] As ").Replace( _
                         " " & TmpS & ")", " [" & TmpS & "])").Replace( _
                         "(" & TmpS & ")", "([" & TmpS & "])").Replace( _
                         "(" & TmpS & " ", "([" & TmpS & "] ").Replace( _
                         "." & TmpS & vbCrLf, ".[" & TmpS & "]" & vbCrLf)
  End Function

  Private Function VbToCSharpComment(ByVal commentLine As String) As String
    Dim TmpI As Int32
    Dim RetS As String = ""

    commentLine = commentLine.Replace("§§", """").Replace("§$", "\")
    If commentLine.Length > 0 Then
      If (commentLine.Length > 2) AndAlso _
         commentLine.Substring(0, 3) = "'''" Then
        'line is a docu-comment
        RetS = "///" & commentLine.Substring(3, commentLine.Length - 3)
      ElseIf commentLine.Substring(0, 1) = "'" Then
        'line is a comment
        RetS = "//" & commentLine.Substring(1, commentLine.Length - 1)
      ElseIf (commentLine.Length > 7) AndAlso _
             (commentLine.Substring(0, 7).ToLower = "#region") Then
        TmpI = commentLine.IndexOf("""")
        If TmpI > -1 Then
          RetS = "#region " & commentLine.Substring(TmpI + 1, commentLine.Length - TmpI - 2)
        End If
      ElseIf (commentLine.Length > 3) AndAlso _
             (commentLine.Substring(0, 3).ToLower = "#if") Then
        If (commentLine.Length > 8) AndAlso _
           (commentLine.Substring(commentLine.Length - 5, 5).ToLower = " then") Then
          RetS = "#if " & ConvertIfStatement(commentLine.Substring(3, commentLine.Length - 8))
        Else
          RetS = "#if " & ConvertIfStatement(commentLine.Substring(3, commentLine.Length - 3))
        End If
      ElseIf (commentLine.Length >= 11) AndAlso _
            (commentLine.Substring(0, 11).ToLower = "#end region") Then
        RetS = "#endregion"
      ElseIf (commentLine.Length >= 7) AndAlso _
            (commentLine.Substring(0, 7).ToLower = "#end if") Then
        RetS = "#endif"
      ElseIf commentLine.Substring(0, 1) = "#" Then
        RetS = commentLine
      End If
    End If
    Return RetS
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
    TmpSrc = "Class BorderClass" & vbCrLf & _
             "Sub BorderSub()" & vbCrLf & _
             "If " & ifStatement & " Then" & vbCrLf & _
             "End If" & vbCrLf & _
             "End Sub" & vbCrLf & _
             "End Class"
    Try
      'convert with the RefactoryProvider
      RetS = TmpRefactoryProvider.ConvertVBtoCS(TmpSrc)
      'remove all wrapped Borders
      TmpI = RetS.IndexOf("if")
      RetS = RetS.Substring(TmpI + 3, RetS.IndexOf("{", TmpI) - TmpI - 4).TrimEnd(New Char() {" "c, Chr(9), Chr(10), Chr(13)})
    Catch ex As Exception
      'could not convert statement, return orginal
      RetS = ifStatement
    End Try
    Return RetS
  End Function

  Private Function ProviderHasParserFlag(ByVal parserFlag As ProviderParserFlags) As Boolean
    Return (SettingsManager.CurrentRefactoryProvider.PreAndPostParseFlags And parserFlag) = parserFlag
  End Function

  'Private Function IsCommentOrEmptyLine(ByVal codeLine As String) As Boolean
  '  Dim truncLine As String = codeLine.TrimStart(" "c, Chr(9))
  '  Return (truncLine.StartsWith("'") OrElse truncLine.Length = 0)
  'End Function

#End Region

End Class
