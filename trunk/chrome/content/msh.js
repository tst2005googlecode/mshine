/*
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen
      
 This program is released "as is" under
 the GNU General Public License V3.
*/
// display main window
function dialog()
{
    var mshd = window.openDialog("chrome://moonshine/content/msh.xul",
    "mshd","chrome,centerscreen,width=570,height=350");
}
// load moonshine application
function load()
{
    var nsIFilePicker = Components.interfaces.nsIFilePicker;
    var fp = Components.classes["@mozilla.org/filepicker;1"]
    .createInstance(nsIFilePicker);
    fp.init(window, "Load a Moonshine application", nsIFilePicker.modeOpen);
    fp.appendFilter("MSH applications (*.msh)","*.msh");
    var res = fp.show();  
    if(res == nsIFilePicker.returnOK)
    {
        var file = fp.file;
        execute(file); //!
    }    
}
// install application in mshapps directory
function install(file)
{
    // if it doesn't exist, create a new mshapps dir
    // and/or copy the application into that directory
    // to begin installation.
    
    // parse metadata for application on installation
    // execute("-m", file)
}
// execute operation to moonshine core interpreter
//function execute(operation, file)
function execute(file)
{
    // create an nsILocalFile for the executable
    var mshc = Components.classes["@mozilla.org/file/local;1"]
    .createInstance(Components.interfaces.nsILocalFile);

    mshc.initWithPath("/usr/bin/gedit");

    // create an nsIProcess 
    var process = Components.classes["@mozilla.org/process/util;1"]
    .createInstance(Components.interfaces.nsIProcess);

    process.init(mshc);

    // run the process with specified arguments
    var args = [file.path];
    process.run(false, args, args.length)
}

