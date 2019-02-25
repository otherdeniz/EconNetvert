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
/// <summary>
/// Contains informations about the conversion of a file.
/// </summary>
using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.NetVert
{
  public class ProcessedFileEventArgs : EventArgs
  {
    public enum ConverterFileTypes
    {
      CodeFile,
      VSProjectFile,
      ASPXFile,
      OtherFile
    }

    public enum ConverterOperations
    {
      Before_Conversion = 0,
      Success_Creating = 10,
      Success_Overwriting = 11,
      FlatCopy = 15,
      Skipped_Exists = 20,
      Skipped_Error = 21
    }

    //DECLARATIONS
    private ConverterFileTypes FFileType;
    private string FInputFile;
    private string FInputSource;
    private string FOutputFile;
    private string FOutputSource;
    private ConverterOperations FOperation;
    private ConverterLanguagesAutodetectable FConverterLanguage;
    private string FConverterError;

    //CONSTRUCTOR
    internal ProcessedFileEventArgs(ConverterFileTypes fileType, string inFile, string inSource, string outFile, string outSource, ConverterOperations convOperation, ConverterLanguagesAutodetectable convLang, string convError)
    {
      FFileType = fileType;
      FInputFile = inFile;
      FInputSource = inSource;
      FOutputFile = outFile;
      FOutputSource = outSource;
      FOperation = convOperation;
      FConverterLanguage = convLang;
      FConverterError = convError;
    }

    //PUBLIC
#region PUBLIC Properties

    public ConverterFileTypes FileType {
      get { return FFileType; }
    }

    public string InputFile {
      get { return FInputFile; }
    }

    public string InputSource {
      get { return FInputSource; }
      set { FInputSource = value; }
    }

    public Int32 InputLinesOfCode {
      get { return Split(FInputSource, vbCrLf).Length; }
    }

    public string OutputFile {
      get { return FOutputFile; }
      set { FOutputFile = value; }
    }

    public string OutputSource {
      get { return FOutputSource; }
      set { FOutputSource = value; }
    }

    public Int32 OutputLinesOfCode {
      get { return Split(FOutputSource, vbCrLf).Length; }
    }

    public ConverterOperations ConverterOperation {
      get { return FOperation; }
    }

    public ConverterLanguagesAutodetectable ConverterLanguage {
      get { return FConverterLanguage; }
    }

    public string ConverterError {
      get { return FConverterError; }
    }

#endregion

    public override string ToString()
    {
      return this.ToString("", "");
    }

    public string ToString(string inputRootPath, string outputRootPath)
    {
      string TmpFT = "";
      string TmpOutLng = "";
      string RetS = "";

      switch (FFileType) {
        case ConverterFileTypes.CodeFile:
          TmpFT = "Codefile";
        case ConverterFileTypes.ASPXFile:
          TmpFT = "ASP.NET File";
          switch (FConverterLanguage) {
            case ConverterLanguagesAutodetectable.VBNetToCSharp:
              TmpOutLng = " [C#]";
            case ConverterLanguagesAutodetectable.CSharpToVBNet:
              TmpOutLng = " [VB.NET]";
          }
        case ConverterFileTypes.VSProjectFile:
          TmpFT = "Visual Studio Project";
        case ConverterFileTypes.OtherFile:
          TmpFT = "File";
      }
      switch (FOperation) {
        case ConverterOperations.Before_Conversion:
          RetS = "Reading " + TmpFT + " '" + TrimmPath(FInputFile, inputRootPath) + "' (" + InputLinesOfCode.ToString + " lines, " + InputSource.Length.ToString + " bytes)";
        case ConverterOperations.Skipped_Error:
          RetS = "Error in " + TmpFT + " '" + TrimmPath(FInputFile, inputRootPath) + "'" + vbCrLf + FConverterError;
        case ConverterOperations.Skipped_Exists:
          RetS = "Skipped, " + TmpFT + " exists '" + TrimmPath(FOutputFile, outputRootPath) + "'";
        case ConverterOperations.Success_Creating:
          RetS = "Creating " + TmpFT + TmpOutLng + " '" + TrimmPath(FOutputFile, outputRootPath) + "' (" + OutputLinesOfCode.ToString + " lines, " + OutputSource.Length.ToString + " bytes)";
        case ConverterOperations.Success_Overwriting:
          RetS = "Overwriting " + TmpFT + TmpOutLng + " '" + TrimmPath(FOutputFile, outputRootPath) + "' (" + OutputLinesOfCode.ToString + " lines, " + OutputSource.Length.ToString + " bytes)";
        case ConverterOperations.FlatCopy:
          RetS = "Copy " + TmpFT + " '" + TrimmPath(FOutputFile, outputRootPath) + "'";
      }
      return RetS;
    }

    //FRIEND
    internal void ModifyStatus(ConverterOperations convStatus, string convError = "", ConverterLanguagesAutodetectable convLang = ConverterLanguagesAutodetectable.Autodetect)
    {
      FOperation = convStatus;
      FConverterError = convError;
      if (convLang != ConverterLanguagesAutodetectable.Autodetect) {
        FConverterLanguage = convLang;
      }
    }

    //PRIVATE
    private string TrimmPath(string fullPath, string removePath)
    {
      string RetS;

      if ((removePath != "") && (fullPath.Length > removePath.Length) && (fullPath.Substring(0, removePath.Length).ToLower == removePath.ToLower)) {
        RetS = fullPath.Substring(removePath.Length, fullPath.Length - removePath.Length).TrimStart('\\');
      } else {
        RetS = fullPath;
      }
      return RetS;
    }

  }
}

