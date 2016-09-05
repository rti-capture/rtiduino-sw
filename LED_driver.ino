/*
 LED driver for RTI domes mark >3
 Autumn 2013
 Philip Basford
 pjbasford@ieee.org
 
 WARNING: All arrays are bytes so sizeof = length
*/

/* ----------------------------------- Compile-time settings ---------------------------------- */  
#define DEBUG                   1     // Define whether to output debug info on debug serial port
#define HAS_SCREEN              1     // Define whether a serial screen is connected to Serial2
#define LED_BURN_CHECK          1     // Define whether to enable LED_BURN_CHECK
#define BUTTONS                 5     // The number of buttons connected to the controller
#define DEFAULT_NUM_LEDS        128   // The default number of LEDs connected. Currently only 76 and 128 are supported.

#define OVERWRITE_NUM_LEDS      128   // Compile-time overwite value for num_leds. This should be set, flashed, commented out and then re-flashed.

/* -------------------------------------------------------------------------------------------- */

/* -------------------------------- System Config Definitions --------------------------------- */  
// EEPROM Config
#include <EEPROM.h>
#define ADDR_NUM_LEDS           0

// Serial Port Assignments
#define DEBUG_SERIAL            Serial
#define SCREEN                  Serial2
#define CONSOLE                 Serial3

//OUTPUT BANKS
#define MAX_LEDS                128
#define LED_BANKS               3
#define A                       0
#define B                       1
#define C                       2

// Hardware Config
#define DEBUG_LED               13 // 
#define CAMERA_SHUTTER          41 // Package pin 51: output to trigger camera
#define TRIGGER                 39 // Package pin 70: Input to start automated capture
#define AUTOMATED_RUNNING_LED   40 // Package pin 52

//Button Config
#define BUTTON_0
#define BUTTON_1
#define BUTTON_2
#define BUTTON_3
#define BUTTON_4

// Default LED setting sanity check
#if ((DEFAULT_NUM_LEDS != 76) & (DEFAULT_NUM_LEDS != 128))
  #error "Unsupported Default Dome Size."
#endif

//LED Variables
uint8_t num_leds;
byte leds[LED_BANKS][8];
byte AUTORUN_LEDS[MAX_LEDS][LED_BANKS];

//Automated running
int LIGHT_ON_TIME = 1500;
int PRE_ON_DELAY = 100;
int SHUTTER_ACTUATION_TIME = 100;
int BETWEEN_SHOT_DELAY = 100;
/* -------------------------------------------------------------------------------------------- */

  
void debug(String output){
  //CONSOLE.println(output);
}

void setup() {
/* ------------------------------------ Setup serial ports ------------------------------------ */  
  CONSOLE.begin(38400); //init serial port
  CONSOLE.setTimeout(100);

#if DEBUG
  DEBUG_SERIAL.begin(9600);
  DEBUG_SERIAL.setTimeout(100);
#endif

#if HAS_SCREEN
  SCREEN.begin(9600); //init serial port
  SCREEN.setTimeout(100);
#endif
/* -------------------------------------------------------------------------------------------- */

/* --------------------------- Check & update stored number of LEDs --------------------------- */
  num_leds = EEPROM.read(ADDR_NUM_LEDS);    // Get the number of LEDs stored in EEPROM

#ifdef OVERWRITE_NUM_LEDS
  #warning Compile-Time overwrite set for LED Number. Please undef OVERWRITE_NUM_LEDS and reflash
#if ((OVERWRITE_NUM_LEDS != 76) & (OVERWRITE_NUM_LEDS != 128))
  #error "Unsupported Overwrite Dome Size."
#endif  
  num_leds = OVERWRITE_NUM_LEDS;
  EEPROM.put(ADDR_NUM_LEDS, OVERWRITE_NUM_LEDS);
#endif

  if((num_leds != 76) && (num_leds != 128)) {
    // Number of LEDs stored in EEPROM is corrupt. Reset to default.
#if DEBUG
    DEBUG_SERIAL.write("Error reading Number of LEDs from EEPROM: defaulting to ");
    DEBUG_SERIAL.print(DEFAULT_NUM_LEDS, DEC);
    DEBUG_SERIAL.write(" LEDs\r\n");
#endif    
    num_leds = DEFAULT_NUM_LEDS;
    EEPROM.put(ADDR_NUM_LEDS, DEFAULT_NUM_LEDS);
  }
/* -------------------------------------------------------------------------------------------- */

/* ------------------------------- Set LED Row and Column pins -------------------------------- */ 
  /* Rows 0-7 (+28V) */
  leds[A][0] = 22; // Package Pin 78
  leds[A][1] = 23; // Package Pin 77
  leds[A][2] = 24; // Package Pin 76
  leds[A][3] = 25; // Package Pin 75
  leds[A][4] = 26; // Package Pin 74
  leds[A][5] = 27; // Package Pin 73
  leds[A][6] = 28; // Package Pin 72
  leds[A][7] = 29; // Package Pin 71

  /* Columns 0-7 (GND) */
  leds[B][0] = 37;  // Package Pin 53
  leds[B][1] = 36;  // Package Pin 54
  leds[B][2] = 35;	// Package Pin 55
  leds[B][3] = 34;	// Package Pin 56
  leds[B][4] = 33;	// Package Pin 57
  leds[B][5] = 32;	// Package Pin 58
  leds[B][6] = 31;	// Package Pin 59
  leds[B][7] = 30;	// Package Pin 60

  /* Rows 8-15 (+28V) */
  leds[C][0] = 49;	// Package Pin 35
  leds[C][1] = 48;	// Package Pin 36
  leds[C][2] = 47;	// Package Pin 37
  leds[C][3] = 46;	// Package Pin 38
  leds[C][4] = 45;	// Package Pin 39
  leds[C][5] = 44;	// Package Pin 40
  leds[C][6] = 43;	// Package Pin 41
  leds[C][7] = 42; 	// Package Pin 42

/* -------------------------------------------------------------------------------------------- */

/* ------------------------------- Write initialisation strings ------------------------------- */ 
#if HAS_SCREEN
  SCREEN.write(254);
  SCREEN.write(128);
  SCREEN.write("RTI ");
#endif

if(num_leds == 76) {
  // Standard 76-LED Dome
  CONSOLE.write("RTI DOME Controller v0.2 \r\n");

#if DEBUG
  DEBUG_SERIAL.write("RTI DOME Controller v0.2 \r\n");
#endif

#if HAS_SCREEN
  SCREEN.write("DOME        ");
#endif
} else if(num_leds ==128) {
  // 128-LED SuperDome
  CONSOLE.write("RTI SUPERDOME Controller v0.2 \r\n");

#if DEBUG
  DEBUG_SERIAL.write("RTI SUPERDOME Controller v0.2 \r\n");
#endif

#if HAS_SCREEN
  SCREEN.write("SUPERDOME   ");
#endif
}

#if HAS_SCREEN  
  SCREEN.write(254);
  SCREEN.write(192);
  SCREEN.write("Controller v0.2 ");
#endif
/* -------------------------------------------------------------------------------------------- */

/* -------------------------------- Setup autorun LED sequence -------------------------------- */
  if(num_leds == 76)  {  
    setup_autorun_dome();
  } else if (num_leds == 128) {
    setup_autorun_superdome();
  }
/* -------------------------------------------------------------------------------------------- */

/* -------------------------------------- Setup I/O pins -------------------------------------- */ 
  pinMode(TRIGGER, INPUT);
  pinMode(CAMERA_SHUTTER, OUTPUT); 
  pinMode(AUTOMATED_RUNNING_LED, OUTPUT);
  digitalWrite(DEBUG_LED, LOW);
  for( int i = 0; i < 3; i++){
      //iterate through the banks of leds
      for(int j = 0; j < 8; j++){
        pinMode(leds[i][j], OUTPUT); //set the pin for the LED as an output
      }
  }
/* -------------------------------------------------------------------------------------------- */

/* ------------------------------------ Initialise Watchdog ----------------------------------- */
  watchdoginit();
/* -------------------------------------------------------------------------------------------- */

/* -------------------------------------- Setup I/O pins -------------------------------------- */   
  CONSOLE.write("Init Complete\r\n");
  
#if DEBUG
    DEBUG_SERIAL.write("Init Complete\r\n");
#endif 
/* -------------------------------------------------------------------------------------------- */  
}

boolean multiple_leds(byte input){
	//check that more than 1 bit is set in the input - if so then more than 1 LED
	// will be on so overheating is not an issue
	return !(input == 0) && (input&(input -1));
}

void watchdoginit() {
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz (15624)
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments (sets Timeout)
  OCR1A = 65535; // = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
 }
 
void watchdogstop() {
#if DEBUG
  DEBUG_SERIAL.write("\tWatchdog STOP\r\n");
#endif
  //digitalWrite(DEBUG_LED, LOW);
  // Set CS12 and CS10 bits ZERO to stop timer 
  TCCR1B &= !((1 << CS12) | (1 << CS10)); 
}

void watchdogstart() {
#if DEBUG
  DEBUG_SERIAL.write("\tWatchdog START\r\n");
#endif
  digitalWrite(DEBUG_LED, HIGH);
  TCNT1  = 0;//initialize counter value to 0
  // Set CS12 and CS10 bits for 1024 prescaler and start
  TCCR1B |= (1 << CS12) | (1 << CS10);  
}


void flash_debug(int time){
  digitalWrite(DEBUG_LED, HIGH);
  delay(time);
  digitalWrite(DEBUG_LED, LOW);
}


void loop() {
  if(digitalRead(TRIGGER) == LOW){
    CONSOLE.write("Starting autorun\r\n");
    autorun();
    CONSOLE.write("Autorun complete\r\n");
  }
  if(CONSOLE.peek() == '?'){  
    // This is the software querying to make sure it's got the correct device attached
    CONSOLE.read();
    spoofResponse();
  }else if(CONSOLE.peek() == '!'){
    //This is the software trying to init the system, can just be thrown away
    char null[11];
    CONSOLE.readBytes(null, 9);
  } else if (CONSOLE.available() >=6){
    char input[10];
    CONSOLE.readBytes(input,6);
    //read the expected amount of data 
  	char Astate = input[1];
  	char Bstate = input[3];
  	char Cstate = input[5];
  	if (Bstate == 0 || ( Astate == 0 && Cstate == 0)){
  		//all LEDs are off
      debug("All off");
  		watchdogstop();
  	}else if(multiple_leds(Astate) || multiple_leds(Bstate & 0x1F)  || multiple_leds(Cstate) || (Astate != 0 && Cstate != 0 )){
  		//more than 1 LED will be lit
      debug("multiple leds");
  		watchdogstop();
  	}else{
      debug("kick dog");
      watchdogstop();
  		watchdogstart();
  	}
    process(A, Astate);
    process(B, Bstate);
    process(C, Cstate);
  }else{
   //didn't get the expected amount of data from the serial link before timeout 
  }
}


void autorun(){
  // Perform an automated capture sequence 
  digitalWrite(AUTOMATED_RUNNING_LED, HIGH);
  SCREEN.write(254);
  SCREEN.write(192);
  SCREEN.write("                ");
  SCREEN.write(254);
  SCREEN.write(128);
  SCREEN.write("Autorun:        ");
  SCREEN.write(254);
  SCREEN.write(192);
  SCREEN.write("    /");
  SCREEN.print(num_leds, DEC);
  
  for(int i = 0; i < num_leds; i++){
      SCREEN.write(254);
      SCREEN.write(192);
      SCREEN.write("    ");
      SCREEN.write(254);
      SCREEN.write(192);
      SCREEN.print(i, DEC);         
      process(A, char(AUTORUN_LEDS[i][0]));
      process(B, char(AUTORUN_LEDS[i][1]));
      process(C, char(AUTORUN_LEDS[i][2]));
      delay(PRE_ON_DELAY);
      digitalWrite(CAMERA_SHUTTER, HIGH);
      delay(SHUTTER_ACTUATION_TIME);
      digitalWrite(CAMERA_SHUTTER, LOW);
      delay(LIGHT_ON_TIME);
      process(A, char(0));
      process(B, char(0));
      process(C, char(0));
      delay(BETWEEN_SHOT_DELAY);   
  }
  digitalWrite(AUTOMATED_RUNNING_LED, LOW);
  
  SCREEN.write(254);
  SCREEN.write(128);
  SCREEN.write("RTI DOME        ");
  SCREEN.write(254);
  SCREEN.write(192);
  SCREEN.write("Controller v0.2 ");
  
}

void spoofResponse(){
  // Spoof the response from the USB IO device
  CONSOLE.println("USB I/O 24R1"); 
}

void process(byte bank, byte state_in){
  int state = state_in + 0;
  if (state & 1){
      digitalWrite(leds[bank][0], HIGH);
  }else{
    digitalWrite(leds[bank][0], LOW);
  }
  if (state & 2){
    digitalWrite(leds[bank][1], HIGH);
  }else{
    digitalWrite(leds[bank][1], LOW);
  } 
  if (state & 4){
    digitalWrite(leds[bank][2], HIGH);
  }else{
    digitalWrite(leds[bank][2], LOW);
  }
  if (state & 8){
    digitalWrite(leds[bank][3], HIGH);
  }else{
    digitalWrite(leds[bank][3], LOW);
  }
  if (state & 16){
    digitalWrite(leds[bank][4], HIGH);
  }else{
    digitalWrite(leds[bank][4], LOW);
  }
  if (state & 32){
    digitalWrite(leds[bank][5], HIGH);
  }else{
     digitalWrite(leds[bank][5], LOW);
  }
  if (state & 64){
    digitalWrite(leds[bank][6], HIGH);
  }else{
    digitalWrite(leds[bank][6], LOW);
  }
  if (state & 128){
    digitalWrite(leds[bank][7], HIGH);
  }else{
    digitalWrite(leds[bank][7], LOW);
  }
}


ISR(TIMER1_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  if (LED_BURN_CHECK){
   	process(A,char(0));
  	process(B,char(0));
	  process(C,char(0));
    debug("dog");
    watchdogstop();
    digitalWrite(DEBUG_LED, LOW);
    flash_debug(1000);
  }
}
