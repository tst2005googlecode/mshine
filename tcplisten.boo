/*
TCP Listener
Console application to listen on a TCP port
and display the received message.

Copyright (c) 2007 Sam Saint-Pettersen

Released under the GNU General Public License v3
*/
import System
import System.IO
import System.Net
import System.Net.Sockets
import System.Text

def Main():
    port = 4242 // listen on port 4242                       
    host = IPAddress.Parse("127.0.0.1") // host == "localhost"
    server = TcpListener(host, port)  // create server instance
    server.Start() // start listening for client requests
    
    // print feedback
    print "TCP Listener"
    print "Listening on ${host}:${port}"
    print "Waiting for a connection..."
    
    // enter the listening loop
    while true:
        // perform a blocking call to accept requests
        server.AcceptTcpClient()
        print "Connection established."
        return 0
