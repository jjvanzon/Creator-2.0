              // Dim i As Long
                    int i ;
              // Dim tFileNumber As Long
                    HANDLE tFileHandle ;
              // Dim tFilePosition As Long
              // Dim tInteger As Integer
                    short tShort ;
              // Dim tByte As Byte
                    char tByte ;
              // tFileNumber = FreeFile
              // Open FilePath For Binary As tFileNumber
                    CString tFilePath = aThis -> ItemMethods ( ) -> ParentItem ( ) -> ItemAttributes ( ) -> Item ( "File Path" ) -> Value ( ) ;
                    tFileHandle = CreateFile ( tFilePath , GENERIC_READ , FILE_SHARE_READ , 0 , OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , 0 ) ;
                    if ( tFileHandle == INVALID_HANDLE_VALUE ) { return ; }
              // For i = 1 To BytesToSkip
                    CItem* tItem = aThis -> ItemMethods ( ) -> ParentItem ( ) ;
                    int tBytesToSkip = StringToInteger ( tItem -> ItemAttributes ( ) -> Item ( "Bytes To Skip" ) -> Value ( ) ) ;
                    DWORD tBytesRead ;
                    for ( i = 1 ; i <= tBytesToSkip ; i ++ ) {
                          // Get tFileNumber, , tByte
                                ReadFile ( tFileHandle , & tByte , 1 , & tBytesRead , 0 ) ;
                    }
              // ReDim Samples((LOF(tFileNumber) - BytesToSkip) / 2)
                    CRelatedList* tSamples = tItem -> RelatedLists ( ) -> Item ( "Samples" ) ;
                    tSamples -> Clear ( ) ;
              // For i = 1 To (LOF(tFileNumber) - BytesToSkip) / 2
                    CItem* tSample ;
                    // Get tFileNumber, , tInteger
                    while ( ReadFile ( tFileHandle , &tShort , 2 , & tBytesRead , 0 ) ) {
                          if ( tBytesRead == 0 ) { break ; } ;
                          tSample = tSamples -> Add ( ) ;
                          // Samples(i) = tInteger
                                tSample -> ItemAttributes ( ) -> Item ( "Value" ) -> Value ( ShortToString ( tShort ) ) ;
                    }
              // Close tFileNumber
                    CloseHandle ( tFileHandle ) ;
              // Loaded = True
                    tItem -> ItemAttributes ( ) -> Item ( "Loaded" ) -> Value ( "True" ) ;