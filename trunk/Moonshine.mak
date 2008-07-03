#
#	Makefile for Moonshine extension for NMAKE on Windows
#

# PREQ: 7-Zip, Firefox

# ASSUMPTION: 7z.exe is in your PATH

EXTENSION = Moonshine
CONTENTS = 
FIREFOX_DIR = C:\Program Files\Mozilla Firefox

make:
	@echo nmake build /f $(EXTENSION).mak - build extension file (XPI)
	@echo nmake install /f $(EXTENSION).mak - install in Firefox

build:
	7z 