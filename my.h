/* 
 * File:   my.h
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on December 15, 2018, 10:24 PM
 */

#ifndef MY_H
#define MY_H

#ifdef __cplusplus
extern "C" {
#endif

int timeval_subtract_my(struct timeval *result, 
        struct timeval *x, struct timeval *y);

#ifdef __cplusplus
}
#endif

#endif /* MY_H */

