# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 15:57:29 by mmacdona          #+#    #+#              #
#    Updated: 2018/08/15 15:57:30 by mmacdona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = gcc -Wall -Werror -Wextra 
SOURCES = main.c cam.c draw_search.c draw.c free.c init.c input.c keyhook.c matrix.c output.c persp.c vect.c valid.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C minilibx
	@$(FLAGS) -c $(SOURCES)
	@$(FLAGS) -o $(NAME) $(OBJECTS) -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit	

clean:
	@make -C libft/ clean
	@make -C minilibx/ clean
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx/ clean
	@/bin/rm -f $(NAME)

re: fclean all

