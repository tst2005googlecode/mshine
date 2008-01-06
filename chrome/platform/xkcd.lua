----------------------------------
-- display latest xkcd web
-- comic from the xkcd atom feed
-- in a new browser window
----------------------------------
-- make a request for xkcd comic feed
feed = net.httpreq("http://xkcd.com/atom.xml")
-- match comic panel
img = string.match(feed, "http\:\/\/imgs.xkcd.com\/comics\/[%w%_]+.png")
-- display comic panel in a new window
std.window(img)

