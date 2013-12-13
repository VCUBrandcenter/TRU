#include <CapacitiveSensor.h>
#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below

int numRuns = 1;   // execution count, so this doesn't run forever
int maxRuns = 10;   // maximum number of times the Choreo should be executed
int capSensePin = 10;
// This is how high the sensor needs to read in order
//  to trigger a touch.  You'll find this number
//  by trial and error, or you could take readings at 
//  the start of the program to dynamically calculate this.
int touchedCutoff = 130;
int paintButton = 10;  //GRN and 5V buttons that the user will click simultaniously to send data
int paintButton1 = 9;  //GRN and 5V buttons that the user will click simultaniously to send data
int paintButton2 = 8;  //GRN and 5V buttons that the user will click simultaniously to send data
int paintButton3 = 7;  //GRN and 5V buttons that the user will click simultaniously to send data


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil


void setup() {
     
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  Serial.begin(9600);
  pinMode(paintButton, INPUT);
  pinMode(paintButton1, INPUT);
  pinMode(paintButton2, INPUT);
  pinMode(paintButton3, INPUT);
  digitalWrite(paintButton, HIGH);
  
  // For debugging, wait until a serial console is connected.
  delay(4000);
  while(!Serial);
  Bridge.begin();
}
void loop()
{
  
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    delay(10);   
    
  if (total1 > 100) {
  //  digitalWrite(paintButton, HIGH); 
    Serial.println("Running AppendRow - Run #" + String(numRuns++));
    
    TembooChoreo AppendRowChoreo;

    // invoke the Temboo client
    AppendRowChoreo.begin();
    
    // set Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // set choreo inputs
    AppendRowChoreo.addInput("Password", "***********");
    AppendRowChoreo.addInput("Username", "***********");
    AppendRowChoreo.addInput("RowData", "Tickle Me Elmo,This device blah blah blah blah,$21.99,www.righthere.com");
    AppendRowChoreo.addInput("SpreadsheetTitle", "Christmas Wish List");
    
    // identify choreo to run
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");
    
    // run choreo; when results are available, print them to serial
    AppendRowChoreo.run();
    
    while(AppendRowChoreo.available()) {
      char c = AppendRowChoreo.read();
      Serial.print(c);
    }
    AppendRowChoreo.close();

  }
 else {
    digitalWrite(paintButton, LOW);
  }
  
    if (total2 > 100) {
  //  digitalWrite(paintButton, HIGH); 
    Serial.println("Running AppendRow - Run #" + String(numRuns++));
    
    TembooChoreo AppendRowChoreo;

    // invoke the Temboo client
    AppendRowChoreo.begin();
    
    // set Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // set choreo inputs
    AppendRowChoreo.addInput("Password", "***********");
    AppendRowChoreo.addInput("Username", "***********");
    AppendRowChoreo.addInput("RowData", "Tickle Me Elmo,This device blah blah blah blah,$21.99,www.righthere.com");
    AppendRowChoreo.addInput("SpreadsheetTitle", "Christmas Wish List");
    
    // identify choreo to run
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");
    
    // run choreo; when results are available, print them to serial
    AppendRowChoreo.run();
    
    while(AppendRowChoreo.available()) {
      char c = AppendRowChoreo.read();
      Serial.print(c);
    }
    AppendRowChoreo.close();

  }
 else {
    digitalWrite(paintButton1, LOW);
  }
  
    if (total3 > 100) {
  //  digitalWrite(paintButton, HIGH); 
    Serial.println("Running AppendRow - Run #" + String(numRuns++));
    
    TembooChoreo AppendRowChoreo;

    // invoke the Temboo client
    AppendRowChoreo.begin();
    
    // set Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // set choreo inputs
    AppendRowChoreo.addInput("Password", "**********");
    AppendRowChoreo.addInput("Username", "***********");
    AppendRowChoreo.addInput("RowData", "Tickle Me Elmo,This device blah blah blah blah,$21.99,www.righthere.com");
    AppendRowChoreo.addInput("SpreadsheetTitle", "Christmas Wish List");
    
    // identify choreo to run
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");
    
    // run choreo; when results are available, print them to serial
    AppendRowChoreo.run();
    
    while(AppendRowChoreo.available()) {
      char c = AppendRowChoreo.read();
      Serial.print(c);
    }
    AppendRowChoreo.close();

  }
 else {
    digitalWrite(paintButton2, LOW);
  }
  
 // Every 500 ms, print the value of the capacitive sensor
  if ( (millis() % 500) == 0){
    Serial.print("Capacitive Sensor on Pin 2 reads: ");
    Serial.println(readCapacitivePin(capSensePin));
  } 

//  Serial.println("Waiting...");
//  delay(3000); // wait 30 seconds between AppendRow calls
}

// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//          how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher
//  In order for this to work now,
// The pin should have a 1+Megaohm resistor pulling
//  it up to +5v.
uint8_t readCapacitivePin(int pinToMeasure){
  // This is how you declare a variable which
  //  will hold the PORT, PIN, and DDR registers
  //  on an AVR
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  if ((pinToMeasure >= 0) && (pinToMeasure <= 7)){
    port = &PORTD;
    ddr = &DDRD;
    bitmask = 1 << pinToMeasure;
    pin = &PIND;
  }
  if ((pinToMeasure > 7) && (pinToMeasure <= 13)){
    port = &PORTB;
    ddr = &DDRB;
    bitmask = 1 << (pinToMeasure - 8);
    pin = &PINB;
  }
  if ((pinToMeasure > 13) && (pinToMeasure <= 19)){
    port = &PORTC;
    ddr = &DDRC;
    bitmask = 1 << (pinToMeasure - 13);
    pin = &PINC;
  }
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  // Make the pin an input WITHOUT the internal pull-up on
  *ddr &= ~(bitmask);
  // Now see how long the pin to get pulled up
  int cycles = 16000;
  for(int i = 0; i < cycles; i++){
    if (*pin & bitmask){
      cycles = i;
      break;
    }
  }
  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  
  return cycles;
}

