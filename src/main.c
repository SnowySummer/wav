#include "wav.h"
#include "track.h"

#include <stdlib.h>
#include <stdio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100.0



void play_pokemon(MusicTrack* track){

  for (int i = 0; i < 2; i++){
    musictrack_put(track, "", 0x0, 1);

    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 1.0);
    musictrack_put(track, "", 0x0, 0.5);

    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 1.0);
    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "F3", 0x1000, 1.0);
    musictrack_put(track, "", 0x0000, 0.5);


    musictrack_put(track, "F3", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 1.0);
    musictrack_put(track, "D4", 0x1000, 1.0);
    musictrack_put(track, "C4", 0x1000, 0.5);
    musictrack_put(track, "A#3", 0x1000, 1.0);
    musictrack_put(track, "C4", 0x1000, 1.5);
    musictrack_put(track, "", 0x0000, 3.5);


    musictrack_put(track, "D#4", 0x1000, 0.5);
    musictrack_put(track, "D#4", 0x1000, 0.5);
    musictrack_put(track, "D#4", 0x1000, 0.5);
    musictrack_put(track, "D#4", 0x1000, 1.0);
    musictrack_put(track, "", 0x0, 0.5);

    musictrack_put(track, "D#4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 1.0);
    musictrack_put(track, "C4", 0x1000, 0.5);
    musictrack_put(track, "A#3", 0x1000, 1.0);
    musictrack_put(track, "", 0x0000, 0.5);


    musictrack_put(track, "A#3", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 1.0);
    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 1.0);
    musictrack_put(track, "A#3", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 2);
    musictrack_put(track, "", 0x0000, 1.5);
  }
  

  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 1);


  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "G4", 0x1000, 1);
  musictrack_put(track, "F4", 0x1000, 1.5);
  musictrack_put(track, "", 0x0   , 1.5);


  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "A4", 0x1000, 0.5);
  musictrack_put(track, "A#4", 0x1000, 0.5);
  musictrack_put(track, "A4", 0x1000, 1);
  musictrack_put(track, "G4", 0x1000, 1);
  musictrack_put(track, "F4", 0x1000, 1);


  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "", 0x0, 0.5);

  musictrack_put(track, "G4", 0x1000, 2);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 1);
  musictrack_put(track, "D4", 0x1000, 1);
  musictrack_put(track, "C4", 0x1000, 1);


  musictrack_put(track, "A#3", 0x1000, 0.5);
  musictrack_put(track, "C4", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 1);
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "C4", 0x1000, 1);
  musictrack_put(track, "A#3", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 2.0);
  musictrack_put(track, "", 0x0, 0.5);

  
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 1);


  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "G4", 0x1000, 1);
  musictrack_put(track, "F4", 0x1000, 1.5);
  musictrack_put(track, "", 0x0   , 1.5);


  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "A4", 0x1000, 0.5);
  musictrack_put(track, "A#4", 0x1000, 0.5);
  musictrack_put(track, "A4", 0x1000, 1);
  musictrack_put(track, "G4", 0x1000, 1);
  musictrack_put(track, "F4", 0x1000, 1.5);
  musictrack_put(track, "", 0x0   , 0.5);
  

  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "D#4", 0x1000, 1);
  musictrack_put(track, "A#4", 0x1000, 1);
  musictrack_put(track, "A#4", 0x1000, 1);
  musictrack_put(track, "", 0x0   , 1);


  musictrack_put(track, "D#4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "A#4", 0x1000, 1);
  musictrack_put(track, "A#4", 0x1000, 1);
  musictrack_put(track, "", 0x0   , 1);


  musictrack_put(track, "A#4", 0x1000, 1.0);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "A#4", 0x1000, 1.0);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "A#4", 0x1000, 0.5);
  musictrack_put(track, "A4", 0x1000, 1);


  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "G4", 0x1000, 1);

  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 0.5);
  musictrack_put(track, "", 0x0   , 0.5);
  musictrack_put(track, "A#4", 0x1000, 1);
  musictrack_put(track, "G4", 0x1000, 1);


  musictrack_put(track, "D4", 0x1000, 0.5);
  musictrack_put(track, "F4", 0x1000, 0.5);
  musictrack_put(track, "G4", 0x1000, 1.5);
}
void play_lullaby(MusicTrack* track){
    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 2);


    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 2);


    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 0.5);
    musictrack_put(track, "G4", 0x1000, 1);
    musictrack_put(track, "F#4", 0x1000, 1);
    musictrack_put(track, "E4", 0x1000, 1);
    musictrack_put(track, "D4", 0x1000, 1);


    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 2);
    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "", 0, 0.5);



    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "B3", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 2);
    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "", 0, 0.5);



    musictrack_put(track, "A3", 0x1000, 0.5);
    musictrack_put(track, "C4", 0x1000, 0.5);
    musictrack_put(track, "F#4", 0x1000, 0.5);
    musictrack_put(track, "E4", 0x1000, 0.5);
    musictrack_put(track, "D4", 0x1000, 1);
    musictrack_put(track, "F#4", 0x1000, 1);
    musictrack_put(track, "G4", 0x1000, 2);

}

int main(void){

  

  
  // Set audio format
  AudioFormat fmt;
  fmt.channels = NUM_CHANNELS;
  fmt.sample_rate = SAMPLE_RATE;

  // Create music track
  MusicTrack* track = musictrack_create(fmt, SAWTOOTH, 90, 3, 4);
  musictrack_bar_add(track, 9);

  musictrack_put(track, "", 0, 0.5);
  play_lullaby(track);

  write_wav("data/music.wav", *track->audiotrack);
  musictrack_destroy(track);

  return 0;
}
