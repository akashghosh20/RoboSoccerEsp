#include <BluetoothSerial.h>
BluetoothSerial SerialBT;


int relay1 = 15; // motor1
int relay2 = 2;  // motor1
int relay3 = 4;  // motor2
int relay4 = 5;  // motor2

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Serial"); // Bluetooth device name

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);


}

void loop() {
  if (SerialBT.available()) {
    String receivedData = SerialBT.readStringUntil('\n');
    Serial.println("Received: " + receivedData);

    // Parse and handle the received data
    handleBluetoothData(receivedData);
  }

  // Your other tasks here
}

void handleBluetoothData(String data) {
  // Assuming the received data is a single character command
  char command = data.charAt(0);

  // Perform actions based on the received command
  switch (command) {
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
    case 'S':
      stopMotors();
      break;
    default:
      // Handle unrecognized command
      break;
  }
}

void moveForward()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going forward");
}

void moveBackward()
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going backward");
}

void stopMotors()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is stopped");
}

void turnRight()
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  Serial.println("The bot is going right");
}

void turnLeft()
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  Serial.println("The bot is going left");
}
