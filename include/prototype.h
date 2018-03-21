/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <SFML/Graphics.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PARAMS sfFullscreen
#define FRAMERATE_LIMIT 30

int menu(void);
int game(sfRenderWindow *window);
void evt_close(sfEvent *event, sfRenderWindow *window);
void evt_key_pressed(sfEvent *event, size_t *num, size_t num_max);

#endif