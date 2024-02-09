// encoders
// mode switcher, menu
void encoderOneProcess() {
  enc1.tick();
  if(menuMode == 0) {
    if (enc1.left()) {
      if (currentMode > 0) {
        currentMode--;
        if (currentMode < 0) {
          currentMode = 0;
        }
      }
      EEPROM.put(1, currentMode);
      drawHomeScreen(101);
      drawHomeScreen(-1);
      Serial.println("enc 1 left");
    }
    if (enc1.right()) {
      if (currentMode < MODES - 1) {
        currentMode++;
        if (currentMode > MODES - 1) {
          currentMode = MODES - 1;
        }
      }
      EEPROM.put(1, currentMode);
      drawHomeScreen(102);
      drawHomeScreen(-1);
      Serial.println("enc 1 right");
    }
    if (enc1.click()) {
      menuMode = 1;
      drawMenu(0);
    }
  } else {
    if (enc1.click()) {
      menuMode = 0;
      drawHomeScreen(-1);
      ledScenarioSwitcher();
    }
    if (enc1.left()) {
      arrowPos--;
      if (arrowPos < 0) arrowPos = 0;
      drawMenu(0);
    }
    if (enc1.right()) {
      arrowPos++;
      if (arrowPos >= 4) arrowPos = 3;
      drawMenu(0);
    }
    if (enc1.rightH()) {
      switch (arrowPos) {
        case 0: val1++; val1 = constrain(val1, 0, 3); EEPROM.put(2, val1);
          break;
        case 1: val2++; val2 = constrain(val2, 1, 50); EEPROM.put(3, val2);
          break;
        case 2: val3++; val3 = constrain(val3, 0, 1); EEPROM.put(4, val3);
          break;
        case 3: val4++; val4 = constrain(val4, 0, 1); EEPROM.put(5, val4);
          break;
      }
      drawMenu(0);
    }
    if (enc1.leftH()) {
      switch (arrowPos) {
        case 0: val1--; val1 = constrain(val1, 0, 3); EEPROM.put(2, val1);
          break;
        case 1: val2--; val2 = constrain(val2, 1, 50); EEPROM.put(3, val2);
          break;
        case 2: val3--; val3 = constrain(val3, 0, 1); EEPROM.put(4, val3);
          break;
        case 3: val4--; val4 = constrain(val4, 0, 1); EEPROM.put(5, val4);
          break;
      }
      drawMenu(0);
    }
  }
}

// media controller
void encoderTwoProcess(){
  enc2.tick();
   if (enc2.click()){Consumer.write(MEDIA_PLAY_PAUSE);drawHomeScreen(203);drawHomeScreen(-1);}          // Клик по кнопке - playpause
   else if (enc2.right()){Consumer.write(MEDIA_VOLUME_UP);drawHomeScreen(202);drawHomeScreen(-1);}           // Вращение вправо - vol+
   else if (enc2.left()){Consumer.write(MEDIA_VOLUME_DOWN);drawHomeScreen(201);drawHomeScreen(-1);}        // Вращение влево - vol-
   else if (enc2.rightH()){Consumer.write(MEDIA_NEXT);drawHomeScreen(205);drawHomeScreen(-1);}  // Вращение вправо с нажатием - next track
   else if (enc2.leftH()){Consumer.write(MEDIA_PREV);drawHomeScreen(204);drawHomeScreen(-1);}   // Вращение влево с нажатием - previous track
}