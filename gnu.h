#ifndef GNU_H
#define GNU_H

#ifdef __cplusplus
extern "C" {
#endif

int timeval_subtract_gnu(struct timeval *result, 
        struct timeval *x, struct timeval *y);

#ifdef __cplusplus
}
#endif

#endif /* GNU_H */

