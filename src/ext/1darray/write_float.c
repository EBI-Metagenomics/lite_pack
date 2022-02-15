#include "lite_pack/ext/1darray/write_float.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_float.h"

void lip_write_1darray_f32_data(struct lip_ctx_file *ctx, unsigned size,
                                float const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(float)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_f32(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(float), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_f64_data(struct lip_ctx_file *ctx, unsigned size,
                                double const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(double)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_f64(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(double), 1, ctx->fp) != 1;
    }
}