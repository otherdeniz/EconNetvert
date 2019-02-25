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

Public Class RefactoryOnlineProvider
  Implements IRefactoryProvider

  'SHARED
  Public Shared Instance As New RefactoryOnlineProvider

  'CONST
  Private Const cCsToVb As String = "cs2vbnet"
  Private Const cVbToCs As String = "vbnet2cs"

  'PUBLIC
#Region "PUBLIC Properties"

  Public ReadOnly Property Name() As String Implements IRefactoryProvider.Name
    Get
      Return "NRefactory Online WebService"
    End Get
  End Property

  Public ReadOnly Property PreAndPostParseFlags() As ProviderParserFlags Implements IRefactoryProvider.PreAndPostParseFlags
    Get
      Return ProviderParserFlags.HandleCommonLanguagePreparation Or _
             ProviderParserFlags.HandleICSharpCodeParserBugs
    End Get
  End Property

#End Region

  Public Function ConvertCStoVB(ByVal csSrc As String) As String Implements IRefactoryProvider.ConvertCStoVB
    Dim TmpErr As String = ""
    Dim RetS As String = ""

    With New net.sharpdevelop.developer.ConvertService
      If Not .PerformConversion(cCsToVb, csSrc, RetS, TmpErr) Then
        Throw New NetVertException(TmpErr)
      End If
      .Dispose()
    End With
    Return RetS
  End Function

  Public Function ConvertVBtoCS(ByVal vbSrc As String) As String Implements IRefactoryProvider.ConvertVBtoCS
    Dim TmpErr As String = ""
    Dim RetS As String = ""

    With New net.sharpdevelop.developer.ConvertService
      If Not .PerformConversion(cVbToCs, vbSrc, RetS, TmpErr) Then
        Throw New NetVertException(TmpErr)
      End If
      .Dispose()
    End With
    Return RetS
  End Function


End Class
