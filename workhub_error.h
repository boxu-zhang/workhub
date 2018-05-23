/**
 * workhub_error.h
 * 
 */

#ifndef WORKHUB_ERROR_H_INCLUDED
#define WORKHUB_ERROR_H_INCLUDED

// errors
#define WH_ERROR_SUCCESS                    0
#define WH_ERROR_UNKNOWN                    -1
#define WH_ERROR_OUT_OF_RESOURCE            -2
#define WH_ERROR_OUT_OF_MEMORY              -3
#define WH_ERROR_INVALID_PARAMETER          -4

#if defined( __cplusplus )
extern "C" {
#endif 

int error_from_host( int errno );
int error_from_wh( int errno );
void wh_dump_error( int errno );

#if defined( __cplusplus )
}
#endif

#endif // WORKHUB_ERROR_H_INCLUDED
