/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_wall_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:36:52 by avialle-          #+#    #+#             */
/*   Updated: 2024/08/29 15:37:49 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static bool	is_wall(t_ray ray, t_map map)
{
	return (map.content[ray.map_pos.y][ray.map_pos.x] == '1');
}

static void	process_wall_dist(t_ray ray, double *dist, char last_side)
{
	if (last_side == 'x')
		*dist = (ray.map_pos.x - ray.true_pos.x
				+ (1 - ray.step_direction.x) / 2) / ray.dir.x;
	else
		*dist = (ray.map_pos.y - ray.true_pos.y
				+ (1 - ray.step_direction.y) / 2) / ray.dir.y;
}

static void	process_wall_cardinal(t_ray ray, t_cardinal *point, char last_side)
{
	if (last_side == 'x')
	{
		if (ray.dir.x > 0)
			*point = EAST;
		else
			*point = WEST;
	}
	else
	{
		if (ray.dir.y > 0)
			*point = NORTH;
		else
			*point = SOUTH;
	}
}

void	init_wall_dda(t_map *map, t_ray *ray, t_dda *wall_ray)
{
	char	last_side;
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step_direction.x;
			last_side = 'x';
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step_direction.y;
			last_side = 'y';
		}
		hit = is_wall(*ray, *map);
	}
	process_wall_dist(*ray, &wall_ray->dist, last_side);
	process_wall_cardinal(*ray, &wall_ray->cardinal, last_side);
}
