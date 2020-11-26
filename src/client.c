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
 * client.c
 * This program communicates with the server by using read and write functions and a socket.
 */

//Main function
int main()
{
	//Variables
	char buffer[100];
	int sock;
	int i;
	struct sockaddr_in client;

	memset(&client, 0, sizeof(client));

	//Creating the socket 
	sock = socket(AF_INET, SOCK_STREAM, 0);

	//Error checking
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("Socket creation has failed.");
		exit(EXIT_FAILURE);
	}
	
	//Error checking
	if(connect(sock, (struct sockaddr *) &client, sizeof(client)) < 0)
	{
		printf("\nConnection between server and client failed.\n");
		return -1;
	}

	//Setting port for client
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_family = AF_INET;
	client.sin_port = htons(5019);

	//Converts IPv4 and IPv6 to binary
	//Error checking
	if(inet_pton(AF_INET, "127.0.0.1", &client.sin_addr) <= 0) 
	{
		printf("\nAddress is invalid.\n");
		return -1;
	}

	//Communicating with the server
	while(1)
	{
		//Entering message to be sent to server
		printf("\nEnter a message to be sent to the server: ");
		fgets(buffer, 100, stdin);
		//Writing message
		i = write(sock, buffer, 100);
		//Reading server message
		i = read(sock, buffer, 100);
		//Printing recieved message from server
		printf("Message recieved from server: %s", buffer);
	}

	//Closing the socket
	close(sock);
	return 0;
} //End main function

