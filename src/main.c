#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_struct();
	parse(ac, av, data);
	// init_mlx(data->mlx);
	// init_img(data->img);
	// init_sprites(data->mlx);
	// init_colors(data->mlx);
	// init_player(data->mlx);
	(void)data;
	return (0);
}
