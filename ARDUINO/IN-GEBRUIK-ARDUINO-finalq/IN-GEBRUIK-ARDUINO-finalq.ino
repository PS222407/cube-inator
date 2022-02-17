//const int DATA_SIZE = 4;
//byte data[DATA_SIZE];   // an array to store the received data
int spd = 1500; //MICROSECONDS lager = sneller maar ook minder torque
int dly = 1000;
int steps = 50;

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

int maxSolveLenght = 315;

String dataString = "";
int count = 0;
//String acknowledge = String("Acknowledge");



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup"); //setup
  
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

  
//  solve();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0)
  {
      String readstring = Serial.readString();
      
      Serial.println(readstring + " ontvangen");
//      int i = Serial.readBytes(data,DATA_SIZE);

      Serial.println(count);
      count++;

      dataString += readstring;
      if(readstring[62] == '1'){
        Serial.println(dataString);
        solve();
      }
  }
  delay(500);
}

void solve(){
//  Serial.println(dataString);
  for(int i = 0; i < maxSolveLenght; i++){
    {
      if(dataString[i] == 'a'){
        steps = 50;
        motorTOP();
      }
      else if (dataString[i] == 'b'){
        steps = 50;
        motorTOPc();
      }
      else if (dataString[i] == 'c'){
        steps = 50;
        motorFRONT();
      }
      else if (dataString[i] == 'd'){
        steps = 50;
        motorFRONTc();
      }
      else if (dataString[i] == 'e'){
        steps = 50;
        motorBOTTOM();
      }
      else if (dataString[i] == 'f'){
        steps = 50;
        motorBOTTOMc();
      }
      else if (dataString[i] == 'g'){
        steps = 50;
        motorBACK();
      }
      else if (dataString[i] == 'h'){
        steps = 50;
        motorBACKc();
      }
      else if (dataString[i] == 'i'){
        steps = 50;
        motorRIGHT();
      }
      else if (dataString[i] == 'j'){
        steps = 50;
        motorRIGHTc();
      }
      else if (dataString[i] == 'k'){
        steps = 50;
        motorLEFT();
      }
      else if (dataString[i] == 'l'){
        steps = 50;
        motorLEFTc();
      }
      else if (dataString[i] == 'm'){
        steps = 100;
        motorTOP();
      }
      else if (dataString[i] == 'n'){
        steps = 100;
        motorFRONT();
      }
      else if (dataString[i] == 'o'){
        steps = 100;
        motorBOTTOM();
      }
      else if (dataString[i] == 'p'){
        steps = 100;
        motorBACK();
      }
      else if (dataString[i] == 'q'){
        steps = 100;
        motorRIGHT();
      }
      else if (dataString[i] == 'r'){
        steps = 100;
        motorLEFT();
      }
      else{
//      Serial.println("DONE");
//        digitalWrite(13, LOW);
      }
      Serial.println(dataString[i]);
      delay(dly);
    }
  }
}


//the code receives 5 arrays by using callbacks, the array is converted to a string (dataString) that will be used to loop through the moves that the motor needs to make.

//MOVE TO BYTES INTERFACE
// U  = a
// U' = b
// F  = c
// F' = d
// D  = e
// D' = f
// B  = g
// B' = h
// R  = i
// R' = j
// L  = k
// L' = l
// U2 = m
// F2 = n
// D2 = o
// B2 = p
// R2 = q
// L2 = r




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
