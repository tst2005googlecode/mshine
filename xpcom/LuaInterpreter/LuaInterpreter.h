/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Header for Moonshine Lua interpreter
*/

#ifndef _LUA_INTERPRETER_H_
#define _LUA_INTERPRETER_H_

#include "ILuaInterpreter.h"

#define LUA_INTERPRETER_CONTRACTID "@moonshine.luaforge.net/MoonshineLua;1"
#define LUA_INTERPRETER_CLASSNAME "Embedded Lua interpreter for Mozilla"
#define LUA_INTERPRETER_CID { 0x37694320, 0x57d6, 0x4056, { 0xbe, 0x3d, 0x24, 0xa1, 0x13, 0x66, 0xa9, 0xb3 } }

class LuaInterpreter : public ILuaInterpreter {
public:
  NS_DECL_ISUPPORTS
  NS_DECL_ILUAINTERPRETER

  LuaInterpreter();

private:
	~LuaInterpreter();
};

#endif
