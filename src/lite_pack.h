#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "format.h"
#include "pack.h"
#include "skip.h"
#include "unpack.h"

static inline unsigned long lip_pack_bool(uint8_t buf[static 1], bool val);

#define lip_pack_int(buf, val) __lip_pack_int(buf, val)

#define lip_pack_float(buf, val) __lip_pack_float(buf, val)

static inline unsigned lip_pack_str_size(uint8_t buf[static 1], unsigned size);
static inline unsigned lip_pack_str_data(uint8_t buf[static 1], unsigned size,
                                         char const str[static 1]);

static inline unsigned long lip_pack_array_head(uint8_t buf[static 1],
                                                unsigned size);

static inline unsigned lip_pack_map_size(uint8_t buf[static 1], unsigned size);

unsigned lip_unpack_bool(uint8_t const buf[static 1], bool *val);
#define lip_unpack_int(buf, val) __lip_unpack_int(buf, val)
#define lip_unpack_float(buf, val) __lip_unpack_float(buf, val)
// char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1]);
unsigned lip_unpack_str_size(uint8_t const buf[static 1], unsigned *size);
unsigned lip_unpack_str_data(uint8_t const buf[static 1], unsigned size,
                             char str[static 1]);
unsigned lip_unpack_array_head(uint8_t const buf[static 1], unsigned *size);
unsigned lip_unpack_map_size(uint8_t const buf[static 1], unsigned *size);

/* clang-format off */
enum lip_format;
enum lip_format_family;

static inline int lip_format(uint8_t const buf[static 1]);
static inline int lip_format_family(uint8_t const buf[static 1]);

static inline unsigned long lip_skip(uint8_t const buf[static 1]);
static inline unsigned long lip_skip_head(uint8_t const buf[static 1]);
static inline unsigned long lip_skip_body(uint8_t const buf[static 1]);
/* clang-format on */

#endif
