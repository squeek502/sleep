cmake_minimum_required (VERSION 2.6)
project (SleepModule)

# Lua
find_package (Lua REQUIRED)

# Our Module
add_library( sleep MODULE sleep.c )
target_link_libraries ( sleep ${LUA_LIBRARIES} )
target_include_directories( sleep PRIVATE ${LUA_INCLUDE_DIR} )