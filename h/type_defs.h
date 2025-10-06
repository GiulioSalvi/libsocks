#include "includes.h"

#ifndef _LIBSOCKS_TYPE_DEFS_H_
    /** Include guard. */
#   define _LIBSOCKS_TYPE_DEFS_H_

#   ifdef _WIN32
        typedef SOCKET sys_socket_t;
#   else /* defined(_WIN32) */
        typedef int fd_t;
        typedef fd_t sys_socket_t;
#   endif

    typedef unsigned short sock_t;
    typedef unsigned short addrf_t;
    typedef unsigned short protocol_t;

    struct socket_t {
        sys_socket_t id;
        sock_t socket_type;
        addrf_t address_family;
        protocol_t protocol_type;
    };

    typedef struct socket_t socket_t;

#   define ADDRF_LOCAL AF_UNIX
#   define ADDRF_INET AF_INET
#   define ADDRF_INET6 AF_INET6

#   define SOCK_TYPE_STREAM SOCK_STREAM
#   define SOCK_TYPE_DATAGRAM SOCK_DGRAM
#   define SOCK_TYPE_RAW SOCK_RAW

#   define PROTOCOL_TYPE_TCP IPPROTO_TCP
#   define PROTOCOL_TYPE_UDP IPPROTO_UDP
#endif /* !defined(_LIBSOCKS_TYPE_DEFS_H_) */
