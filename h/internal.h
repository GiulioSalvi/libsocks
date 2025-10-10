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
#include "includes.h"

#ifndef _LIBSOCKS_INTERNAL_H_
    /** Include guard. */
#   define _LIBSOCKS_INTERNAL_H_

#   ifdef _LIBSOCKS_INTERNAL_
        /**
         * It is used internally to setup WinSocks2.
        **/
        HIDDEN_ABI errno_t init();
        /**
         * It is used internally to dispose WinSocks2.
        **/
        HIDDEN_ABI errno_t cleanup();
#   else /* defined(_LIBSOCKS_INTERNAL_) */
#       error "These functions are intended to be used internally only. Please, do not relay on anything declared in this header as it may be subject to changes or deletion at any moment."
#   endif
#endif /* !defined(_LIBSOCKS_INTERNAL_H_) */
