# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/04 11:55:05 by mmacdona          #+#    #+#              #
#    Updated: 2018/08/04 11:55:06 by mmacdona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execfdf
FLAGS = gcc -Wall -Werror -Wextra 
SOURCES = main.c keyhook.c init.c perspective.c draw.c linear.c convert.c input.c mat4.c output.c t_mat4.c vector.c 

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
