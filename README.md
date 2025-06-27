# Arduino Calculator - 4x4 Keypad & I2C LCD

A simple calculator built using an Arduino Uno, a 4x4 keypad, and an I2C LCD screen. This project allows users to input two numbers, choose a basic operation (+, -, *, /), and view the result on the LCD.
It was created as part of a university project, where I contributed to the code development and logic design.

---

## 🛠Features

- Input two numbers using a 4x4 keypad.
- Choose operation: `+`, `-`, `*`, `/`.
- Display result when `=` is pressed.
- Clear screen with `C` button.
- Scrolling welcome message on startup.

---

## 📷 Hardware Used

| Component | Description |
|---------------------------------------|----------------------------------------------------|
| Arduino Uno | Microcontroller board |
| 4x4 Keypad | For inputting numbers and operations |
| I2C LCD (16x2) | To display input and results |
| Jumper Wires & Breadboard | For connections |

---

## 📌 Circuit Overview

- **Keypad Rows (R1–R4)** connected to Arduino pins `9, 8, 7, 6`
- **Keypad Columns (C1–C4)** connected to Arduino pins `5, 4, 3, 2`
- **I2C LCD** ​​connected via A4 (SDA) and A5 (SCL)

> Note: The I2C address used in the code is `0x27`. If your LCD uses a different address, modify it accordingly.

---

## 🚀How It Works

1. Power the Arduino.
2. A welcome message scrolls on the LCD.
3. Enter the first number via keypad.
4. Press the operation key (`+`, `-`, `*`, or `/`).
5. Enter the second number.
6. Press `=` to calculate and display the result.
7. Press `C` to clear the screen and reset.

---

## 📂 Project Files

- `Arduino_Calculator.ino`: Main code
- `README.md`: Project documentation

---

## 🙋‍♂️ Contributions

This project was implemented in collaboration with a university colleague.
I contributed to:
- Writing and structuring the Arduino code
-Designing the interaction logic
- Testing and debugging the calculator functionality

---

## 📸 Demo (Optional)

If you have a picture or video of the setup, you can embed it here:

```markdown
![Project Demo](/main/images/Arduino_Calculator-3.jpg)

```
---
## 🌐 Let's Connect

[![LinkedIn](https://img.shields.io/badge/Followers-4000-blue?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/abdelwahab-ahmed-shandy/)
[![Medium](https://img.shields.io/badge/Followers-25-brightgreen?style=for-the-badge&logo=medium&logoColor=white)](https://medium.com/@abdelwahabshandy)
[![GitHub](https://img.shields.io/badge/GitHub-333333?style=for-the-badge&logo=github&logoColor=white)](https://github.com/abdelwahab-shandy)
