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

// define lua state
lua_State *L;

MoonshineLua::MoonshineLua() {
	// create a new lua state and load libraries
	L = luaL_newstate();
	luaL_openlibs(L);
}

MoonshineLua::~MoonshineLua() {
	// destory created lua state
	lua_close(L);
}

// return embedded Lua version
NS_IMETHODIMP MoonshineLua::GetVersion(nsACString &_retval) {
	// push lua version onto the stack
	lua_getglobal(L, "_VERSION");
	// return lua version string
	_retval.Assign(lua_tostring(L, -1));
	// completely clear the stack
	lua_settop(L, 0);
	return NS_OK;
}
// execute a Lua statement
NS_IMETHODIMP MoonshineLua::ExecuteStatement(const nsACString & statement, nsACString & _retval)
{
	_retval.Assign(statement);
    return NS_OK;
}
