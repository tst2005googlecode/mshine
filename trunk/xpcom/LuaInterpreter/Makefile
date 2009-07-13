#
#	Makefile for Unix/Linux systems
#
COMPONENT = LuaInterpreter
GECKOSDK_DIR := /opt/devel/geckosdk
all: xpt so
xpt:
	@echo Building header and typelib for $(COMPONENT)...
	$(GECKOSDK_DIR)/bin/xpidl -m header -I$(GECKOSDK_DIR)/idl I$(COMPONENT).idl
	$(GECKOSDK_DIR)/bin/xpidl -m typelib -I$(GECKOSDK_DIR)/idl I$(COMPONENT).idl
	@echo Done.
impl:
	@echo TODO
module:
	@echo TODO
so:
	@echo TODO
clean:
	@echo TODO
