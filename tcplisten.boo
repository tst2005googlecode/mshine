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

def main():
    port = 4242 // listen on port 4242                         
    host = IPAddress.Parse("127.0.0.1") // host == "localhost"
    server = TcpListener(host, port)  // create server instance

    // print feedback   
    print "TCP Listener"
    print "Listening on ${host}:${port}"

main() // invoke main()

