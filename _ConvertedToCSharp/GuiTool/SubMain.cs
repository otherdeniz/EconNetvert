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
using System.Threading;
namespace Econ.Netvert.Gui
{
  class ModuleMain
  {
    //ENTRY POINT
    [STAThread()]
    void Main(string[] argumentList)
    {
      FrmMain TmpFrm;

      System.Windows.Forms.Application.EnableVisualStyles();
      //for each p as  system.Diagnostics.Process.GetCurrentProcess.ProcessName
      if (argumentList.Length == 0) {
        //no arguments, show FrmMain
        Application.Run(new FrmMain());
      } else {
        //arguments are passed
        if (argumentList(0) == "/?") {
          //show FrmAbout
          Application.Run(new FrmAbout());
        } else {
          //check if first argument is a file
          if (File.Exists(argumentList(0))) {
            if ((argumentList.Length > 1) && (argumentList(1).ToLower == "/t")) {
              //convert shell-command
              ShellCommandConvert(argumentList(0), true);
            } else if ((argumentList.Length > 1) && (argumentList(1).ToLower == "/c")) {
              //convert-to shell-command
              ShellCommandConvert(argumentList(0), false);
            } else {
              //show gui
              if (argumentList(0).EndsWith(".vb")) {
                //open the .vb-file
                TmpFrm = new FrmMain();
                TmpFrm.TabMain.SelectedIndex = 0;
                 // ERROR: Not supported in C#: WithStatement

                Application.Run(TmpFrm);
              } else if (argumentList(0).EndsWith(".cs")) {
                //open the .cs-file
                TmpFrm = new FrmMain();
                TmpFrm.TabMain.SelectedIndex = 1;
                 // ERROR: Not supported in C#: WithStatement

                Application.Run(TmpFrm);
              } else {
                MsgBox("Not supported codefile '" + argumentList(0) + "'", MsgBoxStyle.Exclamation);
              }
            }

          } else {
            MsgBox("Argument '" + argumentList(0) + "' is not an existing file.", MsgBoxStyle.Exclamation);
          }
        }
      }
    }

    private void ShellCommandConvert(string srcFile, bool convertTo)
    {
      //Dim TmpInst As ShellConverterInstance
      //Dim TmpT As Thread
      FrmStatus TmpFrm;
      string TmpPrefix = "";

      //check for previous instance
      if (SingleInstance.IsFirstInstance) {
        //first instance
        TmpFrm = new FrmStatus();
        SingleInstance.SetMainForm(TmpFrm);
        TmpFrm.ConvertFile(srcFile);
        TmpFrm.Show();
        if (convertTo) {
          if (!TmpFrm.SetDestination(Left(srcFile, srcFile.Length - Path.GetFileName(srcFile).Length - 1))) {
            //cancel
            return;
          }
        }
        TmpFrm.StartConversion();
        //TmpInst = New ShellConverterInstance(srcFile, convertTo)
        //TmpT = New Thread(AddressOf TmpInst.StartConverterThread)
        //TmpT.Start()
        Application.Run();
      } else {
        //previous instance exists
        if (convertTo)
          TmpPrefix = "?";
        SingleInstance.NotifyPreviousWindow(TmpPrefix + srcFile);
      }
    }

    //Private Class ShellConverterInstance

    //  'DELCARATIONS
    //  Private FSrcFile As String
    //  Private FConvertTo As Boolean

    //  'CONSTRUCTOR
    //  Public Sub New(ByVal srcFile As String, ByVal convertTo As Boolean)
    //    FSrcFile = srcFile
    //    FConvertTo = convertTo
    //  End Sub

    //  <STAThread()> _
    //  Public Sub StartConverterThread()
    //  End Sub

    //End Class

  }
}

