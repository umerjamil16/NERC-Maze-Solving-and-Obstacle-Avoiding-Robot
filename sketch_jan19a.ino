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

int right_p=11;
int right_n=10;
int right_pwm=8;
int left_p=13;
int left_n=12;
int left_pwm=9;

volatile int encoderRight=0;
volatile int encoderLeft=0;

int s_1, s_2, s_3, s_4, s_5, s_6, s_7, s_8, s_9, s_10,r_e,l_e;


void setup(){

  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT); 
  
  pinMode(20,INPUT);
  pinMode(21,INPUT); 
  
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

    
  pinMode(19,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);  
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



}

void forwardMove(int,int);

void loop(){
  forwardMove(125,135);
while(s_9<450){
  forwardMove(127,140);
  s_9=analogRead(sensor9);

}

}

void forwardMove(int R, int L){
  digitalWrite(right_p,0);
 digitalWrite(right_n, 1);

digitalWrite(left_p, 0);
digitalWrite(left_n, 1);

analogWrite(right_pwm, R);
analogWrite(left_pwm, L);

}
