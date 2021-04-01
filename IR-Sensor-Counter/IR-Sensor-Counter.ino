int irPin = D7;
int count = 0;

boolean state = true;

void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT);

}

void loop() {
  if(!digitalRead(irPin) && state){
    count++;
    state = false;
    Serial.print("Count : ");
    Serial.println(count);
    delay(100);
  }

  if(digitalRead(irPin)){
    state = true;
    delay(100);
  }

}
