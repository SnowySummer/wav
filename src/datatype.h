#ifndef __AUDIO_DATATYPE_H__
#define __AUDIO_DATATYPE_H__


#include <stdint.h>

// Audio format
typedef struct {
  uint16_t channels;
  uint32_t sample_rate;
} AudioFormat;



// AudioTrack
typedef enum {SQUARE, SAWTOOTH, PULSE} AudioWaveType;



typedef struct {
  // Track data
  AudioFormat format;
  uint32_t size;
  int16_t* data;

  // Track editing data
  uint32_t cursor;
} AudioTrack;

// MusicTrack

typedef struct {
  AudioWaveType instrument;
  uint16_t bpm;
  uint8_t time_signature_top;
  uint8_t time_signature_bot;

  AudioTrack* audiotrack;

} MusicTrack;

#endif
