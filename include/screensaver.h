/*
** EPITECH PROJECT, 2017
** Screensavers
** File description:
** screensaver.h
*/

#ifndef SCREENSAVER_H_
#define SCREENSAVER_H_

// screensavers
#define NB_SCREENSAVER 3

// screensaver 0 (my_rect)
#define NB_CASE_X 16
#define NB_CASE_Y 9
#define COLOR 255, 0, 255
void my_rect(sfRenderWindow *window);

// screensaver 1 (my_line)
#define NB_POINT 200
void my_line(sfRenderWindow *window);

// screensaver 2 (multiplication_table)
#define START_TABLE 1
#define MODULO 300
void multiplication_table(sfRenderWindow *window);

#endif
