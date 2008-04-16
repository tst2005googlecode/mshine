; Modify date for .autoreg file
; This finalises an XPCOM component registration
; 
; This is an AutoHotKey script; to run it you need AutoHotkey:
; http://www.autohotkey.com

RegFile = C:\Program Files\Mozilla Firefox 3 Beta 5\.autoreg
FileSetTime, %RegFile%
MsgBox, %RegFile%

