#ifndef LIP_IO_FILE_H
#define LIP_IO_FILE_H

#include "lite_pack/export.h"
#include "lite_pack/io/file_ctx.h"
#include "lite_pack/io/file_read_float.h"
#include "lite_pack/io/file_read_int.h"
#include "lite_pack/io/file_write_float.h"
#include "lite_pack/io/file_write_int.h"

/* FILE WRITE */

LIP_API void lip_write_bool(struct lip_ctx_file *ctx, bool val);
#define lip_write_int(ctx, val) __lip_write_int(ctx, val)
#define lip_write_float(ctx, val) __lip_write_float(ctx, val)
LIP_API void lip_write_array_size(struct lip_ctx_file *ctx, unsigned size);
LIP_API void lip_write_map_size(struct lip_ctx_file *ctx, unsigned size);
LIP_API void lip_write_str_size(struct lip_ctx_file *ctx, unsigned size);
LIP_API void lip_write_str_data(struct lip_ctx_file *ctx, unsigned size,
                                char const val[]);
LIP_API void lip_write_ext_size_type(struct lip_ctx_file *ctx, unsigned size,
                                     uint8_t type);

/* FILE READ */

LIP_API void lip_read_bool(struct lip_ctx_file *ctx, bool *val);
#define lip_read_int(ctx, val) __lip_read_int(ctx, val)
#define lip_read_float(ctx, val) __lip_read_float(ctx, val)
LIP_API void lip_read_array_size(struct lip_ctx_file *ctx, unsigned *size);
LIP_API void lip_read_map_size(struct lip_ctx_file *ctx, unsigned *size);
LIP_API void lip_read_str_size(struct lip_ctx_file *ctx, unsigned *size);
LIP_API void lip_read_str_data(struct lip_ctx_file *ctx, unsigned size,
                               char val[]);
LIP_API void lip_read_ext_size_type(struct lip_ctx_file *ctx, unsigned *size,
                                    uint8_t *type);

#endif