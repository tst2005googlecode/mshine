/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Header for Moonshine Lua interpreter
*/

#ifndef _MOONSHINE_LUA_H_
#define _MOONSHINE_LUA_H_

#include "IMoonshineLua.h"

#define MOONSHINE_LUA_CONTRACTID "@mshine.googlecode.com/MoonshineLua;1"
#define MOONSHINE_LUA_CLASSNAME "Lua interpreter for Moonshine"
#define MOONSHINE_LUA_CID { 0x417edeba, 0xc3f4, 0x4add, { 0xb8, 0xf5, 0x9d, 0x7b, 0x76, 0x77, 0x60, 0x84 } }

class MoonshineLua : public IMoonshineLua
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMOONSHINELUA

  MoonshineLua();

private:
  ~MoonshineLua();
};

#endif
