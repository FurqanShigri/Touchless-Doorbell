const int irSensor = 2;
const int buzzer = 8;

bool doorbellRang = false;

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(irSensor);

  Serial.println(sensorState);

  // Hand detected
  if (sensorState == LOW && doorbellRang == false) {
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);

    doorbellRang = true;
  }

  // Wait until hand is removed
  if (sensorState == HIGH) {
    doorbellRang = false;
  }

  delay(50);
}