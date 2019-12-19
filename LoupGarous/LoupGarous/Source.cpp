#include "Header.h"
//#include "Kevin.cpp"
int main()
{

	char mystring[255] = { NULL };
	int nbrJoueur = 0;
	WSADATA WSAData; // Variable uniquement utile pour le WSAStartup
	WSAStartup(MAKEWORD(2, 0), &WSAData);  // On dit au pc qu'on voudrait utiliser les sockets
	joueur* mesJoueurs;
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
			recv(csock, mesJoueurs[0].pseudo, sizeof(mesJoueurs[0].pseudo), 0);//recevoir le pseudo
			//mettre le pseudo dans la structure joueur
			//le metrre vivant
			//lui donner une carte
			nbrJoueur++;//nombre de joueur +1
		}
	}
	//Recevoir message et imprimer le message dans la console du server
	while (1)
	{
		recv(csock, mystring, sizeof(mystring), 0);
		//TODO : Créer une fonction qui envoie le message a tout le monde
		printf("%s", mystring);
	}
	
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