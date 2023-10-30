#ifndef RECEIVER_H
#define RECEIVER_H
#include "SlidingWindow.h"


class Receiver : public SlidingWindow {
  public:
    Receiver();
    
    
  private:
    //sequence number of the last in sequence frame received
    int lastack;
};

#endif