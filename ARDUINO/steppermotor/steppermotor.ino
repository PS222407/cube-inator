int spd = 1500; //MICROSECONDS lager = sneller maar ook minder torque
int dly = 250;
int steps = 50;
long randNumber;
long randNumber2;

bool clockwise = true;

//1250
//250

//850
//10

// Define stepper motor connections and steps per revolution:
#define stepsPerRevolution 200

#define dirPinTOP 4
#define stepPinTOP 5

#define dirPinFRONT 2
#define stepPinFRONT 3

#define dirPinBOTTOM 6
#define stepPinBOTTOM 7

#define dirPinBACK 8
#define stepPinBACK 9

#define dirPinRIGHT 10
#define stepPinRIGHT 11

#define dirPinLEFT 12
#define stepPinLEFT 13

void setup() {  
  randomSeed(analogRead(0));
  
  pinMode(stepPinTOP, OUTPUT);    //
  pinMode(dirPinTOP, OUTPUT);     //
  digitalWrite(dirPinTOP, HIGH);  //

  pinMode(stepPinFRONT, OUTPUT);
  pinMode(dirPinFRONT, OUTPUT);
  digitalWrite(dirPinFRONT, HIGH);

  pinMode(stepPinBOTTOM, OUTPUT);
  pinMode(dirPinBOTTOM, OUTPUT);
  digitalWrite(dirPinBOTTOM, HIGH);

  pinMode(stepPinBACK, OUTPUT);
  pinMode(dirPinBACK, OUTPUT);
  digitalWrite(dirPinBACK, HIGH);
  
  pinMode(stepPinRIGHT, OUTPUT);
  pinMode(dirPinRIGHT, OUTPUT);
  digitalWrite(dirPinRIGHT, HIGH);
  
  pinMode(stepPinLEFT, OUTPUT);
  pinMode(dirPinLEFT, OUTPUT);
  digitalWrite(dirPinLEFT, HIGH);


  if (!clockwise){    
  digitalWrite(dirPinTOP, LOW);
  digitalWrite(dirPinFRONT, LOW);
  digitalWrite(dirPinBOTTOM, LOW);
  digitalWrite(dirPinBACK, LOW);
  digitalWrite(dirPinRIGHT, LOW);
  digitalWrite(dirPinLEFT, LOW);
  }

  solve();
}


int count = 0;

void solve(){
    for (int i = 0; i < 50; i++){
        randNumber = random(12);
        randNumber2 = random(3);
        steps = 50;
        if (randNumber2 == 1){
          steps = 100;
        }
        
        switch (randNumber) {
        case 0:
          motorTOP();
          break;
        case 1:
          motorFRONT();
          break;
        case 2:
          motorBOTTOM();
          break;
        case 3:
          motorBACK();
          break;
        case 4:
          motorRIGHT();
          break;
        case 5:
          motorLEFT();
          break;
          
        case 6:
          motorTOPc();
          break;
        case 7:
          motorFRONTc();
          break;
        case 8:
          motorBOTTOMc();
          break;
        case 9:
          motorBACKc();
          break;
        case 10:
          motorRIGHTc();
          break;
        case 11:
          motorLEFTc();
          break;
      }
        
      delay(150);
    }
}

void loop() {
//  motorTOP();
//  delay(dly);
//  motorFRONT();
//  delay(dly);
//  motorBOTTOM();
//  delay(dly);
//  motorBACK();
//  delay(dly);
//  motorRIGHT();
//  delay(dly);
//  motorLEFT();
//  delay(dly);
//
//  delay(1000);
//  
//  motorTOPc();
//  delay(dly);
//  motorFRONTc();
//  delay(dly);
//  motorBOTTOMc();
//  delay(dly);
//  motorBACKc();
//  delay(dly);
//  motorRIGHTc();
//  delay(dly);
//  motorLEFTc();
//  delay(dly);
////
//  count++;
//  delay(2000);
}


void motorTOP(){
  digitalWrite(dirPinTOP, HIGH);  //
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinTOP, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinTOP, LOW);
    delayMicroseconds(spd);
  }
}
void motorFRONT(){
  digitalWrite(dirPinFRONT, HIGH);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinFRONT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinFRONT, LOW);
    delayMicroseconds(spd);
  }
}
void motorBOTTOM(){
  digitalWrite(dirPinBOTTOM, HIGH);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinBOTTOM, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinBOTTOM, LOW);
    delayMicroseconds(spd);
  }
}
void motorBACK(){
  digitalWrite(dirPinBACK, HIGH);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinBACK, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinBACK, LOW);
    delayMicroseconds(spd);
  }
}
void motorRIGHT(){
  digitalWrite(dirPinRIGHT, HIGH);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinRIGHT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinRIGHT, LOW);
    delayMicroseconds(spd);
  }
}
void motorLEFT(){
  digitalWrite(dirPinLEFT, HIGH);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinLEFT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinLEFT, LOW);
    delayMicroseconds(spd);
  }
}





void motorTOPc(){
  digitalWrite(dirPinTOP, LOW);  //
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinTOP, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinTOP, LOW);
    delayMicroseconds(spd);
  }
}
void motorFRONTc(){
  digitalWrite(dirPinFRONT, LOW);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinFRONT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinFRONT, LOW);
    delayMicroseconds(spd);
  }
}
void motorBOTTOMc(){
  digitalWrite(dirPinBOTTOM, LOW);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinBOTTOM, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinBOTTOM, LOW);
    delayMicroseconds(spd);
  }
}
void motorBACKc(){
  digitalWrite(dirPinBACK, LOW);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinBACK, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinBACK, LOW);
    delayMicroseconds(spd);
  }
}
void motorRIGHTc(){
  digitalWrite(dirPinRIGHT, LOW);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinRIGHT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinRIGHT, LOW);
    delayMicroseconds(spd);
  }
}
void motorLEFTc(){
  digitalWrite(dirPinLEFT, LOW);
    for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinLEFT, HIGH);
    delayMicroseconds(spd);
    digitalWrite(stepPinLEFT, LOW);
    delayMicroseconds(spd);
  }
}
