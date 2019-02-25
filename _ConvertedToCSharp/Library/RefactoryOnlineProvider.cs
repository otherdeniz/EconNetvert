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
namespace Econ.NetVert
{
  public class RefactoryOnlineProvider : IRefactoryProvider
  {
    //SHARED
    public static RefactoryOnlineProvider Instance = new RefactoryOnlineProvider();

    //CONST
    private const string cCsToVb = "cs2vbnet";
    private const string cVbToCs = "vbnet2cs";

    //PUBLIC
#region PUBLIC Properties

    public string IRefactoryProvider.Name {
      get { return "NRefactory Online WebService"; }
    }

    public ProviderParserFlags IRefactoryProvider.PreAndPostParseFlags {
      get { return ProviderParserFlags.HandleCommonLanguagePreparation | ProviderParserFlags.HandleICSharpCodeParserBugs; }
    }

#endregion

    public string IRefactoryProvider.ConvertCStoVB(string csSrc)
    {
      string TmpErr = "";
      string RetS = "";

       // ERROR: Not supported in C#: WithStatement

      return RetS;
    }

    public string IRefactoryProvider.ConvertVBtoCS(string vbSrc)
    {
      string TmpErr = "";
      string RetS = "";

       // ERROR: Not supported in C#: WithStatement

      return RetS;
    }


  }
}

