#include "track.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// ----------------
// -- AudioTrack --
// ----------------

#define SAMPLE_SIZE sizeof(int16_t)

// Object management
AudioTrack* audiotrack_create(uint16_t channels, uint32_t sample_rate, uint32_t samples){
  AudioTrack* track = (AudioTrack*) malloc(sizeof(AudioTrack));

  // Set up track data
  track->format.channels = channels;
  track->format.sample_rate = sample_rate;
  track->size = channels * samples * SAMPLE_SIZE;
  track->data = (int16_t *) malloc(sizeof(int16_t) * track->size);
  memset(track->data, 0, track->size);

  // Set up track editing data
  track->cursor = 0;
  return track;
}
void audiotrack_destroy(AudioTrack* track){
  // Check if track exists
  if (track == NULL)
    return;
  
  if (track->data != NULL)
    free(track->data);
  free(track);
}

// Sound creation


static void audiotrack_add_sound_square_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples);
static void audiotrack_add_sound_sawtooth_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples);
static void audiotrack_add_sound_pulse_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples);


void audiotrack_add_sound(AudioTrack* track, AudioWaveType type, uint32_t freq, int16_t volume, uint32_t samples){

  // Check if we've overflowed on the track
  if (track->cursor >= track->size || track->cursor < 0)
    return;

  // Clamp to add time only on track
  if (track->cursor + samples > track->size)
    samples = track->size - track->cursor;

  // Write out according to wave type
  switch (type)
  {
  case SQUARE:
    audiotrack_add_sound_square_wave(track, freq, volume, samples);
    break;
  case SAWTOOTH:
    audiotrack_add_sound_sawtooth_wave(track, freq, volume, samples);
    break;
  case PULSE:
    audiotrack_add_sound_pulse_wave(track, freq, volume, samples);
    break;
  
  default:
    printf("Unknown WAVE form : %d\n", type);
    exit(1);
  }

}


void audiotrack_cursor_move(AudioTrack* track, uint32_t samples){
  track->cursor += track->format.channels * samples;
}
void audiotrack_cursor_set(AudioTrack* track, uint32_t samples){
  track->cursor = track->format.channels * samples;
}


void audiotrack_duration_set(AudioTrack* track, uint32_t samples){
  // Change track
  uint32_t new_size = track->format.channels * samples * SAMPLE_SIZE;
  track->data = (int16_t *) realloc(track->data, sizeof(int16_t) * new_size);
  if (new_size > track->size)
    memset(track->data + track->size, 0, new_size - track->size);

  // Change aux data
  track->size = new_size;
}
void audiotrack_duration_add(AudioTrack* track, uint32_t samples){
  // Change track
  uint32_t add_size = track->format.channels * samples * SAMPLE_SIZE;
  track->data = (int16_t *) realloc(track->data, sizeof(int16_t) * (track->size + add_size));
  memset(track->data + track->size, 0, add_size);

  // Change aux data
  track->size += add_size;
}

// -----------------------
// -- Private funtcions --
// -----------------------

#define MAX_AUDIO_AMPLITUDE 32767

static void audiotrack_add_sound_square_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples){

  // Get signals period
  uint32_t period = track->format.sample_rate / freq;

  for (int i = 0; i < samples; i++){
    // Check if we're in the track
    if (track->cursor + (i + 1) * track->format.channels - 1 >= track->size)
      break;
    
    for (int j = 0; j < track->format.channels; j++){
      // Calclate new audio portion
      int64_t new_data = track->data[track->cursor + i * track->format.channels + j];
      if ((i % period) < (period / 2))
	      new_data +=  volume;
      else
	      new_data += -volume;



      // Clamp audio
      if (new_data > MAX_AUDIO_AMPLITUDE)
	      new_data =  MAX_AUDIO_AMPLITUDE;
      if (new_data < -MAX_AUDIO_AMPLITUDE)
	      new_data = -MAX_AUDIO_AMPLITUDE;

      // Set audio
      track->data[track->cursor + i * track->format.channels + j] = new_data;
    }
  }
}
static void audiotrack_add_sound_sawtooth_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples){
  // Get signals period
  uint32_t period = track->format.sample_rate/freq;

  
  for (int i = 0; i < samples; i++){
    // Check if we're in the track
    if (track->cursor + (i + 1) * track->format.channels - 1 >= track->size)
      break;
    
    for (int j = 0; j < track->format.channels; j++){
      // Calclate new audio portion
      int64_t new_data = track->data[track->cursor + i * track->format.channels + j];
      new_data += -volume + (i % period) * 2 * volume / period;

      // Clamp audio
      if (new_data > MAX_AUDIO_AMPLITUDE)
	      new_data = MAX_AUDIO_AMPLITUDE;
      if (new_data < -MAX_AUDIO_AMPLITUDE)
	      new_data = MAX_AUDIO_AMPLITUDE;

      // Set audio
      track->data[track->cursor + i * track->format.channels + j] = new_data;
    }
  }
}
static void audiotrack_add_sound_pulse_wave(AudioTrack* track, uint32_t freq, int16_t volume, uint32_t samples){

  // Get signals period
  uint32_t period = track->format.sample_rate/freq;

  
  for (int i = 0; i < samples; i++){
    // Check if we're in the track
    if (track->cursor + (i + 1) * track->format.channels - 1 >= track->size)
      break;
    
    for (int j = 0; j < track->format.channels; j++){
      // Calclate new audio portion
      int64_t new_data = track->data[track->cursor + i * track->format.channels + j];
      if ((i % period) < (period / 5))
	      new_data +=  volume;
      else
	      new_data += -volume;

      // Clamp audio
      if (new_data > MAX_AUDIO_AMPLITUDE)
	      new_data = MAX_AUDIO_AMPLITUDE;
      if (new_data < -MAX_AUDIO_AMPLITUDE)
	      new_data = MAX_AUDIO_AMPLITUDE;

      // Set audio
      track->data[track->cursor + i * track->format.channels + j] = new_data;
    }
  }
}
