#include "SmartGuesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <string>
using std::string;
using namespace std;
using namespace bullpgia;

string SmartGuesser::guess(){
    std::list<std::string>::iterator it = combination.begin();
    if (combination.size() == 0)
        newList();
    if (combination.size() > 1){
        std::advance(it, rand()%(combination.size()-1));
        this->temp = *it;
    }else if (combination.size() == 1)
        this->temp = *combination.begin();

    return temp;
}

void SmartGuesser::startNewGame(uint length){
    combination.clear();
    this->length=length;
    newList();
}


void SmartGuesser::newList(){
    int size = pow(10, length);
    for (size_t i = 0; i < size; i++){
        stringstream in;
        in << setw(length) << setfill('0') << i;
        string str = in.str();
        combination.push_front(str);
    }
}



void SmartGuesser::removeComb(string result){
    list<string>::iterator it2 ;
    it2=combination.begin();
    while (it2 != combination.end()){
        string pre = calculateBullAndPgia(*it2, temp);
        if (pre.compare(result) != 0) {
            it2 = combination.erase(it2);
        }else{
            ++it2;
        }
    }
    this->combination.remove(temp);
}



void SmartGuesser::learn(string result){    removeComb(result); }
