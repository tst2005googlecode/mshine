-------------------------------
-- test base module
-------------------------------
print("\n" .. base.version() .. "\n") -- print version
mshapp = base.load("helloworld.msh") -- load moonshine app
print("\n" .. mshapp .. "\n") -- print moonshine app code
invalid = base.load("simple.lua") -- load an invalid file
print("\n" .. invalid .. "\n") -- this should print an error

