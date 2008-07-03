#
#	Makefile for Moonshine extension for GNU Make on
#   Windows/Unix/Linux/Mac OS X
#

# PREQ: 7-Zip and Firefox

# ASSUMPTION: 7z(.exe) is in your PATH

EXTENSION = moonshine
FILES = install.rdf chrome.manifest AUTHORS.txt COPYING.txt
FIREFOX_DIR_U = /usr/bin/firefox/
FIREFOX_DIR_M = null
FIREFOX_DIR_W = C:\Program Files\Mozilla Firefox\

make:
	@echo make build  - build extension file (XPI)
	@echo make install - install in Firefox
	@echo make clean - clean any built files

build:
	@cd chrome
	7z a -tzip -mx=0 $(EXTENSION).jar *
	7z d $(EXTENSION).jar *.svn -r
	@echo Built JAR
	@cd.. # for some reason cd.. doesn't work on Windows
	7z a -tzip -mx=9 $(EXTENSION).xpi $(FILES) chrome\$(EXTENSION).jar 
	@echo Built XPI

install:
	"$(FIREFOX_DIR_W)firefox.exe" $(EXTENSION).xpi

clean:
	rm $(EXTENSION).xpi
	rm chrome\$(EXTENSION).jar
	@echo Cleaned built files
