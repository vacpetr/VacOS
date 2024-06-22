#include "util.h"

void memset(void *dst, u8 value, u32 size){
    u8 *d = dst;

    while (size-- > 0) {
        *d++ = value;
    }
}