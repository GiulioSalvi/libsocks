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

#include "includes.h"

#ifndef _LIBSOCKS_TYPE_DEFS_H_
    /** Include guard. */
#   define _LIBSOCKS_TYPE_DEFS_H_

#   ifdef _WIN32
        /**
         * Type for identifying socket system representation.
        **/
        typedef SOCKET sys_socket_t;

        /**
         * Used for flagging that the receptions channel must be shutdown.
        **/
#       define SHUTDOWN_RECEIVE SD_RECEIVE
        /**
         * Used for flagging that the transmissions channel must be shutdown.
        **/
#       define SHUTDOWN_SEND SD_SEND
        /**
         * Used for flagging that both channels must be shutdown.
        **/
#       define SHUTDOWN_BOTH SD_BOTH
#   else /* defined(_WIN32) */
        /**
         * Type used for identifying file descriptors on POSIX environments.
        **/
        typedef uint32_t fd_t;
        /**
         * Type used for identifying socket system representation.
        **/
        typedef fd_t sys_socket_t;

        /**
         * Used for flagging that the receptions channel must be shutdown.
        **/
#       define SHUTDOWN_RECEIVE SHUT_RD
        /**
         * Used for flagging that the transmissions channel must be shutdown.
        **/
#       define SHUTDOWN_SEND SHUT_WR
        /**
         * Used for flagging that both channels must be shutdown.
        **/
#       define SHUTDOWN_BOTH SHUT_RDWR
#   endif

    /**
     * Type used for identifying shutdown flags.
    **/
    typedef uint8_t shutdown_flags_t;
    /**
     * Type used for identifying the communication's characteristics.
    **/
    typedef uint8_t sock_t;
    /**
     * Type used for identifying the address families.
    **/
    typedef uint8_t addrf_t;
    /**
     * Type used for identifying the communication-layer protocols. 
    **/
    typedef uint8_t protocol_t;
    /**
     * Bitmask type used for representing the configuration of a socket:
     * - Bits 0 - 1: address family
     * - Bit 2: reserved
     * - Bits 3 - 4: socket type
     * - Bits 5 - 6: protocol type
     * - Bit 7: reserved
     * where bit 0 is the least significant bit.
    **/
    typedef uint8_t config_t;
    /**
     * Bitmask type used for representing the status of a socket:
     * - Bits 0 - 2: good/eof/fail/bad
     * - Bit 3: listening
     * - Bit 4: bound
     * - Bit 5: receiving
     * - Bit 6: writing
     * - Bit 7: shutdown
     * where bit 0 is the least significant bit.
    **/
    typedef uint8_t status_t;
    /**
     * Type used for representing a port number.
    **/
    typedef uint16_t port_t;

    /**
     * Type used for representing the IPv4 addresses.
    **/
    typedef uint32_t ipv4_addr_t;
    /**
     * Type used for representing the IPv4 subnet mask.
    **/
    typedef uint32_t ipv4_netmask_t;

    /**
     * A structure used for representing a linked-list of tuples containing informations about an IPv4 endpoint.
    **/
    struct ipv4_addrinfo {
        /**
         * The next IPv4 endpoint present in the linked-list.
        **/
        struct ipv4_addrinfo* next;
        /**
         * The address of this IPv4 endpoint.
        **/
        ipv4_addr_t v4_addr;
        /**
         * The subnet mask of this IPv4 endpoint.
        **/
        ipv4_netmask_t v4_netmask;
    };

    /**
     * Type for the structure `struct ipv4_addrinfo`.
    **/
    typedef struct ipv4_addrinfo ipv4_addrinfo_t;

    /**
     * A structure used for providing different memory layouts representations of an IPv6 address.
    **/
    struct ipv6_addr {
        union {
            /**
             * A 16 1-byte-blocks representation of an IPv6 address.
            **/
            uint8_t _ipv6_addr8[16];
            /**
             * A 8 2-bytes-blocks representation of an IPv6 address.
            **/
            uint16_t _ipv6_addr16[8];
            /**
             * A 4 4-bytes-blocks representation of an IPv6 address.
            **/
            uint32_t _ipv6_addr32[4];
        } _v6_addr;
    };

    /**
     * Type for the structure `struct ipv6_addr`.
    **/
    typedef struct ipv6_addr ipv6_addr_t;
    /**
     * A macro used for accessing the 16 1-byte-blocks representation of an IPv6 address by default.
    **/
#   define v6_addr_v _v6_addr._ipv6_addr8

    /**
     * Type used for representing the flow information on a connection based on IPv6.
    **/
    typedef uint32_t ipv6_flowinfo_t;
    /**
     * Tye used for representing the scope index of an IPv6 address.
    **/
    typedef uint32_t ipv6_scope_id_t;

    /**
     * A structure used for representing a linked-list of tuples containing informations about an IPv6 endpoint.
    **/
    struct ipv6_addrinfo {
        /**
         * The next IPv6 endpoint present in the linked-list.
        **/
        struct ipv6_addrinfo* next;
        /**
         * The flow information of this IPv6 endpoint.
        **/
        ipv6_flowinfo_t flowinfo;
        /**
         * The scope index of this IPv6 endpoint.
        **/
        ipv6_scope_id_t scope_id;
        /**
         * The address of this IPv4 endpoint.
        **/
        ipv6_addr_t v6_addr;
    };

    /**
     * Type for the structure `struct ipv6_addrinfo`.
    **/
    typedef struct ipv6_addrinfo ipv6_addrinfo_t;

    /**
     * Union between one structure containing IPv6 address information and two contiguous structures containing IPv4 address informations.
     * This is done in order to efficiently use the memory allocated since `sizeof(union ip_addrinfo) == sizeof(ipv6_addrinfo_t) == 2*sizeof(ipv4_addrinfo_t)`.
    **/
    union ip_addrinfo {
        /**
         * A structure containing IPv6 address informations.
        **/
        ipv6_addrinfo_t v6_addr;
        /**
         * Two contiguous structures containing IPv4 address informations.
         * This is done in order to efficiently use the memory allocated since `sizeof(union ip_addrinfo) == sizeof(ipv6_addrinfo_t) == 2*sizeof(ipv4_addrinfo_t)`.
         * Note: Even if they are contiguous, they should be iterated using the pointer `next` provided by the structure. It is guaranteed that the linked-list is not invalidated, i.e. `v4_addrs[0].next == &(v4_addrs[1])` and `v4_addrs[1].next != NULL` if `v4_addrs[1]` is not the last element of the linked-list.
        **/
        ipv4_addrinfo_t v4_addrs[2];
    };

    /**
     * Type for the union `union ip_addrinfo`.
    **/
    typedef union ip_addrinfo ip_addrinfo_t;

    /**
     * A structure used for representing a socket with its properties.
    **/
    struct socket_t {
        /**
         * The system-wide identifier for this socket.
        **/
        sys_socket_t id;
        /**
         * The system-wide identifier for the socket with whom this socket is connect to.
        **/
        sys_socket_t peer_id;
        /**
         * Pointer to the peer socket representation.
        **/
        struct socket_t* peer;
        /**
         * Pointer to address representation to which this socket is bound.
        **/
        ip_addrinfo_t* addr_info;
        /**
         * The maximum number of queued connections that this socket can handle.
        **/
        uint32_t max_conn;
        /**
         * The port to which this socket is bound.
        **/
        port_t port;
        /**
         * Bitmask for representing the status of a socket:
         * - Bits 0 - 2: good/eof/fail/bad
         * - Bit 3: listening
         * - Bit 4: bound
         * - Bit 5: receiving
         * - Bit 6: writing
         * - Bit 7: shutdown
         * where bit 0 is the least significant bit.
         **/
        status_t status;
        /**
         * Bitmask for representing the configuration of a socket:
         * - Bits 0 - 1: addrress family
         * - Bit 2: reserved
         * - Bits 3 - 4: socket type
         * - Bits 5 - 6: protocol type
         * - Bit 7: reserved
         * where bit 0 is the least significant bit.
        **/
        config_t config;
    };

    /**
     * Type for the structure `struct socket_t`.
    **/
    typedef struct socket_t socket_t;

    /**
     * Used for representing an unset address family property.
    **/
#   define ADDRF_UNSET 0u
    /**
     * Used for representing the local, also known as UNIX, address family.
    **/
#   define ADDRF_LOCAL 1u /* AF_UNIX */
    /**
     * Used for representing the INET address family.
    **/
#   define ADDRF_INET 2u /* AF_INET */
    /**
     * Used for representing the INET6 address family.
    **/
#   define ADDRF_INET6 3u /* AF_INET6 */

    /**
     * Used for representing an unset sock type property.
    **/
#   define SOCK_TYPE_UNSET 0u
    /**
     * Used for representing the stream socket type.
    **/
#   define SOCK_TYPE_STREAM 1u /* SOCK_STREAM */
    /**
     * Used for representing the datagram socket type.
    **/
#   define SOCK_TYPE_DATAGRAM 2u /* SOCK_DGRAM */
    /**
     * Used for representing the raw socket type.
    **/
#   define SOCK_TYPE_RAW 3u /* SOCK_RAW */

    /**
     * Used for representing an unset protocol type property.
    **/
#   define PROTOCOL_TYPE_UNSET 0u
    /**
     * Used for representing the TCP protocol type.
    **/
#   define PROTOCOL_TYPE_TCP 1u /* IPPROTO_TCP */
    /**
     * Used for representing the UDP protocol type.
    **/
#   define PROTOCOL_TYPE_UDP 2u /* IPPROTO_UDP */


#endif /* !defined(_LIBSOCKS_TYPE_DEFS_H_) */
