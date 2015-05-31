#include "Timer.h"

void delay(int delayCycle){
	static int previousTime = 0;

	while( (getCurrentTime() - previousTime) < delayCycle);
		previousTime = getCurrentTime();
}

int waitWithoutDelay ( int previousTime, int delayMilliSecond){
	if(getCurrentTime() - previousTime > delayMilliSecond)
		return 1;
	return 0;
}
