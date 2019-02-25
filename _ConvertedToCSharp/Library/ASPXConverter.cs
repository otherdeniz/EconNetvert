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
/// Class\t : NetVert.ASPXConverter
/// -----------------------------------------------------------------------------
/// <summary>
/// Converts ASP.NET code.
/// </summary>
/// <example>...
/// <code lang="Visual Basic">
/// </code>
/// <code lang="C#">
/// </code>
/// ...
/// <code lang="Visual Basic">
/// </code>
/// <code lang="C#">
/// </code>
/// </example>
/// <remarks>
/// Results of the <b>Convert</b>-Functions are returned as instances of this class.
/// </remarks>
/// <history>
///   [esen]  20.04.2006  created
/// </history>
/// -----------------------------------------------------------------------------
namespace Econ.NetVert
{
  public class ASPXConverter : INetVertConverter
  {
    //DECLARATIONS
    private bool FHasError = false;
    private string FErrorText = "";
    private ConverterLanguagesAutodetectable FConverterLanguage = ConverterLanguagesAutodetectable.Autodetect;
    private string FResultSource = "";

    //SHARED
#region Convert Functions

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Convert ASP.NET code using language-autodetection.
    /// </summary>
    /// <param name="aspxSource">The ASPX source code.</param>
    /// <returns>New instance of Class ASPXConverter</returns>
    /// <remarks>
    /// Supported is only ASP.NET code with inline serverside code of the languages Visual Basic .NET or C#.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public static ASPXConverter Convert(string aspxSource, ConverterLanguagesAutodetectable converterLanguage = ConverterLanguagesAutodetectable.Autodetect)
    {
      ASPXConverter RetConv = new ASPXConverter();
      Int32 TmpStart;
      Int32 TmpEnd;
      Int32 TmpLastEnd;
      string TmpDirective;
      string TmpComment = "";
      string TmpCodeLines;
      string TmpConvertCode = "";
      ArrayList TmpHtmlBlocks = new ArrayList();
      string TmpS;

      try {

        //set language
        if (converterLanguage == ConverterLanguagesAutodetectable.Autodetect) {
          RetConv.FConverterLanguage = SearchLanguage(aspxSource);
        } else {
          RetConv.FConverterLanguage = converterLanguage;
        }

        //get Before-Convert-Comment-Sign
        switch (RetConv.FConverterLanguage) {
          case ConverterLanguagesAutodetectable.CSharpToVBNet:
            TmpComment = "//";
          case ConverterLanguagesAutodetectable.VBNetToCSharp:
            TmpComment = "'";
        }

        //for each <%...%> block
        TmpStart = -1;
        TmpLastEnd = 0;
        do {
          //search "<%"
          TmpStart = aspxSource.IndexOf("<%", TmpStart + 1);
          if (TmpStart > -1) {
            //search "%>"
            TmpEnd = aspxSource.IndexOf("%>", TmpStart + 2);
            if (TmpEnd > -1) {

              if (aspxSource.Substring(TmpStart + 2, 1) == "@") {
                //if @: replace language-attribute and codebehind file extension
                TmpDirective = aspxSource.Substring(TmpStart, TmpEnd - TmpStart + 2);
                switch (RetConv.FConverterLanguage) {
                  case ConverterLanguagesAutodetectable.CSharpToVBNet:
                    TmpDirective = TmpDirective.Replace("\"c#\"", "\"vb\"").Replace(".cs\"", ".vb\"").Replace("=cs ", "=vb ").Replace("=c# ", "=vb ").Replace("\"cs\"", "\"vb\"");
                  case ConverterLanguagesAutodetectable.VBNetToCSharp:
                    TmpDirective = TmpDirective.Replace("\"vb\"", "\"c#\"").Replace(".vb\"", ".cs\"").Replace("=vb ", "=c# ");
                }
                aspxSource = aspxSource.Substring(0, TmpStart) + TmpDirective + aspxSource.Substring(TmpEnd + 2, aspxSource.Length - TmpEnd - 2);
              } else {
                //else: convert statements
                TmpHtmlBlocks.Add(aspxSource.Substring(TmpLastEnd, TmpStart - TmpLastEnd + 2));
                TmpConvertCode += TmpComment + "HTMLBLOCK-" + TmpHtmlBlocks.Count.ToString + "." + vbCrLf;
                TmpCodeLines = aspxSource.Substring(TmpStart + 2, TmpEnd - TmpStart - 2);
                TmpS = TmpCodeLines.TrimStart(char.Parse(" "), Chr(9), Chr(10), Chr(13));
                if ((TmpS != "") && (TmpS.Substring(0, 1) == "=")) {
                  //Add Temporary Out-Variable-Prefix
                  TmpCodeLines = "NETVERTASPNETOUT " + TmpS;
                }
                try {

                } catch (Exception ex) {

                }
                //if StrTrimmLeft(StrTrimmLeft(StrTrimmLeft(tmpcodelines," "), chr(9).ToString)
                TmpConvertCode += TmpCodeLines + vbCrLf;
                TmpLastEnd = TmpEnd;
              }

            }
          }
        } while (TmpStart > -1);
        //Append last HTML-Block
        if (aspxSource.Length > TmpLastEnd) {
          TmpHtmlBlocks.Add(aspxSource.Substring(TmpLastEnd, aspxSource.Length - TmpLastEnd));
          TmpConvertCode += TmpComment + "HTMLBLOCK-" + TmpHtmlBlocks.Count.ToString + "." + vbCrLf;
        }
        //Convert Code
        switch (RetConv.FConverterLanguage) {
          case ConverterLanguagesAutodetectable.CSharpToVBNet:
             // ERROR: Not supported in C#: WithStatement

            //get After-Convert-Comment-Sign
            TmpComment = "'";
          case ConverterLanguagesAutodetectable.VBNetToCSharp:
             // ERROR: Not supported in C#: WithStatement

            //get After-Convert-Comment-Sign
            TmpComment = "//";
        }

        //Remove Temporary Out-Variable-Prefix
        TmpConvertCode = TmpConvertCode.Replace("NETVERTASPNETOUT ", "");
        //Insert HTML-Blocks
        for (Int32 iBlock = 0; iBlock <= TmpHtmlBlocks.Count - 1; iBlock++) {
          TmpConvertCode = TmpConvertCode.Replace(TmpComment + "HTMLBLOCK-" + (iBlock + 1).ToString + ".", TmpHtmlBlocks(iBlock));
        }

        //set result
        RetConv.FResultSource = TmpConvertCode;

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

#endregion

    //CONSTRUCTOR
    private ASPXConverter()
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
    /// The result ASPX code.
    /// </summary>
    /// <returns></returns>
    /// <remarks>
    /// Returns the converted ASP.NET source code, if no errors are detected.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public string INetVertConverter.ASPXOutputSource {
      get { return FResultSource; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// The used language for the conversion procedure.
    /// </summary>
    /// <returns></returns>
    /// <remarks>
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public ConverterLanguagesAutodetectable ConverterLanguage {
      get { return FConverterLanguage; }
    }

#endregion

    //PRIVATE SHARED
#region ASP.NET Parsing Methods

    private static ConverterLanguages SearchLanguage(string aspxSource)
    {
      string TmpAspxLower;
      Int32 TmpPageStart;
      Int32 TmpPageEnd = -1;
      string TmpPageString;
      ConverterLanguages RetLng;

      TmpAspxLower = aspxSource.ToLower;
      //search for page-directive
      TmpPageStart = TmpAspxLower.IndexOf("<%@ page");
      //search for control-directive if no page-directive was found
      if (TmpPageStart == -1)
        TmpPageStart = TmpAspxLower.IndexOf("<%@ control");
      //search close-tag
      if (TmpPageStart > -1)
        TmpPageEnd = TmpAspxLower.IndexOf("%>", TmpPageStart);
      if (TmpPageEnd > -1) {
        TmpPageString = TmpAspxLower.Substring(TmpPageStart, TmpAspxLower.Length - TmpPageEnd);
        if ((TmpPageString.IndexOf(" language=\"vb\"") > -1) || (TmpPageString.IndexOf(" language=vb") > -1)) {
          //found VB.NET
          RetLng = ConverterLanguages.VBNetToCSharp;
        } else if ((TmpPageString.IndexOf(" language=\"c#\"") > -1) || (TmpPageString.IndexOf(" language=c#") > -1) || (TmpPageString.IndexOf(" language=cs") > -1) || (TmpPageString.IndexOf(" language=\"cs\"") > -1)) {
          //found C#
          RetLng = ConverterLanguages.CSharpToVBNet;
        } else {
          //no language= attribute found or language is not support
          throw new NetVertException("The Page-Directive does not provide a supported language. The LANGUAGE attribute in the line '<%@ Page Language=\"xx\" %>' must provide a supported value. Only the value 'VB' or 'CS' is supported at the placeholder 'xx'.");
        }
      } else {
        //no page-directive found
        throw new NetVertException("Page-Directive not found. The line '<%@ Page Language=\"xx\" %>' must be present in ASP.NET files.");
      }
      return RetLng;
    }

#endregion

    //#Region "Helper Functions"

    //  Private Overloads Shared Function StrTrimmLeft(ByVal sourceString As String, _
    //                                          ByVal leftTrimmStrings() As String, _
    //                                          Optional ByVal trimmRecursive As Boolean = True) As String
    //    Dim RetS As String = sourceString
    //    Dim TmpB As Boolean

    //    Do
    //      'replace all strings
    //      For Each s As String In leftTrimmStrings
    //        RetS = StrTrimmLeft(sourceString, s, trimmRecursive)
    //      Next
    //      'look if still some strings are at the beginning
    //      TmpB = False
    //      For Each s As String In leftTrimmStrings
    //        If RetS.StartsWith(s) Then
    //          TmpB = True
    //          Exit For
    //        End If
    //      Next
    //    Loop While TmpB
    //    Return RetS
    //  End Function

    //  Private Overloads Shared Function StrTrimmLeft(ByVal sourceString As String, _
    //                                          ByVal leftTrimmString As String, _
    //                                          Optional ByVal trimmRecursive As Boolean = True) As String
    //    Dim RetS As String

    //    If (sourceString.Length >= leftTrimmString.Length) AndAlso _
    //       (Left(sourceString, leftTrimmString.Length).ToLower = leftTrimmString.ToLower) Then
    //      RetS = Right(sourceString, sourceString.Length - leftTrimmString.Length)
    //      If trimmRecursive Then
    //        RetS = StrTrimmLeft(RetS, leftTrimmString, True)
    //      End If
    //    Else
    //      RetS = sourceString
    //    End If
    //    Return RetS
    //  End Function

    //#End Region

  }
}

