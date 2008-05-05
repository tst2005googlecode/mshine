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
lua_State *L; // define lua state

// define script to load API modules
// !!! I should be able to use a relative path !!!
const char *modules = "C:\\Program Files\\Mozilla Firefox 3 Beta 5\\lua\\modules.lua"; 

//
// constructor
//
MoonshineLua::MoonshineLua() { }

// 
// destructor
//
MoonshineLua::~MoonshineLua() { }

//
// return embedded Lua version
//
NS_IMETHODIMP MoonshineLua::GetVersion(nsACString &_retval) {

	L = luaL_newstate(); // create a new lua state
	luaL_openlibs(L); // load standard libraries

	lua_getglobal(L, "_VERSION"); // push lua version onto the stack
	_retval.Assign(lua_tostring(L, 1)); // return lua version string

	lua_pop(L, 1); // pop lua version string from the stack
	lua_close(L); // destroy created lua state

	return NS_OK;
}

//
// execute a Lua/Moonshine API command
//
NS_IMETHODIMP MoonshineLua::ExecuteCommand(const char *command, nsACString & _retval) {

	L = luaL_newstate(); // create a new lua state
	luaL_openlibs(L); // load standard libraries

	int file = luaL_dofile(L, modules); // execute script to load API modules

	int string = luaL_dostring(L, command); // execute (argument) command
	_retval.Assign(lua_tostring(L, 1)); // return result or an error message

	lua_pop(L, 1); // pop result from the stack
	lua_close(L); // destroy created lua state

	return NS_OK;
}

// 
// execute a Lua/Moonshine script
//
NS_IMETHODIMP MoonshineLua::ExecuteScript(const char *script, nsACString & _retval) {
    
	L = luaL_newstate(); // create a new lua state
	luaL_openlibs(L); // load standard libraries

	int file = luaL_dofile(L, script); // execute (argument) script
	 _retval.Assign(lua_tostring(L, 1)); // return result or an error message

	lua_pop(L, 1); // pop result from the stack
	lua_close(L); // destory created lua state

	return NS_OK;
}
