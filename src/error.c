#include "../includes/cub3D.h"

void	print_error_msg(char *str)
{
	ft_printf(RED"%s\n"RESET, str);
}

void	ft_exit(char *str, int error_code)
{
	print_error_msg(str);
	gc_clear(TMP, free);
	gc_clear(DATA, free);
	gc_clear(MATRIX, free);
	exit(error_code);
}
