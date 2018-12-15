#ifndef SO_H
#define SO_H

#ifdef __cplusplus
extern "C" {
#endif

int timeval_subtract_so(struct timeval *result, 
        struct timeval *x, struct timeval *y);

#ifdef __cplusplus
}
#endif

#endif /* SO_H */

