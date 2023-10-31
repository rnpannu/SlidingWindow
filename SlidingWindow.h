#ifndef SLIDING_WINDOW_H
#define SLIDING_WINDOW_H
#include <vector>

class SlidingWindow {
  public:
    SlidingWindow(int max);
    void setWinSize(int wSize);
    void setMax(int max);
    // Can sliding window be incremented
    bool canAddNew();
    // Incrementing sliding window
    int addNew();
    int nrSeqInWin();
    void acknowledge(int sequence);

  protected:
    int windowMax = 0;
    int windowSize = 0;
    std::vector<int> acknowledgedNums;
    std::vector<int> unacknowledgedNums;
    std::vector<int> window;

};

#endif