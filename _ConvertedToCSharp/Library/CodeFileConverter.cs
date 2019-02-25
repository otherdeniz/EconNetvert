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
/// Class\t : NetVert.CodeFileConverter
/// -----------------------------------------------------------------------------
/// <summary>
/// Converts codefiles between VB.NET and C#.
/// </summary>
/// <example> This sample converts all VB.NET Files from "C:\VBFiles" to "C:\CSharpFiles".
/// <code lang="Visual Basic">
///     Sub ConvertFiles()
///       Dim TmpConv As New CodeFileConverter(ConverterLanguages.VBNetToCSharp, AddressOf OutputText)
///       TmpConv.ConvertFiles("C:\VBFiles", "", "C:\CSharpFiles", True, True)
///     End Sub
///     Private Sub OutputText(ByVal textLine As String)
///       'TODO: write textLine to output window or logfile here
///     End Sub
/// </code>
/// <code lang="C#">
///     void ConvertFiles()
///     {
///       CodeFileConverter TmpConv = new CodeFileConverter(ConverterLanguages.VBNetToCSharp, new OutputProcedureDelegate(OutputText));
///       TmpConv.ConvertFiles("C:\\VBFiles", "", "C:\\CSharpFiles", true, true);
///     }
///     private void OutputText(string textLine)
///     {
///       //TODO: write textLine to output window or logfile here
///     }
/// </code>
/// </example>
/// <history>
///   [esen]  15.07.2005  created
/// \t[esen]\t17.10.2005\tv1.0
/// \t[esen]\t30.12.2005\tv1.1
///   [esen]  21.03.2006  v2.0
/// </history>
/// -----------------------------------------------------------------------------
namespace Econ.NetVert
{
  public sealed class CodeFileConverter
  {
    //DECLARATIONS
    private ConverterLanguages FLanguage;
    private Int32 FTotalCount = 0;
    private Int32 FConvertedCount = 0;
    private Int32 FFailedCount = 0;
    private string FFixNamespaces = "System,System.Collections,System.Data,System.Diagnostics";

    //EVENTS
#region PUBLIC Events

    /// <summary>
    /// This event is raised for each file, before the conversion procedure.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    /// <remarks></remarks>
    public event BeforeFileProcessedEventHandler BeforeFileProcessed;
    public delegate void BeforeFileProcessedEventHandler(object sender, ProcessedFileEventArgs e);

    /// <summary>
    /// This event is raised for each file, after the conversion procedure.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    /// <remarks></remarks>
    public event AfterFileProcessedEventHandler AfterFileProcessed;
    public delegate void AfterFileProcessedEventHandler(object sender, ProcessedFileEventArgs e);

#endregion

    //CONSTRUCTOR
    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Create new CodeFileConverter instance.
    /// </summary>
    /// <param name="language">An enumeration value. Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.</param>
    /// <remarks>
    /// The property <b>language</b> could not be changed on existing instances.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public CodeFileConverter(ConverterLanguages language)
    {
      FLanguage = language;
    }

    //PUBLIC
#region PUBLIC Properties

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Default wildcard to search for files. Allways "*.vb" or "*.cs"
    /// </summary>
    /// <returns>"*.vb" for VBNetToCSharp, "*.cs" for CSharpToVBNet</returns>
    /// -----------------------------------------------------------------------------
    public string DefaultWildcard {
      get {
        string RetS = "";
        switch (FLanguage) {
          case ConverterLanguages.VBNetToCSharp:
            RetS = "*.vb";
          case ConverterLanguages.CSharpToVBNet:
            RetS = "*.cs";
        }
        return RetS;
      }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Returns the extension for converted files. Allways "cs" or "vb"
    /// </summary>
    /// <returns>"cs" for VBNetToCSharp, "vb" for CSharpToVBNet</returns>
    /// -----------------------------------------------------------------------------
    public string OutputFileExtension {
      get {
        string RetS = "";
        switch (FLanguage) {
          case ConverterLanguages.VBNetToCSharp:
            RetS = "cs";
          case ConverterLanguages.CSharpToVBNet:
            RetS = "vb";
        }
        return RetS;
      }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Returns the total number of files that matched the wildcard.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public Int32 TotalFilesCount {
      get { return FTotalCount; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Returns the number of files that are converted without errors.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public Int32 ConvertedFilesCount {
      get { return FConvertedCount; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Returns the number of files that failed converting, because of errors.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public Int32 FailedFilesCount {
      get { return FFailedCount; }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Returns the summary text.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public string SummaryText {
      get {
        string RetS;
        RetS = "Processed Files: " + TotalFilesCount.ToString + vbCrLf + "Converted: " + ConvertedFilesCount.ToString + vbCrLf + "Failed: " + FailedFilesCount.ToString + vbCrLf;
        return RetS;
      }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Specifies a comma-sepearated list of Namespaces to fix.<br/>
    /// If the <b>FixNamespace</b> parameter of the <b>Convert</b>-Methods is enabled, the converter appends using-statements at
    /// beginning of C#-Files if converting from VB.NET to C# or removes import-statements from VB.NET-files if they are one of the
    /// here specified Namespaces.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public string FixNamespaces {
      get { return FFixNamespaces; }
      set { FFixNamespaces = value; }
    }

#endregion

#region Convert Functions

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Convert multiple codefiles.
    /// </summary>
    /// <param name="sourceDir">The full path to the source directory.</param>
    /// <param name="wildcards">One or multiple wildcards or filenames to search for in sourceDir ([default] is <b>CodeFileConverter.DefaultWildcard</b>).<br/>
    /// When using multiple wildcards, use comma as delimiter. For example: <b>a*.vb,b*.vb,c*.vb</b> to convert all codefiles beginning with a, b or c.</param>
    /// <param name="targetDir">The full path to the destination directory ([default] is same than sourceDir).</param>
    /// <param name="recurseSubDirs">True if subdirectories should be included ([default] is false).</param>
    /// <param name="overwriteExistingFiles">True if existing files should be overwriten ([default] is false).</param>
    /// <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property ([default] is false).</param>
    /// -----------------------------------------------------------------------------
    public void ConvertFiles(string sourceDir, string wildcards = "", string targetDir = "", bool recurseSubDirs = false, bool overwriteExistingFiles = false, bool fixNamespaces = false)
    {
      string[] TmpWildcards;
      string[] TmpFiles;
      string TmpTarget;

      if (wildcards == "") {
        //use default wildcard
        wildcards = DefaultWildcard;
      }
      if (targetDir == "") {
        //use source-dir as target-dir by default
        targetDir = sourceDir;
      }
      TmpWildcards = Split(wildcards, ",", Compare: CompareMethod.Text);
      if (TmpWildcards.Length > 0) {
        //get files for the first wildcard in wildcards and save in TmpFiles
        TmpFiles = Directory.GetFiles(sourceDir, TmpWildcards(0));
        for (Int32 iW = 1; iW <= TmpWildcards.Length - 1; iW++) {
          //get files for wildcard 1-n in wildcards and append to TmpFiles
           // ERROR: Not supported in C#: WithStatement

        }
        for (Int32 I = 0; I <= TmpFiles.Length - 1; I++) {
          TmpTarget = Path.Combine(targetDir, Path.GetFileNameWithoutExtension(TmpFiles(I)) + "." + OutputFileExtension);
          ConvertFile(TmpFiles(I), TmpTarget, overwriteExistingFiles, fixNamespaces);
        }
        if (recurseSubDirs) {
          foreach (string SF in Directory.GetDirectories(sourceDir)) {
            ConvertFiles(SF, wildcards, Path.Combine(targetDir, Path.GetFileName(SF)), true, overwriteExistingFiles, fixNamespaces);
          }
        }
      } else {
        throw new ArgumentException("missing wildcards");
      }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Convert single codefile.
    /// </summary>
    /// <param name="sourceFile">The full path and filename to the source codefile.</param>
    /// <param name="targetFile">The full path and filename to the destination codefile ([default] is same than sourceFile with changed extension).</param>
    /// <param name="overwriteExistingFile">True if existing file should be overwriten ([default] is false).</param>
    /// <param name="fixNamespaces">True if enable the append/remove default-using-statements as defined in the FixNamespaces Property ([default] is false).</param>
    /// -----------------------------------------------------------------------------
    public void ConvertFile(string sourceFile, string targetFile = "", bool overwriteExistingFile = false, bool fixNamespaces = false)
    {
      INetVertConverter TmpConv;
      string TmpS;
      ProcessedFileEventArgs TmpE;
      string TmpFixNS = "";

      try {

        if (targetFile == "") {
          targetFile = Path.ChangeExtension(sourceFile, "." + OutputFileExtension);
        }
         // ERROR: Not supported in C#: WithStatement

        FTotalCount += 1;
        if (File.Exists(targetFile) && !overwriteExistingFile) {
          //Skipped, file exists
          //OLD: OutputText("Skipped, file exists " & targetFile)
          //RaiseEvent AfterFileProcessed(Me, New ProcessedFileEventArgs(sourceFile, 0, targetFile, 0, ProcessedFileEventArgs.FileStatus.Skipped_Exists, FLanguage, ""))
          if (AfterFileProcessed != null) {
            AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Exists, FLanguage, ""));
          }
        } else {
           // ERROR: Not supported in C#: WithStatement

          //create EventArgs
          TmpE = new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, sourceFile, TmpS, targetFile, "", ProcessedFileEventArgs.ConverterOperations.Before_Conversion, FLanguage, "");
          if (BeforeFileProcessed != null) {
            BeforeFileProcessed(this, TmpE);
          }
          //set Namespaces to fix
          if (fixNamespaces) {
            TmpFixNS = FFixNamespaces;
          }
          //create Converter instance with apropreate language
          if (FLanguage == ConverterLanguages.VBNetToCSharp) {
            TmpConv = VBCSConverter.Convert(TmpE.InputSource, TmpFixNS);
          } else if (FLanguage == ConverterLanguages.CSharpToVBNet) {
            TmpConv = CSVBConverter.Convert(TmpE.InputSource, TmpFixNS);
          } else {
            throw new Exception("Converter-Language not supported");
          }
          if (TmpConv.HasError) {
            //has an error
            FFailedCount += 1;
            //OLD: OutputText("Error in " & sourceFile & vbCrLf & TmpConv.ErrorText)
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, TmpConv.ErrorText);
            if (AfterFileProcessed != null) {
              AfterFileProcessed(this, TmpE);
            }
          } else {
            //no error
            FConvertedCount += 1;
            if (File.Exists(targetFile)) {
              TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Overwriting);
              File.Delete(targetFile);
            } else {
              TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Creating);
            }
            TmpE.OutputSource = TmpConv.OutputSource;
            if (AfterFileProcessed != null) {
              AfterFileProcessed(this, TmpE);
            }
            //save new stream to file
            try {
               // ERROR: Not supported in C#: WithStatement

            } catch (Exception ex) {
              TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, ex.Message);
              if (AfterFileProcessed != null) {
                AfterFileProcessed(this, TmpE);
              }
            }
          }

        }

#if (DEBUG)
      } catch (NetVertException ex) {
        //common error
        if (AfterFileProcessed != null) {
          AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message));
        }
#Else
      } catch (Exception ex) {
        //common error
        if (AfterFileProcessed != null) {
          AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.CodeFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message));
        }
#endif
      }

    }

#endregion

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Reset all Count properties.
    /// </summary>
    /// -----------------------------------------------------------------------------
    public void ResetCounters()
    {
      FTotalCount = 0;
      FConvertedCount = 0;
      FFailedCount = 0;
    }

    //PRIVATE
    //Private Sub OutputText(ByVal textLine As String)
    //  If Not FOutputFunction Is Nothing Then
    //    FOutputFunction.Invoke(textLine & vbCrLf)
    //  End If
    //End Sub

  }
}

