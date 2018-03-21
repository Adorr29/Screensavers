/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** menu.c
*/

#include "prototype.h"

int menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "Game", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	game(window);
	sfRenderWindow_destroy(window);
	return (0);
}
