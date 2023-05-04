// include the library code:
#include "pitches.h"

// define the notes used in the song
int notes[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4
};

// define the note durations used in the song
int noteDurations[] = {
  4, 8, 8, 4, 8, 8, 4, 4,
  4, 8, 8, 4, 8, 8, 2,
  4, 8, 8, 4, 8, 8, 4, 4,
  4, 8, 8, 4, 8, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    // calculate the duration of the note:
    int duration = 1000 / noteDurations[i];
    tone(10, notes[i], duration);

    // pause between notes:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(10);
  }
}

void loop() {
  // do nothing in the loop
}