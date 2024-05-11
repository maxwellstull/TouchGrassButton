#include "USB.h"
#include "USBHIDKeyboard.h"
#include "FSM.h"
USBHIDKeyboard Keyboard;

bool pressed;
bool this_press_applied;
int delay_ms;
FSM fsm;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();
  USB.begin();

  delay_ms = 50;

  fsm.init();
  fsm.set_recharge(300);
  fsm.assignOnPressBehavior([Keyboard]() {Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_F4); delay(10); Keyboard.releaseAll();});

}

void loop() {
  if(digitalRead(2) == LOW)
  {
    //
      fsm.press();
    //button pressed
//    Keyboard.press(KEY_LEFT_ALT);nnnnnn
//    Keyboard.press(KEY_F4);
  }
  else
  {
    //button not pressed
  }
  delay(delay_ms);
  fsm.update(delay_ms);
}


