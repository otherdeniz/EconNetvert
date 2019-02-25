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
namespace Econ.Netvert.Gui
{
  public class FrmAbout : System.Windows.Forms.Form
  {
    //DECLARATIONS
    private Econ.Updater.ApplicationUpdater FUpdater;

    //CONSTRUCTOR
    public FrmAbout()
    {
      base.New();
      InitializeComponent();
      //load settings
      ChkEnableUpdate.Checked = SettingsManager.AutoUpdateOnNewVersion;
    }

    //DESTRUCTOR
    protected override void Dispose(bool disposing)
    {
      //REMOVE EVENT-HANDLER
      FUpdater.ApplicationUpdateResponse -= Updater_ApplicationUpdateResponse;
      if (disposing) {
        if (!(components == null)) {
          components.Dispose();
        }
      }
      base.Dispose(disposing);
    }

    //PUBLIC
    public void BindToUpdater(Econ.Updater.ApplicationUpdater updater)
    {
      FUpdater = updater;
      //ADD EVENT-HANDLER
      FUpdater.ApplicationUpdateResponse += Updater_ApplicationUpdateResponse;
      //CURRENT VERSION
       // ERROR: Not supported in C#: WithStatement

      //NEWEST VERSION
      RefreshNewestVersion();
    }

    //DESIGNER
#region  Vom Windows Form Designer generierter Code 

    // Für Windows Form-Designer erforderlich
    private System.ComponentModel.IContainer components;

    //HINWEIS: Die folgende Prozedur ist für den Windows Form-Designer erforderlich
    //Sie kann mit dem Windows Form-Designer modifiziert werden.
    //Verwenden Sie nicht den Code-Editor zur Bearbeitung.
    internal System.Windows.Forms.Button BtnClose;
    internal System.Windows.Forms.Label Label1;
    internal System.Windows.Forms.Label Label2;
    internal System.Windows.Forms.Label Label3;
    internal System.Windows.Forms.Label Label4;
    internal System.Windows.Forms.Label LblVersion;
    internal System.Windows.Forms.Label LblDate;
    internal System.Windows.Forms.Label Label7;
    internal System.Windows.Forms.Label Label9;
    internal System.Windows.Forms.PictureBox PictureBox1;
    internal System.Windows.Forms.Label Label5;
    internal System.Windows.Forms.LinkLabel LnkMail;
    internal System.Windows.Forms.LinkLabel LnkInternet;
    internal System.Windows.Forms.GroupBox GroupBox1;
    internal System.Windows.Forms.GroupBox GroupBox2;
    internal System.Windows.Forms.Label LblNewFeats;
    internal System.Windows.Forms.Label Label13;
    internal System.Windows.Forms.Label Label6;
    internal System.Windows.Forms.Label LblNewDate;
    internal System.Windows.Forms.Label Label10;
    internal System.Windows.Forms.Label LblNewVer;
    internal System.Windows.Forms.CheckBox ChkEnableUpdate;
    internal System.Windows.Forms.Button BtnUpdate;
    internal System.Windows.Forms.LinkLabel LnkForum;
    [System.Diagnostics.DebuggerStepThrough()]
    private void InitializeComponent()
    {
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmAbout));
      this.BtnClose = new System.Windows.Forms.Button();
      this.Label1 = new System.Windows.Forms.Label();
      this.Label2 = new System.Windows.Forms.Label();
      this.Label3 = new System.Windows.Forms.Label();
      this.Label4 = new System.Windows.Forms.Label();
      this.LblVersion = new System.Windows.Forms.Label();
      this.LblDate = new System.Windows.Forms.Label();
      this.Label7 = new System.Windows.Forms.Label();
      this.Label9 = new System.Windows.Forms.Label();
      this.PictureBox1 = new System.Windows.Forms.PictureBox();
      this.LnkMail = new System.Windows.Forms.LinkLabel();
      this.Label5 = new System.Windows.Forms.Label();
      this.LnkInternet = new System.Windows.Forms.LinkLabel();
      this.LnkForum = new System.Windows.Forms.LinkLabel();
      this.GroupBox1 = new System.Windows.Forms.GroupBox();
      this.GroupBox2 = new System.Windows.Forms.GroupBox();
      this.BtnUpdate = new System.Windows.Forms.Button();
      this.ChkEnableUpdate = new System.Windows.Forms.CheckBox();
      this.LblNewFeats = new System.Windows.Forms.Label();
      this.Label13 = new System.Windows.Forms.Label();
      this.Label6 = new System.Windows.Forms.Label();
      this.LblNewDate = new System.Windows.Forms.Label();
      this.Label10 = new System.Windows.Forms.Label();
      this.LblNewVer = new System.Windows.Forms.Label();
      ((System.ComponentModel.ISupportInitialize)this.PictureBox1).BeginInit();
      this.GroupBox1.SuspendLayout();
      this.GroupBox2.SuspendLayout();
      this.SuspendLayout();
      //
      //BtnClose
      //
      this.BtnClose.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
      this.BtnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
      this.BtnClose.Location = new System.Drawing.Point(192, 277);
      this.BtnClose.Name = "BtnClose";
      this.BtnClose.Size = new System.Drawing.Size(80, 23);
      this.BtnClose.TabIndex = 0;
      this.BtnClose.Text = "Close";
      //
      //Label1
      //
      this.Label1.Location = new System.Drawing.Point(6, 49);
      this.Label1.Name = "Label1";
      this.Label1.Size = new System.Drawing.Size(80, 16);
      this.Label1.TabIndex = 1;
      this.Label1.Text = "Author:";
      //
      //Label2
      //
      this.Label2.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.Label2.Location = new System.Drawing.Point(86, 49);
      this.Label2.Name = "Label2";
      this.Label2.Size = new System.Drawing.Size(303, 16);
      this.Label2.TabIndex = 2;
      this.Label2.Text = "Deniz Esen, Econ Dimension GmbH";
      //
      //Label3
      //
      this.Label3.Location = new System.Drawing.Point(6, 81);
      this.Label3.Name = "Label3";
      this.Label3.Size = new System.Drawing.Size(80, 16);
      this.Label3.TabIndex = 3;
      this.Label3.Text = "Internet:";
      //
      //Label4
      //
      this.Label4.Location = new System.Drawing.Point(6, 17);
      this.Label4.Name = "Label4";
      this.Label4.Size = new System.Drawing.Size(80, 16);
      this.Label4.TabIndex = 5;
      this.Label4.Text = "Version:";
      //
      //LblVersion
      //
      this.LblVersion.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LblVersion.Location = new System.Drawing.Point(86, 17);
      this.LblVersion.Name = "LblVersion";
      this.LblVersion.Size = new System.Drawing.Size(303, 16);
      this.LblVersion.TabIndex = 6;
      this.LblVersion.Text = "-";
      //
      //LblDate
      //
      this.LblDate.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LblDate.Location = new System.Drawing.Point(86, 33);
      this.LblDate.Name = "LblDate";
      this.LblDate.Size = new System.Drawing.Size(303, 16);
      this.LblDate.TabIndex = 9;
      this.LblDate.Text = "-";
      //
      //Label7
      //
      this.Label7.Location = new System.Drawing.Point(6, 33);
      this.Label7.Name = "Label7";
      this.Label7.Size = new System.Drawing.Size(80, 16);
      this.Label7.TabIndex = 8;
      this.Label7.Text = "Date:";
      //
      //Label9
      //
      this.Label9.Location = new System.Drawing.Point(6, 65);
      this.Label9.Name = "Label9";
      this.Label9.Size = new System.Drawing.Size(80, 16);
      this.Label9.TabIndex = 10;
      this.Label9.Text = "E-Mail:";
      //
      //PictureBox1
      //
      this.PictureBox1.Image = (System.Drawing.Image)resources.GetObject("PictureBox1.Image");
      this.PictureBox1.Location = new System.Drawing.Point(8, 8);
      this.PictureBox1.Name = "PictureBox1";
      this.PictureBox1.Size = new System.Drawing.Size(36, 36);
      this.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
      this.PictureBox1.TabIndex = 12;
      this.PictureBox1.TabStop = false;
      //
      //LnkMail
      //
      this.LnkMail.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LnkMail.Location = new System.Drawing.Point(86, 65);
      this.LnkMail.Name = "LnkMail";
      this.LnkMail.Size = new System.Drawing.Size(303, 16);
      this.LnkMail.TabIndex = 13;
      this.LnkMail.TabStop = true;
      this.LnkMail.Text = "d.esen@econdimension.com";
      //
      //Label5
      //
      this.Label5.Location = new System.Drawing.Point(6, 97);
      this.Label5.Name = "Label5";
      this.Label5.Size = new System.Drawing.Size(80, 16);
      this.Label5.TabIndex = 3;
      this.Label5.Text = "Online-Forum:";
      //
      //LnkInternet
      //
      this.LnkInternet.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LnkInternet.Location = new System.Drawing.Point(86, 81);
      this.LnkInternet.Name = "LnkInternet";
      this.LnkInternet.Size = new System.Drawing.Size(303, 16);
      this.LnkInternet.TabIndex = 13;
      this.LnkInternet.TabStop = true;
      this.LnkInternet.Text = "www.econdimension.com";
      //
      //LnkForum
      //
      this.LnkForum.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LnkForum.Location = new System.Drawing.Point(86, 97);
      this.LnkForum.Name = "LnkForum";
      this.LnkForum.Size = new System.Drawing.Size(303, 16);
      this.LnkForum.TabIndex = 13;
      this.LnkForum.TabStop = true;
      this.LnkForum.Text = "www.econdimension.com/devcenter_en/dev_forum.aspx";
      //
      //GroupBox1
      //
      this.GroupBox1.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.GroupBox1.Controls.Add(this.LnkMail);
      this.GroupBox1.Controls.Add(this.Label4);
      this.GroupBox1.Controls.Add(this.LnkForum);
      this.GroupBox1.Controls.Add(this.Label9);
      this.GroupBox1.Controls.Add(this.LnkInternet);
      this.GroupBox1.Controls.Add(this.LblDate);
      this.GroupBox1.Controls.Add(this.Label5);
      this.GroupBox1.Controls.Add(this.Label7);
      this.GroupBox1.Controls.Add(this.Label1);
      this.GroupBox1.Controls.Add(this.LblVersion);
      this.GroupBox1.Controls.Add(this.Label2);
      this.GroupBox1.Controls.Add(this.Label3);
      this.GroupBox1.Location = new System.Drawing.Point(59, 8);
      this.GroupBox1.Name = "GroupBox1";
      this.GroupBox1.Size = new System.Drawing.Size(395, 126);
      this.GroupBox1.TabIndex = 14;
      this.GroupBox1.TabStop = false;
      this.GroupBox1.Text = "Current Version";
      //
      //GroupBox2
      //
      this.GroupBox2.Anchor = (System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.GroupBox2.Controls.Add(this.BtnUpdate);
      this.GroupBox2.Controls.Add(this.ChkEnableUpdate);
      this.GroupBox2.Controls.Add(this.LblNewFeats);
      this.GroupBox2.Controls.Add(this.Label13);
      this.GroupBox2.Controls.Add(this.Label6);
      this.GroupBox2.Controls.Add(this.LblNewDate);
      this.GroupBox2.Controls.Add(this.Label10);
      this.GroupBox2.Controls.Add(this.LblNewVer);
      this.GroupBox2.Location = new System.Drawing.Point(59, 141);
      this.GroupBox2.Name = "GroupBox2";
      this.GroupBox2.Size = new System.Drawing.Size(395, 130);
      this.GroupBox2.TabIndex = 15;
      this.GroupBox2.TabStop = false;
      this.GroupBox2.Text = "Newest available Version";
      //
      //BtnUpdate
      //
      this.BtnUpdate.Location = new System.Drawing.Point(280, 21);
      this.BtnUpdate.Name = "BtnUpdate";
      this.BtnUpdate.Size = new System.Drawing.Size(108, 23);
      this.BtnUpdate.TabIndex = 17;
      this.BtnUpdate.Text = "Update now";
      this.BtnUpdate.UseVisualStyleBackColor = true;
      this.BtnUpdate.Visible = false;
      //
      //ChkEnableUpdate
      //
      this.ChkEnableUpdate.AutoSize = true;
      this.ChkEnableUpdate.Location = new System.Drawing.Point(9, 20);
      this.ChkEnableUpdate.Name = "ChkEnableUpdate";
      this.ChkEnableUpdate.Size = new System.Drawing.Size(223, 17);
      this.ChkEnableUpdate.TabIndex = 16;
      this.ChkEnableUpdate.Text = "Enable Automatic Update on new Version";
      this.ChkEnableUpdate.UseVisualStyleBackColor = true;
      //
      //LblNewFeats
      //
      this.LblNewFeats.Anchor = (System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LblNewFeats.Location = new System.Drawing.Point(86, 72);
      this.LblNewFeats.Name = "LblNewFeats";
      this.LblNewFeats.Size = new System.Drawing.Size(303, 55);
      this.LblNewFeats.TabIndex = 15;
      this.LblNewFeats.Text = "-";
      //
      //Label13
      //
      this.Label13.Location = new System.Drawing.Point(6, 72);
      this.Label13.Name = "Label13";
      this.Label13.Size = new System.Drawing.Size(80, 16);
      this.Label13.TabIndex = 14;
      this.Label13.Text = "New Features:";
      //
      //Label6
      //
      this.Label6.Location = new System.Drawing.Point(6, 40);
      this.Label6.Name = "Label6";
      this.Label6.Size = new System.Drawing.Size(80, 16);
      this.Label6.TabIndex = 10;
      this.Label6.Text = "Version:";
      //
      //LblNewDate
      //
      this.LblNewDate.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LblNewDate.Location = new System.Drawing.Point(86, 56);
      this.LblNewDate.Name = "LblNewDate";
      this.LblNewDate.Size = new System.Drawing.Size(303, 16);
      this.LblNewDate.TabIndex = 13;
      this.LblNewDate.Text = "-";
      //
      //Label10
      //
      this.Label10.Location = new System.Drawing.Point(6, 56);
      this.Label10.Name = "Label10";
      this.Label10.Size = new System.Drawing.Size(80, 16);
      this.Label10.TabIndex = 12;
      this.Label10.Text = "Date:";
      //
      //LblNewVer
      //
      this.LblNewVer.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.LblNewVer.Location = new System.Drawing.Point(86, 40);
      this.LblNewVer.Name = "LblNewVer";
      this.LblNewVer.Size = new System.Drawing.Size(303, 16);
      this.LblNewVer.TabIndex = 11;
      this.LblNewVer.Text = "?";
      //
      //FrmAbout
      //
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 14);
      this.ClientSize = new System.Drawing.Size(466, 311);
      this.Controls.Add(this.GroupBox2);
      this.Controls.Add(this.PictureBox1);
      this.Controls.Add(this.BtnClose);
      this.Controls.Add(this.GroupBox1);
      this.Font = new System.Drawing.Font("Tahoma", 8.25f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (byte)0);
      this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
      this.Name = "FrmAbout";
      this.ShowInTaskbar = false;
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
      this.Text = "About Econ NetVert";
      ((System.ComponentModel.ISupportInitialize)this.PictureBox1).EndInit();
      this.GroupBox1.ResumeLayout(false);
      this.GroupBox2.ResumeLayout(false);
      this.GroupBox2.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

#endregion

    //PRIVATE
    private void RefreshNewestVersion()
    {
      if (FUpdater.NewestVersion != "0") {
        LblNewVer.Text = FUpdater.NewestVersion;
        LblNewDate.Text = FUpdater.ReleaseDate.ToShortDateString;
        if (FUpdater.NewFeatures == "") {
          LblNewFeats.Text = "(not spezified)";
        } else {
          LblNewFeats.Text = FUpdater.NewFeatures;
        }
      }
      BtnUpdate.Visible = FUpdater.NewerVersionAvailable;
    }

    private void Updater_ApplicationUpdateResponse(object sender, Econ.Updater.ApplicationUpdateEventArgs e)
    {
      RefreshNewestVersion();
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnClose_Click(System.Object sender, System.EventArgs e)
    {
      this.Close();
    }

    private void  // ERROR: Handles clauses are not supported in C#
LnkMail_LinkClicked(System.Object sender, System.Windows.Forms.LinkLabelLinkClickedEventArgs e)
    {
      System.Diagnostics.Process.Start("mailto:" + LnkMail.Text);
    }

    private void  // ERROR: Handles clauses are not supported in C#
LnkInternet_LinkClicked(System.Object sender, System.Windows.Forms.LinkLabelLinkClickedEventArgs e)
    {
      System.Diagnostics.Process.Start("http://" + LnkInternet.Text);
    }

    private void  // ERROR: Handles clauses are not supported in C#
LnkForum_LinkClicked(System.Object sender, System.Windows.Forms.LinkLabelLinkClickedEventArgs e)
    {
      System.Diagnostics.Process.Start("http://" + LnkForum.Text);
    }

    private void  // ERROR: Handles clauses are not supported in C#
ChkEnableUpdate_CheckedChanged(System.Object sender, System.EventArgs e)
    {
      SettingsManager.AutoUpdateOnNewVersion = ChkEnableUpdate.Checked;
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnUpdate_Click(System.Object sender, System.EventArgs e)
    {
      FUpdater.ExecuteUpdateProcess(false);
    }

  }
}

