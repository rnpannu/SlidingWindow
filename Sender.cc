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
