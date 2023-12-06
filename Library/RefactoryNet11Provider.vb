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

Public Class RefactoryNet11Provider
  Implements IRefactoryProvider

  'SHARED
  Public Shared Instance As New RefactoryNet11Provider

  'PUBLIC
#Region "PUBLIC Properties"

  Public ReadOnly Property Name() As String Implements IRefactoryProvider.Name
    Get
      Return "ICSharpCode.SharpRefactory 1.1"
    End Get
  End Property

  Public ReadOnly Property PreAndPostParseFlags() As ProviderParserFlags Implements IRefactoryProvider.PreAndPostParseFlags
    Get
      Return ProviderParserFlags.HandleComments Or _
             ProviderParserFlags.HandleCommonLanguagePreparation Or _
             ProviderParserFlags.HandleICSharpCodeParserBugs Or _
             ProviderParserFlags.HandleSomeNet2LangFeatures Or _
             ProviderParserFlags.HandleEmptyLines
    End Get
  End Property

#End Region

  Public Function ConvertCStoVB(ByVal csSrc As String) As String Implements IRefactoryProvider.ConvertCStoVB
    Dim TmpCSLex As ICSharpCode.SharpRefactory.Parser.Lexer
    Dim TmpCSPars As New ICSharpCode.SharpRefactory.Parser.Parser
    Dim TmpCompUnit As ICSharpCode.SharpRefactory.Parser.AST.CompilationUnit
    Dim TmpVBVisitor As New ICSharpCode.SharpRefactory.PrettyPrinter.VBNetVisitor
    Dim RetS As String = ""

    'first we create a lexical analyser
    TmpCSLex = New ICSharpCode.SharpRefactory.Parser.Lexer(New ICSharpCode.SharpRefactory.Parser.StringReader(csSrc))
    'then we use the parser
    TmpCSPars.Parse(TmpCSLex)
    If TmpCSPars.Errors.count > 0 Then
      'parser error, throw exception
      Throw New NetVertException(TmpCSPars.Errors.ErrorOutput)
    Else
      'retrieve the CodeDom from the parser
      TmpCompUnit = TmpCSPars.compilationUnit
      'use visitor to write SourceCode of CodeDom
      TmpVBVisitor.Visit(TmpCompUnit, Nothing)
      'return converted source
      RetS = TmpVBVisitor.SourceText.ToString
    End If
    Return RetS
  End Function

  Public Function ConvertVBtoCS(ByVal vbSrc As String) As String Implements IRefactoryProvider.ConvertVBtoCS
    Dim TmpVBPars As New ICSharpCode.SharpRefactory.Parser.VB.Parser
    Dim TmpCompUnit As ICSharpCode.SharpRefactory.Parser.AST.VB.CompilationUnit
    Dim TmpCSVisitor As New ICSharpCode.SharpRefactory.PrettyPrinter.VB.CSharpVisitor
    Dim TmpVBLex As ICSharpCode.SharpRefactory.Parser.VB.Lexer
    Dim RetS As String = ""

    'first we create a lexical analyser
    TmpVBLex = New ICSharpCode.SharpRefactory.Parser.VB.Lexer(New ICSharpCode.SharpRefactory.Parser.VB.StringReader(vbSrc))
    'then we use the parser
    TmpVBPars.Parse(TmpVBLex)
    If TmpVBPars.Errors.count > 0 Then
      'parser error, throw exception
      Throw New NetVertException(TmpVBPars.Errors.ErrorOutput)
    Else
      'retrieve the CodeDom from the parser
      TmpCompUnit = TmpVBPars.compilationUnit
      'use visitor to write SourceCode of CodeDom
      TmpCSVisitor.Visit(TmpCompUnit, Nothing)
      'return converted source
      RetS = TmpCSVisitor.SourceText.ToString
    End If
    Return RetS
  End Function

End Class
