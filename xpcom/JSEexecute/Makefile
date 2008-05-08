#
#	Makefile for JSExecute component for 32-bit Windows systems
#

# PREQ: Gecko SDK (and Wintools); Touch for Windows

# http://developer.mozilla.org/en/docs/Gecko_SDK#Get_the_SDK
# http://www.codeproject.com/KB/applications/touch_win.aspx

# ASSUMPTION: touch.exe is in your PATH

COMPONENT = JSExecute
GECKOSDK = C:\gecko-sdk
FIREFOX = C:\Program Files\Mozilla Firefox 3 Beta 5
	
# generate the typelib for the XPCOM component
make:
	$(GECKOSDK)\bin\xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
	@echo Generated typelib for $(COMPONENT)
	
# remove generated typelib
clean:
	del I$(COMPONENT).xpt
	@echo Cleaned typelib for $(COMPONENT)

# > BEGIN FOR TESTING ONLY

# copy autoreg file (if required) to allow component registration
autoreg:
	copy /Y .autoreg "$(FIREFOX)"
	@echo Copied .autoreg file to allow component registration

# register component for Firefox
register:
	touch -m "$(FIREFOX)\.autoreg"
	copy /Y $(COMPONENT).js "$(FIREFOX)\components"
	copy /Y I$(COMPONENT).xpt "$(FIREFOX)\components"
	$(GECKOSDK)\bin\regxpcom -x "$(FIREFOX)\components"
	@echo Registered $(COMPONENT)

# remove registered component for Firefox
remove:
	del "$(FIREFOX)\components\$(COMPONENT).js"
	del "$(FIREFOX)\components\I$(COMPONENT).xpt"
	@echo Removed $(COMPONENT)
	
# < END FOR TESTING ONLY
