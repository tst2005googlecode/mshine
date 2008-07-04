/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	Utilise Lua interpreter along with MoPicchu queue within Firefox
*/

// Define contract ID for Lua interpreter component
const luaCID = "@mshine.googlecode.com/MoonshineLua;1";

// Define interface for Lua interpreter component
const luaIf = "ILuaInterpreter";

//
// Execute Lua / Moonshine API command
//
function executeCommand(command) {
	
	/*var lua = compInstance(luaCID);
	lua = queryInterface(lua, luaIf);*/
	
	Components.classes[luaCID].createInstance();
	lua = lua.QueryInterface(Components.interfaces.ILuaInterpreter);*/
	return lua.ExecuteCommand(command);
}
