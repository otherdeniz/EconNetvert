Imports System
Imports System.IO
Imports System.Reflection
Imports System.Collections.Generic
Imports Microsoft.VisualStudio.CommandBars
Imports Extensibility
Imports EnvDTE
Imports EnvDTE80

Public Class Connect
  Implements IDTExtensibility2
  Implements IDTCommandTarget

  'CONST
  'Private Const cWnd1Guid As String = "{7B0FCE98-61D7-4C4C-B3A3-863C47F96404}"
  'Private Const cWnd1Class As String = "Econ.NetVert.VSAddIn.NetVertSettingsControl"
  'Private Const cWnd1Caption As String = "Econ NetVert Settings"

  'DECLARATIONS
  Private _applicationObject As DTE2
  Private _addInInstance As AddIn
  Private FOutputPane As OutputWindowPane
  Private FConverterVBCS As VSProjectFileConverter
  Private FConverterCSVB As VSProjectFileConverter
  Private WithEvents bldEvents As BuildEvents
  Private WithEvents solEvents As SolutionEvents
  'Private _winSettings As Window
  'Private _controlSettings As NetVertSettingsControl

  'CONSTRUCTOR
  '''<summary>Implements the constructor for the Add-in object. Place your initialization code within this method.</summary>
  Public Sub New()
  End Sub

  'PUBLIC
#Region "INTERFACE: IDTExtensibility2"

  '''<summary>Implements the OnConnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being loaded.</summary>
  '''<param name='application'>Root object of the host application.</param>
  '''<param name='connectMode'>Describes how the Add-in is being loaded.</param>
  '''<param name='addInInst'>Object representing this Add-in.</param>
  '''<remarks></remarks>
  Public Sub OnConnection(ByVal application As Object, ByVal connectMode As ext_ConnectMode, ByVal addInInst As Object, ByRef custom As Array) Implements IDTExtensibility2.OnConnection
    _applicationObject = CType(application, DTE2)
    _addInInstance = CType(addInInst, AddIn)
    If FOutputPane Is Nothing Then
      'Remove old Commands
      RemoveAddinCommands()
      'create new commands
      CreateAddinCommands()
      'create Output-Pane
      CreateOutputPane()
    End If
    'subscribe Solution Events
    bldEvents = CType(_applicationObject.Events.BuildEvents, EnvDTE.BuildEvents)
    solEvents = CType(_applicationObject.Events.SolutionEvents, EnvDTE.SolutionEvents)
    'AddHandler _applicationObject.Events.BuildEvents.OnBuildDone, AddressOf EnvDTE_OnBuildDone
    'AddHandler _applicationObject.Events.DocumentEvents.DocumentSaved, AddressOf EnvDTE_DocumentSaved
  End Sub

  '''<summary>Implements the OnDisconnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being unloaded.</summary>
  '''<param name='disconnectMode'>Describes how the Add-in is being unloaded.</param>
  '''<param name='custom'>Array of parameters that are host application specific.</param>
  '''<remarks></remarks>
  Public Sub OnDisconnection(ByVal disconnectMode As ext_DisconnectMode, ByRef custom As Array) Implements IDTExtensibility2.OnDisconnection
    'Remove old Commands
    RemoveAddinCommands()
  End Sub

  '''<summary>Implements the OnAddInsUpdate method of the IDTExtensibility2 interface. Receives notification that the collection of Add-ins has changed.</summary>
  '''<param name='custom'>Array of parameters that are host application specific.</param>
  '''<remarks></remarks>
  Public Sub OnAddInsUpdate(ByRef custom As Array) Implements IDTExtensibility2.OnAddInsUpdate
  End Sub

  '''<summary>Implements the OnStartupComplete method of the IDTExtensibility2 interface. Receives notification that the host application has completed loading.</summary>
  '''<param name='custom'>Array of parameters that are host application specific.</param>
  '''<remarks></remarks>
  Public Sub OnStartupComplete(ByRef custom As Array) Implements IDTExtensibility2.OnStartupComplete
  End Sub

  '''<summary>Implements the OnBeginShutdown method of the IDTExtensibility2 interface. Receives notification that the host application is being unloaded.</summary>
  '''<param name='custom'>Array of parameters that are host application specific.</param>
  '''<remarks></remarks>
  Public Sub OnBeginShutdown(ByRef custom As Array) Implements IDTExtensibility2.OnBeginShutdown
  End Sub

#End Region

#Region "INTERFACE: IDTCommandTarget"

  '''<summary>Implements the QueryStatus method of the IDTCommandTarget interface. This is called when the command's availability is updated</summary>
  '''<param name='commandName'>The name of the command to determine state for.</param>
  '''<param name='neededText'>Text that is needed for the command.</param>
  '''<param name='status'>The state of the command in the user interface.</param>
  '''<param name='commandText'>Text requested by the neededText parameter.</param>
  '''<remarks></remarks>
  Public Sub QueryStatus(ByVal commandName As String, ByVal neededText As vsCommandStatusTextWanted, ByRef status As vsCommandStatus, ByRef commandText As Object) Implements IDTCommandTarget.QueryStatus
    If neededText = vsCommandStatusTextWanted.vsCommandStatusTextWantedNone Then
      Select Case commandName
        Case "Econ.NetVert.VSAddIn.Connect.EconNetVertSettings"
          If _applicationObject.Solution.IsOpen Then
            status = CType(vsCommandStatus.vsCommandStatusEnabled + vsCommandStatus.vsCommandStatusSupported, vsCommandStatus)
          Else
            status = vsCommandStatus.vsCommandStatusSupported
          End If
        Case "Econ.NetVert.VSAddIn.Connect.EconNetVertConvert"
          If _applicationObject.Solution.IsOpen Then
            status = CType(vsCommandStatus.vsCommandStatusEnabled + vsCommandStatus.vsCommandStatusSupported, vsCommandStatus)
          Else
            status = vsCommandStatus.vsCommandStatusSupported
          End If
        Case Else
          status = vsCommandStatus.vsCommandStatusUnsupported
      End Select
    End If
  End Sub

  '''<summary>Implements the Exec method of the IDTCommandTarget interface. This is called when the command is invoked.</summary>
  '''<param name='commandName'>The name of the command to execute.</param>
  '''<param name='executeOption'>Describes how the command should be run.</param>
  '''<param name='varIn'>Parameters passed from the caller to the command handler.</param>
  '''<param name='varOut'>Parameters passed from the command handler to the caller.</param>
  '''<param name='handled'>Informs the caller if the command was handled or not.</param>
  '''<remarks></remarks>
  Public Sub Exec(ByVal commandName As String, ByVal executeOption As vsCommandExecOption, ByRef varIn As Object, ByRef varOut As Object, ByRef handled As Boolean) Implements IDTCommandTarget.Exec
    handled = False
    If executeOption = vsCommandExecOption.vsCommandExecOptionDoDefault Then
      Select Case commandName
        Case "Econ.NetVert.VSAddIn.Connect.EconNetVertSettings"
          ShowSettingsForm()
          handled = True
        Case "Econ.NetVert.VSAddIn.Connect.EconNetVertConvert"
          ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.OnlyManual)
          handled = True
      End Select
    End If
  End Sub

#End Region

  'PRIVATE
#Region "EnvDTE Events"

  Private Sub bldevents_OnBuildDone(ByVal Scope As EnvDTE.vsBuildScope, ByVal Action As EnvDTE.vsBuildAction) Handles bldEvents.OnBuildDone
    If (Scope = vsBuildScope.vsBuildScopeSolution) AndAlso _
       ((Action = vsBuildAction.vsBuildActionBuild) OrElse (Action = vsBuildAction.vsBuildActionRebuildAll)) Then
      ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSolutionBuild)
    End If
  End Sub

  Private Sub solEvents_BeforeClosing() Handles solEvents.BeforeClosing
    ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.BaforeSolutionClose)
  End Sub

  'Private Sub EnvDTE_OnBuildDone(ByVal Scope As EnvDTE.vsBuildScope, ByVal Action As EnvDTE.vsBuildAction)
  '  If (Scope = vsBuildScope.vsBuildScopeSolution) AndAlso _
  '     ((Action = vsBuildAction.vsBuildActionBuild) OrElse (Action = vsBuildAction.vsBuildActionRebuildAll)) Then
  '    ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterBuild)
  '  End If
  'End Sub

  'Private Sub EnvDTE_DocumentSaved(ByVal Document As EnvDTE.Document)
  '  If _applicationObject.Solution.Saved Then
  '    ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSave)
  '  End If
  'End Sub

  'Private Sub docEvents_DocumentSaved(ByVal Document As EnvDTE.Document) Handles docEvents.DocumentSaved
  '  If _applicationObject.Solution.Saved Then
  '    'ExecuteConversion(NetVertVsProject.NetVertExecutionEnum.AfterSave)
  '  End If
  '  'MsgBox("solution saved: " & Document.FullName & vbCrLf & Document.Kind)
  'End Sub

#End Region

#Region "Converter Events"

  Private Sub NetVertConverter_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    FOutputPane.OutputString(e.ToString() & vbCrLf)
    Application.DoEvents()
  End Sub

#End Region

#Region "CommandBar Menu Items"

  Private Sub RemoveAddinCommands()
    Dim toolsPopup As CommandBarPopup = GetToolsPopup()
    Dim command1 As Command
    'remove all commands
    For Each command1 In Me._applicationObject.Commands
      If command1.Name Like "Econ.NetVert.VSAddIn.Connect.EconNetVert*" Then
        Try
          command1.Delete()
        Catch ex As Exception
        End Try
      End If
    Next
    'remove MenuGroup
    For Each ctrl As CommandBarControl In toolsPopup.Controls
      If ctrl.Caption = "Econ NetVert" Then
        ctrl.Delete()
        Exit For
      End If
    Next
  End Sub

  Private Sub CreateAddinCommands()
    Dim commands As Commands2 = CType(_applicationObject.Commands, Commands2)
    Dim TmpMnuGroup As CommandBarPopup = CreateMenuGroup()
    Try
      'Add a command to the Commands collection:
      Dim command As Command
      'COMMAND: Settings
      command = commands.AddNamedCommand2(_addInInstance, _
                                          "EconNetVertSettings", _
                                          "Settings...", _
                                          "Configure Projectsettings for Econ NetVert", _
                                          True, 3715, Nothing, CType(vsCommandStatus.vsCommandStatusSupported, Integer) + CType(vsCommandStatus.vsCommandStatusEnabled, Integer), vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton)
      command.AddControl(TmpMnuGroup.CommandBar, 1) 'Find the appropriate command bar on the MenuBar command bar
      'COMMAND: Execute Now
      command = commands.AddNamedCommand2(_addInInstance, _
                                          "EconNetVertConvert", _
                                          "Run Conversion", _
                                          "Run Conversion with Econ NetVert", _
                                          True, 9255, Nothing, CType(vsCommandStatus.vsCommandStatusSupported, Integer) + CType(vsCommandStatus.vsCommandStatusEnabled, Integer), vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton)
      command.AddControl(TmpMnuGroup.CommandBar, 2)
    Catch argumentException As System.ArgumentException
      'If we are here, then the exception is probably because a command with that name
      '  already exists. If so there is no need to recreate the command and we can 
      '  safely ignore the exception.
    End Try
  End Sub

  Private Function CreateMenuGroup() As CommandBarPopup
    Dim popup1 As CommandBarPopup = Me.GetToolsPopup
    Dim control1 As CommandBarControl = Nothing
    Dim control2 As CommandBarControl
    For Each control2 In popup1.Controls
      If (control2.Caption Is "Econ NetVert") Then
        control1 = control2
        Exit For
      End If
    Next
    If (Not control1 Is Nothing) Then
      control1.Visible = True
      Return DirectCast(control1, CommandBarPopup)
    End If
    Dim popup2 As CommandBarPopup = DirectCast(popup1.Controls.Add(MsoControlType.msoControlPopup, 1, Nothing, 1, True), CommandBarPopup)
    popup2.Caption = "Econ NetVert"
    Return popup2
  End Function

  Private Function GetToolsPopup() As CommandBarPopup
    'Dim commandBars As CommandBars = CType(_applicationObject.CommandBars, CommandBars)
    'Dim menuBarCommandBar As CommandBar = commandBars.Item("MenuBar")
    ''Find the Tools command bar on the MenuBar command bar:
    'Dim toolsControl As CommandBarControl = menuBarCommandBar.Controls.Item(toolsMenuName)
    'Dim toolsPopup As CommandBarPopup = CType(toolsControl, CommandBarPopup)
    Dim bar1 As CommandBar = DirectCast(Me._applicationObject.CommandBars, CommandBars).Item("MenuBar")
    Dim text1 As String = Me.GetLocalizedMenuName("Tools")
    Return TryCast(bar1.Controls.Item(text1), CommandBarPopup)
  End Function

  Private Function GetLocalizedMenuName(ByVal defaultValue As String) As String
    Dim RetMenuName As String
    Try
      'If you would like to move the command to a different menu, change the word "Tools" to the 
      '  English version of the menu. This code will take the culture, append on the name of the menu
      '  then add the command to that menu. You can find a list of all the top-level menus in the file
      '  CommandBar.resx.
      Dim resourceManager As System.Resources.ResourceManager = New System.Resources.ResourceManager("Econ.NetVert.VSAddIn.CommandBar", System.Reflection.Assembly.GetExecutingAssembly())
      Dim cultureInfo As System.Globalization.CultureInfo = New System.Globalization.CultureInfo(_applicationObject.LocaleID)
      RetMenuName = resourceManager.GetString(String.Concat(cultureInfo.TwoLetterISOLanguageName, "Tools"))
    Catch e As Exception
      'We tried to find a localized version of the word Tools, but one was not found.
      '  Default to the en-US word, which may work for the current culture.
      RetMenuName = defaultValue
    End Try
    Return RetMenuName
  End Function

#End Region

#Region "Execute Commands"

  Private Sub ShowSettingsForm()
    Dim TmpFrm As New NetVertSettingsForm
    TmpFrm.NetVertSettings.InitDTE(_applicationObject)
    TmpFrm.ShowDialog()
  End Sub

  Private Sub ExecuteConversion(ByVal excuteFilter As NetVertVsProject.NetVertExecutionEnum)
    Dim TmpProjs As List(Of NetVertVsProject)

    TmpProjs = GetEnabledProjects(excuteFilter)
    If TmpProjs.Count > 0 Then
      FOutputPane.Clear()
      FOutputPane.Activate()
      FOutputPane.OutputString("==== Start Conversion of " & TmpProjs.Count.ToString() & " Projects ====" & vbCrLf)
      'create new converters
      FConverterVBCS = New VSProjectFileConverter(ConverterLanguages.VBNetToCSharp)
      FConverterCSVB = New VSProjectFileConverter(ConverterLanguages.CSharpToVBNet)
      AddHandler FConverterVBCS.AfterFileProcessed, AddressOf NetVertConverter_AfterFileProcessed
      AddHandler FConverterCSVB.AfterFileProcessed, AddressOf NetVertConverter_AfterFileProcessed
      'convert all projects
      For Each nvp As NetVertVsProject In TmpProjs
        ConvertProject(nvp)
      Next
      'output summary
      If FConverterVBCS.TotalProjectsCount > 0 Then
        FOutputPane.OutputString("--------------------------------------" & vbCrLf)
        FOutputPane.OutputString("Summary VB.NET -> C#" & vbCrLf)
        FOutputPane.OutputString(FConverterVBCS.SummaryText & vbCrLf)
      End If
      If FConverterCSVB.TotalProjectsCount > 0 Then
        FOutputPane.OutputString("--------------------------------------" & vbCrLf)
        FOutputPane.OutputString("Summary C# -> VB.NET" & vbCrLf)
        FOutputPane.OutputString(FConverterCSVB.SummaryText & vbCrLf)
      End If
      FOutputPane.OutputString("==== Finish ====" & vbCrLf)
    Else
      If excuteFilter = NetVertVsProject.NetVertExecutionEnum.OnlyManual Then
        FOutputPane.Clear()
        FOutputPane.Activate()
        FOutputPane.OutputString("==== No Projects are Enabled for Conversion ====" & vbCrLf)
      End If
    End If
  End Sub

#End Region

#Region "Misc Helper Functions"

  Private Sub ConvertProject(ByVal project As NetVertVsProject)
    Dim TmpLang As String
    Dim TmpSrc As String
    Dim TmpTar As String

    TmpSrc = project.VSProject.FullName
    Select Case project.Language
      Case "VB"
        TmpLang = "VB.NET -> C#"
      Case "CS"
        TmpLang = "C# -> VB.NET"
      Case Else
        TmpLang = "(UNSUPPORTED)"
    End Select
    FOutputPane.OutputString("------ Convert started: Project: " & project.VSProject.Name & ", Language: " & TmpLang & " ------" & vbCrLf)
    FOutputPane.OutputString("Output Folder: " & project.GetDestinationPath & vbCrLf)
    Application.DoEvents()
    Select Case project.Language
      Case "VB"
        TmpTar = Path.Combine(project.GetDestinationPath, Path.ChangeExtension(New FileInfo(TmpSrc).Name, "." & FConverterVBCS.OutputFileExtension))
        FConverterVBCS.ConvertProject(TmpSrc, TmpTar, True, project.FixNamespaceImport)
      Case "CS"
        TmpTar = Path.Combine(project.GetDestinationPath, Path.ChangeExtension(New FileInfo(TmpSrc).Name, "." & FConverterCSVB.OutputFileExtension))
        FConverterCSVB.ConvertProject(TmpSrc, TmpTar, True, project.FixNamespaceImport)
    End Select
    FOutputPane.OutputString(vbCrLf)
  End Sub

  Private Function GetEnabledProjects() As List(Of NetVertVsProject)
    Dim TmpP As NetVertVsProject
    Dim RetLst As New List(Of NetVertVsProject)

    If _applicationObject.Solution.IsOpen Then
      For Each proj As Project In _applicationObject.Solution.Projects
        TmpP = New NetVertVsProject(proj)
        If TmpP.Enabled Then
          RetLst.Add(TmpP)
        End If
      Next
    End If
    Return RetLst
  End Function

  Private Function GetEnabledProjects(ByVal executeFilter As NetVertVsProject.NetVertExecutionEnum) As List(Of NetVertVsProject)
    Dim TmpLst As List(Of NetVertVsProject) = GetEnabledProjects()
    Dim RetLst As New List(Of NetVertVsProject)

    For Each nvp As NetVertVsProject In TmpLst
      If (nvp.ExecuteMethod = executeFilter) OrElse _
         (executeFilter = NetVertVsProject.NetVertExecutionEnum.OnlyManual) Then
        RetLst.Add(nvp)
      End If
    Next
    Return RetLst
  End Function

  Private Sub CreateOutputPane()
    FOutputPane = _applicationObject.ToolWindows.OutputWindow.OutputWindowPanes.Add("Econ NetVert Conversion")
  End Sub

#End Region

  'Private Sub ShowNetVertSettings()
  '  Dim TmpAss As [Assembly]
  '  Dim TmpWnd As Windows2
  '  Dim TmpCtrlObj As Object = Nothing

  '  If _winSettings Is Nothing Then
  '    TmpAss = Assembly.GetExecutingAssembly
  '    TmpWnd = DirectCast(_applicationObject.Windows, Windows2)
  '    _winSettings = TmpWnd.CreateToolWindow2(_addInInstance, TmpAss.Location, cWnd1Class, cWnd1Caption, cWnd1Guid, TmpCtrlObj)
  '    _controlSettings = DirectCast(TmpCtrlObj, NetVertSettingsControl)
  '    SetToolWindowHeightAndWidth(_winSettings, _controlSettings)
  '  End If
  '  _winSettings.Visible = True
  '  _winSettings.Activate()
  'End Sub

  'Private Sub SetToolWindowHeightAndWidth(ByVal toolWindow As Window, ByVal control As UserControl)
  '  Try
  '    toolWindow.Height = control.MinimumSize.Height
  '    toolWindow.Width = control.MinimumSize.Width
  '  Catch ex As Exception
  '  End Try
  'End Sub

End Class
