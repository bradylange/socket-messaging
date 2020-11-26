# socket-messaging
Server that allows in-sync communication using a socket connection.

Brady Lange

05/04/18

Op Sys Programming

Assignment 5

## `src/server.c`
This program is the server that allows a user to communicate using a socket
connection. This server allows users to have a flow of chats that are in-sync.
The server will listen for a string from a client. It will then print the string
and then ask for an input string.

## `src/client.c`
This program is the client that allows a user to communicate using a socket connection.
The client connects to the server and then asks for an input string from the user.
When the client recieves input from the user, it sends the string to the server 
using the socket connection. It will then wait for a response from the server before
printing the response and then asking for another input.

## `src/mtserver.c` and `src/mtclient.c`
This program is a modification of `server.c` and `client.c`.
The modification of the client server is to make them multi-threaded applications.
They will both have 2 threads. One thread will listen for input from a socket
connection and the other thread will be used to get an input string from the user
then send this string with a socket connection.

### Input:

`src/server.c`: `a.out`

`src/client.c`: `a.out`

`src/mtserver.c`: `a.out`

`src/mtclient.c`: `a.out`

### Output:

`src/server.c`: `Message received from client is: `

`src/client.c`: `Enter a string to be sent to the server: `

`src/mtserver.c`: `Message received from client is: `

`src/mtclient.c`: `Enter a string to be sent to the server: `

## Issues:
- `server.c`: Client closes after getting input from user
- `mtserver.c`: `mtserver.c` does not compile