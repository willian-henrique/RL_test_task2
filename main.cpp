#include <iostream>
#include "math.h"
#include <string>
#include "src/RocketMath.h"
#include <memory>

using namespace std;
RocketMath math_operations;

int main() {

    string user_input = string();
    int32_t input_number = 0;
    uint32_t reverse_number = 0;
    string reverse_char = string();
    string result = string();
    cout << "Welcome to the Rocket Lab user-interface" << endl;

    while(true){

        cout << "Enter a number (0-99999) to calculate the operatio abc^cba: " ;
        getline(cin, user_input);
        input_number = stoi(user_input);

        if(input_number >= 0 && input_number <= 99999){
            reverse_number = math_operations.reverse_numbers((uint32_t)input_number);
            reverse_char = to_string(reverse_number);
            auto p = math_operations.power(user_input, reverse_char);
            result = p.second;
            cout << result << endl;
        }else{
            cout << "Invalid number, please enter with a number between (0 - 99999)." << endl;
        }
    }
    return 0;
}