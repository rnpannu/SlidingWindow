#ifndef RECEIVER_H
#define RECEIVER_H
#include "SlidingWindow.h"


class Receiver : public SlidingWindow {
  public:
    /***
     * @brief Constructor
     * @param max: max window size
    */
    Receiver(int max);
    
    void acknowledge(int SN); 
    
    
  private:
    // Sequence number of the last in sequence frame received
    int lastAck;
};

#endif
