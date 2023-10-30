#include <iostream>
#include <vector>
#include "SlidingWindow.h"

Sender::Sender(int size) : SlidingWindow(int size){

}
int Sender::retransmit(){
    return unacknowledgedNums[0];
}