/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Extension logic
*/

// Load locale strings
var locales = document.getElementById("locales");

// Initially enable Moonshine
var enabled = true;

// Disable or re-enable Moonshine
function ToggleEnable() {
	var ans, msgPrompt, msgConfirm = null; 
	if(enabled) {
		msgPrompt = locales.getString('promptDisable');
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = false;
			msgConfirm = locales.getString('confirmDisabled');
		}
	}
	else {
		msgPrompt = locales.getString('promptEnable');
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = true;
			msgConfirm = locales.getString('confirmEnabled');
		}
	}
	alert(msgConfirm);
}
