#ifndef Timer_H
#define Timer_H

#define ONE_SEC 1000
#define THREE_SEC 3000
#define ONE_HUNDRED_MILI_SEC 100
#define TWO_HUNDRED_FOURTY_MILI_SEC 240
#define ONE_HUNDRED_TWENTY_MILI_SEC 120
#define TWO_HUNDRED_MILI_SEC 200
#define FIVE_HUNDRED_MILI_SEC 500

int getCurrentTime();
void delay(int delayCycle);
int waitWithoutDelay(int previousTime, int delayMilliSecond);


#endif // Timer_H
