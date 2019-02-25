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
/// -----------------------------------------------------------------------------
/// <summary>
/// Determines the source and target programming language.
/// </summary>
/// <remarks>
/// Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.
/// </remarks>
/// -----------------------------------------------------------------------------
using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.NetVert
{
  public enum ConverterLanguages
  {
    VBNetToCSharp = 0,
    CSharpToVBNet = 1
  }

  /// -----------------------------------------------------------------------------
  /// <summary>
  /// Determines the source and target programming language for ASP.NET conversion.
  /// </summary>
  /// <remarks>
  /// Used for ASPX language selection.<br/>
  /// Autodetect searchs for the LANGUAGE="xx" attribut in the ASP.NET page-directive.
  /// </remarks>
  /// -----------------------------------------------------------------------------
  public enum ConverterLanguagesAutodetectable
  {
    VBNetToCSharp = 0,
    CSharpToVBNet = 1,
    Autodetect = 9
  }
}

