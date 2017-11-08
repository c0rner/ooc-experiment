#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#include "class.h"
#include "buffer.h"
#include "string.h"

int main(int argc, char** argv) {
    struct String* s = new(String, "Test");
    struct Buffer* b = new(Buffer, 4096);

    printf("Buffer obj size: %lu\n", b->super.size);
    printf("Buffer size: %lu\n", b->size);
    printf("String obj size: %lu\n", s->super.size);
    printf("String length: %lu\n", s->len(s));
    printf("String text: %s\n", s->text);
    delete(b);
    delete(s);
    return 0;
}
