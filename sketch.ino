#define BLYNK_TEMPLATE_ID "TMPL6ahd7DWY1"
#define BLYNK_TEMPLATE_NAME "smart bus occupancy monitor"
#define BLYNK_AUTH_TOKEN "MoROBlXRpwCNYcyP2h3-BISKGLrF0jYT"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ======================================
// WIFI CONFIG
// ======================================

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// ======================================
// SYSTEM CONFIG
// ======================================

const int totalSeats = 4;

// SENSOR PINS
// sesuai wiring final

int sensorPins[totalSeats] = {
  33,
  32,
  35,
  34
};

// led blynk

int dashboardLedPins[totalSeats] = {
  V8,
  V9,
  V10,
  V11
};

// LED PINS

int ledPins[totalSeats] = {
  13,
  12,
  14,
  27
};

// BUZZER PIN

const int buzzerPin = 26;

// ADC THRESHOLD

const int threshold = 2000;

// ======================================
// WARNING STATE
// ======================================

// agar buzzer hanya bunyi sekali
bool warningTriggered = false;

// ======================================
// BLYNK TIMER
// ======================================

BlynkTimer timer;

// ======================================
// MAIN MONITOR FUNCTION
// ======================================

void monitorSeats() {

  int occupiedSeats = 0;

  // ======================================
  // CHECK EVERY SEAT
  // ======================================

  for (int i = 0; i < totalSeats; i++) {

    int sensorValue =
      analogRead(sensorPins[i]);

    // ======================================
    // SERIAL DEBUG
    // ======================================

    Serial.print("Seat ");
    Serial.print(i + 1);
    Serial.print(" = ");
    Serial.println(sensorValue);

    // ======================================
    // OCCUPIED LOGIC
    // ======================================

    if (sensorValue > threshold) {

      // LED ON
      digitalWrite(
        ledPins[i],
        HIGH
      );

      occupiedSeats++;

      // SEND STATUS TO BLYNK
      Blynk.virtualWrite(
        i,
        "Occupied"
      );

      Blynk.virtualWrite(
       dashboardLedPins[i],
        0
      );     
    }

    // ======================================
    // EMPTY LOGIC
    // ======================================

    else {

      // LED OFF
      digitalWrite(
        ledPins[i],
        LOW
      );

      // SEND STATUS TO BLYNK
      Blynk.virtualWrite(
        i,
        "Empty"
      );

      Blynk.virtualWrite(
        dashboardLedPins[i],
        255
      );
    }
  }

  // ======================================
  // OCCUPANCY CALCULATION
  // ======================================

  int occupancyPercentage =
    (occupiedSeats * 100)
    / totalSeats;

  int remainingSeats =
    totalSeats - occupiedSeats;

  // ======================================
  // SERIAL OUTPUT
  // ======================================

  Serial.print("Occupied Seats = ");
  Serial.println(occupiedSeats);

  Serial.print("Remaining Seats = ");
  Serial.println(remainingSeats);

  Serial.print("Occupancy = ");
  Serial.print(occupancyPercentage);
  Serial.println("%");

  // ======================================
  // SEND TO BLYNK
  // ======================================

  // Occupancy %
  Blynk.virtualWrite(
    V4,
    occupancyPercentage
  );

  // Remaining Seats
  Blynk.virtualWrite(
    V6,
    remainingSeats
  );

  // ======================================
  // WARNING SYSTEM
  // ======================================

  // WARNING jika occupancy >= 80%

  if (occupancyPercentage >= 80) {

    // WARNING TEXT
    Blynk.virtualWrite(
      V5,
      "WARNING: BUS ALMOST FULL"
    );

    Serial.println(
      "WARNING: BUS ALMOST FULL"
    );

    // ======================================
    // BUZZER HANYA SEKALI
    // ======================================

    if (!warningTriggered) {

      // bunyi 2 detik
      tone(buzzerPin, 1000);
      Blynk.virtualWrite(V7, 1);
      
      delay(2000);

      noTone(buzzerPin);
      Blynk.virtualWrite(V7, 0);

      // tandai warning sudah aktif
      warningTriggered = true;
    }
  }

  // ======================================
  // NORMAL CONDITION
  // ======================================

  else {

    // reset warning
    warningTriggered = false;

    noTone(buzzerPin);

    Blynk.virtualWrite(
      V5,
      "Bus Capacity Normal"
    );
  }

  Serial.println("----------------------");
}

// ======================================
// SETUP
// ======================================

void setup() {

  Serial.begin(115200);

  // ======================================
  // LED SETUP
  // ======================================

  for (int i = 0; i < totalSeats; i++) {

    pinMode(
      ledPins[i],
      OUTPUT
    );

    digitalWrite(
      ledPins[i],
      LOW
    );
  }

  // ======================================
  // BUZZER SETUP
  // ======================================

  pinMode(
    buzzerPin,
    OUTPUT
  );

  digitalWrite(
    buzzerPin,
    LOW
  );

  // ======================================
  // CONNECT TO BLYNK
  // ======================================

  Blynk.begin(
    BLYNK_AUTH_TOKEN,
    ssid,
    pass
  );

  // ======================================
  // TIMER LOOP
  // ======================================

  timer.setInterval(
    500L,
    monitorSeats
  );

  Serial.println("SYSTEM READY");
}

// ======================================
// MAIN LOOP
// ======================================

void loop() {

  Blynk.run();
  timer.run();
}