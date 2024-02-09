void layout1(int key){
  switch(key){
    case 0:
      Keyboard.print("a");
      break;
    case 1:
      Keyboard.print("b");
      break;
    case 2:
      Keyboard.print("c");
      break;
    case 3:
      Keyboard.print("d");
      break;
    case 4:
      Keyboard.print("e");
      break;
    case 5:
      Keyboard.print("f");
      break;
    case 6:
      Keyboard.print("j");
      break;
    case 7:
      Keyboard.print("h");
      break;
    case 8:
      Keyboard.print("k");
      break;
    case 9:
      Keyboard.print("l");
      break;
    case 10:
      Keyboard.print("m");
      break;
    case 11:
      Keyboard.print("n");
      break;
    case 12:
      Keyboard.print("o");
      break;
    case 13:
      Keyboard.print("p");
      break;
    case 14:
      Keyboard.print("w");
      break;
  }
}

void layout2(int key){
  switch(key){
    case 0:
      if(val3 == 1){
        Keyboard.press(KEY_LEFT_GUI);  
      }else{
        Keyboard.press(KEY_LEFT_ALT);
      }
      delay(100);
      Keyboard.press('c');
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      break;
    case 1:
      if(val3 == 1){
        Keyboard.press(KEY_LEFT_GUI);  
      }else{
        Keyboard.press(KEY_LEFT_ALT);
      }
      delay(100);
      Keyboard.press('v');
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      break;
    case 2:
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_ARROW);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      break;
    case 3:
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      break;
    case 4:
      Keyboard.print("e");
      break;
    case 5:
      Keyboard.print("f");
      break;
    case 6:
      Keyboard.print("j");
      break;
    case 7:
      Keyboard.print("h");
      break;
    case 8:
      Keyboard.print("k");
      break;
    case 9:
      Keyboard.print("l");
      break;
    case 10:
      Keyboard.print("m");
      break;
    case 11:
      Keyboard.print("n");
      break;
    case 12:
      Keyboard.print("o");
      break;
    case 13:
      Keyboard.print("p");
      break;
    case 14:
      Keyboard.print("w");
      break;
  }
}