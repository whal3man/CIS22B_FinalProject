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
    ''' if the book already exists in the database, add the quantity to the existing quantity. Otherwise, create a Book and add it to books and increase size by one
    ''' </summary>
    Public Sub addBook(book As testWorkflow.Book, quantity As Int)

    End Sub

    ''' <summary>
    ''' returns the index in books of the Book with that isbn
    ''' </summary>
    Private Function searchIsbn(isbn As Int) As Int
    End Function

    ''' <summary>
    ''' takes in an isbn, removes one from the quantity of that book, then returns the retailPrice of that book. If there are no more copies afterward, remove the struct from books.
    ''' </summary>
    Public Function sellBook(isbn As Int) As Int
    End Function

    ''' <summary>
    ''' removes the Book with isbn, then shifts all of the books after it to remove the gap. decreases size by 1
    ''' </summary>
    Public Sub removeBook(Isbn As Int)

    End Sub

    ''' <summary>
    ''' returns the price of book with isbn
    ''' </summary>
    Public Function getPrice(isbn As Int) As Int
    End Function
End Class
