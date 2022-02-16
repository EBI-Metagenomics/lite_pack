#ifndef LIP_1DARRAY_WRITE_INT_DATA_INPLACE_H
#define LIP_1DARRAY_WRITE_INT_DATA_INPLACE_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_io_file;

#define __lip_write_1darray_signed_data_inplace(i, s, a)                       \
    sizeof(*a) == 1 ? lip_write_1darray_i8_data_inplace(i, s, (int8_t *)(a))   \
    : sizeof(*a) == 2                                                          \
        ? lip_write_1darray_i16_data_inplace(i, s, (int16_t *)(a))             \
    : sizeof(*a) == 4                                                          \
        ? lip_write_1darray_i32_data_inplace(i, s, (int32_t *)(a))             \
    : sizeof(*a) == 8                                                          \
        ? lip_write_1darray_i64_data_inplace(i, s, (int64_t *)(a))             \
        : 0

#define __lip_write_1darray_unsigned_data_inplace(i, s, a)                     \
    sizeof(*a) == 1 ? lip_write_1darray_u8_data_inplace(i, s, (uint8_t *)(a))  \
    : sizeof(*a) == 2                                                          \
        ? lip_write_1darray_u16_data_inplace(i, s, (uint16_t *)(a))            \
    : sizeof(*a) == 4                                                          \
        ? lip_write_1darray_u32_data_inplace(i, s, (uint32_t *)(a))            \
    : sizeof(*a) == 8                                                          \
        ? lip_write_1darray_u64_data_inplace(i, s, (uint64_t *)(a))            \
        : 0U

#define __lip_write_1darray_int_data_typed_inplace(i, s, a)                    \
    _Generic(                                                                  \
        (*a), signed char                                                      \
        : __lip_write_1darray_signed_data_inplace(i, s, a), signed short       \
        : __lip_write_1darray_signed_data_inplace(i, s, a), signed int         \
        : __lip_write_1darray_signed_data_inplace(i, s, a), signed long        \
        : __lip_write_1darray_signed_data_inplace(i, s, a), signed long long   \
        : __lip_write_1darray_signed_data_inplace(i, s, a), unsigned char      \
        : __lip_write_1darray_unsigned_data_inplace(i, s, a), unsigned short   \
        : __lip_write_1darray_unsigned_data_inplace(i, s, a), unsigned int     \
        : __lip_write_1darray_unsigned_data_inplace(i, s, a), unsigned long    \
        : __lip_write_1darray_unsigned_data_inplace(i, s, a),                  \
          unsigned long long                                                   \
        : __lip_write_1darray_unsigned_data_inplace(i, s, a))

#define __lip_write_1darray_int_data_inplace(i, s, a)                          \
    __lip_write_1darray_int_data_typed_inplace(i, (a));

/* SIGNED */

LIP_API void lip_write_1darray_i8_data_inplace(struct lip_io_file *io,
                                               unsigned size, int8_t arr[]);

LIP_API void lip_write_1darray_i16_data_inplace(struct lip_io_file *io,
                                                unsigned size, int16_t arr[]);

LIP_API void lip_write_1darray_i32_data_inplace(struct lip_io_file *io,
                                                unsigned size, int32_t arr[]);

LIP_API void lip_write_1darray_i64_data_inplace(struct lip_io_file *io,
                                                unsigned size, int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8_data_inplace(struct lip_io_file *io,
                                               unsigned size, uint8_t arr[]);

LIP_API void lip_write_1darray_u16_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint16_t arr[]);

LIP_API void lip_write_1darray_u32_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint32_t arr[]);

LIP_API void lip_write_1darray_u64_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint64_t arr[]);

#endif