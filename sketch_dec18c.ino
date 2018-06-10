int sensor1 =A15;
int sensor2 =A14;
int sensor3 =A13;
int sensor4 =A12;
int sensor5 =A11;
int sensor6 =A10;
int sensor7 =A9;
int sensor8 =A8;
int sensor9 =A7;
int sensor10 =A0;

int s_1, s_2, s_3, s_4, s_5, s_6, s_7, s_8, s_9, s_10;
void setup(){
  Serial.begin(9600);
}

void loop()
{
s_1=analogRead(sensor1);
s_2=analogRead(sensor2);
s_3=analogRead(sensor3);
s_4=analogRead(sensor4);
s_5=analogRead(sensor5);
s_6=analogRead(sensor6);
s_7=analogRead(sensor7);
s_8=analogRead(sensor8);
s_9=analogRead(sensor9);
s_10=analogRead(sensor10);

 Serial.print("sensor 1 = " );
  Serial.println(s_1);

 Serial.print("sensor 2 = " );
  Serial.println(s_2);

 Serial.print("sensor 3 = " );
  Serial.println(s_3);

 Serial.print("sensor 4 = " );
  Serial.println(s_4);

 Serial.print("sensor 5 = " );
  Serial.println(s_5);

 Serial.print("sensor 6 = " );
  Serial.println(s_6);

 Serial.print("sensor 7 = " );
  Serial.println(s_7);

 Serial.print("sensor 8 = " );
  Serial.println(s_8);

 Serial.print("sensor 9 = " );
  Serial.println(s_9);

 Serial.print("sensor 10 = " );
  Serial.println(s_10);
  
 delay(3000);
}



