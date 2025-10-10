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

#ifndef _LIBSOCKS_INCLUDE_H_
    /** Include guard. */
#   define _LIBSOCKS_INCLUDE_H_

#   include <errno.h>
#   include <stdio.h>
#   include <stdint.h>
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
#       include <ifaddrs.h>
#       include <sys/socket.h>
#       include <netinet/in.h>
#   endif
#endif /* !defined(_LIBSOCKS_INCLUDE_H_) */
