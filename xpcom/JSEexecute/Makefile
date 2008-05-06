#
#	Makefile for JSExecute component
#	for 32-bit Windows systems using GNU Make (MinGW)
#

COMPONENT = JSExecute
GECKOSDK = C:\gecko-sdk
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
	
	
# generate the typelib for the XPCOM component
make:
	xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
	
# remove generated typelib
clean:
	del I$(COMPONENT).xpt

# > BEGIN FOR TESTING ONLY

# register component for Firefox
register:
	copy /Y $(COMPONENT).js "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	regxpcom -x "$(FIREFOX)\components"

# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).js"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	
# < END FOR TESTING ONLY
