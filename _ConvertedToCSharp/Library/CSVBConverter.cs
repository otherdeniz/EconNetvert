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
/// -----------------------------------------------------------------------------
/// Project\t : Econ.NetVert
/// Class\t : NetVert.CSVBConverter
/// -----------------------------------------------------------------------------
/// <summary>
/// Converts C# code to VB.NET code.
/// </summary>
/// <example> This sample shows how to convert C# code to VB.NET code.
/// You need a TextBox named <b>TxtFromCs</b> that contains the C# code and a
/// TextBox named <b>TxtToVb</b> where the resulting VB.NET will be filled in.
/// <code lang="Visual Basic">
///     Sub ConvertCode()
///       Dim TmpConv As CSVBConverter = CSVBConverter.Convert(TxtFromCs.Text)
///       TxtToVb.Text = TmpConv.VBSource
///       If TmpConv.HasError Then
///         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
///       End If
///     End Sub
/// </code>
/// <code lang="C#">
///     void ConvertCode()
///       CSVBConverter TmpConv = CSVBConverter.Convert(TxtFromCs.Text);
///       TxtToVb.Text = TmpConv.VBSource;
///       if (TmpConv.HasError) {
///         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
///       }
///     }
/// </code>
/// This sample converts the same text, but only statements.
/// <code lang="Visual Basic">
///     Sub ConvertStatements()
///       Dim TmpConv As CSVBConverter = CSVBConverter.ConvertMethodBody(TxtFromCs.Text)
///       TxtToVb.Text = TmpConv.VBSource
///       If TmpConv.HasError Then
///         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
///       End If
///     End Sub
/// </code>
/// <code lang="C#">
///     void ConvertStatements()
///       CSVBConverter TmpConv = CSVBConverter.ConvertMethodBody(TxtFromCs.Text);
///       TxtToVb.Text = TmpConv.VBSource;
///       if (TmpConv.HasError) {
///         MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
///       }
///     }
/// </code>
/// </example>
/// <remarks>
/// Results of the <b>Convert</b>-Functions are returned as instances of this class.
/// </remarks>
/// <history>
///   [esen]  15.07.2005  created
/// \t[esen]\t17.10.2005\tv1.0
/// \t[esen]\t29.12.2005\tv1.1
///   [esen]  21.03.2006  v2.0
///   [esen]  18.08.2006  v2.1
/// </history>
/// -----------------------------------------------------------------------------
namespace Econ.NetVert
{
  public sealed class CSVBConverter : INetVertConverter
  {
    //NESTED CLASSES
#region CLASS:PreParseResult
    private class PreParseResult
    {
      //DECLARATIONS
      public string ResultString;
      public string[] OriginalSourceLines;
      public string[] FirstLinesComments;
      public ArrayList LineShifts = new ArrayList();

      //PUBLIC
      public Int32 GetShift(Int32 lineNr)
      {
        Int32 RetI = 0;

        //Returns the amount of LineShift for the Codeline 'lineNr'
        for (Int32 I = 0; I <= LineShifts.Count - 1; I++) {
          if ((Int32)LineShifts(I) < lineNr) {
            RetI += 1;
          }
        }
        return RetI;
      }

    }

#endregion

    //ENUMERATIONS
#region ENUM:CommentAreaKinds

    private enum CommentAreaKinds
    {
      Supported,
      Unsupported
    }

#endregion

    //DECLARATIONS
    private bool FHasError = false;
    private string FErrorText = "";
    private string FResultSource = "";
    private string[] FOverloadableOperators = Split("+ - IsFalse IsTrue Not + - * / \\ & ^ >> << <> > < >= <= And Like Mod Or Xor CType", " ");

    //SHARED
#region Convert Functions

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Converts one or many Namespaces, classes or methods.
    /// </summary>
    /// <param name="csSource">The C# source code.</param>
    /// <param name="fixNamespaces">Comma-sepearated list of Namespaces to fix ([default] is none).</param>
    /// <returns>New instance of Class CSVBConverter</returns>
    /// <remarks>
    /// Supported is any code that can be compiled with C# compiler, standing in a single .cs file.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public static CSVBConverter Convert(string csSource, string fixNamespaces = "")
    {
      PreParseResult TmpPreResult;
      string TmpVBSrc;
      CSVBConverter RetConv = new CSVBConverter();

      try {
        TmpPreResult = RetConv.PreParse(csSource);
        TmpVBSrc = RetConv.ConvertSource(TmpPreResult.ResultString, TmpPreResult);
        RetConv.FResultSource = RetConv.PostParse(TmpVBSrc, TmpPreResult, fixNamespaces);
#if (DEBUG)
        //catch only internal exceptions
      } catch (NetVertException nEx) {
        RetConv.FHasError = true;
        RetConv.FErrorText = nEx.Message;
#Else
        //catch all exceptions
      } catch (Exception ex) {
        RetConv.FHasError = true;
        RetConv.FErrorText = ex.Message;
#endif
      }
      return RetConv;
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Converts codesnippets and simple statements.
    /// </summary>
    /// <param name="csMethodBody">C# source code of a Function or procedure.</param>
    /// <returns>New instance of Class CSVBConverter</returns>
    /// -----------------------------------------------------------------------------
    public static CSVBConverter ConvertMethodBody(string csMethodBody)
    {
      string TmpCSSrc = "";
      string[] TmpLines;
      CSVBConverter TmpConv;

      //wrap BorderSub around the method body
      if (csMethodBody != "") {
        TmpCSSrc = "void BorderSub() {" + vbCrLf + csMethodBody + vbCrLf + "}";
      }
      //convert source
      TmpConv = Convert(TmpCSSrc);
      if (!TmpConv.HasError) {
        if (csMethodBody != "") {
          //remove BorderSub
          TmpConv.FResultSource = TmpConv.FResultSource.Substring(19, TmpConv.FResultSource.Length - 30);
          //decrese indention (left-trimm 2 spaces)
          if (TmpConv.FResultSource.IndexOf(vbCrLf) > -1) {
            //Linebreak by CR-LF
            TmpLines = Split(TmpConv.FResultSource, vbCrLf);
          } else {
            //Linebreak by LF
            TmpLines = Split(TmpConv.FResultSource, vbLf);
          }
          for (Int32 I = 0; I <= TmpLines.Length - 1; I++) {
            if ((TmpLines(I).Length > 2) && (TmpLines(I).Substring(0, 2) == "  ")) {
              TmpLines(I) = TmpLines(I).Substring(2, TmpLines(I).Length - 2);
            }
          }
          TmpConv.FResultSource = Join(TmpLines, vbCrLf);
        }
      }
      return TmpConv;
    }

#endregion

    //CONSTUCTOR
    private CSVBConverter()
    {
      //hidden .cstr
    }

    //PUBLIC
#region PUBLIC Properties

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Is an error detected.
    /// </summary>
    /// <returns>True if an error is detected.</returns>
    /// <remarks>
    /// If an error is detected the property <b>ErrorText</b> contains the details about the error.<br/>
    /// If no error is detected,the property <b>CSharpSource</b> contains the result.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public bool INetVertConverter.HasError {
      get { return FHasError; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Error description.
    /// </summary>
    /// <returns></returns>
    /// <remarks>
    /// If the error is a parser error, 5 codelines are returned as well to show the position of error.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public string INetVertConverter.ErrorText {
      get { return FErrorText; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// The result VB.NET source code.
    /// </summary>
    /// <returns></returns>
    /// <remarks>
    /// Returns the converted VB.NET source code, if no errors are detected.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public string INetVertConverter.VBSource {
      get { return FResultSource; }
    }

#endregion

    //PRIVATE
#region Parse Process Functions

    private PreParseResult PreParse(string csSrc)
    {
      string[] TmpLines;
      string TmpLine;
      string TmpFirstComments = "";
      bool TmpBeforeCode;
      bool TmpInClass;
      Int32 TmpUnsupportedRangeCloseLine = -1;
      CommentAreaKinds TmpInCommentArea = CommentAreaKinds.Supported;
      Int32 TmpBorderCloseLine;
      Int32 TmpI;
      Int32 TmpI2;
      PreParseResult RetRes = new PreParseResult();

      //store original source lines
      if (csSrc.IndexOf(vbCrLf) > -1) {
        //Linebreak by CR-LF
        RetRes.OriginalSourceLines = Split(csSrc, vbCrLf);
      } else {
        //Linebreak by LF
        RetRes.OriginalSourceLines = Split(csSrc, vbLf);
      }
      //Replace TAB's with 2 spaces
      csSrc = csSrc.Replace(Chr(9), "  ");
      if (ProviderHasParserFlag(ProviderParserFlags.HandleComments)) {
        //convert multiline comment-ranges to singleline comments
        //begin search on first sign (TmpI is current search position)
        TmpI = 0;
        while ((TmpI > -1) && (csSrc.IndexOf("/*", TmpI) > -1)) {
          //loop through every comment-range
          TmpI = csSrc.IndexOf("/*", TmpI);
          TmpI2 = csSrc.IndexOf("*/", TmpI + 2);
          if (TmpI2 > -1) {
            //check if this range-start is not allready a commentline
            if (!((TmpI > 0) && (csSrc.Substring(TmpI - 1, 1) == "/"))) {
              //TmpI is the start of the commentrange
              if (csSrc.IndexOf(vbCrLf) > -1) {
                //Linebreak by CR-LF
                TmpLines = Split(csSrc.Substring(TmpI, TmpI2 - TmpI + 2), vbCrLf);
              } else {
                //Linebreak by LF
                TmpLines = Split(csSrc.Substring(TmpI, TmpI2 - TmpI + 2), vbLf);
              }
              //only modify comment-range if it has more than one line, otherwise skip
              if (TmpLines.Length > 1) {
                //only one line
                //  TmpLines(0) = "//" & TmpLines(0).Substring(2, TmpLines(0).Length - 4)
                //Else
                //multiple lines
                for (Int32 L = 0; L <= TmpLines.Length - 1; L++) {
                  if (L == 0) {
                    //first line
                    TmpLines(L) = "//" + TmpLines(L).Substring(2, TmpLines(L).Length - 2);
                  } else if (L == TmpLines.Length - 1) {
                    //last line
                    TmpLines(L) = "//" + TmpLines(L).Substring(0, TmpLines(L).Length - 2);
                  } else {
                    //middle lines
                    TmpLines(L) = "//" + TmpLines(L);
                  }
                }
                //store modified range
                csSrc = csSrc.Substring(0, TmpI) + Join(TmpLines, vbCrLf) + csSrc.Substring(TmpI2 + 2, csSrc.Length - TmpI2 - 2);
              } else {
                //jump to next line
                TmpI2 = csSrc.IndexOf(vbCrLf, TmpI);
              }
            } else {
              //this range-start is a commentline, jump to next line
              TmpI2 = csSrc.IndexOf(vbCrLf, TmpI);
            }
          }
          //jump to TmpI2
          TmpI = TmpI2;
        }
      }
      //get all lines of code
      if (csSrc.IndexOf(vbCrLf) > -1) {
        //Linebreak by CR-LF
        TmpLines = Split(csSrc + vbCrLf, vbCrLf);
      } else {
        //Linebreak by LF
        TmpLines = Split(csSrc + vbLf, vbLf);
      }
      //process each line
      TmpBeforeCode = true;
      TmpBorderCloseLine = TmpLines.Length - 1;
      for (Int32 I = 0; I <= TmpLines.Length - 1; I++) {
        //get line without leading spaces
        TmpLine = StrTrimmLeft(StrTrimmLeft(TmpLines(I), " ", true), Chr(9).ToString, true);
        if (TmpLine.Length == 0) {
          //empty line
          if (TmpInClass && (TmpInCommentArea == CommentAreaKinds.Supported) && ProviderHasParserFlag(ProviderParserFlags.HandleComments)) {
            TmpLines(I) = "string EmptyLineVar;";
          }
        } else {
          if ((TmpLine.Length > 1) && (TmpLine.Substring(0, 2) == "//")) {
            if (ProviderHasParserFlag(ProviderParserFlags.HandleComments)) {
              //current line is a comment
              if (TmpBeforeCode) {
                TmpFirstComments += TmpLine + vbCrLf;
              } else if (TmpInClass && (TmpUnsupportedRangeCloseLine == -1)) {
                if ((TmpInCommentArea == CommentAreaKinds.Supported) && NextCodeLineHasNoneOfKeywords(TmpLines, I, new string[] {
                  "get",
                  "set"
                })) {
                  TmpLines(I) = "string CommentVar = \"" + TmpLine.Replace("\"", "§§").Replace("\\", "§$") + "\";";
                }
              }
            }
          } else if (TmpLine.Substring(0, 1) == "#") {
            if (ProviderHasParserFlag(ProviderParserFlags.HandleComments)) {
              //current line is a compilerarg or region
              if (TmpBeforeCode) {
                TmpFirstComments += TmpLine + vbCrLf;
              } else if (TmpInClass && (TmpInCommentArea == CommentAreaKinds.Supported)) {
                TmpLines(I) = "string RegionVar = \"" + TmpLine.Replace("\"", "§§").Replace("\\", "§$") + "\";";
              }
            }
          } else {
            TmpBeforeCode = false;
            if (((TmpLine.Length > 6) && (TmpLine.Substring(0, 6).ToLower == "using "))) {
              //before add border Class (USING statement)
            } else if ((TmpLine.ToLower.IndexOf("assembly: ") > -1)) {
              //before add border Class (ASSEMBLY statement)
            } else if (((TmpLine.Length > 10) && (TmpLine.Substring(0, 10).ToLower == "Namespace "))) {
              if (TmpLine.IndexOf("{") > -1) {
                TmpI = GetCloseTagLine(TmpLines, I);
              } else {
                TmpI = GetCloseTagLine(TmpLines, I + 1);
              }
              if (TmpI > -1) {
                TmpBorderCloseLine = TmpI;
              }
              if ((I < TmpBorderCloseLine)) {
                if (TmpLine.IndexOf("{") > -1) {
                  //add borderClass now after current line
                  TmpI = I;
                } else {
                  //add borderClass now after next line witch should be '{'
                  TmpI = I + 1;
                }
                TmpInClass = true;
                TmpLines(TmpI) = TmpLines(TmpI) + vbCrLf + "Class BorderClass" + vbCrLf + "{";
                TmpLines(TmpBorderCloseLine) = "}" + vbCrLf + TmpLines(TmpBorderCloseLine);
                RetRes.LineShifts.Add(RetRes.GetShift(TmpI) + TmpI);
                RetRes.LineShifts.Add(RetRes.GetShift(TmpI) + TmpI + 1);
                RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine);
              }
            } else {
              if ((I >= TmpBorderCloseLine)) {
                TmpInClass = false;
              } else {
                if (!TmpInClass) {
                  for (Int32 J = I + 1; J <= TmpLines.Length - 1; J++) {
                    if ((TmpLines(J).ToLower.IndexOf("Namespace") > -1)) {
                      TmpBorderCloseLine = J - 1;
                      break; // TODO: might not be correct. Was : Exit For
                    }
                  }
                  //add borderClass now before current line
                  TmpInClass = true;
                  TmpLine = "Class BorderClass" + vbCrLf + "{" + vbCrLf + TmpLines(I);
                  TmpLines(I) = TmpLine;
                  TmpLines(TmpBorderCloseLine) = TmpLines(TmpBorderCloseLine) + vbCrLf + "}";
                  RetRes.LineShifts.Add(RetRes.GetShift(I) + I);
                  RetRes.LineShifts.Add(RetRes.GetShift(I) + I + 1);
                  RetRes.LineShifts.Add(RetRes.GetShift(TmpBorderCloseLine) + TmpBorderCloseLine);
                }
              }
              if (ProviderHasParserFlag(ProviderParserFlags.HandleSomeNet2LangFeatures)) {
                if (KeywordInLine(TmpLine, "Partial ") > -1) {
                  //support for .NET 2.0 Language keywords: "Partial" classes
                  TmpLines(I) = TmpLine.Replace("Partial ", "").TrimEnd(' ') + "";
                }
                if (KeywordInLine(TmpLine, "operator ") > -1) {
                  //support for VB.NET 2.0 Language keywords: "Operator overloading" (C# supports operator overloading since v1.0)
                  for (Int32 iOp = 0; iOp <= FOverloadableOperators.Length - 1; iOp++) {
                    TmpLines(I) = TmpLine.Replace("operator " + FOverloadableOperators(iOp), "Operator_" + iOp.ToString);
                  }
                }
              }
            }
            if (TmpUnsupportedRangeCloseLine == I) {
              TmpUnsupportedRangeCloseLine = -1;
              TmpInCommentArea = CommentAreaKinds.Supported;
            } else if ((KeywordInLine(TmpLine, "interface ") > -1)) {
              if (TmpLine.LastIndexOf("{") > KeywordInLine(TmpLine, "interface ")) {
                TmpI = I;
              } else {
                TmpI = I + 1;
              }
              TmpUnsupportedRangeCloseLine = GetCloseTagLine(TmpLines, TmpI);
              TmpInCommentArea = CommentAreaKinds.Unsupported;
            } else if ((KeywordInLine(TmpLine, "enum ") > -1)) {
              if (TmpLine.LastIndexOf("{") > KeywordInLine(TmpLine, "enum ")) {
                TmpI = I;
              } else {
                TmpI = I + 1;
              }
              TmpUnsupportedRangeCloseLine = GetCloseTagLine(TmpLines, TmpI);
              TmpInCommentArea = CommentAreaKinds.Unsupported;
            }
          }
        }
      }
      //assign first comments
      RetRes.FirstLinesComments = Split(TmpFirstComments, vbCrLf);
      //assign result string
      RetRes.ResultString = Join(TmpLines, vbCrLf);
      return RetRes;
    }

    private string ConvertSource(string csSrc, PreParseResult preResult)
    {
      IRefactoryProvider TmpRefactoryProvider;
      Int32 TmpI;
      Int32 TmpLine;
      string[] TmpLines;
      string TmpS;
      string RetS = "";

      //get current RefacotryProvider
      TmpRefactoryProvider = SettingsManager.CurrentRefactoryProvider;
      //convert with the RefactoryProvider
      try {
        RetS = TmpRefactoryProvider.ConvertCStoVB(csSrc);
      } catch (NetVertException ex) {
        //parser error, modify text and re-throw exception
        TmpS = ex.Message.Substring(8, ex.Message.Length - 9);
        TmpI = TmpS.IndexOf(" ");
        TmpLine = Int32.Parse(TmpS.Substring(0, TmpI));
        TmpLine -= preResult.GetShift(TmpLine);
        if (TmpLine == 0)
          TmpLine = 1;
        TmpS = "Line " + TmpLine.ToString + TmpS.Substring(TmpI, TmpS.Length - TmpI);
        TmpLines = preResult.OriginalSourceLines;
        if (TmpLine > 1) {
          if (TmpLine > 2) {
            TmpS += vbCrLf + "==== " + TmpLines(TmpLine - 3);
          }
          TmpS += vbCrLf + "==== " + TmpLines(TmpLine - 2);
        }
        if (TmpLines.Length >= TmpLine) {
          TmpS += vbCrLf + "==>> " + TmpLines(TmpLine - 1);
          if (TmpLines.Length > TmpLine) {
            TmpS += vbCrLf + "==== " + TmpLines(TmpLine);
            if (TmpLines.Length > (TmpLine + 1)) {
              TmpS += vbCrLf + "==== " + TmpLines(TmpLine + 1);
            }
          }
        }
        throw new NetVertException(TmpS);
      }
      return RetS;
    }

    private string PostParse(string vbSrc, PreParseResult preResult, string fixNamespaces)
    {
      string[] TmpLines;
      string TmpLine;
      bool TmpB = false;
      Int32 TmpStart;
      Int32 TmpI;
      string TmpS;
      string TmpS2;
      string TmpS3;
      Int32 TmpBorderClassIndent = -1;
      bool TmpInOperator = false;
      bool TmpInSelect = false;
      string RetS;

      //Replace TAB's with 2 spaces
      vbSrc = vbSrc.Replace(Chr(9), "  ");
      //repair string-append syntax 'str += "blabla"' --> 'str += "blabla"'
      vbSrc = vbSrc.Replace(" += \"", " += \"");
      //get all lines of code
      if (vbSrc.IndexOf(vbCrLf) > -1) {
        //Linebreak by CR-LF
        TmpLines = Split(vbSrc, vbCrLf);
      } else {
        //Linebreak by LF
        TmpLines = Split(vbSrc, vbLf);
      }
      //process each line (fix parser bugs)
      for (Int32 Y = 0; Y <= TmpLines.Length - 1; Y++) {
        if (ProviderHasParserFlag(ProviderParserFlags.HandleICSharpCodeParserBugs)) {
          //repair Parser-Bug "wrong enumumeration declarations" (remove incorrect 'private' prefix)
          if (TmpB) {
            if (TmpLines(Y).ToLower.IndexOf("end enum") > -1) {
              TmpB = false;
            } else {
              TmpLines(Y) = TmpLines(Y).Replace("Private ", "");
            }
          } else {
            if (KeywordInLine(TmpLines(Y), "enum ") > -1) {
              TmpB = true;
            }
          }
          //repair Parser-Bug "wrong indexvariable incrementation in 'while' and 'for' statements"
          //System.Math.Min(System.Threading.Interlocked.Increment(I),I-1) -->  I += 1
          TmpStart = TmpLines(Y).ToLower.IndexOf("system.math.min(system.threading.interlocked.increment(");
          if (TmpStart > -1) {
            TmpS = TmpLines(Y).Substring(TmpStart + 55);
            TmpI = TmpS.IndexOf(")");
            if (TmpI > -1) {
              //store code after statement in TmpS2
              if (TmpS.Length > (5 + (TmpI * 2))) {
                TmpS2 = TmpS.Substring((5 + (TmpI * 2)), TmpS.Length - (5 + (TmpI * 2)));
              } else {
                TmpS2 = "";
              }
              //store I-variable in TmpS
              TmpS = TmpS.Substring(0, TmpI);
              //overwrite current line
              TmpLines(Y) = TmpLines(Y).Substring(0, TmpStart) + TmpS + " += 1" + TmpS2;
            }
          }
          //repair Parser-Bug "wrong explicit typecast"
          //CType(ConversionHelpers.AsWorkaround(myvalue, GetType(mytype)), mytype) --> CType(myvalue, mytype)
          TmpStart = TmpLines(Y).ToLower.IndexOf("ctype(conversionhelpers.asworkaround(");
          if (TmpStart > -1) {
            TmpS = TmpLines(Y).Substring(TmpStart + 37);
            TmpI = TmpS.IndexOf(",");
            if (TmpI > -1) {
              //store value in TmpS2
              TmpS2 = TmpS.Substring(0, TmpI);
              TmpI = TmpS.IndexOf("(");
              if (TmpI > -1) {
                TmpS = TmpS.Substring(TmpI, TmpS.Length - TmpI);
                TmpI = TmpS.IndexOf(")");
                if (TmpI > -1) {
                  //store code after statement in TmpS3
                  if (TmpS.Length > (5 + (TmpI * 2))) {
                    TmpS3 = TmpS.Substring((5 + (TmpI * 2)), TmpS.Length - (5 + (TmpI * 2)));
                  } else {
                    TmpS3 = "";
                  }
                  //store type in TmpS
                  TmpS = TmpS.Substring(0, TmpI);
                  //overwrite current line
                  TmpLines(Y) = TmpLines(Y).Substring(0, TmpStart) + "CType(" + TmpS2 + ", " + TmpS + ")" + TmpS3;
                }
              }
            }
          }
          //repair Parser-Bug "multiple attributes on multiple lines have only one < on first and one > on last line"
          //<MyAttrX()> _[CRLF]<MyAttrY()> _[CRLF]<MyAttrZ()>  -->  <MyAttrX(), _[CRLF] MyAttrY(), _[CRLF] MyAttrZ()>
          if ((TmpLines(Y).Length > 3) && (TmpLines(Y).Substring(TmpLines(Y).Length - 3, 3) == "> _") && (TmpLines.Length > Y + 1)) {
            //store next line without leading SPACE and TAB in TmpLine
            TmpLine = StrTrimmLeft(StrTrimmLeft(TmpLines(Y + 1), Chr(9).ToString), " ");
            if ((TmpLine.Length > 1) && (TmpLine.Substring(0, 1) == "<")) {
              //preserve Spaces before TmpLine in TmpS
              if (TmpLines(Y + 1).Length > TmpLine.Length) {
                TmpS = TmpLines(Y + 1).Substring(0, TmpLines(Y + 1).Length - TmpLine.Length);
              } else {
                TmpS = "";
              }
              //replace "> _" with ", _" at end of this line
              TmpLines(Y) = TmpLines(Y).Substring(0, TmpLines(Y).Length - 3) + ", _";
              //replace "<" with " " at begin of next line
              TmpLines(Y + 1) = TmpS + " " + TmpLine.Substring(1, TmpLine.Length - 1);
            }
          }
        }
      }
      //Lines -> String (Add Prefix: CRLF)
      vbSrc = vbCrLf + Join(TmpLines, vbCrLf);
      //fix Namespaces (remove)
      if (fixNamespaces != "") {
        foreach (string ns in Split(fixNamespaces, ",")) {
          vbSrc = vbSrc.Replace(vbCrLf + "Imports " + ns + vbCrLf, vbCrLf);
        }
      }
      //get all lines of code: String -> Lines (Remove Prefix: CRLF)
      TmpLines = Split(vbSrc.Substring(2, vbSrc.Length - 2), vbCrLf);
      //process each line (restore comments and regions)
      for (Int32 I = 0; I <= TmpLines.Length - 1; I++) {
        if ((TmpBorderClassIndent > -1) && (TmpLines(I).Length >= TmpBorderClassIndent + 9) && (TmpLines(I).Substring(TmpBorderClassIndent, 9) == "End Class")) {
          //remove end of BorderClass
          TmpBorderClassIndent = -1;
          //mark line with KILL if its not last line
          if ((TmpLines.Length > I + 1)) {
            TmpLines(I) = "KILL";
          }
        } else if (TmpLines(I).IndexOf("Class BorderClass") > -1) {
          //remove begin of BorderClass
          TmpLine = StrTrimmLeft(TmpLines(I), " ", true);
          TmpBorderClassIndent = TmpLines(I).Length - TmpLine.Length;
          TmpLines(I) = "KILL";
          if ((I > 0) && (TmpLines(I - 1) == "")) {
            //remove empty line before BorderClass (mark with KILL)
            TmpLines(I - 1) = "KILL";
          }
          //mark next line after BorderClass with KILL if its empty and not last line
          if ((TmpLines.Length > I + 1) && (TmpLines(I + 1) == "")) {
            TmpLines(I + 1) = "KILL";
          }
        } else {
          if ((TmpBorderClassIndent > -1) && (TmpLines(I).Length > 2) && (StrTrimmLeft(TmpLines(I).Substring(0, 2), " ") == "")) {
            //correct indention (remove 2 spaces because of BorderClass)
            TmpLines(I) = TmpLines(I).Substring(2, TmpLines(I).Length - 2);
          }
          //get line without leading spaces
          TmpLine = StrTrimmLeft(TmpLines(I), " ", true);
          //preserve spaces
          TmpS = TmpLines(I).Substring(0, TmpLines(I).Length - TmpLine.Length);
          if (TmpLine.Length > 0) {
            //skip empty lines
            if ((TmpLine.Length > 25) && (TmpLine.Substring(0, 25).ToLower == "dim commentvar as string ")) {
              //convert comment
              TmpLines(I) = TmpS + CSharpToVbComment(TmpLine.Substring(28, TmpLine.Length - 29));
              //mark next line with KILL if its empty and not last line
              if ((TmpLines.Length > I + 1) && (TmpLines(I + 1) == "")) {
                TmpLines(I + 1) = "KILL";
              }
            } else if ((TmpLine.Length > 29) && (TmpLine.Substring(0, 29).ToLower == "private commentvar as string ")) {
              //convert comment
              TmpLines(I) = TmpS + CSharpToVbComment(TmpLine.Substring(32, TmpLine.Length - 33));
              //mark next line with KILL if its empty and not last line
              if ((TmpLines.Length > I + 1) && (TmpLines(I + 1) == "")) {
                TmpLines(I + 1) = "KILL";
              }
            } else if ((TmpLine.Length > 24) && (TmpLine.Substring(0, 24).ToLower == "dim regionvar as string ")) {
              //convert region or compilerarg
              TmpLines(I) = CSharpToVbComment(TmpLine.Substring(27, TmpLine.Length - 28));
            } else if ((TmpLine.Length > 28) && (TmpLine.Substring(0, 28).ToLower == "private regionvar as string ")) {
              //convert region or compilerarg
              TmpLines(I) = CSharpToVbComment(TmpLine.Substring(31, TmpLine.Length - 32));
            } else if ((TmpLine // ERROR: Unknown binary operator Like
)) {
              //Empty Line
              TmpLines(I) = "";
            } else if (TmpLine.IndexOf("") > -1) {
              //restore Partial Class (new .NET 2.0 feature)
              TmpLines(I) = TmpLines(I).Replace("", "").Replace("Class ", "Partial Class ");
              //'restore Partial Class (new .NET 2.0 feature)
              //TmpLines(i) = TmpS & "Partial " & TmpLine.Replace("PartialClassConverted", "")
            } else if (TmpLine.IndexOf("Operator_") > -1) {
              //restore "Operator Overloading" Part1 (new .NET 2.0 feature for VB.NET)
              for (Int32 iOp = 0; iOp <= FOverloadableOperators.Length - 1; iOp++) {
                TmpLines(I) = TmpLines(I).Replace("Function Operator_" + iOp.ToString, "Operator " + FOverloadableOperators(iOp));
                TmpInOperator = true;
              }
            } else if (TmpLine // ERROR: Unknown binary operator Like
) {
              //begin of SELECT CASE
              TmpInSelect = true;
            } else if ((TmpLine // ERROR: Unknown binary operator Like
) && TmpInSelect) {
              //inside SELECT CASE
              //delete EXIT SELECT, if next statement is CASE
              if (NextCodeLineHasNoneOfKeywords(TmpLines, I, new string[] { "Case" })) {
                TmpLines(I) = "KILL";
              }
            } else if ((TmpLine == "End Select") && TmpInSelect) {
              //end of SELECT CASE
              TmpInSelect = false;
            } else if ((TmpLine == "End Function") && TmpInOperator) {
              //restore "Operator Overloading" Part2 (new .NET 2.0 feature for VB.NET)
              //End Function -> End Operator
              TmpLines(I) = TmpS + "End Operator";
            } else if (TmpLine // ERROR: Unknown binary operator Like
) {
              //repair compiration of Nothing (must be "is" instead of "=")
              TmpLines(I) = TmpS + TmpLine.Replace("= Nothing", "Is Nothing");
            } else if (TmpLine // ERROR: Unknown binary operator Like
) {
              //repair compiration of Not-Nothing (must be "is" instead of "=")
              TmpLines(I) = TmpS + TmpLine.Replace("<> Nothing", "Is Nothing").Replace("If ", "If Not ");
            }
          }
        }
      }
      //get first lines comments and regions
      TmpS = "";
      for (Int32 I = 0; I <= preResult.FirstLinesComments.Length - 1; I++) {
        if (preResult.FirstLinesComments(I) != "") {
          TmpS += CSharpToVbComment(preResult.FirstLinesComments(I)) + vbCrLf;
        }
      }
      //insert first lines at beginning
      RetS = TmpS + Join(TmpLines, vbCrLf) + vbCrLf;
      //remove all lines that are marked with       RetS = RetS.Replace("KILL" + vbCrLf, "");
      return RetS;
    }

#endregion

#region Helper Functions

    private bool NextCodeLineHasNoneOfKeywords(string[] codeLines, Int32 currentLine, string[] keywords)
    {
      string TmpS;
      bool RetB = true;

      TmpS = GetNextCodeLine(codeLines, currentLine);
      for (Int32 I = 0; I <= keywords.Length - 1; I++) {
        if ((KeywordInLine(TmpS, keywords(I) + " ") > -1) || ((KeywordInLine(TmpS, keywords(I)) > -1) && TmpS.EndsWith(keywords(I)))) {
          RetB = false;
          break; // TODO: might not be correct. Was : Exit For
        }
      }
      return RetB;
    }

    private string GetNextCodeLine(string[] codeLines, Int32 currentLine)
    {
      string TmpLine;
      string RetS = "";

      for (Int32 I = currentLine + 1; I <= codeLines.Length - 1; I++) {
        TmpLine = StrTrimmLeft(StrTrimmLeft(codeLines(I), " ", true), Chr(9).ToString, true);
        if ((TmpLine.Length > 0) && (TmpLine.Substring(0, 1) != "/") && (TmpLine.Substring(0, 1) != "#") && (TmpLine.TrimEnd(' ') != "{") && (TmpLine.TrimEnd(' ') != "}")) {
          //codeLines(I) is a valid codeline (not empty, not a comment, not a compiler-arg or region, not a braket)
          RetS = codeLines(I);
          break; // TODO: might not be correct. Was : Exit For
        }
      }
      return RetS;
    }

    private Int32 KeywordInLine(string codeLine, string keyWordWithSufix)
    {
      string TmpS;
      Int32 RetI;

      RetI = codeLine.ToLower.IndexOf(keyWordWithSufix);
      if (RetI > 0) {
        //check if sign before keyword is SPACE ot TAB
        TmpS = codeLine.Substring(RetI - 1, 1);
        if ((TmpS != " ") && (TmpS != Chr(9).ToString)) {
          RetI = -1;
        }
      }
      return RetI;
    }

    private bool LineInSource(string sourceString, string codeLine)
    {
      Int32 TmpI;
      bool RetB = false;

      TmpI = sourceString.IndexOf(codeLine + vbCrLf);
      if (TmpI == 0) {
        RetB = true;
      } else if (TmpI > 0) {
        do {
          TmpI -= 1;
          if (sourceString.Substring(TmpI - 1, 2) == vbCrLf) {
            RetB = true;
            break; // TODO: might not be correct. Was : Exit Do
          }
        } while ((sourceString.Substring(TmpI, 1) == " "));
      }
      return RetB;
    }

    private Int32 GetCloseTagLine(string[] codeLines, Int32 openTagLine)
    {
      Int32 TmpOpenCount = 1;
      Int32 RetI = -1;

      for (Int32 I = openTagLine + 1; I <= codeLines.Length - 1; I++) {
        for (Int32 Isign = 0; Isign <= codeLines(I).Length - 1; Isign++) {
          if (codeLines(I).Substring(Isign, 1) == "{") {
            TmpOpenCount += 1;
          } else if (codeLines(I).Substring(Isign, 1) == "}") {
            TmpOpenCount -= 1;
          }
          if (TmpOpenCount == 0) {
            break; // TODO: might not be correct. Was : Exit For
          }
        }
        if (TmpOpenCount == 0) {
          RetI = I;
          break; // TODO: might not be correct. Was : Exit For
        }
      }
      return RetI;
    }

    private string CSharpToVbComment(string commentLine)
    {
      string RetS = "";

      commentLine = commentLine.Replace("§§", "\"").Replace("§$", "\\");
      if (commentLine.Length > 1) {
        if ((commentLine.Length > 2) && commentLine.Substring(0, 3) == "///") {
          //line is a docu-comment (xml)
          RetS = "'''" + commentLine.Substring(3, commentLine.Length - 3);
        } else if (commentLine.Substring(0, 2) == "//") {
          //line is a comment
          RetS = "'" + commentLine.Substring(2, commentLine.Length - 2);
        } else if ((commentLine.Length > 7) && (commentLine.Substring(0, 7).ToLower == "#region")) {
          //Region
          RetS = "#Region \"" + commentLine.Substring(8, commentLine.Length - 8) + "\"";
        } else if ((commentLine.Length >= 10) && (commentLine.Substring(0, 10).ToLower == "#endregion")) {
          //End Region
          RetS = "#End Region";
        } else if ((commentLine.Length > 3) && (commentLine.Substring(0, 3).ToLower == "#if")) {
          //#If
          RetS = "#If " + ConvertIfStatement(commentLine.Substring(3, commentLine.Length - 3)) + " Then";
        } else if ((commentLine.Length >= 6) && (commentLine.Substring(0, 6).ToLower == "#endif")) {
          //#End If
          RetS = "#End If";
        } else if (commentLine.Substring(0, 1) == "#") {
          //something else with a leading #
          RetS = commentLine;
        }
      }
      return RetS;
    }

    private string StrTrimmLeft(string sourceString, string leftTrimmString, bool trimmRecursive = true)
    {
      string RetS;

      if ((sourceString.Length >= leftTrimmString.Length) && (Left(sourceString, leftTrimmString.Length).ToLower == leftTrimmString.ToLower)) {
        RetS = Right(sourceString, sourceString.Length - leftTrimmString.Length);
        if (trimmRecursive) {
          RetS = StrTrimmLeft(RetS, leftTrimmString, true);
        }
      } else {
        RetS = sourceString;
      }
      return RetS;
    }

    private string ConvertIfStatement(string ifStatement)
    {
      IRefactoryProvider TmpRefactoryProvider;
      string TmpSrc;
      Int32 TmpI;
      string RetS = "";

      //get current RefacotryProvider
      TmpRefactoryProvider = SettingsManager.CurrentRefactoryProvider;
      //wrap BorderClass, BorderSub and If-Block around the ifStatement
      TmpSrc = "Class BorderClass {" + vbCrLf + "void BorderSub() {" + vbCrLf + "if " + ifStatement + " { }" + vbCrLf + "}" + vbCrLf + "}";
      try {
        //convert with the RefactoryProvider
        RetS = TmpRefactoryProvider.ConvertCStoVB(TmpSrc);
        //remove all wrapped Borders
        TmpI = RetS.IndexOf("If");
        RetS = RetS.Substring(TmpI + 3, RetS.IndexOf("Then", TmpI) - TmpI - 4);
      } catch (Exception ex) {
        //could not convert statement, return orginal
        RetS = ifStatement;
      }
      return RetS;
    }

    private bool ProviderHasParserFlag(ProviderParserFlags parserFlag)
    {
      return (SettingsManager.CurrentRefactoryProvider.PreAndPostParseFlags & parserFlag) == parserFlag;
    }

#endregion

  }
}

