package submodule

import (
	"fmt"
)

/*
#include <stdint.h>
#include <stdlib.h>
void c_init ();
void c_main ();
#cgo CFLAGS: -I ./clib
#cgo LDFLAGS: -L ${SRCDIR}/clib/bld -lcustom
*/
import "C"

// go build will work for "#cgo LDFLAGS: ${SRCDIR}/clib/bld/testlib.so"
// but then it will fail when executing (Reason: image not found)

// HelloFromGo why should i need to comment this. Also, next line a space before export is not allowed ...
//export HelloFromGo
func HelloFromGo() {
	fmt.Println("Hello from Go!")
}

// CallLib .
func CallLib() {
	C.c_init()
	C.c_main()
}
