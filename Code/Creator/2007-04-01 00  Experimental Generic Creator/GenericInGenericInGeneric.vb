'//
'// Creator Generic Experiment . Generic Creator in Generic Creator
'//
'//     Author: Jan-Joost van Zon
'//     Date: Saturday, February 24, 2007 - Sunday, February 25, 2007
'//
'// -----
'//
'// -----

'Options

    Option Explicit On 
    Option Strict On

'Modules

    Module CreatorInGenericGenericCreator

        'Declarations

            Public gggStructure As New hItem()

        'Definitions

            Sub Main()

                gggStructure.hClassGenericallyDescribed = ggStructure

                With gggStructure

                    With .hRelatedLists

                        'Classes

                            With .hRelatedList("ggClasses")

                                'Structure

                                    With .AddItem
                                        With .hItemAttributes
                                            .hItemAttribute("ggClassName").hValue = "gggStructure"
                                        End With
                                    End With

                                    'Class

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("ggClassName").hValue = "gggClass"
                                            End With
                                            With .hRelatedLists
                                                With .hRelatedList("ggClassAttributes")
                                                    'Class Name
                                                        With .AddItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggName").hValue = "gggClassName"
                                                                .hItemAttribute("ggType").hValue = "Stringg"
                                                            End With
                                                        End With
                                                End With
                                            End With
                                        End With

                                        'Class Attribute

                                            With .AddItem
                                                With .hItemAttributes
                                                    .hItemAttribute("ggClassName").hValue = "gggClassAttribute"
                                                End With
                                                With .hRelatedLists
                                                    With .hRelatedList("ggClassAttributes")
                                                        'Name
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("ggName").hValue = "gggName"
                                                                    .hItemAttribute("ggType").hValue = "Stringg"
                                                                End With
                                                            End With
                                                        'Type
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("ggName").hValue = "gggType"
                                                                    .hItemAttribute("ggType").hValue = "Stringg"
                                                                End With
                                                            End With
                                                    End With
                                                End With
                                            End With

                                    'Relation

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("ggClassName").hValue = "gggRelation"
                                            End With
                                        End With

                                        'Relation Class

                                            With .AddItem
                                                With .hItemAttributes
                                                    .hItemAttribute("ggClassName").hValue = "gggRelationClass"
                                                End With
                                                With .hRelatedLists
                                                    With .hRelatedList("ggClassAttributes")
                                                        'Plural
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("ggName").hValue = "gggPlural"
                                                                    .hItemAttribute("ggType").hValue = "Boolean"
                                                                End With
                                                            End With
                                                        'Plural
                                                            With .AddItem
                                                                With .hItemAttributes
                                                                    .hItemAttribute("ggName").hValue = "gggName"
                                                                    .hItemAttribute("ggType").hValue = "Stringg"
                                                                End With
                                                            End With
                                                    End With
                                                End With
                                            End With

                                'Item

                                    With .AddItem
                                        With .hItemAttributes
                                            .hItemAttribute("ggClassName").hValue = "gggItem"
                                        End With
                                    End With

                                    'Item Attribute

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("ggClassName").hValue = "gggItemAttribute"
                                            End With
                                            With .hRelatedLists
                                                With .hRelatedList("ggClassAttributes")
                                                    'Value
                                                        With .AddItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggName").hValue = "gggValue"
                                                                .hItemAttribute("ggType").hValue = "Stringg"
                                                            End With
                                                        End With
                                                End With
                                            End With
                                        End With

                                    'Related Item

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("ggClassName").hValue = "gggRelatedItem"
                                            End With
                                        End With

                                    'Related List

                                        With .AddItem
                                            With .hItemAttributes
                                                .hItemAttribute("ggClassName").hValue = "gggRelatedList"
                                            End With
                                        End With

                            End With

                        'Relations

                            With .hRelatedList("ggRelations")

                                'Structure To

                                    'To Classes

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggStructure"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClass"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggClasses"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Relations

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class A
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggStructure"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelation"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggRelations"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClass"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClassAttribute"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggClassAttributes"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelation"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelationClass"
                                                                .hItemAttribute("ggName").hValue = "gggRelationClassA"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Relation Class B

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelation"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelationClass"
                                                                .hItemAttribute("ggName").hValue = "gggRelationClassB"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClass"
                                                                .hItemAttribute("ggName").hValue = "gggClass"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClass"
                                                                .hItemAttribute("ggName").hValue = "gggClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Item Attributes

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItemAttribute"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggItemAttributes"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Related Items

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedItem"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggRelatedItems"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Related Lists

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedList"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggRelatedLists"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItemAttribute"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggClassAttribute"
                                                                .hItemAttribute("ggName").hValue = "gggClassAttribute"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelationClass"
                                                                .hItemAttribute("ggName").hValue = "gggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Item

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedItem"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                                .hItemAttribute("ggName").hValue = "gggItem"
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
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedList"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelationClass"
                                                                .hItemAttribute("ggName").hValue = "gggRelationClass"
                                                            End With
                                                        End With
                                                    End With
                                            End With
                                        End With

                                    'To Items

                                        With .AddItem
                                            With .hRelatedItems
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassA")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggRelatedList"
                                                            End With
                                                        End With
                                                    End With
                                                'Relation Class B
                                                    With .hRelatedItem("ggRelationClassB")
                                                        With .hItem
                                                            With .hItemAttributes
                                                                .hItemAttribute("ggClass").hValue = "gggItem"
                                                                .hItemAttribute("ggPlural").hValue = "True"
                                                                .hItemAttribute("ggName").hValue = "gggItems"
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