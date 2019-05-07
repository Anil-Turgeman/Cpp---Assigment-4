#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include <iterator>
#include <list>
using std::string;

namespace bullpgia{
    class SmartGuesser: public bullpgia::Guesser{
        public:
            string guess;
            list<string> combination;
            string guess() override;
            void createTheNumberToGuess(uint length);
            void startNewGame(uint length) override;
            void learn(string reply) override;
    };
}
