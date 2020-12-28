//Nur Batrisyia Binti Azizan
//DE96511
//FINAL CLASS PROJECT EEED253

#include <LiquidCrystal.h> 

LiquidCrystal 
lcd(12,11,5,4,3,2); 

char candidate_1='A';
char candidate_2='B';
int vote_1=0;
int vote_2=0;


int state_1=0;
int state_2=0;
int result=0;

int button_1=6;
int button_2=10;
int button_result=8;

const int pingPin = 7;
const int buzzPin = 9;


//Display message 
void first_display() {
  lcd.setCursor(0,0); 
  lcd.print("1-");
  lcd.print(candidate_1); 
  
  lcd.setCursor(0,1); 

  lcd.print("2-");
  lcd.print(candidate_2); 

  lcd.print("      choose!");
  
}

//To show that the machine is reasy to use
void Light()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

//will detectif user come closer to the machine
void sensor() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Turn on the LED if the object is too close:
  if(cm < 100) {
    digitalWrite(buzzPin, HIGH);
  }
  else {
    digitalWrite(buzzPin, LOW);
  }
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}



void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(button_1,INPUT); 
  pinMode(button_2,INPUT); 
  pinMode(button_result,INPUT); 
  pinMode(buzzPin, OUTPUT);
  pinMode(13, OUTPUT);
 
}

void loop() {
  
  Light();
  
  sensor();

     
  first_display();

    
  state_1= digitalRead(button_1);
  state_2=digitalRead(button_2);
  result=digitalRead(button_result);



  if(state_1==HIGH) {
    vote_1++;
    lcd.clear();
    delay(1000);
    lcd.print(candidate_1);
    lcd.print(" selected"); 
    Serial.print(candidate_1);
    Serial.print("    selected");

    
    delay(2000);
    lcd.clear();
    
    first_display();

  }

  if(state_2==HIGH) {
     vote_2++;
    lcd.clear();
    delay(1000);
    lcd.print(candidate_2);
    lcd.print(" selected"); 
    
    Serial.print(candidate_2);
    Serial.print("    selected");
  
    delay(2000);
    lcd.clear();
    
    first_display();

}

  if(result==HIGH) {
      lcd.clear();
      delay(1000);
      lcd.print(candidate_1);
      lcd.print("    ");
      lcd.print(vote_1);

      Serial.print("    ");
      Serial.print(vote_1);
      
      lcd.setCursor(0,1); 
  
      lcd.print(candidate_2);
      lcd.print("    ");
      lcd.print(vote_2);

      Serial.print("    ");
      Serial.print(vote_2);
      
      delay(4000);
      lcd.clear();
    
      first_display();
  }
} 
 