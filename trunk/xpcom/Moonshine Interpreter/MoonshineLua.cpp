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

//
// constructor
//
MoonshineLua::MoonshineLua() {
}
// 
// deconstructor
//
MoonshineLua::~MoonshineLua() {

}
//
// return embedded Lua version
//
NS_IMETHODIMP MoonshineLua::GetVersion(nsACString &_retval) {
	L = luaL_newstate(); // create a new lua state
	luaL_openlibs(L); // load standard libraries

	lua_getglobal(L, "_VERSION"); // push lua version onto the stack
	_retval.Assign(lua_tostring(L, -1)); // return lua version string

	lua_pop(L, 1); // pop lua version string from the stack
	lua_close(L); // destroy created lua state

	return NS_OK;
}
//
// execute a Lua statement
//
NS_IMETHODIMP MoonshineLua::ExecuteStatement(const char *statement, nsACString & _retval) {
	L = luaL_newstate(); // create a new lua state
	luaL_openlibs(L); // load standard libraries

	// compile the entered code (and execute it if error == 0)
	int error = luaL_loadbuffer(L, statement, strlen(statement), "error") || lua_pcall(L, 0, 0, 0);

	// in the event of an error (error != 0)...
	if(error) {
		_retval.Assign(lua_tostring(L, -1)); // return error message
		lua_pop(L, 1); // pop error message from the stack
	}
	else {
		// TODO
		// complelety clear the stack
		_retval.Assign("This statement is valid.");
		lua_settop(L, 0);
	}

	lua_close(L); // destroy created lua state

	return NS_OK;
}
