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

Friend Class NetVertException
  Inherits Exception

  'DECLARATIONS
  Public Property ErrorLine As Int32

  'CONSTRUCTOR
  Public Sub New(ByVal message As String, Optional ByVal errorLine As Int32 = -1)
    MyBase.New(message)
    Me.ErrorLine = errorLine
  End Sub

  'PUBLIC
#Region "PUBLIC Properties"

  Public Overrides ReadOnly Property Message() As String
    Get
      Return MyBase.Message
    End Get
  End Property

#End Region

End Class
