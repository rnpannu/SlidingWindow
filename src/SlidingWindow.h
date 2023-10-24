#ifndef SLIDING_WINDOW_H
#define SLIDING_WINDOW_H

class SlidingWindow {
  public:
    SlidingWindow();
    void setWindow(int wSize) {window = wSize;}
    bool canAddNew();
    int addNew();
    int nrSeqInWin();

  protected:
    int window = 0;
};

#endif