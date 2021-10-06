/*********************************************************

This code uses an Arduino uno to command one SMD PWM Motor COntroller (TE-294-001).


***********************************************************/

const int inAPin_1 = 2;
const int inBPin_1 = 4;
const int PWMPin_1 = 3;

const int inAPin_2 = 5;
const int inBPin_2 = 7;
const int PWMPin_2 = 6;

void setup() {

  pinMode(inAPin_1, OUTPUT);
  pinMode(inBPin_1, OUTPUT);
  pinMode(PWMPin_1, OUTPUT);
  
  pinMode(inAPin_2, OUTPUT);
  pinMode(inBPin_2, OUTPUT);
  pinMode(PWMPin_2, OUTPUT);
}

void loop() {
  int i;
  digitalWrite(inAPin_1, LOW); //stop motors can be both low or high
  digitalWrite(inBPin_1, LOW);
  
  digitalWrite(inAPin_2, LOW); //stop motors can be both low or high
  digitalWrite(inBPin_2, LOW);
  
  delay(2000);
  digitalWrite(inAPin_1, HIGH); // move one direction
  digitalWrite(inBPin_1, LOW);
  
  digitalWrite(inAPin_2, HIGH); // move one direction
  digitalWrite(inBPin_2, LOW);
  
  for (i = 0; i < 50; i++){ 
     analogWrite(PWMPin_1, i);
     analogWrite(PWMPin_2, i);
     delay(10);
  }
   delay(2000);

  digitalWrite(inAPin_1, LOW); // stop motor
  digitalWrite(inBPin_1, LOW);
  
  digitalWrite(inAPin_2, LOW); // stop motor
  digitalWrite(inBPin_2, LOW);
  
  delay(2000);
  
  digitalWrite(inAPin_1, LOW); // move other direction
  digitalWrite(inBPin_1, HIGH);
  
  digitalWrite(inAPin_2, LOW); // move other direction
  digitalWrite(inBPin_2, HIGH);
  
  for (i = 0; i < 50; i++){
     analogWrite(PWMPin_1,i);
     analogWrite(PWMPin_2,i);
     delay(10);
  }
   delay(2000);
   

}
