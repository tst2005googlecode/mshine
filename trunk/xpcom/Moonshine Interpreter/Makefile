#
#	Makefile for Moonshine Lua interpreter
#	for 32-bit Windows systems using GNU Make (MinGW)
#

# PREQ: MinGW GNU Make; MS C/C++ compiler and linker; Touch for Windows; 
# Gecko SDK (and Wintools)

# http://www.mingw.org
# http://urlcut.com/windowsdk
# http://www.codeproject.com/KB/applications/touch_win.aspx
# http://developer.mozilla.org/en/docs/Gecko_SDK#Get_the_SDK

# ASSUMPTIONS: make.exe, cl.exe, link.exe and touch.exe are in your PATH


COMPONENT = MoonshineLua
GECKOSDK = C:\gecko-sdk
SOURCES = MoonshineLua.cpp MoonshineLuaModule.cpp
PPDEFS = WIN32;_DEBUG;_WINDOWS;_USRDLL;LUAINTERPRETER_EXPORTS
LIBS = nspr4.lib xpcom.lib xpcomglue_s.lib lua.lib
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
		
# create the XPCOM component
make:
	# TODO!

# remove any files created during compilation
clean:
	del $(COMPONENT).dll
	del $(COMPONENT).xpt

# generate header and typelibs for XPCOM component
generate:
	$(GECKOSDK)\bin\xpidl -m header -I$(GECKOSDK)\idl I$(COMPONENT).idl
	$(GECKOSDK)\bin\xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl


# > BEGIN FOR TESTING ONLY

# copy autoreg file (if required) to allow component registration
autoreg:
	copy /Y .autoreg "$(FIREFOX)"

# register component for Firefox
register:
	touch -m "$(FIREFOX)\.autoreg"
	copy /Y Debug\$(COMPONENT).dll "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	$(GECKOSDK)\bin\regxpcom -x "$(FIREFOX)\components"
	
# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).dll"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	
# < END FOR TESTING ONLY
