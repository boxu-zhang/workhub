#include "workhub_epoll.h"

#if defined( _WIN32 )

wh_epool_t wh_create_epoll( void * ctx )
{
    HANDLE io_completion_port = CreateIoCompletionPort( NULL, NULL, (ULONG_PTR)ctx, 0 );

    return (wh_epoll_t)io_completion_port;
}

int wh_epoll_add( wh_epoll_t ep, wh_file_t fd )
{
    CreateIoCompletionPort( fd, ep, 0, 0 );

    return error_from_host( GetLassError() );
}

int wh_epoll_remove( wh_epoll_t ep, wh_file_t fd )
{
    return -1;
}



#else

#endif 