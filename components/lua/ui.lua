-- Moonshine
-- Copyright (c) 2007-2008 Samuel Saint-Pettersen
--
-- Lua
-- Copyright (C) 1994-2008 Lua.org, PUC-Rio
--
-- Released under the MIT License
--
-- User interface (UI) API module

-- specify as module
module(..., package.seeall)

-- module version
_VERSION = "UI Module v0.1"

-- required module?
_REQUIRED = "true"

-- open a new browser window
function window(url, width, height)
	if url ~= nil and width == nil and height == nil then 
		return "JSwindow.open('" .. url .. "');"
	elseif url ~= nil and width ~= nil and height ~= nil then
		return "JSwindow.open('" .. url .. "',width=" .. width .. ",height=" .. height .. ");"
	end
end

-- display message box
function message(message) 
	return "JSalert('" .. message .. "');"
end
