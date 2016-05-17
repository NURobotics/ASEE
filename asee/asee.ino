//enable is pin 6 (pwm)
//dir is pin 4(digital)

//AMBIENT_WAIT_TIME is the amount of time we are waiting between our averaging
#define AMBIENT_WAIT_TIME 3
//LIGHT_THRESHOLD is what we will use as our threshold between our ambient base and our current read to determine if we are touching the line at all
#define LIGHT_THRESHOLD 150
int en1 = 5;
int dir1 = 7;

int en2 = 10;
int dir2 = 12;

int en3 = 9;
int dir3 = 8;

int en4 = 6;
int dir4 = 4;

int pushbutton = 3;
int val, x, y;

int en5 = 11;
int dir5 = 13;

int photo1 = 5;
int photo2 = 4;
int leftPhotoTransistor=A1;
int middlePhotoTransistor=A2;
int rightPhotoTransistor=A3;

int leftBase=0;
int middleBase=0;
int rightBase=0;
//these three bases are the base levels initially determined of ambient light during the setup procedure
unsigned long timer;


void setup() {
  Serial.begin(9600);
  pinMode(en1,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(en4, OUTPUT);
  pinMode(en5, OUTPUT);
  pinMode(dir5, OUTPUT);
  pinMode(leftPhotoTransistor, INPUT);
  pinMode(middlePhotoTransistor, INPUT);
  pinMode(rightPhotoTransistor, INPUT);
  pinMode(pushbutton,INPUT);

  //here we will set the base levels
  leftBase = setAmbientBase(leftPhotoTransistor);
  middleBase = setAmbientBase(middlePhotoTransistor);
  rightBase = setAmbientBase(rightPhotoTransistor);
  
  Serial.begin(9600);
}

void loop() {
//  val = digitalRead(pushbutton);
//  if(val == 1) {
//    drop_one_ring();
//
//    delay(1000);
  

  //y = analogRead(photo1); //right sensor
  //x = analogRead(photo2); //left sensor
  Serial.println(analogRead(leftPhotoTransistor));
  delay(250);
  if(x <= 500) { //if left sees black
    drift_left(80,0);
  }else if(y <= 500) {
    drift_right(80,0);
  }else {
 all_forward(100);
  }

}

void drop_one_ring() {
  timer = millis(); 
  
  while(millis() - timer <= 50) {
    analogWrite(en5,100);
    digitalWrite(dir5,HIGH);
  }
  analogWrite(en5,0);
}

//45 100 was almost perfect should be faster
//90 50 

void output_photo() {
  y = analogRead(photo1);
  x = analogRead(photo2);
  Serial.print(x); //both when under 4000
  Serial.print("    ");
  Serial.println(y);

}

