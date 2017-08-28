#include "stddef.h"
#include "solution.h"

int len(const char *string) {
    int res = 0;
    while (*string++) {
        res++;
    }
    return res;
}

int stringStat(const char *string, size_t multiplier, int *count) {
    (*count)++;
    return len(string) * multiplier;
}
