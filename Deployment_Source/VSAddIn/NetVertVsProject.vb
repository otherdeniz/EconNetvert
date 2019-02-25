Imports System.IO

Public Class NetVertVsProject

  'NESTED ENUM
  Public Enum NetVertExecutionEnum
    OnlyManual = 0
    BaforeSolutionClose = 1
    AfterSolutionBuild = 2
  End Enum

  'DELCARATIONS
  Private FProject As EnvDTE.Project

  'CONSTRUCTOR
  Public Sub New(ByVal project As EnvDTE.Project)
    FProject = project
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  Public ReadOnly Property VSProject() As EnvDTE.Project
    Get
      Return FProject
    End Get
  End Property

  Public ReadOnly Property Language() As String
    Get
      Select Case FProject.Kind.ToUpper()
        Case "{F184B08F-C81C-45F6-A57F-5ABD9991F28F}"
          Return "VB"
        Case "{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}"
          Return "CS"
        Case Else
          Return ""
      End Select
    End Get
  End Property

  Public Property Enabled() As Boolean
    Get
      If FProject.Globals.VariableExists("EconNetVertEnabled") Then
        Return (FProject.Globals.VariableValue("EconNetVertEnabled") = "1")
      Else
        Return False 'default
      End If
    End Get
    Set(ByVal value As Boolean)
      FProject.Globals.VariableValue("EconNetVertEnabled") = IIf(value, "1", "0")
      FProject.Globals.VariablePersists("EconNetVertEnabled") = value
      If FProject.Globals.VariableExists("EconNetVertPath") Then FProject.Globals.VariablePersists("EconNetVertPath") = value
      If FProject.Globals.VariableExists("EconNetVertFixNamespaceImports") Then FProject.Globals.VariablePersists("EconNetVertFixNamespaceImports") = value
      If FProject.Globals.VariableExists("EconNetVertExecute") Then FProject.Globals.VariablePersists("EconNetVertExecute") = value
    End Set
  End Property

  Public Property Path() As String
    Get
      If FProject.Globals.VariableExists("EconNetVertPath") Then
        Return FProject.Globals.VariableValue("EconNetVertPath")
      Else
        Return "..\" & FProject.Name & " Converted" 'default
      End If
    End Get
    Set(ByVal value As String)
      FProject.Globals.VariableValue("EconNetVertPath") = value
      FProject.Globals.VariablePersists("EconNetVertPath") = Me.Enabled
    End Set
  End Property

  Public Property FixNamespaceImport() As Boolean
    Get
      If FProject.Globals.VariableExists("EconNetVertFixNamespaceImports") Then
        Return (FProject.Globals.VariableValue("EconNetVertFixNamespaceImports") = "1")
      Else
        Return False 'default
      End If
    End Get
    Set(ByVal value As Boolean)
      FProject.Globals.VariableValue("EconNetVertFixNamespaceImports") = IIf(value, "1", "0")
      FProject.Globals.VariablePersists("EconNetVertFixNamespaceImports") = Me.Enabled
    End Set
  End Property

  Public Property ExecuteMethod() As NetVertExecutionEnum
    Get
      If FProject.Globals.VariableExists("EconNetVertExecute") Then
        Select Case FProject.Globals.VariableValue("EconNetVertExecute")
          Case "1"
            Return NetVertExecutionEnum.BaforeSolutionClose
          Case "2"
            Return NetVertExecutionEnum.AfterSolutionBuild
          Case Else '0
            Return NetVertExecutionEnum.OnlyManual
        End Select
      Else
        Return NetVertExecutionEnum.AfterSolutionBuild  'default
      End If
    End Get
    Set(ByVal value As NetVertExecutionEnum)
      FProject.Globals.VariableValue("EconNetVertExecute") = CStr(value)
      FProject.Globals.VariablePersists("EconNetVertExecute") = Me.Enabled
    End Set
  End Property

#End Region

  Public Function GetSourcePath() As String
    Dim RetP As String
    RetP = New System.IO.FileInfo(FProject.FullName).Directory.FullName
    Return RetP
  End Function

  Public Function GetDestinationPath() As String
    Return System.IO.Path.GetFullPath(System.IO.Path.Combine(GetSourcePath, Me.Path))
  End Function

End Class
