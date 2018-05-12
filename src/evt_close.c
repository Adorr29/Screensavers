/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** evt_close.c
*/

#include "prototype.h"

void evt_close(sfEvent *event, sfRenderWindow *window)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			sfRenderWindow_close(window);
}
