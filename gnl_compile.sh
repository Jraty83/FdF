# cc -I /usr/local/include main_gnl.c draw_line.c map_validator.c ft_strlenws.c -o fdf libft/libft.a -L /usr/local/lib -I fdf.h -lmlx -framework OpenGL -framework AppKit
cc -I /usr/local/X11/include main_gnl.c draw_line.c map_validator.c ft_strlenws.c -o fdf libft/libft.a -L /Users/janne/lib -I fdf.h -lmlx -framework OpenGL -framework AppKit
# cc -L /Users/janne/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit
