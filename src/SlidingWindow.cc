#include <iostream>
#include <vector>
#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(int max) {

}

bool SlidingWindow::canAddNew() {
    if (windowSize < windowMax) {
        return true;
    }
    for (int i = 0; i < acknowledgedNums.size(); i++) {
        if (acknowledgedNums[i] == window[0]) {
            return true;
        }
    }
    return false;
}

int SlidingWindow::addNew() {
    if (canAddNew) {
        int newSN = (window[window.end() - 1] + 1) % windowMax;
        if (windowSize < windowMax) {
            
            window.push_back(newSN);
            
        } else {
            window.erase(window.begin(), window.end(), 0);
            window.push_back(newSN);

        }
        return newSN;
    } else {
        return -1;
    }
    return -1;
}