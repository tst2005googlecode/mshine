# Makefile to build and install Moonshine
# as an XPI package for Firefox

XPI = moonshine.xpi
CONTENTS = chrome chrome.manifest install.rdf
CHORME = chrome
BUILD = build

make:
	7z a -tzip $(XPI) $(CONTENTS)
install:
	firefox $(XPI)
