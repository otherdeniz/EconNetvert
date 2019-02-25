Public Class TextEditorHelperBox

  'DECLARATIONS
  Private FBoxType As TextEditorHelperBoxTypes = TextEditorHelperBoxTypes.SearchBox
  Private FTextEditorControl As ICSharpCode.TextEditor.TextEditorControl
  Private FHandleKeys As Boolean = False

  'EVENTS

  'PUBLIC
#Region "PUBLIC Properties"

  Public Property TextEditorHelperBoxType() As TextEditorHelperBoxTypes
    Get
      Return FBoxType
    End Get
    Set(ByVal value As TextEditorHelperBoxTypes)
      FBoxType = value
      ApplyBoxType()
    End Set
  End Property

  Public Property TextEditorControl() As ICSharpCode.TextEditor.TextEditorControl
    Get
      Return FTextEditorControl
    End Get
    Set(ByVal value As ICSharpCode.TextEditor.TextEditorControl)
      FTextEditorControl = value
    End Set
  End Property

#End Region

  Protected Overrides Sub OnGotFocus(ByVal e As System.EventArgs)
    MyBase.OnGotFocus(e)
    'set focus to input-box
    Select Case FBoxType
      Case TextEditorHelperBoxTypes.GotoLineBox
        TxtGotoLine.Focus()
      Case TextEditorHelperBoxTypes.SearchBox
        TxtSearch.Focus()
    End Select
  End Sub

  'PRIVATE
  Private Sub ApplyBoxType()
    PnlSearch.Visible = (FBoxType = TextEditorHelperBoxTypes.SearchBox)
    PnlGotoLine.Visible = (FBoxType = TextEditorHelperBoxTypes.GotoLineBox)
  End Sub

#Region "Opeartion: SEARCH"

  Private Sub DoSearch()
    If TxtSearch.Text <> "" Then
      If Not DoSearch(TxtSearch.Text) Then
        'error-highlight
        TxtSearch.BackColor = Color.Red
        TxtSearch.ForeColor = Color.White
      End If
    End If
  End Sub

  Private Function DoSearch(ByVal searchString As String) As Boolean
    Dim TmpCurrentCursorPos As Int32
    Dim TmpNextCursorPos As Int32 = -1
    Dim TmpS As String
    Dim RetB As Boolean = False

    If Not FTextEditorControl Is Nothing Then
      TmpCurrentCursorPos = FTextEditorControl.ActiveTextAreaControl.Caret.Offset
      TmpS = FTextEditorControl.Document.TextContent.ToLower
      If TmpS.Length > 0 Then
        'search from cursor to end
        If TmpS.Length > TmpCurrentCursorPos + 1 Then
          TmpNextCursorPos = TmpS.IndexOf(searchString.ToLower, TmpCurrentCursorPos + 1)
        End If
        If TmpNextCursorPos = -1 Then
          'search from beginning
          TmpNextCursorPos = TmpS.IndexOf(searchString.ToLower)
        End If
        If TmpNextCursorPos > -1 Then
          'found, set cursor
          With FTextEditorControl.ActiveTextAreaControl
            .Caret.Position = .Document.OffsetToPosition(TmpNextCursorPos)
            .SelectionManager.SetSelection(.Document.OffsetToPosition(TmpNextCursorPos), _
                                           .Document.OffsetToPosition(TmpNextCursorPos + searchString.Length))
          End With
          'result ok
          RetB = True
        End If
      End If
    End If
    Return RetB
  End Function

#End Region

#Region "Operation: GOTO-Line"

  Private Sub DoGotoLine()
    Try
      If TxtGotoLine.Text <> "" Then
        TxtGotoLine.Text = DoGotoLine(Int32.Parse(TxtGotoLine.Text)).ToString
      End If
    Catch ex As Exception
      'error-highlight
      TxtGotoLine.BackColor = Color.Red
      TxtGotoLine.ForeColor = Color.White
    End Try
  End Sub

  Private Function DoGotoLine(ByVal lineNr As Int32) As Int32
    If Not FTextEditorControl Is Nothing Then
      'check if line is to high, then take last line
      If lineNr > FTextEditorControl.Document.TotalNumberOfLines Then
        lineNr = FTextEditorControl.Document.TotalNumberOfLines
      End If
      'set carret to line
      FTextEditorControl.ActiveTextAreaControl.Caret.Line = lineNr
    End If
    Return lineNr
  End Function

#End Region

#Region "GUI Events"

  Private Sub TextEditorHelperBox_Resize(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Resize
    Me.Height = PnlSearch.Height
  End Sub

  Private Sub BtnSearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnSearch.Click
    DoSearch()
  End Sub

  Private Sub BtnGotoLine_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnGotoLine.Click
    DoGotoLine()
  End Sub

  Private Sub TxtSearch_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles TxtSearch.KeyDown
    'reset error-highlight
    TxtSearch.BackColor = SystemColors.Window
    TxtSearch.ForeColor = SystemColors.WindowText
    'check pressed key
    Select Case e.KeyCode
      Case Keys.Enter
        'ENTER
        DoSearch()
        e.Handled = True
        FHandleKeys = True
    End Select
  End Sub

  Private Sub TxtGotoLine_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles TxtGotoLine.KeyDown
    'reset error-highlight
    TxtGotoLine.BackColor = SystemColors.Window
    TxtGotoLine.ForeColor = SystemColors.WindowText
    'check pressed key
    Select Case e.KeyCode
      Case Keys.Enter
        'ENTER
        DoGotoLine()
        e.Handled = True
        FHandleKeys = True
    End Select
  End Sub

  Private Sub TxtSearch_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles TxtSearch.KeyPress
    'prevent 'beep' on already handled keys
    If FHandleKeys Then e.Handled = True
  End Sub

  Private Sub TxtSearch_KeyUp(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles TxtSearch.KeyUp
    'prevent 'beep' on already handled keys
    If FHandleKeys Then e.Handled = True
    FHandleKeys = False
  End Sub

  Private Sub TxtGotoLine_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles TxtGotoLine.KeyPress
    'prevent 'beep' on already handled keys
    If FHandleKeys Then e.Handled = True
  End Sub

  Private Sub TxtGotoLine_KeyUp(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles TxtGotoLine.KeyUp
    'prevent 'beep' on already handled keys
    If FHandleKeys Then e.Handled = True
    FHandleKeys = False
  End Sub

  Private Sub BtnFirst_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnFirst.Click
    DoGotoLine(0)
  End Sub

  Private Sub BtnLast_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BtnLast.Click
    If Not FTextEditorControl Is Nothing Then
      DoGotoLine(FTextEditorControl.Document.TotalNumberOfLines)
    End If
  End Sub

#End Region

End Class