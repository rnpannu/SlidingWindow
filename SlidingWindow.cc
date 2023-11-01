#include <iostream>
#include <vector>
#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(int max) {
    maxSN = max;
}

void SlidingWindow::setWinSize(int wSize){
    // Invalid
    if (wSize > maxSN) {
        std::cout << "Size cannot be greater than integer range" << std::endl;
        return;
    }
    /*Expanding Window 
    for (int i = window.size(); i < wSize; ++i) {
        window.push_back(i);
        unacknowledgedNums.push_back(i % windowMax);
    }
    //Note: Constricting window check later
    */
    windowSize = wSize;
}

bool SlidingWindow::canAddNew() {
    // Available space in window
    if (window.size() < windowSize){
        return true;
    } else if (window.size() == windowSize){
        for (int i = 0; i < acknowledgedNums.size(); i++) {
            if (acknowledgedNums[i] == window[0]) {
                return true;
            }
    }
    }
   
    return false;
}

int SlidingWindow::addNew() {
    if (canAddNew()) {
        int newSN;
        // Size available to expand
        if (window.size() < windowSize){
            if (window.size() == 0){
                newSN = 0;
            } else{
                newSN = (window.back() + 1) % maxSN;
            }
            
        // Size not available but can slide
        } else {
            newSN = (window.back() + 1) % maxSN;
            window.erase(window.begin());
            acknowledgedNums.erase(acknowledgedNums.begin());
        }
        window.push_back(newSN);
        unacknowledgedNums.push_back(newSN);
        return newSN;
    }
    return -1;
}

int SlidingWindow::nrSeqInWin() {
    return unacknowledgedNums.size();
}
