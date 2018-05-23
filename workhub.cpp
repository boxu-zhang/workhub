#if defined( _WIN32 ) // Windows part

#include <windows.h>
#include <winsock2.h>

#else // Linux part

#endif 

// include C runtime library
#include <stdio.h>
#include <stdlib.h>

// include workhub library
#include "workhub_thread.h"
#include "workhub_error.h"

// constants
#define WH_MAJOR_VERSION                    0
#define WH_MINOR_VERSION                    1
#define WH_INVALID_SOCKET                   INVALID_SOCKET
#define WH_MAX_LISTEN_BACKLOG               10

int accept_thread_proc( socket sock_server )
{

}

int main( int argc, char * argv[] )
{
    printf( "hello workhub(version %d.%d)\n", WH_MAJOR_VERSION, WH_MINOR_VERSION );

    int     errno       = WH_ERROR_SUCCESS;
    socket  sock_sever  = WH_INVALID_SOCKET;
    char *  sock_addr   = argv[1];
    ushort  sock_port   = atoi( argv[2] );
    int     tid         = -1;
    
    do
    {
        sock_server = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

        if ( WH_INVALID_SOCKET == sock_server )
        {
            errno = WH_ERROR_OUT_OF_RESOURCE;
            break;
        }

        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.port       = htons( sock_port );
        addr.S_addr     = inet_addr( sock_addr );

        errno = error_from_host( bind( sock_server, (sockaddr *)&addr, sizeof( addr ) ) );
        
        if ( errno != WH_ERROR_SUCCESS )
            break;
        
        printf( "workhub bind %s:%d", sock_addr, (int)sock_port );

        error = error_from_host( listen( sock_server, WH_MAX_BACKLOG ) );

        if ( errno != WH_ERROR_SUCCESS )
            break;

        // create accept thread
        tid = wh_create_thread( (wh_thread_proc_t)&accept_thread_proc, (void*)sock_server );

        if ( tid == WH_INVALID_THREAD )
        {
            error = WH_ERROR_OUT_OF_RESOURCE;
            break;
        }

        printf( "workhub is listening, using help for command:\n" );

        while ( ( char * line = getline( stdin, ) != NULL )
        {
            if ( !stricmp( line, "quit" ) )
                break;
        }

        printf( "workhub is closing\n" );
        shutdown( sock_server, 0 );
        error = wh_wait_thread( tid, 5000 );

        if ( error != WH_ERROR_SUCCESS )
        {
            printf( "workhub closed ungracefully, wait for thread timeout\n" );
            break;
        }

    } while ( false );

    closesocket( sock_server );

    if ( errno != WH_ERROR_SUCCESS )
        wh_dump_error( errno );

    return errno;
}