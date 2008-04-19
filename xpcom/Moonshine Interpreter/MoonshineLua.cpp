/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	
	Lua
	Copyright (C) 1994-2008 Lua.org, PUC-Rio

	Released under the MIT License
	Implementation code for Moonshine Lua interpreter
*/

#include "MoonshineLua.h"
#include "luaincl.h"

NS_IMPL_ISUPPORTS1(MoonshineLua, IMoonshineLua)

// create a new lua state
//lua_State *L = luaL_newstate();

MoonshineLua::MoonshineLua() {
	//load libraries
	//luaL_openlibs(L);
}

MoonshineLua::~MoonshineLua() {
	// destory created lua state
	//lua_close(L);
}

// return embedded Lua (release) version
NS_IMETHODIMP MoonshineLua::Version(double *_retval) {
	*_retval = 3.142; //! TODO :p mmmm... pi.
    return NS_OK;
}
// run passed lua script
NS_IMETHODIMP MoonshineLua::RunScript() {
	//int script = luaL_dofile(L, "moonshine.lua");
    return NS_OK;
}
