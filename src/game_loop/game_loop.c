/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sei <sei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:13:34 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 17:23:22 by sei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ray_casting(t_data *data)
{
	t_ray		ray;
	t_player	*player;
	t_dda		wall_ray;
	double		camera_x;
	int			x;

	x = 0;
	player = &data->player;
	draw_floor_ceiling(data, data->img);
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		init_ray(&ray, *player, camera_x);
		init_ray_dda(&ray);
		init_wall_dda(&(data->map), &ray, &wall_ray);
		print_col(data, &wall_ray, &ray, x);
		x++;
	}
	mlx_put_image_to_window
		(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
}

int	game_loop(t_data *data)
{
	modif_player(data);
	ray_casting(data);
	set_get_data(data);
	return (0);
}

void	game_event_loop(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17, close_program, data);
	mlx_loop_hook(data->mlx.mlx_ptr, game_loop, (void *)data);
	mlx_loop(data->mlx.mlx_ptr);
}
