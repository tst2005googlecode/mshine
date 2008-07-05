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
function executeCommand(command, alerts) {
	
	if(alerts == true) return alert(lua.ExecuteCommand(command));
	else return lua.ExecuteCommand(command);
}

// 
// Execute Lua / Moonshine script
//
function executeScript(script, alerts) {
	
	var result = lua.ExecuteScript(script);
	
	// Match and execute JavaScript where applicable
	var jsRegex = /JS/; 
	if(result.match(jsRegex)) {
		
		var jsCode = result.replace(jsRegex, "javascript:");
		eval(jsCode);
	}
	else if(alerts) return alert(result);
	else return result;
}
