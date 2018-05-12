/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** menu.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "screensaver.h"

int menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, WINDOW_NAME, WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	game(window, rand() % NB_SCREENSAVER);
	sfRenderWindow_destroy(window);
	return (0);
}
