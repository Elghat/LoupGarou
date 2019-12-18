typedef struct monJoueur
{
	char pseudo[30];
	bool alive;
	char carte[255];
	//monJoueur* _next;
	//monJoueur* _previous;
	bool isConnected;
	char message[255];
}joueur;