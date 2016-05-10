/* Fichier : INFO2_labo05.c
* Auteur  : Trolliet Aurélien & Pinto Almeida Claudio
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

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "wav.h"
#include "mixage.h"

SAMPLE* chargerA(WAV_HEADER* headerA, SAMPLE* fichierA) {
	int ret = 0;
	char nomFichier[TAILLE_CHAINE] = "";
	FILE* fichierWavA;
	SAMPLE* temp;

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
		fread(headerA, 44, 1, fichierWavA);			//Recherche de la longueur de la musique pour calloc
		temp = (SAMPLE*)realloc(fichierA, 1000*sizeof(SAMPLE));
		if (temp != NULL) {
			printf("Reallocation Reussie");
			fichierA = temp;
		}
		fread(fichierA, sizeof(SAMPLE) ,(headerA->data.length/2), fichierWavA);
		fclose(fichierWavA);
	}
	else
	{
		printf("Erreur lors de l'ouverture du fichier A\n");
	}
	return fichierA;
}

int ExportWav(SAMPLE* sample) {
	FILE* fichierWav;
	fichierWav = fopen("musique.wav", "wb");
	if (fichierWav != NULL)
	{
		fwrite(sample, sizeof(SAMPLE), 100, fichierWav);
		if (ferror(fichierWav))
		{
			printf("Erreur d'écriture du fichier .dat\n");
		}
	}
	else
		printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
	if (fclose(fichierWav))
		printf("Le fichier de sauvegarde n'a pas ete correctement ferme.\n)");
	return EXIT_SUCCESS;
}