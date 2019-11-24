# Commify Code Challenge
This is my solution to the Commify Code Challenge. It is imlemented in C++ using object oriented principles.
## Building this project
### Prerequisites
* [GCC/G++](https://gcc.gnu.org/)
* [Boost C++ Libraries](https://www.boost.org/)
* [CMake](https://cmake.org/) (minimum version 3.14.7)
### Linux-Based OSes
On Linux systems, all the prerequisites should be preinstalled. If not, many popular distributions include them in their official repositories.
#### Running tests:
```
$ cd commify-challenge
```
Running using the included bash script:
```
$ chmod +x run-tests
$ ./run-tests
```
Running manually using CMake:
Create a directory to put CMake build files. This example will use `cmake-test-build`.
```
$ mkdir cmake-test-build
$ cd cmake-test-build
$ cmake ../test/
$ make
$ ./Tests
```
#### Running main:
```
$ cd commify-challenge
```
Running using the included bash script:
```
$ chmod +x run-main
$ ./run-main
```
Running manually using CMake:
Like running tests, create a directory to put CMake build files. This example will use `cmake-main-build`.
```
$ mkdir cmake-main-build
$ cmake ../
$ make
$ ./Checkout
```

