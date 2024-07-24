#include "../includes/cub3D.h"

void	print_error_msg(char *str)
{
	ft_printf(RED"%s\n"RESET, str);
}


void	ft_exit(char *str, int error_code)
{
	print_error_msg(str);
	exit(error_code);
}
