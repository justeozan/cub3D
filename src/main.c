#include "../includes/cub3D.h"

static void	check_args(int ac, char	**args)
{
	if (ac != 2)
		ft_exit(ERR_ARGS);
	if (!ft_strnstr2(args[1], ".cub", 4))
		ft_exit(ERR_ARGS_1);
	if (SCREEN_HEIGHT < 100 || SCREEN_WIDTH < 100
		|| SCREEN_HEIGHT > 2160 || SCREEN_WIDTH > 3840)
		ft_exit(ERR_ARGS_2);
}

int	main(int ac, char **av)
{
	t_data	*data;

	check_args(ac, av);
	data = init_struct();
	parse(av, data);
	init_mlx(&data->mlx);
	init_image(&data->img, data->mlx);
	init_sprites(data, &data->mlx);
	// init_player(data->mappy.content, data->player);
	(void)data;
	return (0);
}
