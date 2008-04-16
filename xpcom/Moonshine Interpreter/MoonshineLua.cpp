/*
	Moonshine
	Copyright (c) 2007-2008 Samuel Saint-Pettersen
	Released under the MIT License
	Implementation code for Moonshine Lua interpreter
*/

#include "MoonshineLua.h"

NS_IMPL_ISUPPORTS1(MoonshineLua, IMoonshineLua)

MoonshineLua::MoonshineLua() {
}

MoonshineLua::~MoonshineLua() {
}

// return moonshine lua / embedded lua interpreter version
NS_IMETHODIMP MoonshineLua::Version(float *_retval) {
	*_retval = 1.0;
    return NS_OK;
}
