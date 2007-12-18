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
    local app = xmlp.load(file)
    local match = string.match(file, "%w+\.?%bmsh")
    if match ~= nil then
		-- if filename is as expected; begin parsing
		parseMetadata(app)
		parseLuacode(app)
	else
		-- otherwise; return an error message
		return "Error. This is not an MSH application!"
    end
end
-- parse msh application metadata
function parseMetadata(app)
    tags = {"type","uid","name","desc","author","email","webs","rest"}
    mdata = {}
    for index = 1, #tags do
		mdata[index] = xmlp.tag(app, tags[index])
		return "\n" .. mdata[index] .. "\n"
    end
    local autorun = xmlp.attrib(app, tags[1], "autorun")    
end
-- parse and execute application code
function parseLuacode(app)
    local lcode = xmlp.tag(app, "luacode")
end

