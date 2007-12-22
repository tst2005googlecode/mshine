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
    return [[Standard module for Moonshine 0.1
Copyright (c) 2007 Sam Saint-Pettersen]]
end
-- display message in msgbox;
-- a lua interface to javascript's alert()
function msg(message, title)
    -- use default title if not specified
    local dtitle = "Moonshine"
    -- otherwise use specified title
    if title ~= nil then
        dtitle = title
    end 
    print("Msg:" .. dtitle .. " -> " .. message .. "\n") -- !
    -- TODO: use api module here for msg
end

