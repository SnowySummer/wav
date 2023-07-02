#include "track.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Notes from octave 10 from C - B
float note_freq[12] = {
    16744, 17739, 18794, 19912, 21096, 22350,
    23679, 25087, 26579, 28160, 29834, 31608
};


MusicTrack* musictrack_create(AudioFormat fmt, AudioWaveType instrument, float bpm, uint8_t time_signature_top, uint8_t time_signature_bot){
    MusicTrack* track = (MusicTrack*) malloc(sizeof(MusicTrack));

    track->audiotrack = audiotrack_create(fmt.channels, fmt.sample_rate, 0);
    track->instrument = instrument;
    track->bpm = bpm;
    track->time_signature_top = time_signature_top;
    track->time_signature_bot = time_signature_bot;

    return track;
}


void musictrack_destroy(MusicTrack* track){
    // Check track existence
    if (track == NULL)
        return;
    if (track->audiotrack != NULL)
        audiotrack_destroy(track->audiotrack);
    free(track);
}


void musictrack_bar_add(MusicTrack* track, uint8_t bars){
    uint32_t time = 60.0 * track->time_signature_top * bars * track->audiotrack->format.sample_rate / track->bpm;
    audiotrack_duration_add(track->audiotrack, time);
}


static int8_t check_accidental(const char notes[4]){
    for (int i = 0; i < 3; i++){
        if (notes[i] == '#')
            return 1;
        else if (notes[i] == 'b')
            return -1;
    }
    return 0;
}

static uint8_t check_octave(const char notes[4]){
    for (int i = 0; i < 3; i++){
        if ('0' <= notes[i] && notes[i] <= '9')
            return notes[i] - '0';
    }
    return 10;
}


static uint8_t check_notes(const char notes[4], int8_t accidental){
    int8_t val = notes[0] - 'C';


    if (val < 0) val += 7;
    val *= 2;
    if (val >= 6)
        val -= 1;
    val += accidental;
    if (val < 0)  val += 12;
    if (val > 12) val -= 12;
    return val;
}

void musictrack_add_note(MusicTrack* track, const char notes[4], float volume, float duration){

    if (volume == 0)
        return;
    uint32_t freq = 0;
    int8_t accidental = check_accidental(notes);
    uint8_t note = check_notes(notes, accidental);
    uint8_t octave = check_octave(notes);
    // Check octave overflow
    if (accidental == 1 && note == 0)
        octave++;
    if (accidental == -1 && note == 11)
        octave--;

    freq = note_freq[note] * pow (2, octave - 10);

    uint32_t samples = duration * 60.0 * track->audiotrack->format.sample_rate / track->bpm;
    audiotrack_add_sound(track->audiotrack, track->instrument, freq, 0x1000, samples);
}



void musictrack_cursor_move(MusicTrack* track, float duration){
    audiotrack_cursor_move(track->audiotrack, duration * 60.0 * track->audiotrack->format.sample_rate / track->bpm);
}

void musictrack_cursor_set(MusicTrack* track, float position){
    audiotrack_cursor_set(track->audiotrack, position * 60.0 * track->audiotrack->format.sample_rate / track->bpm);
}

void musictrack_put(MusicTrack* track, const char notes[4], float volume, float duration){
  musictrack_add_note(track, notes, volume, duration - 0.02);
  musictrack_cursor_move(track, duration);
}