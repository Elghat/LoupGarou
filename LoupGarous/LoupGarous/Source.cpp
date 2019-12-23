#include "Header.h"
//#include "Kevin.cpp"
void threadEcouteJoueur(SOCKET csock, int indexPlayer);
void sendMessageToAll(char message[255]);

int main()
{
	srand(time(NULL));
	int nbrLoup = 2;
	int nbrVillageois = 6;
	char mystring[255] = { NULL };
	int nbrJoueur = 0;
	WSADATA WSAData; // Variable uniquement utile pour le WSAStartup
	WSAStartup(MAKEWORD(2, 0), &WSAData);  // On dit au pc qu'on voudrait utiliser les sockets
	mesJoueurs = (joueur*)calloc(8, sizeof(joueur));
	SOCKET sock = NULL; // Le socket server
	SOCKET csock; // Le socket client
	SOCKADDR_IN sin; // Contient les informations techniques du socket server
	SOCKADDR_IN csin;  // Contient les informations techniques du socket client
	sin.sin_addr.s_addr = INADDR_ANY; // qui définit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas à définir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent généralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on écoute
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(sock, (SOCKADDR*)&sin, sizeof(sin)))
	{
		printf("success");
	}
	else
	{
		printf("error");
	}
	if (sock)
	{
		printf("Socket initialized");
	}
	listen(sock, 0);
	int sinsize = sizeof(csin);

	//Si un joueur s'est connecté
	while (nbrJoueur < 8) 
	{
		int sinsize = sizeof(csin);
		if ((csock = accept(sock, (SOCKADDR*)&csin, &sinsize)) != INVALID_SOCKET) 
		{
			strcpy(mystring, "You are connected");
			send(csock, mystring, strlen(mystring), 0);
			recv(csock, mesJoueurs[nbrJoueur].pseudo, sizeof(mesJoueurs[nbrJoueur].pseudo), 0);//recevoir le pseudo
			mesJoueurs[nbrJoueur].alive = true;
			int choixCarte = rand() % 2;
			mesJoueurs[nbrJoueur].csock = csock;
			do
			{
				if (choixCarte == 0 && nbrLoup > 0)
				{
					strcpy(mesJoueurs[nbrJoueur].carte, "Loup");
					nbrLoup--;
				}
				if (choixCarte == 1 && nbrVillageois > 0)
				{
					strcpy(mesJoueurs[nbrJoueur].carte, "Villageois");
					nbrVillageois--;
				}
			} while (nbrLoup != nbrLoup - 1 && nbrLoup > 0 || nbrVillageois != nbrVillageois - 1 && nbrVillageois > 0);
			std::thread ecouteJoueur(threadEcouteJoueur, mesJoueurs[nbrJoueur].csock, nbrJoueur);
			nbrJoueur++;//nombre de joueur +1
		}
	}
	//Recevoir message et imprimer le message dans la console du server
	
	WSACleanup();

	return 0;
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

void threadEcouteJoueur(SOCKET csock, int indexPlayer)
{
	char message[255] = { NULL };
	char tmplMessage[255];
	while (1)
	{
		strcpy(tmplMessage, mesJoueurs[indexPlayer].pseudo);
		strcat(tmplMessage, " : ");
		recv(csock, message, sizeof(message), 0);
		strcat(tmplMessage, message);
		sendMessageToAll(tmplMessage);
		printf("%s", tmplMessage);
		memset(message, 0,sizeof(message));
		memset(tmplMessage, 0, sizeof(tmplMessage));
	}
}

void sendMessageToAll(char message[255])
{
	for (int i = 0; i < 9; i++)
	{
		send(mesJoueurs[i].csock, message, strlen(message), 0);
	}
}