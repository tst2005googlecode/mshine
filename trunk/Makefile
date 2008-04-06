# Makefile to build and install Moonshine
# as an XPI package for Firefox

ARCHIVER=7z
ARGUMENTS=a -tzip
XPIPACKAGE=moonshine.xpi
CONTENTS=chrome chrome.manifest install.rdf
CHORMEDIR=chrome
BUILDDIR=build

make:
	${ARCHIVER} ${ARGUMENTS} ${XPIPACKAGE} ${CONTENTS}
i:
	firefox ${XPIPACKAGE}
