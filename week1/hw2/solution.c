#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int (*someSecretFunctionPrototype)(int);

bool init_function(const char *libraryName, const char *functionName, int parameter) {

    void *hdl = dlopen(libraryName, RTLD_LAZY);
    if (NULL == hdl) return false;

    someSecretFunctionPrototype = (int (*)(int)) dlsym(hdl, functionName);
    if (NULL == someSecretFunctionPrototype) return false;

    return true;
}


int main(int argc, char **argv) {

    const char *libraryName = argv[1];
    const char *functionName = argv[2];
    int number = atoi(argv[3]);


    init_function(libraryName, functionName, number);

    printf("%d\n", someSecretFunctionPrototype(number));
    return 0;
}