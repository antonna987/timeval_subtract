/* 
 * File:   test.c
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on December 15, 2018, 10:34 PM
 */

#include <assert.h>
#include <stdint.h>

#define __USE_MISC
#include <sys/time.h>

struct timeval uint64totv(uint64_t uint64)
{
    struct timeval tv;
    tv.tv_sec = uint64 / 1000000;
    tv.tv_usec = uint64 % 1000000;
    return tv;
}

uint64_t tvtouint64(struct timeval tv)
{
    struct timeval max = uint64totv(UINT64_MAX);
    assert( (tv.tv_sec < max.tv_sec) || 
            ((tv.tv_sec == max.tv_sec) && (tv.tv_usec < max.tv_usec)) );
    
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

/* It simply converts timeval to microseconds, subtracts and makes
 * reverse conversion. */
int timeval_subtract_test(struct timeval *result, 
        struct timeval *x, struct timeval *y)
{
    uint64_t xx = tvtouint64(*x);
    uint64_t yy = tvtouint64(*y);
    
    if (yy > xx) {
        uint64_t sub = yy - xx;
        *result = uint64totv(sub);
        return 1;
    } else {
        uint64_t sub = xx - yy;
        *result = uint64totv(sub);
        return 0;
    }
}

/* This variant uses macros from sys/time.h. */
int timeval_subtract_test2(struct timeval *result, 
        struct timeval *x, struct timeval *y)
{
    if (timercmp(y, x, >)) {
        timersub(y, x, result);
        return 1;
    } else {
        timersub(x, y, result);
        return 0;
    }
}



