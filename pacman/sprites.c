#include "sprites.h"
#include "../GLCD/GLCD.h"

// Pac-Man sprite facing right
uint16_t pacman_sprite_right[8][8] = {
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Black }
};

// Pac-Man sprite facing left
uint16_t pacman_sprite_left[8][8] = {
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Black, Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Black, Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black }
};

// Pac-Man sprite facing down
uint16_t pacman_sprite_down[8][8] = {
    { Black, Black, Black, Yellow, Yellow, Black, Black, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Yellow, Yellow, Yellow, Black, Black, Yellow, Yellow, Yellow },
    { Yellow, Yellow, Black, Black, Black, Black, Yellow, Yellow },
    { Black, Black, Black, Black, Black, Black, Black, Black }
};

// Pac-Man sprite facing up 
uint16_t pacman_sprite_up[8][8] = {
    { Black, Black, Black, Black, Black, Black, Black, Black },
    { Yellow, Yellow, Black, Black, Black, Black, Yellow, Yellow },
    { Yellow, Yellow, Yellow, Black, Black, Yellow, Yellow, Yellow },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Black, Black, Yellow, Yellow, Black, Black, Black }
};

uint16_t blinky_sprite[8][8] = {
		{Black, Black, Red,   Red,   Red,   Red,   Black, Black},
    {Black, Red,   Red,   Red,   Red,   Red,   Red,   Black},
    {Red,   White, Blue, Red,   Red,   White, Blue, Red},
    {Red,   White, White, Red,   Red,   White, White, Red},
    {Red,   Red,   Red,   Red,   Red,   Red,   Red,   Red},
    {Red,   Red, Red,   Red,   Red,   Red,   Red, Red},
    {Red,   Black, Red,   Red, Red, Red,   Black, Red},
    {Red, Black, Red, Red,   Red,   Red, Black, Red}
};

uint16_t power_pill_sprite[8][8] = {
		{ Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Green, Green, Black, Black, Black },
    { Black, Black, Green, Green, Green, Green, Black, Black },
    { Black, Green, Green, Green, Green, Green, Green, Black },
    { Black, Green, Green, Green, Green, Green, Green, Black },
    { Black, Black, Green, Green, Green, Green, Black, Black },
    { Black, Black, Black, Green, Green, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black }
};

uint16_t standard_pill_sprite[8][8] = {
		{ Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, White, White, Black, Black, Black },
    { Black, Black, White, White, White, White, Black, Black },
    { Black, Black, White, White, White, White, Black, Black },
    { Black, Black, Black, White, White, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Black, Black, Black, Black, Black }
};