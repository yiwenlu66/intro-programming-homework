#include <stdio.h>
#define START_PRICE 13
#define START_DISTANCE 3
#define UNIT 2.3
#define WAIT 0.46
#define NIGHT_RATE 1.2
#define RUSH_RATE 2
#define EMPTY_DISTANCE 15
#define EMPTY_RATE 1.5
#define ADD 1

int main()
{
    int isnight, isrush, issingle;
    float distance, wait_time;
    float base, empty, night, wait_fee, rush, add, total;

    // input 1
    printf("Is night? (0 or 1)\n");
    scanf("%d", &isnight);
    if (isnight)
        isrush = 0;
    else {
        printf("Is rush hour? (0 or 1)\n");
        scanf("%d", &isrush);
    }

    // input 2
    printf("Is single trip? (0 or 1)\n");
    scanf("%d", &issingle);

    // input 3
    printf("Distance?\n");
    scanf("%f", &distance);

    // input 4
    printf("Waiting time?\n");
    scanf("%f", &wait_time);

    // base fee
    if (distance <= START_DISTANCE)
        base = START_PRICE;
    else
        base = (distance - START_DISTANCE) * UNIT + START_PRICE;

    // additional fee for empty driving
    if (distance > EMPTY_DISTANCE && issingle)
        empty = (distance - EMPTY_DISTANCE) * UNIT * (EMPTY_RATE - 1);
    else
        empty = 0;

    // additional fee for night
    if (isnight)
        night = base * (NIGHT_RATE - 1);
    else
        night = 0;

    // additional fee for waiting
    wait_fee = WAIT * wait_time;

    // additional fee for rush hours;
    if (isrush)
        rush = wait_fee * (RUSH_RATE - 1);
    else
        rush = 0;

    // additional fee for gas
    add = ADD;

    total = base + empty + night + wait_fee + rush + add;
    printf("￥");
    printf("%.1f\n", total);

    return 0;
}
