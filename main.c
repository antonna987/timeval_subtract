/* 
 * File:   main.c
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on December 11, 2018, 9:02 PM
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "gnu.h"
#include "so.h"
#include "my.h"
#include "test.h"

int main(int argc, char** argv) 
{
    /*
     * Choose function variant to use
     */
    
    int (*subtract)(struct timeval *, struct timeval *, struct timeval *) =
//        timeval_subtract_gnu;
        timeval_subtract_so;
//        timeval_subtract_my;
//        timeval_subtract_test2;
    
    
    /* 
     * Manual tests 
     */
    
    struct test_s {
        struct timeval x;
        struct timeval y;
        int minus;
        struct timeval res;
    };
    
    /* Test cases */
    struct test_s test[] = {
        {
            .x      =   {   .tv_sec = 0,    .tv_usec = 1000 },
            .y      =   {   .tv_sec = 0,    .tv_usec = 500  },
            .minus  = 0,
            .res    =   {   .tv_sec = 0,    .tv_usec = 500  }
        },
        {
            .x      =   {   .tv_sec = 0,    .tv_usec = 0 },
            .y      =   {   .tv_sec = 0,    .tv_usec = 500  },
            .minus  = 1,
            .res    =   {   .tv_sec = 0,    .tv_usec = 500  }
        },
    };
    
    int i;
    for (i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
        struct timeval res;
        int minus = subtract(&res, &(test[i].x), &(test[i].y));
        
        char ctminus = ((test[i].minus == 1) ? '-' : ' ');
        char cminus = ((minus == 1) ? '-' : ' ');
        printf("Testing [%ld.%06ld] - [%ld.%06ld] ?= [%c%ld.%06ld] "
                "(with result [%c%ld.%06ld]) ...",
                test[i].x.tv_sec, test[i].x.tv_usec,
                test[i].y.tv_sec, test[i].y.tv_usec,
                ctminus, test[i].res.tv_sec, test[i].res.tv_usec,
                cminus, res.tv_sec, res.tv_usec);
        
        if (    (res.tv_sec == test[i].res.tv_sec) &&
                (res.tv_usec == test[i].res.tv_usec) &&
                (minus == test[i].minus) )
            printf("OK\n");
        else
            printf("FAILED\n");
    }
    
    
    /* 
     * Automatic tests 
     */
    
    printf("Automatic test ...");

    /* Make all possible subtractions in defined range,
     * and compare it with test subtraction function result. */
    const int MIN   = 0;        /* From 0 */
    const int MAX   = 10000000; /* To 10 seconds */
    const int STEP  = 5000;     /* With 5000 usec step */
    
    uint64_t a, b;
    for (a = MIN; a < MAX; a += STEP) {
        for (b = MIN; b < MAX; b += STEP) {
            struct timeval x = uint64totv(a);
            struct timeval y = uint64totv(b);
            
            struct timeval res, tres;
            int minus = subtract(&res, &x, &y);
            int tminus = timeval_subtract_test(&tres, &x, &y);
            
            if (    (res.tv_sec != tres.tv_sec) ||
                    (res.tv_usec != tres.tv_usec) ||
                    (minus != tminus) ) {
                char cminus = ((minus == 1) ? '-' : ' ');
                char ctminus = ((tminus == 1) ? '-' : ' ');
                printf("[%ld.%06ld] - [%ld.%06ld] != [%c%ld.%06ld] "
                        "(with result [%c%ld.%06ld]) ...FAILED\n",
                        x.tv_sec, x.tv_usec,
                        y.tv_sec, y.tv_usec,
                        ctminus, tres.tv_sec, tres.tv_usec,
                        cminus, res.tv_sec, res.tv_usec);
                
                return (EXIT_FAILURE);
            }

        }
    }
    printf("OK\n");
    
    
    return (EXIT_SUCCESS);
}

