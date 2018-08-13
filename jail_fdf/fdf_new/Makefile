# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 10:18:38 by mmacdona          #+#    #+#              #
#    Updated: 2018/07/09 10:18:39 by mmacdona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execfdf
FLAGS = gcc -Wall -Werror -Wextra 
SOURCES = main.c input.c vector.c output.c linear.c translate.c perspective.c draw.c matrix.c

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