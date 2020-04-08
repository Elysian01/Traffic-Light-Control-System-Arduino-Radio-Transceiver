#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> 
#endif

// connect data to pin 2
// ( Speed, receving pin , Transmitting pin , push to talk)
RH_ASK driver(2000, 2, 4, 5); 
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
}

void loop()
{
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
    }
}
