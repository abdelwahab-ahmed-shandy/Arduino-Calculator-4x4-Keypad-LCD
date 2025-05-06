/*
General Description:
This program is a simple calculator using a 4x4 keypad and an I2C LCD screen. It allows the user to:

- Enter two numbers using the keypad.
- Choose an operation (addition, subtraction, multiplication, division).
- Display the result when pressing '=', or clear everything with 'C'.
*/

#include <Keypad.h>              // Library for keypad handling
#include <LiquidCrystal_I2C.h>   // Library for I2C-based LCD
#include <Wire.h>                // I2C communication library

// Define number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Keypad button layout
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'C'},
  {'*', '0', '=', '/'}
};

// Define Arduino pins connected to keypad rows and columns
byte rowPins[ROWS] = {9, 8, 7, 6};  // Rows connected to pins 9 to 6
byte colPins[COLS] = {5, 4, 3, 2};  // Columns connected to pins 5 to 2

// Create keypad object
/*
This tells the library how the keypad is wired and what keys are where
by linking the key layout with the actual Arduino pins.
*/
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Create LCD object (I2C address 0x27, 16 columns × 2 rows)
// This initializes the LCD using the I2C protocol
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables to store input numbers, result, and operator
boolean firstNumState = true;  // True when entering the first number
String firstNum = "";          // Stores the first number
String secondNum = "";         // Stores the second number
float result = 0.0;            // Calculation result
char operatr = ' ';            // Operation (+, -, *, /)

// Setup function (runs once at start)
void setup() {
  lcd.init();                // Initialize LCD
  lcd.backlight();           // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Arduino Calculator");  // Welcome message
  lcd.setCursor(0, 1);
  lcd.print("by Abdelwahab Shandy");  // Creator's name
  delay(1000);               // Wait for 1 second
  scrollDisplay();           // Display animated message
  clr();                     // Clear screen and prepare for input
}

// Main loop
void loop() {
  char newKey = myKeypad.getKey(); // Read pressed key

  // If a number key (0 to 9) is pressed
  if (newKey != NO_KEY && (newKey >= '0' && newKey <= '9')) {
    if (firstNumState == true) {
      firstNum += newKey;      // Append to the first number
      lcd.print(newKey);
    } else {
      secondNum += newKey;     // Append to the second number
      lcd.print(newKey);
    }
  }

  // If an operator key is pressed (+, -, *, /)
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/')) {
    if (firstNumState == true) {
      operatr = newKey;        // Store the operation
      firstNumState = false;   // Switch to entering second number
      lcd.setCursor(15, 0);    // Display operator at top-right
      lcd.print(operatr);
      lcd.setCursor(5, 1);     // Move cursor to second number input
    }
  }

  // If '=' key is pressed, perform calculation
  if (newKey != NO_KEY && newKey == '=') {
    if (operatr == '+') result = firstNum.toFloat() + secondNum.toFloat();
    if (operatr == '-') result = firstNum.toFloat() - secondNum.toFloat();
    if (operatr == '*') result = firstNum.toFloat() * secondNum.toFloat();
    if (operatr == '/') result = firstNum.toFloat() / secondNum.toFloat();

    // Display the equation and result
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(operatr);
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(result);

    firstNumState = true;  // Reset for new calculation
  }

  // If 'C' key is pressed, clear everything
  if (newKey != NO_KEY && newKey == 'C') {
    clr();  // Call clear function
  }
}

// Function to scroll welcome message on LCD
void scrollDisplay() {
  for (int i = 0; i < 3; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  delay(1000);
  for (int i = 0; i < 3; i++) {
    lcd.scrollDisplayRight();
    delay(300);
  }
  delay(2000);
}

// Function to clear screen and reset variables
void clr() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1st: ");          // Label for first number
  lcd.setCursor(12, 0);
  lcd.print("op ");            // Label for operation
  lcd.setCursor(0, 1);
  lcd.print("2nd: ");          // Label for second number
  lcd.setCursor(5, 0);         // Set cursor for first number input

  // Reset all variables
  firstNum = "";
  secondNum = "";
  result = 0;
  operatr = ' ';
}

//Abdelwahab Shandy .