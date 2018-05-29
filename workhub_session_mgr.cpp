#include "workhub_session_mgr.h"
#include "workhub_config.h"
#include "workhub_lua.h"

// global variable
struct wh_session_mgr
{

    // define session script hosts
    wh_cpp_host * cpp_host;
    wh_lua_host * lua_host;
};

wh_session_mgr * wh_open_session_mgr ()
{
    wh_session_mgr * session_mgr = ( wh_session_mgr * )malloc( sizeof( wh_session_mgr ) );

    if ( !session_mgr )
        return NULL;

    // read global config
    const char * config_script = wh_get_config( "config_script" );

    if ( !strcmp( config_script, "lua" ) )
    {
        session_mgr->lua_host = wh_open_lua_host();
    }
    else
    {
        session_mgr->cpp_host = wh_open_cpp_host();
    }
}

wh_cpp_host * wh_open_cpp_host()
{
    
}

int wh_create_cpp_session( wh_cpp_host * cpp_host, wh_session * )
{
    
}

int wh_session_mgr_new (socket client_socket, wh_session * session )
{
    if ( session_mgr->lua_host != NULL )
    {
        return wh_create_lua_session( session_mgr->lua_host, session );
    }

    return wh_create_cpp_session( session_mgr->cpp_host, session );
}