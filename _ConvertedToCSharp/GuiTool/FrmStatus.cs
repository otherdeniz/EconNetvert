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
using System.Text;
using System.IO;
namespace Econ.Netvert.Gui
{
  public partial class FrmStatus : SingleInstance.ISingleInstanceForm
  {
    //DECLARATIONS
    private string FTargetRoot = "";
    private string FTargetHistory = "";
    private Queue FFileList = new Queue();
    private ArrayList FFileListHistory = new ArrayList();
    private bool FHandleKeys = false;
    private bool FProcessing = true;

#if (Win32Only)
    //BEGIN Win32 Only

    //Win32-API
 // ERROR: Not supported in C#: DeclareDeclaration
 // ERROR: Not supported in C#: DeclareDeclaration
 // ERROR: Not supported in C#: DeclareDeclaration

#region SingleInstance Handler

    public event WndProc2EventHandler WndProc2;
    public delegate void WndProc2EventHandler(System.Windows.Forms.Message m, ref bool Cancel);

    protected override void WndProc(ref System.Windows.Forms.Message m)
    {
      bool bCancel = false;
      if (WndProc2 != null) {
        WndProc2(m, bCancel);
      }
      try {
        if (!bCancel)
          base.WndProc(m);
      } catch (Exception ex) {
#if (DEBUG)
        Debug.WriteLine("Unhandled Exception: " + ex.Message, "Econ Framework Core");
#endif
      }
    }

    public System.IntPtr SingleInstance.ISingleInstanceForm.hWnd {
      get { return Handle; }
    }

    //Public Sub HandleCommand(ByVal strCmd As String) Implements SingleInstance.ISingleInstanceForm.HandleCommand
    //  Dim arrCmd() As String
    //  Try
    //    arrCmd = SerialHelper.DeserializeFromBase64String(strCmd)
    //    HandleCommand(arrCmd)
    //  Catch ex As Exception
    //    MsgBox("Could not handle commandline arguments, Error: " & ex.ToString, MsgBoxStyle.Exclamation, "Error")
    //  Finally
    //    Erase arrCmd
    //  End Try
    //End Sub

    public void SingleInstance.ISingleInstanceForm.SetToForeground()
    {
      this.Focus();
      //hmmm... not working (why)
      //SetActiveWindow(Me.Handle.ToInt32)
      //SetForegroundWindow(Me.Handle.ToInt32)
      //SetFocus(Me.Handle.ToInt32)
    }

#endregion

    //END Win32 Only
#endif

    //PUBLIC
    public virtual void SingleInstance.ISingleInstanceForm.HandleCommand(string strArgs)
    {
      string TmpFile;

      if (strArgs != "") {
        TmpFile = strArgs.TrimStart('?').TrimEnd(Chr(0));
        ConvertFile(TmpFile);
        //check if conversion is still running
        if (!FProcessing) {
          //choose new destination
          if (strArgs.StartsWith("?")) {
            if (!SetDestination(TmpFile.Substring(0, TmpFile.Length - Path.GetFileName(TmpFile).Length - 1))) {
              //user abort
              return;
            }
          }
          //restart the conversion
          FProcessing = true;
          BtnCancel.Text = "Cancel";
          this.AcceptButton = null;
          StartConversion(true);
        }
      }
    }

    public bool SetDestination(string currentFolder)
    {
      FolderBrowserDialog TmpDlg;
      bool RetB = false;

      if (FTargetRoot == "") {
        //ask user
        TmpDlg = new FolderBrowserDialog();
        TmpDlg.ShowNewFolderButton = true;
        TmpDlg.SelectedPath = currentFolder;
        TmpDlg.Description = "Choose destination Path for converted files.";
        if (TmpDlg.ShowDialog() == Windows.Forms.DialogResult.OK) {
          FTargetRoot = TmpDlg.SelectedPath;
          FTargetHistory = FTargetRoot;
          RetB = true;
        }
      } else {
        //already set
        RetB = true;
      }
      return RetB;
    }

    public void ConvertFile(string srcFile)
    {
      FFileList.Enqueue(srcFile);
      FFileListHistory.Add(srcFile);
    }

    public void StartConversion(bool appendConversion = false)
    {
      CodeFileConverter TmpConvVBCS;
      CodeFileConverter TmpConvCSVB;
      VSProjectFileConverter TmpProjConvVBCS;
      VSProjectFileConverter TmpProjConvCSVB;
      ASPXFileConverter TmpAspxConv;
      CodeFileConverter TmpConv;
      VSProjectFileConverter TmpProjConv;
      string TmpSrcFile;
      string TmpTargetFile;
      Int32 TmpErrCount = 0;

      if (!appendConversion) {
        //clear output-TextBox
        TxtStatus.Text = "";
      }
      OutputMessage("Converting..." + vbCrLf);
      //create all converts
      TmpConvVBCS = new CodeFileConverter(ConverterLanguages.VBNetToCSharp);
      TmpConvCSVB = new CodeFileConverter(ConverterLanguages.CSharpToVBNet);
      TmpProjConvVBCS = new VSProjectFileConverter(ConverterLanguages.VBNetToCSharp);
      TmpProjConvCSVB = new VSProjectFileConverter(ConverterLanguages.CSharpToVBNet);
      TmpAspxConv = new ASPXFileConverter(ConverterLanguagesAutodetectable.Autodetect);
      //add event-handlers
      TmpConvVBCS.AfterFileProcessed += Converter_AfterFileProcessed;
      TmpConvCSVB.AfterFileProcessed += Converter_AfterFileProcessed;
      TmpProjConvVBCS.AfterFileProcessed += Converter_AfterFileProcessed;
      TmpProjConvCSVB.AfterFileProcessed += Converter_AfterFileProcessed;
      TmpAspxConv.AfterFileProcessed += Converter_AfterFileProcessed;
      //wait for all events
      System.Windows.Forms.Application.DoEvents();
      //start execution-loop
      while (FFileList.Count > 0) {
        if (!FProcessing) {
          //user-abort
          FTargetRoot = "";
          OutputMessage("--------------------------------------" + vbCrLf);
          OutputMessage("--------------------------------------" + vbCrLf);
          OutputMessage("Abort by user!" + vbCrLf);
          if (SettingsManager.AutoCloseStatusDialogs) {
            System.Windows.Forms.Application.DoEvents();
            //wait 2 seconds
            System.Threading.Thread.Sleep(2000);
            System.Environment.Exit(0);
          } else {
            BtnRestart.Visible = true;
            BtnCancel.Text = "Close";
            this.AcceptButton = BtnCancel;
            BtnCancel.Focus();
          }
          return;
        }
        //reset previous converter
        TmpConv = null;
        TmpProjConv = null;
        //get next file of queue
        TmpSrcFile = FFileList.Dequeue;
        switch (Path.GetExtension(TmpSrcFile).ToLower) {
          case ".vb":
            TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "cs");
            TmpConv = TmpConvVBCS;
            OutputMessage("Converting Codefile '" + Path.GetFileName(TmpSrcFile) + "' from VB.NET to C#..." + vbCrLf);
          case ".cs":
            TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "vb");
            TmpConv = TmpConvCSVB;
            OutputMessage("Converting Codefile '" + Path.GetFileName(TmpSrcFile) + "' from C# to VB.NET..." + vbCrLf);
          case ".vbproj":
            TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "csproj");
            TmpProjConv = TmpProjConvVBCS;
            OutputMessage("Converting Visual Studio Project '" + Path.GetFileName(TmpSrcFile) + "' from VB.NET to C#..." + vbCrLf);
          case ".csproj":
            TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "vbproj");
            TmpProjConv = TmpProjConvCSVB;
            OutputMessage("Converting Visual Studio Project '" + Path.GetFileName(TmpSrcFile) + "' from C# to VB.NET..." + vbCrLf);
          case ".aspx":
          case ".ascx":
          case "*.asmx":
            TmpTargetFile = TmpSrcFile;
            OutputMessage("Converting ASP.NET File '" + Path.GetFileName(TmpSrcFile) + "'..." + vbCrLf);
          default:
            //not supported extension
            TmpTargetFile = "";
        }
        if (TmpTargetFile != "") {
          if (FTargetRoot != "") {
            //set manual destination path
            TmpTargetFile = Path.Combine(FTargetRoot, Path.GetFileName(TmpTargetFile));
          }
          if (TmpTargetFile == TmpSrcFile) {
            //destination equals source, add ".converted" to filename
            TmpTargetFile = Path.ChangeExtension(TmpSrcFile, "converted" + Path.GetExtension(TmpSrcFile));
          }
          if (!TmpConv == null) {
            //convert CodeFile
            TmpConv.ConvertFile(TmpSrcFile, TmpTargetFile, true, true);
          } else if (!TmpProjConv == null) {
            //convert VSProject
            TmpProjConv.ConvertProject(TmpSrcFile, TmpTargetFile, true, true);
          } else {
            //convert ASPXFile
            TmpAspxConv.ConvertFile(TmpSrcFile, TmpTargetFile, true);
          }
        }
        //wait for all events
        System.Windows.Forms.Application.DoEvents();
      }
      //conversion finished
      FTargetRoot = "";
      FProcessing = false;
      if (TmpConvVBCS.TotalFilesCount > 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Summary for Code Files: VB.NET -> C#" + vbCrLf);
        OutputMessage(TmpConvVBCS.SummaryText);
        TmpErrCount += TmpConvVBCS.FailedFilesCount;
      }
      if (TmpConvCSVB.TotalFilesCount > 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Summary for Code Files: C# -> VB.NET" + vbCrLf);
        OutputMessage(TmpConvCSVB.SummaryText);
        TmpErrCount += TmpConvCSVB.FailedFilesCount;
      }
      if (TmpProjConvVBCS.TotalProjectsCount > 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Summary for VS Projects: VB.NET -> C#" + vbCrLf);
        OutputMessage(TmpProjConvVBCS.SummaryText);
        TmpErrCount += TmpProjConvVBCS.FailedCodeFilesCount;
      }
      if (TmpProjConvCSVB.TotalProjectsCount > 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Summary for VS Projects: C# -> VB.NET" + vbCrLf);
        OutputMessage(TmpProjConvCSVB.SummaryText);
        TmpErrCount += TmpProjConvCSVB.FailedCodeFilesCount;
      }
      if (TmpAspxConv.TotalFilesCount > 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Summary for ASP.NET Files" + vbCrLf);
        OutputMessage(TmpAspxConv.SummaryText);
        TmpErrCount += TmpAspxConv.FailedFilesCount;
      }
      if (TmpErrCount == 0) {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("All Conversions Successfull" + vbCrLf);
        if (SettingsManager.AutoCloseStatusDialogs) {
          System.Windows.Forms.Application.DoEvents();
          //wait 2 seconds
          System.Threading.Thread.Sleep(2000);
          System.Environment.Exit(0);
        }
      } else {
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("--------------------------------------" + vbCrLf);
        OutputMessage("Conversionerror in " + TmpErrCount.ToString + " files" + vbCrLf);
        BtnRestart.Visible = true;
      }
      BtnCancel.Text = "Close";
      this.AcceptButton = BtnCancel;
      BtnCancel.Focus();
    }

    //PRIVATE
    private void OutputMessage(string textLine)
    {
      TxtStatus.AppendText(textLine);
      TxtStatus.SelectionStart = TxtStatus.Text.Length;
      TxtStatus.ScrollToCaret();
      //wait for user mouse-events
      System.Windows.Forms.Application.DoEvents();
    }

    private void OnRestartConversion()
    {
      if (FFileListHistory.Count > 0) {
        foreach (string s in FFileListHistory) {
          FFileList.Enqueue(s);
        }
        FTargetRoot = FTargetHistory;
        //restart the conversion
        FProcessing = true;
        BtnCancel.Text = "Cancel";
        this.AcceptButton = null;
        StartConversion();
      }
    }

#region GUI Events

    private void Converter_AfterFileProcessed(object sender, ProcessedFileEventArgs e)
    {
      try {
        OutputMessage(e.ToString(Directory.GetParent(e.InputFile).FullName, Directory.GetParent(e.OutputFile).FullName) + vbCrLf);
      } catch (Exception ex) {
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnCancel_Click(System.Object sender, System.EventArgs e)
    {
      if (FProcessing) {
        FProcessing = false;
      } else {
        System.Environment.Exit(0);
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
ChkAutoClose_CheckedChanged(System.Object sender, System.EventArgs e)
    {
      SettingsManager.AutoCloseStatusDialogs = ChkAutoClose.Checked;
    }

    private void  // ERROR: Handles clauses are not supported in C#
FrmStatus_Load(object sender, System.EventArgs e)
    {
      ChkAutoClose.Checked = SettingsManager.AutoCloseStatusDialogs;
    }

    private void  // ERROR: Handles clauses are not supported in C#
FrmStatus_FormClosed(object sender, System.Windows.Forms.FormClosedEventArgs e)
    {
      System.Environment.Exit(0);
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnRestart_Click(System.Object sender, System.EventArgs e)
    {
      BtnRestart.Visible = false;
      this.Refresh();
      OnRestartConversion();
    }

#endregion

  }
}

