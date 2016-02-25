Public Class Report
    '''  <summary>
    '''  takes in the BookDatabase by reference, NOT VALUE
    '''  </summary>
    Private Property database As testWorkflow.BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As testWorkflow.BookDatabase)
        End Set
    End Property

    Public Property BookDatabase As BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As BookDatabase)
        End Set
    End Property

    Public Property MainMenu1 As MainMenu
        Get
            Return Nothing
        End Get
        Set(value As MainMenu)
        End Set
    End Property

    Public Sub mainMenu()

    End Sub

    ''' <summary>
    ''' a list of all information on all books in the inventory
    ''' </summary>
    Public Sub inventoryList()

    End Sub

    Public Sub inventoryWholesaleValue()

    End Sub
End Class
