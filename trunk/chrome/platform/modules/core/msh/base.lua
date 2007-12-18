-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------

-- specify as module
module(..., package.seeall)

-- return version information
function version()
    return [[Base module for Moonshine 0.1
Copyright (c) 2007 Sam Saint-Pettersen]]
end

-- load an msh application;
-- invoked from msh core interpreter
function load(file)
    local mshapp = xmlp.load(file)
    local match = string.match(file, "%w+\.?%bmsh")
    if match ~= nil then
		-- if filename is as expected; begin parsing
		return mshapp -- ! TEMPORARY RETURN
		parseMetadata(mshapp)
		parseLuacode(mshapp)
	else 
		-- otherwise; return an error message
		return "Error. This is not an MSH application!"
    end
end
-- parse msh application metadata
function parseMetadata(mshapp)
    local metadata = {"type","uid","name","desc","author","email","webs"}
        
end
-- parse application code
function parseLuacode(mshapp)

end
