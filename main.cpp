#include <iostream>
#include "math.h"
#include <string>
#include "src/RocketMath.h"

using namespace std;
RocketMath math_operations;

int main() {

    string user_input;
    int32_t input_number = 0;
    uint32_t reverse_number = 0;
    char reverse_char[32];
    char result[1024];
    cout << "Welcome to the Rocket Lab user-interface" << endl;

    while(true){

        cout << "Enter a number (0-99999) to calculate the operatio abc^cba: " ;
        getline(cin, user_input);
        input_number = stoi(user_input);

        if(input_number >= 0 && input_number <= 99999){
            reverse_number = math_operations.reverse_numbers((uint32_t)input_number);
            sprintf(reverse_char, "%d", reverse_number);
            math_operations.power((char *)user_input.c_str(), reverse_char, result);
            cout << result << endl;
        }else{
            cout << "Invalid number, please enter with a number between (0 - 99999)." << endl;
        }
    }
    return 0;
}