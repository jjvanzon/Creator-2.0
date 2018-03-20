'//
'// Creator Generic Experiment . Generic Creator in Hand Written Creator
'//
'//     Author: Jan-Joost van Zon
'//     Date: Saturday, February 24, 2007 - Sunday, February 25, 2007
'//
'// -----

'Options

    Option Explicit On 
    Option Strict On

'Modules

    Module CreatorInHandWrittenCreator

        'Declarations

            Dim hStructure As New hStructure()

            Public gStructure As hClass

            Dim gClass As hClass
            Dim gClassAttribute As hClass
            Dim gRelation As hClass
            Dim gRelationClass As hClass
            Dim gItem As hClass
            Dim gItemAttribute As hClass
            Dim gRelatedItem As hClass
            Dim gRelatedList As hClass

        'Definitions

            Sub Main()

                With hStructure

                    'Classes

                        With .hClasses

                            'Structure

                                With .Add
                                    gStructure = .This
                                    .hClassName = "gStructure"
                                End With

                                'Class

                                    With .Add
                                        gClass = .This
                                        .hClassName = "gClass"
                                        With .hClassAttributes
                                            'Class Name
                                                With .Add
                                                    .hName = "gClassName"
                                                    .hType = "String"
                                                End With
                                        End With
                                    End With

                                    'Class Attribute

                                        With .Add
                                            gClassAttribute = .This
                                            .hClassName = "gClassAttribute"
                                            With .hClassAttributes
                                                'Name
                                                    With .Add
                                                        .hName = "gName"
                                                        .hType = "String"
                                                    End With
                                                'Type
                                                    With .Add
                                                        .hName = "gType"
                                                        .hType = "String"
                                                    End With
                                            End With
                                        End With

                                'Relation

                                    With .Add
                                        gRelation = .This
                                        .hClassName = "gRelation"
                                    End With

                                    'Relation Class

                                        With .Add
                                            gRelationClass = .This
                                            .hClassName = "gRelationClass"
                                            With .hClassAttributes
                                                'Plural
                                                    With .Add
                                                        .hName = "gPlural"
                                                        .hType = "Boolean"
                                                    End With
                                                'Name
                                                    With .Add
                                                        .hName = "gName"
                                                        .hType = "String"
                                                    End With
                                            End With
                                        End With

                            'Item

                                With .Add
                                    gItem = .This
                                    .hClassName = "gItem"
                                End With

                                'Item Attribute

                                    With .Add
                                        gItemAttribute = .This
                                        .hClassName = "gItemAttribute"
                                        With .hClassAttributes
                                            'Value
                                                With .Add
                                                    .hName = "gValue"
                                                    .hType = "String"
                                                End With
                                        End With
                                    End With

                                'Related Item

                                    With .Add
                                        gRelatedItem = .This
                                        .hClassName = "gRelatedItem"
                                    End With

                                'Related List

                                    With .Add
                                        gRelatedList = .This
                                        .hClassName = "gRelatedList"
                                    End With

                        End With

                    'Relations

                        With .hRelations

                            'Structure To

                                'To Classes

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gStructure
                                        End With
                                        With .hRelationClassB
                                            .hClass = gClass
                                            .hPlural = True
                                            .hName = "gClasses"
                                        End With
                                    End With

                                'To Relations

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gStructure
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelation
                                            .hPlural = True
                                            .hName = "gRelations"
                                        End With
                                    End With

                            'Class To

                                'To Class Attributes

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gClass
                                        End With
                                        With .hRelationClassB
                                            .hClass = gClassAttribute
                                            .hPlural = True
                                            .hName = "gClassAttributes"
                                        End With
                                    End With

                            'Relation To

                                'To Relation Class A

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelation
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelationClass
                                            .hName = "gRelationClassA"
                                        End With
                                    End With

                                'To Relation Class B

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelation
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelationClass
                                            .hName = "gRelationClassB"
                                        End With
                                    End With

                            'Relation Class To

                                'To Class

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelationClass
                                        End With
                                        With .hRelationClassB
                                            .hClass = gClass
                                            .hName = "gClass"
                                        End With
                                    End With

                            'Item To

                                'To Class

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gClass
                                            .hName = "gClass"
                                        End With
                                    End With

                                'To Item Attributes

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gItemAttribute
                                            .hPlural = True
                                            .hName = "gItemAttributes"
                                        End With
                                    End With

                                'To Related Items

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelatedItem
                                            .hPlural = True
                                            .hName = "gRelatedItems"
                                        End With
                                    End With

                                'To Related Lists

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelatedList
                                            .hPlural = True
                                            .hName = "gRelatedLists"
                                        End With
                                    End With

                            'Item Attribute To

                                'To Class Attribute

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gItemAttribute
                                        End With
                                        With .hRelationClassB
                                            .hClass = gClassAttribute
                                            .hName = "gClassAttribute"
                                        End With
                                    End With

                            'Related Item To

                                'To Relation Class

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelatedItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelationClass
                                            .hName = "gRelationClass"
                                        End With
                                    End With

                                'To Item

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelatedItem
                                        End With
                                        With .hRelationClassB
                                            .hClass = gItem
                                            .hPlural = True
                                            .hName = "gItem"
                                        End With
                                    End With

                            'Related List To

                                'To Relation Class

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelatedList
                                        End With
                                        With .hRelationClassB
                                            .hClass = gRelationClass
                                            .hName = "gRelationClass"
                                        End With
                                    End With

                                'To Items

                                    With .Add
                                        With .hRelationClassA
                                            .hClass = gRelatedList
                                        End With
                                        With .hRelationClassB
                                            .hClass = gItem
                                            .hPlural = True
                                            .hName = "gItems"
                                        End With
                                    End With

                        End With

                End With

            End Sub

    End Module
