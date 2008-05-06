/*
	JSExecute (JavaScript Execute)
	Copyright (c) 2008 Samuel Saint-Pettersen

	Released under the MIT License
	
	XPCOM component to allow third party components
	to execute JavaScript code
*/

const nsISupports = Components.interfaces.nsISupports;

// You can change these if you like
const CLASS_ID = Components.ID("97d08069-572c-46aa-9ab7-6ae73aac0b53");
const CLASS_NAME = "Allows third party componets to execute JavaScript ";
const CONTRACT_ID = "@googlecode.com/jsexecute;1";

// This is your constructor.
// You can do stuff here.
function JSExecute() {
  // you can cheat and use this
  // while testing without
  // writing your own interface
  this.wrappedJSObject = this;
}

// This is the implementation of your component.
JSExecute.prototype = {
  // for nsISupports
  QueryInterface: function(aIID)
  {
    // add any other interfaces you support here
    if (!aIID.equals(nsISupports))
        throw Components.results.NS_ERROR_NO_INTERFACE;
    return this;
  }
}

//=================================================
// Note: You probably don't want to edit anything
// below this unless you know what you're doing.
//
// Factory
var JSExecuteFactory = {
  createInstance: function (aOuter, aIID)
  {
    if (aOuter != null)
      throw Components.results.NS_ERROR_NO_AGGREGATION;
    return (new JSExecute()).QueryInterface(aIID);
  }
};

// Module
var JSExecuteModule = {
  registerSelf: function(aCompMgr, aFileSpec, aLocation, aType)
  {
    aCompMgr = aCompMgr.QueryInterface(Components.interfaces.nsIComponentRegistrar);
    aCompMgr.registerFactoryLocation(CLASS_ID, CLASS_NAME, CONTRACT_ID, aFileSpec, aLocation, aType);
  },

  unregisterSelf: function(aCompMgr, aLocation, aType)
  {
    aCompMgr = aCompMgr.QueryInterface(Components.interfaces.nsIComponentRegistrar);
    aCompMgr.unregisterFactoryLocation(CLASS_ID, aLocation);        
  },
  
  getClassObject: function(aCompMgr, aCID, aIID)
  {
    if (!aIID.equals(Components.interfaces.nsIFactory))
      throw Components.results.NS_ERROR_NOT_IMPLEMENTED;

    if (aCID.equals(CLASS_ID))
      return JSExecuteFactory;

    throw Components.results.NS_ERROR_NO_INTERFACE;
  },

  canUnload: function(aCompMgr) { return true; }
};

//module initialization
function NSGetModule(aCompMgr, aFileSpec) { return JSExecuteModule; }
