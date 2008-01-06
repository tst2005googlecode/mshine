-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------
-- THIS MODULE PROVIDES ACCESS TO 
-- LUASOCKET FUNCTIONALITY.

-- specify as module
module(..., package.seeall)

-- return version information
function version()
    return [[Net module for Moonshine 0.1
Copyright (c) 2007 Sam Saint-Pettersen]]
end
-- issue an http request; return the response
function httpreq(url)
    local h = require("socket.http")
    return h.request(url)
end

