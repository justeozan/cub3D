#include "../includes/cub3D.h"

void	print_error_msg(char *str)
{
	ft_printf(RED"%s\n"RESET, str);
}

// void	ft_exit(char *str, int error_code)
// {
// 	print_error_msg(str);
// 	gc_clear(TMP, free);
// 	gc_clear(DATA, free);
// 	gc_clear(MAP, free);
// 	gc_clear(SPRITES, free);
// 	exit(error_code);
// }

void	ft_exit(char *str)
{
	t_gc_id	id;

	id = -1;
	print_error_msg(str);
	while (++id < TMP)
		gc_clear(id, free);
	exit(EXIT_FAILURE);
}
