#ifndef SENDER_H
#define SENDER_H
#include "SlidingWindow.h"

class Sender : public SlidingWindow {
  public:
    /***
     * @brief Constructor
     * @param size: window size
    */
    Sender(int size);
    //bool req(int SN);

    /***
     * @brief Retransmits data that has gone unacknowledged.
     * @return Returns the sequence number of the unacknowledged data being transmitted
    */
    int retransmit();
   


  private:
    
};

#endif
