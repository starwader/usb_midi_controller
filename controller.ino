#include <Control_Surface.h>  // Include the library
#define offset 17
USBMIDI_Interface midi;  // Instantiate a MIDI Interface to use
 
// Instantiate an analog multiplexer
CD74HC4051 mux {
  A0,       // Analog input pin
  {10, 16, 14} // Address pins S0, S1, S2
};
 
// Create an array of CCPotentiometer objects that send out MIDI Control Change 
// messages when you turn the potentiometers connected to the 8 inputs of the mux.
// 3, 15, 2, 4, 5, (down - 8, up - 9), (down - 7, up - 6)

CCPotentiometer volumePotentiometers[] {
  { mux.pin(0), offset+0 },
  { mux.pin(1), offset+1 },
  { mux.pin(2), offset+2 },
  { mux.pin(3), offset+3 },
  { mux.pin(4), offset+4 },
  { mux.pin(5), offset+5 },
  { mux.pin(6), offset+6 },
  { mux.pin(7), offset+7 },
};
CCButton buttons[] {
  {3, offset+8},
  {15, offset+9},
  {2, offset+10},
  {4, offset+11},
  {5, offset+12},
  {8, offset+13},
  {9, offset+14},
  {7, offset+15},
  {6, offset+16},

};
 
void setup() {
  Control_Surface.begin();  // Initialize the Control Surface
}
 
void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
