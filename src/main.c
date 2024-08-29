/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 14:55:24 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	check_args(int ac, char	**args)
{
	if (ac != 2)
		ft_exit(ERR_ARGS);
	if (!ft_strnstr2(args[1], ".cub", 4))
		ft_exit(ERR_ARGS_1);
	if (SCREEN_HEIGHT < 100 || SCREEN_WIDTH < 100
		|| SCREEN_HEIGHT > 2160 || SCREEN_WIDTH > 3840
		|| SCREEN_HEIGHT != SCREEN_WIDTH)
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
	init_player(data, &data->player);
	print_all_infos(data);
	game_event_loop(data);
	return (0);
}
