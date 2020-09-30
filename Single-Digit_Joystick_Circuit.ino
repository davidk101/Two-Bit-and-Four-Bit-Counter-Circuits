int W_PIN, X_PIN;     //USE THESE VARIABLES FOR W and X PINS
int Y_PIN, Z_PIN;     //USE THESE VARIABLES FOR Y and Z PINS  

const int analogInPin = 1;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 30;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int newSensorValue = 0;

void setup()
{

  W_PIN = 12;
  X_PIN = 35;
  Y_PIN = 18;
  Z_PIN = 36;
  
  pinMode(W_PIN,OUTPUT);
  pinMode(X_PIN,OUTPUT);
  pinMode(Y_PIN,OUTPUT);
  pinMode(Z_PIN,OUTPUT);
  
  pinMode(A0, INPUT);
  
    
  // DO NOT EDIT THE CODE BELOW THIS
  Serial.begin(9600); //Initilize the serial monitor
}

void loop()
{
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // converting the number to a 0-9 value
  newSensorValue = sensorValue*(9.0/1023.0);
  
  Serial.print("Value between 0-9: ");
  Serial.println(newSensorValue);
  
  digitalWrite(W_PIN,bitRead(newSensorValue, 3));
  digitalWrite(X_PIN,bitRead(newSensorValue, 2));
  digitalWrite(Y_PIN,bitRead(newSensorValue, 1));
  digitalWrite(Z_PIN,bitRead(newSensorValue, 0));
  
  
}
