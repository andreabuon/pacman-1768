#include "sprites.h"
#include "../GLCD/GLCD.h"

uint16_t pacman_sprite[8][8] = {
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Black, Black, Black, Black },
    { Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, Black },
    { Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black },
    { Black, Black, Yellow, Yellow, Yellow, Yellow, Black, Black }
};

uint16_t power_pill_sprite[8][8] = {
		{ Black, Black, Black, Black, Black, Black, Black, Black },
    { Black, Black, Black, Red, Red, Black, Black, Black },
    { Black, Black, Red, Red, Red, Red, Black, Black },
    { Black, Red, Red, Red, Red, Red, Red, Black },
    { Black, Red, Red, Red, Red, Red, Red, Black },
    { Black, Black, Red, Red, Red, Red, Black, Black },
    { Black, Black, Black, Red, Red, Black, Black, Black },
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