#### 11/13/2018

Finished the project structure setup as borrowed [cmake-project-template][cpt].
Still need to adapt the unit tests and `run.sh` script though.

Implemented a few utility functions:
1. `factor` which returns a vector of the factors of a given integer.
The algorithm used I implemented for a programming challenge over the summer
but originally in Python. It's a very simple algorithm and the project would
benefit from either implementing a stronger and more efficient implementation
or by finding and using a well-tested library that has implemented it already.
2. `join` which takes a vector of strings and joins them together using a
delimiter string. The motivation is for testing, and seeks to do exactly what
the `join` function in Python does.

Turned the project into a library called `acm` which implements the core
data-structure to represent ACM's, and an executable called `acm-main` which is
used as a terminal interface into testing the `acm` library functionality.

[cpt]:https://github.com/kigster/cmake-project-template<Paste>

#### 11/14/2018

Made `util` its own name-space and un-templated the functions there and fixed
the types to integers (since we only care about integers anyways).

Changed the `factor` implementation from including multiples of prime factors to
instead generating a vector of pairs of prime factors and their powers. This
also necessitated changing the return type of `ACM::factorizatons` and changing
the QOL printing function in `acm-main.cpp` to work on integer pair vectors.

Replaced all the old unit test sources with ones for `ACM` and `factor`. Only
the `factor` tests actually do anything as of now.

#### 11/15/2018

Added a function `integerDivisors` to `util` and changed `factor` to `pfactor`
(since it returns a vector of pairs of the *prime* divisors and their powers of
some number n).

Implemented more tests.

#### 11/16/2018

To get `lldb` working had to unlink the `python@2` package (`brew unlink
python@2`). Remember to re-link it.

#### 11/21/2018

Took a while to implement `factorizations` and went through multiple iterations
to get working. But now it works, and for multiple unit-tests. Finished
implementing `irreducible` and `irreducibles_up_to` as well. Changed the test
program to accept a optional operation argument and output the ACM result of the
operation.

