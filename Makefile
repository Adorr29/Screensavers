##
## EPITECH PROJECT, 2017
## Screensavers
## File description:
## Makefile
##

NAME	=	Screensavers

CC	=	gcc

SRCDIR	=	src/
SSDIR	=	$(SRCDIR)screensaver/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)menu.c \
		$(SRCDIR)game.c \
		$(SRCDIR)evt_close.c \
		$(SRCDIR)evt_key_pressed.c \
		$(SSDIR)my_rect.c \
		$(SSDIR)my_line.c \
		$(SSDIR)multiplication_table.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-l csfml-system
LDFLAGS	+=	-l csfml-window
LDFLAGS	+=	-l csfml-graphics
LDFLAGS	+=	-l m

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
