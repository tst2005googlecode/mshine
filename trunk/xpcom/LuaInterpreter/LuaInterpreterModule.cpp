/*
	Moonshine embedded Lua environment for Firefox
	Copyright (c) 2007-2008 Samuel Saint-Pettersen <samji@bigfoot.com>
	Released under the MIT License
	Module definitions for Moonshine Lua interpreter
*/

#include "nsIGenericFactory.h"
#include "LuaInterpreter.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(LuaInterpreter)

static nsModuleComponentInfo components[] = {

	{
		LUA_INTERPRETER_CLASSNAME,
		LUA_INTERPRETER_CID,
		LUA_INTERPRETER_CONTRACTID,
		LuaInterpreterConstructor,
	}
};

NS_IMPL_NSGETMODULE("LuaIntepreterModule", components)
