#include <Servo.h>

Servo myservo;  // create servo object to control a servo
#define servoPin 3
#define pushButtonPin 2 

int angle =90;
int angleStep =50;
const int minAngle = 0;
const int maxAngle = 180;

const int type =2;

int buttonPushed =0;

void setup() {
  Serial.begin(9600);          //  setup serial
  myservo.attach(servoPin);  // attaches the servo on pin 3 to the servo object
  pinMode(pushButtonPin,INPUT_PULLUP);
   myservo.write(angle);//initial position
}

void loop() {
  if(digitalRead(pushButtonPin) == LOW){
    buttonPushed = 1;
  }
   if( buttonPushed ){
  angle = angle + angleStep;

    // reverse the direction of the moving at the ends of the angle:
    if (angle >= maxAngle) {
      angleStep = -angleStep;
        if(type ==1)
        {
            buttonPushed =0;                   
        }
    }
    
    if (angle <= minAngle) {
      angleStep = -angleStep;
       if(type ==2)
        {
            buttonPushed =0;       
        }
    }
    
    myservo.write(angle); // move the servo to desired angle
    
  delay(50); // waits for the servo to get there
   }

  
}
