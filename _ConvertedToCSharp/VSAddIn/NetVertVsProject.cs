using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
namespace Econ.NetVert.VSAddIn
{
  public class NetVertVsProject
  {
    //NESTED ENUM
    public enum NetVertExecutionEnum
    {
      OnlyManual = 0,
      BaforeSolutionClose = 1,
      AfterSolutionBuild = 2
    }

    //DELCARATIONS
    private EnvDTE.Project FProject;

    //CONSTRUCTOR
    public NetVertVsProject(EnvDTE.Project project)
    {
      FProject = project;
    }

    //PUBLIC
#region PUBLIC Properties

    public EnvDTE.Project VSProject {
      get { return FProject; }
    }

    public string Language {
      get {
        switch (FProject.Kind.ToUpper()) {
          case "{F184B08F-C81C-45F6-A57F-5ABD9991F28F}":
            return "VB";
          case "{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}":
            return "CS";
          default:
            return "";
        }
      }
    }

    public bool Enabled {
      get {
        if (FProject.Globals.VariableExists("EconNetVertEnabled")) {
          return (FProject.Globals.VariableValue("EconNetVertEnabled") == "1");
        } else {
          return false;
        }
      }
      set {
        FProject.Globals.VariableValue("EconNetVertEnabled") = IIf(value, "1", "0");
        FProject.Globals.VariablePersists("EconNetVertEnabled") = value;
        if (FProject.Globals.VariableExists("EconNetVertPath"))
          FProject.Globals.VariablePersists("EconNetVertPath") = value;
        if (FProject.Globals.VariableExists("EconNetVertFixNamespaceImports"))
          FProject.Globals.VariablePersists("EconNetVertFixNamespaceImports") = value;
        if (FProject.Globals.VariableExists("EconNetVertExecute"))
          FProject.Globals.VariablePersists("EconNetVertExecute") = value;
      }
    }

    public string Path {
      get {
        if (FProject.Globals.VariableExists("EconNetVertPath")) {
          return FProject.Globals.VariableValue("EconNetVertPath");
        } else {
          return "..\\" + FProject.Name + " Converted";
        }
      }
      set {
        FProject.Globals.VariableValue("EconNetVertPath") = value;
        FProject.Globals.VariablePersists("EconNetVertPath") = this.Enabled;
      }
    }

    public bool FixNamespaceImport {
      get {
        if (FProject.Globals.VariableExists("EconNetVertFixNamespaceImports")) {
          return (FProject.Globals.VariableValue("EconNetVertFixNamespaceImports") == "1");
        } else {
          return false;
        }
      }
      set {
        FProject.Globals.VariableValue("EconNetVertFixNamespaceImports") = IIf(value, "1", "0");
        FProject.Globals.VariablePersists("EconNetVertFixNamespaceImports") = this.Enabled;
      }
    }

    public NetVertExecutionEnum ExecuteMethod {
      get {
        if (FProject.Globals.VariableExists("EconNetVertExecute")) {
          switch (FProject.Globals.VariableValue("EconNetVertExecute")) {
            case "1":
              return NetVertExecutionEnum.BaforeSolutionClose;
            case "2":
              return NetVertExecutionEnum.AfterSolutionBuild;
            default:
              return NetVertExecutionEnum.OnlyManual;
          }
        } else {
          return NetVertExecutionEnum.AfterSolutionBuild;
        }
      }
      set {
        FProject.Globals.VariableValue("EconNetVertExecute") = (string)value;
        FProject.Globals.VariablePersists("EconNetVertExecute") = this.Enabled;
      }
    }

#endregion

    public string GetSourcePath()
    {
      string RetP;
      RetP = new System.IO.FileInfo(FProject.FullName).Directory.FullName;
      return RetP;
    }

    public string GetDestinationPath()
    {
      return System.IO.Path.GetFullPath(System.IO.Path.Combine(GetSourcePath, this.Path));
    }

  }
}

