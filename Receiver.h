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
    
    /***
     * @brief Adds the acknowledged sequence number to the 
     *  acknowledgeNums vector, then removes that sequence 
     *  number from the unacknowledged frames if it exists 
     *  there
     * @param sequence: The sequence number that is being 
     *  acknowledged 
    */
    void acknowledge(int SN); 
    /***
     * @brief Retransmits data that went unacknowledged
     * @return: The sequence number that is being of the data being
     * retransmitted
     * 
    */
    int retransmit();
    
    
  private:
    // Sequence number of the last in sequence frame received
    int lastAck;
};

#endif
