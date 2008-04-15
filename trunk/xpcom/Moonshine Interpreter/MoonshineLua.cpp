/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Implementation code for Moonshine Lua interpreter
*/

#include "MoonshineLua.h"

/* Implementation file */
NS_IMPL_ISUPPORTS1(MoonshineLua, IMoonshineLua)

MoonshineLua::MoonshineLua() {
}

MoonshineLua::~MoonshineLua() {
}

// return moonshine lua / embedded lua interpreter version
NS_IMETHODIMP MoonshineLua::Version(char **_retval) {
	**_retval = "Moonshine Lua interpreter 1.0";
    return NS_OK;
}
