#include <iostream>
#include <vector>
#include "Sender.h"

Receiver::Receiver(int max) : SlidingWindow(int max){
    setMax(max);
    setWindow(1);
}
