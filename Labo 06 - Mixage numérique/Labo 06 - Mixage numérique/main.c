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
	WAV_HEADER headerA;
	WAV_HEADER headerB;

	SAMPLE* fichierA = NULL;
	SAMPLE* fichierB = NULL;

	long blancA = 0;
	long blancB = 0;

	int n = 0;
	int choix = ZERO, valide = ZERO;

	printf("Labo06 - Mixage numerique\n\n");
	printf("-------- Debut du programme ! --------\n\n");
	
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
			fichierA = charger(&headerA);
			break;
		case 2:
			fichierB = charger(&headerB);
			break;
		case 3:
			blancA = decalage();
			break;
		case 4:
			blancB = decalage();
			break;
		case 5:
			regVolume(&headerA, fichierA);
			break;
		case 6:
			regVolume(&headerB, fichierB);
			break;
		case 7:
			mix(&headerA, fichierA, &headerB, fichierB, blancA, blancB);
			break;
		default:
			printf("Choix invalide !\n");
		}
	} while (choix != ZERO);

	for (n = 0; n < 10; n++) {
		printf("G:%d | D:%d", fichierA[n].gauche, fichierA[n].droite);
	};
	//free(port);
	return EXIT_SUCCESS;
}
