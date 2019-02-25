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

Imports Microsoft.Win32

Public NotInheritable Class SettingsManager

  'CONST
  Private Const cRegistryPath As String = "SOFTWARE\Econ Dimension\NetVert"

  'DECLARATIONS
  Private Shared FSettingsLoaded As Boolean = False
  Private Shared FCurrentRefactoryProvider As IRefactoryProvider
  Private Shared FAutoCloseStatusDialogs As Boolean = False
  Private Shared FAutoUpdateOnNewVersion As Boolean = True

  'CONSTRUCTOR
  Private Sub New()
  End Sub

  'SHARED
#Region "SHARED Properties"

  Public Shared Property CurrentRefactoryProvider() As IRefactoryProvider
    Get
      If Not FSettingsLoaded Then LoadSettings()
      Return FCurrentRefactoryProvider
    End Get
    Set(ByVal value As IRefactoryProvider)
      If value Is Nothing Then
        Throw New NoNullAllowedException
      End If
      If Not value Is FCurrentRefactoryProvider Then
        FCurrentRefactoryProvider = value
        SaveSettings()
      End If
    End Set
  End Property

  Public Shared Property AutoCloseStatusDialogs() As Boolean
    Get
      If Not FSettingsLoaded Then LoadSettings()
      Return FAutoCloseStatusDialogs
    End Get
    Set(ByVal value As Boolean)
      If Not value = FAutoCloseStatusDialogs Then
        FAutoCloseStatusDialogs = value
        SaveSettings()
      End If
    End Set
  End Property

  Public Shared Property AutoUpdateOnNewVersion() As Boolean
    Get
      If Not FSettingsLoaded Then LoadSettings()
      Return FAutoUpdateOnNewVersion
    End Get
    Set(ByVal value As Boolean)
      If Not value = FAutoUpdateOnNewVersion Then
        FAutoUpdateOnNewVersion = value
        SaveSettings()
      End If
    End Set
  End Property

#End Region

  'PRIVATE SHARED
  Private Shared Sub LoadSettings()
    Dim TmpKey As RegistryKey
    Dim TmpRegRoot As RegistryKey
    Dim TmpS As String

    Try
      'get the Registry-Key
      TmpRegRoot = RegistryKey.OpenRemoteBaseKey(RegistryHive.CurrentUser, "")
      TmpKey = TmpRegRoot.OpenSubKey(cRegistryPath, True)
      If Not TmpKey Is Nothing Then
        'Key exists
        'load FCurrentRefactoryProvider
        TmpS = TmpKey.GetValue("CurrentRefactoryProvider", "")
        If TmpS <> "" Then
          FCurrentRefactoryProvider = Activator.CreateInstance(Type.GetType(TmpS))
        End If
        'load FAutoCloseStatusDialogs
        TmpS = TmpKey.GetValue("AutoCloseStatusDialogs", "0")
        FAutoCloseStatusDialogs = (TmpS = "1")
        'load FAutoUpdateOnNewVersion
        TmpS = TmpKey.GetValue("AutoUpdateOnNewVersion", "1")
        FAutoUpdateOnNewVersion = (TmpS = "1")
        'close Key
        TmpKey.Close()
      End If
      'close Registry
      TmpRegRoot.Close()
    Catch ex As Exception
    End Try
    'load default FCurrentRefactoryProvider
    If FCurrentRefactoryProvider Is Nothing Then
      FCurrentRefactoryProvider = RefactoryNet20Provider.Instance
    End If
    'settings loaded ok
    FSettingsLoaded = True
  End Sub

  Private Shared Sub SaveSettings()
    Dim TmpKey As RegistryKey
    Dim TmpRegRoot As RegistryKey

    Try
      'get the Registry-Key
      TmpRegRoot = RegistryKey.OpenRemoteBaseKey(RegistryHive.CurrentUser, "")
      TmpKey = TmpRegRoot.OpenSubKey(cRegistryPath, True)
      If TmpKey Is Nothing Then
        'Key not exists, create
        TmpKey = TmpRegRoot.CreateSubKey(cRegistryPath)
      End If
      'save FCurrentRefactoryProvider
      TmpKey.SetValue("CurrentRefactoryProvider", CType(FCurrentRefactoryProvider, Object).GetType.FullName)
      'save FAutoCloseStatusDialogs
      If FAutoCloseStatusDialogs Then
        TmpKey.SetValue("AutoCloseStatusDialogs", "1")
      Else
        TmpKey.SetValue("AutoCloseStatusDialogs", "0")
      End If
      'save FAutoCloseStatusDialogs
      If FAutoUpdateOnNewVersion Then
        TmpKey.SetValue("AutoUpdateOnNewVersion", "1")
      Else
        TmpKey.SetValue("AutoUpdateOnNewVersion", "0")
      End If
      'close Key+Registry
      TmpKey.Close()
      TmpRegRoot.Close()
    Catch ex As Exception
    End Try
  End Sub

End Class
