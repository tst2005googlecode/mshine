-------------------------------
-- test standard module
-------------------------------
print("\n" .. std.version() .. "\n") -- print version
std.msg("Hello from Moonshine!") -- display message
std.window("http://code.google.com") -- open google code in new window
local ans = std.prompt("Enter number:") -- display prompt

