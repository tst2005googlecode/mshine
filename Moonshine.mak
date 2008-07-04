#
#	Makefile for Moonshine extension for NMAKE on Windows
#

# PREQ: 7-Zip and Firefox

# ASSUMPTION: 7z.exe is in your PATH

EXTENSION = moonshine
FILES = install.rdf chrome.manifest
FIREFOX_DIR = C:\Program Files\Mozilla Firefox

make:
	@echo nmake build /f $(EXTENSION).mak - build extension file (XPI)
	@echo nmake install /f $(EXTENSION).mak - install in Firefox
	@echo nmake clean /f $(EXTENSION).mak - clean any built files

build:
	@cd chrome
	7z a -tzip -mx=0 $(EXTENSION).jar *
	7z d $(EXTENSION).jar *.svn -r
	@echo Built JAR
	@cd..
	7z a -tzip -mx=9 $(EXTENSION).xpi $(FILES) components chrome/$(EXTENSION).jar 
	7z d $(EXTENSION).xpi *.svn -r
	@echo Built XPI

install:
	"$(FIREFOX_DIR)\firefox.exe" $(EXTENSION).xpi

clean:
	@del $(EXTENSION).xpi
	@del chrome\$(EXTENSION).jar
	@echo Cleaned built files
