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

}

MoonshineLua::~MoonshineLua() {

}

// return embedded Lua version
NS_IMETHODIMP MoonshineLua::GetVersion(nsACString &_retval) {
	// create a new lua state
	L = luaL_newstate();
	// load libraries
	luaL_openlibs(L);
	// push lua version onto the stack
	lua_getglobal(L, "_VERSION");
	// return lua version string
	_retval.Assign(lua_tostring(L, -1));
	// completely clear the stack
	lua_settop(L, 0);
	// destory created lua state
	lua_close(L);
	return NS_OK;
}
// execute a Lua statement
NS_IMETHODIMP MoonshineLua::ExecuteStatement(const nsACString & statement, nsACString & _retval)
{
	_retval.Assign(statement);
    return NS_OK;
}
