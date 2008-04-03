/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT license
	Application logic
*/

// Initially enable Moonshine
var enabled = true;

// Disable or re-enable Moonshine
function disable() {
	if(enabled) {
		var ans = confirm("Really disable Moonshine?");
		if(ans) {
			enabled = false;
			alert("Disabled!");
		}
	}
}
