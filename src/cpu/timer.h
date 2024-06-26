#ifndef TIMER_H
#define TIMER_H

#include "types.h"

#define CLOCK_FREQUENCY 1193180

void init_timer(u32 freq);

typedef struct{
    u32 tick;
    u16 freq;
}timer_struct;

extern timer_struct timer;

#endif