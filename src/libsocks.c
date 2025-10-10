/*
 Copyright (C) 2025  Giulio Salvi

 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this library.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "config.h"

#ifdef _LIBSOCKS_INTERNAL_
#   if BE_STRICT
#       error "_LIBSOCKS_INTERNAL_ is an internal macro and it should not be defined by the users."
#   else /* BE_STRICT */
#       undef _LIBSOCKS_INTERNAL

#       if defined(_MSC_VER)
#           pragma message("This is an internal macro and it should not be defined by the users. This macro has been disabled.")
#       else
#           warning "This is an internal macro and it should not be defined by the users. This macro has been disabled."
#       endif /* defined(_MSC_VER) */
#   endif
#else /* defined(_LIBSOCKS_INTERNAL_) */
#   define _LIBSOCKS_INTERNAL_
#endif

#include "libsocks.h"
#include "internal.h"

HIDDEN_ABI uint64_t _res_count = false;

HIDDEN_ABI errno_t init() {
#ifdef _WIN32
    WSADATA data;
    errno_t status = WSAStartup(MAKEWORD(2, 2),  &data);
    
    if(status == WSASYSNOTREADY)
        fprintf(stderr, "The network subsystem is not ready, please try again later.\n");
    else if(status == WSAVERNOTSUPPORTED)
        fprintf(stderr, "The system has not the prerequisites to run libsocks.\n");
    else if(status == WSAEINPROGRESS)
        fprintf(stderr, "Probably another program is using blocking system's socket APIs, please try again later.\n");
    else if(status == WSAEPROCLIM)
        fprintf(stderr, "Probably other programs are using system's socket APIs and they have saturated the network subsystem, please try again later.\n");

    if(status)
        return status;

    _res_count++;
#endif /* defined(_WIN32) */
}

HIDDEN_ABI errno_t cleanup() {
#ifdef _WIN32
    if(WSACleanup() == SOCKET_ERROR) {
        errno_t error = WSAGetLastError();

        if(error == WSANOTINITIALISED)
            fprintf(stderr, "The system's socket APIs have not been initialised; please ensure that you have had at least build a socket.\n");
        else if(error == WSAENETDOWN)
            fprintf(stderr, "The system's socket APIs or the network hardware have failed.\n");
        else if(error == WSAEINPROGRESS) {
            fprintf(stderr, "Probably another program is using blocking system's socket APIs; waiting...\n");

            while((error = WSACleanup()) == SOCKET_ERROR && WSAGetLastError() == WSAEINPROGRESS);
        }

        if(error)
            return error;

        _res_count--;
    }
#endif /* defined(_WIN32) */
}
