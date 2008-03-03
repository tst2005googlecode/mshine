/*
Moonshine
Copyright (c) 2007-2008 Samuel Saint-Pettersen
Released under the MIT License
*/

// display main dialog
function mainDialog() {
    // TODO 
}
// display load dialog 
function loadDialog() {
    const nsIFilePicker = Components.interfaces.nsIFilePicker;
    var fp = Components.classes["@mozilla.org/filepicker;1"]
    .createInstance(nsIFilePicker);
    fp.init(window, "Load application", nsIFilePicker.modeOpen);
    fp.appendFilter("Moonshine application", "*.msh");
    fp.show();
}
