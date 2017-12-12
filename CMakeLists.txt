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
add_library( libsleep STATIC sleep.c )
target_link_libraries ( libsleep ${LUA_LIBRARIES} )
target_include_directories ( libsleep PRIVATE ${LUA_INCLUDE_DIR} )
set_target_properties ( libsleep PROPERTIES OUTPUT_NAME sleep )
endif()

# LUA is set by Luarocks
if (LUA)
  SET(INSTALL_LIB_DIR ${LIBDIR})
elseif (UNIX OR APPLE)
  set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
endif()

if (INSTALL_LIB_DIR)
  install(TARGETS sleep ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" LIBRARY DESTINATION "${INSTALL_LIB_DIR}")
endif ()