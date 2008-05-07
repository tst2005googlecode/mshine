#
#	Makefile for JSExecute component
#	for 32-bit Windows systems using GNU Make (MinGW)
#

# PREQ: MinGW GNU Make; Touch for Windows; 
# Gecko SDK (and Wintools)

# http://www.mingw.org
# http://www.codeproject.com/KB/applications/touch_win.aspx
# http://developer.mozilla.org/en/docs/Gecko_SDK#Get_the_SDK

# ASSUMPTION: touch.exe is in your PATH

COMPONENT = JSExecute
GECKOSDK = C:\gecko-sdk
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
	
# generate the typelib for the XPCOM component
make:
	$(GECKOSDK)\bin\xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
	
# remove generated typelib
clean:
	del I$(COMPONENT).xpt

# > BEGIN FOR TESTING ONLY

# copy autoreg file (if required) to allow component registration
autoreg:
	copy /Y .autoreg "$(FIREFOX)"

# register component for Firefox
register:
	touch -m "$(FIREFOX)\.autoreg"
	copy /Y $(COMPONENT).js "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	$(GECKOSDK)\bin\regxpcom -x "$(FIREFOX)\components"

# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).js"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	
# < END FOR TESTING ONLY
