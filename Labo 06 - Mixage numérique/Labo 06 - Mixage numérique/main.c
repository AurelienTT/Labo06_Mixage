/* Fichier : INFO2_labo05.c
* Auteur  : Trolliet Aurélien & Pinto Almeida Claudio
* Date    : 21.04.2016
*
* Description:  programme de mixage audio
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2016
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "wav.h"
#include "mixage.h"

#define ZERO 0
#define EOL '\n'
#define ERR -1


int main()
{
	//WAV_HEADER* fichierA;
	//WAV_HEADER* fichierB;

	int choix = ZERO, valide = ZERO;

	printf("Labo06 - Mixage numerique\n\n");
	printf("-------- Debut du programme ! --------\n\n");

	//port = (Bateau*)calloc(NBR_MAX_BATEAUX, sizeof(Bateau));
	//chargerPort(port);
	
	do
	{

		printf("+-------------------------------------+\n");
		printf("|            MENU PRINCIPAL           |\n");
		printf("+-------------------------------------+\n");
		printf("| %-35s |\n", "1. Charger la piste A");
		printf("| %-35s |\n", "2. Charger la piste B");
		printf("| %-35s |\n", "3. Decalage temporel A");
		printf("| %-35s |\n", "4. Decalage temporel B");
		printf("| %-35s |\n", "5. Reglage Volume A");
		printf("| %-35s |\n", "6. Reglage Volume B");
		printf("| %-35s |\n", "7. Mixer");
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
			chargerA(fichierA);
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
		case 555:
			main_claudio();
			break;
		default:
			printf("Choix invalide !\n");
		}
	} while (choix != ZERO);
	//free(port);
	return EXIT_SUCCESS;
}
