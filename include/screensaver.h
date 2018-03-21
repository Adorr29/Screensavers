/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** screensaver.h
*/

#ifndef SCREENSAVER_H_
#define SCREENSAVER_H_

// screensaver 1 (my_rect)
#define NB_CASE_X (1920 / 120)
#define NB_CASE_Y (1080 / 120)
#define COLOR 255, 0, 255
void my_rect(sfRenderWindow *window);

// screensaver 2 (my_line)
#define NB_POINT 200
void my_line(sfRenderWindow *window);

#endif
