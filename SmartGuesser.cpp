#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <iomanip>
#include <cmath>
using namespace std;
using namespace bullpgia;


string SmartGuesser::guess(){
    list<string>::iterator it = combination.begin();
    int randomIndex = rand()%combination.size();
    advance(it, randomIndex);//puts the random 
    guess = *it; 
    return guess;
}

void SmartGuesser::learn(string calculateStatus) {
	for (list<string>::iterator it=combination.begin(); it!=combination.end();){
		string ans = calculateBullAndPgia(*it, guess);
		if(calculateStatus!=ans){
			it = combination.erase(it);
		}else{
			it++;
		}
	}
}

void SmartGuesser::startNewGame(uint length){
	this->length = length;
	createTheNumberToGuess(length);
}

void SmartGuesser::createTheNumberToGuess(uint length){
	string num;
	int MAX_NUM;

	if(!combination.empty()){
		combination.clear();
	}

	for(int i = 0; i < length; i++){
		num += "9";
	}
	
	MAX_NUM = std::stoi(num);	
	
	for(int i=0; i <= MAX_NUM; i++){
		string curr = to_string(i);
		ostringstream ss;
		ss  << setw(length) << setfill('0') << curr;
		string s = ss.str();
		combination.push_back(s);
	}
	
}
