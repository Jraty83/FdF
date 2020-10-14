cc -I /usr/local/include main_gnl.c draw_line.c map_validator.c ft_strlenws.c -o fdf libft/libft.a -L /usr/local/lib -I fdf.h -lmlx -framework OpenGL -framework AppKit
./fdf "NO_SUCH_FILE"
./fdf test_maps/false_oma_mirror_small.fdf
./fdf test_maps/false_pyramide.fdf
./fdf test_maps/empty.fdf
