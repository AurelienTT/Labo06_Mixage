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

#define TAILLE_CHAINE 20

typedef struct {
	short gauche;
	short droite;
}SAMPLE;

SAMPLE* chargerA(WAV_HEADER* headerA, SAMPLE* fichierA);
int ExportWav(SAMPLE* sampleTab);
