#include <iostream>
#include "functions.h"
#include "test.h"

// TODO(student): declare other functions, as needed

void test_add() {
    assert_equal(add("1", "1"), "2");
    // TODO(student): add tests for add
    assert_equal(add("123", "456"), "579");
    assert_equal(add("9999", "1"), "10000");
    assert_equal(add("108547", "65874921"), "65983468");
    assert_equal(add("15", "5"), "20");
    assert_equal(add("8", "0"), "8");
    assert_equal(add("0", "0"), "0");
    assert_equal(add("-1", "-1"), "-2");
    assert_equal(add("-123", "456"), "333");
    assert_equal(add("10000", "-1"), "9999");
    assert_equal(add("-15", "-15"), "-30");
    assert_equal(add("-100", "0"), "-100");
    assert_equal(add("-5874136", "7422185"), "1548049");
    assert_equal(add("8410641464", "-741265"), "8409900199");
    assert_equal(add("-20000000000000000", "1"), "-19999999999999999");
    assert_equal(add("-84115416785417414", "4597128"), "-84115416780820286");
    assert_equal(add("4597128", "-84115416785417414"), "-84115416780820286");
    assert_equal(add("-2", "2"), "0");
    assert_equal(add("67", "-67"), "0");
    assert_equal(add("10000000000000001", "10000000000000001"), "20000000000000002");
    assert_equal(add("99999999999999999", "111111111111"), "100000111111111110");
    assert_equal(add("-99999999999999989", "-10000000001"), "-100000009999999990");
    assert_equal(add("978654149685168772", "0"), "978654149685168772");
    assert_equal(add("-9999999999999999", "-1"), "-10000000000000000");
    assert_equal(add("123456789012345678901234567890", "-987654321098765432109876543210"), "-864197532086419753208641975320");
    assert_equal(add("2", "2"), "4");
}

void test_subtract() {
    assert_equal(subtract("1", "1"), "0");
    // TODO(student): add tests for subtract
    assert_equal(subtract("123", "456"), "-333");
    assert_equal(subtract("9999", "1"), "9998");
    assert_equal(subtract("108547", "65874921"), "-65766374");
    assert_equal(subtract("15", "5"), "10");
    assert_equal(subtract("8", "0"), "8");
    assert_equal(subtract("0", "0"), "0");
    assert_equal(subtract("-1", "-1"), "0");
    assert_equal(subtract("-123", "456"), "-579");
    assert_equal(subtract("10000", "-1"), "10001");
    assert_equal(subtract("-15", "15"), "-30");
    assert_equal(subtract("-100", "0"), "-100");
    assert_equal(subtract("-5874136", "7422185"), "-13296321");
    assert_equal(subtract("8410641464", "-741265"), "8411382729");
    assert_equal(subtract("-20000000000000000", "-1"), "-19999999999999999");
    assert_equal(subtract("-84115416785417414", "4597128"), "-84115416790014542");
    assert_equal(subtract("4597128", "-84115416785417414"), "84115416790014542");
    assert_equal(subtract("-2", "-2"), "0");
    assert_equal(subtract("67", "-67"), "134");
    assert_equal(subtract("10000000000000001", "-10000000000000001"), "20000000000000002");
    assert_equal(subtract("99999999999999999", "111111111111"), "99999888888888888");
    assert_equal(subtract("-99999999999999989", "-10000000001"), "-99999989999999988");
    assert_equal(subtract("978654149685168772", "0"), "978654149685168772");
    assert_equal(subtract("-9999999999999999", "-1"), "-9999999999999998");
    assert_equal(subtract("123456789012345678901234567890", "-987654321098765432109876543210"), "1111111110111111111011111111100");
    assert_equal(subtract("0", "2"), "-2");
}

void test_multiply() {
    assert_equal(multiply("1", "1"), "1");
    // TODO(student): add tests for multiply
    assert_equal(multiply("123", "456"), "56088");
    assert_equal(multiply("9999", "1"), "9999");
    assert_equal(multiply("108547", "65874921"), "7150525049787");
    assert_equal(multiply("15", "5"), "75");
    assert_equal(multiply("8", "0"), "0");
    assert_equal(multiply("0", "0"), "0");
    assert_equal(multiply("-1", "-1"), "1");
    assert_equal(multiply("-123", "456"), "-56088");
    assert_equal(multiply("10000", "-1"), "-10000");
    assert_equal(multiply("-15", "15"), "-225");
    assert_equal(multiply("-100", "0"), "0");
    assert_equal(multiply("-5874136", "7422185"), "-43598924107160");
    assert_equal(multiply("8410641464", "-741265"), "-6234514144811960");
    assert_equal(multiply("-20000000000000000", "-1"), "20000000000000000");
    assert_equal(multiply("-84115416785417414", "4597128"), "-386689337735912385586992");
    assert_equal(multiply("4597128", "-84115416785417414"), "-386689337735912385586992");
    assert_equal(multiply("-2", "4"), "-8");
    assert_equal(multiply("67", "-67"), "-4489");
    assert_equal(multiply("10000000000000001", "-10000000000000001"), "-100000000000000020000000000000001");
    assert_equal(multiply("99999999999999999", "111111111111"), "11111111111099999888888888889");
    assert_equal(multiply("-99999999999999989", "-10000000001"), "1000000000099999889999999989");
    assert_equal(multiply("978654149685168772", "0"), "0");
    assert_equal(multiply("-9999999999999999", "-1"), "9999999999999999");
}

// TODO(student): add tests for other functions, as needed

int main() {
    test_add();
    test_subtract();
    test_multiply();

    // TODO(student): invoke tests for other functions
    
    return 0;
}