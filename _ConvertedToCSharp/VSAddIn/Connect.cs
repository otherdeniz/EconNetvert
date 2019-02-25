using Microsoft.VisualBasic;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
using System;
using System.IO;
using System.Reflection;
using System.Collections.Generic;
using Microsoft.VisualStudio.CommandBars;
using Extensibility;
using EnvDTE;
using EnvDTE80;
namespace Econ.NetVert.VSAddIn
{
  public class Connect : IDTExtensibility2, IDTCommandTarget
  {
    //CONST
    //Private Const cWnd1Guid As String = "{7B0FCE98-61D7-4C4C-B3A3-863C47F96404}"
    //Private Const cWnd1Class As String = "Econ.NetVert.VSAddIn.NetVertSettingsControl"
    //Private Const cWnd1Caption As String = "Econ NetVert Settings"
    //DECLARATIONS
    private DTE2 _applicationObject;
    private AddIn _addInInstance;
    private OutputWindowPane FOutputPane;
    private VSProjectFileConverter FConverterVBCS;
    private VSProjectFileConverter FConverterCSVB;
    private BuildEvents bldEvents;
    private SolutionEvents solEvents;
    //Private _winSettings As Window
    //Private _controlSettings As NetVertSettingsControl

    //CONSTRUCTOR
    ///<summary>Implements the constructor for the Add-in object. Place your initialization code within this method.</summary>
    public Connect()
    {
    }

    //PUBLIC
#region INTERFACE: IDTExtensibility2

    ///<summary>Implements the OnConnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being loaded.</summary>
    ///<param name='application'>Root object of the host application.</param>
    ///<param name='connectMode'>Describes how the Add-in is being loaded.</param>
    ///<param name='addInInst'>Object representing this Add-in.</param>
    ///<remarks></remarks>
    public void IDTExtensibility2.OnConnection(object application, ext_ConnectMode connectMode, object addInInst, ref Array custom)
    {
      _applicationObject = (DTE2)application;
      _addInInstance = (AddIn)addInInst;
      if (FOutputPane == null) {
        //Remove old Commands
        RemoveAddinCommands();
        //create new commands
        CreateAddinCommands();
        //create Output-Pane
        CreateOutputPane();
      }
      //subscribe Solution Events
      bldEvents = (EnvDTE.BuildEvents)_applicationObject.Events.BuildEvents;
      solEvents = (EnvDTE.SolutionEvents)_applicationObject.Events.SolutionEvents;
      //AddHandler _applicationObject.Events.BuildEvents.OnBuildDone, AddressOf EnvDTE_OnBuildDone
      //AddHandler _applicationObject.Events.DocumentEvents.DocumentSaved, AddressOf EnvDTE_DocumentSaved
    }

    ///<summary>Implements the OnDisconnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being unloaded.</summary>
    ///<param name='disconnectMode'>Describes how the Add-in is being unloaded.</param>
    ///<param name='custom'>Array of parameters that are host application specific.</param>
    ///<remarks></remarks>
    public void IDTExtensibility2.OnDisconnection(ext_DisconnectMode disconnectMode, ref Array custom)
    {
      //Remove old Commands
      RemoveAddinCommands();
    }

    ///<summary>Implements the OnAddInsUpdate method of the IDTExtensibility2 interface. Receives notification that the collection of Add-ins has changed.</summary>
    ///<param name='custom'>Array of parameters that are host application specific.</param>
    ///<remarks></remarks>
    public void IDTExtensibility2.OnAddInsUpdate(ref Array custom)
    {
    }

    ///<summary>Implements the OnStartupComplete method of the IDTExtensibility2 interface. Receives notification that the host application has completed loading.</summary>
    ///<param name='custom'>Array of parameters that are host application specific.</param>
    ///<remarks></remarks>
    public void IDTExtensibility2.OnStartupComplete(ref Array custom)
    {
    }

    ///<summary>Implements the OnBeginShutdown method of the IDTExtensibility2 interface. Receives notification that the host application is being unloaded.</summary>
    ///<param name='custom'>Array of parameters that are host application specific.</param>
    ///<remarks></remarks>
    public void IDTExtensibility2.OnBeginShutdown(ref Array custom)
    {
    }

#endregion

#region INTERFACE: IDTCommandTarget

    ///<summary>Implements the QueryStatus method of the IDTCommandTarget interface. This is called when the command's availability is updated</summary>
    ///<param name='commandName'>The name of the command to determine state for.</param>
    ///<param name='neededText'>Text that is needed for the command.</param>
    ///<param name='status'>The state of the command in the user interface.</param>
    ///<param name='commandText'>Text requested by the neededText parameter.</param>
    ///<remarks></remarks>
    public void IDTCommandTarget.QueryStatus(string commandName, vsCommandStatusTextWanted neededText, ref vsCommandStatus status, ref object commandText)
    {
      if (neededText == vsCommandStatusTextWanted.vsCommandStatusTextWantedNone) {
        switch (commandName) {
          case "Econ.NetVert.VSAddIn.Connect.EconNetVertSettings":
            if (_applicationObject.Solution.IsOpen) {
              status = (vsCommandStatus)vsCommandStatus.vsCommandStatusEnabled + vsCommandStatus.vsCommandStatusSupported;
            } else {
              status = vsCommandStatus.vsCommandStatusSupported;
            }
          case "Econ.NetVert.VSAddIn.Connect.EconNetVertConvert":
            if (_applicationObject.Solution.IsOpen) {
              status = (vsCommandStatus)vsCommandStatus.vsCommandStatusEnabled + vsCommandStatus.vsCommandStatusSupported;
            } else {
              status = vsCommandStatus.vsCommandStatusSupported;
            }
          default:
            status = vsCommandStatus.vsCommandStatusUnsupported;
        }
      }
    }

    ///<summary>Implements the Exec method of the IDTCommandTarget interface. This is called when the command is invoked.</summary>
    ///<param name='commandName'>The name of the command to execute.</param>
    ///<param name='executeOption'>Describes how the command should be run.</param>
    ///<param name='varIn'>Parameters passed from the caller to the command handler.</param>
    ///<param name='varOut'>Parameters passed from the command handler to the caller.</param>
    ///<param name='handled'>Informs the caller if the command was handled or not.</param>
    ///<remarks></remarks>
    public void IDTCommandTarget.Exec(string commandName, vsCommandExecOption executeOption, ref object varIn, ref object varOut, ref bool handled)
    {
      handled = false;
      if (executeOption == vsCommandExecOption.vsCommandExecOptionDoDefault) {
        switch (commandName) {
          case "Econ.NetVert.VSAddIn.Connect.EconNetVertSettings":
            ShowSettingsForm();
            handled = true;
          case "Econ.NetVert.VSAddIn.Connect.EconNetVertConvert":
            ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.OnlyManual);
            handled = true;
        }
      }
    }

#endregion

    //PRIVATE
#region EnvDTE Events

    private void  // ERROR: Handles clauses are not supported in C#
bldevents_OnBuildDone(EnvDTE.vsBuildScope Scope, EnvDTE.vsBuildAction Action)
    {
      if ((Scope == vsBuildScope.vsBuildScopeSolution) && ((Action == vsBuildAction.vsBuildActionBuild) || (Action == vsBuildAction.vsBuildActionRebuildAll))) {
        ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSolutionBuild);
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
solEvents_BeforeClosing()
    {
      ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.BaforeSolutionClose);
    }

    //Private Sub EnvDTE_OnBuildDone(ByVal Scope As EnvDTE.vsBuildScope, ByVal Action As EnvDTE.vsBuildAction)
    //  If (Scope = vsBuildScope.vsBuildScopeSolution) AndAlso _
    //     ((Action = vsBuildAction.vsBuildActionBuild) OrElse (Action = vsBuildAction.vsBuildActionRebuildAll)) Then
    //    ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterBuild)
    //  End If
    //End Sub

    //Private Sub EnvDTE_DocumentSaved(ByVal Document As EnvDTE.Document)
    //  If _applicationObject.Solution.Saved Then
    //    ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSave)
    //  End If
    //End Sub

    //Private Sub docEvents_DocumentSaved(ByVal Document As EnvDTE.Document) Handles docEvents.DocumentSaved
    //  If _applicationObject.Solution.Saved Then
    //    'ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSave)
    //  End If
    //  'MsgBox("solution saved: " & Document.FullName & vbCrLf & Document.Kind)
    //End Sub

#endregion

#region Converter Events

    private void NetVertConverter_AfterFileProcessed(object sender, ProcessedFileEventArgs e)
    {
      FOutputPane.OutputString(e.ToString() + vbCrLf);
      Application.DoEvents();
    }

#endregion

#region CommandBar Menu Items

    private void RemoveAddinCommands()
    {
      CommandBarPopup toolsPopup = GetToolsPopup();
      Command command1;
      //remove all commands
      foreach ( command1 in this._applicationObject.Commands) {
        if (command1.Name // ERROR: Unknown binary operator Like
) {
          try {
            command1.Delete();
          } catch (Exception ex) {
          }
        }
      }
      //remove MenuGroup
      foreach (CommandBarControl ctrl in toolsPopup.Controls) {
        if (ctrl.Caption == "Econ NetVert") {
          ctrl.Delete();
          break; // TODO: might not be correct. Was : Exit For
        }
      }
    }

    private void CreateAddinCommands()
    {
      Commands2 commands = (Commands2)_applicationObject.Commands;
      CommandBarPopup TmpMnuGroup = CreateMenuGroup();
      try {
        //Add a command to the Commands collection:
        Command command;
        //COMMAND: Settings
        command = commands.AddNamedCommand2(_addInInstance, "EconNetVertSettings", "Settings...", "Configure Projectsettings for Econ NetVert", true, 3715, null, (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled, vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);
        command.AddControl(TmpMnuGroup.CommandBar, 1);
        //COMMAND: Execute Now
        command = commands.AddNamedCommand2(_addInInstance, "EconNetVertConvert", "Run Conversion", "Run Conversion with Econ NetVert", true, 9255, null, (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled, vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);
        command.AddControl(TmpMnuGroup.CommandBar, 2);
      } catch (System.ArgumentException argumentException) {
        //If we are here, then the exception is probably because a command with that name
        //  already exists. If so there is no need to recreate the command and we can 
        //  safely ignore the exception.
      }
    }

    private CommandBarPopup CreateMenuGroup()
    {
      CommandBarPopup popup1 = this.GetToolsPopup;
      CommandBarControl control1 = null;
      CommandBarControl control2;
      foreach ( control2 in popup1.Controls) {
        if ((object.ReferenceEquals(control2.Caption, "Econ NetVert"))) {
          control1 = control2;
          break; // TODO: might not be correct. Was : Exit For
        }
      }
      if ((!control1 == null)) {
        control1.Visible = true;
        return (CommandBarPopup)control1;
      }
      CommandBarPopup popup2 = (CommandBarPopup)popup1.Controls.Add(MsoControlType.msoControlPopup, 1, null, 1, true);
      popup2.Caption = "Econ NetVert";
      return popup2;
    }

    private CommandBarPopup GetToolsPopup()
    {
      //Dim commandBars As CommandBars = CType(_applicationObject.CommandBars, CommandBars)
      //Dim menuBarCommandBar As CommandBar = commandBars.Item("MenuBar")
      //'Find the Tools command bar on the MenuBar command bar:
      //Dim toolsControl As CommandBarControl = menuBarCommandBar.Controls.Item(toolsMenuName)
      //Dim toolsPopup As CommandBarPopup = CType(toolsControl, CommandBarPopup)
      CommandBar bar1 = ((CommandBars)this._applicationObject.CommandBars).Item("MenuBar");
      string text1 = this.GetLocalizedMenuName("Tools");
      return bar1.Controls.Item(text1) as CommandBarPopup;
    }

    private string GetLocalizedMenuName(string defaultValue)
    {
      string RetMenuName;
      try {
        //If you would like to move the command to a different menu, change the word "Tools" to the 
        //  English version of the menu. This code will take the culture, append on the name of the menu
        //  then add the command to that menu. You can find a list of all the top-level menus in the file
        //  CommandBar.resx.
        System.Resources.ResourceManager resourceManager = new System.Resources.ResourceManager("Econ.NetVert.VSAddIn.CommandBar", System.Reflection.Assembly.GetExecutingAssembly());
        System.Globalization.CultureInfo cultureInfo = new System.Globalization.CultureInfo(_applicationObject.LocaleID);
        RetMenuName = resourceManager.GetString(string.Concat(cultureInfo.TwoLetterISOLanguageName, "Tools"));
      } catch (Exception e) {
        //We tried to find a localized version of the word Tools, but one was not found.
        //  Default to the en-US word, which may work for the current culture.
        RetMenuName = defaultValue;
      }
      return RetMenuName;
    }

#endregion

#region Execute Commands

    private void ShowSettingsForm()
    {
      NetVertSettingsForm TmpFrm = new NetVertSettingsForm();
      TmpFrm.NetVertSettings.InitDTE(_applicationObject);
      TmpFrm.ShowDialog();
    }

    private void ExecuteConversion(NetVertVsProject.NetVertExecutionEnum excuteFilter)
    {
      List<NetVertVsProject> TmpProjs;

      TmpProjs = GetEnabledProjects(excuteFilter);
      if (TmpProjs.Count > 0) {
        FOutputPane.Clear();
        FOutputPane.Activate();
        FOutputPane.OutputString("==== Start Conversion of " + TmpProjs.Count.ToString() + " Projects ====" + vbCrLf);
        //create new converters
        FConverterVBCS = new VSProjectFileConverter(ConverterLanguages.VBNetToCSharp);
        FConverterCSVB = new VSProjectFileConverter(ConverterLanguages.CSharpToVBNet);
        FConverterVBCS.AfterFileProcessed += NetVertConverter_AfterFileProcessed;
        FConverterCSVB.AfterFileProcessed += NetVertConverter_AfterFileProcessed;
        //convert all projects
        foreach (NetVertVsProject nvp in TmpProjs) {
          ConvertProject(nvp);
        }
        //output summary
        if (FConverterVBCS.TotalProjectsCount > 0) {
          FOutputPane.OutputString("--------------------------------------" + vbCrLf);
          FOutputPane.OutputString("Summary VB.NET -> C#" + vbCrLf);
          FOutputPane.OutputString(FConverterVBCS.SummaryText + vbCrLf);
        }
        if (FConverterCSVB.TotalProjectsCount > 0) {
          FOutputPane.OutputString("--------------------------------------" + vbCrLf);
          FOutputPane.OutputString("Summary C# -> VB.NET" + vbCrLf);
          FOutputPane.OutputString(FConverterCSVB.SummaryText + vbCrLf);
        }
        FOutputPane.OutputString("==== Finish ====" + vbCrLf);
      } else {
        if (excuteFilter == NetVertVsProject.NetVertExecutionEnum.OnlyManual) {
          FOutputPane.Clear();
          FOutputPane.Activate();
          FOutputPane.OutputString("==== No Projects are Enabled for Conversion ====" + vbCrLf);
        }
      }
    }

#endregion

#region Misc Helper Functions

    private void ConvertProject(NetVertVsProject project)
    {
      string TmpLang;
      string TmpSrc;
      string TmpTar;

      TmpSrc = project.VSProject.FullName;
      switch (project.Language) {
        case "VB":
          TmpLang = "VB.NET -> C#";
        case "CS":
          TmpLang = "C# -> VB.NET";
        default:
          TmpLang = "(UNSUPPORTED)";
      }
      FOutputPane.OutputString("------ Convert started: Project: " + project.VSProject.Name + ", Language: " + TmpLang + " ------" + vbCrLf);
      FOutputPane.OutputString("Output Folder: " + project.GetDestinationPath + vbCrLf);
      Application.DoEvents();
      switch (project.Language) {
        case "VB":
          TmpTar = Path.Combine(project.GetDestinationPath, Path.ChangeExtension(new FileInfo(TmpSrc).Name, "." + FConverterVBCS.OutputFileExtension));
          FConverterVBCS.ConvertProject(TmpSrc, TmpTar, true, project.FixNamespaceImport);
        case "CS":
          TmpTar = Path.Combine(project.GetDestinationPath, Path.ChangeExtension(new FileInfo(TmpSrc).Name, "." + FConverterCSVB.OutputFileExtension));
          FConverterCSVB.ConvertProject(TmpSrc, TmpTar, true, project.FixNamespaceImport);
      }
      FOutputPane.OutputString(vbCrLf);
    }

    private List<NetVertVsProject> GetEnabledProjects()
    {
      NetVertVsProject TmpP;
      List<NetVertVsProject> RetLst = new List<NetVertVsProject>();

      if (_applicationObject.Solution.IsOpen) {
        foreach (Project proj in _applicationObject.Solution.Projects) {
          TmpP = new NetVertVsProject(proj);
          if (TmpP.Enabled) {
            RetLst.Add(TmpP);
          }
        }
      }
      return RetLst;
    }

    private List<NetVertVsProject> GetEnabledProjects(NetVertVsProject.NetVertExecutionEnum executeFilter)
    {
      List<NetVertVsProject> TmpLst = GetEnabledProjects();
      List<NetVertVsProject> RetLst = new List<NetVertVsProject>();

      foreach (NetVertVsProject nvp in TmpLst) {
        if ((nvp.ExecuteMethod == executeFilter) || (executeFilter == NetVertVsProject.NetVertExecutionEnum.OnlyManual)) {
          RetLst.Add(nvp);
        }
      }
      return RetLst;
    }

    private void CreateOutputPane()
    {
      FOutputPane = _applicationObject.ToolWindows.OutputWindow.OutputWindowPanes.Add("Econ NetVert Conversion");
    }

#endregion

    //Private Sub ShowNetVertSettings()
    //  Dim TmpAss As [Assembly]
    //  Dim TmpWnd As Windows2
    //  Dim TmpCtrlObj As Object = Nothing

    //  If _winSettings Is Nothing Then
    //    TmpAss = Assembly.GetExecutingAssembly
    //    TmpWnd = DirectCast(_applicationObject.Windows, Windows2)
    //    _winSettings = TmpWnd.CreateToolWindow2(_addInInstance, TmpAss.Location, cWnd1Class, cWnd1Caption, cWnd1Guid, TmpCtrlObj)
    //    _controlSettings = DirectCast(TmpCtrlObj, NetVertSettingsControl)
    //    SetToolWindowHeightAndWidth(_winSettings, _controlSettings)
    //  End If
    //  _winSettings.Visible = True
    //  _winSettings.Activate()
    //End Sub

    //Private Sub SetToolWindowHeightAndWidth(ByVal toolWindow As Window, ByVal control As UserControl)
    //  Try
    //    toolWindow.Height = control.MinimumSize.Height
    //    toolWindow.Width = control.MinimumSize.Width
    //  Catch ex As Exception
    //  End Try
    //End Sub

  }
}

