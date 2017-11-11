#ifndef __STRING_H
#define __STRING_H

#include "class.h"

struct String {
    struct Class super;
    struct Buffer* buf;
    char* text;
};

char* String_ptr(struct String*);
size_t String_len(struct String*);

void String_ctor(void*, va_list*);
void String_dtor(void*);

static const struct Class String = {
    .size = sizeof(struct String),
    .ctor = String_ctor,
    .dtor = String_dtor
};

#endif
