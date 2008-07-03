/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	User interface logic
*/

// Initially enable Moonshine
var enabled = true;

// Initiate locales variable as null
var locales = null;

//
// Disable or re-enable Moonshine
//
function toggleEnable() {
	
	// Initiate feedback variables as null
	var ans, msgPrompt, msgConfirm = null; 
	
	// Get menu "Enabled" option
	const option = document.getElementById("moonshine_enabled");
	
	// Load locales
	locales = document.getElementById("locales");
	
	// If Moonshine is enabled...
	if(enabled) {
		
		// prompt to disable it
		msgPrompt = locales.getString("promptDisable");
		ans = confirm(msgPrompt);
		
		// If Yes; disable it and uncheck menu option
		if(ans) {
			enabled = false;
			option.setAttribute("checked", "false");
			msgConfirm = locales.getString("confirmDisabled");
			
			// Provide feedback that Moonshine has been disabled
			alert(msgConfirm);
		}
		// If No; keep menu option checked
		else option.setAttribute("checked", "true");
	}
	// Otherwise, if Moonshine is disabled...
	else {
		
		// prompt to re-enable it
		msgPrompt = locales.getString("promptEnable");
		ans = confirm(msgPrompt);
		
		// If "Yes"; enable it and check menu option
		if(ans) {
			enabled = true;
			option.setAttribute("checked", "true");
			msgConfirm = locales.getString("confirmEnabled");
			
			// Provide feedback that Moonshine has been enabled
			alert(msgConfirm);
		}
		// If "No"; keep menu option unchecked
		else option.setAttribute("checked", "false");
	}
}
