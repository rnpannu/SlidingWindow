#include <iostream>
#include <vector>
#include "Sender.h"

Sender::Sender(int max) : SlidingWindow(max){}
int Sender::retransmit(){
    return unacknowledgedNums[0];
}