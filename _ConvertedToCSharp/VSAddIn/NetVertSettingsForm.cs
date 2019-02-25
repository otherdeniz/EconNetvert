using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
namespace Econ.NetVert.VSAddIn
{
  public partial class NetVertSettingsForm
  {
    //PRIVATE
    private void  // ERROR: Handles clauses are not supported in C#
NetVertSettingsForm_Load(object sender, System.EventArgs e)
    {
      //Current Version
       // ERROR: Not supported in C#: WithStatement

      //Converter
      switch (((object)SettingsManager.CurrentRefactoryProvider).GetType.FullName) {
        case typeof(RefactoryNet11Provider).FullName:
          CmbConverter.SelectedIndex = 0;
        case typeof(RefactoryNet20Provider).FullName:
          CmbConverter.SelectedIndex = 1;
        case typeof(RefactoryOnlineProvider).FullName:
          CmbConverter.SelectedIndex = 2;
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
CmbConverter_SelectedIndexChanged(System.Object sender, System.EventArgs e)
    {
      switch (CmbConverter.SelectedIndex) {
        case 0:
          SettingsManager.CurrentRefactoryProvider = RefactoryNet11Provider.Instance;
        case 1:
          SettingsManager.CurrentRefactoryProvider = RefactoryNet20Provider.Instance;
        case 2:
          SettingsManager.CurrentRefactoryProvider = RefactoryOnlineProvider.Instance;
      }
    }

    private void  // ERROR: Handles clauses are not supported in C#
BtnClose_Click(System.Object sender, System.EventArgs e)
    {
      this.Close();
    }

  }
}

