

#include <Servo.h> 

Servo myservo;   //boro
Servo uservo;
int pos = 0; 
 int mre=2;
 int mrf=3;
 int mrb=4;//5
 int mle=7;
 int mlf=6;
 int mlb=8;//9

void setup()
{//boroservo.attach(5);
//chotoservo.attach(6);nn
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 // pinMode(13,OUTPUT);

    ; // wait for serial port to connect. Needed for Leonardo only

  pinMode(13,OUTPUT);
   pinMode(2,OUTPUT);//right enable
  pinMode(3,OUTPUT);//right forward
  pinMode(5,OUTPUT);//right backward   
  pinMode(6,OUTPUT);//left forward
  pinMode(7,OUTPUT); //left enable 
  pinMode(9,OUTPUT);//left backward
myservo.attach(9);

uservo.attach(11);//choto
  // set the data rate for the SoftwareSerial port
 uservo.write(140);
delay(1000);

}

void loop() // run over and over
{ int data;

digitalWrite(mre,LOW);
digitalWrite(mle,LOW);
  
  if (Serial.available())
{ //Serial.println("Hello, world?");

data=Serial.read();
//Serial.println(data);
if(data==85){botforward();
//Serial.println("Moving forward");
digitalWrite(13,HIGH);}
else if(data==68){botbackward();
//Serial.print("Moving backward");
}
else if(data==82){botright();
//Serial.print("Moving right");
}
else if(data==76){botleft();
//Serial.print("Moving left");
}
if(data==97){

 for(pos = 90; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } }
 
 if(data==99)
 {
  for(pos = 180; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  }
  if(data==98){
uservo.write(130);
delay(200);}
if(data==100){
for(int i=130;i>=70;i-=10)
{uservo.write(i);
delay(200);}}

}
}


void botforward()
{digitalWrite(mre,HIGH);
digitalWrite(mre,HIGH);
analogWrite(mrf,200);
digitalWrite(mrb,LOW);
analogWrite(mlf,200);
digitalWrite(mlb,LOW);
delay(1000);}

void botbackward()
{digitalWrite(mre,HIGH);
digitalWrite(mle,HIGH);
analogWrite(mrf,0);
digitalWrite(mrb,HIGH);
analogWrite(mlf,0);
digitalWrite(mlb,HIGH);
delay(1000);}
void botleft()
{digitalWrite(mre,HIGH);
digitalWrite(mle,HIGH);
analogWrite(mrf,200);
digitalWrite(mrb,LOW);
analogWrite(mlf,0);
digitalWrite(mlb,HIGH);
delay(1000);}
void botright()
{digitalWrite(mre,HIGH);
digitalWrite(mle,HIGH);
analogWrite(mrf,0);
digitalWrite(mrb,HIGH);
analogWrite(mlf,200);
digitalWrite(mlb,LOW);
delay(1000);}

