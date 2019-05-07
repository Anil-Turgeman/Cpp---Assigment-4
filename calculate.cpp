#include <string>
#include "iostream"
using namespace std ;
namespace bullpgia {
string calculateBullAndPgia(string the_choice,string the_guess){
        int pgia_numbers = 0;
        int bull_numbers = 0;
        int num[10] = {0};
        for(int i=0; i<the_choice.length(); i++){
            if(the_guess[i]==the_choice[i]){
                bull_numbers++;
            }else{
                if(num[the_guess[i] - '0']++ < 0) {
                        pgia_numbers++;
                    }
                if(num[the_choice[i] - '0']-- > 0){
                        pgia_numbers++;
                    }
                }
        }
            return to_string(bull_numbers) + "," +to_string(pgia_numbers);
    }
}
