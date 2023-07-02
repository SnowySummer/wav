#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "datatype.h"

// ----------------
// -- AudioTrack --
// ----------------

AudioTrack* audiotrack_create(uint16_t channels, uint32_t sample_rate, uint32_t samples);
void        audiotrack_destroy(AudioTrack* track);

void audiotrack_add_sound(AudioTrack* track, AudioWaveType type, uint32_t freq, int16_t volume, uint32_t samples);

void audiotrack_cursor_move(AudioTrack* track, uint32_t samples);
void audiotrack_cursor_set(AudioTrack* track, uint32_t samples);

void audiotrack_duration_set(AudioTrack* track, uint32_t samples);
void audiotrack_duration_add(AudioTrack* track, uint32_t samples);

// ----------------
// -- MusicTrack --
// ----------------


MusicTrack* musictrack_create(AudioFormat fmt, AudioWaveType instrument, float bpm, uint8_t time_signature_top, uint8_t time_signature_bot);
void        musictrack_destroy(MusicTrack* track);

void musictrack_bar_add(MusicTrack* track, uint8_t bars);
void musictrack_add_note(MusicTrack* track, const char notes[4], float volume, float duration);

void musictrack_cursor_move(MusicTrack* track, float duration);
void musictrack_cursor_set(MusicTrack* track, float position);
void musictrack_put(MusicTrack* track, const char notes[4], float volume, float duration);


#endif
