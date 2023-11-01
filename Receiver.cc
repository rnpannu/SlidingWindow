#include <iostream>
#include <vector>
#include "Receiver.h"

Receiver::Receiver(int max) : SlidingWindow(max){
    lastAck = -1;
}

void Receiver::acknowledge(int sequence) {
    // Adds acknowledged sequence number to the acknowledged nums vector.
    acknowledgedNums.push_back(sequence);
    // Loop that removes sequence number from the unacknowledged frames if it exists there.
    for (int i = 0; i < unacknowledgedNums.size(); i++) {
        if (sequence == unacknowledgedNums[i]) {
            unacknowledgedNums.erase(unacknowledgedNums.begin() + (i - 1));
        }
    }

    //Unique to reciever, increments last acknowledged frame.
    lastAck += 1;
}

int Receiver::retransmit(){
    return unacknowledgedNums[0];
}

