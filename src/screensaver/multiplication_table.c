/*
** EPITECH PROJECT, 2018
** Screensavers
** File description:
** my_line.c
*/

#include <stdio.h>
#include <math.h>
#include "prototype.h"
#include "screensaver.h"

static const float radius = (WINDOW_HEIGHT / 2) * 0.9;

static sfCircleShape *circle_create(void)
{
	sfCircleShape *circle = sfCircleShape_create();
	const sfVector2f center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
	sfCircleShape_setPosition(circle, center);
	sfCircleShape_setOutlineThickness(circle, 1);
	sfCircleShape_setFillColor(circle, sfTransparent);
	sfCircleShape_setPointCount(circle, MODULO);
	return (circle);
}

static sfVector2f number_get_pos(const size_t number)
{
	sfVector2f pos = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

	pos.x += cos((number % MODULO) * 2 * M_PI / MODULO - M_PI / 2) * radius;
	pos.y += sin((number % MODULO) * 2 * M_PI / MODULO - M_PI / 2) * radius;
	return (pos);
}

void param_aff(sfRenderWindow *window, const double table)
{
	sfFont *font = sfFont_createFromFile(FONT_FILE);
	sfText *text = sfText_create();
	char str[50];

	sprintf(str, "table : %.2f\nmodulo : %d", table, MODULO);
	sfText_setFont(text, font);
	sfText_setString(text, str);
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
}

void multiplication_table(sfRenderWindow *window)
{
	static double table = START_TABLE;
	sfCircleShape *circle = circle_create();
	sfVertexArray *line = sfVertexArray_create();

	sfVertexArray_setPrimitiveType(line, sfLines);
	for (size_t i = 0; i < MODULO; i++) {
		sfVertex vertex = {.color = sfWhite};

		vertex.position = number_get_pos(i);
		sfVertexArray_append(line, vertex);
		vertex.position = number_get_pos(i * table);
		sfVertexArray_append(line, vertex);
	}
	sfRenderWindow_drawCircleShape(window, circle, NULL);
	sfRenderWindow_drawVertexArray(window, line, NULL);
	if (!sfKeyboard_isKeyPressed(sfKeySpace))
		table += 0.01;
	else
		param_aff(window, table);
	sfCircleShape_destroy(circle);
	sfVertexArray_destroy(line);
}
