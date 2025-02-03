#ifndef RocketMath_H
#define RocketMath_H

#include <stdint.h>
#include <cstdint>
#include <string.h>

#define SIZE_OF_POWER_FUNC_RESULT           1024

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
     * @param base number in the format of c-string of the operation.
     * @param exponent number in the format of c-string of the operation.
     * @param result  result of the operation in the format of c-string.
     * @return result if the operation was successful, where:
     *      0 - success
     *      1 - error 
     */
    uint8_t power(char* base, char* exponent, char result[SIZE_OF_POWER_FUNC_RESULT]);

    /**
     * 
     */
    uint8_t multiply(char *num_a, char *num_b, char *result);

    /**
     * Sum 2 values in c-string format.
     * @param num_a number to be part in the sum.
     * @param num_b number to be part in the sum.
     * @param result result of the sum.
     * 
     * @note This function doesn't handle negative values (FIXME)
     */
    void sum(char *num_a, char *num_b, char *result);

private:

    void invert_string(char *str_to_invert);
};

#endif