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

Imports System.Text
Imports System.IO

Public Class FrmMain
  Inherits System.Windows.Forms.Form

  'DECLARATIONS
  Private FTextBuilder As StringBuilder
  Private FCurrentState As FormWindowState = FormWindowState.Normal
  Private FCurrentEditor As ICSharpCode.TextEditor.TextEditorControl
  Private FCurrentHelperBox As TextEditorHelperBox

  'CONSTRUCTOR
  Public Sub New()
    MyBase.New()
    InitializeComponent()
    ApplyTooltips()
  End Sub

  'DESIGNER
#Region " Vom Windows Form Designer generierter Code "

  ' Die Form überschreibt den Löschvorgang der Basisklasse, um Komponenten zu bereinigen.
  Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
    If disposing Then
      If Not (components Is Nothing) Then
        components.Dispose()
      End If
    End If
    MyBase.Dispose(disposing)
  End Sub

  ' Für Windows Form-Designer erforderlich
  Private components As System.ComponentModel.IContainer

  'HINWEIS: Die folgende Prozedur ist für den Windows Form-Designer erforderlich
  'Sie kann mit dem Windows Form-Designer modifiziert werden.
  'Verwenden Sie nicht den Code-Editor zur Bearbeitung.
  Friend WithEvents MnuUndo As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem4 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents MnuRedo As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem5 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents MnuSearch As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents MnuGotoLine As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents HelperBoxFromVb As Econ.Netvert.Gui.TextEditorHelperBox
  Friend WithEvents HelperBoxToCs As Econ.Netvert.Gui.TextEditorHelperBox
  Friend WithEvents HelperBoxFromCs As Econ.Netvert.Gui.TextEditorHelperBox
  Friend WithEvents HelperBoxToVb As Econ.Netvert.Gui.TextEditorHelperBox
  Friend WithEvents ApplicationUpdater As Econ.Updater.ApplicationUpdater
  Friend WithEvents CmbRefactoryProvider As System.Windows.Forms.ComboBox
  Friend WithEvents ToolTipSimple As System.Windows.Forms.ToolTip
  Friend WithEvents TxtFromVb As ICSharpCode.TextEditor.TextEditorControl
  Friend WithEvents TxtToCs As ICSharpCode.TextEditor.TextEditorControl
  Friend WithEvents TxtFromCS As ICSharpCode.TextEditor.TextEditorControl
  Friend WithEvents TxtToVb As ICSharpCode.TextEditor.TextEditorControl
  Friend WithEvents MnuEditor As System.Windows.Forms.ContextMenuStrip
  Friend WithEvents MnuCut As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents MnuCopy As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents MnuPaste As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem3 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents MnuSelectAll As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents TabPageAspx As System.Windows.Forms.TabPage
  Friend WithEvents ChkFixNs As System.Windows.Forms.CheckBox
  Friend WithEvents ChkFixNsWeb As System.Windows.Forms.CheckBox
  Friend WithEvents ChkOverwriteWeb As System.Windows.Forms.CheckBox
  Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
  Friend WithEvents TxtOutputWeb As System.Windows.Forms.TextBox
  Friend WithEvents BtnBrowseTargetWeb As System.Windows.Forms.Button
  Friend WithEvents TxtTargetFolderWeb As System.Windows.Forms.TextBox
  Friend WithEvents Label13 As System.Windows.Forms.Label
  Friend WithEvents BtnBrowseSrcWeb As System.Windows.Forms.Button
  Friend WithEvents TxtSrcFolderWeb As System.Windows.Forms.TextBox
  Friend WithEvents Label14 As System.Windows.Forms.Label
  Friend WithEvents CmbLangWeb As System.Windows.Forms.ComboBox
  Friend WithEvents Label15 As System.Windows.Forms.Label
  Friend WithEvents Label16 As System.Windows.Forms.Label
  Friend WithEvents TxtWildcardWeb As System.Windows.Forms.TextBox
  Friend WithEvents ChkRecurseWeb As System.Windows.Forms.CheckBox
  Friend WithEvents BtnConvertWeb As System.Windows.Forms.Button
  Friend WithEvents SplitContainer1 As System.Windows.Forms.SplitContainer
  Friend WithEvents SplitContainer2 As System.Windows.Forms.SplitContainer
  Friend WithEvents ChkFixNsProj As System.Windows.Forms.CheckBox
  Friend WithEvents NetVertTrayIcon As System.Windows.Forms.NotifyIcon
  Friend WithEvents MnuNetVert As System.Windows.Forms.ContextMenuStrip
  Friend WithEvents MnuShowWindow As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem1 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents MnuConvertSrc As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents VBtoCSCodeMenu As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents CStoVBCodeMenu As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents MnuConvertStatements As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents VBtoCSStatementsMenu As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents CStoVBStatementsMenu As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem2 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents MnuExit As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents TabPageVBtoCS As System.Windows.Forms.TabPage
  Friend WithEvents TabPageCStoVB As System.Windows.Forms.TabPage
  Friend WithEvents TabMain As System.Windows.Forms.TabControl
  Friend WithEvents TabPageFiles As System.Windows.Forms.TabPage
  Friend WithEvents Label1 As System.Windows.Forms.Label
  Friend WithEvents CmbLang As System.Windows.Forms.ComboBox
  Friend WithEvents Label2 As System.Windows.Forms.Label
  Friend WithEvents TxtSrcFolder As System.Windows.Forms.TextBox
  Friend WithEvents BtnBrowseSrc As System.Windows.Forms.Button
  Friend WithEvents FolderBrowser As System.Windows.Forms.FolderBrowserDialog
  Friend WithEvents BtnBrowseTarget As System.Windows.Forms.Button
  Friend WithEvents TxtTarget As System.Windows.Forms.TextBox
  Friend WithEvents Label3 As System.Windows.Forms.Label
  Friend WithEvents Label4 As System.Windows.Forms.Label
  Friend WithEvents TxtWildcard As System.Windows.Forms.TextBox
  Friend WithEvents ChkRecurse As System.Windows.Forms.CheckBox
  Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
  Friend WithEvents TxtOutput As System.Windows.Forms.TextBox
  Friend WithEvents BtnConvertFiles As System.Windows.Forms.Button
  Friend WithEvents BtnVbToCs As System.Windows.Forms.Button
  Friend WithEvents BtnVbToCsMethod As System.Windows.Forms.Button
  Friend WithEvents ChkOverwrite As System.Windows.Forms.CheckBox
  Friend WithEvents Panel3 As System.Windows.Forms.Panel
  Friend WithEvents Panel4 As System.Windows.Forms.Panel
  Friend WithEvents Label5 As System.Windows.Forms.Label
  Friend WithEvents BtnVBOpen As System.Windows.Forms.Button
  Friend WithEvents Panel5 As System.Windows.Forms.Panel
  Friend WithEvents Panel6 As System.Windows.Forms.Panel
  Friend WithEvents BtnCSSave As System.Windows.Forms.Button
  Friend WithEvents Label6 As System.Windows.Forms.Label
  Friend WithEvents BtnVBClear As System.Windows.Forms.Button
  Friend WithEvents ToolTipButtons As System.Windows.Forms.ToolTip
  Friend WithEvents BtnCSCopy As System.Windows.Forms.Button
  Friend WithEvents Panel2 As System.Windows.Forms.Panel
  Friend WithEvents Panel7 As System.Windows.Forms.Panel
  Friend WithEvents BtnVBCopy As System.Windows.Forms.Button
  Friend WithEvents BtnVBSave As System.Windows.Forms.Button
  Friend WithEvents Label7 As System.Windows.Forms.Label
  Friend WithEvents Panel8 As System.Windows.Forms.Panel
  Friend WithEvents Panel9 As System.Windows.Forms.Panel
  Friend WithEvents BtnCSClear As System.Windows.Forms.Button
  Friend WithEvents BtnCSOpen As System.Windows.Forms.Button
  Friend WithEvents Label8 As System.Windows.Forms.Label
  Friend WithEvents DlgFileOpen As System.Windows.Forms.OpenFileDialog
  Friend WithEvents DlgFileSave As System.Windows.Forms.SaveFileDialog
  Friend WithEvents BtnAbout As System.Windows.Forms.Button
  Friend WithEvents PnlBottomVC As System.Windows.Forms.Panel
  Friend WithEvents PnlBottomCV As System.Windows.Forms.Panel
  Friend WithEvents BtnCsToVb As System.Windows.Forms.Button
  Friend WithEvents BtnCsToVbMethod As System.Windows.Forms.Button
  Friend WithEvents TabPageProj As System.Windows.Forms.TabPage
  Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
  Friend WithEvents Label9 As System.Windows.Forms.Label
  Friend WithEvents Label10 As System.Windows.Forms.Label
  Friend WithEvents Label11 As System.Windows.Forms.Label
  Friend WithEvents Label12 As System.Windows.Forms.Label
  Friend WithEvents ChkOverwriteProj As System.Windows.Forms.CheckBox
  Friend WithEvents BtnConvertProjects As System.Windows.Forms.Button
  Friend WithEvents BtnBrowseTargetProj As System.Windows.Forms.Button
  Friend WithEvents TxtDestFolderProj As System.Windows.Forms.TextBox
  Friend WithEvents BtnBrowseSrcProj As System.Windows.Forms.Button
  Friend WithEvents TxtSrcFolderProj As System.Windows.Forms.TextBox
  Friend WithEvents CmbLangProj As System.Windows.Forms.ComboBox
  Friend WithEvents TxtWildcardProj As System.Windows.Forms.TextBox
  Friend WithEvents ChkRecurseProj As System.Windows.Forms.CheckBox
  Friend WithEvents TxtOutputProj As System.Windows.Forms.TextBox
  <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
    Me.components = New System.ComponentModel.Container
    Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FrmMain))
    Me.TabMain = New System.Windows.Forms.TabControl
    Me.TabPageVBtoCS = New System.Windows.Forms.TabPage
    Me.SplitContainer1 = New System.Windows.Forms.SplitContainer
    Me.Panel3 = New System.Windows.Forms.Panel
    Me.TxtFromVb = New ICSharpCode.TextEditor.TextEditorControl
    Me.MnuEditor = New System.Windows.Forms.ContextMenuStrip(Me.components)
    Me.MnuSearch = New System.Windows.Forms.ToolStripMenuItem
    Me.MnuGotoLine = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem5 = New System.Windows.Forms.ToolStripSeparator
    Me.MnuUndo = New System.Windows.Forms.ToolStripMenuItem
    Me.MnuRedo = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem4 = New System.Windows.Forms.ToolStripSeparator
    Me.MnuCut = New System.Windows.Forms.ToolStripMenuItem
    Me.MnuCopy = New System.Windows.Forms.ToolStripMenuItem
    Me.MnuPaste = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem3 = New System.Windows.Forms.ToolStripSeparator
    Me.MnuSelectAll = New System.Windows.Forms.ToolStripMenuItem
    Me.HelperBoxFromVb = New Econ.Netvert.Gui.TextEditorHelperBox
    Me.Panel4 = New System.Windows.Forms.Panel
    Me.BtnVBClear = New System.Windows.Forms.Button
    Me.Label5 = New System.Windows.Forms.Label
    Me.BtnVBOpen = New System.Windows.Forms.Button
    Me.Panel5 = New System.Windows.Forms.Panel
    Me.TxtToCs = New ICSharpCode.TextEditor.TextEditorControl
    Me.HelperBoxToCs = New Econ.Netvert.Gui.TextEditorHelperBox
    Me.Panel6 = New System.Windows.Forms.Panel
    Me.BtnCSCopy = New System.Windows.Forms.Button
    Me.BtnCSSave = New System.Windows.Forms.Button
    Me.Label6 = New System.Windows.Forms.Label
    Me.PnlBottomVC = New System.Windows.Forms.Panel
    Me.BtnVbToCs = New System.Windows.Forms.Button
    Me.BtnVbToCsMethod = New System.Windows.Forms.Button
    Me.TabPageCStoVB = New System.Windows.Forms.TabPage
    Me.SplitContainer2 = New System.Windows.Forms.SplitContainer
    Me.Panel8 = New System.Windows.Forms.Panel
    Me.TxtFromCS = New ICSharpCode.TextEditor.TextEditorControl
    Me.HelperBoxFromCs = New Econ.Netvert.Gui.TextEditorHelperBox
    Me.Panel9 = New System.Windows.Forms.Panel
    Me.Label8 = New System.Windows.Forms.Label
    Me.BtnCSClear = New System.Windows.Forms.Button
    Me.BtnCSOpen = New System.Windows.Forms.Button
    Me.Panel2 = New System.Windows.Forms.Panel
    Me.TxtToVb = New ICSharpCode.TextEditor.TextEditorControl
    Me.HelperBoxToVb = New Econ.Netvert.Gui.TextEditorHelperBox
    Me.Panel7 = New System.Windows.Forms.Panel
    Me.BtnVBCopy = New System.Windows.Forms.Button
    Me.BtnVBSave = New System.Windows.Forms.Button
    Me.Label7 = New System.Windows.Forms.Label
    Me.PnlBottomCV = New System.Windows.Forms.Panel
    Me.BtnCsToVbMethod = New System.Windows.Forms.Button
    Me.BtnCsToVb = New System.Windows.Forms.Button
    Me.TabPageFiles = New System.Windows.Forms.TabPage
    Me.ChkFixNs = New System.Windows.Forms.CheckBox
    Me.ChkOverwrite = New System.Windows.Forms.CheckBox
    Me.GroupBox1 = New System.Windows.Forms.GroupBox
    Me.TxtOutput = New System.Windows.Forms.TextBox
    Me.ChkRecurse = New System.Windows.Forms.CheckBox
    Me.BtnBrowseTarget = New System.Windows.Forms.Button
    Me.TxtTarget = New System.Windows.Forms.TextBox
    Me.Label3 = New System.Windows.Forms.Label
    Me.BtnBrowseSrc = New System.Windows.Forms.Button
    Me.TxtSrcFolder = New System.Windows.Forms.TextBox
    Me.Label2 = New System.Windows.Forms.Label
    Me.CmbLang = New System.Windows.Forms.ComboBox
    Me.Label1 = New System.Windows.Forms.Label
    Me.Label4 = New System.Windows.Forms.Label
    Me.TxtWildcard = New System.Windows.Forms.TextBox
    Me.BtnConvertFiles = New System.Windows.Forms.Button
    Me.TabPageAspx = New System.Windows.Forms.TabPage
    Me.ChkFixNsWeb = New System.Windows.Forms.CheckBox
    Me.ChkOverwriteWeb = New System.Windows.Forms.CheckBox
    Me.GroupBox3 = New System.Windows.Forms.GroupBox
    Me.TxtOutputWeb = New System.Windows.Forms.TextBox
    Me.BtnBrowseTargetWeb = New System.Windows.Forms.Button
    Me.TxtTargetFolderWeb = New System.Windows.Forms.TextBox
    Me.Label13 = New System.Windows.Forms.Label
    Me.BtnBrowseSrcWeb = New System.Windows.Forms.Button
    Me.TxtSrcFolderWeb = New System.Windows.Forms.TextBox
    Me.Label14 = New System.Windows.Forms.Label
    Me.CmbLangWeb = New System.Windows.Forms.ComboBox
    Me.Label15 = New System.Windows.Forms.Label
    Me.Label16 = New System.Windows.Forms.Label
    Me.TxtWildcardWeb = New System.Windows.Forms.TextBox
    Me.ChkRecurseWeb = New System.Windows.Forms.CheckBox
    Me.BtnConvertWeb = New System.Windows.Forms.Button
    Me.TabPageProj = New System.Windows.Forms.TabPage
    Me.ChkFixNsProj = New System.Windows.Forms.CheckBox
    Me.ChkOverwriteProj = New System.Windows.Forms.CheckBox
    Me.GroupBox2 = New System.Windows.Forms.GroupBox
    Me.TxtOutputProj = New System.Windows.Forms.TextBox
    Me.BtnBrowseTargetProj = New System.Windows.Forms.Button
    Me.TxtDestFolderProj = New System.Windows.Forms.TextBox
    Me.Label9 = New System.Windows.Forms.Label
    Me.BtnBrowseSrcProj = New System.Windows.Forms.Button
    Me.TxtSrcFolderProj = New System.Windows.Forms.TextBox
    Me.Label10 = New System.Windows.Forms.Label
    Me.CmbLangProj = New System.Windows.Forms.ComboBox
    Me.Label11 = New System.Windows.Forms.Label
    Me.Label12 = New System.Windows.Forms.Label
    Me.TxtWildcardProj = New System.Windows.Forms.TextBox
    Me.ChkRecurseProj = New System.Windows.Forms.CheckBox
    Me.BtnConvertProjects = New System.Windows.Forms.Button
    Me.FolderBrowser = New System.Windows.Forms.FolderBrowserDialog
    Me.ToolTipButtons = New System.Windows.Forms.ToolTip(Me.components)
    Me.CmbRefactoryProvider = New System.Windows.Forms.ComboBox
    Me.DlgFileOpen = New System.Windows.Forms.OpenFileDialog
    Me.DlgFileSave = New System.Windows.Forms.SaveFileDialog
    Me.NetVertTrayIcon = New System.Windows.Forms.NotifyIcon(Me.components)
    Me.MnuNetVert = New System.Windows.Forms.ContextMenuStrip(Me.components)
    Me.MnuShowWindow = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem1 = New System.Windows.Forms.ToolStripSeparator
    Me.MnuConvertSrc = New System.Windows.Forms.ToolStripMenuItem
    Me.VBtoCSCodeMenu = New System.Windows.Forms.ToolStripMenuItem
    Me.CStoVBCodeMenu = New System.Windows.Forms.ToolStripMenuItem
    Me.MnuConvertStatements = New System.Windows.Forms.ToolStripMenuItem
    Me.VBtoCSStatementsMenu = New System.Windows.Forms.ToolStripMenuItem
    Me.CStoVBStatementsMenu = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem2 = New System.Windows.Forms.ToolStripSeparator
    Me.MnuExit = New System.Windows.Forms.ToolStripMenuItem
    Me.BtnAbout = New System.Windows.Forms.Button
    Me.ToolTipSimple = New System.Windows.Forms.ToolTip(Me.components)
    Me.ApplicationUpdater = New Econ.Updater.ApplicationUpdater(Me.components)
    Me.TabMain.SuspendLayout()
    Me.TabPageVBtoCS.SuspendLayout()
    Me.SplitContainer1.Panel1.SuspendLayout()
    Me.SplitContainer1.Panel2.SuspendLayout()
    Me.SplitContainer1.SuspendLayout()
    Me.Panel3.SuspendLayout()
    Me.MnuEditor.SuspendLayout()
    Me.Panel4.SuspendLayout()
    Me.Panel5.SuspendLayout()
    Me.Panel6.SuspendLayout()
    Me.PnlBottomVC.SuspendLayout()
    Me.TabPageCStoVB.SuspendLayout()
    Me.SplitContainer2.Panel1.SuspendLayout()
    Me.SplitContainer2.Panel2.SuspendLayout()
    Me.SplitContainer2.SuspendLayout()
    Me.Panel8.SuspendLayout()
    Me.Panel9.SuspendLayout()
    Me.Panel2.SuspendLayout()
    Me.Panel7.SuspendLayout()
    Me.PnlBottomCV.SuspendLayout()
    Me.TabPageFiles.SuspendLayout()
    Me.GroupBox1.SuspendLayout()
    Me.TabPageAspx.SuspendLayout()
    Me.GroupBox3.SuspendLayout()
    Me.TabPageProj.SuspendLayout()
    Me.GroupBox2.SuspendLayout()
    Me.MnuNetVert.SuspendLayout()
    Me.SuspendLayout()
    '
    'TabMain
    '
    Me.TabMain.Controls.Add(Me.TabPageVBtoCS)
    Me.TabMain.Controls.Add(Me.TabPageCStoVB)
    Me.TabMain.Controls.Add(Me.TabPageFiles)
    Me.TabMain.Controls.Add(Me.TabPageAspx)
    Me.TabMain.Controls.Add(Me.TabPageProj)
    Me.TabMain.Dock = System.Windows.Forms.DockStyle.Fill
    Me.TabMain.Location = New System.Drawing.Point(4, 8)
    Me.TabMain.Name = "TabMain"
    Me.TabMain.SelectedIndex = 0
    Me.TabMain.Size = New System.Drawing.Size(729, 561)
    Me.TabMain.TabIndex = 0
    '
    'TabPageVBtoCS
    '
    Me.TabPageVBtoCS.Controls.Add(Me.SplitContainer1)
    Me.TabPageVBtoCS.Controls.Add(Me.PnlBottomVC)
    Me.TabPageVBtoCS.Location = New System.Drawing.Point(4, 22)
    Me.TabPageVBtoCS.Name = "TabPageVBtoCS"
    Me.TabPageVBtoCS.Padding = New System.Windows.Forms.Padding(8)
    Me.TabPageVBtoCS.Size = New System.Drawing.Size(721, 535)
    Me.TabPageVBtoCS.TabIndex = 0
    Me.TabPageVBtoCS.Text = "VB to C#"
    Me.TabPageVBtoCS.UseVisualStyleBackColor = True
    '
    'SplitContainer1
    '
    Me.SplitContainer1.Dock = System.Windows.Forms.DockStyle.Fill
    Me.SplitContainer1.Location = New System.Drawing.Point(8, 8)
    Me.SplitContainer1.Name = "SplitContainer1"
    '
    'SplitContainer1.Panel1
    '
    Me.SplitContainer1.Panel1.Controls.Add(Me.Panel3)
    '
    'SplitContainer1.Panel2
    '
    Me.SplitContainer1.Panel2.Controls.Add(Me.Panel5)
    Me.SplitContainer1.Size = New System.Drawing.Size(705, 487)
    Me.SplitContainer1.SplitterDistance = 335
    Me.SplitContainer1.SplitterWidth = 6
    Me.SplitContainer1.TabIndex = 11
    '
    'Panel3
    '
    Me.Panel3.Controls.Add(Me.TxtFromVb)
    Me.Panel3.Controls.Add(Me.HelperBoxFromVb)
    Me.Panel3.Controls.Add(Me.Panel4)
    Me.Panel3.Dock = System.Windows.Forms.DockStyle.Fill
    Me.Panel3.Location = New System.Drawing.Point(0, 0)
    Me.Panel3.Name = "Panel3"
    Me.Panel3.Size = New System.Drawing.Size(335, 487)
    Me.Panel3.TabIndex = 0
    '
    'TxtFromVb
    '
    Me.TxtFromVb.AllowDrop = True
    Me.TxtFromVb.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
    Me.TxtFromVb.ContextMenuStrip = Me.MnuEditor
    Me.TxtFromVb.Dock = System.Windows.Forms.DockStyle.Fill
    Me.TxtFromVb.IsIconBarVisible = False
    Me.TxtFromVb.Location = New System.Drawing.Point(0, 24)
    Me.TxtFromVb.Name = "TxtFromVb"
    Me.TxtFromVb.ShowEOLMarkers = True
    Me.TxtFromVb.ShowInvalidLines = False
    Me.TxtFromVb.ShowSpaces = True
    Me.TxtFromVb.ShowTabs = True
    Me.TxtFromVb.ShowVRuler = True
    Me.TxtFromVb.Size = New System.Drawing.Size(335, 442)
    Me.TxtFromVb.TabIndex = 1
    '
    'MnuEditor
    '
    Me.MnuEditor.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.MnuSearch, Me.MnuGotoLine, Me.ToolStripMenuItem5, Me.MnuUndo, Me.MnuRedo, Me.ToolStripMenuItem4, Me.MnuCut, Me.MnuCopy, Me.MnuPaste, Me.ToolStripMenuItem3, Me.MnuSelectAll})
    Me.MnuEditor.Name = "MnuEditor"
    Me.MnuEditor.Size = New System.Drawing.Size(182, 198)
    '
    'MnuSearch
    '
    Me.MnuSearch.Image = CType(resources.GetObject("MnuSearch.Image"), System.Drawing.Image)
    Me.MnuSearch.Name = "MnuSearch"
    Me.MnuSearch.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.F), System.Windows.Forms.Keys)
    Me.MnuSearch.Size = New System.Drawing.Size(181, 22)
    Me.MnuSearch.Text = "Search..."
    '
    'MnuGotoLine
    '
    Me.MnuGotoLine.Name = "MnuGotoLine"
    Me.MnuGotoLine.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.G), System.Windows.Forms.Keys)
    Me.MnuGotoLine.Size = New System.Drawing.Size(181, 22)
    Me.MnuGotoLine.Text = "Goto Line..."
    '
    'ToolStripMenuItem5
    '
    Me.ToolStripMenuItem5.Name = "ToolStripMenuItem5"
    Me.ToolStripMenuItem5.Size = New System.Drawing.Size(178, 6)
    '
    'MnuUndo
    '
    Me.MnuUndo.Image = CType(resources.GetObject("MnuUndo.Image"), System.Drawing.Image)
    Me.MnuUndo.Name = "MnuUndo"
    Me.MnuUndo.Size = New System.Drawing.Size(181, 22)
    Me.MnuUndo.Text = "Undo"
    '
    'MnuRedo
    '
    Me.MnuRedo.Image = CType(resources.GetObject("MnuRedo.Image"), System.Drawing.Image)
    Me.MnuRedo.Name = "MnuRedo"
    Me.MnuRedo.Size = New System.Drawing.Size(181, 22)
    Me.MnuRedo.Text = "Redo"
    '
    'ToolStripMenuItem4
    '
    Me.ToolStripMenuItem4.Name = "ToolStripMenuItem4"
    Me.ToolStripMenuItem4.Size = New System.Drawing.Size(178, 6)
    '
    'MnuCut
    '
    Me.MnuCut.Image = CType(resources.GetObject("MnuCut.Image"), System.Drawing.Image)
    Me.MnuCut.Name = "MnuCut"
    Me.MnuCut.Size = New System.Drawing.Size(181, 22)
    Me.MnuCut.Text = "Cut"
    '
    'MnuCopy
    '
    Me.MnuCopy.Image = CType(resources.GetObject("MnuCopy.Image"), System.Drawing.Image)
    Me.MnuCopy.Name = "MnuCopy"
    Me.MnuCopy.Size = New System.Drawing.Size(181, 22)
    Me.MnuCopy.Text = "Copy"
    '
    'MnuPaste
    '
    Me.MnuPaste.Image = CType(resources.GetObject("MnuPaste.Image"), System.Drawing.Image)
    Me.MnuPaste.Name = "MnuPaste"
    Me.MnuPaste.Size = New System.Drawing.Size(181, 22)
    Me.MnuPaste.Text = "Paste"
    '
    'ToolStripMenuItem3
    '
    Me.ToolStripMenuItem3.Name = "ToolStripMenuItem3"
    Me.ToolStripMenuItem3.Size = New System.Drawing.Size(178, 6)
    '
    'MnuSelectAll
    '
    Me.MnuSelectAll.Image = CType(resources.GetObject("MnuSelectAll.Image"), System.Drawing.Image)
    Me.MnuSelectAll.Name = "MnuSelectAll"
    Me.MnuSelectAll.Size = New System.Drawing.Size(181, 22)
    Me.MnuSelectAll.Text = "Select all"
    '
    'HelperBoxFromVb
    '
    Me.HelperBoxFromVb.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.HelperBoxFromVb.Location = New System.Drawing.Point(0, 466)
    Me.HelperBoxFromVb.Name = "HelperBoxFromVb"
    Me.HelperBoxFromVb.Size = New System.Drawing.Size(335, 21)
    Me.HelperBoxFromVb.TabIndex = 2
    Me.HelperBoxFromVb.TextEditorControl = Me.TxtFromVb
    Me.HelperBoxFromVb.TextEditorHelperBoxType = Econ.Netvert.Gui.TextEditorHelperBoxTypes.SearchBox
    Me.HelperBoxFromVb.Visible = False
    '
    'Panel4
    '
    Me.Panel4.Controls.Add(Me.BtnVBClear)
    Me.Panel4.Controls.Add(Me.Label5)
    Me.Panel4.Controls.Add(Me.BtnVBOpen)
    Me.Panel4.Dock = System.Windows.Forms.DockStyle.Top
    Me.Panel4.Location = New System.Drawing.Point(0, 0)
    Me.Panel4.Name = "Panel4"
    Me.Panel4.Size = New System.Drawing.Size(335, 24)
    Me.Panel4.TabIndex = 0
    '
    'BtnVBClear
    '
    Me.BtnVBClear.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnVBClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnVBClear.Image = CType(resources.GetObject("BtnVBClear.Image"), System.Drawing.Image)
    Me.BtnVBClear.Location = New System.Drawing.Point(24, 0)
    Me.BtnVBClear.Name = "BtnVBClear"
    Me.BtnVBClear.Size = New System.Drawing.Size(24, 24)
    Me.BtnVBClear.TabIndex = 1
    Me.BtnVBClear.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnVBClear, "Clear")
    '
    'Label5
    '
    Me.Label5.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
    Me.Label5.Location = New System.Drawing.Point(56, 0)
    Me.Label5.Name = "Label5"
    Me.Label5.Size = New System.Drawing.Size(232, 24)
    Me.Label5.TabIndex = 2
    Me.Label5.Text = "Input Source: Visual Basic .NET"
    Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
    '
    'BtnVBOpen
    '
    Me.BtnVBOpen.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnVBOpen.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnVBOpen.Image = CType(resources.GetObject("BtnVBOpen.Image"), System.Drawing.Image)
    Me.BtnVBOpen.Location = New System.Drawing.Point(0, 0)
    Me.BtnVBOpen.Name = "BtnVBOpen"
    Me.BtnVBOpen.Size = New System.Drawing.Size(24, 24)
    Me.BtnVBOpen.TabIndex = 0
    Me.BtnVBOpen.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnVBOpen, "Open Visual Basic .NET (*.vb) Source File...")
    '
    'Panel5
    '
    Me.Panel5.Controls.Add(Me.TxtToCs)
    Me.Panel5.Controls.Add(Me.HelperBoxToCs)
    Me.Panel5.Controls.Add(Me.Panel6)
    Me.Panel5.Dock = System.Windows.Forms.DockStyle.Fill
    Me.Panel5.Location = New System.Drawing.Point(0, 0)
    Me.Panel5.Name = "Panel5"
    Me.Panel5.Size = New System.Drawing.Size(364, 487)
    Me.Panel5.TabIndex = 1
    '
    'TxtToCs
    '
    Me.TxtToCs.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
    Me.TxtToCs.ContextMenuStrip = Me.MnuEditor
    Me.TxtToCs.Dock = System.Windows.Forms.DockStyle.Fill
    Me.TxtToCs.IsIconBarVisible = False
    Me.TxtToCs.Location = New System.Drawing.Point(0, 24)
    Me.TxtToCs.Name = "TxtToCs"
    Me.TxtToCs.ShowEOLMarkers = True
    Me.TxtToCs.ShowInvalidLines = False
    Me.TxtToCs.ShowSpaces = True
    Me.TxtToCs.ShowTabs = True
    Me.TxtToCs.ShowVRuler = True
    Me.TxtToCs.Size = New System.Drawing.Size(364, 442)
    Me.TxtToCs.TabIndex = 2
    '
    'HelperBoxToCs
    '
    Me.HelperBoxToCs.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.HelperBoxToCs.Location = New System.Drawing.Point(0, 466)
    Me.HelperBoxToCs.Name = "HelperBoxToCs"
    Me.HelperBoxToCs.Size = New System.Drawing.Size(364, 21)
    Me.HelperBoxToCs.TabIndex = 3
    Me.HelperBoxToCs.TextEditorControl = Me.TxtToCs
    Me.HelperBoxToCs.TextEditorHelperBoxType = Econ.Netvert.Gui.TextEditorHelperBoxTypes.SearchBox
    Me.HelperBoxToCs.Visible = False
    '
    'Panel6
    '
    Me.Panel6.Controls.Add(Me.BtnCSCopy)
    Me.Panel6.Controls.Add(Me.BtnCSSave)
    Me.Panel6.Controls.Add(Me.Label6)
    Me.Panel6.Dock = System.Windows.Forms.DockStyle.Top
    Me.Panel6.Location = New System.Drawing.Point(0, 0)
    Me.Panel6.Name = "Panel6"
    Me.Panel6.Size = New System.Drawing.Size(364, 24)
    Me.Panel6.TabIndex = 0
    '
    'BtnCSCopy
    '
    Me.BtnCSCopy.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnCSCopy.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnCSCopy.Image = CType(resources.GetObject("BtnCSCopy.Image"), System.Drawing.Image)
    Me.BtnCSCopy.Location = New System.Drawing.Point(24, 0)
    Me.BtnCSCopy.Name = "BtnCSCopy"
    Me.BtnCSCopy.Size = New System.Drawing.Size(24, 24)
    Me.BtnCSCopy.TabIndex = 1
    Me.BtnCSCopy.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnCSCopy, "Copy Source to Clipboard")
    '
    'BtnCSSave
    '
    Me.BtnCSSave.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnCSSave.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnCSSave.Image = CType(resources.GetObject("BtnCSSave.Image"), System.Drawing.Image)
    Me.BtnCSSave.Location = New System.Drawing.Point(0, 0)
    Me.BtnCSSave.Name = "BtnCSSave"
    Me.BtnCSSave.Size = New System.Drawing.Size(24, 24)
    Me.BtnCSSave.TabIndex = 0
    Me.BtnCSSave.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnCSSave, "Save to C# (*.cs) Source File...")
    '
    'Label6
    '
    Me.Label6.ForeColor = System.Drawing.Color.Green
    Me.Label6.Location = New System.Drawing.Point(56, 0)
    Me.Label6.Name = "Label6"
    Me.Label6.Size = New System.Drawing.Size(232, 24)
    Me.Label6.TabIndex = 2
    Me.Label6.Text = "Output Source: C#"
    Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
    '
    'PnlBottomVC
    '
    Me.PnlBottomVC.Controls.Add(Me.BtnVbToCs)
    Me.PnlBottomVC.Controls.Add(Me.BtnVbToCsMethod)
    Me.PnlBottomVC.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.PnlBottomVC.Location = New System.Drawing.Point(8, 495)
    Me.PnlBottomVC.Name = "PnlBottomVC"
    Me.PnlBottomVC.Size = New System.Drawing.Size(705, 32)
    Me.PnlBottomVC.TabIndex = 2
    '
    'BtnVbToCs
    '
    Me.BtnVbToCs.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnVbToCs.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnVbToCs.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnVbToCs.Location = New System.Drawing.Point(0, 8)
    Me.BtnVbToCs.Name = "BtnVbToCs"
    Me.BtnVbToCs.Size = New System.Drawing.Size(112, 24)
    Me.BtnVbToCs.TabIndex = 0
    Me.BtnVbToCs.Text = "Convert"
    '
    'BtnVbToCsMethod
    '
    Me.BtnVbToCsMethod.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnVbToCsMethod.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnVbToCsMethod.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnVbToCsMethod.Location = New System.Drawing.Point(128, 8)
    Me.BtnVbToCsMethod.Name = "BtnVbToCsMethod"
    Me.BtnVbToCsMethod.Size = New System.Drawing.Size(184, 24)
    Me.BtnVbToCsMethod.TabIndex = 0
    Me.BtnVbToCsMethod.Text = "Convert statements"
    '
    'TabPageCStoVB
    '
    Me.TabPageCStoVB.Controls.Add(Me.SplitContainer2)
    Me.TabPageCStoVB.Controls.Add(Me.PnlBottomCV)
    Me.TabPageCStoVB.Location = New System.Drawing.Point(4, 22)
    Me.TabPageCStoVB.Name = "TabPageCStoVB"
    Me.TabPageCStoVB.Padding = New System.Windows.Forms.Padding(8)
    Me.TabPageCStoVB.Size = New System.Drawing.Size(721, 535)
    Me.TabPageCStoVB.TabIndex = 1
    Me.TabPageCStoVB.Text = "C# to VB"
    Me.TabPageCStoVB.UseVisualStyleBackColor = True
    '
    'SplitContainer2
    '
    Me.SplitContainer2.Dock = System.Windows.Forms.DockStyle.Fill
    Me.SplitContainer2.Location = New System.Drawing.Point(8, 8)
    Me.SplitContainer2.Name = "SplitContainer2"
    '
    'SplitContainer2.Panel1
    '
    Me.SplitContainer2.Panel1.Controls.Add(Me.Panel8)
    '
    'SplitContainer2.Panel2
    '
    Me.SplitContainer2.Panel2.Controls.Add(Me.Panel2)
    Me.SplitContainer2.Size = New System.Drawing.Size(705, 487)
    Me.SplitContainer2.SplitterDistance = 335
    Me.SplitContainer2.SplitterWidth = 6
    Me.SplitContainer2.TabIndex = 16
    '
    'Panel8
    '
    Me.Panel8.Controls.Add(Me.TxtFromCS)
    Me.Panel8.Controls.Add(Me.HelperBoxFromCs)
    Me.Panel8.Controls.Add(Me.Panel9)
    Me.Panel8.Dock = System.Windows.Forms.DockStyle.Fill
    Me.Panel8.Location = New System.Drawing.Point(0, 0)
    Me.Panel8.Name = "Panel8"
    Me.Panel8.Size = New System.Drawing.Size(335, 487)
    Me.Panel8.TabIndex = 0
    '
    'TxtFromCS
    '
    Me.TxtFromCS.AllowDrop = True
    Me.TxtFromCS.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
    Me.TxtFromCS.ContextMenuStrip = Me.MnuEditor
    Me.TxtFromCS.Dock = System.Windows.Forms.DockStyle.Fill
    Me.TxtFromCS.IsIconBarVisible = False
    Me.TxtFromCS.Location = New System.Drawing.Point(0, 24)
    Me.TxtFromCS.Name = "TxtFromCS"
    Me.TxtFromCS.ShowEOLMarkers = True
    Me.TxtFromCS.ShowInvalidLines = False
    Me.TxtFromCS.ShowSpaces = True
    Me.TxtFromCS.ShowTabs = True
    Me.TxtFromCS.ShowVRuler = True
    Me.TxtFromCS.Size = New System.Drawing.Size(335, 442)
    Me.TxtFromCS.TabIndex = 2
    '
    'HelperBoxFromCs
    '
    Me.HelperBoxFromCs.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.HelperBoxFromCs.Location = New System.Drawing.Point(0, 466)
    Me.HelperBoxFromCs.Name = "HelperBoxFromCs"
    Me.HelperBoxFromCs.Size = New System.Drawing.Size(335, 21)
    Me.HelperBoxFromCs.TabIndex = 4
    Me.HelperBoxFromCs.TextEditorControl = Me.TxtFromCS
    Me.HelperBoxFromCs.TextEditorHelperBoxType = Econ.Netvert.Gui.TextEditorHelperBoxTypes.SearchBox
    Me.HelperBoxFromCs.Visible = False
    '
    'Panel9
    '
    Me.Panel9.Controls.Add(Me.Label8)
    Me.Panel9.Controls.Add(Me.BtnCSClear)
    Me.Panel9.Controls.Add(Me.BtnCSOpen)
    Me.Panel9.Dock = System.Windows.Forms.DockStyle.Top
    Me.Panel9.Location = New System.Drawing.Point(0, 0)
    Me.Panel9.Name = "Panel9"
    Me.Panel9.Size = New System.Drawing.Size(335, 24)
    Me.Panel9.TabIndex = 0
    '
    'Label8
    '
    Me.Label8.ForeColor = System.Drawing.Color.Green
    Me.Label8.Location = New System.Drawing.Point(56, 0)
    Me.Label8.Name = "Label8"
    Me.Label8.Size = New System.Drawing.Size(232, 24)
    Me.Label8.TabIndex = 0
    Me.Label8.Text = "Input Source: C#"
    Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
    '
    'BtnCSClear
    '
    Me.BtnCSClear.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnCSClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnCSClear.Image = CType(resources.GetObject("BtnCSClear.Image"), System.Drawing.Image)
    Me.BtnCSClear.Location = New System.Drawing.Point(24, 0)
    Me.BtnCSClear.Name = "BtnCSClear"
    Me.BtnCSClear.Size = New System.Drawing.Size(24, 24)
    Me.BtnCSClear.TabIndex = 1
    Me.BtnCSClear.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnCSClear, "Clear")
    '
    'BtnCSOpen
    '
    Me.BtnCSOpen.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnCSOpen.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnCSOpen.Image = CType(resources.GetObject("BtnCSOpen.Image"), System.Drawing.Image)
    Me.BtnCSOpen.Location = New System.Drawing.Point(0, 0)
    Me.BtnCSOpen.Name = "BtnCSOpen"
    Me.BtnCSOpen.Size = New System.Drawing.Size(24, 24)
    Me.BtnCSOpen.TabIndex = 0
    Me.BtnCSOpen.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnCSOpen, "Open C# (*.cs) Source File...")
    '
    'Panel2
    '
    Me.Panel2.Controls.Add(Me.TxtToVb)
    Me.Panel2.Controls.Add(Me.HelperBoxToVb)
    Me.Panel2.Controls.Add(Me.Panel7)
    Me.Panel2.Dock = System.Windows.Forms.DockStyle.Fill
    Me.Panel2.Location = New System.Drawing.Point(0, 0)
    Me.Panel2.Name = "Panel2"
    Me.Panel2.Size = New System.Drawing.Size(364, 487)
    Me.Panel2.TabIndex = 1
    '
    'TxtToVb
    '
    Me.TxtToVb.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
    Me.TxtToVb.ContextMenuStrip = Me.MnuEditor
    Me.TxtToVb.Dock = System.Windows.Forms.DockStyle.Fill
    Me.TxtToVb.IsIconBarVisible = False
    Me.TxtToVb.Location = New System.Drawing.Point(0, 24)
    Me.TxtToVb.Name = "TxtToVb"
    Me.TxtToVb.ShowEOLMarkers = True
    Me.TxtToVb.ShowInvalidLines = False
    Me.TxtToVb.ShowSpaces = True
    Me.TxtToVb.ShowTabs = True
    Me.TxtToVb.ShowVRuler = True
    Me.TxtToVb.Size = New System.Drawing.Size(364, 442)
    Me.TxtToVb.TabIndex = 2
    '
    'HelperBoxToVb
    '
    Me.HelperBoxToVb.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.HelperBoxToVb.Location = New System.Drawing.Point(0, 466)
    Me.HelperBoxToVb.Name = "HelperBoxToVb"
    Me.HelperBoxToVb.Size = New System.Drawing.Size(364, 21)
    Me.HelperBoxToVb.TabIndex = 5
    Me.HelperBoxToVb.TextEditorControl = Me.TxtToVb
    Me.HelperBoxToVb.TextEditorHelperBoxType = Econ.Netvert.Gui.TextEditorHelperBoxTypes.SearchBox
    Me.HelperBoxToVb.Visible = False
    '
    'Panel7
    '
    Me.Panel7.Controls.Add(Me.BtnVBCopy)
    Me.Panel7.Controls.Add(Me.BtnVBSave)
    Me.Panel7.Controls.Add(Me.Label7)
    Me.Panel7.Dock = System.Windows.Forms.DockStyle.Top
    Me.Panel7.Location = New System.Drawing.Point(0, 0)
    Me.Panel7.Name = "Panel7"
    Me.Panel7.Size = New System.Drawing.Size(364, 24)
    Me.Panel7.TabIndex = 0
    '
    'BtnVBCopy
    '
    Me.BtnVBCopy.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnVBCopy.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnVBCopy.Image = CType(resources.GetObject("BtnVBCopy.Image"), System.Drawing.Image)
    Me.BtnVBCopy.Location = New System.Drawing.Point(24, 0)
    Me.BtnVBCopy.Name = "BtnVBCopy"
    Me.BtnVBCopy.Size = New System.Drawing.Size(24, 24)
    Me.BtnVBCopy.TabIndex = 1
    Me.BtnVBCopy.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnVBCopy, "Copy Source to Clipboard")
    '
    'BtnVBSave
    '
    Me.BtnVBSave.Dock = System.Windows.Forms.DockStyle.Left
    Me.BtnVBSave.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnVBSave.Image = CType(resources.GetObject("BtnVBSave.Image"), System.Drawing.Image)
    Me.BtnVBSave.Location = New System.Drawing.Point(0, 0)
    Me.BtnVBSave.Name = "BtnVBSave"
    Me.BtnVBSave.Size = New System.Drawing.Size(24, 24)
    Me.BtnVBSave.TabIndex = 0
    Me.BtnVBSave.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnVBSave, "Save to Visual Basic .NET (*.vb) Source File...")
    '
    'Label7
    '
    Me.Label7.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
    Me.Label7.Location = New System.Drawing.Point(56, 0)
    Me.Label7.Name = "Label7"
    Me.Label7.Size = New System.Drawing.Size(232, 24)
    Me.Label7.TabIndex = 0
    Me.Label7.Text = "Output Source: Visual Basic .NET"
    Me.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
    '
    'PnlBottomCV
    '
    Me.PnlBottomCV.Controls.Add(Me.BtnCsToVbMethod)
    Me.PnlBottomCV.Controls.Add(Me.BtnCsToVb)
    Me.PnlBottomCV.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.PnlBottomCV.Location = New System.Drawing.Point(8, 495)
    Me.PnlBottomCV.Name = "PnlBottomCV"
    Me.PnlBottomCV.Size = New System.Drawing.Size(705, 32)
    Me.PnlBottomCV.TabIndex = 15
    '
    'BtnCsToVbMethod
    '
    Me.BtnCsToVbMethod.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnCsToVbMethod.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnCsToVbMethod.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnCsToVbMethod.Location = New System.Drawing.Point(128, 8)
    Me.BtnCsToVbMethod.Name = "BtnCsToVbMethod"
    Me.BtnCsToVbMethod.Size = New System.Drawing.Size(184, 24)
    Me.BtnCsToVbMethod.TabIndex = 1
    Me.BtnCsToVbMethod.Text = "Convert statements"
    '
    'BtnCsToVb
    '
    Me.BtnCsToVb.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnCsToVb.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnCsToVb.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnCsToVb.Location = New System.Drawing.Point(0, 8)
    Me.BtnCsToVb.Name = "BtnCsToVb"
    Me.BtnCsToVb.Size = New System.Drawing.Size(112, 24)
    Me.BtnCsToVb.TabIndex = 0
    Me.BtnCsToVb.Text = "Convert"
    '
    'TabPageFiles
    '
    Me.TabPageFiles.Controls.Add(Me.ChkFixNs)
    Me.TabPageFiles.Controls.Add(Me.ChkOverwrite)
    Me.TabPageFiles.Controls.Add(Me.GroupBox1)
    Me.TabPageFiles.Controls.Add(Me.ChkRecurse)
    Me.TabPageFiles.Controls.Add(Me.BtnBrowseTarget)
    Me.TabPageFiles.Controls.Add(Me.TxtTarget)
    Me.TabPageFiles.Controls.Add(Me.Label3)
    Me.TabPageFiles.Controls.Add(Me.BtnBrowseSrc)
    Me.TabPageFiles.Controls.Add(Me.TxtSrcFolder)
    Me.TabPageFiles.Controls.Add(Me.Label2)
    Me.TabPageFiles.Controls.Add(Me.CmbLang)
    Me.TabPageFiles.Controls.Add(Me.Label1)
    Me.TabPageFiles.Controls.Add(Me.Label4)
    Me.TabPageFiles.Controls.Add(Me.TxtWildcard)
    Me.TabPageFiles.Controls.Add(Me.BtnConvertFiles)
    Me.TabPageFiles.Location = New System.Drawing.Point(4, 22)
    Me.TabPageFiles.Name = "TabPageFiles"
    Me.TabPageFiles.Size = New System.Drawing.Size(721, 535)
    Me.TabPageFiles.TabIndex = 2
    Me.TabPageFiles.Text = "Convert Files"
    Me.TabPageFiles.UseVisualStyleBackColor = True
    '
    'ChkFixNs
    '
    Me.ChkFixNs.Location = New System.Drawing.Point(494, 144)
    Me.ChkFixNs.Name = "ChkFixNs"
    Me.ChkFixNs.Size = New System.Drawing.Size(176, 24)
    Me.ChkFixNs.TabIndex = 8
    Me.ChkFixNs.Text = "Fix namespace imports"
    Me.ToolTipButtons.SetToolTip(Me.ChkFixNs, resources.GetString("ChkFixNs.ToolTip"))
    '
    'ChkOverwrite
    '
    Me.ChkOverwrite.Location = New System.Drawing.Point(312, 144)
    Me.ChkOverwrite.Name = "ChkOverwrite"
    Me.ChkOverwrite.Size = New System.Drawing.Size(176, 24)
    Me.ChkOverwrite.TabIndex = 7
    Me.ChkOverwrite.Text = "Overwrite existing files"
    Me.ToolTipButtons.SetToolTip(Me.ChkOverwrite, "Enable to overwrite existing files in the target directory.")
    '
    'GroupBox1
    '
    Me.GroupBox1.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.GroupBox1.Controls.Add(Me.TxtOutput)
    Me.GroupBox1.Location = New System.Drawing.Point(16, 176)
    Me.GroupBox1.Name = "GroupBox1"
    Me.GroupBox1.Size = New System.Drawing.Size(689, 348)
    Me.GroupBox1.TabIndex = 10
    Me.GroupBox1.TabStop = False
    Me.GroupBox1.Text = "Output"
    '
    'TxtOutput
    '
    Me.TxtOutput.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtOutput.Location = New System.Drawing.Point(16, 25)
    Me.TxtOutput.MaxLength = 10000000
    Me.TxtOutput.Multiline = True
    Me.TxtOutput.Name = "TxtOutput"
    Me.TxtOutput.ReadOnly = True
    Me.TxtOutput.ScrollBars = System.Windows.Forms.ScrollBars.Both
    Me.TxtOutput.Size = New System.Drawing.Size(657, 307)
    Me.TxtOutput.TabIndex = 0
    Me.TxtOutput.WordWrap = False
    '
    'ChkRecurse
    '
    Me.ChkRecurse.Checked = True
    Me.ChkRecurse.CheckState = System.Windows.Forms.CheckState.Checked
    Me.ChkRecurse.Location = New System.Drawing.Point(128, 144)
    Me.ChkRecurse.Name = "ChkRecurse"
    Me.ChkRecurse.Size = New System.Drawing.Size(176, 24)
    Me.ChkRecurse.TabIndex = 6
    Me.ChkRecurse.Text = "Recurse Subdirectories"
    Me.ToolTipButtons.SetToolTip(Me.ChkRecurse, "Enable to convert files, located in subfolders of the source directory. The subfo" & _
            "lders will be created in the target directory if they not exist.")
    '
    'BtnBrowseTarget
    '
    Me.BtnBrowseTarget.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseTarget.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseTarget.Location = New System.Drawing.Point(676, 112)
    Me.BtnBrowseTarget.Name = "BtnBrowseTarget"
    Me.BtnBrowseTarget.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseTarget.TabIndex = 5
    Me.BtnBrowseTarget.Text = "..."
    '
    'TxtTarget
    '
    Me.TxtTarget.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtTarget.Location = New System.Drawing.Point(128, 112)
    Me.TxtTarget.Name = "TxtTarget"
    Me.TxtTarget.Size = New System.Drawing.Size(542, 21)
    Me.TxtTarget.TabIndex = 4
    '
    'Label3
    '
    Me.Label3.Location = New System.Drawing.Point(16, 112)
    Me.Label3.Name = "Label3"
    Me.Label3.Size = New System.Drawing.Size(104, 24)
    Me.Label3.TabIndex = 5
    Me.Label3.Text = "Target Directory:"
    '
    'BtnBrowseSrc
    '
    Me.BtnBrowseSrc.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseSrc.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseSrc.Location = New System.Drawing.Point(676, 80)
    Me.BtnBrowseSrc.Name = "BtnBrowseSrc"
    Me.BtnBrowseSrc.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseSrc.TabIndex = 3
    Me.BtnBrowseSrc.Text = "..."
    '
    'TxtSrcFolder
    '
    Me.TxtSrcFolder.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtSrcFolder.Location = New System.Drawing.Point(128, 80)
    Me.TxtSrcFolder.Name = "TxtSrcFolder"
    Me.TxtSrcFolder.Size = New System.Drawing.Size(542, 21)
    Me.TxtSrcFolder.TabIndex = 2
    '
    'Label2
    '
    Me.Label2.Location = New System.Drawing.Point(16, 80)
    Me.Label2.Name = "Label2"
    Me.Label2.Size = New System.Drawing.Size(104, 24)
    Me.Label2.TabIndex = 2
    Me.Label2.Text = "Source Directory:"
    '
    'CmbLang
    '
    Me.CmbLang.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbLang.Items.AddRange(New Object() {"Visual Basic .NET -> C#", "C# -> Visual Basic .NET"})
    Me.CmbLang.Location = New System.Drawing.Point(128, 16)
    Me.CmbLang.Name = "CmbLang"
    Me.CmbLang.Size = New System.Drawing.Size(176, 21)
    Me.CmbLang.TabIndex = 0
    '
    'Label1
    '
    Me.Label1.Location = New System.Drawing.Point(16, 16)
    Me.Label1.Name = "Label1"
    Me.Label1.Size = New System.Drawing.Size(104, 24)
    Me.Label1.TabIndex = 0
    Me.Label1.Text = "Language:"
    '
    'Label4
    '
    Me.Label4.Location = New System.Drawing.Point(16, 48)
    Me.Label4.Name = "Label4"
    Me.Label4.Size = New System.Drawing.Size(104, 24)
    Me.Label4.TabIndex = 2
    Me.Label4.Text = "Wildcard(s):"
    '
    'TxtWildcard
    '
    Me.TxtWildcard.Location = New System.Drawing.Point(128, 48)
    Me.TxtWildcard.Name = "TxtWildcard"
    Me.TxtWildcard.Size = New System.Drawing.Size(176, 21)
    Me.TxtWildcard.TabIndex = 1
    '
    'BtnConvertFiles
    '
    Me.BtnConvertFiles.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnConvertFiles.Enabled = False
    Me.BtnConvertFiles.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnConvertFiles.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnConvertFiles.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnConvertFiles.Location = New System.Drawing.Point(569, 16)
    Me.BtnConvertFiles.Name = "BtnConvertFiles"
    Me.BtnConvertFiles.Size = New System.Drawing.Size(136, 24)
    Me.BtnConvertFiles.TabIndex = 9
    Me.BtnConvertFiles.Text = "Convert"
    Me.ToolTipButtons.SetToolTip(Me.BtnConvertFiles, "Start Conversion")
    '
    'TabPageAspx
    '
    Me.TabPageAspx.Controls.Add(Me.ChkFixNsWeb)
    Me.TabPageAspx.Controls.Add(Me.ChkOverwriteWeb)
    Me.TabPageAspx.Controls.Add(Me.GroupBox3)
    Me.TabPageAspx.Controls.Add(Me.BtnBrowseTargetWeb)
    Me.TabPageAspx.Controls.Add(Me.TxtTargetFolderWeb)
    Me.TabPageAspx.Controls.Add(Me.Label13)
    Me.TabPageAspx.Controls.Add(Me.BtnBrowseSrcWeb)
    Me.TabPageAspx.Controls.Add(Me.TxtSrcFolderWeb)
    Me.TabPageAspx.Controls.Add(Me.Label14)
    Me.TabPageAspx.Controls.Add(Me.CmbLangWeb)
    Me.TabPageAspx.Controls.Add(Me.Label15)
    Me.TabPageAspx.Controls.Add(Me.Label16)
    Me.TabPageAspx.Controls.Add(Me.TxtWildcardWeb)
    Me.TabPageAspx.Controls.Add(Me.ChkRecurseWeb)
    Me.TabPageAspx.Controls.Add(Me.BtnConvertWeb)
    Me.TabPageAspx.Location = New System.Drawing.Point(4, 22)
    Me.TabPageAspx.Name = "TabPageAspx"
    Me.TabPageAspx.Size = New System.Drawing.Size(721, 535)
    Me.TabPageAspx.TabIndex = 4
    Me.TabPageAspx.Text = "Convert ASP.NET Files"
    Me.TabPageAspx.UseVisualStyleBackColor = True
    '
    'ChkFixNsWeb
    '
    Me.ChkFixNsWeb.Location = New System.Drawing.Point(494, 144)
    Me.ChkFixNsWeb.Name = "ChkFixNsWeb"
    Me.ChkFixNsWeb.Size = New System.Drawing.Size(176, 24)
    Me.ChkFixNsWeb.TabIndex = 35
    Me.ChkFixNsWeb.Text = "Fix namespace imports"
    Me.ToolTipButtons.SetToolTip(Me.ChkFixNsWeb, resources.GetString("ChkFixNsWeb.ToolTip"))
    Me.ChkFixNsWeb.Visible = False
    '
    'ChkOverwriteWeb
    '
    Me.ChkOverwriteWeb.Location = New System.Drawing.Point(312, 144)
    Me.ChkOverwriteWeb.Name = "ChkOverwriteWeb"
    Me.ChkOverwriteWeb.Size = New System.Drawing.Size(176, 24)
    Me.ChkOverwriteWeb.TabIndex = 28
    Me.ChkOverwriteWeb.Text = "Overwrite existing files"
    Me.ToolTipButtons.SetToolTip(Me.ChkOverwriteWeb, "Enable to overwrite existing files in the target directory.")
    '
    'GroupBox3
    '
    Me.GroupBox3.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.GroupBox3.Controls.Add(Me.TxtOutputWeb)
    Me.GroupBox3.Location = New System.Drawing.Point(16, 176)
    Me.GroupBox3.Name = "GroupBox3"
    Me.GroupBox3.Size = New System.Drawing.Size(689, 348)
    Me.GroupBox3.TabIndex = 30
    Me.GroupBox3.TabStop = False
    Me.GroupBox3.Text = "Output"
    '
    'TxtOutputWeb
    '
    Me.TxtOutputWeb.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtOutputWeb.Location = New System.Drawing.Point(16, 25)
    Me.TxtOutputWeb.MaxLength = 10000000
    Me.TxtOutputWeb.Multiline = True
    Me.TxtOutputWeb.Name = "TxtOutputWeb"
    Me.TxtOutputWeb.ReadOnly = True
    Me.TxtOutputWeb.ScrollBars = System.Windows.Forms.ScrollBars.Both
    Me.TxtOutputWeb.Size = New System.Drawing.Size(657, 307)
    Me.TxtOutputWeb.TabIndex = 0
    Me.TxtOutputWeb.WordWrap = False
    '
    'BtnBrowseTargetWeb
    '
    Me.BtnBrowseTargetWeb.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseTargetWeb.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseTargetWeb.Location = New System.Drawing.Point(676, 112)
    Me.BtnBrowseTargetWeb.Name = "BtnBrowseTargetWeb"
    Me.BtnBrowseTargetWeb.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseTargetWeb.TabIndex = 26
    Me.BtnBrowseTargetWeb.Text = "..."
    '
    'TxtTargetFolderWeb
    '
    Me.TxtTargetFolderWeb.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtTargetFolderWeb.Location = New System.Drawing.Point(128, 112)
    Me.TxtTargetFolderWeb.Name = "TxtTargetFolderWeb"
    Me.TxtTargetFolderWeb.Size = New System.Drawing.Size(542, 21)
    Me.TxtTargetFolderWeb.TabIndex = 25
    '
    'Label13
    '
    Me.Label13.Location = New System.Drawing.Point(16, 112)
    Me.Label13.Name = "Label13"
    Me.Label13.Size = New System.Drawing.Size(104, 24)
    Me.Label13.TabIndex = 34
    Me.Label13.Text = "Target Directory:"
    '
    'BtnBrowseSrcWeb
    '
    Me.BtnBrowseSrcWeb.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseSrcWeb.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseSrcWeb.Location = New System.Drawing.Point(676, 80)
    Me.BtnBrowseSrcWeb.Name = "BtnBrowseSrcWeb"
    Me.BtnBrowseSrcWeb.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseSrcWeb.TabIndex = 24
    Me.BtnBrowseSrcWeb.Text = "..."
    '
    'TxtSrcFolderWeb
    '
    Me.TxtSrcFolderWeb.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtSrcFolderWeb.Location = New System.Drawing.Point(128, 80)
    Me.TxtSrcFolderWeb.Name = "TxtSrcFolderWeb"
    Me.TxtSrcFolderWeb.Size = New System.Drawing.Size(542, 21)
    Me.TxtSrcFolderWeb.TabIndex = 23
    '
    'Label14
    '
    Me.Label14.Location = New System.Drawing.Point(16, 80)
    Me.Label14.Name = "Label14"
    Me.Label14.Size = New System.Drawing.Size(104, 24)
    Me.Label14.TabIndex = 32
    Me.Label14.Text = "Source Directory:"
    '
    'CmbLangWeb
    '
    Me.CmbLangWeb.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbLangWeb.Items.AddRange(New Object() {"Autodetect", "Visual Basic .NET -> C#", "C# -> Visual Basic .NET"})
    Me.CmbLangWeb.Location = New System.Drawing.Point(128, 16)
    Me.CmbLangWeb.Name = "CmbLangWeb"
    Me.CmbLangWeb.Size = New System.Drawing.Size(176, 21)
    Me.CmbLangWeb.TabIndex = 21
    '
    'Label15
    '
    Me.Label15.Location = New System.Drawing.Point(16, 16)
    Me.Label15.Name = "Label15"
    Me.Label15.Size = New System.Drawing.Size(104, 24)
    Me.Label15.TabIndex = 31
    Me.Label15.Text = "Language:"
    '
    'Label16
    '
    Me.Label16.Location = New System.Drawing.Point(16, 48)
    Me.Label16.Name = "Label16"
    Me.Label16.Size = New System.Drawing.Size(104, 24)
    Me.Label16.TabIndex = 33
    Me.Label16.Text = "Wildcard(s):"
    '
    'TxtWildcardWeb
    '
    Me.TxtWildcardWeb.Location = New System.Drawing.Point(128, 48)
    Me.TxtWildcardWeb.Name = "TxtWildcardWeb"
    Me.TxtWildcardWeb.Size = New System.Drawing.Size(176, 21)
    Me.TxtWildcardWeb.TabIndex = 22
    Me.TxtWildcardWeb.Text = "*.aspx,*.ascx,*.asmx"
    '
    'ChkRecurseWeb
    '
    Me.ChkRecurseWeb.Checked = True
    Me.ChkRecurseWeb.CheckState = System.Windows.Forms.CheckState.Checked
    Me.ChkRecurseWeb.Location = New System.Drawing.Point(128, 144)
    Me.ChkRecurseWeb.Name = "ChkRecurseWeb"
    Me.ChkRecurseWeb.Size = New System.Drawing.Size(176, 24)
    Me.ChkRecurseWeb.TabIndex = 27
    Me.ChkRecurseWeb.Text = "Recurse Subdirectories"
    Me.ToolTipButtons.SetToolTip(Me.ChkRecurseWeb, "Enable to convert files, located in subfolders of the source directory. The subfo" & _
            "lders will be created in the target directory if they not exist.")
    '
    'BtnConvertWeb
    '
    Me.BtnConvertWeb.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnConvertWeb.Enabled = False
    Me.BtnConvertWeb.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnConvertWeb.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnConvertWeb.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnConvertWeb.Location = New System.Drawing.Point(569, 16)
    Me.BtnConvertWeb.Name = "BtnConvertWeb"
    Me.BtnConvertWeb.Size = New System.Drawing.Size(136, 24)
    Me.BtnConvertWeb.TabIndex = 29
    Me.BtnConvertWeb.Text = "Convert"
    Me.ToolTipButtons.SetToolTip(Me.BtnConvertWeb, "Start Conversion")
    '
    'TabPageProj
    '
    Me.TabPageProj.Controls.Add(Me.ChkFixNsProj)
    Me.TabPageProj.Controls.Add(Me.ChkOverwriteProj)
    Me.TabPageProj.Controls.Add(Me.GroupBox2)
    Me.TabPageProj.Controls.Add(Me.BtnBrowseTargetProj)
    Me.TabPageProj.Controls.Add(Me.TxtDestFolderProj)
    Me.TabPageProj.Controls.Add(Me.Label9)
    Me.TabPageProj.Controls.Add(Me.BtnBrowseSrcProj)
    Me.TabPageProj.Controls.Add(Me.TxtSrcFolderProj)
    Me.TabPageProj.Controls.Add(Me.Label10)
    Me.TabPageProj.Controls.Add(Me.CmbLangProj)
    Me.TabPageProj.Controls.Add(Me.Label11)
    Me.TabPageProj.Controls.Add(Me.Label12)
    Me.TabPageProj.Controls.Add(Me.TxtWildcardProj)
    Me.TabPageProj.Controls.Add(Me.ChkRecurseProj)
    Me.TabPageProj.Controls.Add(Me.BtnConvertProjects)
    Me.TabPageProj.Location = New System.Drawing.Point(4, 22)
    Me.TabPageProj.Name = "TabPageProj"
    Me.TabPageProj.Size = New System.Drawing.Size(721, 535)
    Me.TabPageProj.TabIndex = 3
    Me.TabPageProj.Text = "Convert Visual Studio Projects"
    Me.TabPageProj.UseVisualStyleBackColor = True
    '
    'ChkFixNsProj
    '
    Me.ChkFixNsProj.Location = New System.Drawing.Point(494, 144)
    Me.ChkFixNsProj.Name = "ChkFixNsProj"
    Me.ChkFixNsProj.Size = New System.Drawing.Size(176, 24)
    Me.ChkFixNsProj.TabIndex = 8
    Me.ChkFixNsProj.Text = "Fix namespace imports"
    Me.ToolTipButtons.SetToolTip(Me.ChkFixNsProj, resources.GetString("ChkFixNsProj.ToolTip"))
    '
    'ChkOverwriteProj
    '
    Me.ChkOverwriteProj.Location = New System.Drawing.Point(312, 144)
    Me.ChkOverwriteProj.Name = "ChkOverwriteProj"
    Me.ChkOverwriteProj.Size = New System.Drawing.Size(176, 24)
    Me.ChkOverwriteProj.TabIndex = 7
    Me.ChkOverwriteProj.Text = "Overwrite existing files"
    Me.ToolTipButtons.SetToolTip(Me.ChkOverwriteProj, "Enable to overwrite existing files in the target directory.")
    '
    'GroupBox2
    '
    Me.GroupBox2.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.GroupBox2.Controls.Add(Me.TxtOutputProj)
    Me.GroupBox2.Location = New System.Drawing.Point(16, 176)
    Me.GroupBox2.Name = "GroupBox2"
    Me.GroupBox2.Size = New System.Drawing.Size(689, 348)
    Me.GroupBox2.TabIndex = 10
    Me.GroupBox2.TabStop = False
    Me.GroupBox2.Text = "Output"
    '
    'TxtOutputProj
    '
    Me.TxtOutputProj.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtOutputProj.Location = New System.Drawing.Point(16, 25)
    Me.TxtOutputProj.MaxLength = 10000000
    Me.TxtOutputProj.Multiline = True
    Me.TxtOutputProj.Name = "TxtOutputProj"
    Me.TxtOutputProj.ReadOnly = True
    Me.TxtOutputProj.ScrollBars = System.Windows.Forms.ScrollBars.Both
    Me.TxtOutputProj.Size = New System.Drawing.Size(657, 307)
    Me.TxtOutputProj.TabIndex = 0
    Me.TxtOutputProj.WordWrap = False
    '
    'BtnBrowseTargetProj
    '
    Me.BtnBrowseTargetProj.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseTargetProj.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseTargetProj.Location = New System.Drawing.Point(676, 112)
    Me.BtnBrowseTargetProj.Name = "BtnBrowseTargetProj"
    Me.BtnBrowseTargetProj.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseTargetProj.TabIndex = 5
    Me.BtnBrowseTargetProj.Text = "..."
    '
    'TxtDestFolderProj
    '
    Me.TxtDestFolderProj.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtDestFolderProj.Location = New System.Drawing.Point(128, 112)
    Me.TxtDestFolderProj.Name = "TxtDestFolderProj"
    Me.TxtDestFolderProj.Size = New System.Drawing.Size(542, 21)
    Me.TxtDestFolderProj.TabIndex = 4
    '
    'Label9
    '
    Me.Label9.Location = New System.Drawing.Point(16, 112)
    Me.Label9.Name = "Label9"
    Me.Label9.Size = New System.Drawing.Size(104, 24)
    Me.Label9.TabIndex = 19
    Me.Label9.Text = "Target Directory:"
    '
    'BtnBrowseSrcProj
    '
    Me.BtnBrowseSrcProj.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnBrowseSrcProj.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnBrowseSrcProj.Location = New System.Drawing.Point(676, 80)
    Me.BtnBrowseSrcProj.Name = "BtnBrowseSrcProj"
    Me.BtnBrowseSrcProj.Size = New System.Drawing.Size(29, 20)
    Me.BtnBrowseSrcProj.TabIndex = 3
    Me.BtnBrowseSrcProj.Text = "..."
    '
    'TxtSrcFolderProj
    '
    Me.TxtSrcFolderProj.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.TxtSrcFolderProj.Location = New System.Drawing.Point(128, 80)
    Me.TxtSrcFolderProj.Name = "TxtSrcFolderProj"
    Me.TxtSrcFolderProj.Size = New System.Drawing.Size(542, 21)
    Me.TxtSrcFolderProj.TabIndex = 2
    '
    'Label10
    '
    Me.Label10.Location = New System.Drawing.Point(16, 80)
    Me.Label10.Name = "Label10"
    Me.Label10.Size = New System.Drawing.Size(104, 24)
    Me.Label10.TabIndex = 14
    Me.Label10.Text = "Source Directory:"
    '
    'CmbLangProj
    '
    Me.CmbLangProj.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbLangProj.Items.AddRange(New Object() {"Visual Basic .NET -> C#", "C# -> Visual Basic .NET"})
    Me.CmbLangProj.Location = New System.Drawing.Point(128, 16)
    Me.CmbLangProj.Name = "CmbLangProj"
    Me.CmbLangProj.Size = New System.Drawing.Size(176, 21)
    Me.CmbLangProj.TabIndex = 0
    '
    'Label11
    '
    Me.Label11.Location = New System.Drawing.Point(16, 16)
    Me.Label11.Name = "Label11"
    Me.Label11.Size = New System.Drawing.Size(104, 24)
    Me.Label11.TabIndex = 10
    Me.Label11.Text = "Language:"
    '
    'Label12
    '
    Me.Label12.Location = New System.Drawing.Point(16, 48)
    Me.Label12.Name = "Label12"
    Me.Label12.Size = New System.Drawing.Size(104, 24)
    Me.Label12.TabIndex = 15
    Me.Label12.Text = "Wildcard(s):"
    '
    'TxtWildcardProj
    '
    Me.TxtWildcardProj.Location = New System.Drawing.Point(128, 48)
    Me.TxtWildcardProj.Name = "TxtWildcardProj"
    Me.TxtWildcardProj.Size = New System.Drawing.Size(176, 21)
    Me.TxtWildcardProj.TabIndex = 1
    '
    'ChkRecurseProj
    '
    Me.ChkRecurseProj.Checked = True
    Me.ChkRecurseProj.CheckState = System.Windows.Forms.CheckState.Checked
    Me.ChkRecurseProj.Location = New System.Drawing.Point(128, 144)
    Me.ChkRecurseProj.Name = "ChkRecurseProj"
    Me.ChkRecurseProj.Size = New System.Drawing.Size(176, 24)
    Me.ChkRecurseProj.TabIndex = 6
    Me.ChkRecurseProj.Text = "Recurse Subdirectories"
    Me.ToolTipButtons.SetToolTip(Me.ChkRecurseProj, "Enable to convert files, located in subfolders of the source directory. The subfo" & _
            "lders will be created in the target directory if they not exist.")
    '
    'BtnConvertProjects
    '
    Me.BtnConvertProjects.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnConvertProjects.Enabled = False
    Me.BtnConvertProjects.Font = New System.Drawing.Font("Tahoma", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.BtnConvertProjects.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.Go
    Me.BtnConvertProjects.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
    Me.BtnConvertProjects.Location = New System.Drawing.Point(569, 16)
    Me.BtnConvertProjects.Name = "BtnConvertProjects"
    Me.BtnConvertProjects.Size = New System.Drawing.Size(136, 24)
    Me.BtnConvertProjects.TabIndex = 9
    Me.BtnConvertProjects.Text = "Convert"
    Me.ToolTipButtons.SetToolTip(Me.BtnConvertProjects, "Start Conversion")
    '
    'ToolTipButtons
    '
    Me.ToolTipButtons.AutoPopDelay = 20000
    Me.ToolTipButtons.InitialDelay = 300
    Me.ToolTipButtons.ReshowDelay = 100
    Me.ToolTipButtons.ShowAlways = True
    Me.ToolTipButtons.ToolTipIcon = System.Windows.Forms.ToolTipIcon.Info
    Me.ToolTipButtons.UseAnimation = False
    '
    'CmbRefactoryProvider
    '
    Me.CmbRefactoryProvider.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.CmbRefactoryProvider.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
    Me.CmbRefactoryProvider.FormattingEnabled = True
    Me.CmbRefactoryProvider.Items.AddRange(New Object() {"ICSharpCode 1.1", "ICSharpCode 2.1", "NRefactory WebService"})
    Me.CmbRefactoryProvider.Location = New System.Drawing.Point(563, 2)
    Me.CmbRefactoryProvider.Name = "CmbRefactoryProvider"
    Me.CmbRefactoryProvider.Size = New System.Drawing.Size(140, 21)
    Me.CmbRefactoryProvider.TabIndex = 1
    Me.ToolTipSimple.SetToolTip(Me.CmbRefactoryProvider, "Select the current Refactory-Provider (choosen Provider will also be used by the " & _
            "Command-Line Tool)")
    '
    'DlgFileOpen
    '
    Me.DlgFileOpen.Title = "Open Input"
    '
    'DlgFileSave
    '
    Me.DlgFileSave.Title = "Save Output"
    '
    'NetVertTrayIcon
    '
    Me.NetVertTrayIcon.ContextMenuStrip = Me.MnuNetVert
    Me.NetVertTrayIcon.Icon = CType(resources.GetObject("NetVertTrayIcon.Icon"), System.Drawing.Icon)
    Me.NetVertTrayIcon.Text = "Econ NetVert"
    Me.NetVertTrayIcon.Visible = True
    '
    'MnuNetVert
    '
    Me.MnuNetVert.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.MnuShowWindow, Me.ToolStripMenuItem1, Me.MnuConvertSrc, Me.MnuConvertStatements, Me.ToolStripMenuItem2, Me.MnuExit})
    Me.MnuNetVert.Name = "MnuNetVert"
    Me.MnuNetVert.Size = New System.Drawing.Size(239, 104)
    '
    'MnuShowWindow
    '
    Me.MnuShowWindow.Font = New System.Drawing.Font("Tahoma", 8.25!, System.Drawing.FontStyle.Bold)
    Me.MnuShowWindow.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.window
    Me.MnuShowWindow.Name = "MnuShowWindow"
    Me.MnuShowWindow.Size = New System.Drawing.Size(238, 22)
    Me.MnuShowWindow.Text = "Show window"
    '
    'ToolStripMenuItem1
    '
    Me.ToolStripMenuItem1.Name = "ToolStripMenuItem1"
    Me.ToolStripMenuItem1.Size = New System.Drawing.Size(235, 6)
    '
    'MnuConvertSrc
    '
    Me.MnuConvertSrc.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.VBtoCSCodeMenu, Me.CStoVBCodeMenu})
    Me.MnuConvertSrc.Name = "MnuConvertSrc"
    Me.MnuConvertSrc.Size = New System.Drawing.Size(238, 22)
    Me.MnuConvertSrc.Text = "Convert source in clipboard"
    '
    'VBtoCSCodeMenu
    '
    Me.VBtoCSCodeMenu.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.VB_to_CS2_16
    Me.VBtoCSCodeMenu.Name = "VBtoCSCodeMenu"
    Me.VBtoCSCodeMenu.Size = New System.Drawing.Size(178, 22)
    Me.VBtoCSCodeMenu.Text = "From VB.NET to C#"
    '
    'CStoVBCodeMenu
    '
    Me.CStoVBCodeMenu.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.CS_to_VB2_16
    Me.CStoVBCodeMenu.Name = "CStoVBCodeMenu"
    Me.CStoVBCodeMenu.Size = New System.Drawing.Size(178, 22)
    Me.CStoVBCodeMenu.Text = "From C# to VB.NET"
    '
    'MnuConvertStatements
    '
    Me.MnuConvertStatements.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.VBtoCSStatementsMenu, Me.CStoVBStatementsMenu})
    Me.MnuConvertStatements.Name = "MnuConvertStatements"
    Me.MnuConvertStatements.Size = New System.Drawing.Size(238, 22)
    Me.MnuConvertStatements.Text = "Convert statements in clipboard"
    '
    'VBtoCSStatementsMenu
    '
    Me.VBtoCSStatementsMenu.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.VB_to_CS2_16
    Me.VBtoCSStatementsMenu.Name = "VBtoCSStatementsMenu"
    Me.VBtoCSStatementsMenu.Size = New System.Drawing.Size(178, 22)
    Me.VBtoCSStatementsMenu.Text = "From VB.NET to C#"
    '
    'CStoVBStatementsMenu
    '
    Me.CStoVBStatementsMenu.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.CS_to_VB2_16
    Me.CStoVBStatementsMenu.Name = "CStoVBStatementsMenu"
    Me.CStoVBStatementsMenu.Size = New System.Drawing.Size(178, 22)
    Me.CStoVBStatementsMenu.Text = "From C# to VB.NET"
    '
    'ToolStripMenuItem2
    '
    Me.ToolStripMenuItem2.Name = "ToolStripMenuItem2"
    Me.ToolStripMenuItem2.Size = New System.Drawing.Size(235, 6)
    '
    'MnuExit
    '
    Me.MnuExit.Image = Global.Econ.Netvert.Gui.My.Resources.Resources.XP_Exit_16
    Me.MnuExit.Name = "MnuExit"
    Me.MnuExit.Size = New System.Drawing.Size(238, 22)
    Me.MnuExit.Text = "Exit Econ NetVert"
    '
    'BtnAbout
    '
    Me.BtnAbout.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.BtnAbout.FlatStyle = System.Windows.Forms.FlatStyle.Popup
    Me.BtnAbout.Image = CType(resources.GetObject("BtnAbout.Image"), System.Drawing.Image)
    Me.BtnAbout.Location = New System.Drawing.Point(709, 2)
    Me.BtnAbout.Name = "BtnAbout"
    Me.BtnAbout.Size = New System.Drawing.Size(24, 24)
    Me.BtnAbout.TabIndex = 2
    Me.BtnAbout.TabStop = False
    Me.ToolTipSimple.SetToolTip(Me.BtnAbout, "About")
    '
    'ApplicationUpdater
    '
    Me.ApplicationUpdater.ApplicationId = "1816e5a9-2370-44d5-a8dd-7dbd3ecd9a21"
    Me.ApplicationUpdater.AutoCheckOnStartup = True
    Me.ApplicationUpdater.ServerURL = "http://updater.econdimension.com"
    '
    'FrmMain
    '
    Me.AllowDrop = True
    Me.AutoScaleBaseSize = New System.Drawing.Size(5, 14)
    Me.ClientSize = New System.Drawing.Size(737, 573)
    Me.Controls.Add(Me.CmbRefactoryProvider)
    Me.Controls.Add(Me.BtnAbout)
    Me.Controls.Add(Me.TabMain)
    Me.Font = New System.Drawing.Font("Tahoma", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
    Me.MinimumSize = New System.Drawing.Size(660, 352)
    Me.Name = "FrmMain"
    Me.Padding = New System.Windows.Forms.Padding(4, 8, 4, 4)
    Me.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show
    Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
    Me.Text = "Econ NetVert"
    Me.TabMain.ResumeLayout(False)
    Me.TabPageVBtoCS.ResumeLayout(False)
    Me.SplitContainer1.Panel1.ResumeLayout(False)
    Me.SplitContainer1.Panel2.ResumeLayout(False)
    Me.SplitContainer1.ResumeLayout(False)
    Me.Panel3.ResumeLayout(False)
    Me.MnuEditor.ResumeLayout(False)
    Me.Panel4.ResumeLayout(False)
    Me.Panel5.ResumeLayout(False)
    Me.Panel6.ResumeLayout(False)
    Me.PnlBottomVC.ResumeLayout(False)
    Me.TabPageCStoVB.ResumeLayout(False)
    Me.SplitContainer2.Panel1.ResumeLayout(False)
    Me.SplitContainer2.Panel2.ResumeLayout(False)
    Me.SplitContainer2.ResumeLayout(False)
    Me.Panel8.ResumeLayout(False)
    Me.Panel9.ResumeLayout(False)
    Me.Panel2.ResumeLayout(False)
    Me.Panel7.ResumeLayout(False)
    Me.PnlBottomCV.ResumeLayout(False)
    Me.TabPageFiles.ResumeLayout(False)
    Me.TabPageFiles.PerformLayout()
    Me.GroupBox1.ResumeLayout(False)
    Me.GroupBox1.PerformLayout()
    Me.TabPageAspx.ResumeLayout(False)
    Me.TabPageAspx.PerformLayout()
    Me.GroupBox3.ResumeLayout(False)
    Me.GroupBox3.PerformLayout()
    Me.TabPageProj.ResumeLayout(False)
    Me.TabPageProj.PerformLayout()
    Me.GroupBox2.ResumeLayout(False)
    Me.GroupBox2.PerformLayout()
    Me.MnuNetVert.ResumeLayout(False)
    Me.ResumeLayout(False)

  End Sub

#End Region

  'PRIVATE
#Region "Tooltips / Info"

  Private Sub ApplyTooltips()
    Dim TmpS As String

    'VB->CS / CS->VB "Convert" Button
    TmpS = "The input source must contain one or many of the following codeelements:" & vbCrLf & _
           "- Comments, Regions or Comiplerargs" & vbCrLf & _
           "- Assembly Attributes" & vbCrLf & _
           "- Import Statements" & vbCrLf & _
           "- Namespaces" & vbCrLf & _
           "- Classes, Interfaces or Structures" & vbCrLf & _
           "- Variable, Constants, Enumerations or Delegate declarations" & vbCrLf & _
           "- Property, Procedure or Function implementation"
    ToolTipButtons.SetToolTip(BtnVbToCs, TmpS)
    ToolTipButtons.SetToolTip(BtnCsToVb, TmpS)
    'VB->CS / CS->VB "Convert statements" Button
    TmpS = "The input source must contain one or many statement lines that can be placed inside a method body." & vbCrLf & _
           "(The converter temporarly wraps a BorderSub() method around the statements)"
    ToolTipButtons.SetToolTip(BtnVbToCsMethod, TmpS)
    ToolTipButtons.SetToolTip(BtnCsToVbMethod, TmpS)
    'Wildcards
    TmpS = "One or multiple wildcards or filenames, to search for $1 in the source directory." & vbCrLf & _
           "When using multiple wildcards use comma as delimiter." '& vbCrLf
    ToolTipButtons.SetToolTip(TxtWildcard, TmpS.Replace("$1", "sourcecode files") & vbCrLf & _
                                           "Examples: file1.vb,file2.vb or *.vb or file1.cs,file2.cs or *.cs")
    ToolTipButtons.SetToolTip(TxtWildcardWeb, TmpS.Replace("$1", "ASP.NET files") & vbCrLf & _
                                              "Examples: file1.aspx,file2.aspx or *.aspx,*.ascx,*.asmx")
    ToolTipButtons.SetToolTip(TxtWildcardProj, TmpS.Replace("$1", "Visual Studio projects") & vbCrLf & _
                                               "Examples: project1.vbproj,project2.vbproj or *.vbproj or project1.csproj,project2.csproj or *.csproj")
    'ASP.NET-Language
    ToolTipButtons.SetToolTip(CmbLangWeb, "When 'Autodetect' is selected, the converter searches for the '<@ Page language=xx>' attribute in each ASP.NET file.")
    CmbLangWeb.SelectedIndex = 0
  End Sub

  Private Sub ShowInfoConvert()
    Dim TmpS As String

    TmpS = "The input source text is empty." & vbCrLf & vbCrLf & _
           "It must contain one or many of the following codeelements:" & vbCrLf & _
           "- Comments, Regions or Comiplerargs" & vbCrLf & _
           "- Assembly Attributes" & vbCrLf & _
           "- Import Statements" & vbCrLf & _
           "- Namespaces" & vbCrLf & _
           "- Classes, Interfaces or Structures" & vbCrLf & _
           "- Variable, Constants, Enumerations or Delegate declarations" & vbCrLf & _
           "- Property, Procedure or Function implementation"
    MsgBox(TmpS, MsgBoxStyle.Information, "Convert...")
  End Sub

  Private Sub ShowInfoConvertMethod()
    Dim TmpS As String

    TmpS = "The input source text is empty." & vbCrLf & vbCrLf & _
           "It must contain one or many statement lines that can be placed inside a method body." & vbCrLf & _
           "(The converter temporarly wraps a BorderSub() method around the statements)"
    MsgBox(TmpS, MsgBoxStyle.Information, "Convert statements...")
  End Sub

#End Region

#Region "Convert VB.NET -> C#"

  Private Sub BtnVbToCs_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVbToCs.Click
    Dim TmpConv As VBCSConverter

    If TxtFromVb.Text = "" Then
      ShowInfoConvert()
    Else
      TmpConv = VBCSConverter.Convert(TxtFromVb.Text)
      TxtToCs.Document.TextContent = TmpConv.CSharpSource
      TxtToCs.Refresh()
      If TmpConv.HasError Then
        MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
      End If
    End If
  End Sub

  Private Sub BtnVbToCsMethod_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVbToCsMethod.Click
    Dim TmpConv As VBCSConverter

    If TxtFromVb.Text = "" Then
      ShowInfoConvertMethod()
    Else
      TmpConv = VBCSConverter.ConvertMethodBody(TxtFromVb.Text)
      TxtToCs.Document.TextContent = TmpConv.CSharpSource
      TxtToCs.Refresh()
      If TmpConv.HasError Then
        MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
      End If
    End If
  End Sub

  Private Sub VBtoCSCodeMenu_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles VBtoCSCodeMenu.Click
    Dim TmpConv As VBCSConverter

    TmpConv = VBCSConverter.Convert(Clipboard.GetText)
    If TmpConv.HasError Then
      MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
    Else
      Clipboard.SetText(TmpConv.CSharpSource)
    End If
  End Sub

  Private Sub VBtoCSStatementsMenu_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles VBtoCSStatementsMenu.Click
    Dim TmpConv As VBCSConverter

    TmpConv = VBCSConverter.ConvertMethodBody(Clipboard.GetText)
    If TmpConv.HasError Then
      MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
    Else
      Clipboard.SetText(TmpConv.CSharpSource)
    End If
  End Sub

  Private Sub BtnVBOpen_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVBOpen.Click
    Dim TmpFS As FileStream
    Dim TmpRead As StreamReader

    DlgFileOpen.Filter = "Visual Basic .NET Source File (*.vb)|*.vb|All Files (*.*)|*.*"
    If DlgFileOpen.ShowDialog(Me) = DialogResult.OK Then
      TmpFS = New FileStream(DlgFileOpen.FileName, FileMode.Open)
      'use ANSI Encoding instead of UTF-8 because Visual Studio creates ANSI Files
      TmpRead = New StreamReader(TmpFS, System.Text.Encoding.Default)
      'TmpRead = File.OpenText(DlgFileOpen.FileName)
      TxtFromVb.Document.TextContent = TmpRead.ReadToEnd
      TmpRead.Close()
    End If
  End Sub

  Private Sub BtnVBClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVBClear.Click
    TxtFromVb.Document.TextContent = ""
    TxtFromVb.Refresh()
  End Sub

  Private Sub BtnCSSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCSSave.Click
    Dim TmpFS As FileStream
    Dim TmpWrite As StreamWriter

    DlgFileSave.Filter = "C# Source File (*.cs)|*.cs|All Files (*.*)|*.*"
    If DlgFileSave.ShowDialog(Me) = DialogResult.OK Then
      TmpFS = New FileStream(DlgFileSave.FileName, FileMode.Create)
      TmpWrite = New StreamWriter(TmpFS, System.Text.Encoding.Default)
      TmpWrite.Write(TxtToCs.Text)
      TmpWrite.Close()
    End If
  End Sub

  Private Sub BtnCSCopy_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCSCopy.Click
    Clipboard.SetDataObject(TxtToCs.Text, True)
  End Sub

#End Region

#Region "Convert C# -> VB.NET"

  Private Sub BtnCsToVb_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCsToVb.Click
    Dim TmpConv As CSVBConverter

    If TxtFromCS.Text = "" Then
      ShowInfoConvert()
    Else
      TmpConv = CSVBConverter.Convert(TxtFromCS.Text)
      TxtToVb.Document.TextContent = TmpConv.VBSource
      TxtToVb.Refresh()
      If TmpConv.HasError Then
        MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
      End If
    End If
  End Sub

  Private Sub BtnCsToVbMethod_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCsToVbMethod.Click
    Dim TmpConv As CSVBConverter

    If TxtFromCS.Text = "" Then
      ShowInfoConvertMethod()
    Else
      TmpConv = CSVBConverter.ConvertMethodBody(TxtFromCS.Text)
      TxtToVb.Document.TextContent = TmpConv.VBSource
      TxtToVb.Refresh()
      If TmpConv.HasError Then
        MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
      End If
    End If
  End Sub

  Private Sub CStoVBCodeMenu_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CStoVBCodeMenu.Click
    Dim TmpConv As CSVBConverter

    TmpConv = CSVBConverter.Convert(Clipboard.GetText)
    If TmpConv.HasError Then
      MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
    Else
      Clipboard.SetText(TmpConv.VBSource)
    End If
  End Sub

  Private Sub CStoVBStatementsMenu_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CStoVBStatementsMenu.Click
    Dim TmpConv As CSVBConverter

    TmpConv = CSVBConverter.ConvertMethodBody(Clipboard.GetText)
    If TmpConv.HasError Then
      MessageBox.Show(TmpConv.ErrorText, "Parser Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
    Else
      Clipboard.SetText(TmpConv.VBSource)
    End If
  End Sub

  Private Sub BtnCSOpen_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCSOpen.Click
    Dim TmpFS As FileStream
    Dim TmpRead As StreamReader

    DlgFileOpen.Filter = "C# Source File (*.cs)|*.cs|All Files (*.*)|*.*"
    If DlgFileOpen.ShowDialog(Me) = DialogResult.OK Then
      TmpFS = New FileStream(DlgFileOpen.FileName, FileMode.Open)
      'use ANSI Encoding instead of UTF-8 because Visual Studio creates ANSI Files
      TmpRead = New StreamReader(TmpFS, System.Text.Encoding.Default)
      'TmpRead = File.OpenText(DlgFileOpen.FileName)
      TxtFromCS.Document.TextContent = TmpRead.ReadToEnd
      TmpRead.Close()
    End If
  End Sub

  Private Sub BtnCSClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnCSClear.Click
    TxtFromCS.Document.TextContent = ""
    TxtFromCS.Refresh()
  End Sub

  Private Sub BtnVBSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVBSave.Click
    Dim TmpFS As FileStream
    Dim TmpWrite As StreamWriter

    DlgFileSave.Filter = "Visual Basic .NET Source File (*.vb)|*.vb|All Files (*.*)|*.*"
    If DlgFileSave.ShowDialog(Me) = DialogResult.OK Then
      TmpFS = New FileStream(DlgFileSave.FileName, FileMode.Create)
      TmpWrite = New StreamWriter(TmpFS, System.Text.Encoding.Default)
      TmpWrite.Write(TxtToVb.Text)
      TmpWrite.Close()
    End If
  End Sub

  Private Sub BtnVBCopy_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnVBCopy.Click
    Clipboard.SetDataObject(TxtToVb.Text, True)
  End Sub

#End Region

#Region "Convert Files"

  Private Sub BtnConvertFiles_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnConvertFiles.Click
    Dim TmpConv As CodeFileConverter

    'disable button
    BtnConvertFiles.Enabled = False
    'create StringBuilder
    FTextBuilder = New StringBuilder
    'clear output-TextBox
    TxtOutput.Text = ""
    OutputText("Searching for Files..." & vbCrLf)
    'create CodeFileConverter for selected language
    If CmbLang.SelectedIndex = 0 Then
      TmpConv = New CodeFileConverter(ConverterLanguages.VBNetToCSharp)
    Else
      TmpConv = New CodeFileConverter(ConverterLanguages.CSharpToVBNet)
    End If
    Try
      AddHandler TmpConv.AfterFileProcessed, AddressOf Converter_AfterFileProcessed
      'begin conversion
      TmpConv.ConvertFiles(TxtSrcFolder.Text, TxtWildcard.Text, TxtTarget.Text, ChkRecurse.Checked, ChkOverwrite.Checked, ChkFixNs.Checked)
      'finished
      OutputText(TmpConv.SummaryText)
      'OutputText("Processed Files: " & TmpConv.TotalFilesCount.ToString & vbCrLf)
      'OutputText("Converted: " & TmpConv.ConvertedFilesCount.ToString & vbCrLf)
      'OutputText("Failed: " & TmpConv.FailedFilesCount.ToString & vbCrLf)
    Catch ex As Exception
      'common error
      OutputText("Error: " & ex.Message & vbCrLf & ex.StackTrace & vbCrLf)
    End Try
    're-enable button
    CheckButton()
  End Sub

  Private Sub OutputText(ByVal textLine As String)
    FTextBuilder.Append(textLine)
    TxtOutput.SuspendLayout()
    TxtOutput.Text = FTextBuilder.ToString
    TxtOutput.SelectionStart = TxtOutput.Text.Length
    TxtOutput.ScrollToCaret()
    TxtOutput.ResumeLayout(True)
    TxtOutput.Refresh()
    'System.Windows.Forms.Application.DoEvents()
  End Sub

  Private Sub CheckButton()
    BtnConvertFiles.Enabled = (CmbLang.SelectedIndex > -1) AndAlso _
                              (TxtSrcFolder.Text <> "")
  End Sub

  Private Sub Converter_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    OutputText(e.ToString(TxtSrcFolder.Text, TxtTarget.Text) & vbCrLf)
  End Sub

  Private Sub BtnBrowseSrc_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseSrc.Click
    If TxtSrcFolder.Text <> "" Then
      FolderBrowser.SelectedPath = TxtSrcFolder.Text
    End If
    If FolderBrowser.ShowDialog(Me) = DialogResult.OK Then
      TxtSrcFolder.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub BtnBrowseTarget_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseTarget.Click
    If TxtTarget.Text <> "" Then
      FolderBrowser.SelectedPath = TxtTarget.Text
    End If
    If FolderBrowser.ShowDialog(Me) = DialogResult.OK Then
      TxtTarget.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub CmbLang_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CmbLang.SelectedIndexChanged
    If CmbLang.SelectedIndex = 0 Then
      TxtWildcard.Text = "*.vb"
    ElseIf CmbLang.SelectedIndex = 1 Then
      TxtWildcard.Text = "*.cs"
    End If
    CheckButton()
  End Sub

  Private Sub TxtSrcFolder_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TxtSrcFolder.TextChanged
    TxtTarget.Text = TxtSrcFolder.Text
    CheckButton()
  End Sub

#End Region

#Region "Convert ASP.NET Files"

  Private Sub BtnConvertWeb_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnConvertWeb.Click
    Dim TmpConv As ASPXFileConverter = Nothing

    'disable button
    BtnConvertWeb.Enabled = False
    'create StringBuilder
    FTextBuilder = New StringBuilder
    'clear output-TextBox
    TxtOutputWeb.Text = ""
    OutputTextWeb("Searching for ASP.NET Files..." & vbCrLf)
    'create CodeFileConverter for selected language
    Select Case CmbLangWeb.SelectedIndex
      Case 0
        TmpConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.Autodetect)
      Case 1
        TmpConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.VBNetToCSharp)
      Case 2
        TmpConv = New ASPXFileConverter(ConverterLanguagesAutodetectable.CSharpToVBNet)
    End Select
    Try
      AddHandler TmpConv.AfterFileProcessed, AddressOf ConverterWeb_AfterFileProcessed
      'begin conversion
      TmpConv.ConvertFiles(TxtSrcFolderWeb.Text, TxtWildcardWeb.Text, TxtTargetFolderWeb.Text, ChkRecurseWeb.Checked, ChkOverwriteWeb.Checked)
      'finished
      OutputTextWeb(TmpConv.SummaryText)
    Catch ex As Exception
      'common error
      OutputTextWeb("Error: " & ex.Message & vbCrLf & ex.StackTrace & vbCrLf)
    End Try
    're-enable button
    CheckButtonWeb()
  End Sub

  Private Sub OutputTextWeb(ByVal textLine As String)
    FTextBuilder.Append(textLine)
    TxtOutputWeb.SuspendLayout()
    TxtOutputWeb.Text = FTextBuilder.ToString
    TxtOutputWeb.SelectionStart = TxtOutputWeb.Text.Length
    TxtOutputWeb.ScrollToCaret()
    TxtOutputWeb.ResumeLayout(True)
    TxtOutputWeb.Refresh()
    'System.Windows.Forms.Application.DoEvents()
  End Sub

  Private Sub CheckButtonWeb()
    BtnConvertWeb.Enabled = (CmbLangWeb.SelectedIndex > -1) AndAlso _
                            (TxtSrcFolderWeb.Text <> "")
  End Sub

  Private Sub ConverterWeb_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    OutputTextWeb(e.ToString(TxtSrcFolderWeb.Text, TxtTargetFolderWeb.Text) & vbCrLf)
  End Sub

  Private Sub BtnBrowseSrcWeb_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseSrcWeb.Click
    If TxtSrcFolderWeb.Text <> "" Then
      FolderBrowser.SelectedPath = TxtSrcFolderWeb.Text
    End If
    If FolderBrowser.ShowDialog(Me) = DialogResult.OK Then
      TxtSrcFolderWeb.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub BtnBrowseTargetWeb_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseTargetWeb.Click
    If TxtTargetFolderWeb.Text <> "" Then
      FolderBrowser.SelectedPath = TxtTargetFolderWeb.Text
    End If
    If FolderBrowser.ShowDialog(Me) = DialogResult.OK Then
      TxtTargetFolderWeb.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub TxtSrcFolderWeb_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TxtSrcFolderWeb.TextChanged
    TxtTargetFolderWeb.Text = TxtSrcFolderWeb.Text
    CheckButtonWeb()
  End Sub

#End Region

#Region "Convert VS-Projects"

  Private Sub BtnConvertProjects_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnConvertProjects.Click
    Dim TmpConv As VSProjectFileConverter

    'disable button
    BtnConvertProjects.Enabled = False
    'create new StringBuilder
    FTextBuilder = New StringBuilder
    'clear output-TextBox
    TxtOutputProj.Text = ""
    OutputTextProj("Searching for Visual Studio Projectfiles..." & vbCrLf)
    'create CodeFileConverter for selected language
    If CmbLangProj.SelectedIndex = 0 Then
      TmpConv = New VSProjectFileConverter(ConverterLanguages.VBNetToCSharp)
    Else
      TmpConv = New VSProjectFileConverter(ConverterLanguages.CSharpToVBNet)
    End If
    Try
      AddHandler TmpConv.AfterFileProcessed, AddressOf ConverterProj_AfterFileProcessed
      'begin conversion
      TmpConv.ConvertProjects(TxtSrcFolderProj.Text, TxtWildcardProj.Text, TxtDestFolderProj.Text, ChkRecurseProj.Checked, ChkOverwriteProj.Checked, ChkFixNsProj.Checked)
      'finished
      OutputTextProj(TmpConv.SummaryText)
      'OutputTextProj("Converted Projects: " & TmpConv.TotalProjectsCount.ToString & vbCrLf)
      'OutputTextProj("Copied Files: " & TmpConv.CopyFilesCount.ToString & vbCrLf)
      'OutputTextProj("Processed Code-Files: " & TmpConv.TotalCodeFilesCount.ToString & vbCrLf)
      'OutputTextProj("Converted Code-Files: " & TmpConv.ConvertedCodeFilesCount.ToString & vbCrLf)
      'OutputTextProj("Failed Code-Files: " & TmpConv.FailedCodeFilesCount.ToString & vbCrLf)
    Catch ex As Exception
      'common error
      OutputTextProj("Error: " & ex.Message & vbCrLf & ex.StackTrace & vbCrLf)
    End Try
    're-enable button
    CheckButtonProj()
  End Sub

  Private Sub OutputTextProj(ByVal textLine As String)
    FTextBuilder.Append(textLine)
    TxtOutputProj.SuspendLayout()
    TxtOutputProj.Text = FTextBuilder.ToString
    TxtOutputProj.SelectionStart = TxtOutputProj.Text.Length
    TxtOutputProj.ScrollToCaret()
    TxtOutputProj.ResumeLayout(True)
    TxtOutputProj.Refresh()
    'System.Windows.Forms.Application.DoEvents()
  End Sub

  Private Sub CheckButtonProj()
    BtnConvertProjects.Enabled = (CmbLangProj.SelectedIndex > -1) AndAlso _
                                 (TxtSrcFolderProj.Text <> "")
  End Sub

  Private Sub ConverterProj_AfterFileProcessed(ByVal sender As Object, ByVal e As ProcessedFileEventArgs)
    OutputTextProj(e.ToString(TxtSrcFolderProj.Text, TxtDestFolderProj.Text) & vbCrLf)
  End Sub

  Private Sub BtnBrowseSrcProj_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseSrcProj.Click
    If TxtSrcFolderProj.Text <> "" Then
      FolderBrowser.SelectedPath = TxtSrcFolderProj.Text
    End If
    If FolderBrowser.ShowDialog(Me) = System.Windows.Forms.DialogResult.OK Then
      TxtSrcFolderProj.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub BtnBrowseTargetProj_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnBrowseTargetProj.Click
    If TxtDestFolderProj.Text <> "" Then
      FolderBrowser.SelectedPath = TxtDestFolderProj.Text
    End If
    If FolderBrowser.ShowDialog(Me) = System.Windows.Forms.DialogResult.OK Then
      TxtDestFolderProj.Text = FolderBrowser.SelectedPath
    End If
  End Sub

  Private Sub CmbLangProj_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CmbLangProj.SelectedIndexChanged
    If CmbLangProj.SelectedIndex = 0 Then
      TxtWildcardProj.Text = "*.vbproj"
      ChkFixNsProj.Checked = True
    ElseIf CmbLangProj.SelectedIndex = 1 Then
      TxtWildcardProj.Text = "*.csproj"
      ChkFixNsProj.Checked = False
    End If
    CheckButtonProj()
  End Sub

  Private Sub TxtSrcFolderProj_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TxtSrcFolderProj.TextChanged
    TxtDestFolderProj.Text = TxtSrcFolderProj.Text
    CheckButtonProj()
  End Sub

#End Region

#Region "Common GUI Events"

  Private Sub TxtFromVb_DragDrop(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles TxtFromVb.DragDrop
    Dim TmpO As Object
    Dim TmpArr() As String

    TmpO = e.Data.GetData("FileNameW", False)
    If TypeOf TmpO Is Array Then
      TmpArr = TmpO
      If TmpArr.Length > 0 Then
        'open the file
        Try
          With New StreamReader(New FileStream(TmpArr(0), FileMode.Open), System.Text.Encoding.Default)
            TxtFromVb.Text = .ReadToEnd
            .Close()
          End With
        Catch ex As Exception
          MsgBox(ex.Message, MsgBoxStyle.Exclamation)
        End Try
      End If
    End If
  End Sub

  Private Sub TxtFromVb_DragEnter(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles TxtFromVb.DragEnter
    Dim TmpO As Object

    TmpO = e.Data.GetData("Shell IDList Array", False)
    If Not TmpO Is Nothing Then
      e.Effect = DragDropEffects.Link
    End If
  End Sub

  Private Sub TxtFromCS_DragDrop(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles TxtFromCS.DragDrop
    Dim TmpO As Object
    Dim TmpArr() As String

    TmpO = e.Data.GetData("FileNameW", False)
    If TypeOf TmpO Is Array Then
      TmpArr = TmpO
      If TmpArr.Length > 0 Then
        'open the file
        Try
          With New StreamReader(New FileStream(TmpArr(0), FileMode.Open), System.Text.Encoding.Default)
            TxtFromCS.Text = .ReadToEnd
            .Close()
          End With
        Catch ex As Exception
          MsgBox(ex.Message, MsgBoxStyle.Exclamation)
        End Try
      End If
    End If
  End Sub

  Private Sub TxtFromCS_DragEnter(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles TxtFromCS.DragEnter
    Dim TmpO As Object

    TmpO = e.Data.GetData("Shell IDList Array", False)
    If Not TmpO Is Nothing Then
      e.Effect = DragDropEffects.Link
    End If
  End Sub

  Private Sub ToolTipButtons_Popup(ByVal sender As System.Object, ByVal e As System.Windows.Forms.PopupEventArgs) Handles ToolTipButtons.Popup
    If e.AssociatedControl Is Nothing Then
      ToolTipButtons.ToolTipTitle = ""
    Else
      If e.AssociatedControl.Text = "" Then
        ToolTipButtons.ToolTipTitle = e.AssociatedControl.GetType.Name
      Else
        ToolTipButtons.ToolTipTitle = e.AssociatedControl.Text
      End If
    End If
  End Sub

  Private Sub FrmMain_DragDrop(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles Me.DragDrop
    Dim TmpO As Object
    Dim TmpArr() As String

    If TabMain.SelectedIndex < 2 Then
      TmpO = e.Data.GetData("FileNameW", False)
      If TypeOf TmpO Is Array Then
        TmpArr = TmpO
        If TmpArr.Length > 0 Then
          'open the file
          Try
            With New StreamReader(New FileStream(TmpArr(0), FileMode.Open), System.Text.Encoding.Default)
              Select Case TabMain.SelectedIndex
                Case 0
                  TxtFromVb.Text = .ReadToEnd
                Case 1
                  TxtFromCS.Text = .ReadToEnd
              End Select
              .Close()
            End With
          Catch ex As Exception
            MsgBox(ex.Message, MsgBoxStyle.Exclamation)
          End Try
        End If
      End If
    End If
  End Sub

  Private Sub FrmMain_DragEnter(ByVal sender As Object, ByVal e As System.Windows.Forms.DragEventArgs) Handles Me.DragEnter
    Dim TmpO As Object

    If TabMain.SelectedIndex < 2 Then
      TmpO = e.Data.GetData("Shell IDList Array", False)
      If Not TmpO Is Nothing Then
        e.Effect = DragDropEffects.Link
      End If
    End If
  End Sub

  Private Sub FrmMain_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
    'Refactory-Provider Drop-Down
    Select Case CType(SettingsManager.CurrentRefactoryProvider, Object).GetType.FullName
      Case GetType(RefactoryNet11Provider).FullName
        CmbRefactoryProvider.SelectedIndex = 0
      Case GetType(RefactoryNet20Provider).FullName
        CmbRefactoryProvider.SelectedIndex = 1
      Case GetType(RefactoryOnlineProvider).FullName
        CmbRefactoryProvider.SelectedIndex = 2
    End Select
    'TextEditor Highlightings
    TxtFromVb.Document.HighlightingStrategy = ICSharpCode.TextEditor.Document.HighlightingManager.Manager.FindHighlighter("VBNET")
    TxtToCs.Document.HighlightingStrategy = ICSharpCode.TextEditor.Document.HighlightingManager.Manager.FindHighlighter("C#")
    TxtFromCS.Document.HighlightingStrategy = ICSharpCode.TextEditor.Document.HighlightingManager.Manager.FindHighlighter("C#")
    TxtToVb.Document.HighlightingStrategy = ICSharpCode.TextEditor.Document.HighlightingManager.Manager.FindHighlighter("VBNET")
    'Fix Editor FontSize-Bug
    With TxtFromVb
      .Font = New Font(.Font.FontFamily, 8.25, .Font.Style, .Font.Unit)
    End With
    With TxtToCs
      .Font = New Font(.Font.FontFamily, 8.25, .Font.Style, .Font.Unit)
    End With
    With TxtFromCS
      .Font = New Font(.Font.FontFamily, 8.25, .Font.Style, .Font.Unit)
    End With
    With TxtToVb
      .Font = New Font(.Font.FontFamily, 8.25, .Font.Style, .Font.Unit)
    End With
  End Sub

  Private Sub CmbRefactoryProvider_SelectedIndexChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles CmbRefactoryProvider.SelectedIndexChanged
    Select Case CmbRefactoryProvider.SelectedIndex
      Case 0 'ICSharpCode .NET11
        SettingsManager.CurrentRefactoryProvider = RefactoryNet11Provider.Instance
      Case 1 'ICSharpCode .NET20
        SettingsManager.CurrentRefactoryProvider = RefactoryNet20Provider.Instance
      Case 2 'NRefactory Online
        SettingsManager.CurrentRefactoryProvider = RefactoryOnlineProvider.Instance
    End Select
  End Sub

  Private Sub FrmMain_LocationChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.LocationChanged
    If Me.WindowState <> FCurrentState Then
      If Me.WindowState = FormWindowState.Minimized Then
        Me.ShowInTaskbar = False
      Else
        Me.ShowInTaskbar = True
      End If
      FCurrentState = Me.WindowState
    End If
  End Sub

  Private Sub BtnAbout_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnAbout.Click
    Dim TmpFrm As New FrmAbout
    TmpFrm.BindToUpdater(Me.ApplicationUpdater)
    TmpFrm.ShowDialog(Me)
  End Sub

  Private Sub ApplicationUpdater_ApplicationUpdateResponse(ByVal sender As Object, ByVal e As Updater.ApplicationUpdateEventArgs) Handles ApplicationUpdater.ApplicationUpdateResponse
    If ApplicationUpdater.NewerVersionAvailable AndAlso _
       SettingsManager.AutoUpdateOnNewVersion Then
      ApplicationUpdater.ExecuteUpdateProcess(True)
    End If
  End Sub

#End Region

#Region "Tray-Icon Menu"

  Private Sub NetVertTrayIcon_DoubleClick(ByVal sender As Object, ByVal e As System.EventArgs) Handles NetVertTrayIcon.DoubleClick
    MnuShowWindow_Click(Me, EventArgs.Empty)
  End Sub

  Private Sub MnuShowWindow_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuShowWindow.Click
    If Me.WindowState = FormWindowState.Minimized Then
      Me.WindowState = FormWindowState.Normal
    End If
    Me.Focus()
  End Sub

  Private Sub MnuExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuExit.Click
    Me.Close()
  End Sub

  Private Sub MnuNetVert_Opening(ByVal sender As System.Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MnuNetVert.Opening
    Dim TmpB As Boolean

    TmpB = (Clipboard.GetText <> "")
    MnuConvertSrc.Enabled = TmpB
    MnuConvertStatements.Enabled = TmpB
  End Sub

#End Region

#Region "TextEditor Menu"

  Private Sub MnuEditor_Opening(ByVal sender As System.Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MnuEditor.Opening
    Dim TmpB As Boolean = False

    If Not FCurrentEditor Is Nothing Then
      TmpB = FCurrentEditor.ActiveTextAreaControl.SelectionManager.SelectedText.Length > 0
      MnuCut.Enabled = TmpB
      MnuCopy.Enabled = TmpB
      MnuPaste.Enabled = (Clipboard.GetText <> "")
      MnuUndo.Enabled = FCurrentEditor.EnableUndo
      MnuRedo.Enabled = FCurrentEditor.EnableRedo
      MnuSelectAll.Enabled = (FCurrentEditor.Document.TextLength > 0)
      MnuSearch.Checked = (FCurrentHelperBox.Visible AndAlso _
                           FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.SearchBox)
      MnuGotoLine.Checked = (FCurrentHelperBox.Visible AndAlso _
                             FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.GotoLineBox)
      MnuSearch.Enabled = (FCurrentEditor.Document.TextLength > 0) OrElse _
                          MnuSearch.Checked
      MnuGotoLine.Enabled = (FCurrentEditor.Document.TotalNumberOfLines > 1) OrElse _
                            MnuGotoLine.Checked
    Else
      e.Cancel = True
    End If
  End Sub

  Private Sub TxtFromVb_Enter(ByVal sender As Object, ByVal e As System.EventArgs) Handles TxtFromVb.Enter
    FCurrentEditor = TxtFromVb
    FCurrentHelperBox = HelperBoxFromVb
    MnuSearch.Enabled = True
    MnuGotoLine.Enabled = True
    MnuEditor.Refresh()
  End Sub

  Private Sub TxtFromCS_Enter(ByVal sender As Object, ByVal e As System.EventArgs) Handles TxtFromCS.Enter
    FCurrentEditor = TxtFromCS
    FCurrentHelperBox = HelperBoxFromCs
    MnuSearch.Enabled = True
    MnuGotoLine.Enabled = True
    MnuEditor.Refresh()
  End Sub

  Private Sub TxtToCs_Enter(ByVal sender As Object, ByVal e As System.EventArgs) Handles TxtToCs.Enter
    FCurrentEditor = TxtToCs
    FCurrentHelperBox = HelperBoxToCs
    MnuSearch.Enabled = True
    MnuGotoLine.Enabled = True
    MnuEditor.Refresh()
  End Sub

  Private Sub TxtToVb_Enter(ByVal sender As Object, ByVal e As System.EventArgs) Handles TxtToVb.Enter
    FCurrentEditor = TxtToVb
    FCurrentHelperBox = HelperBoxToVb
    MnuSearch.Enabled = True
    MnuGotoLine.Enabled = True
    MnuEditor.Refresh()
  End Sub

  Private Sub MnuCut_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuCut.Click
    'write selected Text to clipboard
    Clipboard.SetText(FCurrentEditor.ActiveTextAreaControl.SelectionManager.SelectedText)
    'delete selected text
    FCurrentEditor.ActiveTextAreaControl.SelectionManager.RemoveSelectedText()
  End Sub

  Private Sub MnuCopy_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuCopy.Click
    'write selected Text to clipboard
    Clipboard.SetText(FCurrentEditor.ActiveTextAreaControl.SelectionManager.SelectedText)
  End Sub

  Private Sub MnuPaste_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuPaste.Click
    Dim TmpS As String

    With FCurrentEditor.ActiveTextAreaControl
      If .SelectionManager.HasSomethingSelected Then
        'delete selected text
        .SelectionManager.RemoveSelectedText()
      End If
      'insert Text from clipboard
      TmpS = Clipboard.GetText()
      .Document.Insert(.Caret.Offset, TmpS)
      'set carret to the end of newly inserted text
      .Caret.Position = .Document.OffsetToPosition(.Caret.Offset + TmpS.Length)
    End With
  End Sub

  Private Sub MnuSelectAll_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles MnuSelectAll.Click
    With FCurrentEditor.ActiveTextAreaControl
      .SelectionManager.SetSelection(New Point(0, 0), _
                                     .Document.OffsetToPosition(FCurrentEditor.Text.Length))
    End With
  End Sub

  Private Sub MnuUndo_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuUndo.Click
    FCurrentEditor.Undo()
  End Sub

  Private Sub MnuRedo_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles MnuRedo.Click
    FCurrentEditor.Redo()
  End Sub

  Private Sub MnuSearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuSearch.Click
    If (FCurrentHelperBox.Visible AndAlso _
        FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.SearchBox) Then
      'Disable HelperBox
      FCurrentHelperBox.Visible = False
    Else
      'Enable HelperBox-Search
      FCurrentHelperBox.Visible = True
      FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.SearchBox
      'set focus to helper-box
      FCurrentHelperBox.Focus()
    End If
  End Sub

  Private Sub MnuGotoLine_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MnuGotoLine.Click
    If (FCurrentHelperBox.Visible AndAlso _
        FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.GotoLineBox) Then
      'Disable HelperBox
      FCurrentHelperBox.Visible = False
    Else
      'Enable HelperBox-GotoLine
      FCurrentHelperBox.Visible = True
      FCurrentHelperBox.TextEditorHelperBoxType = TextEditorHelperBoxTypes.GotoLineBox
      'set focus to helper-box
      FCurrentHelperBox.Focus()
    End If
  End Sub

#End Region

End Class
