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

MoonshineLua::MoonshineLua() {
	// declare a new lua state and load libraries
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
}

MoonshineLua::~MoonshineLua() {
}

// return moonshine lua / embedded lua interpreter version
NS_IMETHODIMP MoonshineLua::Version(double *_retval) {
	*_retval = 0.1;
    return NS_OK;
}
