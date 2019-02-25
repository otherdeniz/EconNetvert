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
  public class RefactoryNet20Provider : IRefactoryProvider
  {
    //SHARED
    public static RefactoryNet20Provider Instance = new RefactoryNet20Provider();

    //PUBLIC
#region PUBLIC Properties

    public string IRefactoryProvider.Name {
      get { return "ICSharpCode.NRefactory 2.0"; }
    }

    public ProviderParserFlags IRefactoryProvider.PreAndPostParseFlags {
      get { return ProviderParserFlags.HandleComments | ProviderParserFlags.HandleCommonLanguagePreparation | ProviderParserFlags.HandleICSharpCodeParserBugs | ProviderParserFlags.HandleSomeNet2LangFeatures; }
    }

#endregion

    public string IRefactoryProvider.ConvertCStoVB(string csSrc)
    {
      TextReader TmpReader;
      ICSharpCode.NRefactory.IParser TmpCSPars;
      ICSharpCode.NRefactory.Ast.CompilationUnit TmpCompUnit;
      ICSharpCode.NRefactory.PrettyPrinter.VBNetOutputVisitor TmpVBVisitor = new ICSharpCode.NRefactory.PrettyPrinter.VBNetOutputVisitor();
      string RetS = "";

      //create a reader for the source
      TmpReader = new StringReader(csSrc);
      //we create the parser (witch includes the lexical analyser)
      TmpCSPars = ICSharpCode.NRefactory.ParserFactory.CreateParser(ICSharpCode.NRefactory.SupportedLanguage.CSharp, TmpReader);
      //then we use the parser
      TmpCSPars.Parse();
      TmpReader.Close();
      if (TmpCSPars.Errors.count > 0) {
        //parser error, throw exception
        throw new NetVertException(TmpCSPars.Errors.ErrorOutput);
      } else {
        //retrieve the CodeDom from the parser
        TmpCompUnit = TmpCSPars.CompilationUnit;
        //use visitor to write SourceCode of CodeDom
        TmpVBVisitor.VisitCompilationUnit(TmpCompUnit, null);
        //return converted source
        RetS = TmpVBVisitor.Text;
      }
      return RetS;
    }

    public string IRefactoryProvider.ConvertVBtoCS(string vbSrc)
    {
      TextReader TmpReader;
      ICSharpCode.NRefactory.IParser TmpVBPars;
      ICSharpCode.NRefactory.Ast.CompilationUnit TmpCompUnit;
      ICSharpCode.NRefactory.PrettyPrinter.CSharpOutputVisitor TmpCSVisitor = new ICSharpCode.NRefactory.PrettyPrinter.CSharpOutputVisitor();
      string RetS = "";

      //create a reader for the source
      TmpReader = new StringReader(vbSrc);
      //we create the parser (witch includes the lexical analyser)
      TmpVBPars = ICSharpCode.NRefactory.ParserFactory.CreateParser(ICSharpCode.NRefactory.SupportedLanguage.VBNet, TmpReader);
      //then we use the parser
      TmpVBPars.Parse();
      TmpReader.Close();
      if (TmpVBPars.Errors.count > 0) {
        //parser error, throw exception
        throw new NetVertException(TmpVBPars.Errors.ErrorOutput);
      } else {
        //retrieve the CodeDom from the parser
        TmpCompUnit = TmpVBPars.CompilationUnit;
        //use visitor to write SourceCode of CodeDom
        TmpCSVisitor.VisitCompilationUnit(TmpCompUnit, null);
        //return converted source
        RetS = TmpCSVisitor.Text;
      }
      return RetS;
    }

  }
}

