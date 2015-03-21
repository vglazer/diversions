#include <stdio.h>
#include <dlfcn.h>

#include "dynamic.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <function>\n", argv[0]);
        return 1;
    }

    void * handle = dlopen("./libdynamic.so", RTLD_NOW|RTLD_LOCAL);
    if (handle)
    {
        void (*function)(void) = (void(*)(void))dlsym(handle, argv[1]);
        if (!function)
        {
            fprintf(stderr, "%s\n", dlerror());
            return 1;
        }

        (*function)();
    }
    dlclose(handle);

    return 0;
}

