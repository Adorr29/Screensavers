/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** evt_key_pressed.c
*/

#include "prototype.h"

void evt_key_pressed(sfEvent *event, size_t *num, size_t num_max)
{
	if (event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyRight)
			*num >= num_max - 1 ? *num = 0 : (*num += 1);
		if (event->key.code == sfKeyLeft)
			*num == 0 ? *num = num_max - 1 : (*num -= 1);
	}
}
