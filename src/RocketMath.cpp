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
    //Isn't an optimized, but is easier to the given time
    char temp_result[SIZE_OF_POWER_FUNC_RESULT + 1][SIZE_OF_POWER_FUNC_RESULT];
    memset(temp_result, 0, (SIZE_OF_POWER_FUNC_RESULT+1)*SIZE_OF_POWER_FUNC_RESULT);
    for (size_t a = 0; a < size_a; a++){

        int64_t carry = 0;
        int64_t mult = 0;
        size_t b = 0;
        for ( ; b < size_b; b++)
        {
            mult = (local_num_a[size_a -1 - a] - '0') * (local_num_b[size_b -1 - b] - '0') + carry;
            temp_result[a][b] = (mult%10 + '0');
            carry = mult/10;
        }  
        if (carry > 0)
        {
            temp_result[a][size_b] = carry + '0';
        }
        // Is necessary multiply by 10, 100, 1000 to after sum the result (easy way to do a shift).
        strcpy(&temp_result[a][a], &temp_result[a][0]);
        memset(&temp_result[a][0], '0', a);
        //Now invert to keep the standard
        invert_string(temp_result[a]);
        sum(temp_result[a], temp_result[size_a + 1], temp_result[size_a + 1]);
       
    }
    strcpy(result, temp_result[size_a+1]); 
    return 0;
}
uint8_t RocketMath::power(char* base, char* exponent, char result[SIZE_OF_POWER_FUNC_RESULT]){
 
    memset(result, 0, SIZE_OF_POWER_FUNC_RESULT);

    result[0] = '1';
    for (size_t i = 0; i < (size_t) stoi(exponent); i++)
    {
        multiply(base, result, result);
    }
    return 0;
}