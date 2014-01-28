/*
 LED driver for RTI domes mark >3
 Autumn 2013
 Philip Basford
 pjbasford@ieee.org
 
 WARNING: All arrays are bytes so sizeof = length
*/

  //Setup variables
  const byte CAMERA_SHUTTER = 41; //51 output to trigger camera
  const byte TRIGGER = 39; // 70Input to start automated capture
  const byte AUTOMATED_RUNNING_LED = 40; //52
  const byte DEBUG_LED = 13;
  //OUTPUT BANKS
  const byte A = 0;
  const byte B = 1;
  const byte C = 2;
  
  //LED OUTPUTS
   byte leds[3][8];
  
  //Automated running
  int LIGHT_ON_TIME = 1500;
  int PRE_ON_DELAY = 100;
  int SHUTTER_ACTUATION_TIME = 100;
  int BETWEEN_SHOT_DELAY = 100;
  byte rows[5];
  byte columns[16];
  
  //enable watchdog checks
  int ledburncheck = 1;
  
void debug(String output){
  Serial3.println(output);
}

void setup() {
  
  leds[A][0] = 22; //78
  leds[A][1] = 23; //77
  leds[A][2] = 24; //76
  leds[A][3] = 25; //75
  leds[A][4] = 26; //74
  leds[A][5] = 27; //73
  leds[A][6] = 28; //72
  leds[A][7] = 29; //71
  
  leds[B][0] = 37;  //53
  leds[B][1] = 36;  //54
  leds[B][2] = 35;	//55
  leds[B][3] = 34;	//56
  leds[B][4] = 33;	//57
  leds[B][5] = 32;	//58
  leds[B][6] = 31;	//59
  leds[B][7] = 30;	//60
  
  leds[C][0] = 49;	//35
  leds[C][1] = 48;	//36
  leds[C][2] = 47;	//37
  leds[C][3] = 46;	//38
  leds[C][4] = 45;	//39
  leds[C][5] = 44;	//40
  leds[C][6] = 43;	//41
  leds[C][7] = 42; 	//42
 
  rows[0] = leds[B][0];
  rows[1] = leds[B][1];
  rows[2] = leds[B][2];
  rows[3] = leds[B][3]; 
  rows[4] = leds[B][4];
  
  columns[0] = leds[A][0];
  columns[1] = leds[A][1];
  columns[2] = leds[A][2];
  columns[3] = leds[A][3];
  columns[4] = leds[A][4];
  columns[5] = leds[A][5];
  columns[6] = leds[A][6];
  columns[7] = leds[A][7];
  columns[8] = leds[C][0];
  columns[9] = leds[C][1];
  columns[10] = leds[C][2];
  columns[11] = leds[C][3];
  columns[12] = leds[C][4];
  columns[13] = leds[C][5];
  columns[14] = leds[C][6];
  columns[15] = leds[C][7];
  
  Serial3.begin(38400); //init serial port
  Serial3.setTimeout(100);
  Serial3.write("RTI DOME Controller v0.1 \r\n");

  //Setup IO
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
  
   watchdoginit();
  
  Serial3.write("Init Complete\r\n");
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
  OCR1A = 65500; // = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
 }
 
 void watchdogstop() {
   debug("dog stop");
   //digitalWrite(DEBUG_LED, LOW);
  // Set CS12 and CS10 bits ZERO to stop timer 
  TCCR1B &= !((1 << CS12) | (1 << CS10)); 
}

void watchdogstart() {
  debug("dog start");
  digitalWrite(DEBUG_LED, HIGH);
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
    Serial3.write("Starting autorun\r\n");
    autorun();
    Serial3.write("Autorun complete\r\n");
  }
  if(Serial3.peek() == '?'){
    
    // This is the software querying to make sure it's got the correct device attached
    Serial3.read();
    spoofResponse();
  }else if(Serial3.peek() == '!'){
    //This is the software trying to init the system, can just be thrown away
    char null[11];
    Serial3.readBytes(null, 9);
  } else if (Serial3.available() >=6){
    char input[10];
    Serial3.readBytes(input,6);
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
   for(int i = 0; i < sizeof(rows); i++){
     digitalWrite(rows[i], HIGH);
     for(int j = 0; j < sizeof(columns); j++){
       digitalWrite(columns[j], HIGH);
       delay(PRE_ON_DELAY);
       digitalWrite(CAMERA_SHUTTER, HIGH);
       delay(SHUTTER_ACTUATION_TIME);
       digitalWrite(CAMERA_SHUTTER, LOW);
       delay(LIGHT_ON_TIME);
       digitalWrite(columns[j], LOW);
       delay(BETWEEN_SHOT_DELAY);
     }
     digitalWrite(rows[i], LOW);
   }
   digitalWrite(AUTOMATED_RUNNING_LED, LOW);
}

void spoofResponse(){
   // Spoof the response from the USB IO device
   Serial3.println("USB I/O 24R1"); 
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
  if (ledburncheck){

    	process(A,char(0));
	process(B,char(0));
	process(C,char(0));
        debug("dog");
        watchdogstop();
        digitalWrite(DEBUG_LED, LOW);
        flash_debug(1000);
  }
  
}
