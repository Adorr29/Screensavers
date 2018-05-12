/*
** EPITECH PROJECT, 2018
** Screensavers
** File description:
** my_line.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "prototype.h"
#include "screensaver.h"

static void start(sfVector2f tab[], float angle[], float speed[])
{
	static bool start = true;

	if (start == false)
		return;
	start = false;
	for (size_t i = 1; i < NB_POINT; i++) {
		tab[i].x = rand() % (WINDOW_WIDTH + 500) - 250;
		tab[i].y = rand() % (WINDOW_HEIGHT + 500) - 250;
		angle[i] = rand() % 360 * M_PI / 180.0;
		speed[i] = rand() % 501 / 100.0 + 1.0;
	}
}

static char get_dist(sfVector2f a, sfVector2f b)
{
	float dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

	if (dist > 255)
		dist = 255;
	dist = 255 - dist;
	return (dist);
}

static void move(sfRenderWindow *win, sfVector2f t[], float angle[], float sd[])
{
	t[0].x = sfMouse_getPositionRenderWindow(win).x;
	t[0].y = sfMouse_getPositionRenderWindow(win).y;
	for (size_t i = 1; i < NB_POINT; i++) {
		bool tmp = false;

		t[i].x += cos(angle[i]) * sd[i];
		t[i].y += sin(angle[i]) * sd[i];
		t[i].x < -300 || t[i].x > WINDOW_WIDTH + 300 ? tmp = true : 0;
		t[i].y < -300 || t[i].y > WINDOW_HEIGHT + 300 ? tmp = true : 0;
		if (tmp) {
			tmp = rand() & 2;
			t[i].x = rand() % (WINDOW_WIDTH + 500) - 250;
			t[i].y = rand() % (WINDOW_HEIGHT + 500) - 250;
			t[i].x = !tmp && rand() & 2 ? WINDOW_WIDTH + 250 : -250;
			t[i].y = tmp && rand() & 2 ? WINDOW_HEIGHT + 250 : -250;
			angle[i] = rand() % 360 * M_PI / 180.0;
			sd[i] = rand() % 501 / 100.0 + 1.0;
		}
	}
}

static void l_modif(sfVertexArray *l, float d, sfVector2f tab1, sfVector2f tab2)
{
	sfVertex point = {.color = sfWhite};

	point.color.a = d;
	point.position = tab1;
	sfVertexArray_append(l, point);
	point.position = tab2;
	sfVertexArray_append(l, point);
}

void my_line(sfRenderWindow *window)
{
	static sfVector2f tab[NB_POINT] = {0};
	static float angle[NB_POINT] = {0};
	static float speed[NB_POINT] = {0};
	sfVertexArray *l = sfVertexArray_create();

	start(tab, angle, speed);
	sfVertexArray_setPrimitiveType(l, sfLines);
	move(window, tab, angle, speed);
	for (size_t i = 0; i < NB_POINT; i++)
		for (size_t j = i + 1; j < NB_POINT; j++) {
			float d = get_dist(tab[i], tab[j]);

			d ? l_modif(l, d, tab[i], tab[j]) : 0;
			d ? sfRenderWindow_drawVertexArray(window, l, NULL) : 0;
			d ? sfVertexArray_clear(l) : 0;
		}
	sfVertexArray_destroy(l);
}
