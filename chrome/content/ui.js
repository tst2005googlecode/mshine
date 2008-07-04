/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	User interface logic
*/

// Initially enable Moonshine
var enabled = true;

// 
// Display execute command prompt and alert return from an executed command 
//
function displayExeCmd() {
	
	const loc = loadLoc();
	var command = prompt(locStr(loc, "promptExeCmd"));
	if(command != null) alert(executeCommand(command));
}

// Display sandpit for code experimentation
//
function displaySandpit() {
	
	alert("Sandpit"); // !
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
