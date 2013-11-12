#include <iostream>
#include <lua.hpp>

extern "C" {
    #include "system.h"
}


#define NUM_INSTRUCTIONS 10000

// Filesystem functions for core.utils.fs
int make_dir(lua_State* L)
{
    const char* path = lua_tostring(L, -1);
    fs_makedir(path);
    return 0;
}
int is_dir(lua_State* L)
{
    const char* path = lua_tostring(L, -1);
    lua_pushboolean(L, fs_is_dir(path));
    return 1;
}
typedef struct cb_struct {
    int ref;
    lua_State* L;
} cb_struct;

void list_dir_cb(const char *name, int is_dir, void *user)
{
    cb_struct* s = (cb_struct*) user;
    int ref = s->ref;
    lua_State* L = s->L;
    //call lua function with arguments
    lua_rawgeti(L, LUA_REGISTRYINDEX, ref);
    lua_pushstring(L, name);
    lua_pushboolean(L, is_dir);
    lua_pcall(L, 2, 0, 0);
}

int list_dir(lua_State* L)
{
    // get path and callback function
    const char* path = lua_tostring(L, -2);
    int ref = luaL_ref(L, LUA_REGISTRYINDEX);
    cb_struct s;
    s.ref = ref;
    s.L = L;
    fs_listdir(path, list_dir_cb, (void*) &s);
    luaL_unref(L, LUA_REGISTRYINDEX, ref);
    return 0;
}
// Curl functions for core.network.curl

// Hook functions for core.utils.sandbox
void hook(lua_State* l, lua_Debug* ar)
{
    lua_yield(l, 0);
}
int set_hook(lua_State *L)
{
    int num = lua_tointeger(L, -1);
    if (num > 0) {
        lua_sethook(L, hook, LUA_MASKCOUNT, num);
    } else {
        lua_sethook(L, hook, LUA_MASKCOUNT, NUM_INSTRUCTIONS);
    }
    return 0;
}
int remove_hook(lua_State *L)
{
    lua_sethook(L, hook, 0, 0);
    return 0;
}

// MAIN
int main(int argc, char* argv[])
{
        lua_State* super = luaL_newstate();
	lua_State* L;
        luaL_openlibs(super);
        luaL_Reg fs_reg [] = {{"make_dir",make_dir}, {"is_dir",is_dir},{"list_dir",list_dir},{NULL, NULL}};
        luaL_Reg hook_reg [] = {{"set_hook", set_hook}, {"remove_hook", remove_hook},{NULL, NULL}};
        luaL_register(super, "hook", hook_reg);
        luaL_register(super, "fs", fs_reg);


        L = lua_newthread(super);
                //luaJIT_setmode(L, 0, LUAJIT_MODE_ENGINE|LUAJIT_MODE_OFF);

        std::string script = argc >= 2 ? std::string(argv[1]) : "client.lua";
	int error = luaL_loadfile( L, script.c_str() );

        //setting debug hook
        //lua_sethook(L, hook, LUA_MASKCOUNT, NUM_INSTRUCTIONS);
        //lua_sethook(L, hook, LUA_MASKLINE, 0);

        if (error) {
		std::cerr << lua_tostring( L, -1 ) << std::endl;
		lua_pop( L, 1 );
	}

        int status = lua_resume(L, 0);
        while (status == LUA_YIELD){
            status = lua_resume(L,0);
        }
        if (status) {
		std::cerr << lua_tostring( L, -1 ) << std::endl;
		lua_pop( L, 1 );
	}
        //lua_sethook(L, hook, 0, 0);


	lua_close(super);

	return 0;
}

