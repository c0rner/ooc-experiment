#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#include "class.h"
#include "buffer.h"
#include "string.h"

int main(void) {
    struct String* s = new(String, "This is test string");
    struct Buffer* b = new(Buffer, 4096);

    printf("Buffer obj size: %lu\n", b->super.size);
    printf("Buffer size: %lu\n", Buffer_size(b));
    printf("String obj size: %lu\n", s->super.size);
    printf("String length: %lu\n", String_len(s));
    printf("String text: %s\n", String_ptr(s));
    delete(b);
    delete(s);
    return 0;
}
