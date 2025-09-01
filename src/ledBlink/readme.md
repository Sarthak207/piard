📘 Project 1: Blink LED (Arduino + PlatformIO)
🎯 Objective

Get started with Arduino programming using PlatformIO.

Blink the built-in LED on Arduino Uno (LED_BUILTIN, pin 13).

Understand the setup/loop structure, digital output, and delays.

🧠 Theory
🔹 What is LED_BUILTIN?

A predefined constant in Arduino framework.

On Arduino Uno → it maps to pin 13.

The onboard LED is connected to pin 13 via a resistor.

🔹 Arduino Program Structure

setup() → runs once after reset or power-up.

loop() → runs repeatedly forever.

void setup() {
  // runs once
}

void loop() {
  // runs repeatedly
}

🔹 Digital I/O

pinMode(pin, OUTPUT) → configure pin as an output.

digitalWrite(pin, HIGH) → set pin HIGH (5V).

digitalWrite(pin, LOW) → set pin LOW (0V).

🔹 Timing

delay(ms) pauses the CPU for given milliseconds.

Example: delay(1000) → 1 second pause.

⚙️ Code

File: src/main.cpp

#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // configure LED pin as output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // LED ON
  delay(500);                      // wait 0.5 sec
  digitalWrite(LED_BUILTIN, LOW);  // LED OFF
  delay(500);                      // wait 0.5 sec
}

▶️ How to Run

Connect Arduino Uno to your PC via USB.

Create a PlatformIO project (board = uno).

Place code in src/main.cpp.

Upload with:

pio run -t upload


The onboard LED should blink at 1 Hz (ON 0.5s, OFF 0.5s).

✅ Learning Outcomes

Setup Arduino Uno with PlatformIO.

Wrote your first Arduino sketch.

Understood digital output control.

Learned how delays affect execution timing.

🔜 Next Step (Project 2)

Control LED blink rate from Raspberry Pi via Serial Communication.

This introduces Pi ↔ Arduino interaction.