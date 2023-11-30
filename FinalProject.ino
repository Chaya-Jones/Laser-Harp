#include <SoftwareSerial.h>
#include "Adafruit_Soundboard.h"

char cmd;
uint8_t n = 3;

// Choose any two pins that can be used with SoftwareSerial to RX & TX
#define SFX_TX 5
#define SFX_RX 6

// Connect to the RST pin on the Sound Board
#define SFX_RST 4

// You can also monitor the ACT pin for when audio is playing!

// we'll be using software serial
SoftwareSerial ss = SoftwareSerial(SFX_TX, SFX_RX);

// pass the software serial to Adafruit_soundboard, the second
// argument is the debug port (not used really) and the third
// arg is the reset pin
Adafruit_Soundboard sfx = Adafruit_Soundboard(&ss, NULL, SFX_RST);
// can also try hardware serial with
// Adafruit_Soundboard sfx = Adafruit_Soundboard(&Serial1, NULL, SFX_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit Sound Board!");

  // softwareserial at 9600 baud
  ss.begin(9600);
  // can also do Serial1.begin(9600)

  if (!sfx.reset()) {
    Serial.println("Not found");
    while (1)
      ;
  }
  Serial.println("SFX board found");
}


void loop() {
  flushInput();


  cmd = 'c';

  while (!Serial.available()) {

    //low E
    if (digitalRead(2) == true) {
      cmd = '#';
      n = 2;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }
    }
    //low F
            else if (digitalRead(3) == true) {
      cmd = '#';
      n = 3;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
    //low G
             else if (digitalRead(7) == true) {
      cmd = '#';
      n = 4;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
   //A
            else if (digitalRead(8) == true) {
      cmd = '#';
      n = 5;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
   //B
            else if (digitalRead(9) == true) {
      cmd = '#';
      n = 6;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
   //C
            else if (digitalRead(10) == true) {
      cmd = '#';
      n = 7;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
   //D
            else if (digitalRead(11) == true) {
      cmd = '#';
      n = 8;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }

    //E
            else if (digitalRead(12) == true) {
      cmd = '#';
      n = 9;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }
   //F
            else if (digitalRead(13) == true) {
      cmd = '#';
      n = 10;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }

    //G
            else if (digitalRead(14) == true) {
      cmd = '#';
      n = 11;

      Serial.print("\nPlaying track #");
        // Serial.println(n);
        if (!sfx.playTrack((uint8_t)n)) {
          Serial.println("Failed to play track?");
        }

            }

      break;
    }
  }



void flushInput() {
  // Read all available serial input to flush pending data.
  uint16_t timeoutloop = 0;
  while (timeoutloop++ < 40) {
    while (ss.available()) {
      ss.read();
      timeoutloop = 0;  // If char was received reset the timer
    }
    delay(1);
  }
}
