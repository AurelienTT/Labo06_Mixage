/* Fichier : INFO2_labo05.c
* Auteur  : Trolliet Aurélien & Ottensmeyer Léonard
* Date    : 24.03.2016
*
* Description:  programme permettant de gérer un port
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2016
*/

#include <stdlib.h>
#include <stdio.h>

#define ZERO 0
#define EOL '\n'
#define ERR -1


int main()
{
	//Bateau* port;

	int choix = ZERO, valide = ZERO;
	//char noPlaque[TAILLE_CHAINE];

	printf("Labo04bis - Gestion d'un port\n\n");
	printf("-------- Debut du programme ! --------\n\n");

	//port = (Bateau*)calloc(NBR_MAX_BATEAUX, sizeof(Bateau));
	//chargerPort(port);
	
	do
	{

		printf("+-------------------------------------+\n");
		printf("|            MENU PRINCIPAL           |\n");
		printf("+-------------------------------------+\n");
		printf("| %-35s |\n", "1. Ajouter un bateau");
		printf("| %-35s |\n", "2. Supprimer un bateau");
		printf("| %-35s |\n", "3. Afficher un apercu");
		printf("| %-35s |\n", "4. Afficher le details des bateaux");
		printf("| %-35s |\n", "5. Sauver le port");
		printf("| %-35s |\n", "0. Quitter");
		printf("+-------------------------------------+\n\n");
		printf("Choix> ");

		valide = scanf("%d", &choix);
		printf("\n");
		while (getchar() != EOL);       // vidage du buffer

		if (valide == ZERO) choix = ERR;     // test

		switch (choix)
		{
		case 1:
		//	saisirBateau(port);
			break;
		case 2:
			//supprimerBateau(port, noPlaque);
			break;
		case 3:
			//afficherSommaire(port);
			break;
		case 4:
			//afficherDetails(port);
			break;
		case 5:
			//sauverPort(port);
			break;
		default:
			printf("Choix invalide !\n");
		}
	} while (choix != ZERO);
	//free(port);
	return EXIT_SUCCESS;
}
