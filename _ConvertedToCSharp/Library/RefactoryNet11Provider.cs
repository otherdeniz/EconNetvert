//=================================
//Deniz Esen
//Econ Dimension GmbH
//http://www.econdimension.com
//d.esen@econdimension.com
//=================================
// You are free to use, change and
// redistribute this Class or parts
// of it.
// No Support.
//=================================
using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
namespace Econ.NetVert
{
  public class RefactoryNet11Provider : IRefactoryProvider
  {
    //SHARED
    public static RefactoryNet11Provider Instance = new RefactoryNet11Provider();

    //PUBLIC
#region PUBLIC Properties

    public string IRefactoryProvider.Name {
      get { return "ICSharpCode.SharpRefactory 1.1"; }
    }

    public ProviderParserFlags IRefactoryProvider.PreAndPostParseFlags {
      get { return ProviderParserFlags.HandleComments | ProviderParserFlags.HandleCommonLanguagePreparation | ProviderParserFlags.HandleICSharpCodeParserBugs | ProviderParserFlags.HandleSomeNet2LangFeatures; }
    }

#endregion

    public string IRefactoryProvider.ConvertCStoVB(string csSrc)
    {
      ICSharpCode.SharpRefactory.Parser.Lexer TmpCSLex;
      ICSharpCode.SharpRefactory.Parser.Parser TmpCSPars = new ICSharpCode.SharpRefactory.Parser.Parser();
      ICSharpCode.SharpRefactory.Parser.AST.CompilationUnit TmpCompUnit;
      ICSharpCode.SharpRefactory.PrettyPrinter.VBNetVisitor TmpVBVisitor = new ICSharpCode.SharpRefactory.PrettyPrinter.VBNetVisitor();
      string RetS = "";

      //first we create a lexical analyser
      TmpCSLex = new ICSharpCode.SharpRefactory.Parser.Lexer(new ICSharpCode.SharpRefactory.Parser.StringReader(csSrc));
      //then we use the parser
      TmpCSPars.Parse(TmpCSLex);
      if (TmpCSPars.Errors.count > 0) {
        //parser error, throw exception
        throw new NetVertException(TmpCSPars.Errors.ErrorOutput);
      } else {
        //retrieve the CodeDom from the parser
        TmpCompUnit = TmpCSPars.compilationUnit;
        //use visitor to write SourceCode of CodeDom
        TmpVBVisitor.Visit(TmpCompUnit, null);
        //return converted source
        RetS = TmpVBVisitor.SourceText.ToString;
      }
      return RetS;
    }

    public string IRefactoryProvider.ConvertVBtoCS(string vbSrc)
    {
      ICSharpCode.SharpRefactory.Parser.VB.Parser TmpVBPars = new ICSharpCode.SharpRefactory.Parser.VB.Parser();
      ICSharpCode.SharpRefactory.Parser.AST.VB.CompilationUnit TmpCompUnit;
      ICSharpCode.SharpRefactory.PrettyPrinter.VB.CSharpVisitor TmpCSVisitor = new ICSharpCode.SharpRefactory.PrettyPrinter.VB.CSharpVisitor();
      ICSharpCode.SharpRefactory.Parser.VB.Lexer TmpVBLex;
      string RetS = "";

      //first we create a lexical analyser
      TmpVBLex = new ICSharpCode.SharpRefactory.Parser.VB.Lexer(new ICSharpCode.SharpRefactory.Parser.VB.StringReader(vbSrc));
      //then we use the parser
      TmpVBPars.Parse(TmpVBLex);
      if (TmpVBPars.Errors.count > 0) {
        //parser error, throw exception
        throw new NetVertException(TmpVBPars.Errors.ErrorOutput);
      } else {
        //retrieve the CodeDom from the parser
        TmpCompUnit = TmpVBPars.compilationUnit;
        //use visitor to write SourceCode of CodeDom
        TmpCSVisitor.Visit(TmpCompUnit, null);
        //return converted source
        RetS = TmpCSVisitor.SourceText.ToString;
      }
      return RetS;
    }

  }
}

