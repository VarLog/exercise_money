# Money and prime numbers
=================

Simple exercise:

![](money.jpg)

## Source structure

* `src/money` contains whole the implementation;
* `test/money` contains Google C++ Testing Framework tests.

## Build

Use CMake:

```
> mkdir build
> cd build
> cmake ..
> make
> ./bin/money
...
```

## Tests

For testing purposes this project uses Google C++ Testing Framework. To enable tests you should define `ENABLE_TESTS=ON` variable:

```
> cmake -DENABLE_TESTS=ON ..
> make
> ./bin/money_test
...
```
