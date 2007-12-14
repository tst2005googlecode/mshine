---------------------------------------------------
-- XML parser for use with XML in Lua programs
-- Version 0.1
-- Copyright (c) 2007 Sam Saint-Pettersen
-- Released under the GNU General Public License v3
---------------------------------------------------

-- specify as module
module(..., package.seeall)

-- allowed characters as tag value
tagval = "[%.%,%;%:%-%&%%\\%\/%#%~%\"%@%\'%w%x%s]+"

-- allowed characters as attribute value
attval = "[%.%,%;%:%-%&%@%w%x%s]+"

-- return version information
function version()
	return "XML Parser 0.1\nCopyright (c) 2007 Sam Saint-Pettersen <samji@bigfoot.com>"
end
-- load file
function load(file)
	if file ~= nil then
		local xml = io.open(file, "r")
		return (xml:read("*all"))
	else
		return "Usage: xml.load(file as str)"
	end
end
-- parse tag
function tag(xml, tag, occur)
         if xml or tag ~= nil then
                local tagp = tagval .. "</" .. tag .. ">"
                local tagm = string.match(xml, tagp)
                local start = string.len(tag) - 1000
                if tagm ~= nil then
                        return string.match(tagm, tagval, start)
                else
                        return "Tag: " .. tag .. " does not exist."
                end
         else
                return "Usage: xml.tag(xml as str, tag as str [, occur as int])"
         end
end
-- parse attribute
function attrib(xml, tag, attr, occur)
	if xml or tag or attr ~= nil then
		local attp = "<" .. tag .. "%s" .. attr .. "%=%\"?%\'?" .. attval .. "%\'?%\"?%\/?>"
		local attm = string.match(xml, attp)
		local start = string.len(tag) + string.len(attr) + 3
		if attm ~= nil then
			return string.match(attm, attval, start)
		else
			return "Attribute: " .. attr .. " does not exist for " .. tag .. "."
		end
	else
		return "Usage: xml.attrib(xml as str, tag as str, attr as str [, occur as int])"
	end
end
