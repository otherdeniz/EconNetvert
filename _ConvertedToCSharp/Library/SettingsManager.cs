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
using Microsoft.Win32;
namespace Econ.NetVert
{
  public sealed class SettingsManager
  {
    //CONST
    private const string cRegistryPath = "SOFTWARE\\Econ Dimension\\NetVert";

    //DECLARATIONS
    private static bool FSettingsLoaded = false;
    private static IRefactoryProvider FCurrentRefactoryProvider;
    private static bool FAutoCloseStatusDialogs = false;
    private static bool FAutoUpdateOnNewVersion = true;

    //CONSTRUCTOR
    private SettingsManager()
    {
    }

    //SHARED
#region SHARED Properties

    public static IRefactoryProvider CurrentRefactoryProvider {
      get {
        if (!FSettingsLoaded)
          LoadSettings();
        return FCurrentRefactoryProvider;
      }
      set {
        if (value == null) {
          throw new NoNullAllowedException();
        }
        if (!object.ReferenceEquals(value, FCurrentRefactoryProvider)) {
          FCurrentRefactoryProvider = value;
          SaveSettings();
        }
      }
    }

    public static bool AutoCloseStatusDialogs {
      get {
        if (!FSettingsLoaded)
          LoadSettings();
        return FAutoCloseStatusDialogs;
      }
      set {
        if (!value == FAutoCloseStatusDialogs) {
          FAutoCloseStatusDialogs = value;
          SaveSettings();
        }
      }
    }

    public static bool AutoUpdateOnNewVersion {
      get {
        if (!FSettingsLoaded)
          LoadSettings();
        return FAutoUpdateOnNewVersion;
      }
      set {
        if (!value == FAutoUpdateOnNewVersion) {
          FAutoUpdateOnNewVersion = value;
          SaveSettings();
        }
      }
    }

#endregion

    //PRIVATE SHARED
    private static void LoadSettings()
    {
      RegistryKey TmpKey;
      RegistryKey TmpRegRoot;
      string TmpS;

      try {
        //get the Registry-Key
        TmpRegRoot = RegistryKey.OpenRemoteBaseKey(RegistryHive.CurrentUser, "");
        TmpKey = TmpRegRoot.OpenSubKey(cRegistryPath, true);
        if (!TmpKey == null) {
          //Key exists
          //load FCurrentRefactoryProvider
          TmpS = TmpKey.GetValue("CurrentRefactoryProvider", "");
          if (TmpS != "") {
            FCurrentRefactoryProvider = Activator.CreateInstance(Type.GetType(TmpS));
          }
          //load FAutoCloseStatusDialogs
          TmpS = TmpKey.GetValue("AutoCloseStatusDialogs", "0");
          FAutoCloseStatusDialogs = (TmpS == "1");
          //load FAutoUpdateOnNewVersion
          TmpS = TmpKey.GetValue("AutoUpdateOnNewVersion", "1");
          FAutoUpdateOnNewVersion = (TmpS == "1");
          //close Key
          TmpKey.Close();
        }
        //close Registry
        TmpRegRoot.Close();
      } catch (Exception ex) {
      }
      //load default FCurrentRefactoryProvider
      if (FCurrentRefactoryProvider == null) {
        FCurrentRefactoryProvider = RefactoryNet20Provider.Instance;
      }
      //settings loaded ok
      FSettingsLoaded = true;
    }

    private static void SaveSettings()
    {
      RegistryKey TmpKey;
      RegistryKey TmpRegRoot;

      try {
        //get the Registry-Key
        TmpRegRoot = RegistryKey.OpenRemoteBaseKey(RegistryHive.CurrentUser, "");
        TmpKey = TmpRegRoot.OpenSubKey(cRegistryPath, true);
        if (TmpKey == null) {
          //Key not exists, create
          TmpKey = TmpRegRoot.CreateSubKey(cRegistryPath);
        }
        //save FCurrentRefactoryProvider
        TmpKey.SetValue("CurrentRefactoryProvider", ((object)FCurrentRefactoryProvider).GetType.FullName);
        //save FAutoCloseStatusDialogs
        if (FAutoCloseStatusDialogs) {
          TmpKey.SetValue("AutoCloseStatusDialogs", "1");
        } else {
          TmpKey.SetValue("AutoCloseStatusDialogs", "0");
        }
        //save FAutoCloseStatusDialogs
        if (FAutoUpdateOnNewVersion) {
          TmpKey.SetValue("AutoUpdateOnNewVersion", "1");
        } else {
          TmpKey.SetValue("AutoUpdateOnNewVersion", "0");
        }
        //close Key+Registry
        TmpKey.Close();
        TmpRegRoot.Close();
      } catch (Exception ex) {
      }
    }

  }
}

