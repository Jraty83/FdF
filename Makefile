# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 13:21:08 by jraty             #+#    #+#              #
#    Updated: 2020/12/01 15:06:40 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c draw_line.c map_validator.c ft_strlenws.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = libft/libft.h

LIB = libft/libft.a

LIBDIR = libft

COMPFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L /Users/janne/lib -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc -c $(SRCS)
	gcc $(COMPFLAGS) $(LIB) $(OBJS) $(LIBFLAGS) -I $(INCLUDES) -o $(NAME)

clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)
	
re: fclean all

.PHONY: all clean fclean re
