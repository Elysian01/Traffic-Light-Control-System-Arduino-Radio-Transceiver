#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> 
#endif

// connect data to pin 2
// ( Speed, receving pin , Transmitting pin , push to talk)
RH_ASK driver(2000, 4, 10, 5);


int sw1 = 9;
int sw2 = 7;
int sw3 = 5;
int sw4 = 3;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);    
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
  ;
#endif



pinMode(sw1,INPUT_PULLUP);
pinMode(sw2,INPUT_PULLUP);
pinMode(sw3,INPUT_PULLUP);
pinMode(sw4,INPUT_PULLUP);
}

void loop()
{
  int a = digitalRead(sw1);
  int b = digitalRead(sw2);
  int c = digitalRead(sw3);
  int d = digitalRead(sw4);
  
  if ( a == 0 && b!= 0 && c != 0 && d!=0){
    const char *msg = "East"; 
    driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
  }
  else if (a != 0 && b== 0 && c != 0 && d!=0){
    const char *msg = "South"; 
    driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
  }
  else if (a != 0 && b!= 0 && c == 0 && d!=0){
    const char *msg = "West"; 
    driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
  }
  else if (a != 0 && b!= 0 && c != 0 && d==0){
    const char *msg = "North"; 
    driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
  }
  else 
  {
   const char *msg = "Invalid Input";
   driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
  }
  
    

    
} 
