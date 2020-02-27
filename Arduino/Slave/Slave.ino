#include <SoftwareSerial.h> // To declare a new serial
#define first_pin 1
#define second_pin 2
#define third_pin 3
#define fourth_pin 4
#define fifth_pin 5
#define delay_period 10 // Wait time after each game
#define rxPin 8
#define txPin 9

// Declaring a new serial named s2
// rxPin: the pin on which to receive serial data

// txPin: the pin on which to transmit serial data
SoftwareSerial slaveSerial(rxPin, txPin);
// We need to have two serials since serials support only one way communication

/*
                                      FLOW OF CONTROL FOR SLAVE
                                      
 * When the slave receives a command from the serial, it will interpret the command and do one of the following
 * 1. If command is of type note then it will try to caclulate the score after reading input from button 
 * 2. If command is of type order then it will follow the order of reset, send score
 */

float score; // Player score
unsigned long threshold_period; // Wait period for each note

void waitForNextRound() {
  delay(delay_period*1000); // Wait for delay_period seconds
}

float calculateScore(int pin_no) {
  unsigned long start_time, time_difference;
  start_time = micros();
  // Wait for input from button
  while(true) {
    // If button_state is high then it was pushed, else not pushed
    int button_state = digitalRead(pin_no); // Returns High or Low from the specified push button
    unsigned long intermediate_time = micros();
    if(button_state == HIGH) {
      time_difference = intermediate_time - start_time;
      break;
    }
    // Wait for a certain period and then terminate the current note for the player
    if(intermediate_time - start_time > threshold_period) {
      time_difference = -1;
      break;
    }
  }
  // Did not push a button or pushed the wrong button
  if(time_difference == -1) {
    return 0.0f;
    // Pushed the correct button
  } else if(time_difference > 0) {
    return (float)time_difference;
  }
}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600); // 9600 refers to speed of transfer of data => 9600 bps (bits per second) or 9600 bauds
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  // Specifying behaviour of pins
  // TODO: INPUT vs INPUT_PULLUP
  pinMode(first_pin, INPUT);
  pinMode(second_pin, INPUT);
  pinMode(third_pin, INPUT);
  pinMode(fourth_pin, INPUT);
  pinMode(fifth_pin, INPUT);
  score = 0.0f; // Reset the score for each round
  threshold_period = 0.0025;
  slaveSerial.begin(38400);
  while(!slaveSerial); // Wait for the custom serial to connect
}
/*
 Transmission from each pin may take some time. So they are placed in the buffer
 and then codes are executed. So sometimes we may begin executing the code we have input
 from the pin
 */
void loop() {
  Serial.flush(); // Wait for the serial buffer to be completely empty before executing the below codes
  // We will be reading char input from the pin ( size of char is 1 byte )
  if(Serial.available() >= 1) { // .available() method gives us the number of bytes available for reading from the Serial buffer
    char command = Serial.read(); // Read the incoming byte
    Serial.println("Command Received : "+command);
    /*
     * Command Documentation
     * A : Note A4 is received
     * B : Note B4 is received
     * C : Note C4 is received
     * D : Note D4 is received
     * E : Note E4 is received
     * P : Return score from player1 
     * Q : Return score from player2
     * R : Reset game
     */ 
     float current_round_score = 0.0f;
     switch(command) {
      case 'A':
        // Note A4 is played.
        current_round_score = calculateScore(first_pin);
        break;
      case 'B':
        // Note B4 is played.
        current_round_score = calculateScore(second_pin);
        break;
      case 'C':
        // Note C4 is played.
        current_round_score = calculateScore(third_pin);
        break;
      case 'D':
        // Note D4 is played.
        current_round_score = calculateScore(fourth_pin);
        break;
      case 'E':
        // Note E4 is played.
        current_round_score = calculateScore(fifth_pin);
        break;
      case 'P':
        // Return score from player 1
        slaveSerial.write(score);
        break;
      case 'Q':
        // Return score from player 2
        break;
      case 'R':
        // Reset the score
        score = 0.0f;
        waitForNextRound(); // Wait for next round to begin
        break;
      default:
        break;
     }
     score+=current_round_score; // Update the score after each note
  }
}
