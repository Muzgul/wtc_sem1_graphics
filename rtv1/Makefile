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

NAME = rtv1
FLAGS = gcc -Wall -Werror -Wextra 
SOURCES = main.c angle.c camera.c free.c init.c input_fetch.c input.c object.c vector.c output.c mat4.c t_mat4.c collision.c light.c misc.c list.c error.c check_input.c config.c

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

