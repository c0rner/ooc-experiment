#ifndef __BUFFER_H
#define __BUFFER_H

#include "class.h"

struct Buffer {
    struct Class super;
    size_t size;
    char* data;
};

size_t Buffer_size(struct Buffer*);
char* Buffer_ptr(struct Buffer*);

void Buffer_ctor(void*, va_list*);
void Buffer_dtor(void*);

static const struct Class Buffer = {
    .size = sizeof(struct Buffer),
    .ctor = Buffer_ctor,
    .dtor = Buffer_dtor
};

#endif
