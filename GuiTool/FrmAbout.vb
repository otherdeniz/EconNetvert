'=================================
'Deniz Esen
'Econ Dimension GmbH
'http://www.econdimension.com
'd.esen@econdimension.com
'=================================
' You are free to use, change and
' redistribute this class or parts
' of it.
' No Support.
'=================================

Imports System.Windows.Forms

Public Class FrmAbout
  Inherits System.Windows.Forms.Form

  'DECLARATIONS
  Private FUpdater As Econ.Updater.ApplicationUpdater

  'CONSTRUCTOR
  Public Sub New()
    MyBase.New()
    InitializeComponent()
    'load settings
    ChkEnableUpdate.Checked = SettingsManager.AutoUpdateOnNewVersion
  End Sub

  'DESTRUCTOR
  Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
    'REMOVE EVENT-HANDLER
    RemoveHandler FUpdater.ApplicationUpdateResponse, AddressOf Updater_ApplicationUpdateResponse
    If disposing Then
      If Not (components Is Nothing) Then
        components.Dispose()
      End If
    End If
    MyBase.Dispose(disposing)
  End Sub

  'PUBLIC
  Public Sub BindToUpdater(ByVal updater As Econ.Updater.ApplicationUpdater)
    FUpdater = updater
    'ADD EVENT-HANDLER
    AddHandler FUpdater.ApplicationUpdateResponse, AddressOf Updater_ApplicationUpdateResponse
    'CURRENT VERSION
    With System.Reflection.Assembly.GetExecutingAssembly
      LblDate.Text = System.IO.File.GetLastWriteTime(.Location).ToShortDateString
      LblVersion.Text = .GetName.Version.ToString
    End With
    'NEWEST VERSION
    RefreshNewestVersion()
  End Sub

  'DESIGNER
#Region " Vom Windows Form Designer generierter Code "

  ' Für Windows Form-Designer erforderlich
  Private components As System.ComponentModel.IContainer

  'HINWEIS: Die folgende Prozedur ist für den Windows Form-Designer erforderlich
  'Sie kann mit dem Windows Form-Designer modifiziert werden.
  'Verwenden Sie nicht den Code-Editor zur Bearbeitung.
  Friend WithEvents BtnClose As System.Windows.Forms.Button
  Friend WithEvents Label1 As System.Windows.Forms.Label
  Friend WithEvents Label2 As System.Windows.Forms.Label
  Friend WithEvents Label3 As System.Windows.Forms.Label
  Friend WithEvents Label4 As System.Windows.Forms.Label
  Friend WithEvents LblVersion As System.Windows.Forms.Label
  Friend WithEvents LblDate As System.Windows.Forms.Label
  Friend WithEvents Label7 As System.Windows.Forms.Label
  Friend WithEvents Label9 As System.Windows.Forms.Label
  Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
  Friend WithEvents LnkMail As System.Windows.Forms.LinkLabel
  Friend WithEvents LnkInternet As System.Windows.Forms.LinkLabel
  Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
  Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
  Friend WithEvents LblNewFeats As System.Windows.Forms.Label
  Friend WithEvents Label13 As System.Windows.Forms.Label
  Friend WithEvents Label6 As System.Windows.Forms.Label
  Friend WithEvents LblNewDate As System.Windows.Forms.Label
  Friend WithEvents Label10 As System.Windows.Forms.Label
  Friend WithEvents LblNewVer As System.Windows.Forms.Label
  Friend WithEvents ChkEnableUpdate As System.Windows.Forms.CheckBox
  Friend WithEvents BtnUpdate As System.Windows.Forms.Button
  <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
    Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FrmAbout))
    Me.BtnClose = New System.Windows.Forms.Button()
    Me.Label1 = New System.Windows.Forms.Label()
    Me.Label2 = New System.Windows.Forms.Label()
    Me.Label3 = New System.Windows.Forms.Label()
    Me.Label4 = New System.Windows.Forms.Label()
    Me.LblVersion = New System.Windows.Forms.Label()
    Me.LblDate = New System.Windows.Forms.Label()
    Me.Label7 = New System.Windows.Forms.Label()
    Me.Label9 = New System.Windows.Forms.Label()
    Me.PictureBox1 = New System.Windows.Forms.PictureBox()
    Me.LnkMail = New System.Windows.Forms.LinkLabel()
    Me.LnkInternet = New System.Windows.Forms.LinkLabel()
    Me.GroupBox1 = New System.Windows.Forms.GroupBox()
    Me.GroupBox2 = New System.Windows.Forms.GroupBox()
    Me.BtnUpdate = New System.Windows.Forms.Button()
    Me.ChkEnableUpdate = New System.Windows.Forms.CheckBox()
    Me.LblNewFeats = New System.Windows.Forms.Label()
    Me.Label13 = New System.Windows.Forms.Label()
    Me.Label6 = New System.Windows.Forms.Label()
    Me.LblNewDate = New System.Windows.Forms.Label()
    Me.Label10 = New System.Windows.Forms.Label()
    Me.LblNewVer = New System.Windows.Forms.Label()
    CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
    Me.GroupBox1.SuspendLayout()
    Me.GroupBox2.SuspendLayout()
    Me.SuspendLayout()
    '
    'BtnClose
    '
    Me.BtnClose.Anchor = System.Windows.Forms.AnchorStyles.Bottom
    Me.BtnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel
    Me.BtnClose.Location = New System.Drawing.Point(192, 264)
    Me.BtnClose.Name = "BtnClose"
    Me.BtnClose.Size = New System.Drawing.Size(80, 23)
    Me.BtnClose.TabIndex = 0
    Me.BtnClose.Text = "Close"
    '
    'Label1
    '
    Me.Label1.Location = New System.Drawing.Point(6, 49)
    Me.Label1.Name = "Label1"
    Me.Label1.Size = New System.Drawing.Size(80, 16)
    Me.Label1.TabIndex = 1
    Me.Label1.Text = "Author:"
    '
    'Label2
    '
    Me.Label2.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.Label2.Location = New System.Drawing.Point(86, 49)
    Me.Label2.Name = "Label2"
    Me.Label2.Size = New System.Drawing.Size(303, 16)
    Me.Label2.TabIndex = 2
    Me.Label2.Text = "Deniz Esen, Basel, Switzerland"
    '
    'Label3
    '
    Me.Label3.Location = New System.Drawing.Point(6, 81)
    Me.Label3.Name = "Label3"
    Me.Label3.Size = New System.Drawing.Size(80, 16)
    Me.Label3.TabIndex = 3
    Me.Label3.Text = "Internet:"
    '
    'Label4
    '
    Me.Label4.Location = New System.Drawing.Point(6, 17)
    Me.Label4.Name = "Label4"
    Me.Label4.Size = New System.Drawing.Size(80, 16)
    Me.Label4.TabIndex = 5
    Me.Label4.Text = "Version:"
    '
    'LblVersion
    '
    Me.LblVersion.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LblVersion.Location = New System.Drawing.Point(86, 17)
    Me.LblVersion.Name = "LblVersion"
    Me.LblVersion.Size = New System.Drawing.Size(303, 16)
    Me.LblVersion.TabIndex = 6
    Me.LblVersion.Text = "-"
    '
    'LblDate
    '
    Me.LblDate.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LblDate.Location = New System.Drawing.Point(86, 33)
    Me.LblDate.Name = "LblDate"
    Me.LblDate.Size = New System.Drawing.Size(303, 16)
    Me.LblDate.TabIndex = 9
    Me.LblDate.Text = "-"
    '
    'Label7
    '
    Me.Label7.Location = New System.Drawing.Point(6, 33)
    Me.Label7.Name = "Label7"
    Me.Label7.Size = New System.Drawing.Size(80, 16)
    Me.Label7.TabIndex = 8
    Me.Label7.Text = "Date:"
    '
    'Label9
    '
    Me.Label9.Location = New System.Drawing.Point(6, 65)
    Me.Label9.Name = "Label9"
    Me.Label9.Size = New System.Drawing.Size(80, 16)
    Me.Label9.TabIndex = 10
    Me.Label9.Text = "E-Mail:"
    '
    'PictureBox1
    '
    Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
    Me.PictureBox1.Location = New System.Drawing.Point(8, 8)
    Me.PictureBox1.Name = "PictureBox1"
    Me.PictureBox1.Size = New System.Drawing.Size(36, 36)
    Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
    Me.PictureBox1.TabIndex = 12
    Me.PictureBox1.TabStop = False
    '
    'LnkMail
    '
    Me.LnkMail.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LnkMail.Location = New System.Drawing.Point(86, 65)
    Me.LnkMail.Name = "LnkMail"
    Me.LnkMail.Size = New System.Drawing.Size(303, 16)
    Me.LnkMail.TabIndex = 13
    Me.LnkMail.TabStop = True
    Me.LnkMail.Text = "esen@other.ch"
    '
    'LnkInternet
    '
    Me.LnkInternet.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LnkInternet.Location = New System.Drawing.Point(86, 81)
    Me.LnkInternet.Name = "LnkInternet"
    Me.LnkInternet.Size = New System.Drawing.Size(303, 16)
    Me.LnkInternet.TabIndex = 13
    Me.LnkInternet.TabStop = True
    Me.LnkInternet.Text = "econnetvert.codeplex.com"
    '
    'GroupBox1
    '
    Me.GroupBox1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.GroupBox1.Controls.Add(Me.LnkMail)
    Me.GroupBox1.Controls.Add(Me.Label4)
    Me.GroupBox1.Controls.Add(Me.Label9)
    Me.GroupBox1.Controls.Add(Me.LnkInternet)
    Me.GroupBox1.Controls.Add(Me.LblDate)
    Me.GroupBox1.Controls.Add(Me.Label7)
    Me.GroupBox1.Controls.Add(Me.Label1)
    Me.GroupBox1.Controls.Add(Me.LblVersion)
    Me.GroupBox1.Controls.Add(Me.Label2)
    Me.GroupBox1.Controls.Add(Me.Label3)
    Me.GroupBox1.Location = New System.Drawing.Point(59, 8)
    Me.GroupBox1.Name = "GroupBox1"
    Me.GroupBox1.Size = New System.Drawing.Size(395, 109)
    Me.GroupBox1.TabIndex = 14
    Me.GroupBox1.TabStop = False
    Me.GroupBox1.Text = "Current Version"
    '
    'GroupBox2
    '
    Me.GroupBox2.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.GroupBox2.Controls.Add(Me.BtnUpdate)
    Me.GroupBox2.Controls.Add(Me.ChkEnableUpdate)
    Me.GroupBox2.Controls.Add(Me.LblNewFeats)
    Me.GroupBox2.Controls.Add(Me.Label13)
    Me.GroupBox2.Controls.Add(Me.Label6)
    Me.GroupBox2.Controls.Add(Me.LblNewDate)
    Me.GroupBox2.Controls.Add(Me.Label10)
    Me.GroupBox2.Controls.Add(Me.LblNewVer)
    Me.GroupBox2.Location = New System.Drawing.Point(59, 124)
    Me.GroupBox2.Name = "GroupBox2"
    Me.GroupBox2.Size = New System.Drawing.Size(395, 134)
    Me.GroupBox2.TabIndex = 15
    Me.GroupBox2.TabStop = False
    Me.GroupBox2.Text = "Newest available Version"
    '
    'BtnUpdate
    '
    Me.BtnUpdate.Location = New System.Drawing.Point(280, 21)
    Me.BtnUpdate.Name = "BtnUpdate"
    Me.BtnUpdate.Size = New System.Drawing.Size(108, 23)
    Me.BtnUpdate.TabIndex = 17
    Me.BtnUpdate.Text = "Update now"
    Me.BtnUpdate.UseVisualStyleBackColor = True
    Me.BtnUpdate.Visible = False
    '
    'ChkEnableUpdate
    '
    Me.ChkEnableUpdate.AutoSize = True
    Me.ChkEnableUpdate.Location = New System.Drawing.Point(9, 20)
    Me.ChkEnableUpdate.Name = "ChkEnableUpdate"
    Me.ChkEnableUpdate.Size = New System.Drawing.Size(223, 17)
    Me.ChkEnableUpdate.TabIndex = 16
    Me.ChkEnableUpdate.Text = "Enable Automatic Update on new Version"
    Me.ChkEnableUpdate.UseVisualStyleBackColor = True
    '
    'LblNewFeats
    '
    Me.LblNewFeats.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LblNewFeats.Location = New System.Drawing.Point(86, 72)
    Me.LblNewFeats.Name = "LblNewFeats"
    Me.LblNewFeats.Size = New System.Drawing.Size(303, 59)
    Me.LblNewFeats.TabIndex = 15
    Me.LblNewFeats.Text = "-"
    '
    'Label13
    '
    Me.Label13.Location = New System.Drawing.Point(6, 72)
    Me.Label13.Name = "Label13"
    Me.Label13.Size = New System.Drawing.Size(80, 16)
    Me.Label13.TabIndex = 14
    Me.Label13.Text = "New Features:"
    '
    'Label6
    '
    Me.Label6.Location = New System.Drawing.Point(6, 40)
    Me.Label6.Name = "Label6"
    Me.Label6.Size = New System.Drawing.Size(80, 16)
    Me.Label6.TabIndex = 10
    Me.Label6.Text = "Version:"
    '
    'LblNewDate
    '
    Me.LblNewDate.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LblNewDate.Location = New System.Drawing.Point(86, 56)
    Me.LblNewDate.Name = "LblNewDate"
    Me.LblNewDate.Size = New System.Drawing.Size(303, 16)
    Me.LblNewDate.TabIndex = 13
    Me.LblNewDate.Text = "-"
    '
    'Label10
    '
    Me.Label10.Location = New System.Drawing.Point(6, 56)
    Me.Label10.Name = "Label10"
    Me.Label10.Size = New System.Drawing.Size(80, 16)
    Me.Label10.TabIndex = 12
    Me.Label10.Text = "Date:"
    '
    'LblNewVer
    '
    Me.LblNewVer.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.LblNewVer.Location = New System.Drawing.Point(86, 40)
    Me.LblNewVer.Name = "LblNewVer"
    Me.LblNewVer.Size = New System.Drawing.Size(303, 16)
    Me.LblNewVer.TabIndex = 11
    Me.LblNewVer.Text = "?"
    '
    'FrmAbout
    '
    Me.AutoScaleBaseSize = New System.Drawing.Size(5, 14)
    Me.ClientSize = New System.Drawing.Size(466, 298)
    Me.Controls.Add(Me.GroupBox2)
    Me.Controls.Add(Me.PictureBox1)
    Me.Controls.Add(Me.BtnClose)
    Me.Controls.Add(Me.GroupBox1)
    Me.Font = New System.Drawing.Font("Tahoma", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
    Me.Name = "FrmAbout"
    Me.ShowInTaskbar = False
    Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
    Me.Text = "About Econ NetVert"
    CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
    Me.GroupBox1.ResumeLayout(False)
    Me.GroupBox2.ResumeLayout(False)
    Me.GroupBox2.PerformLayout()
    Me.ResumeLayout(False)
    Me.PerformLayout()

  End Sub

#End Region

  'PRIVATE
  Private Sub RefreshNewestVersion()
    If FUpdater.NewestVersion <> "0" Then
      LblNewVer.Text = FUpdater.NewestVersion
      LblNewDate.Text = FUpdater.ReleaseDate.ToShortDateString
      If FUpdater.NewFeatures = "" Then
        LblNewFeats.Text = "(not spezified)"
      Else
        LblNewFeats.Text = FUpdater.NewFeatures
      End If
    End If
    BtnUpdate.Visible = FUpdater.NewerVersionAvailable
  End Sub

  Private Sub Updater_ApplicationUpdateResponse(ByVal sender As Object, ByVal e As Econ.Updater.ApplicationUpdateEventArgs)
    RefreshNewestVersion()
  End Sub

  Private Sub BtnClose_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnClose.Click
    Me.Close()
  End Sub

  Private Sub LnkMail_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LnkMail.LinkClicked
    System.Diagnostics.Process.Start("mailto:" & LnkMail.Text)
  End Sub

  Private Sub LnkInternet_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LnkInternet.LinkClicked
    System.Diagnostics.Process.Start("http://" & LnkInternet.Text)
  End Sub

  Private Sub ChkEnableUpdate_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ChkEnableUpdate.CheckedChanged
    SettingsManager.AutoUpdateOnNewVersion = ChkEnableUpdate.Checked
  End Sub

  Private Sub BtnUpdate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnUpdate.Click
    FUpdater.ExecuteUpdateProcess(False)
  End Sub

End Class
