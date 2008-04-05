/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Extension logic
*/

// Initially enable Moonshine
var enabled = true;

// Disable or re-enable Moonshine
function toggleEnable() {
	var ans, msgPrompt, msgConfirm = null; 
	if(enabled) {
		msgPrompt = "Really disable Moonshine?"; //promptDisable
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = false;
			msgConfirm = "Moonshine was disabled."; //confirmDisabled
		}
	}
	else {
		msgPrompt = "Enable Moonshine?"; //promptEnable
		ans = confirm(msgPrompt);
		if(ans) {
			enabled = true;
			msgConfirm = "Moonshine was enabled."; //confirmEnabled
		}
	}
	alert(msgConfirm);
}
//COMMIT DARN IT