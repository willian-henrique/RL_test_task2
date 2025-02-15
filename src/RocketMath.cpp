#include <cmath>
#include <cstdint>
#include <string.h>
#include <string>
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


void RocketMath::invert_string(shared_ptr<string> result){

    int len = result.get()->length();
    // cout << "len " << len << "  res " << result.get()->c_str() << endl;
    for (int i = 0; i < len / 2; i++) {

        char temp = (*result)[i];
        (*result)[i] = (*result)[len - 1 - i];
        (*result)[len - 1 - i] = temp;
    }
}

void RocketMath::sum(const shared_ptr<const string> num_a, const shared_ptr<const string> num_b, shared_ptr<string> result){

    size_t size_a = num_a.get()->length();
    size_t size_b = num_b.get()->length();

    shared_ptr<string> local_num_a = make_shared<string>();
    shared_ptr<string> local_num_b = make_shared<string>();
    
    uint32_t carry = 0;
    uint32_t sum = 0;    
    size_t bigger = 0;
    char a, b;


    *local_num_a = *num_a;
    *local_num_b = *num_b;
    *result = "";
    invert_string(local_num_a);
    invert_string(local_num_b);

    if(size_a > size_b){
        bigger = size_a;
    }else{
        bigger = size_b;
    }

    for (uint32_t i = 0; i < bigger ; i++){
        
        if((*local_num_a)[i] > '9' || (*local_num_a)[i] < '0' || local_num_a.get()->size() < i){

            a = '0';
        }else{
            a = (*local_num_a)[i];
        }

        if((*local_num_b)[i] > '9' || (*local_num_b)[i] < '0' || local_num_b.get()->size() < i ){
            b = '0';
        }else{
            b = (*local_num_b)[i];
        }
        sum = (a - '0') + (b - '0') + carry;
        (*result) += (sum%10 + '0');
        carry = sum/10;
    }
    if(carry != 0){
        (*result) += carry + '0';
        carry = 0;
    }
    invert_string(result);
}
uint8_t RocketMath::multiply(const shared_ptr<const string> num_a, const shared_ptr<const string> num_b, shared_ptr<string> result){

    shared_ptr mult_result = make_shared<string>("");
    shared_ptr sum_result = make_shared<string>("");
    size_t size_a = num_a.get()->length();
    size_t size_b = (*num_b).length();


    *result = "";
        
    for (size_t a = 0; a < size_a; a++){

        int64_t carry = 0;
        int64_t mult = 0;
        size_t b = 0;
        *mult_result = "";

        for ( ; b < size_b; b++)
        {
            mult = ((*num_a)[size_a -1 - a] - '0') * ( (*num_b)[size_b -1 - b] - '0') + carry;
            (*mult_result) += (mult%10 + '0');
            carry = mult/10;
        }  
        if (carry > 0)
        {
            (*mult_result) += carry + '0';
        }
        // Is necessary multiply by 10, 100, 1000 to after sum the result (easy way to do a shift).
        (*mult_result) = string("").append(a, '0') + *mult_result ; 
        //Now invert to keep the standard
        invert_string(mult_result);
        sum(mult_result, sum_result, sum_result);      
    }
    *result = *sum_result;
    return 0;
}
uint8_t RocketMath::power(const shared_ptr<const string> base, const shared_ptr<const string> exponent, shared_ptr<string> result){
 
    size_t exp;
    shared_ptr local_result = make_shared<string>("1");
    
    exp = std::stoi(*exponent);
    for (size_t i = 0; i < exp; i++)
    {
        multiply(base, local_result, result);
        *local_result = *result;
    }
    return 0;
}