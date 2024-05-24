#include<Servo.h>




// servo pin
#define servopin 13

// sensor pin
#define sensor 21

// Motor pins
#define motor1_pwm 8
#define motor1_dir1 22
#define motor1_dir2 23

#define motor2_pwm 9
#define motor2_dir1 24
#define motor2_dir2 25

#define motor3_pwm 10
#define motor3_dir1 26
#define motor3_dir2 27
#define motor4_pwm 11
#define motor4_dir1 28
#define motor4_dir2 29
#define motor5_pwm 12
#define motor5_dir1 30
#define motor5_dir2 31

// Encoder pins
#define enc1_pin1 2
#define enc1_pin2 4
#define enc2_pin1 3
#define enc2_pin2 5

#define enc3_pin1 18
#define enc3_pin2 17
#define enc4_pin1 19
#define enc4_pin2 16
#define enc5_pin1 20
#define enc5_pin2 15

bool sensor_flag = true ;// true for go

// PID variables
float Ki1 = 0.0001,Kd1 = 1 , Kp1 = 5;
float Ki2 = 0.0001,Kd2 = 1 , Kp2 = 5;
float Ki3 = 0.0001,Kd3 = 1 , Kp3 = 5;
float Ki4 = 0.0001,Kd4 = 1 , Kp4 = 5;
float Ki5 = 0.0001,Kd5 = 1 , Kp5 = 5;

float error1, prevError1;
float error2, prevError2;
float error3, prevError3;
float error4, prevError4;
float error5, prevError5;

// Target angles
volatile float target1 = 0; 
volatile float target2 = 0;
volatile float target3 = 0;
volatile float target4 = 0;
volatile float target5 = 0; 

// Encoder variables
volatile int enc1Pos = 0;
volatile int enc2Pos = 0;
volatile int enc3Pos = 0;
volatile int enc4Pos = 0;
volatile int enc5Pos = 0;

// Modes
char mode= '0';

volatile int degree1 = 0;
volatile int degree2 = 0;
volatile int degree3 = 0;
volatile int degree4 = 0;
volatile int degree5 = 0;

Servo servo;

void setup() {
  Serial.begin (9600);
  

  // attach servopin
  servo.attach(servopin);
  
  // Set motor pins as outputs  
  pinMode(motor1_pwm, OUTPUT);
  pinMode(motor1_dir1, OUTPUT);
  pinMode(motor1_dir2, OUTPUT);
  pinMode(motor2_pwm, OUTPUT);
  pinMode(motor2_dir1, OUTPUT);
  pinMode(motor2_dir2, OUTPUT);
  
  pinMode(motor3_pwm, OUTPUT);
  pinMode(motor3_dir1, OUTPUT);
  pinMode(motor3_dir2, OUTPUT);
  pinMode(motor4_pwm, OUTPUT);
  pinMode(motor4_dir1, OUTPUT);
  pinMode(motor4_dir2, OUTPUT);
  pinMode(motor5_pwm, OUTPUT);
  pinMode(motor5_dir1, OUTPUT);
  pinMode(motor5_dir2, OUTPUT);
  
  // Set encoder pins as inputs
  pinMode(enc1_pin1, INPUT);
  pinMode(enc1_pin2, INPUT);
  pinMode(enc2_pin1, INPUT);
  pinMode(enc2_pin2, INPUT);
  
  pinMode(enc3_pin1, INPUT);
  pinMode(enc3_pin2, INPUT);
  pinMode(enc4_pin1, INPUT);
  pinMode(enc4_pin2, INPUT);
  pinMode(enc5_pin1, INPUT);
  pinMode(enc5_pin2, INPUT);
  
  // set sensor pin as input
   pinMode(sensor,INPUT);


       

   
  attachInterrupt(digitalPinToInterrupt(enc1_pin1), readEncoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(enc2_pin1), readEncoder2, RISING);
  
  attachInterrupt(digitalPinToInterrupt(enc3_pin1), readEncoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(enc4_pin1), readEncoder4, RISING);
  attachInterrupt(digitalPinToInterrupt(enc5_pin1), readEncoder5, RISING);
  
  attachInterrupt(digitalPinToInterrupt(sensor), sensor_ISR , RISING);  
}

void loop() {

   if (Serial.available()) {
    mode = Serial.read();
   
  }
  // convert number of pulses to angles 
  degree1 = map(enc1Pos,0,141,0,360);
  degree2 = map(enc2Pos,0,141,0,360);
  degree3 = map(enc3Pos,0,141,0,360);
  degree4 = map(enc4Pos,0,141,0,360);
  degree5 = map(enc5Pos,0,141,0,360);

   // Calculate errors
   error1 = target1 - degree1;
   error2 = target2 - degree2;
   error3 = target3 - degree3;
   error4 = target4 - degree4;
   error5 = target5 - degree5;
   
   // PID logic
   float motor1_output = pid(error1, prevError1, Kp1, Ki1, Kd1);
   float motor2_output = pid(error2, prevError2, Kp2, Ki2, Kd2);
   
   float motor3_output = pid(error3, prevError3, Kp3, Ki3, Kd3);
   float motor4_output = pid(error4, prevError4, Kp4, Ki4, Kd4);
   float motor5_output = pid(error5, prevError5, Kp5, Ki5, Kd5);
   
   // Set motor speeds and directions
   motorControl(motor1_pwm, motor1_dir1, motor1_dir2, motor1_output);
   motorControl(motor2_pwm, motor2_dir1, motor2_dir2, motor2_output);
   
   motorControl(motor3_pwm, motor3_dir1, motor3_dir2, motor3_output);
   motorControl(motor4_pwm, motor4_dir1, motor4_dir2, motor4_output);
   motorControl(motor5_pwm, motor5_dir1, motor5_dir2, motor5_output);
   

   // Store previous errors
   prevError1 = error1;
   prevError2 = error2;
   prevError3 = error3;
   prevError4 = error4;
   prevError5 = error5;

   Serial.println(degree1);
   Serial.println(degree2);
   Serial.println(degree3);
   Serial.println(degree4);
   Serial.println(degree5);
   

}
void readEncoder1() {
  if (digitalRead(enc1_pin2) == HIGH) {
      enc1Pos++;
    }
  else {
      enc1Pos--;
  }
}
void readEncoder2() {
  if (digitalRead(enc2_pin2) == HIGH) {
      enc2Pos++;
    }
  else {
      enc2Pos--;
  }
}

void readEncoder3() {
  if (digitalRead(enc3_pin2) == HIGH) {
      enc3Pos++;
    }
  else {
      enc3Pos--;
  }
}
void readEncoder4() {
  if (digitalRead(enc4_pin2) == HIGH) {
      enc4Pos++;
    }
  else {
      enc4Pos--;
  }
}
void readEncoder5() {
  if (digitalRead(enc5_pin2) == HIGH) {
      enc5Pos++;
    }
  else {
      enc5Pos--;
  }
}

void sensor_ISR()
{
  if(sensor_flag)
  {
    if (mode == '1'){
    
    
    
    target1 = -55;
    target2 = 0;
    target3 = 0;
    target4 = 0;
    target5 = 0;

    servo.write(35);
    
    sensor_flag = false ;
    }
    
    else if (mode == '2'){
    
    servo.write(90);
    
    target1 = 0;
    target2 = -55;
    target3 = 0;
    target4 = 0;
    target5 = 0;

    
    
    sensor_flag = false ;
    }

    else if (mode == '3'){

    servo.write(90);
    
    target1 = 0;
    target2 = 0;
    target3 = -55;
    target4 = 0;
    target5 =  0;
    
    sensor_flag = false ;
    }

    else if (mode == '4'){
    target1 = 0;
    target2 = 0;
    target3 = 0;
    target4 = -55;
    target5 = 0;
    
    sensor_flag = false ;
    }

    else if (mode == '5'){
    target1 = 0;
    target2 = -55;
    target3 = -55;
    target4 = 0;
    target5 = 0;
    
    sensor_flag = false ;
    }
     else {
    
    servo.write(60);
    
    target1 = -55;
    target2 = -55;
    target3 = -55;
    target4 = -55;
    target5 = 0;

    
    
    sensor_flag = false ;
    }
    
  }
  else
  {
    servo.write(0);
    
    target1 = 0;
    target2 = 0;
    target3 = 0;
    target4 = 0;
    target5 = 0;

    
    
    sensor_flag = true ;
  }
}

// Motor control function 
void motorControl(int pwm,int dir1, int dir2, float output) {
  if (output > 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW); 
  } 
  else if (output < 0){
    output = -output;
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }  
  else
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
  analogWrite(pwm,output);
}

// PID function
float pid(float error, float prevError, float Kp, float Ki, float Kd) {
  float P = Kp * error;
  float I = Ki * (error + prevError);
  float D = Kd * (error - prevError);
  float pid_output = P + I + D;
  return pid_output; 
}
