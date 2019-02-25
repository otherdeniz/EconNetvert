using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.Netvert.Gui
{
  [Microsoft.VisualBasic.CompilerServices.DesignerGenerated()]
  partial class FrmStatus : System.Windows.Forms.Form
  {
    //Form overrides dispose to clean up the component list.
    [System.Diagnostics.DebuggerNonUserCode()]
    protected override void Dispose(bool disposing)
    {
      if (disposing && components != null) {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    //Required by the Windows Form Designer
    private System.ComponentModel.IContainer components;

    //NOTE: The following procedure is required by the Windows Form Designer
    //It can be modified using the Windows Form Designer.  
    //Do not modify it using the code editor.
    [System.Diagnostics.DebuggerStepThrough()]
    private void InitializeComponent()
    {
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmStatus));
      this.BtnCancel = new System.Windows.Forms.Button();
      this.TxtStatus = new System.Windows.Forms.TextBox();
      this.Panel1 = new System.Windows.Forms.Panel();
      this.BtnRestart = new System.Windows.Forms.Button();
      this.ChkAutoClose = new System.Windows.Forms.CheckBox();
      this.Panel1.SuspendLayout();
      this.SuspendLayout();
      //
      //BtnCancel
      //
      this.BtnCancel.Anchor = (System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
      this.BtnCancel.Location = new System.Drawing.Point(452, 9);
      this.BtnCancel.Name = "BtnCancel";
      this.BtnCancel.Size = new System.Drawing.Size(75, 23);
      this.BtnCancel.TabIndex = 2;
      this.BtnCancel.Text = "Cancel";
      this.BtnCancel.UseVisualStyleBackColor = true;
      //
      //TxtStatus
      //
      this.TxtStatus.Dock = System.Windows.Forms.DockStyle.Fill;
      this.TxtStatus.Location = new System.Drawing.Point(8, 8);
      this.TxtStatus.MaxLength = 2000000;
      this.TxtStatus.Multiline = true;
      this.TxtStatus.Name = "TxtStatus";
      this.TxtStatus.ReadOnly = true;
      this.TxtStatus.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.TxtStatus.Size = new System.Drawing.Size(526, 368);
      this.TxtStatus.TabIndex = 0;
      //
      //Panel1
      //
      this.Panel1.Controls.Add(this.BtnRestart);
      this.Panel1.Controls.Add(this.ChkAutoClose);
      this.Panel1.Controls.Add(this.BtnCancel);
      this.Panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.Panel1.Location = new System.Drawing.Point(8, 376);
      this.Panel1.Name = "Panel1";
      this.Panel1.Size = new System.Drawing.Size(526, 32);
      this.Panel1.TabIndex = 1;
      //
      //BtnRestart
      //
      this.BtnRestart.Anchor = (System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
      this.BtnRestart.Location = new System.Drawing.Point(371, 9);
      this.BtnRestart.Name = "BtnRestart";
      this.BtnRestart.Size = new System.Drawing.Size(75, 23);
      this.BtnRestart.TabIndex = 1;
      this.BtnRestart.Text = "Restart";
      this.BtnRestart.UseVisualStyleBackColor = true;
      this.BtnRestart.Visible = false;
      //
      //ChkAutoClose
      //
      this.ChkAutoClose.AutoSize = true;
      this.ChkAutoClose.Location = new System.Drawing.Point(3, 12);
      this.ChkAutoClose.Name = "ChkAutoClose";
      this.ChkAutoClose.Size = new System.Drawing.Size(130, 17);
      this.ChkAutoClose.TabIndex = 0;
      this.ChkAutoClose.Text = "Autoclose on success";
      this.ChkAutoClose.UseVisualStyleBackColor = true;
      //
      //FrmStatus
      //
      this.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(542, 416);
      this.Controls.Add(this.TxtStatus);
      this.Controls.Add(this.Panel1);
      this.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
      this.Name = "FrmStatus";
      this.Padding = new System.Windows.Forms.Padding(8);
      this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "Econ NetVert";
      this.Panel1.ResumeLayout(false);
      this.Panel1.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }
    internal System.Windows.Forms.Button BtnCancel;
    internal System.Windows.Forms.TextBox TxtStatus;
    internal System.Windows.Forms.Panel Panel1;
    internal System.Windows.Forms.CheckBox ChkAutoClose;
    internal System.Windows.Forms.Button BtnRestart;
  }
}

