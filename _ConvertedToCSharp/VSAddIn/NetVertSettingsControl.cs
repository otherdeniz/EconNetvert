using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
namespace Econ.NetVert.VSAddIn
{
  public partial class NetVertSettingsControl
  {
    //DECLARATIONS
    private EnvDTE80.DTE2 FEnvDte;
    private List<NetVertVsProject> FProjects = new List<NetVertVsProject>();
    private NetVertVsProject FCurrentProject;
    private bool FDoEvents = true;

    //PUBLIC
    public void InitDTE(EnvDTE80.DTE2 dte)
    {
      NetVertVsProject TmpP;

      FEnvDte = dte;
      if ((!dte.Solution == null) && dte.Solution.IsOpen) {
        foreach (EnvDTE.Project proj in dte.Solution.Projects) {
          TmpP = new NetVertVsProject(proj);
          if (TmpP.Language != "") {
            CmbProject.Items.Add(proj.Name);
            FProjects.Add(TmpP);
          }
        }
        if (FProjects.Count > 0) {
          CmbProject.SelectedIndex = 0;
          ChkEnabled.Enabled = true;
        }
      }
    }

    //PRIVATE
    private void OpenProject(NetVertVsProject proj)
    {
      FCurrentProject = proj;
      FDoEvents = false;
      //Enabled
      ChkEnabled.Checked = FCurrentProject.Enabled;
      //Path
      TxtPath.Text = FCurrentProject.Path;
      //Fix Namespace
      ChkFixNs.Checked = FCurrentProject.FixNamespaceImport;
      //Execute
      CmbExecute.SelectedIndex = FCurrentProject.ExecuteMethod;
      //Lang
      switch (FCurrentProject.Language) {
        case "VB":
          TxtLang.Text = "Visual Basic .NET -> C#";
        case "CS":
          TxtLang.Text = "C# -> Visual Basic .NET";
      }
      FDoEvents = true;
    }

    private void SaveValues()
    {
      FCurrentProject.Enabled = ChkEnabled.Checked;
      FCurrentProject.Path = TxtPath.Text;
      FCurrentProject.FixNamespaceImport = ChkFixNs.Checked;
      FCurrentProject.ExecuteMethod = CmbExecute.SelectedIndex;
    }

#region GUI Events

    private void  // ERROR: Handles clauses are not supported in C#
CmbProject_SelectedIndexChanged(System.Object sender, System.EventArgs e)
    {
      if (CmbProject.SelectedIndex > -1) {
        OpenProject(FProjects(CmbProject.SelectedIndex));
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
ChkEnabled_CheckedChanged(object sender, System.EventArgs e)
    {
      PnlConversion.Enabled = ChkEnabled.Checked;
      if (FDoEvents)
        SaveValues();
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtPath_TextChanged(System.Object sender, System.EventArgs e)
    {
      if (FDoEvents)
        SaveValues();
    }

    private void  // ERROR: Handles clauses are not supported in C#
CmbExecute_SelectedIndexChanged(System.Object sender, System.EventArgs e)
    {
      if (FDoEvents)
        SaveValues();
    }

    private void  // ERROR: Handles clauses are not supported in C#
ChkFixNs_CheckedChanged(System.Object sender, System.EventArgs e)
    {
      if (FDoEvents)
        SaveValues();
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnBrowse_Click(System.Object sender, System.EventArgs e)
    {
      if (FolderBrowser.ShowDialog() == DialogResult.OK) {
        TxtPath.Text = FolderBrowser.SelectedPath;
      }
    }

#endregion

  }
}

