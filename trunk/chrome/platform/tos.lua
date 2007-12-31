-------------------------------
-- print detected os
-------------------------------
win = os.getenv("WinDir")
if win ~= nil then
	print("Windows")
else
	print("Unix-like")
end

