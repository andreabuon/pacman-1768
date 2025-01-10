#include "pathfinding.h"

#include <math.h>
#include <limits.h>

int get_euclidean_distance(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2) {
    int dx = (int) row1 - (int) row2;    
    int dy = (int) col1 - (int) col2;

    return sqrt((double)(dx * dx) + (dy * dy));
}


static int is_valid_position_blinky(Game* game, int x, int y) {
    return (x >= 0 && x < MAP_LENGTH) && (y >= 0 && y < MAP_HEIGHT) && (game->map[y][x].type != WALL);
}

// Function to find the closest direction towards Pacman
enum Direction get_closest_next_direction(Game* game) {
    int min_distance = INT_MAX;
    enum Direction best_direction = DEFAULT_BLINKY_DIRECTION;

    // Evaluate each direction
    struct {
        int dx, dy;
        enum Direction dir;
    } moves[] = {
        {0, -1, UP},
        {0, 1, DOWN},
        {-1, 0, LEFT},
        {1, 0, RIGHT},
    };

    for (int i = 0; i < 4; i++) {
        int new_x = game->blinky_x + moves[i].dx;
        int new_y = game->blinky_y + moves[i].dy;

        if (is_valid_position_blinky(game, new_x, new_y)){
            int distance = get_euclidean_distance(new_y, new_x, game->pacman_y, game->pacman_x);
            if (distance < min_distance) {
                min_distance = distance;
                best_direction = moves[i].dir;
            }
        }
    }

    return best_direction;
}

// Function to find the furthest direction from Pacman
enum Direction get_furthest_next_direction(Game* game) {
    int max_distance = 0;
    enum Direction best_direction = DEFAULT_BLINKY_DIRECTION;

    struct {
        int dx, dy;
        enum Direction dir;
    } moves[] = {
        {0, -1, UP},
        {0, 1, DOWN},
        {-1, 0, LEFT},
        {1, 0, RIGHT},
    };

    for (int i = 0; i < 4; i++) {
        int new_x = game->blinky_x + moves[i].dx;
        int new_y = game->blinky_y + moves[i].dy;

        if (is_valid_position_blinky(game, new_x, new_y)) {
            int distance = get_euclidean_distance(new_y, new_x, game->pacman_y, game->pacman_x);
            if (distance > max_distance) {
                max_distance = distance;
                best_direction = moves[i].dir;
            }
        }
    }

    return best_direction;
}