#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "class.h"

void* new(const struct Class _class, ...) {
    struct Class* class;
    class = calloc(1, _class.size);
    memcpy(class, &_class, _class.size);

    if (_class.ctor) {
        va_list ap;
        va_start(ap, _class);
        _class.ctor(class, &ap);
        va_end(ap);
    }
    return class;
}

void delete(void* _class) {
    struct Class* class = _class;
    assert(class);
    if (class->ctor) class->dtor(class);
    free(class);
}

