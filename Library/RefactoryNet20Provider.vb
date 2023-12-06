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

Public Class RefactoryNet20Provider
  Implements IRefactoryProvider

  'SHARED
  Public Shared Instance As New RefactoryNet20Provider

  'PUBLIC
#Region "PUBLIC Properties"

  Public ReadOnly Property Name() As String Implements IRefactoryProvider.Name
    Get
      Return "ICSharpCode.NRefactory 4.0"
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
    Dim TmpReader As TextReader
    Dim TmpCSPars As ICSharpCode.NRefactory.IParser
    Dim TmpCompUnit As ICSharpCode.NRefactory.Ast.CompilationUnit
    Dim TmpVBVisitor As New ICSharpCode.NRefactory.PrettyPrinter.VBNetOutputVisitor
    Dim RetS As String = ""

    'create a reader for the source
    TmpReader = New StringReader(csSrc)
    'we create the parser (witch includes the lexical analyser)
    TmpCSPars = ICSharpCode.NRefactory.ParserFactory.CreateParser(ICSharpCode.NRefactory.SupportedLanguage.CSharp, TmpReader)
    'then we use the parser
    TmpCSPars.Parse()
    TmpReader.Close()
    If TmpCSPars.Errors.count > 0 Then
      'parser error, throw exception
      Throw New NetVertException(TmpCSPars.Errors.ErrorOutput)
    Else
      'retrieve the CodeDom from the parser
      TmpCompUnit = TmpCSPars.CompilationUnit
      'use visitor to write SourceCode of CodeDom
      TmpVBVisitor.VisitCompilationUnit(TmpCompUnit, Nothing)
      'return converted source
      RetS = TmpVBVisitor.Text
    End If
    Return RetS
  End Function

  Public Function ConvertVBtoCS(ByVal vbSrc As String) As String Implements IRefactoryProvider.ConvertVBtoCS
    Dim TmpReader As TextReader
    Dim TmpVBPars As ICSharpCode.NRefactory.IParser
    Dim TmpCompUnit As ICSharpCode.NRefactory.Ast.CompilationUnit
    Dim TmpCSVisitor As New ICSharpCode.NRefactory.PrettyPrinter.CSharpOutputVisitor
    Dim RetS As String = ""

    'create a reader for the source
    TmpReader = New StringReader(vbSrc)
    'we create the parser (witch includes the lexical analyser)
    TmpVBPars = ICSharpCode.NRefactory.ParserFactory.CreateParser(ICSharpCode.NRefactory.SupportedLanguage.VBNet, TmpReader)
    'then we use the parser
    TmpVBPars.Parse()
    TmpReader.Close()
    If TmpVBPars.Errors.count > 0 Then
      'parser error, throw exception
      Throw New NetVertException(TmpVBPars.Errors.ErrorOutput)
    Else
      'retrieve the CodeDom from the parser
      TmpCompUnit = TmpVBPars.CompilationUnit
      'use visitor to write SourceCode of CodeDom
      TmpCSVisitor.VisitCompilationUnit(TmpCompUnit, Nothing)
      'return converted source
      RetS = TmpCSVisitor.Text
    End If
    Return RetS
  End Function

End Class
