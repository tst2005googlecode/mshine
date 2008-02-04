-------------------------------
-- test xml parser module
-------------------------------
print("\n" .. xmlp.version() .. "\n") -- print version
file = "<file type='image'>giraffe.png</file>" -- xml fragment as file
print(xmlp.vtag(file, "file", 1) .. " (" .. xmlp.vatt(file, "file", "type", 1) .. ")") -- print from fragment

