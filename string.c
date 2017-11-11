#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "buffer.h"
#include "string.h"

char* String_ptr(struct String* self) {
    assert(self);
    return self->text;
}

size_t String_len(struct String* self) {
    assert(self);
    return strnlen(self->text, Buffer_size(self->buf));
}

void String_ctor(void* _self, va_list* args) {
    struct String* self = _self;
    const char* text = va_arg(*args, const char*);
    assert(self);
    assert(text);

    // Allocate and set up string buffer
    self->buf = new(Buffer, strlen(text) + 1);
    assert(self->buf);
    self->text = Buffer_ptr(self->buf);
    strcpy(self->text, text);
}

void String_dtor(void* _self) {
    struct String* s = _self;
    assert(s);
    delete(s->buf);
}
