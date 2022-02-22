#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/stdio_unlocked.h"
#include "lite_pack/unpack_map.h"

bool lip_read_map_size(struct lip_file *file, unsigned *size)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    switch (lip_format(file->buf))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        file->error = lip_fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error = lip_unpack_map_size(file->buf, size) == 0);
}