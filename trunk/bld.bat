@rem build moonshine extension
del moonshine.xpi
7z a -tzip moonshine.xpi chrome chrome.manifest install.rdf
cls
dir
