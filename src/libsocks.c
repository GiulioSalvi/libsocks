#include "config.h"

#ifdef _LIBSOCKS_INTERNAL_
#   if BE_STRICT
#       error "_LIBSOCKS_INTERNAL_ is an internal macro and it should not be defined by the users."
#   else /* BE_STRICT */
#       if defined(_MSC_VER)
#           pragma message("This is an internal macro and it should not be defined by the users. This macro has been disabled.")
#       else
#           warning "This is an internal macro and it should not be defined by the users. This macro has been disabled."
#       endif /* defined(_MSC_VER) */

#       undef _LIBSOCKS_INTERNAL
#   endif
#else /* !defined(_LIBSOCKS_INTERNAL_) */
#   define _LIBSOCKS_INTERNAL_
#endif

#include "libsocks.h"
#include "internal.h"

HIDDEN_ABI bool initialized = false;

HIDDEN_ABI void init() {
#ifdef _WIN32
    WSADATA data;
    int status = WSAStartup(MAKEWORD(2, 2),  &data);
    
    if(status == WSASYSNOTREADY)
        fprintf(stderr, "The network subsystem is not ready, please try again later.\n");
    else if(status == WSAVERNOTSUPPORTED)
        fprintf(stderr, "The system has not the prerequisites to run libsocks.\n");
    else if(status == WSAEINPROGRESS)
        fprintf(stderr, "Probably another program is using blocking system's socket APIs, please try again later.\n");
    else if(status == WSAEPROCLIM)
        fprintf(stderr, "Probably other programs are using system's socket APIs and they have saturated the network subsystem, please try again later.\n");

    if(status)
        exit(status);

    initialized = true;
#endif /* defined(_WIN32) */
}

HIDDEN_ABI void cleanup() {
#ifdef _WIN32
    if(WSACleanup() == SOCKET_ERROR) {
        int error = WSAGetLastError();

        if(error == WSANOTINITIALISED)
            fprintf(stderr, "The system's socket APIs have not been initialised; please ensure that you have had at least build a socket.\n");
        else if(error == WSAENETDOWN)
            fprintf(stderr, "The system's socket APIs or the network hardware have failed.\n");
        else if(error == WSAEINPROGRESS) {
            fprintf(stderr, "Probably another program is using blocking system's socket APIs; waiting...\n");

            while((error = WSACleanup()) == SOCKET_ERROR && WSAGetLastError() == WSAEINPROGRESS);
        }

        if(error)
            exit(error);

        initialized = false;
    }
#endif /* defined(_WIN32) */
}
