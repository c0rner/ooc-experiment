#ifndef __CLASS_H
#define __CLASS_H

struct Class {
    size_t size;
    void (*ctor)(void* self, va_list* args);
    void (*dtor)(void* self);
};

void* new(const struct Class, ...);
void delete(void*);

#endif
