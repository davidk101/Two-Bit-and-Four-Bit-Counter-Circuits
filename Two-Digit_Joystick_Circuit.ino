int W_PIN, X_PIN;     //USE THESE VARIABLES FOR W and X PINS
int Y_PIN, Z_PIN;     //USE THESE VARIABLES FOR Y and Z PINS  

int W_PIN_2, X_PIN_2;     
int Y_PIN_2, Z_PIN_2;

byte onesDigit, tensDigit;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int newSensorValue = 0;

void setup()
{

  W_PIN = 5;
  X_PIN = 4;
  Y_PIN = 3;
  Z_PIN = 2;
  
  W_PIN_2 = A2;
  X_PIN_2 = A3;
  Y_PIN_2 = A4;
  Z_PIN_2 = A5;
  
  pinMode(W_PIN,OUTPUT);
  pinMode(X_PIN,OUTPUT);
  pinMode(Y_PIN,OUTPUT);
  pinMode(Z_PIN,OUTPUT);
  
  pinMode(W_PIN_2,OUTPUT);
  pinMode(X_PIN_2,OUTPUT);
  pinMode(Y_PIN_2,OUTPUT);
  pinMode(Z_PIN_2,OUTPUT);
  
  pinMode(A0, INPUT);
  
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
  newSensorValue = sensorValue*(99.0/1023.0);
  
  Serial.print("Value between 0-99: ");
  Serial.println(newSensorValue);
  
  onesDigit = byte(newSensorValue%10);
  tensDigit = byte(newSensorValue/10);    
    
  digitalWrite(W_PIN,bitRead(onesDigit, 3));
  digitalWrite(X_PIN,bitRead(onesDigit, 2));
  digitalWrite(Y_PIN,bitRead(onesDigit, 1));
  digitalWrite(Z_PIN,bitRead(onesDigit, 0));
  
  digitalWrite(W_PIN_2,bitRead(tensDigit, 3));
  digitalWrite(X_PIN_2,bitRead(tensDigit, 2));
  digitalWrite(Y_PIN_2,bitRead(tensDigit, 1));
  digitalWrite(Z_PIN_2,bitRead(tensDigit, 0));
  
}
