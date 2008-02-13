-------------------------------
-- print detected os
-------------------------------
os = os.getenv("WinDir")
if os ~= nil then
    print("Windows")
else
    print("Unix-like")
end

