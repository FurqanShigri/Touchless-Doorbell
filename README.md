# Touchless Doorbell Using IR Sensor and Arduino

## 📌 Project Overview

The **Touchless Doorbell** is an Arduino-based project that allows a user to ring a doorbell without physically touching any button. An **IR sensor** detects the presence of a person's hand or an object near the sensor. When an object is detected, the Arduino activates a buzzer for a short time.

This project is useful for learning about **IR sensors, digital input, Arduino programming, and buzzer control**.

---

## 🎯 Project Objective

The main objective of this project is to create a simple contactless doorbell system that:

* Detects a hand or object using an IR sensor
* Activates a buzzer when an object is detected
* Prevents the buzzer from beeping continuously
* Works without requiring physical contact

---

## 🧰 Components Required

| Component                    |    Quantity |
| ---------------------------- | ----------: |
| Arduino Uno                  |           1 |
| IR Obstacle/Proximity Sensor |           1 |
| Buzzer                       |           1 |
| Breadboard                   |           1 |
| Jumper Wires                 | As required |

---

## 🔌 Circuit Connections

### IR Sensor

| IR Sensor Pin | Arduino Uno   |
| ------------- | ------------- |
| VCC           | 5V            |
| GND           | GND           |
| OUT           | Digital Pin 2 |

### Buzzer

| Buzzer Pin   | Arduino Uno   |
| ------------ | ------------- |
| Positive (+) | Digital Pin 8 |
| Negative (-) | GND           |

---

## ⚙️ Working Principle

1. The IR sensor continuously detects objects near it.
2. When a hand or object comes close to the sensor, the sensor output changes.
3. The Arduino reads the signal from the IR sensor.
4. When the sensor detects an object, the Arduino activates the buzzer.
5. The buzzer beeps once.
6. The system waits until the object or hand is removed before allowing another beep.

The IR sensor commonly works as follows:

* `LOW (0)` → Object detected
* `HIGH (1)` → No object detected

> Note: The output logic may vary depending on the IR sensor module. If your sensor works in the opposite way, change `LOW` to `HIGH` in the code.

---

## 💻 Arduino Code

```cpp
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
```

---

## 🔊 How the Buzzer Works

The Arduino uses the `tone()` function to generate a sound:

```cpp
tone(buzzer, 1000);
```

This produces a sound with a frequency of **1000 Hz**.

The buzzer is stopped using:

```cpp
noTone(buzzer);
```

---

## 🧪 Testing

To test the project:

1. Upload the code to the Arduino Uno.
2. Open the Serial Monitor at **9600 baud**.
3. Keep your hand away from the IR sensor.
4. Move your hand close to the sensor.
5. The sensor should detect your hand.
6. The buzzer should beep once.
7. Move your hand away and bring it near again to activate the doorbell again.

---

## ⚠️ Troubleshooting

### Buzzer Does Not Beep

Check:

* Buzzer positive pin is connected to Arduino digital pin 8.
* Buzzer negative pin is connected to GND.
* The buzzer is not connected backward.
* The correct Arduino board and port are selected.

### Buzzer Beeps Continuously

The IR sensor may be detecting an object continuously.

Try:

* Moving objects away from the sensor.
* Adjusting the IR sensor's sensitivity potentiometer.
* Checking the OUT pin connection.

### Sensor Always Shows `0`

Adjust the small potentiometer on the IR sensor module until:

* No object detected → `1`
* Object detected → `0`

### Sensor Logic Is Reversed

If your sensor shows:

* `HIGH` when an object is detected

Change:

```cpp
if (sensorState == LOW)
```

to:

```cpp
if (sensorState == HIGH)
```

---

## 🚀 Future Improvements

This project can be improved by adding:

* LCD display
* LED indicator
* Servo motor for automatic door opening
* Wi-Fi notification using ESP32
* Camera for visitor detection
* Motion sensor
* Bluetooth notification
* Smart home integration

---

## 📁 Project Files

A recommended project folder structure:

```text
Touchless-Doorbell/
│
├── Touchless_Doorbell.ino
├── README.md
├── Circuit_Diagram.png
└── Working_Video.mp4
```

---

## 👨‍💻 Project Information

**Project Name:** Touchless Doorbell
**Platform:** Arduino
**Microcontroller:** Arduino Uno
**Input:** IR Proximity Sensor
**Output:** Buzzer
**Programming Language:** C/C++

---

## 📜 License

This project is created for educational and learning purposes.
 
