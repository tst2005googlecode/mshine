-------------------------------
-- test base module
-------------------------------
print("\n" .. mshb.version() .. "\n") -- print version
mshapp = mshb.load("helloworld.msh") -- load moonshine app
print(mshapp .. "\n") -- print moonshine app code
invalid = mshb.load("simple.lua") -- load an invalid file
print(invalid .. "\n") -- this should print an error

