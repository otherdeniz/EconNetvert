Public Class NetVertSettingsForm

  'PRIVATE
  Private Sub NetVertSettingsForm_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
    'Current Version
    With System.Reflection.Assembly.GetExecutingAssembly
      LblVersion.Text = "Econ NetVert v" & .GetName.Version.ToString()
    End With
    'Converter
    Select Case CType(SettingsManager.CurrentRefactoryProvider, Object).GetType.FullName
      Case GetType(RefactoryNet11Provider).FullName
        CmbConverter.SelectedIndex = 0
      Case GetType(RefactoryNet20Provider).FullName
        CmbConverter.SelectedIndex = 1
      Case GetType(RefactoryOnlineProvider).FullName
        CmbConverter.SelectedIndex = 2
    End Select
  End Sub

  Private Sub CmbConverter_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CmbConverter.SelectedIndexChanged
    Select Case CmbConverter.SelectedIndex
      Case 0 'ICSharpCode .NET11
        SettingsManager.CurrentRefactoryProvider = RefactoryNet11Provider.Instance
      Case 1 'ICSharpCode .NET20
        SettingsManager.CurrentRefactoryProvider = RefactoryNet20Provider.Instance
      Case 2 'NRefactory Online
        SettingsManager.CurrentRefactoryProvider = RefactoryOnlineProvider.Instance
    End Select
  End Sub

  Private Sub BtnClose_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnClose.Click
    Me.Close()
  End Sub

End Class