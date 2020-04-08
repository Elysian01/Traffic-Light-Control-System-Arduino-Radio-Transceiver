#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> 
#endif



// ( Speed, receving pin , Transmitting pin , push to talk)
RH_ASK driver(2000, 2, 4, 5); 

// Traffic light pins allotment
int r1 = 52;
int y1 = 50;
int g1 = 48;

int r2 = 42;
int y2 = 40;
int g2 = 38;

int r3 = 32;
int y3 = 30;
int g3 = 28;

int r4 = 24;
int y4 = 22;
int g4 = 23;

int eachlaneTime = 2000; // time for green light to remain active
int lightGap = 1000;  // Between red and yellow , yellow and green


void setup() {


  pinMode (r1, OUTPUT);
  pinMode (y1, OUTPUT);
  pinMode (g1, OUTPUT);

  pinMode (r2, OUTPUT);
  pinMode (y2, OUTPUT);
  pinMode (g2, OUTPUT);

  pinMode (r3, OUTPUT);
  pinMode (y3, OUTPUT);
  pinMode (g3, OUTPUT);

  pinMode (r4, OUTPUT);
  pinMode (y4, OUTPUT);
  pinMode (g4, OUTPUT);


  #ifdef RH_HAVE_SERIAL
    Serial.begin(9600);    
  #endif
  if (!driver.init())
  #ifdef RH_HAVE_SERIAL
    Serial.println("init failed");
  #else
  ;
  #endif

}

void loop() {
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
  
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      // Message with a good checksum received, dump it.
      //driver.printBuffer("Got:", buf, buflen);
        
          String rev;
          for (int i = 0; i < buflen;i++) {
              rev += (char)buf[i];
          }
          while (rev.equals("Invalid Input"))
          {            
              digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
                digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
                digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
                digitalWrite(r1,0);delay(lightGap);digitalWrite(y1,1);delay(lightGap);digitalWrite(y1,0);digitalWrite(g1,1);delay(eachlaneTime);
               String check = Receiver();
              if (check != "Invalid Input") {break;}

              
                digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);
                digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
                digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
                digitalWrite(r2,0);delay(lightGap);digitalWrite(y2,1);delay(lightGap);digitalWrite(y2,0);digitalWrite(g2,1);delay(eachlaneTime);
               check = Receiver();
              if (check != "Invalid Input") {break;}
              
                digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);delay(100);
                digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
                digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
                digitalWrite(r3,0);delay(lightGap);digitalWrite(y3,1);delay(lightGap);digitalWrite(y3,0);digitalWrite(g3,1);delay(eachlaneTime);
               check = Receiver();
              if (check != "Invalid Input") {break;}
                       
                digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);
                digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
                digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
                digitalWrite(r4,0);delay(lightGap);digitalWrite(y4,1);delay(lightGap);digitalWrite(y4,0);digitalWrite(g4,1);delay(eachlaneTime);
               check = Receiver();
              if (check != "Invalid Input") {break;}
              
          }
          
          if (rev.equals("East"))
          {
                digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
                digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
                digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
                digitalWrite(r1,0);digitalWrite(y1,0);digitalWrite(g1,1);    
          }

          
          else if (rev == "South")
          {
              digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
              digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
              digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);
              digitalWrite(r2,0);digitalWrite(y2,0);digitalWrite(g2,1);
          }

          else if (rev == "West")
          {
              digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
              digitalWrite(r3,0);digitalWrite(y3,0);digitalWrite(g3,1);
              digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
              digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0); 
          }

          else if (rev == "North")
          {
              digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
              digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
              digitalWrite(r4,0);digitalWrite(y4,0);digitalWrite(g4,1);
              digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0); 
          }
          else 
          {
              digitalWrite(r2,0);digitalWrite(y2,0);digitalWrite(g2,0);
              digitalWrite(r3,0);digitalWrite(y3,0);digitalWrite(g3,0);
              digitalWrite(r4,0);digitalWrite(y4,0);digitalWrite(g4,0);
              digitalWrite(r1,0);digitalWrite(y1,0);digitalWrite(g1,0); 
          }
          Serial.println(rev);         
    } 
}

String Receiver(){
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      // Message with a good checksum received, dump it.
      //driver.printBuffer("Got:", buf, buflen);
        
        String rev;
          for (int i = 0; i < buflen;i++) {
            rev += (char)buf[i];
          }
          Serial.println(rev);
          delay(100);
          return rev;
          
    }
}
