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

#ifndef _LIBSOCKS_H_
    /** Include guard. */
#   define _LIBSOCKS_H_

#   include "config.h"
#   include "includes.h"
#   include "type_defs.h"

VISIBLE_ABI errno_t libsocks_socket(socket_t* socket, addrf_t address_family, sock_t socket_type, protocol_t protocol_type);
VISIBLE_ABI errno_t libsocks_connect(socket_t* socket, ip_addrinfo_t* address_info, addrf_t address_family);
VISIBLE_ABI errno_t libsocks_bind(socket_t* socket, ip_addrinfo_t* address_info, addrf_t address_family);
VISIBLE_ABI errno_t libsocks_listen(socket_t* socket, uint32_t max_connections);
VISIBLE_ABI errno_t libsocks_accept(socket_t* socket);
VISIBLE_ABI ssize_t libsocks_send(socket_t* socket, void* buffer, size_t buffer_size, int _ /* reserved */);
VISIBLE_ABI ssize_t libsocks_recv(socket_t* socket, void* buffer, size_t buffer_size, int _ /* reserved */);
VISIBLE_ABI errno_t libsocks_close(socket_t* socket);
VISIBLE_ABI errno_t libsocks_shutdown(socket_t* socket, shutdown_flags_t flags);
#endif /* !defined(_LIBSOCKS_H_) */
