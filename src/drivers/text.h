#ifndef TEXT_H
#define TEXT_H

#include "screen.h"
#include "../cpu/types.h"

#define FONT_WIDTH 8
#define FONT_HEIGHT 8

void print_char(char c, int x, int y, color color, int size);
void print_string(char* s, int x, int y, color color, int size);

#endif