#ifndef CENT_H
#define CENT_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "glib.h"

#define BREAKPOINT()                \
    printf("breakpoint @ %s:%d\n",  \
    (strrchr((__FILE__), '/')       \
    ? strrchr((__FILE__), '/') + 1  \
    : (__FILE__)), __LINE__)

#define CENT_SIZE 100

typedef void (*EntityCallback)();

typedef struct {
    const char* name;
    EntityCallback update;
    EntityCallback render;
} EntityType;

typedef struct {
    uint32_t id;
    bool alive;
    EntityType type;
    void* data;
} Entity;

typedef struct {
    EntityType types[CENT_SIZE];
    Entity entities[CENT_SIZE]; // 0 = null entity
} Cent;
extern Cent cent;

#define cent_declare_types(...)                     \
    Cent cent = {                                   \
        .types = (EntityType[]) { __VA_ARGS__ },    \
        .entities = (EntityType[]) { 0 },           \
    }

#define type(t, render, update) \
    (EntityType) {              \
        .name = #t,             \
        .render = render,       \
        .update = update        \
    }

#define cent_create_entity(t) \
    cent_create_entity_f(#t, sizeof(t))

void cent_init();
void cent_step();
void cent_quit();
void cent_panic(const char* error);

uint32_t cent_uid();
uint32_t cent_create_entity_f(const char* typename, size_t size);

#endif // CENT_H