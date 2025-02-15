#include "unity_framework/unity.h"
#include "../src/RocketMath.h"
#include <string>
#include <string.h>
#include <memory>

RocketMath to_test;
using std::string, std::shared_ptr, std::make_shared;

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
    
    shared_ptr result = make_shared<string>();
    shared_ptr base = make_shared<string>();
    shared_ptr exponent = make_shared<string>();

    *result = "";
    *base = "1234";
    *exponent = "5";

    to_test.power((const shared_ptr<const string>) base, (const shared_ptr<const string>) exponent, result);
    TEST_ASSERT_EQUAL_STRING("2861381721051424", result->c_str());

    *result = "";
    *base = "12";
    *exponent = "21";    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("46005119909369701466112", result->c_str());

    *result = "";
    *base = "13";
    *exponent = "31";    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("34059943367449284484947168626829637", result->c_str());

    *result = "";
    *base = "123";
    *exponent = "321";    
    to_test.power(base, exponent, result);
    TEST_ASSERT_EQUAL_STRING("72367033806371673149109894141163778628811792657571658906010558390395870363"
                    "79840174409528068615550773640492165707028496172182896059297790954263709889"
                    "76972231026226285667876540913278254539915951402057014129613641887324089361"
                    "97890553699715836951569999800431957769217006743321026257517932764164662319"
                    "48791496253330274136820721118949461532655279066772041128547416263676516890"
                    "72119241349733743044960196353766658585599417357039248364677569172479954695"
                    "83487467791524582153744522107597865277798136080074161485280424274076931083"
                    "99448711171956224970254036285571291113226596623575435535351670333904300150"
                    "61185207603595777378694720186179421205908731707108050786963717389063757217"
                    "85723", result->c_str());

}

void test_function_multiply(void) {
    
    shared_ptr result = make_shared<string>();
    shared_ptr value_a = make_shared<string>();
    shared_ptr value_b = make_shared<string>();

    *value_a = "1234";
    *value_b = "1";    
    to_test.multiply((const shared_ptr<const string>) value_a, (const shared_ptr<const string>) value_b, result);
    TEST_ASSERT_EQUAL_STRING("1234", result.get()->c_str());

    *value_a = "1234";
    *value_b = "5678";    
    to_test.multiply((const shared_ptr<const string>) value_a, (const shared_ptr<const string>)value_b, result);
    TEST_ASSERT_EQUAL_STRING("7006652", result.get()->c_str());

    *value_a = "5555";
    *value_b = "5555";    
    to_test.multiply((const shared_ptr<const string>) value_a, (const shared_ptr<const string>) value_b, result);
    TEST_ASSERT_EQUAL_STRING("30858025", result.get()->c_str());

    *value_a = "99999999999";
    *value_b = "99999999999";    
    to_test.multiply((const shared_ptr<const string>) value_a,(const shared_ptr<const string>) value_b, result);
    TEST_ASSERT_EQUAL_STRING("9999999999800000000001", result.get()->c_str());

    *value_a = "9999999999800000000001";
    *value_b = "9999999999800000000001";    
    to_test.multiply((const shared_ptr<const string>) value_a, (const shared_ptr<const string>) value_b, result);
    TEST_ASSERT_EQUAL_STRING("99999999996000000000059999999999600000000001", result.get()->c_str());

    //BIG numbers are failing
    *value_a = "99999999999999999999999999999999999999999999";
    *value_b = "99999999999999999999999999999999999999999999";    
    to_test.multiply(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("9999999999999999999999999999999999999999999800000000000000000000000000000000000000000001", result.get()->c_str());
}

void test_function_sum(void) {
    
    shared_ptr result = make_shared<string>();
    shared_ptr value_a = make_shared<string>();
    shared_ptr value_b = make_shared<string>();

    *value_a = "86380";
    *value_b = "6170000";    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("6256380", result.get()->c_str());

    *value_a = "2403942039420493209420423084032840923840293859043803489385903859340850986380";
    *value_b = "61700005305930352930493049032034924304902940934290";    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("2403942039420493209420423145732846229770646789536852521420828164243791920670", result.get()->c_str());
    


    *result = "";
    *value_a = "0";
    *value_b = "6170000";    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("6170000", result.get()->c_str());

    *value_a = "99999999";
    *value_b = "99999999";    
    to_test.sum(value_a, value_b, result);
    TEST_ASSERT_EQUAL_STRING("199999998", result.get()->c_str());
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