/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** screensaver_tab.h
*/

#ifndef SCREENSAVER_TAB_H_
#define SCREENSAVER_TAB_H_

#include "screensaver.h"

typedef void (*screensaver_t)(sfRenderWindow *window);

static screensaver_t screensaver[NB_SCREENSAVER] = {
	my_rect,
	my_line,
	multiplication_table
};

#endif
