/*
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen
      
 This program is released "as is" under
 the GNU General Public License V3.
*/
var xmlDoc, file, app, lua;
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
        app = fp.file;
        installA();
    }    
}
// install application in msh_apps directory
function installA()
{
    // if it doesn't exist, create a new mshapps dir
    var file = Components.classes["@mozilla.org/file/directory_service;1"]
    .getService(Components.interfaces.nsIProperties)
    .get("ProfD", Components.interfaces.nsIFile);
    file.append("msh_apps");
    if(!file.exists() || !file.isDirectory())
    {
        file.create(Components.interfaces.nsIFile.DIRECTORY_TYPE, 0777);
    } 
    // if it doesn't exist, create a new apps.xml
    file.append("apps.xml");
    if(!file.exists())
    {
        file.create(Components.interfaces.nsIFile.NORMAL_FILE_TYPE, 0664);
        alert("Created new: " + file.leafName); //!
    
        // create and write base structure for apps.xml
        var data = '<?xml version="1.0" encoding="utf-8" standalone="yes"?>\n'
        + '<!-- apps.xml file referencing msh applications -->\n'
        + '<mshapps xmlns="mshine.googlecode.com">\n';
        var foStream = Components.classes["@mozilla.org/network/file-output-stream;1"]
        .createInstance(Components.interfaces.nsIFileOutputStream);
        foStream.init(file, 0x02 | 0x08 | 0x20, 0666, 0); // write, create, truncate
        foStream.write(data, data.length);
        foStream.close(); 
    }
    xmlDoc = document.implementation.createDocument("","",null);
    xmlDoc.load("helloworld.msh"); // app.path???
    xmlDoc.onload = installB;
}
function installB()
{
	alert(xmlDoc.getElementsByTagName("name")[0].firstChild.nodeValue); //!
}
// execute application using moonshine core interpreter
function execute()
{
    // create an nsILocalFile for the executable
    var mshc = Components.classes["@mozilla.org/file/local;1"]
    .createInstance(Components.interfaces.nsILocalFile);
    
    // specify executable, depending on platform
    if(navigator.appVersion.indexOf("X11") != -1) 
    {
        // for unix/linux platforms
        mshc.initWithPath("/usr/bin/gedit"); 
    }
    else if(navigator.appVersion.indexOf("Win") != -1)
    {
	    // for windows platforms
	    mshc.initWithPath("c:\\windows\\notepad.exe");
    }
    else
    {   
        // error message for unsupported platforms
        alert("Could not execute the application.\n" +
        "Because a version of the MSH core intepreter\n" +
        "does not exist for your platform.");   
    }
    // create an nsIProcess 
    var process = Components.classes["@mozilla.org/process/util;1"]
    .createInstance(Components.interfaces.nsIProcess);
    
    // initialize the process
    process.init(mshc);

    // run the process with specified arguments
    //var args = [lua.path];
    process.run(false, args, args.length)
}

