---------------------------------------------
-- simple moonshine application to
-- display the latest xkcd comic 
-- as found on the xkcd atom feed
---------------------------------------------

-- make a request for xkcd comic feed
feed = net.httpreq("http://xkcd.com/atom.xml")
-- match comic panel
img = string.match(feed, "http\:\/\/imgs.xkcd.com\/comics\/[%w%_]+.png")
-- display comic panel in a new window
std.window(img)
