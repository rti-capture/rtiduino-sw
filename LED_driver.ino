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

void setup() {
  
  leds[A][0] = 29; //71
  leds[A][1] = 28; //72
  leds[A][2] = 27; //73
  leds[A][3] = 26; //74
  leds[A][4] = 25; //75
  leds[A][5] = 24; //76
  leds[A][6] = 23; //77
  leds[A][7] = 22; //78
  
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
  for( int i = 0; i < 3; i++){
      //iterate through the banks of leds
      for(int j = 0; j < 8; j++){
       pinMode(leds[i][j], OUTPUT); //set the pin for the LED as an output
      }
  }
  

  
  Serial3.write("Init Complete\r\n");
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
     Serial3.println(input[1]);
     process(A, input[1]);
     process(B, input[3]);
     process(C, input[5]);
  }else{
   //didn't get the expected amount of data from the serial link before timeout 
   flash_debug(200);
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
  Serial3.write(state);
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
