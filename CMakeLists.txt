cmake_minimum_required (VERSION 2.6)
project (sleep C)

find_package (Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

add_library( sleep MODULE sleep.c )
set_target_properties( sleep PROPERTIES PREFIX "" )

# Only link against the Lua library on Windows
if(WIN32)
  target_link_libraries ( sleep ${LUA_LIBRARIES} )
endif()

# Needed to avoid getting undefined references to liblua
if(APPLE)
  set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -undefined dynamic_lookup")
endif()

# Build static library when cross-compiling
if(CMAKE_HOST_UNIX)
  add_library( libsleep STATIC sleep.c )
  target_link_libraries ( libsleep ${LUA_LIBRARIES} )
  set_target_properties ( libsleep PROPERTIES OUTPUT_NAME sleep )
endif()

# Install targets for Luarocks and UNIX, but not Windows
if(LUAROCKS_INSTALL_LIBDIR)
  SET(INSTALL_LIB_DIR ${LUAROCKS_INSTALL_LIBDIR})
elseif(UNIX)
  set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
endif()

if(INSTALL_LIB_DIR)
  install(TARGETS sleep ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" LIBRARY DESTINATION "${INSTALL_LIB_DIR}")
endif()