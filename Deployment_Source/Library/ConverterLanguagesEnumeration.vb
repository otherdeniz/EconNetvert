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

''' -----------------------------------------------------------------------------
''' <summary>
''' Determines the source and target programming language.
''' </summary>
''' <remarks>
''' Use <b>VBNetToCSharp</b> to convert from VB.NET to C# or <b>CSharpToVBNet</b> to convert from C# to VB.NET.
''' </remarks>
''' -----------------------------------------------------------------------------
Public Enum ConverterLanguages
  VBNetToCSharp = 0
  CSharpToVBNet = 1
End Enum

''' -----------------------------------------------------------------------------
''' <summary>
''' Determines the source and target programming language for ASP.NET conversion.
''' </summary>
''' <remarks>
''' Used for ASPX language selection.<br/>
''' Autodetect searchs for the LANGUAGE="xx" attribut in the ASP.NET page-directive.
''' </remarks>
''' -----------------------------------------------------------------------------
Public Enum ConverterLanguagesAutodetectable
  VBNetToCSharp = 0
  CSharpToVBNet = 1
  Autodetect = 9
End Enum