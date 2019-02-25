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
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;
#if (Win32Only)
//BEGIN Win32 Only
#region SerialHelper CLASS
namespace Econ.Netvert.Gui
{
  public class SerialHelper
  {
    public static string SerializeToBase64String(object o)
    {
      BinaryFormatter formatter = new BinaryFormatter();
      MemoryStream serialMemoryStream = new MemoryStream();
      formatter.Serialize(serialMemoryStream, o);
      byte[] bytes = serialMemoryStream.ToArray();
      return Convert.ToBase64String(bytes).Trim();
    }

    public static object DeserializeFromBase64String(string base64String)
    {
      BinaryFormatter formatter = new BinaryFormatter();
      base64String = base64String.Trim(ControlChars.NullChar);
      byte[] bytes = Convert.FromBase64String(base64String);
      MemoryStream serialMemoryStream = new MemoryStream(bytes);
      return formatter.Deserialize(serialMemoryStream);
    }
  }

#endregion

  //--------------------------------------------------------------------

#region SingleInstance CLASS

  public class SingleInstance
  {
    public interface ISingleInstanceForm
    {
      delegate void _WndProc(Message m, ref bool Cancel);
      event _WndProc WndProc;
      IntPtr Handle { get; }
      void HandleCommand(string strCmd);
      void SetToForeground();
    }
#region API
    private const int WM_COPYDATA = 0x4a;

    [StructLayout(LayoutKind.Sequential)]
    private struct COPYDATASTRUCT
    {
      public int dwData;
      public int cbData;
      public int lpData;
    }

 // ERROR: Not supported in C#: DeclareDeclaration
 // ERROR: Not supported in C#: DeclareDeclaration

    private delegate int EnumWindowsProc(int hWnd, int lParam);
 // ERROR: Not supported in C#: DeclareDeclaration

 // ERROR: Not supported in C#: DeclareDeclaration
#endregion

#region EnumWindows
    private static EnumWindowsProc _EWP = new EnumWindowsProc(EWP);
    private static int EWP(int hWnd, int lParam)
    {
      // Customised windows enumeration procedure.  Stops
      // when it finds another application with the Window
      // property set, or when all windows are exhausted.
      try {
        if (IsThisApp(hWnd)) {
          _hWnd = hWnd;
          return 0;
        } else {
          return 1;
        }
      } catch {
        return 0;
      }
    }
    private static bool IsThisApp(long hWnd)
    {
      // Check if the windows property is set for this
      // window handle:
      if (GetProp(hWnd, _mcThisAppID + "_APPLICATION") == 1) {
        return true;
      }
    }

    private static bool FindWindow()
    {
      if (_hWnd == -1) {
        EnumWindows(_EWP, 0);
        if (_hWnd == -1) {
          return false;
        } else {
          return true;
        }
      } else {
        return true;
      }
    }

    private static bool SendCDSToWindow(COPYDATASTRUCT CD)
    {
      try {
        IntPtr lpCD = Marshal.AllocHGlobal(Len(CD));
        Marshal.StructureToPtr(CD, lpCD, false);
        SendMessage(_hWnd, WM_COPYDATA, _hWnd, lpCD);
        Marshal.FreeHGlobal(lpCD);

        return true;
      } catch {
        return false;
      }
    }

    private static bool SendMessageToWindow(string strCmd)
    {
      if (_hWnd == -1)
        return false;
      if (Len(strCmd) == 0) {
        try {
          COPYDATASTRUCT CD;
           // ERROR: Not supported in C#: WithStatement

          return SendCDSToWindow(CD);
        } catch {
          return false;
        }
      } else {
        try {
          byte[] B = Encoding.Default.GetBytes(strCmd);
          IntPtr lpB = Marshal.AllocHGlobal(B.Length);
          Marshal.Copy(B, 0, lpB, B.Length);

          COPYDATASTRUCT CD;
           // ERROR: Not supported in C#: WithStatement

          B = null;

          try {
            if (SendCDSToWindow(CD)) {
              return true;
            } else {
              return false;
            }
          } catch {
            return false;
          } finally {
            Marshal.FreeHGlobal(lpB);
          }

        } catch {
          return false;
        }
      }
    }
    private static bool SendMessageToWindow(object oCmd)
    {
      try {
        string strCmd = SerialHelper.SerializeToBase64String(oCmd);
        return SendMessageToWindow(strCmd);
      } catch {
        return false;
      }
    }
#endregion

    private static int _hWnd = -1;
    private static string _mcThisAppID;
    private static Threading.Mutex oMutex;
    private static bool _MutexOwned = false;
    private static ISingleInstanceForm MainForm;

    static SingleInstance()
    {
      _mcThisAppID = System.Reflection.Assembly.GetExecutingAssembly().FullName;
      oMutex = new Threading.Mutex(true, _mcThisAppID + "_APPLICATION_MUTEX", _MutexOwned);
      if (!_MutexOwned) {
        //modified DE
        //try to find window for 5 secs
        _MutexOwned = true;
        System.DateTime TmpStart = Now;
        do {
          if (FindWindow()) {
            //another window found
            _MutexOwned = false;
            break; // TODO: might not be correct. Was : Exit Do
          }
          Threading.Thread.Sleep(250);
        } while ((DateDiff(DateInterval.Second, DateAdd(DateInterval.Second, 5, TmpStart), Now) < 0));
      }
      AppDomain.CurrentDomain.ProcessExit += OnExit;
    }
    private static void OnExit(object sender, EventArgs e)
    {
      try {
        if (!oMutex == null) {
          oMutex.ReleaseMutex();
          ((IDisposable)oMutex).Dispose();
          oMutex = null;
        }
      } catch {
        //Do Nothing
      }
    }

    public static bool IsFirstInstance {
      get { return _MutexOwned; }
    }

    public static bool NotifyPreviousWindow()
    {
      return SendMessageToWindow("");
    }
    public static bool NotifyPreviousWindow(string strText)
    {
      return SendMessageToWindow(strText);
    }
    public static bool NotifyPreviousWindow(object oCmd)
    {
      return SendMessageToWindow(oCmd);
    }

    public static void SetMainForm(ISingleInstanceForm frm)
    {
      MainForm = frm;
      try {
        int hWnd = frm.Handle.ToInt32;
        SetProp(hWnd, _mcThisAppID + "_APPLICATION", 1);
      } catch {
        MainForm = null;
      }
    }

    private static void  // ERROR: Handles clauses are not supported in C#
MainForm_WndProc(System.Windows.Forms.Message m, ref bool Cancel)
    {
      switch (m.Msg) {
        case WM_COPYDATA:
          byte[] B;
          try {
            COPYDATASTRUCT CD = m.GetLParam(typeof(COPYDATASTRUCT));
             // ERROR: Not supported in C#: ReDimStatement

            IntPtr lpData = new IntPtr(CD.lpData);
            Marshal.Copy(lpData, B, 0, CD.cbData);
            string strData = Encoding.Default.GetString(B);
            MainForm.HandleCommand(strData);
            MainForm.SetToForeground();
            Cancel = true;
          } catch {
            Cancel = false;
          } finally {
            B = null;
          }


        default:
          Cancel = false;
      }
    }
  }

#endregion

  //END Win32 Only
#Else
  //BEGIN NO-Win32

  public class SingleInstance
  {
    public interface ISingleInstanceForm
    {
      void HandleCommand(string strCmd);
    }

    //PUBLIC SHARED
    public static bool IsFirstInstance {
      get { return true; }
    }

    public static void SetMainForm(ISingleInstanceForm frm)
    {
      //nothing to do
    }

    public static bool NotifyPreviousWindow()
    {
      return true;
    }

    public static bool NotifyPreviousWindow(string strText)
    {
      return true;
    }

    public static bool NotifyPreviousWindow(object oCmd)
    {
      return true;
    }

  }

  //END NO-Win32
#endif
}

