// Included Libraries for the LPC2148 ARM
// Holds general addresses for the LPC2148 (Register Names, Interrupts addresses, Port Names/Numbers etc...)
#include "LPC214x.h"

// General Definitions for Code Readability
// The pin numbers were found on the UberBoard v2 Schematic
#define RED_LED         (1<<18) // The Red LED is on Port 0-Pin 18
#define GREEN_LED       (1<<19) // The Green LED is on Port 0-Pin 19
#define BLUE_LED        (1<<20) // The Blue LED is on Port 0-Pin 20

//*******************************************************
//                                      Function Prototypes
//*******************************************************
void delay_ms(int count);       // Tell the compiler we are going to be using a functions called "delay_ms"

int main (void) {
  //*******************************************************
  //                                      Initialization
  //*******************************************************
  IODIR0 |= RED_LED | GREEN_LED | BLUE_LED;       // Set the Red, Green and Blue LED pins as outputs
  IOSET0 = RED_LED | GREEN_LED | BLUE_LED;        // Initially turn all of the LED's off

//*******************************************************
//                                      Main Code
//*******************************************************
// Now that everything is initialized, let's run an endless program loop
 while (1) {
   IOCLR0 = RED_LED;              // Turn on the Red LED
   IOSET0 = GREEN_LED | BLUE_LED; // Make sure Green and Blue are off
   delay_ms(3330);                // Leave the Red LED on for 1/3 of a second
   IOCLR0 = GREEN_LED;            // Now turn the Green LED on
   IOSET0 = RED_LED | BLUE_LED;   // and turn off Red and Blue
   delay_ms(3330);                // Leave the Green LED on for 1/3 of a second
   IOCLR0 = BLUE_LED;             // Now turn on the Blue LED
   IOSET0 = RED_LED | GREEN_LED;  // Make sure Red and Green are off
   delay_ms(3330);                // Leave the Blue LED on for 1/3 of a second
 }

 return 0;
}


// Usage: delay_ms(1000);
// Inputs: int count: Number of milliseconds to delay
// The function will cause the firmware to delay for "count" milleseconds.
void delay_ms (int count) {
  int i;
  count *= 10000;
  for (i = 0; i < count; i++) // We are going to count to 10000 "count" number of times
    asm volatile ("nop");           // "nop" means no-operation.  We don't want to do anything during the delay
}
