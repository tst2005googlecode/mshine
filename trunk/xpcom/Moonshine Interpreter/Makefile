#
#	Makefile for Moonshine Lua interpreter for 32-bit Windows systems
#

# PREQ: MS C/C++ compiler and linker; Windows SDK; 
# Gecko SDK (and Wintools); Touch for Windows

# http://www.microsoft.com/express/vc/
# http://urlcut.com/windowsdk
# http://developer.mozilla.org/en/docs/Gecko_SDK#Get_the_SDK
# http://www.codeproject.com/KB/applications/touch_win.aspx

# ASSUMPTIONS: cl.exe, link.exe and touch.exe are in your PATH

COMPONENT = MoonshineLua
GECKOSDK = C:\gecko-sdk
WINSDK = C:\Program Files\Microsoft SDKs\Windows\v6.1
MSVC = C:\Program Files\Microsoft Visual Studio 9.0\VC
SOURCES = MoonshineLua.cpp MoonshineLuaModule.cpp
PPDEFS = WIN32 _DEBUG _WINDOWS _USRDLL LUAINTERPRETER_EXPORTS _UNICODE UNICODE
LIBS = nspr4.lib xpcom.lib xpcomglue_s.lib lua.lib \
kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib \
shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib

FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
		
# build the XPCOM component
make:
	cl /Od /c /I "$(GECKOSDK)\include" /I "$(MSVC)\include" /D "$(PPDEFS)"  \
	/Gm /ZI /EHsc /MDd /Fo"Debug\\" /W3 /nologo /TP $(SOURCES)
	
	link /OUT:"Debug\$(COMPONENT).dll" /NOLOGO \
	/LIBPATH:"$(GECKOSDK)\lib" /LIBPATH:"$(MSVC)\lib" /LIBPATH:"$(WINSDK)\Lib" \
    /DLL /MANIFEST /DEBUG /SUBSYSTEM:WINDOWS /MACHINE:X86 \
	Debug\$(COMPONENT).obj Debug\$(COMPONENT)Module.obj $(LIBS) 	
	
	@echo Built $(COMPONENT).dll
	 
# remove any files created during component creation
clean:
	del /Q Debug\*
	@echo Cleaned created files for $(COMPONENT)

# generate header and typelib for XPCOM component
generate:
	$(GECKOSDK)\bin\xpidl -m header -I$(GECKOSDK)\idl I$(COMPONENT).idl
	$(GECKOSDK)\bin\xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
	@echo Generated header and typelib for $(COMPONENT)

# > BEGIN FOR TESTING ONLY

# copy autoreg file (if required) to allow component registration
autoreg:
	copy /Y .autoreg "$(FIREFOX)"
	@echo Copied .autoreg file to allow component registration

# register component for Firefox
register:
	touch -m "$(FIREFOX)\.autoreg"
	copy /Y Debug\$(COMPONENT).dll "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	$(GECKOSDK)\bin\regxpcom -x "$(FIREFOX)\components"
	@echo Registered $(COMPONENT)
	
# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).dll"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	@echo Removed $(COMPONENT)
	
# < END FOR TESTING ONLY
