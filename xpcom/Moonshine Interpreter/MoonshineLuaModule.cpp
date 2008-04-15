/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Module definitions for Moonshine Lua interpreter
*/

#include "nsIGenericFactory.h"
#include "MoonshineLua.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(MoonshineLua)
static nsModuleComponentInfo components[] = 
{
	{
		MOONSHINE_LUA_CLASSNAME,
		MOONSHINE_LUA_CID,
		MOONSHINE_LUA_CONTRACTID,
		MoonshineLuaConstructor,
	}
};
NS_IMPL_NSGETMODULE("MoonshineLuasModule", components)
