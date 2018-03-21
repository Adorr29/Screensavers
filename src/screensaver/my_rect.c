/*
** EPITECH PROJECT, 2018
** Screensavers
** File description:
** my_rect.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "screensaver.h"

static void start(char tab[NB_CASE_X][NB_CASE_Y])
{
	static bool start = true;

	if (start == false)
		return;
	start = false;
	for (size_t i = 0; i < NB_CASE_X; i++)
		for (size_t j = 0; j < NB_CASE_Y; j++)
			tab[i][j] = rand() % 256;
}

void my_rect(sfRenderWindow *window)
{
	static char tab[NB_CASE_X][NB_CASE_Y] = {0};
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f size = {WINDOW_WIDTH / NB_CASE_X, WINDOW_HEIGHT / NB_CASE_Y};
	sfColor color = {COLOR, 0};

	start(tab);
	sfRectangleShape_setSize(rect, size);
	for (size_t i = 0; i < NB_CASE_X; i++)
		for (size_t j = 0; j < NB_CASE_Y; j++) {
			sfVector2f pos = {size.x * i, size.y * j};

			color.a = tab[i][j];
			sfRectangleShape_setFillColor(rect, color);
			sfRectangleShape_setPosition(rect, pos);
			sfRenderWindow_drawRectangleShape(window, rect, NULL);
			tab[i][j] == 0 ? tab[i][j] = rand() % 256 : tab[i][j]--;
		}
	sfRectangleShape_destroy(rect);
}
