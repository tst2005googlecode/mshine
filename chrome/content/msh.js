/*
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen
      
 This program is released "as is" under
 the GNU General Public License V3.
*/
// display main window
var mshd;
function MSHdialog()
{
    mshd = window.openDialog("chrome://moonshine/content/msh.xul",
    "mshd","chrome,centerscreen,width=570,height=350");
}
// load moonshine application
function loadMSH()
{
    var nsIFilePicker = Components.interfaces.nsIFilePicker;
    var fp = Components.classes["@mozilla.org/filepicker;1"]
    .createInstance(nsIFilePicker);
    fp.init(window, "Load a Moonshine application", nsIFilePicker.modeOpen);
    fp.appendFilter("MSH applications (*.msh)","*.msh");
    fp.appendFilter("Lua files (*.lua)","*.lua");
    var res = fp.show();  
    if(res == nsIFilePicker.returnOK)
    {
        var file = fp.file;
        alert(file);
    }    
}
// push metadata for application
function pushMetadata()
{

}
// start or stop moonshine application
function execMSH()
{

}

