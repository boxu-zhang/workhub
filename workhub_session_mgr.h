#ifndef WORKHUB_SESSION_MGR_H_INCLUDED
#define WORKHUB_SESSION_MGR_H_INCLUDED

#include "workhub_session.h"

struct wh_session_mgr;

#if defined( __cplusplus )
extern "C" {
#endif

int wh_session_mgr_new( socket client_socket, wh_session * session );
int wh_session_mgr_find( socket client_socket, wh_session * session );
int wh_session_mgr_remove( wh_session * session );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_SESSION_MGR_H_INCLUDED