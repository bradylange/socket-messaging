#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

/*
 * Brady Lange
 * Program 4
 * 5/4/18
 * server.c
 * This program communicates with the client by using read and write functions and a socket.
 */

//Main function
int main()
{
	//Variables
	int i;
	socklen_t len;
	char buffer[100];
	int the_socket;
	int serverData;
	struct sockaddr_in address;
	struct sockaddr_in client;

	memset(&address, 0, sizeof(address));

	//Setting the port of the server
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(5019);
	
	//Creating the socket
	if((serverData = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		//Error checking
		perror("Socket creation failure.");
		exit(EXIT_FAILURE);
	}

	//Binding the server with socket
	if(bind(serverData, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		//Error checking
		perror("Binding process failure.");
		exit(EXIT_FAILURE);
	}

	//Listening for the client
	if(listen(serverData, 3) < 0)
	{
		//Error checking
		perror("Listen failure.");
		exit(EXIT_FAILURE);
	}

	//Size of client
	len = sizeof(client);

	if((the_socket = accept(serverData, (struct sockaddr*) &client, &len)) < 0)
	{
		//Error checking
		perror("Accept failure.");
		exit(EXIT_FAILURE);
	}

	//Communicating with the client
	while(1)
	{
		i = read(the_socket, buffer, 100);
		printf("Message received from client: %s", buffer);
		printf("\nEnter message to be sent to client: ");
		fgets(buffer, 100, stdin);
		i = write(the_socket, buffer, 100);
	}

	//Closing the socket
	close(the_socket);
	return 0;
} //End main function