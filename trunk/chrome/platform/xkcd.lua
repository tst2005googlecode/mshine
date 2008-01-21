----------------------------------
-- display latest xkcd web
-- comic from the xkcd atom feed
-- in a new browser window
----------------------------------
-- make a request for xkcd comic feed
feed = net.httpreq("http://xkcd.com/atom.xml")
-- match comic panel
img = string.match(feed, "http\:\/\/imgs.xkcd.com\/comics\/[%w%_]+.png")
-- print url of matched comic panel
print(img)
-- display comic panel in a new window
std.window(img)

