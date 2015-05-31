#include "SDLED1.h"
#include "stdio.h"

//State Diagram for LED1
void SDLED1(State *state, int *previousTime)	{

	switch (*state)
	{
		case INITIAL:
			turnOffLED();
			*state = ON_LED1;
			break;

		case ON_LED1:
			if(getCurrentTime() - *previousTime > ONE_HUNDRED_TWENTY_MILI_SEC)	{
				*previousTime = getCurrentTime();
				turnOnLED();
				*state = OFF_LED1;
			}
			break;

		case OFF_LED1:
			if(getCurrentTime() - *previousTime > ONE_HUNDRED_TWENTY_MILI_SEC)	{
				*previousTime = getCurrentTime();
				turnOffLED();
				*state = FINAL;
			}
			break;

		case FINAL:
			*state = ON_LED1;
			break;

		default:
			break;
	}
}
