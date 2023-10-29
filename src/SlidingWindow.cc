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

int SlidingWindow::nrSeqInWin() {
    return unacknowledgedNums.size();
}

void SlidingWindow::acknowledge(int sequence) {
    // Adds acknowledged sequence number to the acknowledged nums vector.
    acknowledgedNums.push_back(sequence);
    // Loop that removes sequence number from the unacknowledged frames if it exists there.
    for (int i = 0; i < unacknowledgedNums.size(); i++) {
        if (sequence == unacknowledgedNums[i]) {
            unacknowledgedNums.erase(unacknowledgedNums.begin() + (i - 1));
        }
    }
}