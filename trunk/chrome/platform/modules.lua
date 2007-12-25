-------------------------------------------
-- Moonshine environment for Lua-based
-- services in Mozilla Firefox web browser
-- Copyright (c) 2007 Sam Saint-Pettersen.

-- This program is released "as is" under
-- the GNU General Public License V3.
-------------------------------------------
-- IMPORTANT: ALL MODULES INCLUDED
-- UNDER MODULES/CORE ARE NEEDED BY
-- THE MOONSHINE CORE INTEPRETER
-- AND SHOULD NOT BE REMOVED OR
-- HAVE THEIR REFERENCES HERE REMOVED
-- OR OTHERWISE ALTERED. THIS FILE,
-- AS SUCH, MUST NOT BE MOVED
-- OR OTHERWISE DELETED.
-- ONLY MODULES/OPTIONAL CAN
-- BE CHANGED OR REMOVED.

-- load and reference modules
base = require("modules/core/msh.base")
xmlp = require("modules/core/xml.parser")
api = require("modules/core/msh.api")
--net = require("modules/core/net.socket")

