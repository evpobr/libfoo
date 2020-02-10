#ifndef FOO_FOO_FOO_H
#define FOO_FOO_FOO_H

#include "foo_export.h"

typedef struct foo_object *foo_ctx;

#ifdef __cplusplus
extern "C"
{
#endif

FOO_EXPORT int foo_new(foo_ctx *ctx);
FOO_EXPORT void foo_delete(foo_ctx ctx);

#ifdef __cplusplus
}
#endif

#endif
