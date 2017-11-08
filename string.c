#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "buffer.h"

struct String {
    struct Class super;
    struct Buffer* buf;
    char* text;
    size_t (*len)(struct String*);
};

size_t String_len(struct String* _self) {
    return strnlen(_self->buf->data, _self->buf->size);
}

void String_ctor(void* _self, va_list* args) {
    struct String* s = _self;
    const char* text = va_arg(*args, const char*);
    assert(s);

    // Allocate and set up string buffer
    s->buf = new(Buffer, strlen(text) + 1);
    assert(s->buf);
    s->text = s->buf->data;
    strcpy(s->text, text);

    // Initialise string methods
    s->len = String_len;
}

void String_dtor(void* _self) {
    struct String* s = _self;
    assert(s);
    delete(s->buf);
}
