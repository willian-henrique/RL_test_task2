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


void RocketMath::invert_string(string &result){

    int len = result.length();
    // cout << "len " << len << "  res " << result.get()->c_str() << endl;
    for (int i = 0; i < len / 2; i++) {

        char temp = result[i];
        result[i] = result[len - 1 - i];
        result[len - 1 - i] = temp;
    }
}

string RocketMath::sum(const string &num_a, const string &num_b){

    size_t size_a = num_a.length();
    size_t size_b = num_b.length();

    string local_num_a = "";
    string local_num_b = "";
    string result = "";

    uint32_t carry = 0;
    uint32_t sum = 0;    
    size_t bigger = 0;
    char a = '0', b = '0';


    local_num_a = num_a;
    local_num_b = num_b;

    invert_string(local_num_a);
    invert_string(local_num_b);

    if(size_a > size_b){
        bigger = size_a;
    }else{
        bigger = size_b;
    }

    for (uint32_t i = 0; i < bigger ; i++){
        
        if(local_num_a.size() < i || local_num_a[i] > '9' || local_num_a[i] < '0'){

            a = '0';
        }else{
            a = local_num_a[i];
        }

        if(local_num_b.size() < i || local_num_b[i] > '9' || local_num_b[i] < '0'  ){
            b = '0';    
        }else{
                
        }
        sum = (a - '0') + (b - '0') + carry;
        result += (sum%10 + '0');
        carry = sum/10;
    }
    if(carry != 0){
        result += carry + '0';
        carry = 0;
    }
    // I don't need delete local_num_a and local_num_b?
    invert_string(result);
    return result;
}
pair<bool, string> RocketMath::multiply(const string &num_a, const string &num_b){

    string mult_result = "";
    string sum_result = "";
    size_t size_a = num_a.length();
    size_t size_b = num_b.length();
        
    for (size_t a = 0; a < size_a; a++){

        int64_t carry = 0;
        int64_t mult = 0;
        size_t b = 0;
        mult_result = "";

        for ( ; b < size_b; b++)
        {
            mult = (num_a[size_a -1 - a] - '0') * ( num_b[size_b -1 - b] - '0') + carry;
            mult_result += (mult%10 + '0');
            carry = mult/10;
        }  
        if (carry > 0)
        {
            mult_result += carry + '0';
        }
        // Is necessary multiply by 10, 100, 1000 to after sum the result (easy way to do a shift).
        mult_result = string("").append(a, '0') + mult_result ; 
        //Now invert to keep the standard
        invert_string(mult_result);
        sum_result = sum(mult_result, sum_result);      
    }
    return make_pair(true, sum_result);
}
pair<bool, string> RocketMath::power(const string &base, const string &exponent){
 
    size_t exp = 0;
    string local_result = "1";
    pair<bool, string> p;
    exp = std::stoi(exponent);
    for (size_t i = 0; i < exp; i++)
    {
        p = multiply(base, local_result);
        local_result = p.second;
    }
    return make_pair(true, local_result);
}