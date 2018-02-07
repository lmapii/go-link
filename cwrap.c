#include <stdio.h>
#include "_cgo_export.h"

// include library
#include "wrap_lib.h"

void c_init ()
{
    // using this approach to avoid having to pass a callback function directly to go
    // like this i could call init with a local function and simply invoke a go-function in this module
	(void) wrap_init (0);
}

void c_main ()
{
    printf("Hi from C++\n");
    HelloFromGo();
}