''//
'// Creator Generic Experiment . Hand Written Creator
'//
'//     Author: Jan-Joost van Zon
'//     Date: Saturday, February 24, 2007 - Sunday, February 25, 2007
'//
'// -----
'// 
'//     Comment:
'//
'//         All relations in the experiment are unary.
'//
'//         The same things are described in all the three layers,
'//         but this first layer, does contain search methods,
'//         but these don't have to be included in the higher layers.
'//         And the highest layer may not be finished yet.
'//
'// -----


'Options

    Option Explicit On 
    Option Strict On

'Classes

    'Structure

        Class hStructure

            Public ReadOnly hClasses As New hClasses()
            Public ReadOnly hRelations As New hRelations()

        End Class

        'Classes

            Class hClasses

                'Declarations

                    Private sCount As Integer
                    Private shClass() As hClass

                'Definitions

                    Public Property Count() As Integer
                        Get
                            Return sCount
                        End Get
                        Set(ByVal aValue As Integer)
                            If aValue < 0 Then aValue = 0
                            If Not sCount = aValue Then
                                If aValue = 0 Then
                                    ReDim shClass(0)
                                Else
                                    ReDim Preserve shClass(aValue - 1)
                                End If
                                Dim i As Integer
                                For i = sCount To aValue - 1
                                    shClass(i) = New hClass()
                                Next
                                sCount = aValue
                            End If
                        End Set
                    End Property

                    Public ReadOnly Property hClass(ByVal aIndex As Integer) As hClass
                        Get
                            Return shClass(aIndex)
                        End Get
                    End Property

                    Public ReadOnly Property hClass(ByVal aName As String) As hClass
                        Get
                            Dim i As Integer
                            For i = 0 To Count - 1
                                If Not hClass(i) Is Nothing Then
                                    If hClass(i).hClassName = aName Then Return hClass(i)
                                End If
                            Next
                        End Get
                    End Property

                    Public Function Add() As hClass
                        Count += 1
                        Return hClass(Count - 1)
                    End Function

            End Class

            'Class

                Class hClass

                    Public ReadOnly This As hClass = Me

                    Public hClassName As String
                    Public ReadOnly hClassAttributes As New hClassAttributes()

                End Class

                'Class Atributes

                    Class hClassAttributes

                        'Declarations

                            Private sCount As Integer
                            Private shClassAttribute() As hClassAttribute

                        'Definitions

                            Public Property Count() As Integer
                                Get
                                    Return sCount
                                End Get
                                Set(ByVal aValue As Integer)
                                    If aValue < 0 Then aValue = 0
                                    If Not sCount = aValue Then
                                        If aValue = 0 Then
                                            ReDim shClassAttribute(0)
                                        Else
                                            ReDim Preserve shClassAttribute(aValue - 1)
                                        End If
                                        Dim i As Integer
                                        For i = sCount To aValue - 1
                                            shClassAttribute(i) = New hClassAttribute()
                                        Next
                                        sCount = aValue
                                    End If
                                End Set
                            End Property

                            Public ReadOnly Property hClassAttribute(ByVal aIndex As Integer) As hClassAttribute
                                Get
                                    Return shClassAttribute(aIndex)
                                End Get
                            End Property

                            Public ReadOnly Property hClassAttribute(ByVal aName As String) As hClassAttribute
                                Get
                                    Dim i As Integer
                                    For i = 0 To Count - 1
                                        If Not hClassAttribute(i) Is Nothing Then
                                            If hClassAttribute(i).hName = aName Then Return hClassAttribute(i)
                                        End If
                                    Next
                                End Get
                            End Property

                            Public Function Add() As hClassAttribute
                                Count += 1
                                Return hClassAttribute(Count - 1)
                            End Function

                    End Class

                    'Class Attribute

                        Class hClassAttribute
                            Public hName As String
                            Public hType As String
                        End Class

        'Relations

            Class hRelations

                'Declarations

                    Private sCount As Integer
                    Private shRelation() As hRelation

                'Definitions

                    Public Property Count() As Integer
                        Get
                            Return sCount
                        End Get
                        Set(ByVal aValue As Integer)
                            If aValue < 0 Then aValue = 0
                            If Not sCount = aValue Then
                                If aValue = 0 Then
                                    ReDim shRelation(0)
                                Else
                                    ReDim Preserve shRelation(aValue - 1)
                                End If
                                Dim i As Integer
                                For i = sCount To aValue - 1
                                    shRelation(i) = New hRelation()
                                Next
                                sCount = aValue
                            End If
                        End Set
                    End Property

                    Public ReadOnly Property hRelation(ByVal aIndex As Integer) As hRelation
                        Get
                            Return shRelation(aIndex)
                        End Get
                    End Property

                    Public Function Add() As hRelation
                        Count += 1
                        Return hRelation(Count - 1)
                    End Function

            End Class

            'Relation

                Class hRelation
                    Public ReadOnly This As hRelation = Me
                    Public hRelationClassA As New hRelationClass()
                    Public hRelationClassB As New hRelationClass()
                End Class

                'Relation Class

                    Class hRelationClass
                        Public hClass As hClass
                        Public hPlural As Boolean
                        Public hName As String
                    End Class

    'Item

        Class hItem

            Public hClass As hClass
            Public hClassGenericallyDescribed As hItem
            Public ReadOnly hItemAttributes As New hItemAttributes()
            Public ReadOnly hRelatedItems As hRelatedItems
            Public ReadOnly hRelatedLists As New hRelatedLists()

        End Class

        'Item Atributes

            Class hItemAttributes

                'Declarations

                    Private sCount As Integer
                    Private shItemAttribute() As hItemAttribute

                'Definitions

                    Public Property Count() As Integer
                        Get
                            Return sCount
                        End Get
                        Set(ByVal aValue As Integer)
                            If aValue < 0 Then aValue = 0
                            If Not sCount = aValue Then
                                If aValue = 0 Then
                                    ReDim shItemAttribute(0)
                                Else
                                    ReDim Preserve shItemAttribute(aValue - 1)
                                End If
                                Dim i As Integer
                                For i = sCount To aValue - 1
                                    shItemAttribute(i) = New hItemAttribute()
                                Next
                                sCount = aValue
                            End If
                        End Set
                    End Property

                    Public ReadOnly Property hItemAttribute(ByVal aIndex As Integer) As hItemAttribute
                        Get
                            Return shItemAttribute(aIndex)
                        End Get
                    End Property

                    Public ReadOnly Property hItemAttribute(ByVal aName As String) As hItemAttribute
                        Get
                            Dim i As Integer
                            For i = 0 To Count - 1
                                If Not hItemAttribute(i) Is Nothing Then
                                    If hItemAttribute(i).hClassAttribute.hName = aName Then Return hItemAttribute(i)
                                End If
                            Next
                        End Get
                    End Property

                    Public Function Add() As hItemAttribute
                        Count += 1
                        Return hItemAttribute(Count - 1)
                    End Function

            End Class

            'Item Attribute

                Class hItemAttribute
                    Public hClassAttribute As hClassAttribute
                    Public hValue As String
                End Class

        'Related Items

            Class hRelatedItems

                'Declarations

                    Private sCount As Integer
                    Private shRelatedItem() As hRelatedItem

                'Definitions

                    Public Property Count() As Integer
                        Get
                            Return sCount
                        End Get
                        Set(ByVal aValue As Integer)
                            If aValue < 0 Then aValue = 0
                            If Not sCount = aValue Then
                                If aValue = 0 Then
                                    ReDim shRelatedItem(0)
                                Else
                                    ReDim Preserve shRelatedItem(aValue - 1)
                                End If
                                Dim i As Integer
                                For i = sCount To aValue - 1
                                    shRelatedItem(i) = New hRelatedItem()
                                Next
                                sCount = aValue
                            End If
                        End Set
                    End Property

                    Public ReadOnly Property hRelatedItem(ByVal aIndex As Integer) As hRelatedItem
                        Get
                            Return shRelatedItem(aIndex)
                        End Get
                    End Property

                    Public ReadOnly Property hRelatedItem(ByVal aName As String) As hRelatedItem
                        Get
                            Dim i As Integer
                            For i = 0 To Count - 1
                                If Not hRelatedItem(i) Is Nothing Then
                                    If hRelatedItem(i).hRelationClass.hName = aName Then Return hRelatedItem(i)
                                End If
                            Next
                        End Get
                    End Property

            End Class

            'Related Item

                Class hRelatedItem
                    Public hRelationClass As hRelationClass
                    Public hItem As hItem
                End Class

        'Related Lists

            Class hRelatedLists

                'Declarations

                    Private sCount As Integer
                    Private shRelatedList() As hRelatedList

                'Definitions

                    Public Property Count() As Integer
                        Get
                            Return sCount
                        End Get
                        Set(ByVal aValue As Integer)
                            If aValue < 0 Then aValue = 0
                            If Not sCount = aValue Then
                                If aValue = 0 Then
                                    ReDim shRelatedList(0)
                                Else
                                    ReDim Preserve shRelatedList(aValue - 1)
                                End If
                                Dim i As Integer
                                For i = sCount To aValue - 1
                                    shRelatedList(i) = New hRelatedList()
                                Next
                                sCount = aValue
                            End If
                        End Set
                    End Property

                    Public ReadOnly Property hRelatedList(ByVal aIndex As Integer) As hRelatedList
                        Get
                            Return shRelatedList(aIndex)
                        End Get
                    End Property

                    Public ReadOnly Property hRelatedList(ByVal aName As String) As hRelatedList
                        Get
                            Dim i As Integer
                            For i = 0 To Count - 1
                                If Not hRelatedList(i) Is Nothing Then
                                    If hRelatedList(i).hRelationClass.hName = aName Then Return hRelatedList(i)
                                End If
                            Next
                        End Get
                    End Property

                    Public Function Add() As hRelatedList
                        Count += 1
                        Return hRelatedList(Count - 1)
                    End Function

            End Class

            'Related List

                Class hRelatedList

                    'Declarations

                        Public hRelationClass As hRelationClass

                        Private sCount As Integer
                        Private shItem() As hItem

                    'Definitions

                        Public Property Count() As Integer
                            Get
                                Return sCount
                            End Get
                            Set(ByVal aValue As Integer)
                                If aValue < 0 Then aValue = 0
                                If Not sCount = aValue Then
                                    If aValue = 0 Then
                                        ReDim shItem(0)
                                    Else
                                        ReDim Preserve shItem(aValue - 1)
                                    End If
                                    Dim i As Integer
                                    For i = sCount To aValue - 1
                                        shItem(i) = New hItem()
                                    Next
                                    sCount = aValue
                                End If
                            End Set
                        End Property

                        Public ReadOnly Property hItem(ByVal aIndex As Integer) As hItem
                            Get
                                Return shItem(aIndex)
                            End Get
                        End Property

                        Public Function AddItem() As hItem
                            Count += 1
                            Return hItem(Count - 1)
                        End Function

                End Class
