#include <lua.h>
#include <lauxlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define EXPORT __declspec(dllexport)
#else
    #include <sys/time.h>
    #include <unistd.h>
    #define EXPORT
#endif

static int lc_sleep(lua_State *L)
{
    int ms = luaL_checkint(L, 1);
    if (ms < 0)
        return luaL_error(L, "argument must be a positive integer");
#ifdef _WIN32
    Sleep(ms);
#else
    struct timeval tv;
    tv.tv_sec = (long)ms / 1000L;
    tv.tv_usec = (long)ms % 1000L * 1000L;
    select(0, NULL, NULL, NULL, &tv);
#endif
    return 0;
}

EXPORT int luaopen_sleep(lua_State *L)
{
    lua_pushcfunction(L, lc_sleep);
    return 1;
}