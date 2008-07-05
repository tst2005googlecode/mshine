/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	Utilise Lua interpreter along with MoPicchu queue within Firefox
*/

// Define contract ID for Lua interpreter component
const luaCID = "@mshine.googlecode.com/MoonshineLua;1";

// Create new instance of Lua interpreter component
var lua = Components.classes[luaCID].createInstance();
lua = lua.QueryInterface(Components.interfaces.ILuaInterpreter);

//
// Execute Lua / Moonshine command
//
function executeCommand(command) {
	
	var result = lua.ExecuteCommand(command);
	return alert(result);
}

// 
// Execute Lua / Moonshine script
//
function executeScript(script) {
	
	var result = lua.ExecuteScript(script);
	
	// ! Implement stack usage ! //
	
	return alert(result);
}

//
// Execute JavaScript where applicable
//
function executeJS(jsRegex) {
	
	var jsRegex = /JS/; 
	if(result.match(jsRegex)) {
	
		var jsCode = result.replace(jsRegex, "javascript:");
		eval(jsCode);
	}
}
