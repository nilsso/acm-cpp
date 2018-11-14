(See: <https://github.com/kigster/cmake-project-template> for project template details)

### Building
<kbd>mkdir -p build/manual && (cd build/manual && cmake ../.. && make && make install)</kbd>

### (Re)building
<kbd>(cd build/manual && make && make install)</kbd>

### Cleaning
<kbd>rm -rf ./{bin,lib,include,build}</kbd>

# Todo

- Local source includes use relative path filenames instead of
implementation-defined (i.e. CMake defined) filenames. So instead of `#include
"../util.h"` it should be `#include <util>`. But for now relative stays since
I'm too lazy to get Vim to figure out where to look as specified by CMake.
