#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 



// clock wise 90 degrees 150
// anti_clock 90 degrees 143
// clock wise 45 degrees 75
// anti_clock 45 degrees 71


volatile int fr = A7;
volatile int fl = A6;
volatile int br = A10;
volatile int bl = A11;
volatile int lf = A5;
volatile int lb = A4;
volatile int rf = A3;
volatile int rb = A2;
volatile int flg =A8;
volatile int blg= A9;
volatile int c1 = A13;
volatile int c2 = A14;
volatile int c3 = A15;



volatile int vfr=0;
volatile int vfl=0;
volatile int vbr=0;
volatile int vbl=0;
volatile int vlf=0;
volatile int vlb=0;
volatile int vrf=0;
volatile int vrb=0; 
volatile int vflg=0;
volatile int vblg=0;
volatile int vc1=0;
volatile int vc2=0;
volatile int vc3=0;


int m_forward=8;
int m_backward=9;
int m_control=10;


int ta=0;
int tb=0;
int tc=0;

int FR=0;
int FL=0;
int FR_store[2];
int FL_store[2];
void FR_pure();
void FL_pure();

int BR=0;
int BL=0;
int BR_store[2];
int BL_store[2];
void BR_pure();
void BL_pure();


int RF=0;
int RB=0;
int RB_store[2];
int RF_store[2];
void RB_pure();
void RF_pure();


int LB=0;
int LF=0;
int LF_store[2];
int LB_store[2];
void LF_pure();
void LB_pure();

int FLG=0;
int BLG=0;
int FLG_store[2];
int BLG_store[2];
void FLG_pure();
void BLG_pure();

int C1=0;
int C2=0;
int C3=0;

int C1_store[2];
int C2_store[2];
int C3_store[2];

void C1_pure();
void C2_pure();
void C3_pure();

int pwmr=4;
int forwardr=2;
int reverser=3;

int pwml=13;
int forwardl=12;
int reversel=11;

int r=0;
int l=0;


volatile int encoderRight=0;
volatile int encoderLeft=0;


void pulse_count_E(); 

int mf=5;
int mb=6;
int pwm=7;
volatile int encoderM=0;


void clockk(int);
void pulse_count_R();
void pulse_count_L();
void anti_clock_s_f(int);
void clock_s_f(int);
void anti_clock_s_b(int);
void anti_clock_s_f_b(int);
void clock_s_b(int);
void cal_forward(int,int,int);
void cal_backward(int,int,int);
void forward_move(int,int);
void backward_move(int,int);
void reverse_break(int);
void forward_break(int);
void allignment_forward();
void allignment_forward_L();
void allignment_backward();
void allignment_forward_2();
void allignment_forwardxx();
void allignment_forward_alley();
void allignment_forward_line();
void side_allignment();
void side_allignment2();
void side_allignment_L2();
void back_allignment();
void front_allignment();
void front_adjust();
void stopp();
void final_select();
void mech_run();
void a_return();
void b_return();
void c_return();


void megaR();
void megaL();



void setup()
{
  attachInterrupt(2,pulse_count_R,FALLING);
  attachInterrupt(3,pulse_count_L,FALLING);
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
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  attachInterrupt(4 ,pulse_count_E,FALLING);  
  
    
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

  
  //analogReference(INTERNAL1V1);
}



void loop()
{
   
  
 myservo.write(290);


  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  




  while(1)
  {
   cal_forward(1,130,130);
   cs_check();
   if(ta==100 || tb==100 || tc==100)
   break;
  }
  ta=tb=tc=0;
 // delay(100);
  final_select();
  final_select();
  final_select();
    











 if(ta==100)

  {
  
  //////////////////////////////////////
  stopp();
  delay(100);
  cal_backward(150,30,30); //30 30
  stopp();
  forward_break(120); // 120
  stopp();
  delay(300);
  //side_allignment2();
//  megaR();
  
  stopp();
  //delay(00);
  anti_clock(90);
  stopp();
  delay(100);
  cal_forward(140,100,100);
  stopp();
  delay(100);
  reverse_break(120);
  //side_allignment_L2();
  megaL();
  stopp();
  delay(100);
 /////////////////////////////////////////
   
  while(1)
  {
    
   RB_pure();
    cal_forward(1,50,50);
    if(RB>140)
    break;
    FLG_pure();
    if(FLG>200)
    break;
  }
  
stopp();  

   while(1)
 {
 //  RB_pure();
 

  //cal_forward(1,0,0);
  allignment_forward();
 
 FLG_pure(); 
  if(FLG>240)
  break;
 }
 
 stopp();
 reverse_break(200);
 stopp();
 delay(150);
 clockk(60);
stopp();

delay(100);
cal_forward(50,100,100);
reverse_break(100);
stopp();
delay(100);
//side_allignment_L;
megaL();
stopp();
//delay(200);




cal_forward(100,20,20);
while(1)
{
  FLG_pure();
  if(FLG>375)
  break;
  cal_forward(1,120,120);
}

 reverse_break(110); //110
 stopp();
 delay(100);
 
// while(1);
 
  encoderLeft=0;
 encoderRight=0;
 clockk(60);
 stopp();
 delay(200);
// side_allignment_L();
megaL();
 stopp();
 
 delay(200);
// while(1);
 
 
 
 while(1)
  {
      allignment_backward();
       LF_pure();
       LB_pure();
    if(LB<100 )//&& LF<100)
   {
       break;
   }
    
   
  }
 cal_backward(320,100,100);
 forward_break(180); //110
 stopp();
 delay(200);

//side_allignment();
stopp();
delay(200);
anti_clock(105);
stopp();
delay(200);
cal_forward(170,100,100);
reverse_break(100);
stopp();
delay(200);
//side_allignment_L();
megaL();
stopp();

delay(200);


  while(1)
  {
      cal_forward(1,130,130);
//allignment_forward();
         FL_pure();
    if(FL>110)
   {
       break;
   }
    
   
  }
  
  reverse_break(180);
  stopp();
  delay(200);
  //cal_backward(50,100,100);
  //forward_break(50);
  
  clockk(75);
  stopp();
//  while(1);

delay(200);
cal_forward(100,100,100);
//reverse_break(90);  //break removed
//stopp();
//delay(200);
//  side_allignment_L();
// stopp();

//while(1);



//while(1);
  
//while(1);


//side_allignment_L();
//stopp();
//delay(100);
FLG_pure();

  while(1) // balling alley
  {
    FLG_pure();
    if(FLG>520)
    break;
   
   allignment_forward_alley();
   //cal_forward(1,80,80);
  }
 
 reverse_break(100);


 stopp();
 delay(100);
 // side_allignment_L2();
// megaL();
 //stopp();
 //delay(100);
 //side_allignment2();
 //stopp();
 //delay(100);
 
 
 
 
 
 
//while(1);

mech_run();
// BLG_pure();
/////check point  //////////////////////////////////////////////

while(1)
{
  
  BLG_pure();
  
     cal_backward(1,90,90);
  if(BLG >350)
 break;
  
}

forward_break(180);
stopp();
delay(200);



clockk(210);
stopp();
delay(200);


//cal_forward(50,90,90);
//stopp();
//delay(100);
//side_allignment2();
//stopp();
//delay(100);



//comming out
while(1)
{
  FL_pure();
 cal_forward(1,100,100);
  if(FL>130)
  break;
   
}
reverse_break(160);
stopp();
delay(200);


clockk(115);
stopp();
delay(200);

//side_allignment_L();
//stopp();
//delay(200);
cal_forward(30,100,100);
reverse_break(130);
stopp();
delay(100);
//side_allignment_L();
megaL();
stopp();
delay(100);
//while(1);
c_return();

  
}
  
  


  
 
  
  
  
  
  
  
//  while(1);
  
  
  
  
  
  
  
  
  
else if(tb==100)
  {
   
    cal_forward(300,100,100);
 while(1)
{
  LF_pure();
  LB_pure();
  allignment_forward_2b();
  if(LF>140 && LB>140)
  break;
   
}
  
  
  
 while(1)
{
  LF_pure();
 
 allignment_forward_2b();
  LB_pure();
  if(LB<110 && LF<110)
  break;
}

reverse_break(260);
stopp();
delay(200);
cal_backward(50,100,100);
forward_break(50);
//side_allignment();
megaR();
stopp();
delay(200);

anti_clock(90);
stopp();
delay(200);

//while(1);

while(1)
{
  FLG_pure();
  cal_forward(1,20,20);
  if(FLG>250)
  break;
}
reverse_break(30);

while(1)
{
  FLG_pure();
  cal_forward(1,30,30);
  if(FLG>450)
  break;
}
reverse_break(200);

//front_adjust_4b();
//reverse_break(200);
//stopp();
//delay(100);
//while(1);

//front_allignment();
///stopp();
//delay(100);
stopp();
delay(200);

//while(1);
clockk(190);
stopp();
delay(100);
//side_allignment_L();
megaL();
stopp();
delay(200);


 //////////////
 
/////////////////////////////////////////////////////////////////////// LL  
 while(1)
  {
      allignment_backward();
       LF_pure();
       LB_pure();
    if(LB<100 )//&& LF<100)
   {
       break;
   }
    
   
  }
 cal_backward(260,100,100);
 forward_break(160); //230
 stopp();
 delay(200);
 

//side_allignment();
stopp();
delay(200);
anti_clock(95);
stopp();
delay(200);
cal_forward(170,100,100);
reverse_break(100);
stopp();
delay(200);
//side_allignment_L();
megaL();
stopp();

delay(200);


  while(1)
  {
      cal_forward(1,130,130);
//allignment_forward();
         FL_pure();
    if(FL>110)
   {
       break;
   }
    
   
  }
  
  reverse_break(180);
  stopp();
  delay(200);
  //cal_backward(50,100,100);
  //forward_break(50);
  
  clockk(85);
  stopp();
//  while(1);

delay(200);
cal_forward(50,100,100);
//reverse_break(90);
//stopp();
//delay(200);
//  side_allignment_L();
 stopp();

//while(1);



//while(1);
  
//while(1);


//side_allignment_L();
//stopp();
//delay(100);
FLG_pure();

  while(1) // balling alley
  {
    FLG_pure();
    if(FLG>520)
    break;
   
   allignment_forward_alley();
   //cal_forward(1,80,80);
  }
 
 reverse_break(100);


 stopp();
 delay(100);
 // side_allignment_L2();
 stopp();
 //delay(100);
 //side_allignment2();
 //stopp();
 //delay(100);
 
 
 
 
 
 
//while(1);

mech_run();
// BLG_pure();
/////check point  //////////////////////////////////////////////

while(1)
{
  
  BLG_pure();
  
     cal_backward(1,90,90);
  if(BLG >350)
 break;
  
}

forward_break(180);
stopp();
delay(200);

//while(1);

clockk(240);
stopp();
delay(200);


//cal_forward(50,90,90);
//stopp();
//delay(100);
//side_allignment2();
//stopp();
//delay(100);



//comming out
while(1)
{
  FL_pure();
 cal_forward(1,100,100);
  if(FL>130)
  break;
   
}
reverse_break(160);
stopp();
delay(200);


clockk(100);
stopp();
delay(200);

//side_allignment_L();
//stopp();
//delay(200);
cal_forward(30,100,100);
reverse_break(130);
stopp();
delay(100);
//side_allignment_L();
megaL();
stopp();
delay(100);

a_return();
  
   
  }
  
  
  
  
   
  
  
  
  
  
  





  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
else  if(tc==100)
  {
  
   
      while(1)
  {
      FLG_pure();
     allignment_forward();
     if(FLG>140)
     break;
  }
 reverse_break(20);




      while(1)
  {
      FLG_pure();
     allignment_forward();
     if(FLG>200)
     break;
  }
 reverse_break(20);


  while(1)
  {
      FLG_pure();
     allignment_forward();
     if(FLG>310)
     break;
  }

 reverse_break(210);
stopp();

front_adjust();
stopp();
delay(200);


 
//side_allignment();
megaR();
stopp();
 delay(100);


 
  //////////////////////////////////////////////////////////////////////////////// 1st path with allignment
  clockk(100);
  stopp();


delay(100);
//side_allignment2();
//stopp();
//delay(150);
cal_backward(100,20,40);
while(1)
{
  LB_pure();
  if(LB>200)
  break;
cal_backward(1,20,40);
}
anti_clock(5);


 while(1)
  {
      allignment_backward_c_start();
       LF_pure();
       LB_pure();
    if(LB<100)// && LF<100)
   {
       break;
   }
    
   
  }
 cal_backward(200,80,100);
 forward_break(240); //110
 stopp();
 delay(200);
 


anti_clock(75);
stopp();
delay(200);
cal_forward(130,80,100);
reverse_break(100);
stopp();
//delay(200);
//side_allignment_L();
megaL();
stopp();

delay(100);


  while(1)
  {
      cal_forward(1,110,130);
//allignment_forward();
         FL_pure();
    if(FL>110)
   {
       break;
   }
    
   
  }
  
  reverse_break(140);
  stopp();
  delay(200);
  //cal_backward(50,100,100);
  //forward_break(50);
  
  clockk(75);
  stopp();


delay(150);
//cal_forward(100,100,100);
//reverse_break(90);
//stopp();
//delay(200);
//megaL();
//  side_allignment_L();


  while(1) // balling alley
  {
    FLG_pure();
    if(FLG>470)
    break;
   
   allignment_forward_alley();
   //cal_forward(1,80,80);
  }
 
 reverse_break(100);


 stopp();
 delay(100);
// side_allignment2();
megaR();
stopp();






mech_run();

megaL();
stopp();
delay(100);
while(1)
{
  
  BLG_pure();
  
     cal_backward(1,70,90);
  if(BLG >350)
 break;
  
}

forward_break(185);
stopp();
delay(200);

//while(1);

clockk(200);
stopp();
delay(200);


//cal_forward(50,90,90);
//stopp();
//delay(100);
//side_allignment2();
//stopp();
//delay(100);



//comming out
while(1)
{
  FL_pure();
 cal_forward(1,80,100);
  if(FL>125)
  break;
   
}
reverse_break(180);
stopp();
delay(200);


clockk(80);
stopp();
delay(200);

//side_allignment_L();
//stopp();
//delay(200);
//cal_forward(30,100,100);
//reverse_break(120);
//stopp();
//delay(100);
//side_allignment_L();
megaL();
stopp();
delay(100);


a_return_c();    
   

  
} 
 
}


///////////////////////////////////////////////////////// 
 void c_return()
 {
   
     encoderLeft=0;
   encoderRight=0;
  cal_forward(200,0,0);

 

while(1)
{
       allignment_forward_3();
       FLG_pure();
       if(FLG>270)
   {
       break;
   }

}

reverse_break(300);
//side_allignment();
stopp();
delay(100);
clockk(110);
stopp();

//delay(100);
//front_allignment();
stopp();
delay(200);
//side_allignment_L();
megaL();
stopp();

delay(100);

//while(1);
//front_allignment();

while(1)
{
  allignment_backward_c();
  RF_pure();
  RB_pure();
  //if(RF<90 && RB<90)
//  break;
}


stopp();
delay(200);
//front_allignment();


while(1);
cal_backward(200,0,30);
stopp();
delay(100);
//side_allignment_L();
megaL();
stopp();
delay(100);
//anti_clock(170);
//stopp();
//delay(200);
//side_allignment2();
//////////////

while(1)
{
  allignment_backward();
  RF_pure();
  RB_pure();
  //if(RF<90 && RB<90)
//  break;
}

//reverse_break(300);

}


////////////////////////////////////
 void b_return()
 {
    while(1)
{
  LB_pure();
 cal_forward(1,80,120);
  if(LB<100)
  break;
}

while(1)
{
  LB_pure();
 cal_forward(1,80,120);
  if(LB>140) // LF
  break;
}
reverse_break(100);
stopp();

delay(200);

clockk(120);
stopp();
delay(200);

front_allignment();
stopp();
delay(200);

//while(1);
//cal_backward(200,150,150);


while(1)
{
  cal_backward(1,0,20);
  FLG_pure();
  
  if(FLG<200)
  break;
} 



//stopp();
//delay(200);
//side_allignment_L2();
//stopp();
//delay(200);
///////////////////////////////////
while(1)
{
  cal_backward(1,0,40);
  BLG_pure();
  
  if(BLG>350)
  break;
} 

  forward_break(230);
  stopp();
 delay(200);

stopp();
delay(200);
anti_clock(80);
stopp();
delay(200);
side_allignment_L2();
stopp();
///////////////////////
 while(1)
 {
   LB_pure();
   LF_pure();
 allignment_backward_2();
// if(LF<100 && LB<100)
// break;
 
 }
 forward_break(300);
//forward_break(100);
 stopp();



 }
 
/////////////////////////////////////////////////////// 
 
  void a_return()

{   
    
    while(1)
{
  LB_pure();
 cal_forward(1,60,60);
  if(LB<100)
  break;
}



cal_forward(100,100,100);


//delay(100);
reverse_break(140);
stopp();
delay(100);
///side_allignment2();                    // new
//stopp();
//delay(100);


megaR();
stopp();
delay(100);

clockk(130);
stopp();
delay(100);



//front_allignment();
//stopp();
//delay(100);


cal_backward(100,100,100);
while(1)
{
  FLG_pure();
  if(FLG<330)
  break;
  cal_backward(1,80,80);
  
}

forward_break(160);
stopp();
delay(100);
anti_clock(75);

stopp();
delay(200);
megaL();
stopp();
delay(100);
//side_allignment_L2();


//stopp();
//delay(100);
//reverse_break(260);
//stopp();
//delay(300);

//delay(100);
//stopp();
//LF_pure();
                             //between two tri
                             
/*while(1)
{
cal_backward(1,40,40);
if(LF<100)
break;
LF_pure();
}
*/
//side_allignment();
//stopp();


BLG_pure();
while(1)
{
cal_backward(1,40,40);
if(BLG>220)//120
break;
BLG_pure();
}

//forward_break(120);
//stopp();
//delay(200);
/////////////


clockk(130);                         ////////////////////////60
stopp();
delay(50);


//cal_backward(200,100,100);
//forward_break(100);
//stopp();
//side_allignment2();
//stopp();
//delay(100);



 while(1)
{
cal_backward(1,40,15);
//if(RF<90)
//break;
//RF_pure();
}
/*
anti_clock(90);
cal_backward(200,40,40);
forward_break(250);
*/

}


  void a_return_c()

{   
    
    while(1)
{
  LB_pure();
 cal_forward(1,20,40);
  if(LB<110)
  break;
}
cal_forward(180,20,40);



//delay(100);
reverse_break(200);
stopp();
delay(200);
///side_allignment2();                    // new
//stopp();
//delay(100);


clockk(80);  // 90
stopp();
delay(100);


cal_backward(150,20,40);
stopp();
megaL();
stopp();


BLG_pure();
while(1)
{
cal_backward(1,20,40);
if(BLG>220)//120
break;
BLG_pure();
}

//forward_break(120);
//stopp();
//delay(200);
/////////////


clockk(135);                         ////////////////////////60
stopp();
delay(100);


//cal_backward(200,100,100);
//forward_break(100);
//stopp();
//side_allignment2();
//stopp();
//delay(100);



 while(1)
{
cal_backward(1,20,0);
//if(RF<90)
//break;
//RF_pure();
}

}


///////////////////////////////////////////  
 void mech_run()
  {
    
  myservo.write(90); 
  delay(200);
     digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 analogWrite(7,0);
  
  encoderM=0;
  while(encoderM<=200)
  {
    Serial.println(encoderM);
  }
 encoderM=0;
   digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  analogWrite(7,0);
  delay(20);
     digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  analogWrite(7,255);
  
  
 // while(1);
  delay(700);
 // while(1);
    digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 analogWrite(7,0);
    encoderM=0;
 delay(200);
   digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  analogWrite(7,255);
  
   myservo.write(290); 
 
  
  }
  
  
  
  
  //////////////////////
  void final_select()
  {
    
    C1_pure();
    C2_pure();
    C3_pure();
    
    if(C1<C2 && C1<C3)
    {
      ta=100;
      tb=0;
      tc=0;
    }
    
    if(C2<C1 && C2<C3)
    {
      ta=0;
      tb=100;
      tc=0;
    }
    
    if(C3<C2 && C3<C1)
    {
      ta=0;
      tb=0;
      tc=100;
    }
    
    
  }
  
  

/////////////////////////////////////
void cs_check()
{
 
  C1_pure();
  C2_pure();
  C3_pure();
  
  
  if(C1>150&& C1>100 && C2>100 && C2>150 && C3>100 && C3>150)
  {
    ta=100;
    tb=100;
    tc=100;
  }
  
  
}



void front_adjust()
{
  delay(50);
  FR_pure();
  FL_pure();
  
  if(FR<100 || FL<100)
  {
    while(1)
    {
       FR_pure();
  FL_pure();
    forward_move(140,150);
    
    if(FR>130 || FL>130)
    {
       reverse_break(130);
    break;
    }
    }
    stopp();
  }
  
 
//  delay(30);
       FR_pure();
  FL_pure();
  
  
  if(FR>160 || FL>160)
  {
    while(1)
    {
       FR_pure();
  FL_pure();
    backward_move(140,150);

    if(FR<130 || FL<130)
    {
      forward_break(130);
    break;
    }
    }
    
  }
 



 stopp(); 
 delay(50);
}


////////////////////////////////

void front_adjust_4b()
{
  
  FR_pure();
  FL_pure();
  
  if(FR<110 || FL<110)
  {
    while(1)
    {
       FR_pure();
  FL_pure();
    forward_move(160,160);
    
    if(FR>230 || FL>230)
    {
       reverse_break(220);
    break;
    }
    }
    stopp();
  }
 
 
 
//  delay(30);
       FR_pure();
  FL_pure();
  
  
  if(FR>300 || FL>300)
  {
    while(1)
    {
       FR_pure();
  FL_pure();
    backward_move(160,160);

    if(FR<270 || FL<270)
    {
      forward_break(230);
    break;
    }
    }
    
  }
 

 //stopp(); 
// delay(50);
}
//////////////////////////////

void allignment_forward_line()
{
    RF_pure();
   RB_pure();
   
   if(RF<155 )//&& RB>RF)
   {
     forward_move(150,50);
   }


   if(RF>155) //&& RB<RF)
   {
     forward_move(50,150);
   }



  
}

////////////////////////////////////////////







////////////////////////////////////////
void allignment_forwardxx()
{
   RF_pure();
  RB_pure();
  
 float L,R;
 
if(RF<150)
 {
   L=225-1*(RF);
   R=20+1.5*(RF);
   forward_move(R,L);
   ///////
 }
   RF_pure();
  RB_pure();
 if(RF>160)
 {
   L=220-(RF)*0.2;
   R=255-(RF)*0.5;
   forward_move(R,L); 
 }
   RF_pure();
  RB_pure();
 
 if(RF>=150 && RF<=160)
 {
 
 L=(RF-155)*0.6 +20;
 R=(RB-155)*0.6 +20;
 forward_move(R,L);
 
 }
 
  
}
//////////////////////////////////
void allignment_forward_alley()
{
    LF_pure();
   LB_pure();
   
 if(LF<LB)// && LF<155)
 {
   forward_move(50,200);
 }
 
 
  if(LF>LB)//&& LF>155)
 {
   forward_move(200,50);
 }

 
}

//////////////////////////////////////
void allignment_forward_L()
{
   LF_pure();
   LB_pure();
   
 if(LF<LB && LF>120)
 {
   forward_move(50,100);
 }
 
 
  if(LF>LB && LF>120)
 {
   forward_move(100,50);
 }
 
  
}



//////////////////////////////////////////////////////////

void allignment_forward()
{
   RF_pure();
   RB_pure();
   
  if(RF>150 && RF < 170)// && RB<130)  //right jerk
  {  
     
     forward_move(0,120);
  }  
  
  if(RB>150 && RB <170)  //left jerk
  {
    forward_move(100,20);
  }
   RF_pure();
  RB_pure();
 
 if(RB>RF && RB>170)
 {
   forward_move(255,20);  // opposite
 }

 if(RF>RB && RF >170)
 {
   forward_move(20,255);
 }
 
 RF_pure();
  RB_pure();

 if(RB>RF && RB<165)
 {
   forward_move(255,20);  // opposite
 } 
 if(RB<RF && RF<165)
 {
   forward_move(255,20);  // opposite
 } 
 
 
 
else// if(RF<190 && RF >130 && RB<190 && RB>130 ) // straight move in band
 {

   forward_move(0,20);
   l=0;
   r=0;
 }

 
}



void allignment_forward_2()
{
   RF_pure();
   RB_pure();
   
 if(RF>RB && RF>165)
 {
   forward_move(0,50);
 }
 
 
  if(RF<RB && RF<165)
 {
   forward_move(50,0);
 }
 
  
}


void allignment_forward_2b()
{
   RF_pure();
   RB_pure();
   
 if(RF>RB && RF>165)
 {
   forward_move(50,150);
 }
 
 
  if(RF<RB && RF<165)
 {
   forward_move(150,50);
 }
 
  
}




void allignment_forward_3()
{
   RF_pure();
   RB_pure();
   
 if(RF>RB )//&& RF>155)
 {
   forward_move(0,50);
 }
 
 
  if(RF<RB)// && RF<155)
 {
   forward_move(50,0);
 }
 
  
}



/////////////////////////////////
void allignment_backward_2()
{
   LF_pure();
   LB_pure();
   
   if(LB>LF)// && LB>140)
   {
     backward_move(50,0);
   }


   if(LB<LF)// && LF>140)
   {
     backward_move(0,50);
   }
}
//////////////////////////////

void allignment_backward_c_start()
{
   LF_pure();
   LB_pure();
   
   if(LB>LF)// && LB>140)
   {
     backward_move(70,0);
   }


   if(LB<LF)// && LF>140)
   {
     backward_move(0,70);
   }
}


void allignment_backward()
{
   LF_pure();
   LB_pure();
   
   if(LB>LF)// && LB>140)
   {
     backward_move(170,70);
   }


   if(LB<LF)// && LF>140)
   {
     backward_move(70,170);
   }
}




/////////////////////////////
void allignment_backward_c()
{
   LF_pure();
   LB_pure();
   
   if(LB>LF)// && LB>140)
   {
     backward_move(70,0);
   }


   if(LB<LF)// && LF>140)
   {
     backward_move(0,70);
   }
}



void back_allignment()
{
delay(50);
  analogWrite(pwmr,120);
  analogWrite(pwml,120);
//  long unsigned int pulse=millis();
 // while(millis()<=(500+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   BL_pure();
   BR_pure();

    if(BR>(BL))
    {
      while(1)
      {
        if(BL-10>BR-20)
        break;
        
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           BR_pure();
   BL_pure();
      }
      
    }
   else if(BL>BR)
    {
      while(1)
      {
      if(BR>BL)
      break;
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           BR_pure();
   BL_pure();
      }
    }
    
    
    
  }
  
  delay(50);
}




/////////////////////////////////////////////

void front_allignment()
{
delay(50);
  analogWrite(pwmr,110);
  analogWrite(pwml,110);

{
   FL_pure();
   FR_pure();

    if(FR>(FL))
    {
      while(1)
      {
        if(FL>FR-10)
        break;
        
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           FR_pure();
   FL_pure();
      }
      
    }
    
   else if(FL>FR)
    {
      while(1)
      {
      if(FR+70>FL)
      break;
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           FR_pure();
  FL_pure();
      }
    }
    
    
    
  }
  
  delay(50);
}


/////////////////////////////////////////////

void side_allignment_L()
{
  analogWrite(pwmr,80);
  analogWrite(pwml,80);
long unsigned int pulseee=millis();
  while(millis()<=(300+pulseee))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
    LB_pure();
   LF_pure();
    if(LB>(LF))//-20))
    {
        analogWrite(forwardr,255);
        analogWrite(reverser,0);
        analogWrite(forwardl,0);
        analogWrite(reversel,255);
      
    }
    if(LB<(LF))//-20))
    {
        analogWrite(forwardr,0);
        analogWrite(reverser,255);
        analogWrite(forwardl,255);
        analogWrite(reversel,0);
      
    }    
  }
  
}


/////////////////////////////


void megaR()
{
  
   delay(50);
  analogWrite(pwmr,100);
  analogWrite(pwml,100);
//  long unsigned int pulse=millis();
 // while(millis()<=(500+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   RB_pure();
   RF_pure();

    if(RB>(RF))
    {
      while(1)
      {
        if((RF+10)>RB)
        break;
        
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           RB_pure();
   RF_pure();
      }
      
    }
   else //if(RF>RB)
    {
      while(1)
      {
      if((RB+20)>RF)
      break;
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           RB_pure();
   RF_pure();
      }
    }
    
    
    
  }
  
  delay(50);

  
 //////////////////////////
 analogWrite(pwmr,120);
  analogWrite(pwml,120);
  long unsigned int pulse=millis();
  while(millis()<=(300+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   RB_pure();
   RF_pure();

    if(RB>(RF-5))
    {
        analogWrite(forwardr,0);
        analogWrite(reverser,255);
        analogWrite(forwardl,255);
        analogWrite(reversel,0);
      
    }
    if(RB<(RF-5))
    {
        analogWrite(forwardr,255);
        analogWrite(reverser,0);
        analogWrite(forwardl,0);
        analogWrite(reversel,255);
    }
    
    
    
  }
  
  
}

/////////////////////////////////

void megaL()
{
  
  delay(50);
  analogWrite(pwmr,100);
  analogWrite(pwml,100);
//  long unsigned int pulse=millis();
 // while(millis()<=(500+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   LB_pure();
   LF_pure();

    if(LB>(LF))
    {
      while(1)
      {
        if(LF+20>LB)
        break;
        
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           LB_pure();
   LF_pure();
      }
      
    }
   else //if(RF>RB)
    {
      while(1)
      {
      if((LB+20)>LF)
      break;
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           LB_pure();
   LF_pure();
      }
    }
    
    
    
  }
  
  delay(50);

  
  
  
  ////////
    analogWrite(pwmr,120);
  analogWrite(pwml,120);
long unsigned int pulseee=millis();
  while(millis()<=(350+pulseee))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
    LB_pure();
   LF_pure();
    if(LB>(LF))//-20))
    {
        analogWrite(forwardr,255);
        analogWrite(reverser,0);
        analogWrite(forwardl,0);
        analogWrite(reversel,255);
      
    }
    if(LB<(LF))//-20))
    {
        analogWrite(forwardr,0);
        analogWrite(reverser,255);
        analogWrite(forwardl,255);
        analogWrite(reversel,0);
      
    }    
  }
////////////////////////  

}


///////////////////////////////////


void side_allignment()
{
  analogWrite(pwmr,80);
  analogWrite(pwml,80);
  long unsigned int pulse=millis();
  while(millis()<=(300+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   RB_pure();
   RF_pure();

    if(RB>(RF-5))
    {
        analogWrite(forwardr,0);
        analogWrite(reverser,255);
        analogWrite(forwardl,255);
        analogWrite(reversel,0);
      
    }
    if(RB<(RF-5))
    {
        analogWrite(forwardr,255);
        analogWrite(reverser,0);
        analogWrite(forwardl,0);
        analogWrite(reversel,255);
    }
    
    
    
  }
  
}
///////////////////////////////////////////////////////////////////
void side_allignment_L2()
{
delay(50);
  analogWrite(pwmr,120);
  analogWrite(pwml,120);
//  long unsigned int pulse=millis();
 // while(millis()<=(500+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   LB_pure();
   LF_pure();

    if(LB>(LF))
    {
      while(1)
      {
        if(LF+2>LB)
        break;
        
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           LB_pure();
   LF_pure();
      }
      
    }
   else //if(RF>RB)
    {
      while(1)
      {
      if((LB+10)>LF)
      break;
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           LB_pure();
   LF_pure();
      }
    }
    
    
    
  }
  
  delay(50);
}


/////////////////////////////




void side_allignment2()
{
  delay(50);
  analogWrite(pwmr,120);
  analogWrite(pwml,120);
//  long unsigned int pulse=millis();
 // while(millis()<=(500+pulse))//(vrb!=vrf || vrb!=(vrf+30)|| vrb!=(vrf-30) || vrf!=(vrb+30)|| vrf!=(vrb-30))
  {
   RB_pure();
   RF_pure();

    if(RB>(RF))
    {
      while(1)
      {
        if((RF+10)>RB)
        break;
        
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           RB_pure();
   RF_pure();
      }
      
    }
   else //if(RF>RB)
    {
      while(1)
      {
      if((RB+20)>RF)
      break;
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           RB_pure();
   RF_pure();
      }
    }
    
    
    
  }
  
  delay(50);

//////////////////////////////////



  {
   RB_pure();
   RF_pure();

    if(RB>(RF))
    {
      while(1)
      {
        if((RF+10)>RB)
        break;
        
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);
        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
           RB_pure();
   RF_pure();
      }
      
    }
   else //if(RF>RB)
    {
      while(1)
      {
      if((RB+20)>RF)
      break;
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);
        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
           RB_pure();
   RF_pure();
      }
    }
    
    
    
  }
  
  delay(50);

//////////////////////////////////




}


////////////////////////////////////////////////////////////////





void pulse_count_R()
{
  encoderRight++;
}

void pulse_count_L()
{
  encoderLeft++;
}

void anti_clock_s_f(int vr)
{          
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);

        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
  
        analogWrite(pwmr,100);
        analogWrite(pwml,100);
        encoderRight=0;
        while(encoderRight<=vr)
        {}
        encoderRight=0;
        RF_pure();
        RB_pure();
        while(1)
        {
          if(RF<RB-20)
          break;
         RF_pure();
        RB_pure();
        }
        
       // clock(65); //40
        digitalWrite(pwmr,1);
        digitalWrite(pwml,1);      
}

/////////////////
void anti_clock_s_f_b(int vr)
{          
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);

        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
  
        analogWrite(pwmr,0);
        analogWrite(pwml,0);
  anti_clock(vr);
       
        BR_pure();
        BL_pure();
         encoderRight=0;
        while(1)
        {
          if(BL>BR-15)
          break;
         BL_pure();
        BR_pure();
        }
        
       clockk(30); //40
        analogWrite(pwmr,50);
        analogWrite(pwml,50);      
}


////////////////
void clock_s_b(int vf)
{
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);

        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
  
        digitalWrite(pwmr,100);
        digitalWrite(pwml,100);
        encoderLeft=0;
        while(encoderLeft<=vf)
        {}
        LF_pure();
        LB_pure();
        while(LF<LB)
        {
        LF_pure();
        LB_pure();
        }
        
        anti_clock(90); //40
        digitalWrite(pwmr,1);
        digitalWrite(pwml,1);
        digitalWrite(pwmr,1);
        digitalWrite(pwml,1);  
}



void anti_clock(int vr)
{          
        digitalWrite(forwardr,1);
        digitalWrite(reverser,0);

        digitalWrite(forwardl,0);
        digitalWrite(reversel,1);
  
        analogWrite(pwmr,60);
        analogWrite(pwml,60);
        encoderRight=0;
        while(encoderRight<=vr)
        {}
        digitalWrite(pwmr,1);
        digitalWrite(pwml,1);      
}


void clockk(int vf)

{
        digitalWrite(forwardr,0);
        digitalWrite(reverser,1);

        digitalWrite(forwardl,1);
        digitalWrite(reversel,0);
  
        analogWrite(pwmr,60);
        analogWrite(pwml,60);
        encoderRight=0;
        while(encoderRight<=vf)
        {}
       // digitalWrite(pwmr,1);
       // digitalWrite(pwml,1);    
}


void cal_forward(int e,int rpwm, int lpwm)
{
   analogWrite(pwmr,rpwm);
   analogWrite(pwml,lpwm);
   digitalWrite(forwardr,1);
   digitalWrite(reverser,0);

   digitalWrite(forwardl,1);
   digitalWrite(reversel,0);
   encoderRight=0;
   while(encoderRight<=e)
   {}
   digitalWrite(pwmr,1);
   digitalWrite(pwml,1);
}


void cal_backward(int e,int rpwm, int lpwm)
{
   analogWrite(pwmr,rpwm);
   analogWrite(pwml,lpwm);
   digitalWrite(forwardr,0);
   digitalWrite(reverser,1);

   digitalWrite(forwardl,0);
   digitalWrite(reversel,1);
   encoderRight=0;
   while(encoderRight<=e)
   {}
   digitalWrite(pwmr,1);
   digitalWrite(pwml,1);
}


void forward_break(int span)
{
   analogWrite(pwmr,50);
   analogWrite(pwml,90);
   digitalWrite(forwardr,1);
   digitalWrite(reverser,0);

   digitalWrite(forwardl,1);
   digitalWrite(reversel,0);
   delay(span);
   digitalWrite(pwmr,1);
   digitalWrite(pwml,1);
}




void reverse_break(int span)
{
   analogWrite(pwmr,50);  // 90
   analogWrite(pwml,90);
   digitalWrite(forwardr,0);
   digitalWrite(reverser,1);

   digitalWrite(forwardl,0);
   digitalWrite(reversel,1);
   delay(span);
   digitalWrite(pwmr,1);
   digitalWrite(pwml,1);
}


void backward_move(int rpwm,int lpwm)
{
   analogWrite(pwmr,rpwm);
   analogWrite(pwml,lpwm);
   digitalWrite(forwardr,0);
   digitalWrite(reverser,1);

   digitalWrite(forwardl,0);
   digitalWrite(reversel,1);
}


void forward_move(int rpwm,int lpwm)
{
   analogWrite(pwmr,rpwm);
   analogWrite(pwml,lpwm);
   digitalWrite(forwardr,1);
   digitalWrite(reverser,0);

   digitalWrite(forwardl,1);
   digitalWrite(reversel,0);
}




void stopp()
{
   analogWrite(pwmr,255);
   analogWrite(pwml,255);
   digitalWrite(forwardr,1);
   digitalWrite(reverser,1);

   digitalWrite(forwardl,1);
   digitalWrite(reversel,1);
}


































void FR_pure()
{
    FR_store[0]=analogRead(fr);
    FR_store[1]=analogRead(fr);
    FR_store[2]=analogRead(fr);
   // FR_store[3]=analogRead(fr);

  FR=FR_store[2]+FR_store[1]+FR_store[0];
  FR=FR/3;

}


void FL_pure()
{
    FL_store[0]=analogRead(fl);
    FL_store[1]=analogRead(fl);
    FL_store[2]=analogRead(fl);
   //FL_store[3]=analogRead(fl);

  FL=FL_store[2]+FL_store[1]+FL_store[0];//
  FL=FL/3;
 
}


void BL_pure()
{
    
    BL_store[0]=analogRead(bl);
    BL_store[1]=analogRead(bl);
    BL_store[2]=analogRead(bl);
    //BL_store[3]=analogRead(bl);

  BL=BL_store[2]+BL_store[1]+BL_store[0];
  BL=BL/3;

}



void BR_pure()
{
   
    BR_store[0]=analogRead(br);
    BR_store[1]=analogRead(br);
    BR_store[2]=analogRead(br);
   // BR_store[3]=analogRead(br);
    
  BR=BR_store[2]+BR_store[1]+BR_store[0];
  BR=BR/3;
 
}


void LF_pure()
{
    
    LF_store[0]=analogRead(lf);
    LF_store[1]=analogRead(lf);
    LF_store[2]=analogRead(lf);
  //  LF_store[3]=analogRead(lf);
    
  LF=LF_store[2]+LF_store[1]+LF_store[0];
  LF=LF/3;

}


void LB_pure()
{
    
    LB_store[0]=analogRead(lb);
    LB_store[1]=analogRead(lb);
    LB_store[2]=analogRead(lb);
 //   LB_store[3]=analogRead(lb);

  LB=LB_store[2]+LB_store[1]+LB_store[0];
  LB=LB/3;

}



void RF_pure()
{
    RF_store[0]=analogRead(rf);
    RF_store[1]=analogRead(rf);
    RF_store[2]=analogRead(rf);
   // RF_store[3]=analogRead(rf);
    
  RF=RF_store[2]+RF_store[1]+RF_store[0];
  RF=RF/3;

  
}


void RB_pure()
{
   
    RB_store[0]=analogRead(rb);
    RB_store[1]=analogRead(rb);
    RB_store[2]=analogRead(rb);
  //  RB_store[3]=analogRead(rb);
    
  RB=RB_store[2]+RB_store[1]+RB_store[0];
  RB=RB/3;
  
}

void FLG_pure()
{
    FLG_store[0]=analogRead(flg);
    FLG_store[1]=analogRead(flg);
    FLG_store[2]=analogRead(flg);
  //  FLG_store[3]=analogRead(flg);
    
  FLG=FLG_store[2]+FLG_store[1]+FLG_store[0];
  FLG=FLG/3;

}


void BLG_pure()
{
    BLG_store[0]=analogRead(blg);
    BLG_store[1]=analogRead(blg);
    BLG_store[2]=analogRead(blg);
  //  FLG_store[3]=analogRead(flg);
    
  BLG=BLG_store[2]+BLG_store[1]+BLG_store[0];
  BLG=BLG/3;
//Serial.println(FLG);  
}

void C1_pure()
{
  C1_store[0]=analogRead(c1);
  C1_store[1]=analogRead(c1);
  C1_store[2]=analogRead(c1);
  
  C1= C1_store[0]+C1_store[1]+C1_store[2];
  C1=C1/3;
}

void C2_pure()
{
  C2_store[0]=analogRead(c2);
  C2_store[1]=analogRead(c2);
  C2_store[2]=analogRead(c2);
  
  C2= C2_store[0]+C2_store[1]+C2_store[2];
  C2=C2/3;
}

void C3_pure()
{
  C3_store[0]=analogRead(c3);
  C3_store[1]=analogRead(c3);
  C3_store[2]=analogRead(c3);
  
  C3= C3_store[0]+C3_store[1]+C3_store[2];
  C3=C3/3;
}



void pulse_count_E()
{
  encoderM++;
}
