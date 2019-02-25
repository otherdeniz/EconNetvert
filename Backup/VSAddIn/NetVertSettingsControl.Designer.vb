<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class NetVertSettingsControl
    Inherits System.Windows.Forms.UserControl

    'UserControl overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
    Me.ChkFixNs = New System.Windows.Forms.CheckBox
    Me.TxtPath = New System.Windows.Forms.TextBox
    Me.Label2 = New System.Windows.Forms.Label
    Me.TxtLang = New System.Windows.Forms.TextBox
    Me.Label1 = New System.Windows.Forms.Label
    Me.PnlProject = New System.Windows.Forms.Panel
    Me.ChkEnabled = New System.Windows.Forms.CheckBox
    Me.CmbProject = New System.Windows.Forms.ComboBox
    Me.Label3 = New System.Windows.Forms.Label
    Me.PnlConversion = New System.Windows.Forms.Panel
    Me.BtnBrowse = New System.Windows.Forms.Button
    Me.CmbExecute = New System.Windows.Forms.ComboBox
    Me.Label4 = New System.Windows.Forms.Label
    Me.FolderBrowser = New System.Windows.Forms.FolderBrowserDialog
    Me.PnlProject.SuspendLayout()
    Me.PnlConversion.SuspendLayout()
    Me.SuspendLayout()
    '
    'ChkFixNs
    '
    Me.ChkFixNs.AutoSize = True
    Me.ChkFixNs.Location = New System.Drawing.Point(91, 79)
    Me.ChkFixNs.Name = "ChkFixNs"
    Me.ChkFixNs.Size = New System.Drawing.Size(187, 17)
    Me.ChkFixNs.TabIndex = 4
    Me.ChkFixNs.Text = "Fix Namespace Import Statements"
    Me.ChkFixNs.UseVisualStyleBackColor = True
    '
    'TxtPath
    '
    Me.TxtPath.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtPath.Location = New System.Drawing.Point(92, 0)
    Me.TxtPath.Name = "TxtPath"
    Me.TxtPath.Size = New System.Drawing.Size(280, 20)
    Me.TxtPath.TabIndex = 3
    '
    'Label2
    '
    Me.Label2.AutoSize = True
    Me.Label2.Location = New System.Drawing.Point(3, 3)
    Me.Label2.Name = "Label2"
    Me.Label2.Size = New System.Drawing.Size(85, 13)
    Me.Label2.TabIndex = 2
    Me.Label2.Text = "Destination Path"
    '
    'TxtLang
    '
    Me.TxtLang.Location = New System.Drawing.Point(91, 26)
    Me.TxtLang.Name = "TxtLang"
    Me.TxtLang.ReadOnly = True
    Me.TxtLang.Size = New System.Drawing.Size(143, 20)
    Me.TxtLang.TabIndex = 1
    '
    'Label1
    '
    Me.Label1.AutoSize = True
    Me.Label1.Location = New System.Drawing.Point(2, 29)
    Me.Label1.Name = "Label1"
    Me.Label1.Size = New System.Drawing.Size(55, 13)
    Me.Label1.TabIndex = 0
    Me.Label1.Text = "Language"
    '
    'PnlProject
    '
    Me.PnlProject.Controls.Add(Me.ChkEnabled)
    Me.PnlProject.Controls.Add(Me.CmbProject)
    Me.PnlProject.Controls.Add(Me.Label3)
    Me.PnlProject.Dock = System.Windows.Forms.DockStyle.Top
    Me.PnlProject.Location = New System.Drawing.Point(0, 0)
    Me.PnlProject.Name = "PnlProject"
    Me.PnlProject.Size = New System.Drawing.Size(400, 54)
    Me.PnlProject.TabIndex = 4
    '
    'ChkEnabled
    '
    Me.ChkEnabled.AutoSize = True
    Me.ChkEnabled.Enabled = False
    Me.ChkEnabled.Location = New System.Drawing.Point(92, 30)
    Me.ChkEnabled.Name = "ChkEnabled"
    Me.ChkEnabled.Size = New System.Drawing.Size(143, 17)
    Me.ChkEnabled.TabIndex = 5
    Me.ChkEnabled.Text = "Enable Code Conversion"
    Me.ChkEnabled.UseVisualStyleBackColor = True
    '
    'CmbProject
    '
    Me.CmbProject.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.CmbProject.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbProject.FormattingEnabled = True
    Me.CmbProject.Location = New System.Drawing.Point(92, 3)
    Me.CmbProject.Name = "CmbProject"
    Me.CmbProject.Size = New System.Drawing.Size(305, 21)
    Me.CmbProject.TabIndex = 1
    '
    'Label3
    '
    Me.Label3.AutoSize = True
    Me.Label3.Location = New System.Drawing.Point(3, 6)
    Me.Label3.Name = "Label3"
    Me.Label3.Size = New System.Drawing.Size(40, 13)
    Me.Label3.TabIndex = 0
    Me.Label3.Text = "Project"
    '
    'PnlConversion
    '
    Me.PnlConversion.Controls.Add(Me.BtnBrowse)
    Me.PnlConversion.Controls.Add(Me.ChkFixNs)
    Me.PnlConversion.Controls.Add(Me.CmbExecute)
    Me.PnlConversion.Controls.Add(Me.TxtPath)
    Me.PnlConversion.Controls.Add(Me.Label4)
    Me.PnlConversion.Controls.Add(Me.Label2)
    Me.PnlConversion.Controls.Add(Me.TxtLang)
    Me.PnlConversion.Controls.Add(Me.Label1)
    Me.PnlConversion.Dock = System.Windows.Forms.DockStyle.Fill
    Me.PnlConversion.Enabled = False
    Me.PnlConversion.Location = New System.Drawing.Point(0, 54)
    Me.PnlConversion.Name = "PnlConversion"
    Me.PnlConversion.Size = New System.Drawing.Size(400, 311)
    Me.PnlConversion.TabIndex = 5
    '
    'BtnBrowse
    '
    Me.BtnBrowse.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowse.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowse.Location = New System.Drawing.Point(372, 0)
    Me.BtnBrowse.Name = "BtnBrowse"
    Me.BtnBrowse.Size = New System.Drawing.Size(25, 20)
    Me.BtnBrowse.TabIndex = 5
    Me.BtnBrowse.Text = "..."
    Me.BtnBrowse.UseVisualStyleBackColor = True
    '
    'CmbExecute
    '
    Me.CmbExecute.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbExecute.FormattingEnabled = True
    Me.CmbExecute.Items.AddRange(New Object() {"Only Manual", "Before Close Solution", "After Build Solution"})
    Me.CmbExecute.Location = New System.Drawing.Point(91, 52)
    Me.CmbExecute.Name = "CmbExecute"
    Me.CmbExecute.Size = New System.Drawing.Size(143, 21)
    Me.CmbExecute.TabIndex = 1
    '
    'Label4
    '
    Me.Label4.AutoSize = True
    Me.Label4.Location = New System.Drawing.Point(3, 55)
    Me.Label4.Name = "Label4"
    Me.Label4.Size = New System.Drawing.Size(46, 13)
    Me.Label4.TabIndex = 0
    Me.Label4.Text = "Execute"
    '
    'NetVertSettingsControl
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.Controls.Add(Me.PnlConversion)
    Me.Controls.Add(Me.PnlProject)
    Me.MinimumSize = New System.Drawing.Size(200, 100)
    Me.Name = "NetVertSettingsControl"
    Me.Size = New System.Drawing.Size(400, 365)
    Me.PnlProject.ResumeLayout(False)
    Me.PnlProject.PerformLayout()
    Me.PnlConversion.ResumeLayout(False)
    Me.PnlConversion.PerformLayout()
    Me.ResumeLayout(False)

  End Sub
  Friend WithEvents TxtPath As System.Windows.Forms.TextBox
  Friend WithEvents Label2 As System.Windows.Forms.Label
  Friend WithEvents TxtLang As System.Windows.Forms.TextBox
  Friend WithEvents Label1 As System.Windows.Forms.Label
  Friend WithEvents ChkFixNs As System.Windows.Forms.CheckBox
  Friend WithEvents PnlProject As System.Windows.Forms.Panel
  Friend WithEvents CmbProject As System.Windows.Forms.ComboBox
  Friend WithEvents Label3 As System.Windows.Forms.Label
  Friend WithEvents ChkEnabled As System.Windows.Forms.CheckBox
  Friend WithEvents PnlConversion As System.Windows.Forms.Panel
  Friend WithEvents CmbExecute As System.Windows.Forms.ComboBox
  Friend WithEvents Label4 As System.Windows.Forms.Label
  Friend WithEvents BtnBrowse As System.Windows.Forms.Button
  Friend WithEvents FolderBrowser As System.Windows.Forms.FolderBrowserDialog

End Class
