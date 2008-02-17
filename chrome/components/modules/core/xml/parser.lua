----------------------------------------------------
-- XML parser for use with XML in Lua programs
-- Version 0.1.1
-- Copyright (c) 2007-2008 Samuel Saint-Pettersen
-- Released under the MIT License
-- See the COPYING file
----------------------------------------------------

-- specify as module
module(..., package.seeall)

-- tag value pattern
val = "[%w%x%s\/\\\.]+"

-- return version information
function version()
    return [[XML parser 0.1.1
Copyright (c) 2007-2008 Samuel Saint-Pettersen]]
end
-- parse tag
function vtag(data, tag, occur)
    if data and tag and occur ~= nil then
        local tm = {}
        local i = 1
        local ftag = "<\/" .. tag .. ">" -- ?
        local query = val .. ftag
        for mv in string.gmatch(data, query) do
            tm[i] = string.gsub(mv, ftag, "")
            i = i + 1
        end
        if tm[occur] ~= nil then
            return tm[occur]
        else
            return "Tag: " .. tag .."[" .. occur .. "] does not exist"
        end          
    else
        return "Usage: r = xmlp.vtag(data as str, tag as str, occur as int)"
    end
end
-- parse attribute
function vatt(data, tag, att, occur)
    if data and tag and att and occur ~= nil then
        local am = {}
        local i = 1
        local fatt = "<" .. tag .. "%s" .. att .. "\=\"?\'?"
        local query = fatt .. val
        for mv in string.gmatch(data, query) do
            am[i] = string.gsub(mv, fatt, "")
            i = i + 1
        end
        if am[occur] ~= nil then
            return am[occur]
        else
            return "Attribute: " .. att .. " @ " .. tag .. "[" .. occur .. "] does not exist"
        end
    else
        return [[Usage: r = xmlp.vatt(data as str, tag as str, attr as str
, occur as int)]] 
    end
end
-- count tags
function ctag(data, tag)
    if data ~= nil then
        local pattern
        local count = 0
        if tag ~= nil then
            pattern = "<" .. tag .. "[%s%w%x\=\'\"\.]*\/?>" 
        else
            pattern = "<[%w%x%s\-\"\'\=\.]+\/?>" 
        end
        for mt in string.gmatch(data, pattern) do
            count = count + 1
        end
        return count
    else
        return "Usage: r = xmlp.ctag(data as str [, tag as str])"
    end
end     
