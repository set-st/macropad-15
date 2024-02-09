#include <EncButton.h>
#include <EEPROM.h>

//#include <Keyboard.h>
//#include <KeyboardLayout.h>
#include <HID-Project.h>

const int ROW1PIN = A0;
const int ROW2PIN = A1;
const int ROW3PIN = A2;

#define EE_RESET 14     // любое число 0-255. Измени, чтобы сбросить настройки

#define NUMLEDS 15
#define STRIP_PIN 5     // пин ленты
#define COLOR_DEBTH 3

#include <microLED.h>
microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB> strip;

#define USE_MICRO_WIRE
#include <GyverOLED.h>
GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_I2C> oled;

// row1
VirtButton row1b1;
VirtButton row1b2;
VirtButton row1b3;
// row2
VirtButton row2b1;
VirtButton row2b2;
VirtButton row2b3;

// encoders
EncButtonT<7, 8, 6> enc1;
EncButtonT<14, 16, 15> enc2;

// mapping
#define MODES 2
const char * modemap[MODES][1] = {
  // mode name for display
  {"Default"},
  {"Game 1"},
};

int currentMode = 0;
int menuMode = 0;

// переменные
int val1 = 1; // led mode
int val2 = 10; // led brightness
int val3 = 0; // 1 mac or 0 win
int val4 = 1; // multimedia encoder

int8_t arrowPos = 0;  // позиция стрелки

void setup() {
  oled.init();
  oled.clear();
  pinMode(ROW1PIN, INPUT_PULLUP);
  pinMode(ROW2PIN, INPUT_PULLUP);
  pinMode(ROW3PIN, INPUT_PULLUP);
  if (EEPROM.read(0) != EE_RESET) {   // первый запуск
    EEPROM.write(0, EE_RESET);
    EEPROM.put(1, currentMode);
    EEPROM.put(2, val1);
    EEPROM.put(3, val2);
    EEPROM.put(4, val3);
    EEPROM.put(5, val4);
  }
  EEPROM.get(1, currentMode);
  EEPROM.get(2, val1);
  EEPROM.get(3, val2);
  EEPROM.get(4, val3);
  EEPROM.get(5, val4);
  Serial.begin(115200);
  //Keyboard.begin();
  Consumer.begin();
  oled.home();
  oled.println("Started");
  oled.update();
  strip.clear();
  strip.show();
  drawHomeScreen(-1);
  ledScenarioSwitcher();
}

//buttons
void button(int id){
  Serial.print("Starting press key: ");
  Serial.println(id);
  Serial.print("Mode: ");
  Serial.println(currentMode);
  drawHomeScreen(id);
  fireLed(id);
  switch(currentMode){
    case 0:
      layout1(id);
      break;
    case 1:
      layout2(id);
      break;
  }
  drawHomeScreen(-1);
}

void loop() {
  static uint32_t heartBeat = millis();
  if (millis() - heartBeat >= 1000) {
    heartBeat = millis();
    serviceRow();
  }

  static uint32_t timer = millis();   // Миллис - таймер (НЕ DELAY!!!)
  if (millis() - timer >= 10) {       // Каждые 1000 мс
    timer = millis();
    encoderOneProcess();
    encoderTwoProcess();

    int r1 = analogRead(ROW1PIN);
    int r2 = analogRead(ROW2PIN);
    int r3 = analogRead(ROW3PIN);

    row1b1.tick(r1 < 17 && r1 > 0);
    row1b2.tick(r2 < 17 && r2 > 0);
    row1b3.tick(r3 < 17 && r3 > 0);

    row2b1.tick(r1 < 45 && r1 > 35);
    row2b2.tick(r2 < 45 && r2 > 35);
    row2b3.tick(r3 < 45 && r3 > 35);

    //Serial.println(r1);

    // row 1
    if (row1b1.click()) {
      button(0);
    }

    if (row1b2.click()) {
      button(1);
    }

    if (row1b3.click()) {
      button(2);
    }

    // row 2
    if (row2b1.click()) {
      button(3);
    }

    if (row2b2.click()) {
      button(4);
    }

    if (row2b3.click()) {
      button(5);
    }
  }
}
