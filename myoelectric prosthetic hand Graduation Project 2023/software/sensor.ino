
#define sensor_pin     A0
#define interrupt_pin  13
#define readings       5 
int Read = 0;
long long int sum  = 0;
float avg = 0;
void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  pinMode(interrupt_pin,OUTPUT);

}

void loop() {
  for(int i=0;i<readings;i++)
  {
    Read = analogRead(sensor_pin);
    sum = sum + Read ;
  }
  avg = sum/readings;
  Serial.println(avg);
  if(avg>650)
  {
    digitalWrite(interrupt_pin,HIGH);
    delay(1000);
    digitalWrite(interrupt_pin,LOW);
  }
  
  Read = 0;
  sum  = 0;
  avg  = 0;
}
