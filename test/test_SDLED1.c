#include "unity.h"
#include "SDLED1.h"
#include "State.h"
#include "mock_Timer.h"
#include "mock_LED.h"

void setUp(void){}

void tearDown(void){}

void test_SDLED1_INITIAL_state_should_off_LED_and_go_next_state(void)
{
	State state = INITIAL;
	int previousTime = 0;

	turnOffLED_Expect();
	SDLED1(&state, &previousTime);

	TEST_ASSERT_EQUAL(state, ON_LED1);
}

void test_SDLED1_ON_LED1_state_should_go_OFF_LED1_after_120ms_time_expired(void)
{
	State state = ON_LED1;
	int previousTime = 0;

	getCurrentTime_ExpectAndReturn(130);
	getCurrentTime_ExpectAndReturn(130);
	turnOnLED_Expect();
	
	SDLED1(&state, &previousTime);
	
	TEST_ASSERT_EQUAL(state, OFF_LED1);
	TEST_ASSERT_EQUAL(previousTime, 130);
}

void test_SDLED1_state_stay_ON_LED1_when_120ms_hvnt_expired(void)
{
	State state = ON_LED1;
	int previousTime = 0;

	getCurrentTime_ExpectAndReturn(100);
	
	SDLED1(&state, &previousTime);
	
	TEST_ASSERT_EQUAL(state, ON_LED1);
}

void test_SDLED1_OFF_LED1_should_go_FINAL_when_120ms_time_expired(void)
{
	State state = OFF_LED1;
	int previousTime = 0;

	getCurrentTime_ExpectAndReturn(121);
	getCurrentTime_ExpectAndReturn(121);
	turnOffLED_Expect();
	
	SDLED1(&state, &previousTime);
	
	TEST_ASSERT_EQUAL(state, FINAL);
	TEST_ASSERT_EQUAL(previousTime, 121);
}

void test_SDLED1_FINAL_should_go_to_ON_LED1_state(void)
{
	State state = FINAL;
	int previousTime = 0;
	
	SDLED1(&state, &previousTime);
	
	TEST_ASSERT_EQUAL(state, ON_LED1);
}