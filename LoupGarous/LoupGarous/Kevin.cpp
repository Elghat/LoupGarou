#include "Header.h"


void ConnectS()
{
	char mystring[255] = { NULL };
	//char servername[255] = { NULL };
	WSADATA WSAData; // Variable uniquement utile pour le WSAStartup
	WSAStartup(MAKEWORD(2, 0), &WSAData);  // On dit au pc qu'on voudrait utiliser les sockets

	SOCKET sock; // Le socket server
	SOCKET csock; // Le socket client
	SOCKADDR_IN sin; // Contient les informations techniques du socket server
	SOCKADDR_IN csin;  // Contient les informations techniques du socket client
	sin.sin_addr.s_addr = INADDR_ANY; // qui définit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas à définir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent généralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on écoute
	sock = socket(AF_INET, SOCK_STREAM, 0);
	//char line[255] = { NULL };
	//


	if (bind(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		printf("success");
	}
	else
	{
		printf("error");
	}

	listen(sock, 0);
	int val = 0; // La variable int val sera utilisée pour prendre la valeur de retour du accept()



	while (1)
	{
		int sinsize = sizeof(csin);
		if ((csock = accept(sock, (SOCKADDR*)&csin, &sinsize)) != INVALID_SOCKET)
		{
			strcpy(mystring, "Hello World");
			send(csock, mystring, strlen(mystring), 0);
			closesocket(csock);
		}
	}



	
}




void Deconnect()
{
	WSACleanup();
}