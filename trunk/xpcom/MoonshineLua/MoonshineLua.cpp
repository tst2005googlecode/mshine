/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	
	Lua
	Copyright (C) 1994-2008 Lua.org, PUC-Rio

	Released under the MIT License
	Implementation code for Moonshine Lua interpreter
*/

#include "MoonshineLua.h" 
#include "nsStringAPI.h"
#include "luaincl.h"	  

NS_IMPL_ISUPPORTS1(MoonshineLua, IMoonshineLua)

//
// Constructor
//
MoonshineLua::MoonshineLua() { }

// 
// Destructor
//
MoonshineLua::~MoonshineLua() { }

// Define Lua state
lua_State *L;

// Define script to load API modules
const char *modules = "C:\\Program Files\\Mozilla Firefox 3 Beta 5\\lua\\modules.lua"; // !

//
// Return embedded Lua version
//
NS_IMETHODIMP MoonshineLua::GetVersion(nsACString &_retval) {

	L = luaL_newstate(); // Create a new Lua state
	luaL_openlibs(L); // Load standard libraries

	lua_getglobal(L, "_VERSION"); // Push Lua version onto the stack
	_retval.Assign(lua_tostring(L, 1)); // Return Lua version string

	lua_pop(L, 1); // Pop Lua version string from the stack
	lua_close(L); // Destroy created Lua state

	return NS_OK;
}

//
// Execute a Lua/Moonshine API command
//
NS_IMETHODIMP MoonshineLua::ExecuteCommand(const char *command, nsACString & _retval) {

	L = luaL_newstate(); // Create a new Lua state
	luaL_openlibs(L); // Load standard libraries

	int file = luaL_dofile(L, modules); // Execute script to load API modules

	int str = luaL_dostring(L, command); // Execute (argument) command
	_retval.Assign(lua_tostring(L, 1)); // Return result or an error message

	lua_pop(L, 1); // Pop result from the stack
	lua_close(L); // Destroy created Lua state

	return NS_OK;
}

// 
// Execute a Lua/Moonshine script
//
NS_IMETHODIMP MoonshineLua::ExecuteScript(const char *script, nsACString & _retval) {
    
	L = luaL_newstate(); // Create a new Lua state
	luaL_openlibs(L); // Load standard libraries

	int file = luaL_dofile(L, script); // Execute (argument) script
	 _retval.Assign(lua_tostring(L, 1)); // Return result or an error message

	lua_pop(L, 1); // Pop result from the stack
	lua_close(L); // Destory created Lua state

	return NS_OK;
}
