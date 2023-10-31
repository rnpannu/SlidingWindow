#include <iostream>
#include <vector>
#include "Receiver.h"

Receiver::Receiver(int max) : SlidingWindow(max){
    setMax(max);
    setWindow(1);
}
