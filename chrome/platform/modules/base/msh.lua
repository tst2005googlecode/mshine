-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------
-- THIS IS THE BASE.MSH MODULE, IT IS
-- REQUIRED BY THE MSH CORE INTERPRETER.
-- DO NOT DELETE THIS FILE ITSELF OR
-- REMOVE ITS REFERENCE FROM MODULES.LUA.

-- specify as module
module(..., package.seeall)

-- allowed characters as tag value
-- load an msh application
function loadMSH(file)
    local mshapp = io.open(file, "-r")
    return mshapp:read("*all")
end
function hello()
    return "Hello from loadmsh.lua"
end
