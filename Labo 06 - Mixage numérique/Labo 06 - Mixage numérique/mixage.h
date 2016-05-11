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

#define TAILLE_CHAINE 30
#define SAMPLE_RATE 44100

long decalage();
short sommeShort(short a, short b);

typedef struct {
	short gauche;
	short droite;
}SAMPLE;


SAMPLE* charger(WAV_HEADER* header);
void mix(WAV_HEADER* headerA, SAMPLE* sampleA, WAV_HEADER* headerB, SAMPLE* sampleB, long blancA, long blancB);
void regVolume(WAV_HEADER* header, SAMPLE* sample);
