void Measure();
void Correction(int x);
void Print();
void OC_Print();
void CB_Print();
#include<LiquidCrystal.h>
LiquidCrystal LCD(13,12,11,10,9,8);

float PF, Angle;
int dur = 0;
int Case = 0;
float IL,IL1;

int R1 = 1;
int R2 = 2;
int R3 = 3;
int R4 = 4;
int ReadDur = 0;


void setup() {
  
  LCD.begin(20, 4);
  
  pinMode(ReadDur, INPUT);
  pinMode(A0,INPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R4, LOW);
  
}

void loop() {

  Case=0;
  Correction(Case);
  Measure();
  delay(500);
  
  while(IL<1 && IL1<1)
 {
  LCD.clear();
  OC_Print();
  delay(300);
  Measure();
  delay(500);
  }

  Case=0;
  Correction(Case);
  Measure();
  delay(500);
  
  LCD.clear();
  Print();
  CB_Print();
  
while(PF<0.95)
    {
     LCD.setCursor(0,2);
     LCD.print("Correcting PF");
     Case++;
     if (Case>15)
     {Case=0;
     break;}
     Correction(Case);
     delay(100);
     Measure();
     delay(500);
     Print();
     CB_Print();
     if(Angle>20 || PF>0.95)
     break;
     delay(400);
    }
    
    delay(400);
    
    LCD.setCursor(0,2);
    LCD.print("                   ");
    LCD.setCursor(0,2);
    LCD.print("WAIT");
    delay(1000);
    Print();
    CB_Print();
    
    while(1)
    {
      if(PF<0.95)
      {
        break;
      }
      
      LCD.setCursor(0,2);
      LCD.print("                   ");
      LCD.setCursor(0,2);
      LCD.print("CORRECTION DONE!");
      
      delay(700);
      Measure();
      Print();
      CB_Print();
      }
      
      delay(500);
    
     
}


 

void Measure()
{
  dur = pulseIn(ReadDur, HIGH);
  Angle = dur * 0.018; //time to angle (in degree) convert
  Angle = Angle-90; // (-90) is for offseting the angle
  PF = cos(Angle*0.0174533); //angle conversion from degree to radian, then PF calcultion
 IL= analogRead(A0);
 delay(500);
 IL1= analogRead(A0);
}

void Print()
{
  LCD.setCursor(0,3);
  LCD.print("                  ");
  LCD.setCursor(0,0);  //setCursor(x,y)    x=column  y=row
  LCD.print("Angle = ");
  LCD.print(Angle);
  LCD.setCursor(0,1);
  LCD.print("PF = ");
  LCD.print(PF);
  
  
}
void CB_Print()
{
  LCD.setCursor(0,3);
  LCD.print("CB Combination=");
  LCD.print(Case);
}

  void OC_Print()
{
  LCD.clear();
  LCD.setCursor(0,1);  //setCursor(x,y)    x=column  y=row
  LCD.print("       NO LOAD");
  LCD.setCursor(0,2);
  LCD.print("      CONNECTED");
  }


  
void Correction(int x)
{
  if(x==1)
  {
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  else if(x==2)
  {
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  }

  else if(x==3)
  {
     digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
  }

  else if(x==4)
  {
     digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
   digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }

  else if(x==5)
  {
    digitalWrite(R1, HIGH);
   digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
   digitalWrite(R4, LOW);
  }

  else if(x==6)
  {
    digitalWrite(R1, LOW);
   digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }

  else if(x==7)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }
  else if(x==8)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
   digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==9)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==10)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==11)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==12)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==13)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==14)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==15)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
  } 
}
