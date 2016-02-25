Public Class Cashier
    ''' <summary>
    ''' takes in the BookDatabase by reference, NOT VALUE
    ''' </summary>
    Private Property database As testWorkflow.BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As testWorkflow.BookDatabase)
        End Set
    End Property

    Public Property MainMenu1 As MainMenu
        Get
            Return Nothing
        End Get
        Set(value As MainMenu)
        End Set
    End Property

    ''' <summary>
    ''' displays the cashier main menu and asks the user for input
    ''' </summary>
    Public Sub mainMenu()

    End Sub
End Class
