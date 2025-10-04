#ifndef _LIBSOCKS_H_
    /** Include guard. */
#   define _LIBSOCKS_H_

#   include <stdio.h>
#   include <stdlib.h>

#   ifdef _WIN32
#       ifndef WIN32_LEAN_AND_MEAN
#           define WIN_32_LEAN_AND_MEAN
#       endif /* WIN32_LEAN_AND_MEAN */

#       include <windows.h>
#       include <winsock2.h>
#       include <ws2tcpip.h>
#   else
#       include <unistd.h>
#       include <sys/socket.h>
#   endif /* _WIN32 */

#endif /* _LIBSOCKS_H_ */
