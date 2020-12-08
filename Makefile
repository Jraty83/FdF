# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 13:21:08 by jraty             #+#    #+#              #
#    Updated: 2020/12/08 10:53:23 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c draw.c reader.c background.c parser.c events.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = libft/libft.h

LIB = libft/libft.a

LIBDIR = libft

COMPFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L /Users/janne/lib -lmlx -I /usr/local/include/X11 -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit

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
