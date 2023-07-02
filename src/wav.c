#include "wav.h"

#include <string.h>
#include <stdio.h>


// ----------------
// -- RIFF chunk --
// ----------------

typedef struct {
  uint8_t  id[4];
  uint32_t size;
  uint8_t  fmt[4];
} RIFF_chk;
static char RIFF_ID[5] = "RIFF";
static char RIFF_FMT[5] = "WAVE";

static RIFF_chk create_riff(uint32_t size){
  RIFF_chk riff;
  memcpy(riff.id, RIFF_ID, 4);
  riff.size = size;
  memcpy(riff.fmt, RIFF_FMT, 4);
  return riff;
}



// ---------------
// -- FMT chunk --
// ---------------

typedef struct {
  uint8_t  id[4];
  uint32_t size;
  uint16_t fmt;
  uint16_t channels;
  uint32_t sample_rate;
  uint32_t byte_rate;
  uint16_t blk_align;
  uint16_t bpsample;
} FMT_chk;
static char FMT_ID[5] = "fmt "; 

static FMT_chk create_fmt(AudioFormat format){
  FMT_chk fmt;
  memcpy(fmt.id, FMT_ID, 4);
  fmt.size = 16;
  fmt.fmt = 1;
  fmt.channels = format.channels;
  fmt.sample_rate = format.sample_rate;  
  fmt.byte_rate = format.channels * format.sample_rate * sizeof(int16_t);
  fmt.blk_align = format.channels * sizeof(int16_t);
  fmt.bpsample = 8 * sizeof(int16_t);
  return fmt;
}



// ----------------
// -- DATA chunk --
// ----------------

typedef struct {
  uint8_t  id[4];
  uint32_t size;
  int16_t* data;
} DATA_chk;
static char DATA_ID[5] = "data";

static DATA_chk create_data(AudioTrack track){
  DATA_chk data;
  memcpy(data.id, DATA_ID, 5);
  data.size = track.size;
  data.data= track.data;
  return data;
}



// ---------------
// -- Final WAV --
// ---------------

void write_wav(const char* filepath, AudioTrack track){
  // Prepare chunks
  RIFF_chk riff = create_riff(track.size + 36);
  FMT_chk  fmt  = create_fmt(track.format);
  DATA_chk data = create_data(track);

  
  // Write WAV files
  FILE* f = fopen(filepath, "w");
  fwrite(&riff, 1, sizeof(RIFF_chk), f);
  fwrite(&fmt, 1, sizeof(FMT_chk), f);
  fwrite(&data.id, 1, sizeof(data.id), f);
  fwrite(&data.size, 1, sizeof(data.size), f);
  fwrite(data.data, 1, track.size, f);
  fclose(f);
}
