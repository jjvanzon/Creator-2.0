''Creator in Generic Creator

'Option Explicit On 
'Option Strict On

'Module Code

'    Sub Main()

'        Dim i As Integer
'        Dim j As Integer

'        Dim ggStructure As hItem
'        ggStructure.hClass = gStructure

'        With ggStructure

'            'Classes

'                With .hRelatedList("gClasses")

'                    'Structure

'                        ReDim .hItems(i)
'                        .hItems(i) = New hItem()
'                        With .hItems(i)
'                            .hItemAttribute("gClassName").hValue = "ggStructure"
'                        End With
'                        i += 1

'                        'Class

'                            ReDim .hItems(i)
'                            .hItems(i) = New hItem()
'                            With .hItems(i)
'                                .hItemAttribute("gClassName").hValue = "ggClass"
'                                With .hRelatedList("gClassAttributes")
'                                    'Class Name
'                                        j = 0
'                                        ReDim .hItems(j)
'                                        .hItems(j) = New hItem()
'                                        With .hItems(j)
'                                            .hItemAttribute("gName").hValue = "ggClassName"
'                                            .hItemAttribute("gType").hValue = "String"
'                                        End With
'                                        j += 1
'                                End With
'                            End With
'                            i += 1

'                            'Class Attribute

'                                ReDim .hItems(i)
'                                .hItems(i) = New hItem()
'                                With .hItems(i)
'                                    .hItemAttribute("gClassName").hValue = "ggClassAttribute"
'                                    With .hRelatedList("gClassAttributes")
'                                        'Name
'                                            j = 0
'                                            ReDim .hItems(j)
'                                            .hItems(j) = New hItem()
'                                            With .hItems(j)
'                                                .hItemAttribute("gName").hValue = "ggName"
'                                                .hItemAttribute("gType").hValue = "String"
'                                            End With
'                                            j += 1
'                                        'Type
'                                            j = 0
'                                            ReDim .hItems(j)
'                                            .hItems(j) = New hItem()
'                                            With .hItems(j)
'                                                .hItemAttribute("gName").hValue = "ggType"
'                                                .hItemAttribute("gType").hValue = "String"
'                                            End With
'                                            j += 1
'                                    End With
'                                End With
'                                i += 1

'                        'Relation

'                            ReDim .hItems(i)
'                            .hItems(i) = New hItem()
'                            With .hItems(i)
'                                .hItemAttribute("gClassName").hValue = "ggRelation"
'                            End With
'                            i += 1

'                            '...

'                End With

'        End With

'    End Sub

'End Module