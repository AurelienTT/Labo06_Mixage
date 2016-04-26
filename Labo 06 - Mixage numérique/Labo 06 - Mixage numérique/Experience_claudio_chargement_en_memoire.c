/* Fichier : lol.c
* Auteur  : Claudio Pinto Almeida
* Date    : 21.04.2016
*
* Description : Claudio apprend comment lire des fichiers binaires
*
*
* Remarque(s) : Claudio est nul, oui
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2015
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Experience_claudio_chargement_en_memoire.h"
#include "wav.h"
#include "mixage.h"

/*----------------------------------------------------------------------------*/
int main_claudio(void)
{
	FILE * fichierBond_A;
	WAV_HEADER * head_bond_A;


	fichierBond_A = fopen("Bond_A.wav", "rb");
	if (fichierBond_A != NULL)
	{
		//printf("\nSuccess lors de l'ouverture du fichier yo");
		fread(head_bond_A, 44, 1, fichierBond_A);
		//fread(head_bond_A, sizeof(long), 5, fichierBond_A);
		printf("sample_rate = %ld\n", head_bond_A->format.sample_rate);
	}
	else
	{
		printf("\nErreur lors de l'ouverture du fichier yo");
	}
	if (fclose(fichierBond_A))
	{
		printf("\nLe fichier ne s'est pas fermé correctement :D");
	}
	else
	{
		printf("\nLe fichier s'est fermé correctement yey");
	}
	

	// Fin lol
	system("pause");
	return EXIT_SUCCESS;
}