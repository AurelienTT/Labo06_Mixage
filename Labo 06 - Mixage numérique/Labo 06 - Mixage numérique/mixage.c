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

SAMPLE* charger(WAV_HEADER* header) {

	FILE* fichierWav;
	SAMPLE* temp;

	int ret = 0;
	char nomFichier[TAILLE_CHAINE] = "";

	do {								//Saisie du Nom du fichier à charger
		printf("Nom du fichier a charger : ");
		ret = scanf("%s", nomFichier);
		if (ret != 1) {
			printf("Erreur de saisie !\n");
			fflush(stdin);
		}
	} while (ret != 1);

	fichierWav = fopen(nomFichier, "rb");		//Chargement en mémoire du fichier
	if (fichierWav != NULL) {
		fread(header, sizeof(WAV_HEADER), 1, fichierWav);
		temp = (SAMPLE*)malloc((header->data.length / 2)*sizeof(SAMPLE));
		if (temp != NULL) {
			fread(temp, sizeof(SAMPLE), (header->data.length / 2), fichierWav);
			printf("Chargement de \"%s\" Reussi !\n\n", nomFichier);
		}
		fclose(fichierWav);
	}
	else
	{
		printf("Impossible d'ouvrire \"%s\" !\n\n", nomFichier);
	}
	return temp;
}

void mix(WAV_HEADER* headerA, SAMPLE* sampleA, WAV_HEADER* headerB, SAMPLE* sampleB, long blancA, long blancB) {
	
	FILE* fichierWav;
	SAMPLE sample = {0,0};
	WAV_HEADER header;

	long n = 0;
	int ret = 0;
	char nomFichier[TAILLE_CHAINE] = "";

	//initialisation du header de sauvgarde avec la bonne longueur
	header = *headerA;

	if (headerA->data.length + blancA >= headerB->data.length + blancB) {
		header.data.length = headerA->data.length + sizeof(SAMPLE)*blancA;
	}
	else {
		header.data.length = headerB->data.length + sizeof(SAMPLE)*blancB;
	}

	do {								//Saisie du Nom du fichier à enregistrer
		printf("Enregistrer sous : ");
		ret = scanf("%s", nomFichier);
		printf("\n");
		if (ret != 1) {
			printf("Erreur de saisie !\n");
			fflush(stdin);
		}
	} while (ret != 1);
								//Enregistrement du fichier
	fichierWav = fopen(nomFichier, "wb");
	if (fichierWav != NULL)
	{
		fwrite(&header, sizeof(WAV_HEADER), 1, fichierWav);
		do {
			if ((n < blancA) && (n < blancB)) {
				sample.droite = 0;
				sample.gauche = 0;
			}
			else if ((n < blancA) && (n >= blancB)) {
				sample.droite = sampleB[n - blancB].droite;
				sample.gauche = sampleB[n - blancB].gauche;
			}
			else if ((n >= blancA) && (n < blancB)) {
				sample.droite = sampleA[n - blancA].droite;
				sample.gauche = sampleA[n - blancA].gauche;
			}
			else {
				if ((n - blancA) >= (headerA->data.length/2)) {
					sample.droite = sampleB[n - blancB].droite;
					sample.gauche = sampleB[n - blancB].gauche;
				}
				else if ((n - blancB) >= (headerB->data.length/2)) {
					sample.droite = sampleA[n - blancA].droite;
					sample.gauche = sampleA[n - blancA].gauche;
				}
				else {
					sample.droite = sommeShort(sampleA[n - blancA].droite, sampleB[n - blancB].droite);
					sample.gauche = sommeShort(sampleA[n - blancA].gauche, sampleB[n - blancB].gauche);
				}
			}

			n++;

			fwrite(&sample, sizeof(SAMPLE), 1, fichierWav);

			if (ferror(fichierWav))
			{
				printf("Erreur d'ecriture du fichier wav\n\n");
				break;
			}
		} while ((n < (headerA->data.length/2)+blancA) || (n < (headerB->data.length/2)+blancB));
	}
	else
		printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n\n");
	if (fclose(fichierWav))
		printf("Le fichier de sauvegarde n'a pas ete correctement ferme.\n\n)");
}

long decalage() {				//Decalage entré en seconde et retourner en Nb de sample

	int ret = 0;
	long blancNbSample = 0;
	double blancSecondes = 0;

	do {
		printf("Commencer la piste a [s]: ");
		ret = scanf("%lf", &blancSecondes);
		if (ret != 1) {
			printf("Erreur de saisie !\n");
			fflush(stdin);
		}
	} while (ret != 1);

	printf("\n");

	blancNbSample = (long)blancSecondes*SAMPLE_RATE;
	return blancNbSample;
}

void regVolume(WAV_HEADER* header, SAMPLE* sample) {

	int ret = 0;
	unsigned short pourCent = 0;
	long n = 0;

	do {
		printf("Ajuster le volume de 0 a 1000 pour cent: ");
		ret = scanf("%hd", &pourCent);
		if ((ret != 1)||(pourCent > 1000)) {
			printf("Erreur de saisie !\n");
			fflush(stdin);
		}
	} while ((ret != 1) || (pourCent > 1000));

	printf("\n");

	for (n = 0; n < (header->data.length / 2); n++) {
		sample[n].droite = (short) sample[n].droite*(pourCent / 100.);
		sample[n].gauche = (short) sample[n].gauche*(pourCent / 100.);
	}
}

short sommeShort(short a, short b) {	//Somme avec contrôle des dépassement de limite du short
	short somme = 0;
	somme = a + b;
	if ((a < 0) == (b < 0)) {
		if (a < 0) {
			if (somme > b) somme = SHRT_MIN;
		}
		else {
			if (somme < b) somme = SHRT_MAX;
		}
	}
	return somme;
}