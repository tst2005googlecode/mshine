/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Extension logic
*/

// Initially enable Moonshine
var enabled = true;

// Initiate locales variable
var locales = null;

// Disable or re-enable Moonshine
function toggleEnable() {
	var ans, msgPrompt, msgConfirm = null; 
	locales = document.getElementById("locales");
	if(enabled) {
		msgPrompt = locales.getString("promptDisable");
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = false;
			msgConfirm = locales.getString("confirmDisabled");
		}
	}
	else {
		msgPrompt = locales.getString("promptEnable");
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = true;
			msgConfirm = locales.getString("confirmEnabled");
		}
	}
	alert(msgConfirm);
}
