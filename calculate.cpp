#include <iostream>
#include "calculate.hpp"
#include <vector>
using namespace std;

string calculateBullAndPgia(string choice, string guess){
	int bulls = 0;
	int pgia = 0;
	string newGuess = " ";
	string newChoice = " ";

	for (int i = 0 ; i < choice.length() ; i++){
		if (guess[i] == choice[i]){
			bulls++;
		}else {
			newGuess += guess[i];
			newChoice += choice[i];
		}
	}

	for (int i = 0 ; i < newGuess.length() ; i++){
		for (int j = 0 ; j < newChoice.length() ; j++){
			if (newGuess[i] == newChoice[j]){
				pgia++;
				newChoice.replace(j, 1, "A");
			}
		}
	}

	return to_string(bulls) + ", " + to_string(pgia);
}
