/**
 * workhub_error.cpp
 * 
 */
#include "workhub_error.h"

#if defined( _WIN32 )

// for windows 
#include <winerror.h>

// convert windows error to workhub errors
int error_from_host( int errno )
{
    switch( errno )
    {
        case ERROR_INVALID_PARAMETER:
            return WH_ERROR_INVALID_PARAMETER;
    }

    return WH_ERROR_UNKNOWN;
}

int error_from_wh( int errno )
{
    switch( errno )
    {
        case WH_ERROR_SUCCESS:
            return ERROR_SUCCESS;
    }

    return E_FAIL;
}

#else

// for linux
#include <errno.h>

// convert windows error to workhub errors
int error_from_host( int errno )
{
    return WH_ERROR_UNKNOWN;
}

int error_from_wh( int errno )
{
    return -1;
}

#endif

const char * wh_dump_error( int errno )
{
    static const char * error_messages [] = 
    {
        "Error Success",
        "Error Unknow",
        "Error Out of resource",
        "Error Out of memory",
        "Error invalid parameter",
    };

    if ( errno == 0 )
        return error_messages[ 0 ];

    if ( errno > 0 )
        return "Not an error message";
    
    if ( 0 - error < _countof( error_messages ) )
        return error_messages[ 0 - error ];

    return "Unrecoginzed error number";
}