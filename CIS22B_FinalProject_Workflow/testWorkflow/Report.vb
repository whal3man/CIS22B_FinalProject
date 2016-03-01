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

    Public Property MainMenu1 As MainMenu
        Get
            Return Nothing
        End Get
        Set(value As MainMenu)
        End Set
    End Property

    Public Property BookDatabase As BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As BookDatabase)
        End Set
    End Property

    Public Sub mainMenu()

    End Sub

    ''' <summary>
    ''' a list of all information on all books in the inventory
    ''' </summary>
    Public Sub inventoryList()

    End Sub

    ''' <summary>
    ''' list of the wholesale value of all books in the inventory and the total wholesale value of the inventory
    ''' </summary>
    Public Sub inventoryWholesaleValue()

    End Sub

    ''' <summary>
    ''' list of the retail value of all the books in the inventory and the total retail value of the inventory
    ''' </summary>
    Public Sub inventoryRetailValue()

    End Sub

    ''' <summary>
    ''' list all books by quantity
    ''' </summary>
    Public Sub listQuantity()

    End Sub

    Public Sub listCost()

    End Sub

    ''' <summary>
    ''' list of all books in the inventory, sorted by purchase date. the books that have been in the inventory the longest will be listed first
    ''' </summary>
    Public Sub listAge()

    End Sub
End Class
