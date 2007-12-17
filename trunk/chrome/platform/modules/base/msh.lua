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
-- THIS MODULE IS DEPENDENT ON XML.PARSER.

-- specify as module
module(..., package.seeall)

-- return version information
function version()
    return "Base module for Moonshine 0.1\nCopyright (c) 2007 Sam Saint-Pettersen"
end

-- load an msh application;
-- invoked from msh core interpreter
function loadMSH(file)
	local mshapp = xml.load(file)
	--if file == extension of msh
		-- begin parsing
		parseMetadata(mshapp)
		parseLuacode(mshapp)
	--else 
		-- return an error message
		return "Error. This is not an MSH application!"
end

-- parse msh application metadata
function parseMetadata(mshapp)

end
-- parse application code
function parseLuacode(mshapp)

end
