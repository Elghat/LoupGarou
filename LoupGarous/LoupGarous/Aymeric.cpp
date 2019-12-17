#include "Header.h"

int main()
{
	int n = 0; //nombre de joueur

	char myString[255] = { NULL };

	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	SOCKET sock;
	SOCKET Csock;

	SOCKADDR_IN sin;
	SOCKADDR_IN Csin;

	sin.sin_addr.s_addr = INADDR_ANY; //définit l'adresse du serveur (any = toute mes interfaces)
	sin.sin_family = AF_INET;
	sin.sin_port = htons(9999);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(sock, (SOCKADDR*)&sin, sizeof(sin))) {
		printf("success");
	}
	else {
		printf("error");
	}

	listen(sock, 0);

	while (1) {
		int sinsize = sizeof(Csin);
		Csock = accept(sock, (SOCKADDR*)&Csin, &sinsize);
		if (Csock != INVALID_SOCKET) {
			strcpy(myString, "You are connected");
			send(Csock, myString, strlen(myString), 0);
			recv(Csock, myString, sizeof(myString), 0);//recevoir le pseudo
			//mettre le pseudo dans la structure joueur
			//le metrre vivant
			//lui donner une carte
			closesocket(Csock);
		}
	}

	WSACleanup();
}