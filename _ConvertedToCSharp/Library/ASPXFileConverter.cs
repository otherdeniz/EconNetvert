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
/// Class\t : NetVert.ASPXFileConverter
/// -----------------------------------------------------------------------------
/// <summary>
/// Converts ASP.NET files.
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
/// <history>
///   [esen]  01.05.2006  created
/// </history>
/// -----------------------------------------------------------------------------
namespace Econ.NetVert
{
  public sealed class ASPXFileConverter
  {
    //DECLARATIONS
    private ConverterLanguagesAutodetectable FLanguage;
    private Int32 FTotalCount = 0;
    private Int32 FConvertedCount = 0;
    private Int32 FFailedCount = 0;

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
    /// Create new ASPXFileConverter instance.
    /// </summary>
    /// <param name="language">An enumeration value. Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.</param>
    /// <remarks>
    /// The property <b>language</b> could not be changed on existing instances.
    /// </remarks>
    /// -----------------------------------------------------------------------------
    public ASPXFileConverter(ConverterLanguagesAutodetectable language = ConverterLanguagesAutodetectable.Autodetect)
    {
      FLanguage = language;
    }

    //PUBLIC
#region PUBLIC Properties

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

#endregion

#region Convert Functions

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Convert multiple ASPX files.
    /// </summary>
    /// <param name="sourceDir">The full path to the source directory.</param>
    /// <param name="wildcards">One or multiple wildcards or filenames to search for in sourceDir ([default] is <b>*.aspx,*.ascx</b>).<br/>
    /// When using multiple wildcards, use comma as delimiter.</param>
    /// <param name="targetDir">The full path to the destination directory ([default] is same than sourceDir).</param>
    /// <param name="recurseSubDirs">True if subdirectories should be included ([default] is false).</param>
    /// <param name="overwriteExistingFiles">True if existing files should be overwriten ([default] is false).</param>
    /// -----------------------------------------------------------------------------
    /// <remarks>
    /// If the targetDir equals to sourceDir, the converted filenames get modified as follow: "(file).converted.(ext)"<br/>
    /// For example: "default.aspx" (VB.NET) will be converted to "default.converted.aspx" (C#)
    /// </remarks>
    public void ConvertFiles(string sourceDir, string wildcards = "", string targetDir = "", bool recurseSubDirs = false, bool overwriteExistingFiles = false)
    {
      string[] TmpWildcards;
      string[] TmpFiles;
      string TmpTarget;

      if (wildcards == "") {
        //use default wildcard
        wildcards = "*.aspx,*.ascx,*.asmx";
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
          if (targetDir == sourceDir) {
            TmpTarget = Path.Combine(targetDir, Path.GetFileNameWithoutExtension(TmpFiles(I)) + ".converted" + Path.GetExtension(TmpFiles(I)));
          } else {
            TmpTarget = Path.Combine(targetDir, Path.GetFileName(TmpFiles(I)));
          }
          ConvertFile(TmpFiles(I), TmpTarget, overwriteExistingFiles);
        }
        if (recurseSubDirs) {
          foreach (string SF in Directory.GetDirectories(sourceDir)) {
            ConvertFiles(SF, wildcards, Path.Combine(targetDir, Path.GetFileName(SF)), true, overwriteExistingFiles);
          }
        }
      } else {
        throw new ArgumentException("missing wildcards");
      }
    }

    /// -----------------------------------------------------------------------------
    /// <summary>
    /// Convert single ASPX file.
    /// </summary>
    /// <param name="sourceFile">The full path and filename to the source ASPX file.</param>
    /// <param name="targetFile">The full path and filename to the destination ASPX file.</param>
    /// <param name="overwriteExistingFile">True if existing file should be overwriten ([default] is false).</param>
    /// -----------------------------------------------------------------------------
    public void ConvertFile(string sourceFile, string targetFile, bool overwriteExistingFile = false)
    {
      ASPXConverter TmpConv;
      string TmpS;
      ProcessedFileEventArgs TmpE;

      try {

         // ERROR: Not supported in C#: WithStatement

        FTotalCount += 1;
        if (File.Exists(targetFile) && !overwriteExistingFile) {
          //Skipped, file exists
          if (AfterFileProcessed != null) {
            AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Exists, FLanguage, ""));
          }
        } else {
           // ERROR: Not supported in C#: WithStatement

          //create EventArgs
          TmpE = new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, sourceFile, TmpS, targetFile, "", ProcessedFileEventArgs.ConverterOperations.Before_Conversion, FLanguage, "");
          if (BeforeFileProcessed != null) {
            BeforeFileProcessed(this, TmpE);
          }
          //convert now
          TmpConv = ASPXConverter.Convert(TmpS, FLanguage);
          if (TmpConv.HasError) {
            //has an error
            FFailedCount += 1;
            TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Skipped_Error, TmpConv.ErrorText, TmpConv.ConverterLanguage);
            if (AfterFileProcessed != null) {
              AfterFileProcessed(this, TmpE);
            }
          } else {
            //no error
            FConvertedCount += 1;
            if (File.Exists(targetFile)) {
              TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Overwriting, "", TmpConv.ConverterLanguage);
              File.Delete(targetFile);
            } else {
              TmpE.ModifyStatus(ProcessedFileEventArgs.ConverterOperations.Success_Creating, "", TmpConv.ConverterLanguage);
            }
            TmpE.OutputSource = TmpConv.ASPXOutputSource;
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
          AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message));
        }
#Else
      } catch (Exception ex) {
        //common error
        if (AfterFileProcessed != null) {
          AfterFileProcessed(this, new ProcessedFileEventArgs(ProcessedFileEventArgs.ConverterFileTypes.ASPXFile, sourceFile, "", targetFile, "", ProcessedFileEventArgs.ConverterOperations.Skipped_Error, FLanguage, ex.Message));
        }
#endif
      }


      //With Directory.GetParent(targetFile)
      //  If Not .Exists Then
      //    OutputText("Creating directory " & .FullName)
      //    .Create()
      //  End If
      //End With
      //FTotalCount += 1
      //If File.Exists(targetFile) AndAlso _
      //   Not overwriteExistingFile Then
      //  OutputText("Skipped, file exists " & targetFile)
      //Else

      //  TmpReader = File.OpenText(sourceFile)
      //  TmpS = TmpReader.ReadToEnd
      //  TmpReader.Close()
      //  'TmpError = ""
      //  TmpConv = ASPXConverter.Convert(TmpS, FLanguage)
      //  If TmpConv.HasError Then
      //    'has an error
      //    FFailedCount += 1
      //    OutputText("Error in " & sourceFile & vbCrLf & TmpConv.ErrorText)
      //  Else
      //    'no error
      //    If File.Exists(targetFile) Then
      //      OutputText("Overwriting " & targetFile)
      //    Else
      //      OutputText("Creating " & targetFile)
      //    End If
      //    FConvertedCount += 1
      //    TmpWriter = File.CreateText(targetFile)
      //    TmpWriter.Write(TmpConv.ASPXOutputSource)
      //    TmpWriter.Close()
      //  End If

      //End If
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

