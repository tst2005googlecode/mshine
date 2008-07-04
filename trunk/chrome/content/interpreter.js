/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	Utilise Lua interpreter along with MoPicchu queue within Firefox
*/

// Define contract ID for Lua interpreter component
const luaCID = "@mshine.googlecode.com/MoonshineLua;1";

// Define constact ID for MoPicchu queue component
const mpCID = "@mopicchu.googlecode.com/MoPicchu;1";

// Create new instance of Lua interpreter component
var lua = Components.classes[luaCID].createInstance();
lua = lua.QueryInterface(Components.interfaces.ILuaInterpreter);

// Create new instance of MoPicchu queue component
var mp = Components.classes[mpCID].createInstance();
mp = mp.QueryInterface(Components.interfaces.IMoPicchu);

//
// Execute Lua / Moonshine command
//
function executeCommand(command, result) {
	
	if(result == true) return alert(lua.ExecuteCommand(command));
	else lua.ExecuteCommand(command);
}

// 
// Execute Lua / Moonshine script
//
function executeScript(script, result) {
	
	if(result == true) return alert(lua.ExecuteScript(script));
	else lua.ExecuteScript(script);
}
