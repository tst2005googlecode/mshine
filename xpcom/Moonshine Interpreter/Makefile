#
#	Makefile for Moonshine Lua interpreter
#	for 32-bit Windows systems using GNU Make (MinGW)
#


COMPONENT = MoonshineLua
GECKOSDK = C:\gecko-sdk
SOURCES = MoonshineLua.cpp MoonshineLuaModule.cpp
PPDEFS = WIN32;_DEBUG;_WINDOWS;_USRDLL;LUAINTERPRETER_EXPORTS
LIBS = nspr4.lib xpcom.lib xpcomglue_s.lib lua.lib
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
	
	
# create the XPCOM component
make:
	@echo "TODO"

# remove any files created during compilation
clean:
	del $(COMPONENT).dll
	del $(COMPONENT).xpt

# generate header and typelibs for XPCOM component
generate:
	xpidl -m header -I$(GECKOSDK)\idl I$(COMPONENT).idl
	xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl


# > BEGIN FOR TESTING ONLY

# register component for Firefox
register:
	copy /Y Debug\$(COMPONENT).dll "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	regxpcom -x "$(FIREFOX)\components"
	
# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).dll"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	
# < END FOR TESTING ONLY
