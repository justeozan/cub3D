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
		*dist = (ray.map_pos.x - ray.true_pos.x
				+ (1 - ray.step_direction.x) / 2) / ray.dir.x;
}

static void	process_wall_cardinal(t_ray ray, t_cardinal *cardinal, char last_side)
{
	if (last_side == 'x')
	{
		if (ray.dir.x > 0)
			*cardinal = EAST;
		else
			*cardinal = WEST;
	}
	else
	{
		if (ray.dir.y > 0)
			*cardinal = NORTH;
		else
			*cardinal = SOUTH;
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
