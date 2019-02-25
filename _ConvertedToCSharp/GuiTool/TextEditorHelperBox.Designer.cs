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
  partial class TextEditorHelperBox : System.Windows.Forms.UserControl
  {
    //UserControl overrides dispose to clean up the component list.
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
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TextEditorHelperBox));
      this.Label1 = new System.Windows.Forms.Label();
      this.PnlSearch = new System.Windows.Forms.Panel();
      this.TxtSearch = new System.Windows.Forms.TextBox();
      this.PnlGotoLine = new System.Windows.Forms.Panel();
      this.TxtGotoLine = new System.Windows.Forms.TextBox();
      this.Label2 = new System.Windows.Forms.Label();
      this.BtnLast = new System.Windows.Forms.Button();
      this.BtnFirst = new System.Windows.Forms.Button();
      this.BtnGotoLine = new System.Windows.Forms.Button();
      this.BtnSearch = new System.Windows.Forms.Button();
      this.PnlSearch.SuspendLayout();
      this.PnlGotoLine.SuspendLayout();
      this.SuspendLayout();
      //
      //Label1
      //
      this.Label1.Location = new System.Drawing.Point(0, 0);
      this.Label1.Name = "Label1";
      this.Label1.Size = new System.Drawing.Size(41, 20);
      this.Label1.TabIndex = 0;
      this.Label1.Text = "Search";
      this.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      //
      //PnlSearch
      //
      this.PnlSearch.Controls.Add(this.BtnSearch);
      this.PnlSearch.Controls.Add(this.TxtSearch);
      this.PnlSearch.Controls.Add(this.Label1);
      this.PnlSearch.Dock = System.Windows.Forms.DockStyle.Top;
      this.PnlSearch.Location = new System.Drawing.Point(0, 0);
      this.PnlSearch.Name = "PnlSearch";
      this.PnlSearch.Size = new System.Drawing.Size(328, 21);
      this.PnlSearch.TabIndex = 1;
      //
      //TxtSearch
      //
      this.TxtSearch.Anchor = (System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) | System.Windows.Forms.AnchorStyles.Right);
      this.TxtSearch.Location = new System.Drawing.Point(44, 0);
      this.TxtSearch.Name = "TxtSearch";
      this.TxtSearch.Size = new System.Drawing.Size(260, 20);
      this.TxtSearch.TabIndex = 1;
      //
      //PnlGotoLine
      //
      this.PnlGotoLine.Controls.Add(this.BtnLast);
      this.PnlGotoLine.Controls.Add(this.BtnFirst);
      this.PnlGotoLine.Controls.Add(this.BtnGotoLine);
      this.PnlGotoLine.Controls.Add(this.TxtGotoLine);
      this.PnlGotoLine.Controls.Add(this.Label2);
      this.PnlGotoLine.Dock = System.Windows.Forms.DockStyle.Top;
      this.PnlGotoLine.Location = new System.Drawing.Point(0, 21);
      this.PnlGotoLine.Name = "PnlGotoLine";
      this.PnlGotoLine.Size = new System.Drawing.Size(328, 21);
      this.PnlGotoLine.TabIndex = 2;
      this.PnlGotoLine.Visible = false;
      //
      //TxtGotoLine
      //
      this.TxtGotoLine.Location = new System.Drawing.Point(75, 0);
      this.TxtGotoLine.Name = "TxtGotoLine";
      this.TxtGotoLine.Size = new System.Drawing.Size(68, 20);
      this.TxtGotoLine.TabIndex = 1;
      //
      //Label2
      //
      this.Label2.Location = new System.Drawing.Point(0, 0);
      this.Label2.Name = "Label2";
      this.Label2.Size = new System.Drawing.Size(72, 20);
      this.Label2.TabIndex = 0;
      this.Label2.Text = "Line Number";
      this.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      //
      //BtnLast
      //
      this.BtnLast.Image = (System.Drawing.Image)resources.GetObject("BtnLast.Image");
      this.BtnLast.Location = new System.Drawing.Point(190, 0);
      this.BtnLast.Name = "BtnLast";
      this.BtnLast.Size = new System.Drawing.Size(20, 20);
      this.BtnLast.TabIndex = 4;
      this.BtnLast.TabStop = false;
      this.BtnLast.UseVisualStyleBackColor = true;
      //
      //BtnFirst
      //
      this.BtnFirst.Image = (System.Drawing.Image)resources.GetObject("BtnFirst.Image");
      this.BtnFirst.Location = new System.Drawing.Point(170, 0);
      this.BtnFirst.Name = "BtnFirst";
      this.BtnFirst.Size = new System.Drawing.Size(20, 20);
      this.BtnFirst.TabIndex = 3;
      this.BtnFirst.TabStop = false;
      this.BtnFirst.UseVisualStyleBackColor = true;
      //
      //BtnGotoLine
      //
      this.BtnGotoLine.Image = (System.Drawing.Image)resources.GetObject("BtnGotoLine.Image");
      this.BtnGotoLine.Location = new System.Drawing.Point(144, 0);
      this.BtnGotoLine.Name = "BtnGotoLine";
      this.BtnGotoLine.Size = new System.Drawing.Size(20, 20);
      this.BtnGotoLine.TabIndex = 2;
      this.BtnGotoLine.TabStop = false;
      this.BtnGotoLine.UseVisualStyleBackColor = true;
      //
      //BtnSearch
      //
      this.BtnSearch.Anchor = (System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
      this.BtnSearch.Image = (System.Drawing.Image)resources.GetObject("BtnSearch.Image");
      this.BtnSearch.Location = new System.Drawing.Point(305, 0);
      this.BtnSearch.Name = "BtnSearch";
      this.BtnSearch.Size = new System.Drawing.Size(20, 20);
      this.BtnSearch.TabIndex = 2;
      this.BtnSearch.TabStop = false;
      this.BtnSearch.UseVisualStyleBackColor = true;
      //
      //TextEditorHelperBox
      //
      this.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.Controls.Add(this.PnlGotoLine);
      this.Controls.Add(this.PnlSearch);
      this.Name = "TextEditorHelperBox";
      this.Size = new System.Drawing.Size(328, 74);
      this.PnlSearch.ResumeLayout(false);
      this.PnlSearch.PerformLayout();
      this.PnlGotoLine.ResumeLayout(false);
      this.PnlGotoLine.PerformLayout();
      this.ResumeLayout(false);

    }
    internal System.Windows.Forms.Label Label1;
    internal System.Windows.Forms.Panel PnlSearch;
    internal System.Windows.Forms.Button BtnSearch;
    internal System.Windows.Forms.TextBox TxtSearch;
    internal System.Windows.Forms.Panel PnlGotoLine;
    internal System.Windows.Forms.Button BtnGotoLine;
    internal System.Windows.Forms.TextBox TxtGotoLine;
    internal System.Windows.Forms.Label Label2;
    internal System.Windows.Forms.Button BtnLast;
    internal System.Windows.Forms.Button BtnFirst;

  }
}

