/*
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen
      
 This program is released "as is" under
 the GNU General Public License V3.
*/
// display main window
function MSHdialog()
{
    var mshd = window.openDialog("chrome://moonshine/content/msh.xul",
	"mshd","chrome,centerscreen,width=600,height=350");
}

