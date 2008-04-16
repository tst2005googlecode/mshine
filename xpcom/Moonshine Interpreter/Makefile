#
#	Makefile for Moonshine Lua interpreter
#

COMPONENT = MoonshineLua
GECKOSDK = C:\gecko-sdk
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5

# create .autoreg file in order to register a component
prepare:
	notepad "$(FIREFOX)\.autoreg"
	
# generate header and typelibs for XPCOM component
generate:
	xpidl -m header -I$(GECKOSDK)\idl I$(COMPONENT).idl
	xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
	
# register component for firefox
register:
	copy /Y Debug\$(COMPONENT).dll "$(FIREFOX)\components
	regxpcom -x "$(FIREFOX)\components"
	autohotkey updateautoreg.ahk
