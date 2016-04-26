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

/*----------------------------------------------------------------------------*/
int main(void)
{
	FILE * fichierBond_A;
	fichierBond_A = fopen("Bond_A.wav", "rb");
	if (fichierBond_A != NULL)
	{

	}
	else
	{
		printf("\nErreur lors de l'ouverture du fichier yo");
	}
	

	// Fin lol
	system("pause");
	return EXIT_SUCCESS;
}