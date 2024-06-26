#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../cpu/types.h"

#define KEYBOARD_PORT 0x60
#define KEYBOARD_RELEASE 0x80
#define NUM_OF_KEYS 88

#define KEY_IS_PRESS(_s) (!((_s) & KEYBOARD_RELEASE))

extern bool keyboard_keys[NUM_OF_KEYS];

void init_keyboard();

//key defines

#define KEY_ESCAPE 1

#define KEY_1 2
#define KEY_2 3
#define KEY_3 4
#define KEY_4 5
#define KEY_5 6
#define KEY_6 7
#define KEY_7 8
#define KEY_8 9
#define KEY_9 10
#define KEY_0 11

#define KEY_DASH 12
#define KEY_EQUAL 13
#define KEY_BACKSPACE 14
#define KEY_TAB 15

#define KEY_Q 16
#define KEY_W 17
#define KEY_E 18
#define KEY_R 19
#define KEY_T 20
#define KEY_Y 21
#define KEY_U 22
#define KEY_I 23
#define KEY_O 24
#define KEY_P 25
#define KEY_OPENING_SQUARE_BRACKETS 26
#define KEY_CLOSING_SQUARE_BRACKETS 27
#define KEY_ENTER 28
#define KEY_LEFT_CONTROL 29
#define KEY_A 30
#define KEY_S 31
#define KEY_D 32
#define KEY_F 33
#define KEY_G 34
#define KEY_H 35
#define KEY_J 36
#define KEY_K 37
#define KEY_L 38
#define KEY_SEMICOLON 39
#define KEY_SINGLE_QOUTE 40
#define KEY_BACK_TICK 41
#define KEY_LEFT_SHIFT 42
#define KEY_BACKSLASH 43
#define KEY_Z 44
#define KEY_X 45
#define KEY_C 46
#define KEY_V 47
#define KEY_B 48
#define KEY_N 49
#define KEY_M 50
#define KEY_COMMA 51
#define KEY_DOT 52
#define KEY_SLASH 53
#define KEY_RIGHT_SHIFT 54
#define KEY_KEYPAD_STAR 55
#define KEY_LEFT_ALT 56
#define KEY_SPACE 57
#define KEY_CAPSLOCK 58

#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67
#define KEY_F10 68
#define KEY_NUMBER_LOCK 69
#define KEY_SCROLL_LOCK 70
#define KEY_KEYPAD_7 71
#define KEY_KEYPAD_8 72
#define KEY_KEYPAD_9 73
#define KEY_KEYPAD_DASH 74
#define KEY_KEYPAD_4 75
#define KEY_KEYPAD_5 76
#define KEY_KEYPAD_6 77
#define KEY_KEYPAD_PLUS 78
#define KEY_KEYPAD_1 79
#define KEY_KEY_KEYPAD_2 80
#define KEY_KEY_KEYPAD_3 81
#define KEY_KEY_KEYPAD_0 82
#define KEY_KEY_KEYPAD_DOT 83

#define KEY_F11 87
#define KEY_F12 88




#endif