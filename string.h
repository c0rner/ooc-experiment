#ifndef __STRING_H
#define __STRING_H

#include "class.h"

struct String {
    struct Class super;
    struct Buffer* buf;
    char* text;
    size_t (*len)(struct String*);
};

extern void String_ctor(void*, va_list*);
extern void String_dtor(void*);

static const struct Class String = {
    .size = sizeof(struct String),
    .ctor = String_ctor,
    .dtor = String_dtor
};

#endif
