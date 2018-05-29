#ifndef WORKHUB_SESSION_H_INCLUDED
#define WORKHUB_SESSION_H_INCLUDED

struct wh_session
{
    int (*fn_create)( wh_session * session );
    int (*fn_read)( wh_session * session );
    int (*fn_write)( wh_session * session );
    int (*fn_close)( wh_session * session );
    int (*fn_ctrl)( wh_session * session );
};

#if defined( __cplusplus )
extern "C" {
#endif

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_SESSION_H_INCLUDED