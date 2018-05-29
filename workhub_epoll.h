#ifndef WORKHUB_EPOOL_H_INCLUDED
#define WORKHUB_EPOOL_H_INCLUDED

typedef void * wh_epoll_t;

#if defined( __cplusplus )
extern "C" {
#endif

wh_epoll_t wh_create_epoll();
int wh_epoll_add( socket fd );
int wh_epoll_remove();
void wh_close_epoll( wh_epoll_t ep );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_EPOOL_H_INCLUDED