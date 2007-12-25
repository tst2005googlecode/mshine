-------------------------------
-- test xml module
-------------------------------
print("\n" .. socket._VERSION .. "\n") -- print version
c = socket.tcp()
c:connect('localhost','4242')
c:send('alert("Connected.")')
print("Connected.")

