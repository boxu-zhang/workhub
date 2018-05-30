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

    return session_mgr;
}

wh_cpp_host * wh_open_cpp_host()
{
    
}

int wh_cpp_session_create( wh_session * session )
{
    
}

int wh_cpp_session_close( wh_session * session )
{

}

int wh_cpp_session_read( wh_session * session )
{
    if ( !session )
        return WH_ERROR_INVALID_PARAMETER;

    if ( session->sock_client == INVALID_SOCKET || session->sock_client == NULL )
        return WH_ERROR_INVALID_PARAMETER;

    // read from socket
    
}

int wh_cpp_session_write( wh_session * session )
{

}

int wh_cpp_session_ctrl( wh_session * session )
{

}

int wh_session_mgr_new ( wh_session_mgr * session_mgr, socket client_socket, wh_session * session )
{
    if ( session_mgr->lua_host != NULL )
    {
        return wh_create_lua_session( session_mgr->lua_host, session );
    }

    // default session script is cpp
    wh_session * session;
    
    session->sock_client = client_socket;
    session->script_host = "cpp";
    session->script_host_data = NULL;
    session->fn_create = &wh_cpp_session_create;
    session->fn_close = &wh_cpp_session_close;
    session->fn_read = &wh_cpp_session_read;
    session->fn_write = &wh_cpp_session_write;
    session->fn_ctrl = &wh_cpp_session_ctrl;

    return wh_create_cpp_session( session_mgr->cpp_host, session );
}