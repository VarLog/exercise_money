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

## Results

```
> time ./bin/money 1000 > log

real    0m6.503s
user    0m4.922s
sys     0m1.540s
> tail log
isDivisible( 1000 992 )
isDivisible( 1000 993 )
isDivisible( 1000 994 )
isDivisible( 1000 995 )
isDivisible( 1000 996 )
isDivisible( 1000 997 )
isDivisible( 1000 998 )
isDivisible( 1000 999 )
isDivisible( 1000 1000 )
calculateSum res: 248838
> time ./bin/money 18370 > log

real    278m50.354s
user    267m38.271s
sys     9m59.242s
> tail log
isDivisible( 18370 18362 )
isDivisible( 18370 18363 )
isDivisible( 18370 18364 )
isDivisible( 18370 18365 )
isDivisible( 18370 18366 )
isDivisible( 18370 18367 )
isDivisible( 18370 18368 )
isDivisible( 18370 18369 )
isDivisible( 18370 18370 )
calculateSum res: 84340880
>
```

That is all.
