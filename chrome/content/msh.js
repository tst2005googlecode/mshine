/*
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen
      
 This program is released "as is" under
 the GNU General Public License V3.
*/
// display main window
function MSHwindow()
{
    var mshw = window.openDialog("chrome://moonshine/content/msh.xul", "mshw", "chrome,centerscreen,width=590,height=350");
}

