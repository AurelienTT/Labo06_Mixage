/* Fichier : wav.h
* Auteur  : DMT
* Date    : 12.04.2015
*
* Description : Structures des headers des fichiers musique wav et
*               prototypes de la fonction facilitant le remplissage de ces headers 
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2013
*/
#ifndef __WAV_FILE_H_
#define __WAV_FILE_H_

typedef struct
{
    char riff[4]; // must contain "RIFF"
    long length;  // must contain total length of file - 8
    char wav[4];  // must contain "WAVE"
} RIFF_HEADER;

typedef struct
{
    char fmt[4]; // must contain "fmt "
    long length; // must contain 0x10
    short audio_format; // must contain 1 for PCM
    short channel_number; // 1 = mono, 2 = stereo, ...
    long sample_rate; // in Hz
    long byte_rate; // == sample_rate * channel_number * BitsPerSample/8
    short bytes_per_sample; // 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
    short bits_per_sample; // = 8, 16
} FORMAT_HEADER;

typedef struct
{
    char data[4] ; // must contain data
    long length; // length of data;
} DATA_HEADER;

typedef struct 
{
    RIFF_HEADER riff;
    FORMAT_HEADER format;
    DATA_HEADER data;
} WAV_HEADER;

void wav_prepare_header(WAV_HEADER * header, int channel_number, int sample_rate_hz, 
                        int sample_count, int bits_per_sample);

#endif