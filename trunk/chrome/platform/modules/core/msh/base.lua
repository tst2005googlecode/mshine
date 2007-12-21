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
        parseApplication(app)
    else
        -- otherwise; return an error message
        return "Error. This is not an MSH application!"
    end
end
-- parse application metadata and code
function parseApplication(app)
    -- tags to parse
    tags = {"type","uid","name","desc","author","email","webs","img","rest","luacode"}
    data = {}
    -- parse each tag
    for index = 1, #tags do
		data[index] = xmlp.tag(app, tags[index])
		print("\n" .. data[index]) -- !
    end
    -- parse type tag's autorun attribute
    local autorun = xmlp.attrib(app, tags[1], "autorun")
    print("\n" .. autorun) -- !
end
-- retrieve and cache accompanying image for application
function getImage(url)
    -- TODO: most likely won't be implemented in first release!
end

