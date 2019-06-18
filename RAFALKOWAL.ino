#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
// zmienne
String msg;
int kroki_x=0;
int kroki_y=0;
int kroki_z=0;
int i=0;
int x=0;

int kier_x=0;
int kier_y=0;
int kier_z=0;
void setup() {
  
  
// put your setup code here, to run once:

Serial.begin(115200);
pinMode(X_ENABLE_PIN, OUTPUT);
digitalWrite (X_ENABLE_PIN, LOW);
pinMode(Y_ENABLE_PIN, OUTPUT);
digitalWrite (Y_ENABLE_PIN, LOW);
pinMode(Z_ENABLE_PIN, OUTPUT);
digitalWrite (Z_ENABLE_PIN, LOW);


pinMode(X_DIR_PIN, OUTPUT);
digitalWrite (X_DIR_PIN, HIGH);
pinMode(Y_DIR_PIN, OUTPUT);
digitalWrite (Y_DIR_PIN, HIGH);
pinMode(Z_DIR_PIN, OUTPUT);
digitalWrite (Z_DIR_PIN, HIGH);

pinMode(X_STEP_PIN, OUTPUT);
pinMode(Y_STEP_PIN, OUTPUT);
pinMode(Z_STEP_PIN, OUTPUT);


pinMode(X_MAX_PIN, INPUT_PULLUP);
pinMode(Y_MAX_PIN, INPUT_PULLUP);
pinMode(Z_MAX_PIN, INPUT_PULLUP);



  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  /*//////////////////////////////////////// INACZEJ TRZEBA ZROBIC XD
if(digitalRead(X_MAX_PIN))
{
digitalWrite (X_STEP_PIN, LOW);

}
if(digitalRead(Y_MAX_PIN))
{
digitalWrite (Y_STEP_PIN, LOW);

}

if(digitalRead(Z_MAX_PIN))
{
digitalWrite (Z_STEP_PIN, LOW);

}
*/


    


   
/*  Ruch w doł i w gore na przemian
    if(i==200)
    {

    digitalWrite (X_DIR_PIN, LOW);
    digitalWrite (Y_DIR_PIN, LOW);
    digitalWrite (Z_DIR_PIN, LOW);
    }
    if(i>400)
    {

    digitalWrite (X_DIR_PIN, HIGH);
    digitalWrite (Y_DIR_PIN, HIGH);
    digitalWrite (Z_DIR_PIN, HIGH);
    i=0;
    }


    */


// kominikacja //sprawdzenie czy cos jest w buforze portu szeregowego
    
  while(Serial.available())
  {
  msg=Serial.readStringUntil('\n');
  sscanf(msg.c_str(),"x %d y %d z %d", &kroki_x, &kroki_y, &kroki_z);
  Serial.println(kroki_x);
  Serial.println(kroki_y);
  Serial.println(kroki_z);
  
  //Sprawdzanie kierunku 
kier_x=kroki_x<0;
digitalWrite (X_DIR_PIN, kier_x);
kroki_x=abs(kroki_x);

kier_y=kroki_y<0;
digitalWrite (Y_DIR_PIN, kier_y);
kroki_y=abs(kroki_y);

kier_z=kroki_z<0;
digitalWrite (Z_DIR_PIN, kier_z);
kroki_z=abs(kroki_z);
  
  }






//Wykonywanie krokow plus zabezpieczenie
if(digitalRead((X_MAX_PIN)==0 || kier_x==1) && kroki_x>0)
  {
  digitalWrite(X_STEP_PIN, HIGH);
  kroki_x--;
  }
  
  

 
if(digitalRead((Y_MAX_PIN)==0 || kier_y==1) && kroki_y>0)
  {
  digitalWrite(Y_STEP_PIN, HIGH);
  kroki_y--;
  }

 

  
  
if(digitalRead((Z_MAX_PIN)==0 || kier_z==1) && kroki_z>0)
  {
  digitalWrite(Z_STEP_PIN, HIGH);
  kroki_z--;
  } 
  
  delay(2);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(2);
  
  


  

}
