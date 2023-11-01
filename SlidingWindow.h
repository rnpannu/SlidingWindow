#ifndef SLIDING_WINDOW_H
#define SLIDING_WINDOW_H
#include <vector>

class SlidingWindow {
  public:
    /***
     * @brief Constructor
     * @param max: max window size
    */
    SlidingWindow(int max);
    
    /***
     * @brief Sets the windowSize of the SlidingWindow object
     * @param wSize: size of window
    */
    virtual void setWinSize(int wSize);

    /***
     * @brief Can the sliding window be incremented
     * @return true: sliding window can be incremented
     *         false: slidinw window cannot be incremented
    */
    virtual bool canAddNew();
    
    /***
     * @brief Increment the sliding window
     * @return -1: Sliding window cannot be incremented
     *      newSN: The sequence number of the added frame
    */
    virtual int addNew();

    /***
     * @brief Returns the number of frames in the sliding 
     *  window
     * @return The size of unacknowledgedNums 
    */
    virtual int nrSeqInWin();

    /***
     * @brief Adds the acknowledged sequence number to the 
     *  acknowledgeNums vector, then removes that sequence 
     *  number from the unacknowledged frames if it exists 
     *  there
     * @param sequence: The sequence number that is being 
     *  acknowledged 
    */
    virtual void acknowledge(int sequence);

    virtual int retransmit() = 0;


  protected:
    // Maximum size of the sliding window
    int windowSize = 0;

    // Contains all sequence numbers that have been 
    // acknowledged
    std::vector<int> acknowledgedNums;

    // Contains all sequence numbers that have been 
    // unacknowledged
    std::vector<int> unacknowledgedNums;

    // The sliding window itself with the corresponding data 
    // stored inside
    std::vector<int> window;

    int maxSN;

};

#endif
