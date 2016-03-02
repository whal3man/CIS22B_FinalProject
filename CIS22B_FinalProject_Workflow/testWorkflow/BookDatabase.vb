Public Class BookDatabase
    ''' <summary>
    ''' array of Book of some arbitrary size
    ''' </summary>
    Private Property books As testWorkflow.Book
        Get
            Return Nothing
        End Get
        Set(value As testWorkflow.Book)
        End Set
    End Property

    ''' <summary>
    ''' number of BookStructs in books
    ''' </summary>
    Private Property size As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    Public Property Book As Book
        Get
            Return Nothing
        End Get
        Set(value As Book)
        End Set
    End Property

    ''' <summary>
    ''' contains the number that should be given to the next book added
    ''' </summary>
    Private Property identifierCount As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    ''' <summary>
    ''' add the book to the end of books and incresase size by 1. sets the bookIdentifier to identifierCount then incraments identifierCount. runs sortBooks
    ''' </summary>
    Public Sub addBook(book As testWorkflow.Book)

    End Sub

    ''' <summary>
    ''' returns the index in books of the Book with that identifier
    ''' </summary>
    Private Function searchIdentifier(identifier As Int) As Int
    End Function

    ''' <summary>
    ''' takes in an identifier, returns the price of that book, then removes that book from books, then decreases size by 1. runs sortBooks
    ''' </summary>
    Public Function sellBook(identifier As Int) As Int
    End Function

    ''' <summary>
    ''' removes the Book with isbn, then shifts all of the books after it to remove the gap. decreases size by 1
    ''' </summary>
    Public Sub removeBook(Isbn As Int)

    End Sub

    ''' <summary>
    ''' returns the price of book with identifier
    ''' </summary>
    Public Function getPrice(identifier As Int) As Int
    End Function

    ''' <summary>
    ''' sorts the books by isbn, from lowest to highest
    ''' </summary>
    Public Sub sortBooks()

    End Sub

    ''' <summary>
    ''' swaps books in the array with indexes location1 and location2
    ''' </summary>
    Private Sub swapBooks(location1 As Int, location2 As Int)

    End Sub

    ''' <summary>
    ''' prints info on all books with isbn
    ''' </summary>
    ''' <param name="out">passed by reference</param>
    Public Sub printISBN(isbn As String, out As ostream)

    End Sub

    ''' <summary>
    ''' prints the information on the book with identifier
    ''' </summary>
    ''' <param name="out">passed by reference</param>
    Public Sub printBook(identifier As Int, out As ostream)

    End Sub
End Class
