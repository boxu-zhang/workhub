#ifndef WORKHUB_LUA_H_INCLUDED
#define WORKHUB_LUA_H_INCLUDED

struct lua_script_host;
struct lua_script_session;

#if defined( __cplusplus )
extern "C" {
#endif

lua_script_host * wh_open_lua_host();
void wh_close_lua_host( lua_script_host * lua_host );

lua_script_session * wh_create_lua_session( lua_script_host * lua_host, wh_session * session );
int wh_lua_session_execute( lua_script_session * lua_session, const char * file );
void wh_destroy_lua_session( lua_script_session * lua_session );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_LUA_H_INCLUDED