# sleep

[![Build Status](https://travis-ci.org/squeek502/sleep.svg?branch=master)](https://travis-ci.org/squeek502/sleep)
[![Build status](https://ci.appveyor.com/api/projects/status/bxrotq7ei7p3gkns?svg=true)](https://ci.appveyor.com/project/squeek502/sleep)

Bare-bones Lua module that exposes a millisecond-precision sleep function

```lua
local sleep = require('sleep')

-- sleep for 1 second
sleep(1000)
```

## Installation
With [Luarocks](https://luarocks.org):
```
luarocks install sleep
```

## Building
To build sleep, you'll need to install [`cmake`](https://cmake.org) and some C compiler. If you're compiling for Windows, you'll also need to have a Lua static library available that [can be found by `cmake`](https://cmake.org/cmake/help/v3.0/module/FindLua.html) (preferably built with the same compiler you're using to build sleep).

### On Windows
Open a command line in the `sleep` directory and do the following:
```sh
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
If needed, you can specify a [generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) by doing `cmake -G "Visual Studio 14 2015 Win64" ..` instead of `cmake ..`

### On Linux
From the `sleep` directory, do the following:
```sh
mkdir build && cd build
cmake ..
make
```