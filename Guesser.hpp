#pragma once
#include <iostream>
#include "calculate.hpp"
using namespace std;

namespace bullpgia{
    class Guesser {
        public:
            uint length = 0;
            virtual string guess()=0;
            virtual void startNewGame(uint length){}
            virtual void learn(string reply){}
    };
}
