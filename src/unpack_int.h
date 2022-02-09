#ifndef LIP_UNPACK_INT_H
#define LIP_UNPACK_INT_H

#include <stdint.h>

/* clang-format off */
#define __lip_unpack_signed(buf, val)                                            \
    sizeof(*val) == 1   ? __lip_unpack_i8(buf, (int8_t*)(val))                     \
    : sizeof(*val) == 2 ? __lip_unpack_i16(buf, (int16_t*)(val))                   \
    : sizeof(*val) == 4 ? __lip_unpack_i32(buf, (int32_t*)(val))                   \
    : sizeof(*val) == 8 ? __lip_unpack_i64(buf, (int64_t*)(val))                   \
                       : 0

#define __lip_unpack_unsigned(buf, val)                                          \
    sizeof(*val) == 1   ? __lip_unpack_u8(buf, (uint8_t*)(val))                    \
    : sizeof(*val) == 2 ? __lip_unpack_u16(buf, (uint16_t*)(val))                  \
    : sizeof(*val) == 4 ? __lip_unpack_u32(buf, (uint32_t*)(val))                  \
    : sizeof(*val) == 8 ? __lip_unpack_u64(buf, (uint64_t*)(val))                  \
                       : 0U

#define __lip_unpack_int(buf, val)                                               \
    _Generic((*val), signed char                                                \
             : __lip_unpack_signed(buf, val), signed short                       \
             : __lip_unpack_signed(buf, val), signed int                         \
             : __lip_unpack_signed(buf, val), signed long                        \
             : __lip_unpack_signed(buf, val), signed long long                   \
             : __lip_unpack_signed(buf, val), unsigned char                      \
             : __lip_unpack_unsigned(buf, val), unsigned short                   \
             : __lip_unpack_unsigned(buf, val), unsigned int                     \
             : __lip_unpack_unsigned(buf, val), unsigned long                    \
             : __lip_unpack_unsigned(buf, val), unsigned long long               \
             : __lip_unpack_unsigned(buf, val))
/* clang-format on */

unsigned __lip_unpack_i8(unsigned char const buf[], int8_t *val);
unsigned __lip_unpack_i16(unsigned char const buf[], int16_t *val);
unsigned __lip_unpack_i32(unsigned char const buf[], int32_t *val);
unsigned __lip_unpack_i64(unsigned char const buf[], int64_t *val);

unsigned __lip_unpack_u8(unsigned char const buf[], uint8_t *val);
unsigned __lip_unpack_u16(unsigned char const buf[], uint16_t *val);
unsigned __lip_unpack_u32(unsigned char const buf[], uint32_t *val);
unsigned __lip_unpack_u64(unsigned char const buf[], uint64_t *val);

#endif
