Imports System.Collections.Generic

Public Class NetVertSettingsControl

  'DECLARATIONS
  Private FEnvDte As EnvDTE80.DTE2
  Private FProjects As List(Of NetVertVsProject) = New List(Of NetVertVsProject)
  Private FCurrentProject As NetVertVsProject
  Private FDoEvents As Boolean = True

  'PUBLIC
  Public Sub InitDTE(ByVal dte As EnvDTE80.DTE2)
    Dim TmpP As NetVertVsProject

    FEnvDte = dte
    If (Not dte.Solution Is Nothing) AndAlso _
       dte.Solution.IsOpen Then
      For Each proj As EnvDTE.Project In dte.Solution.Projects
        TmpP = New NetVertVsProject(proj)
        If TmpP.Language <> "" Then
          CmbProject.Items.Add(proj.Name)
          FProjects.Add(TmpP)
        End If
      Next
      If FProjects.Count > 0 Then
        CmbProject.SelectedIndex = 0
        ChkEnabled.Enabled = True
      End If
    End If
  End Sub

  'PRIVATE
  Private Sub OpenProject(ByVal proj As NetVertVsProject)
    FCurrentProject = proj
    FDoEvents = False
    'Enabled
    ChkEnabled.Checked = FCurrentProject.Enabled
    'Path
    TxtPath.Text = FCurrentProject.Path
    'Fix Namespace
    ChkFixNs.Checked = FCurrentProject.FixNamespaceImport
    'Execute
    CmbExecute.SelectedIndex = FCurrentProject.ExecuteMethod
    'Lang
    Select Case FCurrentProject.Language
      Case "VB"
        TxtLang.Text = "Visual Basic .NET -> C#"
      Case "CS"
        TxtLang.Text = "C# -> Visual Basic .NET"
    End Select
    FDoEvents = True
  End Sub

  Private Sub SaveValues()
    FCurrentProject.Enabled = ChkEnabled.Checked
    FCurrentProject.Path = TxtPath.Text
    FCurrentProject.FixNamespaceImport = ChkFixNs.Checked
    FCurrentProject.ExecuteMethod = CmbExecute.SelectedIndex
  End Sub

#Region "GUI Events"

  Private Sub CmbProject_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CmbProject.SelectedIndexChanged
    If CmbProject.SelectedIndex > -1 Then
      OpenProject(FProjects(CmbProject.SelectedIndex))
    End If
  End Sub

  Private Sub ChkEnabled_CheckedChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles ChkEnabled.CheckedChanged
    PnlConversion.Enabled = ChkEnabled.Checked
    If FDoEvents Then SaveValues()
  End Sub

  Private Sub TxtPath_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TxtPath.TextChanged
    If FDoEvents Then SaveValues()
  End Sub

  Private Sub CmbExecute_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CmbExecute.SelectedIndexChanged
    If FDoEvents Then SaveValues()
  End Sub

  Private Sub ChkFixNs_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ChkFixNs.CheckedChanged
    If FDoEvents Then SaveValues()
  End Sub

  Private Sub BtnBrowse_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowse.Click
    If FolderBrowser.ShowDialog() = DialogResult.OK Then
      TxtPath.Text = FolderBrowser.SelectedPath
    End If
  End Sub

#End Region

End Class
