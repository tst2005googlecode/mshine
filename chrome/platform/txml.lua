print("\n" .. xmlp.version() .. "\n")
file = "<file type='image'>giraffe.png</file>"
print(xmlp.tag(file, "file") .. " (" .. xmlp.attrib(file, "file", "type") .. ")")
