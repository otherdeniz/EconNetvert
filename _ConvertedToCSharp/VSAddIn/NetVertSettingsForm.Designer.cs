using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.NetVert.VSAddIn
{
  [Microsoft.VisualBasic.CompilerServices.DesignerGenerated()]
  partial class NetVertSettingsForm : System.Windows.Forms.Form
  {
    //Form overrides dispose to clean up the component list.
    [System.Diagnostics.DebuggerNonUserCode()]
    protected override void Dispose(bool disposing)
    {
      try {
        if (disposing && components != null) {
          components.Dispose();
        }
      } finally {
        base.Dispose(disposing);
      }
    }

    //Required by the Windows Form Designer
    private System.ComponentModel.IContainer components;

    //NOTE: The following procedure is required by the Windows Form Designer
    //It can be modified using the Windows Form Designer.  
    //Do not modify it using the code editor.
    [System.Diagnostics.DebuggerStepThrough()]
    private void InitializeComponent()
    {
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(NetVertSettingsForm));
      this.Panel1 = new System.Windows.Forms.Panel();
      this.GroupBox1 = new System.Windows.Forms.GroupBox();
      this.LblVersion = new System.Windows.Forms.Label();
      this.BtnClose = new System.Windows.Forms.Button();
      this.Panel2 = new System.Windows.Forms.Panel();
      this.Label2 = new System.Windows.Forms.Label();
      this.CmbConverter = new System.Windows.Forms.ComboBox();
      this.Label1 = new System.Windows.Forms.Label();
      this.NetVertSettings = new Econ.NetVert.VSAddIn.NetVertSettingsControl();
      this.Panel1.SuspendLayout();
      this.Panel2.SuspendLayout();
      this.SuspendLayout();
      //
      //Panel1
      //
      this.Panel1.Controls.Add(this.GroupBox1);
      this.Panel1.Controls.Add(this.LblVersion);
      this.Panel1.Controls.Add(this.BtnClose);
      this.Panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.Panel1.Location = new System.Drawing.Point(8, 188);
      this.Panel1.Name = "Panel1";
      this.Panel1.Size = new System.Drawing.Size(451, 37);
      this.Panel1.TabIndex = 1;
      //
      //GroupBox1
      //
      this.GroupBox1.Location = new System.Drawing.Point(0, 0);
      this.GroupBox1.Name = "GroupBox1";
      this.GroupBox1.Size = new System.Drawing.Size(451, 8);
      this.GroupBox1.TabIndex = 3;
      this.GroupBox1.TabStop = false;
      //
      //LblVersion
      //
      this.LblVersion.AutoSize = true;
      this.LblVersion.ForeColor = System.Drawing.SystemColors.ControlDark;
      this.LblVersion.Location = new System.Drawing.Point(3, 15);
      this.LblVersion.Name = "LblVersion";
      this.LblVersion.Size = new System.Drawing.Size(117, 13);
      this.LblVersion.TabIndex = 2;
      this.LblVersion.Text = "Econ NetVert vX.X.X.X";
      //
      //BtnClose
      //
      this.BtnClose.Anchor = (System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
      this.BtnClose.Location = new System.Drawing.Point(373, 10);
      this.BtnClose.Name = "BtnClose";
      this.BtnClose.Size = new System.Drawing.Size(75, 23);
      this.BtnClose.TabIndex = 1;
      this.BtnClose.Text = "Close";
      this.BtnClose.UseVisualStyleBackColor = true;
      //
      //Panel2
      //
      this.Panel2.Controls.Add(this.Label2);
      this.Panel2.Controls.Add(this.CmbConverter);
      this.Panel2.Controls.Add(this.Label1);
      this.Panel2.Dock = System.Windows.Forms.DockStyle.Top;
      this.Panel2.Location = new System.Drawing.Point(8, 8);
      this.Panel2.Name = "Panel2";
      this.Panel2.Size = new System.Drawing.Size(451, 28);
      this.Panel2.TabIndex = 2;
      //
      //Label2
      //
      this.Label2.AutoSize = true;
      this.Label2.ForeColor = System.Drawing.SystemColors.ControlDark;
      this.Label2.Location = new System.Drawing.Point(245, 3);
      this.Label2.Name = "Label2";
      this.Label2.Size = new System.Drawing.Size(171, 13);
      this.Label2.TabIndex = 2;
      this.Label2.Text = "(This Setting applies to all Projects)";
      //
      //CmbConverter
      //
      this.CmbConverter.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
      this.CmbConverter.FormattingEnabled = true;
      this.CmbConverter.Items.AddRange(new object[] {
        "ICSharpCode 1.1",
        "ICSharpCode 2.1",
        "NRefactory WebService"
      });
      this.CmbConverter.Location = new System.Drawing.Point(93, 0);
      this.CmbConverter.Name = "CmbConverter";
      this.CmbConverter.Size = new System.Drawing.Size(145, 21);
      this.CmbConverter.TabIndex = 1;
      //
      //Label1
      //
      this.Label1.AutoSize = true;
      this.Label1.Location = new System.Drawing.Point(3, 3);
      this.Label1.Name = "Label1";
      this.Label1.Size = new System.Drawing.Size(53, 13);
      this.Label1.TabIndex = 0;
      this.Label1.Text = "Converter";
      //
      //NetVertSettings
      //
      this.NetVertSettings.Dock = System.Windows.Forms.DockStyle.Fill;
      this.NetVertSettings.Location = new System.Drawing.Point(8, 36);
      this.NetVertSettings.MinimumSize = new System.Drawing.Size(200, 100);
      this.NetVertSettings.Name = "NetVertSettings";
      this.NetVertSettings.Size = new System.Drawing.Size(451, 152);
      this.NetVertSettings.TabIndex = 0;
      //
      //NetVertSettingsForm
      //
      this.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(467, 233);
      this.Controls.Add(this.NetVertSettings);
      this.Controls.Add(this.Panel2);
      this.Controls.Add(this.Panel1);
      this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
      this.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "NetVertSettingsForm";
      this.Padding = new System.Windows.Forms.Padding(8);
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "Econ NetVert Settings";
      this.Panel1.ResumeLayout(false);
      this.Panel1.PerformLayout();
      this.Panel2.ResumeLayout(false);
      this.Panel2.PerformLayout();
      this.ResumeLayout(false);

    }
    internal Econ.NetVert.VSAddIn.NetVertSettingsControl NetVertSettings;
    internal System.Windows.Forms.Panel Panel1;
    internal System.Windows.Forms.Button BtnClose;
    internal System.Windows.Forms.Label LblVersion;
    internal System.Windows.Forms.Panel Panel2;
    internal System.Windows.Forms.ComboBox CmbConverter;
    internal System.Windows.Forms.Label Label1;
    internal System.Windows.Forms.GroupBox GroupBox1;
    internal System.Windows.Forms.Label Label2;
  }
}

