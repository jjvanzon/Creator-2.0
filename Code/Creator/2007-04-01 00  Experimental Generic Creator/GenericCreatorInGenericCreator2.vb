'//
'// Creator Generic Experiment . Generic Creator in Generic Creator
'//
'//     Author: Jan-Joost van Zon
'//     Date: Saturday, February 24, 2007 - Sunday, February 25, 2007
'//
'// -----

'Options

    Option Explicit On 
    Option Strict On

'Modules

    Module CreatorInGenericCreator

        'Declarations

            Public ggStructure As New hItem()

        'Definitions

            Sub Main()

                ggStructure.hClass = gStructure

                With ggStructure

                    With .hRelatedLists

                        'Classes

                            With .hRelatedList("gClasses")

                                'Structure

                                    With .AddItem
                                        With .hItemAttributes
                                            .hItemAttribute("gClassName").hValue = "ggStructure"
                                        End With
                                    End With

                                    'Class

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("gClassName").hValue = "ggClass"
                                            End With
                                            With .hRelatedLists
                                                With .hRelatedList("gClassAttributes")
                                                    'Class Name
                                                        With .AddItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gName").hValue = "ggClassName"
                                                                .hItemAttribute("gType").hValue = "String"
                                                            End With
                                                        End With
                                                End With
                                            End With
                                        End With

                                        'Class Attribute

                                            With .AddItem
                                                With .hItemAttributes
                                                    .hItemAttribute("gClassName").hValue = "ggClassAttribute"
                                                End With
                                                With .hRelatedLists
                                                    With .hRelatedList("gClassAttributes")
                                                        'Name
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("gName").hValue = "ggName"
                                                                    .hItemAttribute("gType").hValue = "String"
                                                                End With
                                                            End With
                                                        'Type
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("gName").hValue = "ggType"
                                                                    .hItemAttribute("gType").hValue = "String"
                                                                End With
                                                            End With
                                                    End With
                                                End With
                                            End With

                                    'Relation

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("gClassName").hValue = "ggRelation"
                                            End With
                                        End With

                                        'Relation Class

                                            With .AddItem
                                                With .hItemAttributes
                                                    .hItemAttribute("gClassName").hValue = "ggRelationClass"
                                                End With
                                                With .hRelatedLists
                                                    With .hRelatedList("gClassAttributes")
                                                        'Plural
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("gName").hValue = "ggPlural"
                                                                    .hItemAttribute("gType").hValue = "Boolean"
                                                                End With
                                                            End With
                                                        'Plural
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("gName").hValue = "ggName"
                                                                    .hItemAttribute("gType").hValue = "String"
                                                                End With
                                                            End With
                                                    End With
                                                End With
                                            End With

                                'Item

                                    With .AddItem
                                        With .hItemAttributes
                                            .hItemAttribute("gClassName").hValue = "ggItem"
                                        End With
                                    End With

                                    'Item Attribute

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("gClassName").hValue = "ggItemAttribute"
                                            End With
                                            With .hRelatedLists
                                                With .hRelatedList("gClassAttributes")
                                                    'Value
                                                        With .AddItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gName").hValue = "ggValue"
                                                                .hItemAttribute("gType").hValue = "String"
                                                            End With
                                                        End With
                                                End With
                                            End With
                                        End With

                                    'Related Item

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("gClassName").hValue = "ggRelatedItem"
                                            End With
                                        End With

                                    'Related List

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("gClassName").hValue = "ggRelatedList"
                                            End With
                                        End With

                            End With

                        'Relations

                            With .hRelatedList("gRelations")

                                'Structure To

                                    'To Classes

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggStructure"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClass"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggClasses"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Relations

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggStructure"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelation"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggRelations"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Class To

                                    'To Class Attributes

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClass"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClassAttribute"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggClassAttributes"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Relation To

                                    'To Relation Class A

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelation"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelationClass"
                                                                .hItemAttribute("gName").hValue = "ggRelationClassA"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Relation Class B

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelation"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelationClass"
                                                                .hItemAttribute("gName").hValue = "ggRelationClassB"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Relation Class To

                                    'To Class

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClass"
                                                                .hItemAttribute("gName").hValue = "ggClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Item To

                                    'To Class

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClass"
                                                                .hItemAttribute("gName").hValue = "ggClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Item Attributes

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItemAttribute"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggItemAttributes"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Related Items

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedItem"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggRelatedItems"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Related Lists

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedList"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggRelatedLists"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Item Attribute To

                                    'To Class Attribute

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItemAttribute"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggClassAttribute"
                                                                .hItemAttribute("gName").hValue = "ggClassAttribute"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Related Item To

                                    'To Relation Class

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelationClass"
                                                                .hItemAttribute("gName").hValue = "ggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Item

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                                .hItemAttribute("gName").hValue = "ggItem"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                'Related List To

                                    'To Relation Class

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedList"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelationClass"
                                                                .hItemAttribute("gName").hValue = "ggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Items

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggRelatedList"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("gRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("gClass").hValue = "ggItem"
                                                                .hItemAttribute("gPlural").hValue = "True"
                                                                .hItemAttribute("gName").hValue = "ggItems"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                            End With

                    End With

                End With

            End Sub

    End Module