cmake_minimum_required (VERSION 2.6)
project (SleepModule C)

# Lua
find_package (Lua REQUIRED)

# Our Module
add_library( sleep MODULE sleep.c )
target_link_libraries ( sleep ${LUA_LIBRARIES} )
target_include_directories( sleep PRIVATE ${LUA_INCLUDE_DIR} )
set_target_properties( sleep PROPERTIES PREFIX "" )

if (UNIX OR CMAKE_HOST_UNIX)
add_library( sleep_s STATIC sleep.c )
target_link_libraries ( sleep_s ${LUA_LIBRARIES} )
target_include_directories ( sleep_s PRIVATE ${LUA_INCLUDE_DIR} )
set_target_properties ( sleep_s PROPERTIES OUTPUT_NAME sleep )
endif()