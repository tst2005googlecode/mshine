/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	
	Lua
	Copyright (C) 1994-2008 Lua.org, PUC-Rio

	Released under the MIT License
	Implementation code for Moonshine Lua interpreter
*/

#define COMPONENT_VERSION 0.1

#include "LuaInterpreter.h"
#include "nsStringAPI.h"
#include "LuaIncl.h"

NS_IMPL_ISUPPORTS1(LuaInterpreter, ILuaInterpreter)

//
// Constructor
//
LuaInterpreter::LuaInterpreter() { }

//
// Destructor
//
LuaInterpreter::~LuaInterpreter() { }

// Define Lua state
lua_State *L;

// Define path to Moonshine API modules
char *modules = "C:\\Program Files\\Mozilla Firefox\\lua\\modules.lua"; // Absolute path currently necessary :(

//
// Return component version
//
NS_IMETHODIMP LuaInterpreter::ReturnVersion(double *_retval) {

	*_retval = COMPONENT_VERSION;
    return NS_OK;
}

//
// Return Lua version ("release")
//
NS_IMETHODIMP LuaInterpreter::ReturnLuaVersion(nsACString & _retval) {

	_retval.Assign(LUA_RELEASE);
    return NS_OK;
}

//
// Execute a Lua/Moonshine API command
//
NS_IMETHODIMP LuaInterpreter::ExecuteCommand(const char *command, nsACString & _retval) {

	L = luaL_newstate(); // Create a new Lua state
	luaL_openlibs(L); // Load standard libraries

	//luaL_dofile(L, modules); // Execute script to load API modules

	luaL_dostring(L, command); // Execute (argument) command
	_retval.Assign(lua_tostring(L, 1)); // Return result or an error message

	lua_pop(L, 1); // Pop result from the stack
	lua_close(L); // Destroy created Lua state

	return NS_OK;
}

// 
// Execute a Lua/Moonshine script
//
NS_IMETHODIMP LuaInterpreter::ExecuteScript(const char *script, nsACString & _retval) {

	L = luaL_newstate(); // Create a new Lua state
	luaL_openlibs(L); // Load standard libraries

	//luaL_dofile(L, modules); // Execute script to load API modules

	luaL_dofile(L, script); // Execute (argument) script
	 _retval.Assign(lua_tostring(L, 1)); // Return result or an error message

	lua_pop(L, 1); // Pop result from the stack
	lua_close(L); // Destory created Lua state

	return NS_OK;
}
