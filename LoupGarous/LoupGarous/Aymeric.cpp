#include "Header.h"

int main()
{
	int nbrJoueur = 0; //nombre de joueur

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

	while (nbrJoueur <8) {
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
			nbrJoueur++;//nombre de joueur +1
		}
	}

	//la partie commence

	bool gagnant = false;

	while (!gagnant) {
		printf("les villageois s'endorment");//envoyer à tous les joueurs
		tourLoup();
		printf("les villageois se reveillent");//envoyer à tous les joueurs
		tourVillage();
	}
	

	WSACleanup();
}


void tourLoup() {
	//chat loup
	// slash kill pour tuer
	//mort
}

void tourVillage() {
	//chat commun
	//vote 
	//mort
}