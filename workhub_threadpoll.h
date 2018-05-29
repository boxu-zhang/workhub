#ifndef WORKHUB_THREADPOOL_H_INCLUDED
#define WORKHUB_THREADPOOL_H_INCLUDED

#include "workhub_thread.h"

typedef void * wh_thread_pool_t;

#if defined( __cplusplus )
extern "C" {
#endif

wh_thread_pool_t wh_create_thread_pool( wh_thread_proc_t thread_proc, void * ctx );
void wh_destroy_thread_pool( wh_thread_pool_t thread_pool );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_THREADPOOL_H_INCLUDED