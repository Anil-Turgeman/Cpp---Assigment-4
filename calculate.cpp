#include <iostream>
#include "calculate.hpp"
using std::string;
namespace bullpgia {
    string calculateBullAndPgia(string chooser, string guesser) {
        int bull = 0, pgia = 0;
        int arr[chooser.size()];
        for(int i = 0; i < chooser.size(); i++){
            if(chooser[i] == guesser[i]){
                bull++;
                arr[i] = -1;
            }else{
                size_t found = chooser.find(guesser[i]); 
                if(found < chooser.size() && arr[found] != -1){
                    pgia++;
                    arr[found] = -1;
                }
            }
        }
        
        return to_string(bull) + ", " + to_string(pgia);
    }
}
