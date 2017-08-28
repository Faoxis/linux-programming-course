#include "stdio.h"
#include "solution.h"

int main() {

    int v = 1;
    int* p = &v;

    printf("%d\n", stringStat("hello", 2, p));
    printf("%d\n", *p);
}
