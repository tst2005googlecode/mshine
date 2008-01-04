/* 
 Moonshine environment for Lua-based
 services in Mozilla Firefox web browser
 Copyright (c) 2007 Sam Saint-Pettersen.

 This program is released "as is" under
 the GNU General Public License V3.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
int main(int argc, char *argv[])
{
    // declare a new lua state and load libraries
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // print title
    printf("\nMoonshine core interpreter");
    printf("\nCopyright (c) 2007 Sam Saint-Pettersen\n");
 
    // invoke module loading
    int chmodu = luaL_dofile(L, "modules.lua");
    if(chmodu != 0)
    {
        // if there is a problem loading modules; display error
        const char *message = lua_tostring(L, -1);
        fprintf(stderr, "\nError loading one or more modules:\n%s\n", message);
    }
    else
    {   
        // otherwise, confirm modules were loaded
        printf("\nLoaded modules.\n\n");
    }
    // if argument is provided; run code
    if(argc > 1)
    {   
        luaL_dofile(L, argv[1]);
    }
    // otherwise; display prompt
    else 
    {
        printf("\nUsage: msh <mshluacode>\n");
    }

    // close current lua state    
    lua_close(L);

    // print a new line
    printf("\n");

    return 0;
}

