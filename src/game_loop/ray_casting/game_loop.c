/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:13:34 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 05:12:12 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	ray_casting(t_data *data)
{
	t_ray		ray;	//REVIEW - Understand what this struct is
	t_player	*player;
	t_dda		wall_ray; //REVIEW - Choose a better name for this struct
	double		camera_x;
	int			x;

	x = 0;
	player = &data->player;
	draw_floor_ceiling(data, data->img);
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		init_ray(&ray, player, camera_x);
		init_ray_dda(&wall_ray, ray);	//REVIEW - Understand what this function does (and means)
		init_wall_dda(&wall_ray, data->map);	//REVIEW - Understand what this function does (and means)
		print_frame(data, &wall_ray, &ray, x);	//REVIEW - Understand what this function does
		x++;
	}
	mlx_put_image_to_window
		(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
}

void	game_loop(t_data *data)
{
	modif_player(data);
	ray_casting(data);
}

void	game_event_loop(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17, (int)close_program, data);
	mlx_loop_hook(data->mlx.mlx_ptr, game_loop, (void *)data);
	mlx_loop(data->mlx.mlx_ptr);
}
