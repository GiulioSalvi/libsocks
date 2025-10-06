#ifndef _LIBSOCKS_INCLUDE_H_
    /** Include guard. */
#   define _LIBSOCKS_INCLUDE_H_

#   include <stdio.h>
#   include <stdlib.h>
#   include <stdbool.h>

#   ifdef _WIN32
#       ifndef WIN32_LEAN_AND_MEAN
#           define WIN_32_LEAN_AND_MEAN
#       endif /* !defined(WIN32_LEAN_AND_MEAN) */

#       include <winsock2.h>
#       include <windows.h>
#       include <ws2tcpip.h>
#   else /* defined(_WIN32) */
#       include <unistd.h>
#       include <sys/socket.h>
#       include <netinet/in.h>
#   endif
#endif /* !defined(_LIBSOCKS_INCLUDE_H_) */
