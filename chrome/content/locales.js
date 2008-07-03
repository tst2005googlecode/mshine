/*
	Copyright (c) 2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License

	Covenience functions for working with locales.
	Include this script in your interfaces to allow 
	a syntax like below to load a locale:
	
	const loc = loadLoc();
	prompt(locStr(loc, "myLocaleString"));
	
	Rather than the more cumbersome equivalent:
	
	const loc = document.getElementById("locales");
	prompt(loc.getString("myLocaleString"));
*/

// 
// Load locale for functions
//
function loadLoc() {
	
	return document.getElementById("locales");
}

//
// Load a locale string
//
function locStr(loc, str) {
	
	return loc.getString(str);
}
