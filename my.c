/* 
 * File:   my.c
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on December 15, 2018, 10:24 PM
 */

#include <sys/time.h>

int timeval_subtract_my(struct timeval *result, 
        struct timeval *x, struct timeval *y)
{
    /* We need to calculate RESULT = X - Y */
    /* First, determine which one is greater and result sign */
    int negative;
    if (    (y->tv_sec > x->tv_sec) || 
            ((y->tv_sec == x->tv_sec) && (y->tv_usec > x->tv_usec)) ) {
        /* The result will be negative, because y > x */
        negative = 1;
        /* A little trick here is to reverse X and Y, and make reverse
         * subtraction, so RESULT = -(Y - X). */
        result->tv_sec = y->tv_sec - x->tv_sec;
        result->tv_usec = y->tv_usec - x->tv_usec;
    } else {
        /* The result will be positive: RESULT = (X - Y). */
        negative = 0;
        /* Here without trick, make straight subtraction. */
        result->tv_sec = x->tv_sec - y->tv_sec;
        result->tv_usec = x->tv_usec - y->tv_usec;
    }

    /* TV_USEC could be negative and we need to fix it, but now it's 
     * much easier, because we stored sign in NEGATIVE and no matter
     * what way we have gone through previous IF, value inside 
     * brackets (X - Y) or (Y - X) will be non-negative. */
    if (result->tv_usec < 0) {
        result->tv_usec += 1000000;
        result->tv_sec--;   /* With respect to first IF conditions, at
                             * this line, TV_SEC can't become negative -
                             * that's thin place at this calculations. */
    }

    return negative;
}

