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

//
// Execute Lua / Moonshine API command
//
function executeCommand(command) {
	
	var lua = Components.classes[luaCID].createInstance();
	lua = lua.QueryInterface(Components.interfaces.ILuaInterpreter);
	return lua.ExecuteCommand(command);
}
