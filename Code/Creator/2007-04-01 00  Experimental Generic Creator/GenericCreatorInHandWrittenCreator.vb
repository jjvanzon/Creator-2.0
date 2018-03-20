''Creator in Hand Written Creator

'Option Explicit On 
'Option Strict On

'Module CreatorInHandWrittenCreator

'    Public hStructure As New hStructure()

'    Public gStructure As hClass

'    Dim gClass As hClass
'    Dim gClassAttribute As hClass
'    Dim gRelation As hClass
'    Dim gRelationClass As hClass
'    Dim gItem As hClass
'    Dim gItemAttribute As hClass
'    Dim gList As hClass

'    Sub Main()

'        With hStructure

'            'Classes

'                'Structure

'                    ReDim .hClasses(0)
'                    .hClasses(0) = New hClass()
'                    gStructure = .hClasses(0)
'                    With .hClasses(0)
'                        .hClassName = "gStructure"
'                    End With

'                    'Class

'                        ReDim .hClasses(1)
'                        .hClasses(1) = New hClass()
'                        gClass = .hClasses(1)
'                        With .hClasses(1)
'                            .hClassName = "gClass"
'                            'Class Name
'                                ReDim .hClassAttributes(0)
'                                .hClassAttributes(0) = New hClassAttribute()
'                                With .hClassAttributes(0)
'                                    .hName = "gClassName"
'                                    .hType = "String"
'                                End With
'                        End With

'                        'Class Attribute

'                            ReDim .hClasses(2)
'                            .hClasses(2) = New hClass()
'                            gClassAttribute = .hClasses(2)
'                            With .hClasses(2)
'                                .hClassName = "gClassAttribute"
'                                'Name
'                                    ReDim Preserve .hClassAttributes(0)
'                                    .hClassAttributes(0) = New hClassAttribute()
'                                    With .hClassAttributes(0)
'                                        .hName = "gName"
'                                        .hType = "String"
'                                    End With
'                                'Type
'                                    ReDim Preserve .hClassAttributes(1)
'                                    .hClassAttributes(1) = New hClassAttribute()
'                                    With .hClassAttributes(1)
'                                        .hName = "gType"
'                                        .hType = "String"
'                                    End With
'                            End With

'                    'Relation

'                        ReDim .hClasses(3)
'                        .hClasses(3) = New hClass()
'                        gRelation = .hClasses(3)
'                        With .hClasses(3)
'                            .hClassName = "gRelation"
'                        End With

'                        'Relation Class

'                            ReDim .hClasses(4)
'                            .hClasses(4) = New hClass()
'                            gRelationClass = .hClasses(4)
'                            With .hClasses(4)
'                                .hClassName = "gRelationClass"
'                                'Class
'                                    ReDim Preserve .hClassAttributes(0)
'                                    .hClassAttributes(0) = New hClassAttribute()
'                                    With .hClassAttributes(0)
'                                        .hName = "gClass"
'                                        .hType = "hClass"
'                                    End With
'                                'Plural
'                                    ReDim Preserve .hClassAttributes(1)
'                                    .hClassAttributes(1) = New hClassAttribute()
'                                    With .hClassAttributes(1)
'                                        .hName = "hPlural"
'                                        .hType = "Boolean"
'                                    End With
'                                'Name
'                                    ReDim Preserve .hClassAttributes(2)
'                                    .hClassAttributes(2) = New hClassAttribute()
'                                    With .hClassAttributes(2)
'                                        .hName = "hName"
'                                        .hType = "String"
'                                    End With
'                            End With

'                'Item

'                    ReDim .hClasses(5)
'                    .hClasses(5) = New hClass()
'                    gItem = .hClasses(5)
'                    With .hClasses(5)
'                        .hClassName = "gItem"
'                        'Class
'                            ReDim Preserve .hClassAttributes(0)
'                            .hClassAttributes(0) = New hClassAttribute()
'                            With .hClassAttributes(0)
'                                .hName = "gClass"
'                                .hType = "gClass"
'                            End With
'                    End With

'                    'Item Attribute

'                        ReDim .hClasses(6)
'                        .hClasses(6) = New hClass()
'                        gItemAttribute = .hClasses(6)
'                        With .hClasses(6)
'                            .hClassName = "gItemAttribute"
'                            'ClassAttribute
'                                ReDim Preserve .hClassAttributes(0)
'                                .hClassAttributes(0) = New hClassAttribute()
'                                With .hClassAttributes(0)
'                                    .hName = "gClassAttribute"
'                                    .hType = "gClassAttribute"
'                                End With
'                            'Value
'                                ReDim Preserve .hClassAttributes(1)
'                                .hClassAttributes(1) = New hClassAttribute()
'                                With .hClassAttributes(1)
'                                    .hName = "gValue"
'                                    .hType = "String"
'                                End With
'                        End With

'                    'List

'                        ReDim .hClasses(7)
'                        .hClasses(7) = New hClass()
'                        gList = .hClasses(7)
'                        With .hClasses(7)
'                            .hClassName = "gList"
'                        End With

'            'Relations

'                'Structure To

'                    'To Classes

'                        ReDim .hRelations(0)
'                        .hRelations(0) = New hRelation()
'                        With .hRelations(0)
'                            With .hRelationClassA
'                                .hClass = gStructure
'                            End With
'                            With .hRelationClassB
'                                .hClass = gClass
'                                .hPlural = True
'                                .hName = "gClasses"
'                            End With
'                        End With

'                    'To Relations

'                        ReDim .hRelations(1)
'                        .hRelations(1) = New hRelation()
'                        With .hRelations(1)
'                            With .hRelationClassA
'                                .hClass = gStructure
'                            End With
'                            With .hRelationClassB
'                                .hClass = gRelation
'                                .hPlural = True
'                                .hName = "gRelations"
'                            End With
'                        End With

'                'Class To

'                    'To Class Attributes

'                        ReDim .hRelations(2)
'                        .hRelations(2) = New hRelation()
'                        With .hRelations(2)
'                            With .hRelationClassA
'                                .hClass = gClass
'                            End With
'                            With .hRelationClassB
'                                .hClass = gClassAttribute
'                                .hPlural = True
'                                .hName = "gClassAttributes"
'                            End With
'                        End With

'                'Relation To

'                    'To Relation Class A

'                        ReDim .hRelations(3)
'                        .hRelations(3) = New hRelation()
'                        With .hRelations(3)
'                            With .hRelationClassA
'                                .hClass = gRelation
'                            End With
'                            With .hRelationClassB
'                                .hClass = gRelationClass
'                                .hName = "gRelationClassA"
'                            End With
'                        End With

'                    'To Relation Class B

'                        ReDim .hRelations(4)
'                        .hRelations(4) = New hRelation()
'                        With .hRelations(4)
'                            With .hRelationClassA
'                                .hClass = gRelation
'                            End With
'                            With .hRelationClassB
'                                .hClass = gRelationClass
'                                .hName = "gRelationClassB"
'                            End With
'                        End With

'                'Relation Class To

'                    'To Class

'                        ReDim .hRelations(5)
'                        .hRelations(5) = New hRelation()
'                        With .hRelations(5)
'                            With .hRelationClassA
'                                .hClass = gRelationClass
'                            End With
'                            With .hRelationClassB
'                                .hClass = gClass
'                                .hName = "gClass"
'                            End With
'                        End With

'                'Item To

'                    'To Class

'                        ReDim .hRelations(6)
'                        .hRelations(6) = New hRelation()
'                        With .hRelations(6)
'                            With .hRelationClassA
'                                .hClass = gItem
'                            End With
'                            With .hRelationClassB
'                                .hClass = gClass
'                                .hName = "gClass"
'                            End With
'                        End With

'                    'To Item Attributes

'                        ReDim .hRelations(7)
'                        .hRelations(7) = New hRelation()
'                        With .hRelations(7)
'                            With .hRelationClassA
'                                .hClass = gItem
'                            End With
'                            With .hRelationClassB
'                                .hClass = gItemAttribute
'                                .hPlural = True
'                                .hName = "gItemAttributes"
'                            End With
'                        End With

'                    'To Related Items

'                        ReDim .hRelations(8)
'                        .hRelations(8) = New hRelation()
'                        With .hRelations(8)
'                            With .hRelationClassA
'                                .hClass = gItem
'                            End With
'                            With .hRelationClassB
'                                .hClass = gItem
'                                .hPlural = True
'                                .hName = "gRelatedItems"
'                            End With
'                        End With

'                    'To Related Lists

'                        ReDim .hRelations(9)
'                        .hRelations(9) = New hRelation()
'                        With .hRelations(9)
'                            With .hRelationClassA
'                                .hClass = gItem
'                            End With
'                            With .hRelationClassB
'                                .hClass = gList
'                                .hPlural = True
'                                .hName = "gLists"
'                            End With
'                        End With

'                'Item Attribute To

'                    'To Class Attribute

'                        ReDim .hRelations(10)
'                        .hRelations(10) = New hRelation()
'                        With .hRelations(10)
'                            With .hRelationClassA
'                                .hClass = gItemAttribute
'                            End With
'                            With .hRelationClassB
'                                .hClass = gClassAttribute
'                                .hName = "gClassAttribute"
'                            End With
'                        End With

'                'List To

'                    'To Relation Class

'                        ReDim .hRelations(11)
'                        .hRelations(11) = New hRelation()
'                        With .hRelations(11)
'                            With .hRelationClassA
'                                .hClass = gList
'                            End With
'                            With .hRelationClassB
'                                .hClass = gRelationClass
'                                .hPlural = True
'                                .hName = "gRelationClass"
'                            End With
'                        End With

'                    'To Items

'                        ReDim .hRelations(12)
'                        .hRelations(12) = New hRelation()
'                        With .hRelations(12)
'                            With .hRelationClassA
'                                .hClass = gList
'                            End With
'                            With .hRelationClassB
'                                .hClass = gItem
'                                .hPlural = True
'                                .hName = "gItems"
'                            End With
'                        End With

'        End With

'    End Sub

'End Module
