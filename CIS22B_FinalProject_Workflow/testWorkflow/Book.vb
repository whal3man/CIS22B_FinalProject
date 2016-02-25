Public Class Book
    Private Property title As String
        Get
            Return Nothing
        End Get
        Set(value As String)
        End Set
    End Property

    Private Property isbn As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    Private Property author As String
        Get
            Return Nothing
        End Get
        Set(value As String)
        End Set
    End Property

    Private Property publisher As String
        Get
            Return Nothing
        End Get
        Set(value As String)
        End Set
    End Property

    Private Property wholesaleCost As Double
        Get
            Return Nothing
        End Get
        Set(value As Double)
        End Set
    End Property

    Private Property retailPrice As Double
        Get
            Return Nothing
        End Get
        Set(value As Double)
        End Set
    End Property

    Public Property BookStruct As BookStruct
        Get
            Return Nothing
        End Get
        Set(value As BookStruct)
        End Set
    End Property

    Public Function getAuthor() As String
    End Function

    Public Function setAuthor(auth As String) As Void
    End Function

    Public Function getIsbn() As Int
    End Function

    Public Sub setIsbn(isbn As Int)

    End Sub

    Public Function getTitle() As String
    End Function

    Public Sub setTitle(nam As String)

    End Sub

    Public Function getPublisher() As String
    End Function

    Public Sub setPublisher(pub As String)

    End Sub

    Public Function getRetailPrice() As Double
    End Function

    Public Sub setRetailPrice(price As Double)

    End Sub

    Public Function getWholesaleCost() As Double
    End Function

    Public Sub setWholesaleCost(cost As Double)

    End Sub

    ''' <summary>
    ''' default constructor
    ''' </summary>
    Public Function Book() As testWorkflow.Book
    End Function

    Public Function Book(title As String, author As String, isbn As Int, publisher As String, wholesaleCost As Double, retailPrice As String) As testWorkflow.Book
    End Function
End Class
