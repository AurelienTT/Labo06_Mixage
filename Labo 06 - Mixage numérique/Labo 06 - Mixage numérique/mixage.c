/* Fichier : INFO2_labo05.c
* Auteur  : Trolliet Aur�lien & Pinto Almeida Claudio
* Date    : 26.04.2016
*
* Description:  programme de mixage audio
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2016
*/

#include <stdlib.h>
#include <stdio.h>
#include "wav.h"
#include "mixage.h"

chargerA(WAV_HEADER* fichierA) {
	int ret = 0;
	char nomFichier[TAILLE_CHAINE] = "";
	FILE* fichierWavA;

	do {
		printf("Nom du fichier A : ");
		ret = scanf("%s", nomFichier);
		if (ret != 1) {
			printf("Erreur de saisie !\n");
			fflush(stdin);
		}
	} while (ret != 1);

	fichierWavA = fopen(nomFichier, "rb");
	if (fichierWavA != NULL) {
		fread(fichierA, 44, 1, fichierWavA);
		fclose(fichierWavA);
	}
	else
	{
		printf("Erreur lors de l'ouverture du fichier A\n");
	}
	printf("sample_rate = %ld", fichierA->format.sample_rate);
	return EXIT_SUCCESS;
}