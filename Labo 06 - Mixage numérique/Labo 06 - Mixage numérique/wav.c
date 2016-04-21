/* Fichier : wav.c
* Auteur  : DMT
* Date    : 12.04.2015
*
* Description : Fonctions facilitant le remplissage des structures  
*               headers de fichiers musique wav
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2013
*/
#include "wav.h"

void prepare_riff_header(RIFF_HEADER * riff, long data_length)
{
    riff->riff[0] = 'R';
    riff->riff[1] = 'I';
    riff->riff[2] = 'F';
    riff->riff[3] = 'F';
    riff->length = data_length + sizeof(WAV_HEADER) - 8;
    riff->wav[0] = 'W';
    riff->wav[1] = 'A';
    riff->wav[2] = 'V';
    riff->wav[3] = 'E';
}

void prepare_format_header(FORMAT_HEADER * format,
                           int channel_number, int sample_rate_hz, int bits_per_sample)
{
    format->fmt[0] = 'f';
    format->fmt[1] = 'm';
    format->fmt[2] = 't';
    format->fmt[3] = ' ';
    format->length = 0x10;
    format->audio_format = 1; // PCM
    format->channel_number = channel_number;
    format->sample_rate = sample_rate_hz;
    format->byte_rate = sample_rate_hz * channel_number * bits_per_sample / 8;
    format->bytes_per_sample = channel_number * bits_per_sample / 8;
    format->bits_per_sample = bits_per_sample;
}

void prepare_data_header(DATA_HEADER * data, long data_length)
{
    data->data[0] = 'd';
    data->data[1] = 'a';
    data->data[2] = 't';
    data->data[3] = 'a';
    data->length = data_length;
}

void wav_prepare_header(WAV_HEADER * header, int channel_number, int sample_rate_hz, int sample_count, int bits_per_sample)
{
    long data_length;
    data_length = channel_number * sample_count * bits_per_sample / 8;
    prepare_riff_header(&header->riff, data_length);
    prepare_format_header(&header->format, channel_number, sample_rate_hz, bits_per_sample);
    prepare_data_header(&header->data, data_length);
}
