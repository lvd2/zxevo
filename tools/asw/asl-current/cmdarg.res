;* decodecmd.res
;*****************************************************************************
;* AS-Portierung                                                             *
;*                                                                           *
;* Definition der Fehlermeldungen, die beim Einlesen auftreten koennen       *
;*                                                                           *
;* Historie:  5. 5.1996 Grundsteinlegung                                     *
;*           18. 4.1999 Fehlermeldung Indirektion im Key-File                *
;*                                                                           *
;*****************************************************************************

Include header.res

Message ErrMsgKeyFileNotFound
 "Key-Datei nicht gefunden"
 "key file not found"

Message ErrMsgKeyFileError
 "Fehler beim Lesen der Key-Datei"
 "error reading key file"

Message ErrMsgNoKeyInFile
 "Referenz auf Key-Datei in Key-Datei nicht erlaubt"
 "no references to a key file from inside a key file"
