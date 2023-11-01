#ifndef SENDER_H
#define SENDER_H
#include "SlidingWindow.h"

class Sender : public SlidingWindow {
  public:
    Sender(int size);
    //bool req(int SN);
    int retransmit();
    void acknowledge(int SN); 
   


  private:
    
};

#endif
