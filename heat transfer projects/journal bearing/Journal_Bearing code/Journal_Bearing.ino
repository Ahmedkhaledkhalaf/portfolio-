/*
  Smooth MAX6675 Thermocouple

  Reads a temperature from the MAX6675 thermocouple,
  smooth and displays it in the default Serial.

  https://github.com/YuriiSalimov/MAX6675_Thermocouple

  Created by Yurii Salimov, May, 2019.
  Released into the public domain.
*/
#include <Thermocouple.h>
#include <MAX6675_Thermocouple.h>
#include <SmoothThermocouple.h>

/*Encoder Pins*/
#define CH1_PIN 2
#define CH2_PIN 3

/*Thermocouple Pins*/
#define CS_PIN  4
#define SO_PIN  5
#define SCK_PIN 6

/*Motor Control*/
#define PWM_PIN 9
#define IN1_PIN 10
#define IN2_PIN 11

/************************************/
/**
  Thermocouple Initialization
  Smoothing factor of a temperature value.
*/
#define SMOOTHING_FACTOR 2
float T_max = 0;
float T_node = 23;
int T_mapped;

Thermocouple* thermocouple = NULL;
/************************************/

/**
 * Oil Specs:
 * Mu = 2.1 Pascal.Sec
 * K = 0.136 W/m.K
 */

 float Mu = 2.1;
 float K = 0.136;

/**
  Motor & Encoder Initialization
*/
byte Encoder0PinALast;
unsigned long int  Num_Of_Pulses;
boolean DIR = true;
double Speed=0;
double Time = 0;
float V_Linear;
float Omega;
/************************************/


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
 
  Encoder_Init();

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  analogWrite(PWM_PIN, 255);

  Thermocouple* originThermocouple = new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN);
  thermocouple = new SmoothThermocouple(originThermocouple, SMOOTHING_FACTOR);

  /* OR
    thermocouple = new SmoothThermocouple(
      new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN),
      SMOOTHING_FACTOR
    );
  */
}

// the loop function runs over and over again forever
void loop() {
  Thermo_Readings();
  //Serial.println("LOOOOOOOOOOOOOOOOOOOP");
  
  Omega = RPM_Read();
 
  Serial.println(T_mapped);
  Serial.println(Omega);
  
  V_Linear = Omega * ((2*3.14)/60) * 0.0125;
  
  delay(100);
  T_max = (T_node + ((Mu*(V_Linear*V_Linear))/8*K));
  
  delay(100);
 // T_mapped = map(Temp(), 20, 20.2, 0, 100);
  int Temp_mapped = (float)Temp()*100;
  delay(100);
  
  if(Temp_mapped >=  2305 && Temp_mapped <= 2310)
  {
    Serial.println("WARNNING !");
  }
  else if(Temp_mapped >= 2310)
  {
    analogWrite(PWM_PIN, 0);
    Serial.println("Motor Stopped !!"); 
  }
  
  
  // Reads temperature
  //Temp();
  //Serial.print("Pulse: ");
  //Serial.println(Num_Of_Pulses);
 // Num_Of_Pulses = 0;
  delay(100);

  /* calculating speed */
  
}


double Temp()
{
  const double celsius = thermocouple->readCelsius();
  const double kelvin = thermocouple->readKelvin();
  const double fahrenheit = thermocouple->readFahrenheit();

  // Output of information
/*  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(kelvin);
  Serial.print(" K, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
*/
  return (celsius);
}

void Thermo_Readings()
{
  const double celsius_1 = thermocouple->readCelsius();
  const double kelvin_1 = thermocouple->readKelvin();
  const double fahrenheit_1 = thermocouple->readFahrenheit();

  // Output of information
  Serial.print("Temperature: ");
  Serial.print(celsius_1);
  Serial.print(" C, ");
  Serial.print(kelvin_1);
  Serial.print(" K, ");
  Serial.print(fahrenheit_1);
  Serial.println(" F");
}

void Encoder_Init()
{
  Num_Of_Pulses = 0;
  DIR = true;
  pinMode(CH2_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), Wheel_Speed, CHANGE);
}

void Wheel_Speed()
{
  Num_Of_Pulses++;
  /*int Lstate = digitalRead(CH1_PIN);
  if((Encoder0PinALast == LOW) && (Lstate == HIGH))
  {
    int Val = digitalRead(CH2_PIN);
    if(Val == LOW && DIR)
    {
      DIR = false;
    }
    else if(Val == HIGH && !DIR)
    {
      DIR = true;
    }
  }
  Encoder0PinALast = Lstate;

  if(!DIR) Num_Of_Pulses++;
  else Num_Of_Pulses--;*/
}

float RPM_Read()
{
  if (millis() >= Time+2000)
  {
     Speed=(float) ( (Num_Of_Pulses/979) / 2 )*60; // pulses / 950 = revs , over 2 second >> speed unit rev/s
     Num_Of_Pulses=0;
     Time=millis();
     Serial.print(Speed);
     Serial.println(" RPM");
  }
  return Speed;
}
