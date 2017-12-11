#include <lua.h>
#include <lauxlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define EXPORT __declspec(dllexport)
#else
    #include <unistd.h>
    #define EXPORT
#endif

static int lua_sleep(lua_State *L)
{
    int ms = (int)luaL_checkinteger(L, 1);
    if (ms < 0)
        return luaL_error(L, "argument must be a positive integer");
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
    return 0;
}

EXPORT int luaopen_sleep(lua_State *L)
{
    lua_pushcfunction(L, lua_sleep);
    return 1;
}