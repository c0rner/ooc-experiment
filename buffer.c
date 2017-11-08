#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "buffer.h"
#include "class.h"

void Buffer_ctor(void* _self, va_list* args) {
    struct Buffer* b = _self;
    const size_t size = va_arg(*args, const size_t);

    assert(b);
    b->size = size;
    b->data = calloc(1, size);
    assert(b->data);
}

void Buffer_dtor(void* _self) {
    struct Buffer* b = _self;
    assert(b);
    free(b->data);
}
