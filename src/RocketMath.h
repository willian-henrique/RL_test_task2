#ifndef RocketMath_H
#define RocketMath_H

// #include <stdint>
#include <string>
#include <memory>
#include <iostream>

const auto SIZE_OF_POWER_FUNC_RESULT = 1024;

using namespace std;

class RocketMath
{

public:
    RocketMath();
    ~RocketMath();

    /**
     * Implementing the reverse of the number, e.i input 12345 output 54321.
     * @param base_number base number which will be reversed.
     * @return The reversed number.
     */
    uint32_t reverse_numbers(uint32_t base_number);
    
    /**
     * Calculate the power of given base and exponent number 
     * 
     * @param base number in the format of string of the operation.
     * @param exponent number in the format of c-string of the operation.
     * @param result  result of the operation in the format of c-string.
     * @return result if the operation was successful, where:
     *      0 - success
     *      1 - error 
     */
    pair<bool, string> power(const string &base, const string& exponent);

    /**
     * Calculate the multiplication of given 2 numbers num_a*num_b
     * 
     * @param num_a first number
     * @param num_b second number
     * @param result return of operation
     */
    pair<bool, string> multiply(const string &num_a, const string &num_b);

    /**
     * Sum 2 values in c-string format.
     * @param num_a number to be part in the sum.
     * @param num_b number to be part in the sum.
     * @param result result of the sum.
     * 
     * @note This function doesn't handle negative values (FIXME)
     */
    string sum(const string &num_a, const string &num_b);

private:

    /**
     * Inverte a given c-string i.e. "123456789" will be "987654321"
     * @param str_to_invert C-string to be inverted.
     */
    void invert_string(string &result);
};

#endif