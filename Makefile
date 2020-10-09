# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 13:21:08 by jraty             #+#    #+#              #
#    Updated: 2020/10/07 15:49:27 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c \
		
LIB = libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(LIB) -L $(LIB) -lft
	cc -I /usr/local/include main.c libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
	@make clean -C $(LIB)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB)
	
re: fclean all
