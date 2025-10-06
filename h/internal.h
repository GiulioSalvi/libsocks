#include "config.h"

#ifndef _LIBSOCKS_INTERNAL_H_
    /** Include guard. */
#   define _LIBSOCKS_INTERNAL_H_

#   ifdef _LIBSOCKS_INTERNAL_
        HIDDEN_ABI void init();
        HIDDEN_ABI void cleanup();
#   else /* defined(_LIBSOCKS_INTERNAL_) */
#       error "These functions are intended to be used for internal usage only. Please, do not relay on anything declared in this header as it may be subject to changes or deletion in any moment."
#   endif
#endif /* !defined(_LIBSOCKS_INTERNAL_H_) */
