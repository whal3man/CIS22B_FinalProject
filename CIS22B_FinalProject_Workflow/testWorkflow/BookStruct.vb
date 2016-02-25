Public Structure BookStruct
    Public Property book As testWorkflow.Book
        Get
            Return Nothing
        End Get
        Set(value As testWorkflow.Book)
        End Set
    End Property

    Public Property dateAdded As String
        Get
            Return Nothing
        End Get
        Set(value As String)
        End Set
    End Property

    Public Property quantity As Int
        Get
            Return Nothing
        End Get
        Set(value As Int)
        End Set
    End Property

    Public Property BookDatabase As BookDatabase
        Get
            Return Nothing
        End Get
        Set(value As BookDatabase)
        End Set
    End Property
End Structure
