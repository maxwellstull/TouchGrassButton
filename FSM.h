#ifndef FSM_H
#define FSM_H

#include <functional>


class FSM
{
  public:
    enum State 
      {
        POLLING = 0,
        RECHARGE = 1,
      };
  private:
    double recharge_ms;
    double recharge_timer;
    State current_state;
    std::function<void()> onPressFunction;

  public:
  void set_recharge(double amnt)
  {
    recharge_ms = amnt;
  }
  void init()
  {
    recharge_timer = recharge_ms;
    current_state = State::POLLING;

  }
  void press()
  {
    switch(current_state)
    {
      case(State::POLLING):
      {
        current_state = State::RECHARGE; 
        recharge_timer = recharge_ms;
        onPressFunction();
        break;
      }
      case(State::RECHARGE):
      {
        recharge_timer = recharge_ms;
        break;
      }
      default:
      {
        break;
      }
    }
  }
  void assignOnPressBehavior(std::function<void()> funk)
  {
    onPressFunction = funk;
  }
  void update(double time_ms)
  {
    if(current_state == State::RECHARGE)
    {    
      recharge_timer -= time_ms;
      if(recharge_timer <= 0)
      {
        current_state = State::POLLING;
      }
    }
  }
  int getState()
  {
    return current_state;
  }

};



#endif