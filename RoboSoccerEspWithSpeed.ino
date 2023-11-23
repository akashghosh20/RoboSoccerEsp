#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

int relay1 = 15; // motor1
int relay2 = 2;  // motor1
int relay3 = 4;  // motor2
int relay4 = 5;  // motor2

int speedPin1 = 22;  // PWM pin for motor1
int speedPin2 = 23;  // PWM pin for motor2

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESPAG"); // Bluetooth device name

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
}

void loop() {
  while (SerialBT.available()) {

    String incomingData = SerialBT.readStringUntil('\n');
    Serial.println("Received: " + incomingData);

    if(incomingData.startsWith("speed:")){
      handleSpeedValue(incomingData);
    }
    else{
      // Parse and handle the received data
        handleBluetoothData(incomingData[0]);
    }

  }

  // Your other tasks here
}

void handleBluetoothData(char data) {
  // Perform actions based on the received command
  

  switch (data) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'G':
      forwardLeft();
      break;
    case 'I':
      forwardRight();
      break;
    case 'H':
      backwardLeft();
      break;
    case 'J':
      backwardRight();
      break;
    case 'S':
      stopMotors();
      Serial.println("Stop command received");
      break;
    default:
      stopMotors();
      Serial.println("Unknown command received");
      break;
  }
}

void moveForward() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going forward");
}

void moveBackward() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward");
}

void stopMotors() {
  analogWrite(speedPin1, 0);  // Set motor1 speed to 0
  analogWrite(speedPin2, 0);  // Set motor2 speed to 0

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is stopped");
}

void turnRight() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going right");
}

void turnLeft() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going left");
}

void forwardLeft() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going forward-left");
}

void forwardRight() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going forward-right");
}

void backwardLeft() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward-left");
}

void backwardRight() {
  analogWrite(speedPin1, 255);  // Adjust the PWM value for motor1 speed
  analogWrite(speedPin2, 255);  // Adjust the PWM value for motor2 speed

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward-right");
}



void handleSpeedValue(String incomingData) {
  // Read the speed value as a string until a newline character is encountered
  

  // Extract the speed value from the received string
  int colonIndex = incomingData.indexOf(':');
  if (colonIndex != -1) {
    String valuePart = incomingData.substring(colonIndex + 1);
    
    // Convert the value part to an integer
    int speedValue = valuePart.toInt();

   

    // Set the analog write value for speed control
    analogWrite(speedPin1, speedValue);
    analogWrite(speedPin2, speedValue);

    Serial.print("Bots current  speed is: ");
    Serial.println(speedValue);
  }
}

