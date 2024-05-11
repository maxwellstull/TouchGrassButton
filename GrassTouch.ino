#include "USB.h"
#include "USBHIDKeyboard.h"
#include "FSM.h"
USBHIDKeyboard Keyboard;

bool pressed;
bool this_press_applied;
int delay_ms;
FSM fsm;

void setup() {
  // Set pinmode and begin keyboard stuff
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();
  USB.begin();
  // Loop frequency
  delay_ms = 50;
  // Create finite state machine
  fsm.init();
  fsm.set_recharge(300);
  fsm.assignOnPressBehavior([Keyboard]() {Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_F4); delay(10); Keyboard.releaseAll();});
}

void loop() {
  if(digitalRead(2) == LOW)
  {
      fsm.press();
  }
  else
  {
    //button not pressed, do nothing :)
  }
  delay(delay_ms);
  fsm.update(delay_ms);
}


