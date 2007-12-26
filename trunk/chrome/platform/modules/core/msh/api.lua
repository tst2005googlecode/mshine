-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------
-- THIS MODULE PROVIDES API FUNCTIONALITY.
-- IT SHOULD NOT BE ACCESSED DIRECTLY FROM
-- A MOONSHINE APPLICATION.

-- specify as module
module(..., package.seeall)

-- return version information
function version()
    return [[API module for Moonshine 0.1
Copyright (c) 2007 Sam Saint-Pettersen]]
end
-- make a javascript call using tcp functionality
-- to localhost:4242 where MozRPL is listening
-- within the browser
function call(jscode)
    local c = socket.tcp()
    c:connect('localhost',4242)
    c:send(jscode)
end

