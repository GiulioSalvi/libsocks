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

#ifndef _LIBSOCKS_CONFIG_H_
    /** Include guard. */
#   define _LIBSOCKS_CONFIG_H_

    /**
     * Used for triggering errors instead of warnings when asserted.
    **/
#   define BE_STRICT 0

#   ifdef _WIN32
        /**
         * ABI attributes for hiding symbols.
        **/
#       define HIDDEN_ABI
        /**
         * ABI attributes for exporting symbols.
        **/
#       define VISIBLE_ABI __declspec(dllexport)
#   else /* defined(_WIN32) */
        /**
         * ABI attributes for hiding symbols.
        **/
#       define HIDDEN_ABI __attribute__((visibility("hidden")))
        /**
         * ABI attributes for exporting symbols.
        **/
#       define VISIBLE_ABI __attribute__((visibility("default")))
#   endif
#endif /* !defined(_LIBSOCKS_CONFIG_H_) */
