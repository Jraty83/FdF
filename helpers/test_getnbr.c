#include "../libft/libft.h"
#include <stdio.h>

int        ft_getnbr(char *str)
{
    size_t    i;
    int        result;

    result = 0;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        result = (result * 10) + (str[i++] - 48);
    if (str[0] == '-')
        result *= -1;
    return (result);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
//		printf("atoi output is: %d\n", atoi(argv[1]));
//		printf("ft_getnbr output: %d\n", ft_getnbr(argv[1]));
		printf("ft_getnbr output: %d\n", ft_getnbr(argv[1])) && printf("atoi  output  is: %d\n", atoi(argv[1]));
	}
	return (0);
}
