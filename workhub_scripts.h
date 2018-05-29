#ifndef WORKHUB_SCRIPTS_H_INCLUDED
#define WORKHUB_SCRIPTS_H_INCLUDED

#include "workhub_session.h"

struct wh_script_host;
struct wh_script_session;

#if defined( __cplusplus )
extern "C" {
#endif

wh_script_host wh_open_script_host( const char * name );
void wh_close_script_host( wh_script_host * script_host );

wh_script_session * wh_open_script_session( wh_script_host * script_host, wh_session * session );
int wh_script_session_execute( wh_script_session * session, const char * file );
void wh_close_script_session( wh_script_session * session );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_SCRIPTS_H_INCLUDED