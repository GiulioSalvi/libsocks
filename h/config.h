#ifndef _LIBSOCKS_CONFIG_H_
    /** Include guard. */
#   define _LIBSOCKS_CONFIG_H_

#   define BE_STRICT 1

#   ifdef _WIN32
#       define HIDDEN_ABI
#       define VISIBLE_ABI __declspec(dllexport)
#   else /* defined(_WIN32) */
#       define HIDDEN_ABI __attribute__((visibility("hidden")))
#       define VISIBLE_ABI __attribute__((visibility("default")))
#   endif
#endif /* !defined(_LIBSOCKS_CONFIG_H_) */
