/*
	JSExecute (JavaScript Execute)
	Copyright (c) 2008 Samuel Saint-Pettersen

	Released under the MIT License
	
	XPCOM component to allow third party components
	to execute JavaScript code
*/

// Import XPCOMUtils library
Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");

// Class constuctor
function JSExecute() { };

// Class definiton
JSExecute.prototype = {
	classDescription: "Allows 3rd party components to execute JavaScript",
	classID: Components.ID("{1B245EF6-4CB5-4dcf-BCC8-F5E3F2510305}"),
	contractID: "@googlecode.com/jsexecute;1",
	QueryInterface: XPCOMUtils.generateQI([Components.interfaces.IJSExecute]),
	
	// Implement JavaScript execution method
	execute: function() {
		return 10;
	}
}
// Create component array
var components = [JSExecute];
function NSGetModule(compMgr, fileSpec) {
	return XPCOMUtils.generateModule(components);
}
