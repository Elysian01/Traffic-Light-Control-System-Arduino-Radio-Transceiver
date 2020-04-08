int redled = 3;
int yellowled = 4;
int greenled = 5
;

void setup() {
  pinMode (redled, OUTPUT);
  pinMode (yellowled, OUTPUT);
  pinMode (greenled, OUTPUT);
  
}

void loop() {

 digitalWrite (redled, 1);
 delay(2000);
    digitalWrite (redled, 0); //stopped  
      digitalWrite (yellowled, 1); 
   delay (2000); // yellowled lights for 3 sec.
   digitalWrite (yellowled, 0);
    digitalWrite (greenled, 1);
   delay (2000);
   digitalWrite (greenled, 0);// greenled start flashing
   delay (500);
   digitalWrite (greenled, 1);
   delay (500);    
   digitalWrite (greenled, 0);
   delay (500);
   digitalWrite (greenled, 1);
   delay (500);
   digitalWrite (greenled, 0);
  delay (500);
 digitalWrite (greenled, 1);
   delay (500);
   digitalWrite (greenled, 0);
     delay (500);
 digitalWrite (greenled, 1);
   delay (500);
   digitalWrite (greenled, 0);
 
 
   
    
}
