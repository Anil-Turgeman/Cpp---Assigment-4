#include "calculate.hpp"
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia{
    string calculateBullAndPgia(string choice, string guess){
        int tempC[10] = {0}, tempG[10] = {0}, bull = 0, pgia = 0;

        for (int i = 0; i < choice.length(); i++){
            tempC[i] = choice[i];
            tempG[i] = guess[i];
        }
        for (int i = 0; i < choice.length(); i++){
            if (tempC[i] == tempG[i]){
                bull++;
                tempC[i] = tempG[i] = 0;
            }
        }
        int c = 0;
        while (c < choice.length()){
            if (tempC[c] != 0){
                for (int i = 0; i < guess.length(); i++){
                    if(tempG[i]!=0)
                        if(tempG[i]==tempC[c]){
                            pgia++;
                            tempC[c]=0;
                            tempG[i]=0;
                        }
                }
            }
            c++;
        }
        return std::to_string(bull) + ", " + std::to_string(pgia);
    }
}
