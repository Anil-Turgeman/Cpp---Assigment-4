#include <string>
#include "iostream"
using namespace std;
namespace bullpgia {
    
    string calculateBullAndPgia(string choice,string guess){
            int cows = 0;
            int bulls = 0;
            int num[10] = {0};
            for(int i = 0; i < choice.length(); i++){
                if(guess[i] == choice[i]){
                    bulls++;
                }else{
                    if(num[guess[i] - '0']++ < 0) {
                        cows++;
                    }
                    if(num[choice[i] - '0']-- > 0){
                            cows++;
                        }
                    }
            }
        return to_string(bulls) + ", " + to_string(cows);
    }
}
