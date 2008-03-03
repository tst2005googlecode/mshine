# Makefile to build and install Moonshine
# as an XPI package for Firefox

ARCHIVER=7z
ARGUMENTS=a -tzip
XPIPACKAGE=moonshine.xpi
CONTENTS=chrome chrome.manifest install.rdf
BROWSER=/alt/firefox/firefox

make:
	${ARCHIVER} ${ARGUMENTS} ${XPIPACKAGE} ${CONTENTS}
	reset
install:
	${BROWSER} ${XPIPACKAGE}
