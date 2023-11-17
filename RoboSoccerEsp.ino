#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

int relay1 = 15; // motor1
int relay2 = 2;  // motor1
int relay3 = 4;  // motor2
int relay4 = 5;  // motor2

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESPAkash"); // Bluetooth device name

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
}

void loop() {
  while (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.println("Received: " + String(receivedChar));

    // Parse and handle the received data
    handleBluetoothData(receivedChar);
  }

  // Your other tasks here
}

void handleBluetoothData(char data) {
  // Perform actions based on the received command
  Serial.print("Incoming data is ");
  Serial.println(data);

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
    case 'l':
      forwardLeft();
      break;
    case 'r':
      forwardRight();
      break;
    case 'b':
      backwardLeft();
      break;
    case 'I':
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
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going forward");
}

void moveBackward() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward");
}

void stopMotors() {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is stopped");
}

void turnRight() {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going right");
}

void turnLeft() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going left");
}

void forwardLeft()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going forward-left");
}

void forwardRight()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going forward-right");
}

void backwardLeft()
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going backward-left");
}

void backwardRight()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward-right");
}
