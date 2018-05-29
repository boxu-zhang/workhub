#include "workhub_threadpoll.h"

struct _thread_pool_t
{
    int              thread_count;
    wh_thread_id *   threads;
};

size_t thread_pool_length( int thread_count )
{
    return sizeof( wh_thread_id * ) * thread_count + sizeof( thread_count );
}

wh_thread_pool_t wh_create_thread_pool( wh_thread_proc_t thread_proc, void * ctx )
{
    _thread_pool_t * thread_pool = ( _thread_pool_t * )malloc( thread_pool_length( number_of_hyperthread() ) );

    thread_pool->thread_count = number_of_hyperthread();
    
    for ( int i = 0; i < thread_pool->thread_count; ++i )
    {
        thread_pool->threads[ i ] = wh_create_thread( thread_proc, ctx );
    }

    return (wh_thread_pool_t)thread_pool;
}

void wh_destroy_thread_pool( wh_thread_pool_t thread_pool )
{
    _thread_pool_t * _thread_pool = ( _thread_pool_t * )thread_pool;

    for ( int i = 0; i < _thread_pool->thread_count; ++i )
    {
        wh_close_thread( _thread_pool->threads[ i ] );
    }

    free( _thread_pool );
}

