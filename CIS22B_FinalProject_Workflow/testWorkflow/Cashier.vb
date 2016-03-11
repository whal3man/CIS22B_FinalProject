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
    ''' array of identifiers that the user wants to buy
    ''' </summary>
    Private Property cart As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    ''' <summary>
    ''' amount of items in the cart
    ''' </summary>
    Public Property cartSize As Integer
        Get
            Return Nothing
        End Get
        Set(value As Integer)
        End Set
    End Property

    ''' <summary>
    ''' displays the cashier main menu and asks the user for input
    ''' options:
    ''' add book to cart
    ''' remove book from cart
    ''' checkout
    ''' </summary>
    Public Sub mainMenu()

    End Sub

    ''' <summary>
    ''' //displays a menu that
    ''' //asks the user for the identifier of the book they wish to add to cart
    ''' //adds the book they select to the cart
    ''' </summary>
    Public Sub addBook()

    End Sub

    ''' <summary>
    ''' displays a menu that displays all books in cart, subtotals, calculates tax, and presents grand total. if they checkout, subtract books from BookDatabase
    ''' </summary>
    Public Sub checkout()

    End Sub

    ''' <summary>
    ''' displays a menu that
    ''' lists all books in cart with all their information
    ''' asks the user which one they want to remove
    ''' removes the book they select, or leaves the menu if they choose to
    ''' </summary>
    Public Sub removeBook()

    End Sub
End Class
