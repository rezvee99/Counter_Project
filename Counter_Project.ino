#include <LiquidCrystal.h>
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int led1=2;
int led2=3;
int led3=4,led4=5,led5=6,led6=7;


int count = 0;
String re="R";
String c1 = re;
String ch=re;
String c2 = re;
String c3 = re; 
int s1,s2,s3,p,p1,p2;

const int trigPin1 = 8;
const int echoPin1 = 9;

const int trigPin2 = 10;
const int echoPin2 = 11;

const int trigPin3 = 12;
const int echoPin3 = 13;

void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(led1,1);
  pinMode(led2,1);
  pinMode(led3,1);
  pinMode(led4,1);
  pinMode(led5,1);
  pinMode(led6,1);

 
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("People Entered: ");
  lcd.setCursor(0, 1);
  lcd.print("=");

}
long microsecondsToCentimeters(int mic)
{
  return mic/29/2;
}
void loop() {



  long duration1, cm1, duration2, cm2, duration3, cm3;
 

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);

  cm1 = microsecondsToCentimeters(duration1);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration2);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration3 = pulseIn(echoPin3, HIGH);
  cm3 = microsecondsToCentimeters(duration3);

Serial.print(cm1);
Serial.print(" ");
Serial.print(cm2);
Serial.print(" ");
Serial.print(cm3);
Serial.println(" ");



if(cm3==0)
{
  cm3=11;
}





 // Serial.print("X= ");
 // Serial.println(cm3);
 
  if ((cm1 <9 && c1==re) &&(c3==re&&ch==re)&&(c2==re&&c1==re))
  {
   ch="x"; 
   c1="x";
   Serial.print(ch);
   digitalWrite(led4,1);
  
  }
 if ((cm1 <9 && c1==re) &&(c3=="z" && ch=="zy"))
  {
    c1="x";
    ch="zyx";
    Serial.print(ch);
  }
  if((cm2<9 && c3==re)&&(c2==re&&c1=="x")&&(ch=="x"&&c1=="x"))
  {
    c2="y";
    ch="xy";
    Serial.print(ch);
    digitalWrite(led4,1);
    digitalWrite(led6,1);
  }
  if((cm2<9&&c3=="z")&&(c2==re&&c1==re)&&(ch=="z"&&c1==re))
  {
    c2="y";
    ch="zy";
    Serial.print(ch);
    digitalWrite(led4,1);
    digitalWrite(led6,1);
    
  }
  if((cm3<9&&c3==re)&&(c2=="y"&&ch=="xy")&&(c1=="x"&&ch=="xy"))
  {
    c3="z";
    ch="xyz";
    Serial.print(ch);
  }
  if((cm3<9&&c3==re)&&(c2==re&&ch==re)&&(c1==re&&ch==re))
  {
    c3="z";
    ch=c3;
    Serial.print(ch);
    digitalWrite(led6,1);
  }
  Serial.println(ch);
  if((ch=="xyz"&&c1=="x")&&(c2=="y"&&c3=="z"))
  {
    
    count++;
    ch=re;
    c1=re;
    c2=re;
    c3=re;
    
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
    digitalWrite(led6,0);
    delay(1000);
    
  }
  if((ch=="zyx"&&c1=="x")&&(c2 == "y" && c3 =="z"))
  {
    count--;
    ch=re;
    c1=re;
    c2=re;
    c3=re;
   

    digitalWrite(led4,0);
    digitalWrite(led6,0);
    delay(1000);
    
  }
 delay(100);

 
 if(count<0)
 {
  count=0;
 }
 

  Serial.println(count);
  lcd.setCursor(2, 1);
  lcd.print(count);
  delay(5);
  if((count==0&&c3==re)&&(c2==re&&ch==re)&&(c1==re&&ch==re))
  {
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    digitalWrite(led6,0);
  }
  


 
 
  


}

