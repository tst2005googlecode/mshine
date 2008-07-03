/*
	Lua
	Copyright (C) 1994-2008 Lua.org, PUC-Rio

	Lua header for C++ code
	Please feel free to use this code as you will for your own C++ project
	which embeds Lua. It's pretty standard :)
*/

#ifndef _LUA_INC_H_
#define _LUA_INC_H_

extern "C" { // Because Lua is written in ANSI C...
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#endif
