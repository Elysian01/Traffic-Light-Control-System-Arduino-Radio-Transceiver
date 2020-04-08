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
  
}

void loop() {

  digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
  digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
  digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
  digitalWrite(r1,0);delay(lightGap);digitalWrite(y1,1);delay(lightGap);digitalWrite(y1,0);digitalWrite(g1,1);delay(eachlaneTime);

  digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);
  digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
  digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
  digitalWrite(r2,0);delay(lightGap);digitalWrite(y2,1);delay(lightGap);digitalWrite(y2,0);digitalWrite(g2,1);delay(eachlaneTime);

  digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);delay(100);
  digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
  digitalWrite(r4,1);digitalWrite(y4,0);digitalWrite(g4,0);
  digitalWrite(r3,0);delay(lightGap);digitalWrite(y3,1);delay(lightGap);digitalWrite(y3,0);digitalWrite(g3,1);delay(eachlaneTime);


  digitalWrite(r1,1);digitalWrite(y1,0);digitalWrite(g1,0);
  digitalWrite(r2,1);digitalWrite(y2,0);digitalWrite(g2,0);
  digitalWrite(r3,1);digitalWrite(y3,0);digitalWrite(g3,0);
  digitalWrite(r4,0);delay(lightGap);digitalWrite(y4,1);delay(lightGap);digitalWrite(y4,0);digitalWrite(g4,1);delay(eachlaneTime);

  
}
