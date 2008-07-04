/*
 	COMPONENTS FUNCTIONS
	Copyright (c) 2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License

	Covenience functions for working with components.
	Include this script in your interfaces to allow 
	a syntax like below to create an instance of a component:
	
	compInstance(cid, interface);

	Rather than the more cumbersome equivalent:
	
	const cid = "xxxxxxxx...";
	var comp = null;
	...
	comp = Components.classes[cid].createInstance();
	lua = lua.QueryInterface(Components.interfaces.IComponent);
*/

//
// Create a new instance of a component
//
function compInstance(cid) {

	return Components.classes[cid].createInstance();	
}

// 
// Query component interface
//
function queryInterface(instance, Interface) {
	
	return instance.QueryInterface(Components.interfaces.Interface);
}
