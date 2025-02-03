#include <cmath>
#include <iostream>

#include "RocketMath.h"
using namespace std;

RocketMath::RocketMath(/* args */)
{
}

RocketMath::~RocketMath()
{
}

uint32_t RocketMath::reverse_numbers(uint32_t base_number){

    uint32_t reversed = 0;
    uint16_t multiplication_factor = 10;
    bool flag_last = false;
    do{

        if(base_number < 10){
            flag_last = true;
        }
        reversed = (base_number%10) + (reversed*10);
        base_number = base_number/10;
    }while(flag_last == false);
    
    return reversed;
}


void RocketMath::invert_string(char *str_to_invert){

    int len = strlen(str_to_invert);
    for (int i = 0; i < len / 2; i++) {

        char temp = str_to_invert[i];
        str_to_invert[i] = str_to_invert[len - 1 - i];
        str_to_invert[len - 1 - i] = temp;
    }
}

void RocketMath::sum(char *num_a, char *num_b, char *result){

    size_t size_a = strlen(num_a);
    size_t size_b = strlen(num_b);
    char local_num_a[SIZE_OF_POWER_FUNC_RESULT];
    char local_num_b[SIZE_OF_POWER_FUNC_RESULT];
    uint32_t carry = 0;
    uint32_t sum = 0;    
    size_t bigger = 0;

    memset(local_num_a, 0, SIZE_OF_POWER_FUNC_RESULT);
    strcpy(local_num_a, num_a);

    memset(local_num_b, 0, SIZE_OF_POWER_FUNC_RESULT);
    strcpy(local_num_b, num_b);

    memset(result, 0, SIZE_OF_POWER_FUNC_RESULT);

    invert_string(local_num_a);
    invert_string(local_num_b);

    // cout << "NUM_A: " << local_num_a << " NUM_B: " << local_num_b << endl; 

    if(size_a > size_b){
        bigger = size_a;
    }else{
        bigger = size_b;
    }
    for (uint32_t i = 0; i < bigger ; i++){
        
        if(local_num_a[i] > '9' || local_num_a[i] < '0'){

            local_num_a[i] = '0';
        }
        if(local_num_b[i] > '9' || local_num_b[i] < '0'){

            local_num_b[i] = '0';
        }
        sum = (local_num_a[i] - '0') + (local_num_b[i] - '0') + carry;
        result[i] = (sum%10 + '0');
        carry = sum/10;
    }
    if(carry != 0){
        result[bigger] = carry + '0'; 
    }
    invert_string(result);
}
uint8_t RocketMath::multiply(char *num_a, char *num_b, char *result){

    size_t size_a = strlen(num_a);
    size_t size_b = strlen(num_b);
    char local_num_a[SIZE_OF_POWER_FUNC_RESULT];
    char local_num_b[SIZE_OF_POWER_FUNC_RESULT];

    memset(local_num_a, 0, SIZE_OF_POWER_FUNC_RESULT);
    strcpy(local_num_a, num_a);

    memset(local_num_b, 0, SIZE_OF_POWER_FUNC_RESULT);
    strcpy(local_num_b, num_b);

    memset(result, 0, SIZE_OF_POWER_FUNC_RESULT);

    // invert_string(local_num_a);
    // invert_string(local_num_b);

    //Isn't an optimized, but is easier to the given time
    char temp_result[SIZE_OF_POWER_FUNC_RESULT + 1][SIZE_OF_POWER_FUNC_RESULT];
    
    memset(temp_result, 0, (SIZE_OF_POWER_FUNC_RESULT+1)*SIZE_OF_POWER_FUNC_RESULT);

    // std::cout << "num_a: " << local_num_a << "  num_b: " << local_num_b << std::endl; 
    // std::cout << "size a: " << size_a << " size b: " << size_b << std::endl;
    for (int64_t a = 0; a < size_a; a++){

        int64_t carry = 0;
        int64_t mult = 0;
        int64_t b = 0;
        for ( ; b < size_b; b++)
        {
            mult = (local_num_a[size_a -1 - a] - '0') * (local_num_b[size_b -1 - b] - '0') + carry;
            // std::cout << "mult  " << mult << " num_a[a]: " << (num_a[size_a -1 - a] - '0') << " num_b[b] " << (num_b[size_b -1- b] - '0') << std::endl;
            // std::cout <<  "size_b - 1 - b: " << size_b - 1 - b << std::endl; 

            temp_result[a][b] = (mult%10 + '0');
            carry = mult/10;
            // std::cout << "temp_result[a][b] " << temp_result[size_a - 1 - a][size_b - 1 - b] << " carry: " << carry << std::endl;
        }  
        //  cout << "carry: " << carry << endl;
        if (carry > 0)
        {
            temp_result[a][size_b] = carry + '0';
        }
        // cout << "carry: " << carry << "    " << temp_result[a][0] << endl;
        // Is necessary multiply by 10, 100, 1000 to after sum the result (easy way to do a shift).

        // cout << "TEMP_RESULT: " << temp_result[a] << endl; 
        strcpy(&temp_result[a][a], &temp_result[a][0]);
        memset(&temp_result[a][0], '0', a);

        //Now invert to keep the standard
        invert_string(temp_result[a]);

        // std::cout << "AQUII TEMP_RESULT  " << temp_result[a] << "    ----   " << strlen(temp_result[a]) << std::endl;
        sum(temp_result[a], temp_result[size_a + 1], temp_result[size_a + 1]);
       
    }
    // std::cout << "MULT RESULT: " << temp_result[size_a+1] << std::endl;
    strcpy(result, temp_result[size_a+1]); 
    return 0;
}
uint8_t RocketMath::power(char* base, char* exponent, char result[SIZE_OF_POWER_FUNC_RESULT]){
 
    memset(result, 0, SIZE_OF_POWER_FUNC_RESULT);

    result[0] = '1';
    for (size_t i = 0; i < stoi(exponent); i++)
    {
        // cout << result << endl;
        multiply(base, result, result);
        // cout << "result: " << result << "   base: " << base << endl;
    }

    // std::cout << "result: " << result << std::endl;
    return 0;
}