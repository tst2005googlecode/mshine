-------------------------------
-- test xml parser module
-------------------------------
print("\n" .. xmlp.version() .. "\n") -- print version
file = "<file type='image'>giraffe.png</file>" -- xml fragment as file
print(xmlp.tag(file, "file") .. " (" .. xmlp.attrib(file, "file", "type") .. ")") -- print from fragment

