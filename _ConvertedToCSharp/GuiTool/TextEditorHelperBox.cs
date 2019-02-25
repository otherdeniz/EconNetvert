using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.Netvert.Gui
{
  public partial class TextEditorHelperBox
  {
    //DECLARATIONS
    private TextEditorHelperBoxTypes FBoxType = TextEditorHelperBoxTypes.SearchBox;
    private ICSharpCode.TextEditor.TextEditorControl FTextEditorControl;
    private bool FHandleKeys = false;

    //EVENTS

    //PUBLIC
#region PUBLIC Properties

    public TextEditorHelperBoxTypes TextEditorHelperBoxType {
      get { return FBoxType; }
      set {
        FBoxType = value;
        ApplyBoxType();
      }
    }

    public ICSharpCode.TextEditor.TextEditorControl TextEditorControl {
      get { return FTextEditorControl; }
      set { FTextEditorControl = value; }
    }

#endregion

    protected override void OnGotFocus(System.EventArgs e)
    {
      base.OnGotFocus(e);
      //set focus to input-box
      switch (FBoxType) {
        case TextEditorHelperBoxTypes.GotoLineBox:
          TxtGotoLine.Focus();
        case TextEditorHelperBoxTypes.SearchBox:
          TxtSearch.Focus();
      }
    }

    //PRIVATE
    private void ApplyBoxType()
    {
      PnlSearch.Visible = (FBoxType == TextEditorHelperBoxTypes.SearchBox);
      PnlGotoLine.Visible = (FBoxType == TextEditorHelperBoxTypes.GotoLineBox);
    }

#region Opeartion: SEARCH

    private void DoSearch()
    {
      if (TxtSearch.Text != "") {
        if (!DoSearch(TxtSearch.Text)) {
          //error-highlight
          TxtSearch.BackColor = Color.Red;
          TxtSearch.ForeColor = Color.White;
        }
      }
    }

    private bool DoSearch(string searchString)
    {
      Int32 TmpCurrentCursorPos;
      Int32 TmpNextCursorPos = -1;
      string TmpS;
      bool RetB = false;

      if (!FTextEditorControl == null) {
        TmpCurrentCursorPos = FTextEditorControl.ActiveTextAreaControl.Caret.Offset;
        TmpS = FTextEditorControl.Document.TextContent.ToLower;
        if (TmpS.Length > 0) {
          //search from cursor to end
          if (TmpS.Length > TmpCurrentCursorPos + 1) {
            TmpNextCursorPos = TmpS.IndexOf(searchString.ToLower, TmpCurrentCursorPos + 1);
          }
          if (TmpNextCursorPos == -1) {
            //search from beginning
            TmpNextCursorPos = TmpS.IndexOf(searchString.ToLower);
          }
          if (TmpNextCursorPos > -1) {
            //found, set cursor
             // ERROR: Not supported in C#: WithStatement

            //result ok
            RetB = true;
          }
        }
      }
      return RetB;
    }

#endregion

#region Operation: GOTO-Line

    private void DoGotoLine()
    {
      try {
        if (TxtGotoLine.Text != "") {
          TxtGotoLine.Text = DoGotoLine(Int32.Parse(TxtGotoLine.Text)).ToString;
        }
      } catch (Exception ex) {
        //error-highlight
        TxtGotoLine.BackColor = Color.Red;
        TxtGotoLine.ForeColor = Color.White;
      }
    }

    private Int32 DoGotoLine(Int32 lineNr)
    {
      if (!FTextEditorControl == null) {
        //check if line is to high, then take last line
        if (lineNr > FTextEditorControl.Document.TotalNumberOfLines) {
          lineNr = FTextEditorControl.Document.TotalNumberOfLines;
        }
        //set carret to line
        FTextEditorControl.ActiveTextAreaControl.Caret.Line = lineNr;
      }
      return lineNr;
    }

#endregion

#region GUI Events

    private void  // ERROR: Handles clauses are not supported in C#
TextEditorHelperBox_Resize(object sender, System.EventArgs e)
    {
      this.Height = PnlSearch.Height;
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnSearch_Click(System.Object sender, System.EventArgs e)
    {
      DoSearch();
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnGotoLine_Click(System.Object sender, System.EventArgs e)
    {
      DoGotoLine();
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtSearch_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      //reset error-highlight
      TxtSearch.BackColor = SystemColors.Window;
      TxtSearch.ForeColor = SystemColors.WindowText;
      //check pressed key
      switch (e.KeyCode) {
        case Keys.Enter:
          //ENTER
          DoSearch();
          e.Handled = true;
          FHandleKeys = true;
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtGotoLine_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      //reset error-highlight
      TxtGotoLine.BackColor = SystemColors.Window;
      TxtGotoLine.ForeColor = SystemColors.WindowText;
      //check pressed key
      switch (e.KeyCode) {
        case Keys.Enter:
          //ENTER
          DoGotoLine();
          e.Handled = true;
          FHandleKeys = true;
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtSearch_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
    {
      //prevent 'beep' on already handled keys
      if (FHandleKeys)
        e.Handled = true;
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtSearch_KeyUp(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      //prevent 'beep' on already handled keys
      if (FHandleKeys)
        e.Handled = true;
      FHandleKeys = false;
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtGotoLine_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
    {
      //prevent 'beep' on already handled keys
      if (FHandleKeys)
        e.Handled = true;
    }

    private void  // ERROR: Handles clauses are not supported in C#
TxtGotoLine_KeyUp(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      //prevent 'beep' on already handled keys
      if (FHandleKeys)
        e.Handled = true;
      FHandleKeys = false;
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnFirst_Click(System.Object sender, System.EventArgs e)
    {
      DoGotoLine(0);
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnLast_Click(System.Object sender, System.EventArgs e)
    {
      if (!FTextEditorControl == null) {
        DoGotoLine(FTextEditorControl.Document.TotalNumberOfLines);
      }
    }

#endregion

  }
}

