#ifndef WORKHUB_THREAD_H_INCLUDED
#define WORKHUB_THREAD_H_INCLUDED

typedef int wh_thread_id;

typedef int (*wh_thread_proc_t)(void * ctx);

#define WH_WAIT_OK      0
#define WH_WAIT_TIMEOUT 1
#define WH_WAIT_ERROR   2

#if defined( __cplusplus )
extern "C" {
#endif

wh_thread_id wh_create_thread( wh_thread_proc_t thread_proc, void * ctx );
int wh_wait_thread( wh_thread_id tid, int miliseconds );
void wh_close_thread( wh_thread_id tid );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_THREAD_H_INCLUDED