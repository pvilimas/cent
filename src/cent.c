#include "cent.h"

// advance by one frame
void cent_step()
{
    // TODO
}

// reset entities array and free all data
void cent_free()
{
    for (int i = 0; i < CENT_SIZE; i++) {
        free(cent.entities[i].data);
        cent.entities[i].alive = false;
    }
}

// exit with error
void cent_panic(const char* error)
{
    fprintf(stdout, "cent: %s\n", error);
    exit(1);
}

// generate a unique id for an entity
uint32_t cent_uid()
{
    uint32_t uid = 1; // skip 0
    while (!cent.entities[uid].alive) {
        uid++;
        if (uid >= CENT_SIZE) {
            cent_panic("out of memory, exiting");
        }
    }
    return uid;
}

uint32_t cent_create_entity_f(const char* typename, size_t size)
{
    uint32_t id = cent_uid();
    cent.entities[id] = (Entity) {
        .id = id,
        .alive = true,
        .type = typename,
        .data = malloc(size)
    };
    return id;
}