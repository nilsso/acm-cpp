# Arithmetical Congruence Monoid C++

This project serves as a C++ implementation and extension of the
[acm-sage][acm-sage] project and was started as an undergraduate research
project.

## License

This project was organized using [cmake-project-template][cpt] as a scaffold.

## Usage

To set up a local build environment:

```
mkdir build
cd build
cmake ..
make
```

## Other usages

- building:<br/>
<kbd>mkdir -p build/manual && (cd build/manual && cmake ../.. && make && make install)</kbd>

- (re)building:<br/>
<kbd>(cd build/manual && make && make install)</kbd>

- cleaning:<br/>
<kbd>rm -rf ./{bin,lib,include,build}</kbd>

- serve README.md (requiring [grip][grip]):<br/>
<kbd>nohup grip README >/dev/null 2>&1 &</kbd>

## Todo

- Local source includes use relative path filenames instead of
implementation-defined (i.e. CMake defined) filenames. So instead of `#include
"../util.h"` it should be `#include <util>`. But for now relative stays since
I'm too lazy to get Vim to figure out where to look as specified by CMake.
- Fix TravisCI and `run.sh`

[acm-sage]:https://github.com/coneill-math/acm-sage
[cpt]:https://github.com/kigster/cmake-project-template
[grip]:https://github.com/joeyespo/grip
