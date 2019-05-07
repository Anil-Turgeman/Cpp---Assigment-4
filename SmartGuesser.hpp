#pragma once
#include <iostream>
#include "Guesser.hpp"
using std::string;

namespace bullpgia{
    class SmartGuesser: public bullpgia::Guesser {
        public:
            uint length = 0;
            string guess() override;
            void learn(string reply) override;
            void startNewGame(uint length) override;
    };
}
