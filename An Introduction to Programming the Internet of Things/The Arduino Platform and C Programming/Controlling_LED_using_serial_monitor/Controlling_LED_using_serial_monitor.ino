void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int bval = Serial.read();

    if(bval == '1')
      digitalWrite(13, HIGH);

    if(bval == '0')
      digitalWrite(13, LOW);
  }


}
