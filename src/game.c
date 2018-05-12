/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** game.c
*/

#include "prototype.h"
#include "screensaver_tab.h"

int game(sfRenderWindow *window, size_t screensaver_num)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			evt_key_pressed(&event, &screensaver_num, NB_SCREENSAVER);
		}
		sfRenderWindow_clear(window, sfBlack);
		screensaver[screensaver_num](window);
		sfRenderWindow_display(window);
	}
	return (0);
}
