#include <iostream>
#include <string>
#include "SmartGuesser.hpp"
using namespace std;
using namespace bullpgia;

    int flag = 0;
    int candidate = 0;
    string ans = "";

    void SmartGuesser::learn(string reply){
        int bulls = (int)(reply[0]);
        if (bulls - 48 == (flag+1)){
            flag++;
            candidate = 0;
        }
        ans.replace(flag, 1, to_string(candidate));
        candidate++;
    }

    string SmartGuesser::guess() {
        return ans;
    }

    void SmartGuesser::startNewGame(uint length){
        this->length = length;
        flag = 0;
        candidate = 0;
        ans = "wrong";
        ans = ans.substr(0,length);
    }
