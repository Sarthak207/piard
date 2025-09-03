# Project 2: Raspberry Pi ↔ Arduino Serial Communication

This project demonstrates how to communicate between **Arduino Uno** and **Raspberry Pi** using **Serial (UART over USB)**.  
The Raspberry Pi sends commands to the Arduino, and Arduino controls its **built-in LED** accordingly.

---

## 🔧 Hardware Setup

- **Arduino Uno** connected to **Raspberry Pi** via USB cable.
- No external components needed (using `LED_BUILTIN`).

---

## 📂 Project Structure

```
piard/
├── src/
│   ├── ledBlink/
│   │   └── ledBlink.cpp
│   └── serialComm/
│       ├── serialComm.cpp    # Arduino code
│       └── raspberryPi/
│           └── serialtest.py # Raspberry Pi code
└── platformio.ini
```

---

## ⚙️ Arduino Code (`serialComm.cpp`)

- Reads serial input from Raspberry Pi.
- Turns LED **ON** when receiving `'1'`.
- Turns LED **OFF** when receiving `'0'`.
- Echoes back the response via `Serial.println()`.

---

## 🐍 Raspberry Pi Code (`serialtest.py`)

- Opens serial port (`/dev/ttyACM0` or `/dev/ttyUSB0`).
- Sends user input (`1` or `0`) to Arduino.
- Reads Arduino’s response and prints it.

---

## 🛠️ Challenges & Fixes

### 1. Build Error (`undefined reference to 'setup' / 'loop'`)

- **Cause:** Wrong `src_filter` in `platformio.ini` (was excluding the actual `.cpp` file).
- **Fix:** Adjusted config:
  ```ini
  [env:serialComm]
  platform = atmelavr
  board = uno
  framework = arduino
  build_src_filter = +<serialComm/serialComm.cpp>
  ```

---

### 2. Serial Port Not Found (`/dev/ttyACM0` missing)

- **Cause:** Wrong device path in Python (`dev/ttyACM0` instead of `/dev/ttyACM0`).
- **Fix:** Corrected path, verified using:
  ```bash
  ls /dev/ttyACM* /dev/ttyUSB*
  ```

---

### 3. pyserial Installation Issue (PEP 668 restriction)

- **Cause:** Raspberry Pi OS blocked system-wide pip install.
- **Fix Options:**
  - **System install:**
    ```bash
    sudo apt install python3-serial
    ```
  - **OR virtual environment:**
    ```bash
    python3 -m venv venv
    source venv/bin/activate
    pip install pyserial
    ```

---

## ✅ How to Run

**Upload Arduino code with PlatformIO:**
```bash
pio run -e serialComm -t upload
```

**Run Python script on Raspberry Pi:**
```bash
python3 serialtest.py
```
Enter `1` or `0` to toggle Arduino LED.