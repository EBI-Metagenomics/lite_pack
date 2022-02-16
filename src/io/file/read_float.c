#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_float.h"

bool __lip_read_f32(struct lip_io_file *io, float *val)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    if (lip_format(io->buf) != LIP_FMT_FLOAT_32)
    {
        io->error = true;
        return false;
    }

    io->error = fread(io->buf + 1, 4, 1, io->fp) != 1;
    if (io->error) return false;

    return !(io->error = __lip_unpack_f32(io->buf, val) == 0);
}

bool __lip_read_f64(struct lip_io_file *io, double *val)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    unsigned sz = 0;
    if (lip_format(io->buf) == LIP_FMT_FLOAT_32)
    {
        sz = 4;
    }
    else if (lip_format(io->buf) == LIP_FMT_FLOAT_64)
    {
        sz = 8;
    }
    else
    {
        io->error = true;
        return false;
    }

    io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
    if (io->error) return false;

    return !(io->error = __lip_unpack_f64(io->buf, val) == 0);
}
