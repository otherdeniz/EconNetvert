﻿'------------------------------------------------------------------------------
' <auto-generated>
'     This code was generated by a tool.
'     Runtime Version:4.0.30319.42000
'
'     Changes to this file may cause incorrect behavior and will be lost if
'     the code is regenerated.
' </auto-generated>
'------------------------------------------------------------------------------

Option Strict Off
Option Explicit On

Imports System
Imports System.ComponentModel
Imports System.Diagnostics
Imports System.Web.Services
Imports System.Web.Services.Protocols
Imports System.Xml.Serialization

'
'This source code was auto-generated by Microsoft.VSDesigner, Version 4.0.30319.42000.
'
Namespace net.sharpdevelop.developer
    
    '''<remarks/>
    <System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.8.9032.0"),  _
     System.Diagnostics.DebuggerStepThroughAttribute(),  _
     System.ComponentModel.DesignerCategoryAttribute("code"),  _
     System.Web.Services.WebServiceBindingAttribute(Name:="ConvertServiceSoap", [Namespace]:="http://developer.sharpdevelop.net/CodeConverter.NET/")>  _
    Partial Public Class ConvertService
        Inherits System.Web.Services.Protocols.SoapHttpClientProtocol
        
        Private PerformConversionOperationCompleted As System.Threading.SendOrPostCallback
        
        Private useDefaultCredentialsSetExplicitly As Boolean
        
        '''<remarks/>
        Public Sub New()
            MyBase.New
            Me.Url = Global.Econ.NetVert.My.MySettings.Default.Econ_NetVert_net_sharpdevelop_developer_ConvertService
            If (Me.IsLocalFileSystemWebService(Me.Url) = true) Then
                Me.UseDefaultCredentials = true
                Me.useDefaultCredentialsSetExplicitly = false
            Else
                Me.useDefaultCredentialsSetExplicitly = true
            End If
        End Sub
        
        Public Shadows Property Url() As String
            Get
                Return MyBase.Url
            End Get
            Set
                If (((Me.IsLocalFileSystemWebService(MyBase.Url) = true)  _
                            AndAlso (Me.useDefaultCredentialsSetExplicitly = false))  _
                            AndAlso (Me.IsLocalFileSystemWebService(value) = false)) Then
                    MyBase.UseDefaultCredentials = false
                End If
                MyBase.Url = value
            End Set
        End Property
        
        Public Shadows Property UseDefaultCredentials() As Boolean
            Get
                Return MyBase.UseDefaultCredentials
            End Get
            Set
                MyBase.UseDefaultCredentials = value
                Me.useDefaultCredentialsSetExplicitly = true
            End Set
        End Property
        
        '''<remarks/>
        Public Event PerformConversionCompleted As PerformConversionCompletedEventHandler
        
        '''<remarks/>
        <System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://developer.sharpdevelop.net/CodeConverter.NET/PerformConversion", RequestNamespace:="http://developer.sharpdevelop.net/CodeConverter.NET/", ResponseNamespace:="http://developer.sharpdevelop.net/CodeConverter.NET/", Use:=System.Web.Services.Description.SoapBindingUse.Literal, ParameterStyle:=System.Web.Services.Protocols.SoapParameterStyle.Wrapped)>  _
        Public Function PerformConversion(ByVal TypeOfConversion As String, ByVal SourceCode As String, ByRef ConvertedCode As String, ByRef ErrorMessage As String) As Boolean
            Dim results() As Object = Me.Invoke("PerformConversion", New Object() {TypeOfConversion, SourceCode})
            ConvertedCode = CType(results(1),String)
            ErrorMessage = CType(results(2),String)
            Return CType(results(0),Boolean)
        End Function
        
        '''<remarks/>
        Public Overloads Sub PerformConversionAsync(ByVal TypeOfConversion As String, ByVal SourceCode As String)
            Me.PerformConversionAsync(TypeOfConversion, SourceCode, Nothing)
        End Sub
        
        '''<remarks/>
        Public Overloads Sub PerformConversionAsync(ByVal TypeOfConversion As String, ByVal SourceCode As String, ByVal userState As Object)
            If (Me.PerformConversionOperationCompleted Is Nothing) Then
                Me.PerformConversionOperationCompleted = AddressOf Me.OnPerformConversionOperationCompleted
            End If
            Me.InvokeAsync("PerformConversion", New Object() {TypeOfConversion, SourceCode}, Me.PerformConversionOperationCompleted, userState)
        End Sub
        
        Private Sub OnPerformConversionOperationCompleted(ByVal arg As Object)
            If (Not (Me.PerformConversionCompletedEvent) Is Nothing) Then
                Dim invokeArgs As System.Web.Services.Protocols.InvokeCompletedEventArgs = CType(arg,System.Web.Services.Protocols.InvokeCompletedEventArgs)
                RaiseEvent PerformConversionCompleted(Me, New PerformConversionCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState))
            End If
        End Sub
        
        '''<remarks/>
        Public Shadows Sub CancelAsync(ByVal userState As Object)
            MyBase.CancelAsync(userState)
        End Sub
        
        Private Function IsLocalFileSystemWebService(ByVal url As String) As Boolean
            If ((url Is Nothing)  _
                        OrElse (url Is String.Empty)) Then
                Return false
            End If
            Dim wsUri As System.Uri = New System.Uri(url)
            If ((wsUri.Port >= 1024)  _
                        AndAlso (String.Compare(wsUri.Host, "localHost", System.StringComparison.OrdinalIgnoreCase) = 0)) Then
                Return true
            End If
            Return false
        End Function
    End Class
    
    '''<remarks/>
    <System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.8.9032.0")>  _
    Public Delegate Sub PerformConversionCompletedEventHandler(ByVal sender As Object, ByVal e As PerformConversionCompletedEventArgs)
    
    '''<remarks/>
    <System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.8.9032.0"),  _
     System.Diagnostics.DebuggerStepThroughAttribute(),  _
     System.ComponentModel.DesignerCategoryAttribute("code")>  _
    Partial Public Class PerformConversionCompletedEventArgs
        Inherits System.ComponentModel.AsyncCompletedEventArgs
        
        Private results() As Object
        
        Friend Sub New(ByVal results() As Object, ByVal exception As System.Exception, ByVal cancelled As Boolean, ByVal userState As Object)
            MyBase.New(exception, cancelled, userState)
            Me.results = results
        End Sub
        
        '''<remarks/>
        Public ReadOnly Property Result() As Boolean
            Get
                Me.RaiseExceptionIfNecessary
                Return CType(Me.results(0),Boolean)
            End Get
        End Property
        
        '''<remarks/>
        Public ReadOnly Property ConvertedCode() As String
            Get
                Me.RaiseExceptionIfNecessary
                Return CType(Me.results(1),String)
            End Get
        End Property
        
        '''<remarks/>
        Public ReadOnly Property ErrorMessage() As String
            Get
                Me.RaiseExceptionIfNecessary
                Return CType(Me.results(2),String)
            End Get
        End Property
    End Class
End Namespace
