-------------------------------
-- test base module
-------------------------------
print("\n" .. mshb.version() .. "\n") -- print version
mshapp = mshb.load("helloworld.msh") -- load moonshine app
print("\n" .. mshapp .. "\n") -- print moonshine app code
invalid = mshb.load("simple.lua") -- load an invalid file
print("\n" .. invalid .. "\n") -- this should print an error

