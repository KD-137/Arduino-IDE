
const int en_buzz = 3;
const int en_ohm = 4;
const int en_volt = 2;
int dig1=0;
int dig2=0;
int dig3=0;
int dig4=0;
int dot1=0;
int dot2=0;
int dot3=0;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(en_buzz,OUTPUT);
digitalWrite(en_buzz, LOW);
pinMode(en_ohm, OUTPUT);
digitalWrite(en_ohm,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available() > 0)
{
  char inByte = Serial.read();

  if (inByte=='V')
  {
    dig1=0;
    dig2=0;
    dig3=0;
    dig4=0;
    mode = 1;
    Serial.write('K');
  }
  else if (inByte=='R')
  {
    dig1=0;
    dig2=0;
    dig3=0;
    dig4=0;
    mode=3;
    digitalWrite(en_buzz,LOW);
    delay(200);
    digitalWrite(en_ohm,HIGH);
    Serial.write('K');
    delay(200);

    
  }
  else if (inByte=='Z')
  {
    mode = 4;
    digitalWrite(en_ohm,LOW);
    delay(200);
    digitalWrite(en_buzz,HIGH);
    Serial.write('K');
    delay(200);

  }
  else
  {
    mode = 0;
    Serial.write('E');
  }
  
}

if (mode!=0) // not a stop state
{

if (mode == 1) // Voltage mode
{

int y=0;
float x = analogRead(A0) * (5.0 / 1023.0);
delay(500);

y = (int) x;
x = x - (float)y;
x= 10 * x;
dig1 = y;
y = (int) x;
x = x - (float)y;
x= 10 * x;
dig2 = y;
y = (int) x;
x = x - (float)y;
x= 10 * x;
dig3 = y;
dig4 = (int) x;


Serial.print('a');
   Serial.print(dig1);
Serial.print('b');
Serial.print(dig2);
Serial.print('c');
Serial.print(dig3);
Serial.print('d');
Serial.print(dig4);
//Serial.println();

}
else if (mode==3)
{

  int y=0;
  float x = analogRead(A2) * (5.0 / 1023.0);

  if(x>2.5)
  {
    dig1=8;
    dig2=8;
    dig3=8;
    dig4=8;
    dot1=1;
    dot2=1;
    dot3=1;
    
  }
  else
  {

y = (int) x;
x = x - (float)y;
x= 10 * x;
dig1 = y;
y = (int) x;
x = x - (float)y;
x= 10 * x;
dig2 = y;
y = (int) x;
x = x - (float)y;
x= 10 * x;
dig3 = y;
dig4 = (int) x;

  dot1=0;
  dot2=0;
  dot3=1;
  }

Serial.print('a');
Serial.print(dig1);
Serial.print('e');
Serial.print(dot1);
Serial.print('b');
Serial.print(dig2);
Serial.print('f');
Serial.print(dot2);
Serial.print('c');
Serial.print(dig3);
Serial.print('g');
Serial.print(dot3);
Serial.print('d');
Serial.print(dig4);
  
  delay(500);
}
else if (mode==4)
{

  if (analogRead(A1) > 400) 
  {
    Serial.print('z');
  }
  delay(20);
}

}


}
