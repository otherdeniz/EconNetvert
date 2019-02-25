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

Public Interface IRefactoryProvider

  ReadOnly Property Name() As String

  ReadOnly Property PreAndPostParseFlags() As ProviderParserFlags

  Function ConvertVBtoCS(ByVal vbSrc As String) As String

  Function ConvertCStoVB(ByVal csSrc As String) As String

End Interface
