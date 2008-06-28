#
#	Makefile for MoonshineLua for NMAKE on Windows
#

# PREQ: Visual Studio, Touch for Windows, Gecko SDK, Firefox

# ASSUMPTION: devenv.exe and touch.exe are in your PATH

COMPONENT = MoonshineLua
FIREFOX_DIR = C:\Program Files\Mozilla Firefox
GECKOSDK_DIR = C:\gecko-sdk

make:
	@echo nmake build /f $(COMPONENT).mak - build XPCOM component
	@echo nmake generate /f $(COMPONENT).mak - generate header and typelib for XPCOM
	@echo nmake autoreg /f $(COMPONENT).mak - when first registering component
	@echo nmake register /f $(COMPONENT).mak - register component with Firefox
	@echo nmake clean /f $(COMPONENT).mak - remove files created during building
	@echo nmake remove /f $(COMPONENT).mak - remove component from Firefox
	
build:
	devenv $(COMPONENT).sln /build Debug /project $(COMPONENT).vcproj /projectconfig Debug 
	@echo Built $(COMPONENT) as stack
	
generate:
	$(GECKOSDK_DIR)\bin\xpidl -m header -I$(GECKOSDK_DIR)\idl I$(COMPONENT).idl
	$(GECKOSDK_DIR)\bin\xpidl -m typelib -I$(GECKOSDK_DIR)\idl I$(COMPONENT).idl
	@echo Generated header and typelib for $(COMPONENT)
	
autoreg:
	copy /Y .autoreg "$(FIREFOX_DIR)"
	@echo Copied .autoreg file to allow component registration
	
register:
	touch -m "$(FIREFOX)\.autoreg"
	copy /Y Debug\$(COMPONENT).dll "$(FIREFOX_DIR)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX_DIR)\components"
	$(GECKOSDK_DIR)\bin\regxpcom -x "$(FIREFOX_DIR)\components"
	@echo Registered $(COMPONENT)

clean:
	devenv $(COMPONENT).sln /clean Debug /project $(COMPONENT).vcproj /projectconfig Debug 
	
remove:
	del "$(FIREFOX_DIR)\components\$(COMPONENT).dll"
	del "$(FIREFOX_DIR)\components\I$(COMPONENT).xpt"
	@echo Removed $(COMPONENT)
