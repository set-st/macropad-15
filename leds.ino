void fireLed(int ledId){
  mData prevcolor = strip.get(ledId);
  strip.set(ledId, mRGB(0, 0, 255)); 
  strip.fade(ledId, 60);
  strip.show();
  delay(20);
  strip.set(ledId, prevcolor);
  strip.fade(ledId, val2); // restore brightness from settings
  strip.show();
  Serial.print("Fired led: ");
  Serial.println(ledId);
  ledScenarioSwitcher();
}

void ledScenarioSwitcher(){
  switch(val1){
    case 0:
      ledScenario1();
      break;
    case 1:
      ledScenario2();
      break;
    case 2:
      ledScenario3();
      break;
    case 3:
      ledScenario4();
      break;
  }
}

void ledScenario1(){
  strip.setBrightness(val2);
  strip.fill(mRGB(255, 0, 0));
  strip.show();
}

void ledScenario2(){
  strip.setBrightness(val2);
  for (int i = 0; i < NUMLEDS; i++) strip.set(i, mWheel8(i * 255 / NUMLEDS));
  strip.show();
}

void ledScenario3(){
  strip.setBrightness(val2);
  strip.fill(mRGB(0, 255, 0));
  strip.show();
}

void ledScenario4(){
  strip.setBrightness(val2);
  strip.fill(mRGB(255, 255, 255));
  strip.show();
}