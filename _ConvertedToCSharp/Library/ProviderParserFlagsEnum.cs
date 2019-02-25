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
  public enum ProviderParserFlags
  {
    HandleComments = Math.Pow(2, 0),
    HandleCommonLanguagePreparation = Math.Pow(2, 1),
    HandleICSharpCodeParserBugs = Math.Pow(2, 2),
    HandleSomeNet2LangFeatures = Math.Pow(2, 3)
  }
}

