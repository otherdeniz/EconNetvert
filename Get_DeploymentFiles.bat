@Echo off
echo.
echo. Get Binaries...
echo.
xcopy .\CmdLineTool\bin\release\netvertcmd.exe .\Deployment_Binaries /Y
xcopy .\GuiTool\bin\release_merged\netvertgui.exe .\Deployment_Binaries /Y
xcopy .\Library\bin\merged\Econ.NetVert.dll .\Deployment_Binaries /Y
xcopy .\Library\doc\EconNetVert.chm ".\Deployment_Binaries\Econ.NetVert Library Documentation.chm" /Y
xcopy .\GuiTool\libs\Econ.ApplicationUpdater.dll .\Deployment_Binaries /Y
xcopy .\VSAddIn\bin\Package_Output\EconNetVert_VSAddIn.vsi .\Deployment_Binaries /Y


echo.
echo. Get Installer...
echo.
xcopy .\Installer\Release\*.* .\Deployment_Installer /Y


echo.
echo. Get Source-Code...
echo.
xcopy .\CmdLineTool .\Deployment_Source\CmdLineTool /Y /S /EXCLUDE:Get_DeploymentFiles_Exclude.txt
xcopy .\GuiTool .\Deployment_Source\GuiTool /Y /S /EXCLUDE:Get_DeploymentFiles_Exclude.txt
xcopy .\Library .\Deployment_Source\Library /Y /S /EXCLUDE:Get_DeploymentFiles_Exclude.txt
xcopy .\VSAddIn .\Deployment_Source\VSAddIn /Y /S /EXCLUDE:Get_DeploymentFiles_Exclude.txt
xcopy .\Installer\*.* .\Deployment_Source\Installer\. /Y


