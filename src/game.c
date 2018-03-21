/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** game.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "screensaver_tab.h"

int game(sfRenderWindow *window)
{
	sfEvent event;
	size_t num = rand() % NB_SCREENSAVER;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			evt_key_pressed(&event, &num, NB_SCREENSAVER);
		}
		sfRenderWindow_clear(window, sfBlack);
		screensaver[num](window);
		sfRenderWindow_display(window);
	}
	return (0);
}
