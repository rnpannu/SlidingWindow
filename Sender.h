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

    /***
     * @brief Acknowledges that a sequence number has been sent and places it in
     * the acknowledgedNums vector. Also removes from unacknowledgedNums if
     * present there.
     * @param: Takes in the sequence number of the acknowledged data
    */
    void acknowledge(int SN); 
   


  private:
    
};

#endif
