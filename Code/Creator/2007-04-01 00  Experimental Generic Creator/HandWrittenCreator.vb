''Hand Written Creator

'    'Alle relaties in het experiment zijn unary.

'    'The same things are described in all the three layers,
'    'but this first layer, does contain search methods,
'    'but these don't have to be included in the higher layers.
'    'And the highest layer may not be finished yet.


'    Option Explicit On 
'    Option Strict On

'    'Structure

'        Class hStructure
'            Public hClasses() As hClass
'            Public hRelations() As hRelation

'            Public Function hClass(ByVal aName As String) As hClass
'                Dim i As Integer
'                For i = 0 To UBound(hClasses)
'                    If Not hClasses(i) Is Nothing Then
'                        If hClasses(i).hClassName = aName Then Return hClasses(i)
'                    End If
'                Next
'            End Function

'        End Class

'        'Class

'            Class hClass
'                Public hClassName As String
'                Public hClassAttributes() As hClassAttribute

'                Public Function hClassAttribute(ByVal aName As String) As hClassAttribute
'                    Dim i As Integer
'                    For i = 0 To UBound(hClassAttributes)
'                        If Not hClassAttributes(i) Is Nothing Then
'                            If hClassAttributes(i).hName = aName Then Return hClassAttributes(i)
'                        End If
'                    Next
'                End Function

'            End Class

'            'Class Attribute

'                Class hClassAttribute
'                    Public hName As String
'                    Public hType As String
'                End Class

'        'Relation

'            Class hRelation
'                Public hRelationClassA As New hRelationClass()
'                Public hRelationClassB As New hRelationClass()
'            End Class

'            'Relation Class

'                Class hRelationClass
'                    Public hClass As hClass
'                    Public hPlural As Boolean
'                    Public hName As String
'                End Class

'    'Global

'        'Item

'            Class hItem
'                Public hClass As hClass
'                Public hItemAttributes() As hItemAttribute
'                Public hRelatedItems() As hItem
'                Public hRelatedLists() As hList

'                Public Function hItemAttribute(ByVal aName As String) As hItemAttribute
'                    Dim i As Integer
'                    For i = 0 To UBound(hItemAttributes)
'                        If Not hItemAttributes(i) Is Nothing Then
'                            If hItemAttributes(i).hClassAttribute.hName = aName Then Return hItemAttributes(i)
'                        End If
'                    Next
'                End Function

'                'Public Function hRelatedItem(ByVal aName As String) As hItem
'                '    Dim i As Integer
'                '    For i = 0 To UBound(hRelatedItems)
'                '        If Not hRelatedItems(i) Is Nothing Then
'                '            If hRelatedItems(i).h  .hClassAttribute.hName = aName Then Return hRelatedItems(i)
'                '        End If
'                '    Next
'                'End Function

'                Public Function hRelatedList(ByVal aName As String) As hList
'                    Dim i As Integer
'                    For i = 0 To UBound(hRelatedLists)
'                        If Not hRelatedLists(i) Is Nothing Then
'                            If hRelatedLists(i).hRelationClass.hName = aName Then Return hRelatedLists(i)
'                        End If
'                    Next
'                End Function

'            End Class

'            'Yet to Add: hRelatedItem

'            'Item Attribute

'                Class hItemAttribute
'                    Public hClassAttribute As hClassAttribute
'                    Public hValue As String
'                End Class

'            'List

'                Class hList
'                    Public hRelationClass As hRelationClass
'                    Public hItems() As hItem
'                End Class
