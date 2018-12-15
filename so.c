#include <sys/time.h>

/*
 * This code was originally posted here
 * https://stackoverflow.com/a/15849714
 */

int timeval_subtract_so(struct timeval *result, 
        struct timeval *x, struct timeval *y)
{
    struct timeval xx = *x;
    struct timeval yy = *y;
    x = &xx; y = &yy;

    if (x->tv_usec > 999999) 
    {
        x->tv_sec += x->tv_usec / 1000000;
        x->tv_usec %= 1000000;
    }

    if (y->tv_usec > 999999) 
    {
        y->tv_sec += y->tv_usec / 1000000;
        y->tv_usec %= 1000000;
    }

    result->tv_sec = x->tv_sec - y->tv_sec;

    if ((result->tv_usec = x->tv_usec - y->tv_usec) < 0) 
    {
        result->tv_usec += 1000000;
        result->tv_sec--; // borrow
    }

    return result->tv_sec < 0;
}

