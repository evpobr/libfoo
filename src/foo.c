#include "foo_priv.h"

#include <stdlib.h>

FOO_EXPORT int foo_new(foo_ctx *ctx)
{
    if (!ctx)
    {
        return -1;
    }
    *ctx = NULL;

    struct foo_object *obj = calloc(1, sizeof(*obj));
    if (!obj)
    {
        return -1;
    }

    *ctx = obj;

    return 0;
}

FOO_EXPORT void foo_delete(foo_ctx ctx)
{
    if (ctx)
    {
        free(ctx);
    }
}
