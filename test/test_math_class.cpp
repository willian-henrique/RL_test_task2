#include "unity_framework/unity.h"
#include "../src/RocketMath.h"
#include <string.h>

RocketMath to_test;

void setUp(void) {
    // nothing to do in the initialization math class
}

void tearDown(void) {
    // nothing to do in the ending of the math class
}

void test_function_reverse_numbers(void) {

    TEST_ASSERT_EQUAL_INT32(4302, to_test.reverse_numbers(2034));
    TEST_ASSERT_EQUAL_INT32(9123, to_test.reverse_numbers(3219));
    TEST_ASSERT_EQUAL_INT32(123456789, to_test.reverse_numbers(987654321));        
    TEST_ASSERT_EQUAL_INT32(0, to_test.reverse_numbers(0));    
    TEST_ASSERT_EQUAL_INT32(99999, to_test.reverse_numbers(99999));
}

void test_function_power(void) {
    
    char result[1024];
    char base[1024];
    char exponent[1024];

    strcpy(base, "1234");
    strcpy(exponent, "5");    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("2861381721051424", result);

    memset(base, 0, 1024);
    memset(exponent, 0, 1024);
    memset(result, 0, 1024);
    strcpy(base, "12");
    strcpy(exponent, "21");    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("46005119909369701466112", result);

    //BIG numbers are failing
    memset(base, 0, 1024);
    memset(exponent, 0, 1024);
    memset(result, 0, 1024);
    strcpy(base, "13");
    strcpy(exponent, "31");    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("34059943367449284484947168626829637", result);
}

void test_function_multiply(void) {
    
    char result[1024];
    char value_a[1024];
    char value_b[1024];

    strcpy(value_a, "1234");
    strcpy(value_b, "1");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("1234", result);

    strcpy(value_a, "1234");
    strcpy(value_b, "5678");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("7006652", result);

    strcpy(value_a, "5555");
    strcpy(value_b, "5555");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("30858025", result);

    strcpy(value_a, "99999999999");
    strcpy(value_b, "99999999999");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("9999999999800000000001", result);

    strcpy(value_a, "9999999999800000000001");
    strcpy(value_b, "9999999999800000000001");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("99999999996000000000059999999999600000000001", result);

    //BIG numbers are failing
    strcpy(value_a, "99999999999999999999999999999999999999999999");
    strcpy(value_b, "99999999999999999999999999999999999999999999");    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("9999999999999999999999999999999999999999999800000000000000000000000000000000000000000001", result);
}

void test_function_sum(void) {
    
    char result[1024];
    char value_a[1024];
    char value_b[1024];

    strcpy(value_a, "86380");
    strcpy(value_b, "6170000");    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("6256380", result);

    strcpy(value_a, "2403942039420493209420423084032840923840293859043803489385903859340850986380");
    strcpy(value_b, "61700005305930352930493049032034924304902940934290");    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("2403942039420493209420423145732846229770646789536852521420828164243791920670", result);


    memset(result, 0, 1024);
    memset(value_a, 0, 1024);
    strcpy(value_b, "6170000");    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("6170000", result);

    strcpy(value_a, "99999999");
    strcpy(value_b, "99999999");    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("199999998", result);
}
// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_reverse_numbers);
    RUN_TEST(test_function_power);
    RUN_TEST(test_function_multiply);
    RUN_TEST(test_function_sum);
    return UNITY_END();
}