-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------
-- THIS MODULE PROVIDES STANDARD
-- FUNCTIONALITY.

-- specify as module
module(..., package.seeall)

-- return version information
function version()
    return [[Standard module for Moonshine 0.1
Copyright (c) 2007 Sam Saint-Pettersen]]
end
-- display message in msgbox;
-- a lua interface to javascript's alert()
function msg(message)
    local a = 'alert("' .. message .. '")'
    api.call(a)
end
-- display prompt to user;
-- a lua interface to javascript's prompt()
function prompt(message, value)
    local p = 'var p = prompt("' .. message .. '")'
    api.call(p)
end
-- open a new window;
-- a lua interface to javascript's window.open()
function window(url, id, width, height)

end

