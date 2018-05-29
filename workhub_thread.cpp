/**
 * workhub_thread.cpp
 * 
 *  implement cross-platform thread create/close implementation
 */
#include "workhub_thread.h"

#if defined( _WIN32 )
#include <process.h>

int wait_from_host( DWORD wait )
{
    switch( wait )
    {
        case WAIT_OBJECT_0:
            return WH_WAIT_OK;
        case WAIT_TIMEOUT:
            return WH_WAIT_TIMEOUT;
        case WAIT_ERROR:
            return WH_WAIT_ERROR;
    }

    return WH_WAIT_ERROR;
}

wh_thread_id wh_create_thread( wh_thread_proc_t thread_proc, void * ctx )
{
    return (wh_thread_id)_beginthreadex( NULL, 0, (_beginthread_proc_type)thread_proc, ctx, 0, NULL );
}

int wh_wait_thread( wh_thread_id tid, int miliseconds )
{
    DWORD wait = WaitForSingleObject( (HANDLE)tid, miliseconds );

    return wait_from_host( wait );
}

void wh_close_thread( wh_thread_id tid )
{
    CloseHandle( (HANDLE)tid );
}

#else

#endif // 