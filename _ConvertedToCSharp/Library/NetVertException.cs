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
namespace Econ.NetVert
{
  internal class NetVertException : Exception
  {
    //CONSTRUCTOR
    public NetVertException(string message)
    {
      base.New(message);
    }

    //PUBLIC
#region PUBLIC Properties

    public override string Message {
      get { return base.Message; }
    }

#endregion

  }
}

