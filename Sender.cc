#include <iostream>
#include <vector>
#include "Sender.h"

Sender::Sender(int max) : SlidingWindow(max){}
/*
bool Sender::req(int SN){
    
}
*/
int Sender::retransmit(){
    return unacknowledgedNums[0];
}

void Sender::acknowledge(int sequence) {
    // Adds acknowledged sequence number to the acknowledged nums vector.
    acknowledgedNums.push_back(sequence);
    // Loop that removes sequence number from the unacknowledged frames if it exists there.
    for (int i = 0; i < unacknowledgedNums.size(); i++) {
        if (sequence == unacknowledgedNums[i]) {
            unacknowledgedNums.erase(unacknowledgedNums.begin() + (i - 1));
        }
    }
}
