/* 
 * File:   test.h
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on December 15, 2018, 10:34 PM
 */

#ifndef TEST_H
#define TEST_H

#ifdef __cplusplus
extern "C" {
#endif

int timeval_subtract_test(struct timeval *result, 
        struct timeval *x, struct timeval *y);

int timeval_subtract_test2(struct timeval *result, 
        struct timeval *x, struct timeval *y);

struct timeval uint64totv(uint64_t uint64);

uint64_t tvtouint64(struct timeval tv);


#ifdef __cplusplus
}
#endif

#endif /* TEST_H */

