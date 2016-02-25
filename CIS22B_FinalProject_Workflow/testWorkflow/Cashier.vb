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

    Public Property BookDatabase As BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As BookDatabase)
        End Set
    End Property

    ''' <summary>
    ''' array of isbn's that the user wants to buy
    ''' </summary>
    Private Property cart As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    ''' <summary>
    ''' displays the cashier main menu and asks the user for input
    ''' </summary>
    Public Sub mainMenu()

    End Sub

    ''' <summary>
    ''' displays a menu that allows user to add books to cart
    ''' </summary>
    Public Sub addBook()

    End Sub

    ''' <summary>
    ''' displays a menu that displays all books in cart, subtotals, calculates tax, and presents grand total. if they checkout, subtract books from BookDatabase
    ''' </summary>
    Public Sub checkout()

    End Sub
End Class
