#
#	Makefile for Moonshine Lua interpreter
#

COMPONENT = MoonshineLua
GECKOSDK = C:\gecko-sdk

# generate header and typelibs for XPCOM component
generate:
	xpidl -m header -I$(GECKOSDK)\idl I$(COMPONENT).idl
	xpidl -m typelib -I$(GECKOSDK)\idl I$(COMPONENT).idl
