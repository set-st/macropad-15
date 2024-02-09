void drawMenu(int page){
  oled.clear();
  oled.setCursor(0, 0);
  oled.print("Settings");
  oled.setCursor(1, 2);
  oled.print("  Light mode: ");
  oled.print(val1);
  oled.setCursor(1, 3);
  oled.print("  Brightness: ");
  oled.print(val2);
  oled.setCursor(1, 4);
  oled.print("  System: ");
  if(val3 == 1){oled.print("macOS");}else{oled.print("Windows");}
  oled.setCursor(1, 5);
  oled.print("  Multimedia: ");
  oled.print(val4);
  // выводим стрелку
  switch (arrowPos) {
    case 0: oled.setCursor(0, 2);
      break;
    case 1: oled.setCursor(0, 3);
      break;
    case 2: oled.setCursor(0, 4);
      break;
    case 3: oled.setCursor(0, 5);
      break;
  }
  oled.print(">");
  oled.update();
}

void drawHomeScreen(int buttonId){
  oled.clear();
  if(currentMode > MODES){
    currentMode = MODES-1;
    EEPROM.put(1, currentMode);
  }

  oled.setCursorXY(3,5);
  oled.println(modemap[currentMode][0]);
  oled.roundRect(0, 0, 100, 15, OLED_STROKE);

  // draw buttons
  int startY = 20;
  int startX = 0;
  int sizeX = 16;
  int sizeY = 11;
  for(int i=0; i<15; i++){
    if(buttonId == i){
      int pressed = startY+1;
      oled.roundRect(startX, pressed, startX+sizeX, pressed+sizeY, OLED_STROKE);
      oled.line(startX+3, pressed+(sizeY-2), startX+(sizeX-3), pressed+(sizeY-2));
      oled.dot(startX+2, pressed+(sizeY-3));
      oled.dot(startX+(sizeX-2), pressed+(sizeY-3));
    }
    else{
      oled.line(startX+3, startY+(sizeY-2), startX+(sizeX-3), startY+(sizeY-2));
      oled.dot(startX+2, startY+(sizeY-3));
      oled.dot(startX+(sizeX-2), startY+(sizeY-3));
      oled.roundRect(startX, startY, startX+sizeX, startY+sizeY, OLED_STROKE);
    }
    startX = startX + sizeX + 5;
    if(i == 4 || i == 9){
      startY = startY + sizeY + 5;
      startX = 0;
    }
  }

  // encoder 1
  int e1x = 117;
  int e1y = 10;
  oled.setCursorXY(e1x-2, e1y-3);
  switch(buttonId){
    case 101:
      oled.print("<");
      break;
    case 102:
      oled.print(">");
      break;
    case 103:
      oled.circle(e1x, e1y, 8, OLED_STROKE);
      break;
  }
  oled.circle(e1x, e1y, 10, OLED_STROKE);
  oled.circle(e1x, e1y, 8, OLED_STROKE);

  // encoder 2
  int e2x = 117;
  int e2y = 38;
  oled.setCursorXY(e2x-2, e2y-3);
  switch(buttonId){
    case 201: // left
      oled.print("<");
      break;
    case 202: // right
      oled.print(">");
      break;
    case 203: // push
      oled.circle(e2x, e2y, 8);
      break;
    case 204: // left with push
      oled.circle(e2x, e2y, 8);
      oled.textMode(BUF_SUBTRACT);
      oled.setCursorXY(e2x-2, e2y-3);
      oled.print("<");
      oled.textMode(BUF_ADD);
      break;
    case 205: // right with push
      oled.circle(e2x, e2y, 8);
      oled.textMode(BUF_SUBTRACT);
      oled.setCursorXY(e2x-2, e2y-3);
      oled.print(">");
      oled.textMode(BUF_ADD);
      break;
  }
  oled.circle(e2x, e2y, 10, OLED_STROKE);
  oled.circle(e2x, e2y, 8, OLED_STROKE);
  oled.update();
}

// sibple draw a heart beat
int heartStatus = 0;
void serviceRow(){
  if(menuMode == 0){
    if(heartStatus == 0){
      oled.circle(117, 60, 3);
      heartStatus = 1;
    }else{
      oled.circle(117, 60, 3, OLED_CLEAR);
      heartStatus = 0;
    }
    oled.update();
  }
}