/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	User interface logic
*/

// Initially enable Moonshine
var enabled = true;

// 
// Display execute command prompt and pass command 
// 
function promptCommand() {
	
	const loc = loadLoc();
	
	var command = prompt(locStr(loc, "promptExeCmd"));
	if(command != null) executeCommand(command);
}

// 
// Display file load prompt to execute a selected Lua script
//
function loadScript() {
	
	const loc = loadLoc();
	
	var nsIFilePicker = Components.interfaces.nsIFilePicker;
	var fp = Components.classes["@mozilla.org/filepicker;1"].createInstance(nsIFilePicker);
	fp.init(window, locStr(loc, "promptExeScript"), nsIFilePicker.modeOpen);
	fp.appendFilter(locStr(loc, "filterExeScript"), "*.lua");
	fp.show();

	var script = fp.file.path;
	if(script != null) executeScript(script);
}

//
// Display sandpit for code experimentation
//
function displaySandpit() {
	
	alert("Sandpit"); // !
} 

//
// Enable or disable alerts for returns
//
function toggleAlerts() {
	
	// Get menu "Enabled" option
	const option = document.getElementById("alerts_enabled");
	
	if(alerts) {
	
		alerts = false;
		option.setAttribute("checked", "false");
	}
	else {
		
		alerts = true;	
		option.setAttribute("checked", "true");
	}		 
}

//
// Disable or re-enable Moonshine
//
function toggleEnable() {
	
	const loc = loadLoc(); 
	var ans = null; // Initialize feedback variable as null
	
	// Get menu "Enabled" option
	const option = document.getElementById("moonshine_enabled");
	
	// If Moonshine is enabled...
	if(enabled) {
		
		// prompt to disable it
		ans = confirm(locStr(loc, "promptDisable"));
		
		// If Yes; disable it and uncheck menu option
		if(ans) {
			enabled = false;
			option.setAttribute("checked", "false");
		
			// Provide feedback that Moonshine has been disabled
			alert(locStr(loc, "confirmDisabled"));
		}
		// If No; keep menu option checked
		else option.setAttribute("checked", "true");
	}
	// Otherwise, if Moonshine is disabled...
	else {
		
		// prompt to re-enable it
		msgPrompt = locStr(loc, "promptEnable");
		ans = confirm(msgPrompt);
		
		// If "Yes"; enable it and check menu option
		if(ans) {
			enabled = true;
			option.setAttribute("checked", "true");
			
			// Provide feedback that Moonshine has been enabled
			alert(locStr(loc, "confirmEnabled"));
		}
		// If "No"; keep menu option unchecked
		else option.setAttribute("checked", "false");
	}
}
