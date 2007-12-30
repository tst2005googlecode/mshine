-------------------------------
-- test luasocket module
-------------------------------
print("\n" .. socket._VERSION .. "\n") -- print version
c = socket.tcp() -- init tcp protocol
c:connect('localhost',4242)  -- connect to browser listener on port 4242
c:send('alert("Connected.")') -- display connected in browser
print("Connected.") -- display connected in msh core interpreter

