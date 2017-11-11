#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "buffer.h"
#include "class.h"

size_t Buffer_size(struct Buffer* self) {
    assert(self);
    return self->size;
}

char* Buffer_ptr(struct Buffer* self) {
    assert(self);
    return self->data;
}

void Buffer_ctor(void* _self, va_list* args) {
    struct Buffer* self = _self;
    const size_t size = va_arg(*args, const size_t);

    assert(self);
    self->size = size;
    self->data = calloc(1, size);
    assert(self->data);
}

void Buffer_dtor(void* _self) {
    struct Buffer* self = _self;
    assert(self);
    free(self->data);
}
