#include "cent.h"

struct player {
    float x, y;
    int hp;
};

void player_render() {
    printf("rendering player\n");
}

void player_update() {
    printf("updating player\n");
}

struct enemy {
    float x, y;
    int hp;
};

void enemy_render() {
    printf("rendering player\n");
}

void enemy_update() {
    printf("updating player\n");
}

cent_declare_types(
    type(struct player, player_render, player_update),
    type(struct enemy, enemy_render, enemy_update)
);

int main() {
    cent_init();

    Entity* e = cent_create_entity(struct player);

    cent_step();
    cent_quit();
    return 0;
}