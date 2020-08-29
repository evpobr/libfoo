# foo_new(3)

## NAME

foo_new - create foo object

## SYNOPSIS

````c
#include <foo/foo.h>

FOO_EXPORT int foo_new(foo_ctx *ctx);
````

## DESCRIPTION

`foo_new`() creates new foo object.

## RETURN VALUE

`foo_new`() return `0` on success, negative error code otherwise.

## SEE ALSO

`foo_delete`(3)
