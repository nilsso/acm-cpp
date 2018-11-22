# Arithmetical Congruence Monoid C++

This project serves as a C++ implementation and extension of the
[acm-sage][acm-sage] project and was started as an undergraduate research
project.

<!--
   -## License
   -
   -This project was organized using [cmake-project-template][cpt] as a scaffold.
   -->

## Requirements

Building the project requires only a few packages:
- the [cmake](https://cmake.org/) build tool
- a C++ compiler with C++17 support (trying to keep things modern)

Install these via your favorite package manager.

## Installation

First clone and move into the project:

```bash
git clone https://github.com/nilsso/acm-cpp
cd acm-cpp
```

Then either:

- Run the helper script `./run.sh` (which makes and compiles the project in
`build/run`, installs the binaries to `bin`, runs the unit tests programs,
then runs a few examples of the `acm-main` test program)

- Or `mkdir build && cd build && cmake .. && make` to build manually

## Usage

Through the test program we can try out the functionality of the `acm` library:

Within the Hilbert monoid, we can find the divisors of and factorize 441, as
well as generate irreducible elements less than 100 (starting at 1):

```bash
./acm-main -H -d 441
# > (1,9,21,49,441)

./acm-main -H -f 441
# > ((9,49),(21,21))

./acm-main -H -n 100
# > (1,5,9,13,17,21,29,33,37,41,49,53,57,61,69,73,77,89,93,97)
```

<!--
   -## Miscellaneous other usages
   -
   -- building:
   -`mkdir -p build/manual && (cd build/manual && cmake ../.. && make && make install)`
   -
   -- (re)building:
   -`(cd build/manual && make && make install)`
   -
   -- cleaning:
   -`rm -rf ./{bin,lib,include,build}`
   -
   -- serve README.md (requiring [grip][grip]):
   -`nohup grip README >/dev/null 2>&1 &`
   -->

[acm-sage]:https://github.com/coneill-math/acm-sage
[cpt]:https://github.com/kigster/cmake-project-template
[grip]:https://github.com/joeyespo/grip
