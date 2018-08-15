Simple example on how to link a locally built C-library to a Go application using `cgo`.

The demo consists of a wrapper C-module `cwrap.c` which wraps all calls to the library: Usually a C-library consists of different files where include-paths are passed to the compiler via `-I` and thus not explicitly listed in `#include` directives. This would not easily work when using C-modules with Go since `go build` isn't easily fed include directories.

Another module `module.go` uses these C-functions and also exports a function that is called from within the C-module. It demonstrates all the quirks of unallowed whitespaces before the `export` comment or no newline before `import "C"`.

## Usage

Make sure to put this repo into your `$GOPATH` or simply append `link-lib` to your `GOPATH` using `export GOPATH=$GOPATH:$(pwd)`

```
export GOPATH=$GOPATH:$(pwd)
cd src/submodule/clib
make clean && make
cd ../../
go build
./src
```

It should then output 

```
in wrap_lib: wrap_init
Hi from C
Hello from Go!
```

> Remark: Obviously you need to have Go installed. For building the C-library you'll need GCC or any other compiler. Check the `makefile` in `link-lib/src/submodule/clib/makefile` for the required tools.
