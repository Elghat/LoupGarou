#include "Header.h"
//#include "Kevin.cpp"
int main()
{

	char mystring[255] = { NULL };
	//char servername[255] = { NULL };
	WSADATA WSAData; // Variable uniquement utile pour le WSAStartup
	WSAStartup(MAKEWORD(2, 0), &WSAData);  // On dit au pc qu'on voudrait utiliser les sockets
	joueur* mesJoueurs;
	mesJoueurs = (joueur*)malloc(8);
	SOCKET sock = NULL; // Le socket server
	SOCKET csock; // Le socket client
	SOCKADDR_IN sin; // Contient les informations techniques du socket server
	SOCKADDR_IN csin;  // Contient les informations techniques du socket client
	sin.sin_addr.s_addr = INADDR_ANY; // qui d�finit l'adresse du serveur. Si vous codez un serveur, vous n'avez pas � d�finir d'adresse, vous utiliseriez donc : sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET; //  la "famille" du socket, le type si on veut. Pour l'Internet, les programmeurs utilisent g�n�ralement AF_INET. 
	sin.sin_port = htons(9999); // port sur lequel on �coute
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
	if (sock)
	{
		printf("Socket initialized");
	}
	listen(sock, 0);//
	int sinsize = sizeof(csin);
	//Si un joueur s'est connect�
	if ((csock = accept(sock, (SOCKADDR*)&csin, &sinsize)) != INVALID_SOCKET)
	{
		printf("Someone connected");
		strcpy(mystring, "Hello World\r\n");
		send(csock, mystring, strlen(mystring), 0);
		send(csock, "connard\0", strlen("connard\0"), 0);
		/*recv(csock, )*/
	}
	//Recevoir message et imprimer le message dans la console du server
	while (1)
	{
		recv(csock, mystring, sizeof(mystring), 0);
		//TODO : Cr�er une fonction qui envoie le message a tout le monde
		printf("%s", mystring);
	}

	closesocket(csock);


	
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