#include <SoftwareSerial.h> // To declare a new serial
#define first_pin 2
#define second_pin 3
#define third_pin 4
#define fourth_pin 5
#define fifth_pin 6
#define rxPin 7
#define txPin 8
#define led_pin 9

#define delay_period 14 // Wait time after each game
#define wrong_penalty 0.01f // Penalty for hitting the wrong button

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

void handleVictory() {
  digitalWrite(led_pin, HIGH); // Switch on the LED for the corresponding player
  delay(2500);
  digitalWrite(led_pin, LOW);
}

// Check whether the user pressed other buttons
bool checkOtherPins(int pin_no) {
  int pin_array[] = {first_pin, second_pin, third_pin, fourth_pin, fifth_pin};
  int pin_array_length = sizeof(pin_array)/sizeof(pin_array[0]);
  for(int i = 0; i<pin_array_length; i++) {
    if(pin_array[i] == pin_no)
      continue; // Lets say the user has to press the second button. Then we don't check the output of second button from here
    int button_state = digitalRead(pin_array[i]);
    if(button_state == HIGH) { // If some other button is pressed return true
      return true;
    }
  }
  return false;
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
    if(checkOtherPins(pin_no) == true) {
      time_difference = -2;
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
  } else if(time_difference == -2) {
      return score*-1.0f*wrong_penalty; // Penalty is awarded for pressing wrong buttons
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
  pinMode(first_pin, INPUT);
  pinMode(second_pin, INPUT);
  pinMode(third_pin, INPUT);
  pinMode(fourth_pin, INPUT);
  pinMode(fifth_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  score = 0.0f; // Reset the score for each round
  threshold_period = 2000; // Wait period for button press (2 seconds)
  slaveSerial.begin(9600);
  while(!slaveSerial); // Wait for the custom serial to connect
}
/*
 Transmission from each pin may take some time. So they are placed in the buffer
 and then codes are executed. So sometimes we may begin executing the code we have input
 from the pin
 */
void loop() {
  digitalWrite(led_pin, LOW);
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
     * P : Return score from player
     * w : You won the game
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
        // Return score from player
        slaveSerial.write(score);
        break;
      case 'W':
        // Player has won
        handleVictory();
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
