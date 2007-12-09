file = "<file type='image'>giraffe.png</file>"
print(xml.tag(file, "file") .. " (" .. xml.attrib(file, "file", "type") .. ")")

