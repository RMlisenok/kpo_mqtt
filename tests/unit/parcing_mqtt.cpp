#include <Arduino.h>
#include <unity.h>

void test_parse_light_command() {
    String cmd = "light:on";
    String action = cmd.substring(0, cmd.indexOf(':'));
    String value = cmd.substring(cmd.indexOf(':') + 1);
    TEST_ASSERT_EQUAL_STRING("light", action.c_str());
    TEST_ASSERT_EQUAL_STRING("on", value.c_str());
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_parse_light_command);
    UNITY_END();
}

void loop() {}
