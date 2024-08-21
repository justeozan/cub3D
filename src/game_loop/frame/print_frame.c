/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:15:50 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/21 02:50:22 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	put_pixel(t_image img, int col, int line, int color)
{
	int	offset;

	offset = (img.len_line * line) + (img.bit_per_pixel * col / 8);
	if (col >= 0 && col < SCREEN_WIDTH && line >= 0 && line < SCREEN_HEIGHT)
		*((int *)(img.addr + offset)) = color;
}

static void	get_sprite_x(t_ray *ray, t_dda *wall_ray, t_sprites *sprite, int *x_sprite)
{
	double	wall_hit_pos;

	if (wall_ray->cardinal == NORTH || wall_ray->cardinal == SOUTH)
		wall_hit_pos = ray->true_pos.x  + wall_ray->dist * ray->dir.x;
	else
		wall_hit_pos = ray->true_pos.y  + wall_ray->dist * ray->dir.y;
	wall_hit_pos -= floor(wall_hit_pos);
	*x_sprite = (int)(wall_hit_pos * (double)sprite->x);
}

static void	sprite_to_display(t_data *data, t_sprites *sprite, t_cardinal cardinal)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (data->sprites[i].cardinal == cardinal)
			*sprite = data->sprites[i];
}

void	draw_floor_ceiling(t_data *data, t_image img)
{
	int	i;
	int	j;
	int	half_screen;

	half_screen = SCREEN_HEIGHT / 2;
	i = 0;
	while (i < half_screen)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			put_pixel(img, j, i, data->colors.ceiling);
		i++;
	}
	while (i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			put_pixel(img, j, i, data->colors.floor);
		i++;
	}
}

void	print_col(t_data *data, t_dda *wall_ray, t_ray *ray, int x)
{
	t_pixel_column	col;
	t_sprites		sprite;
	int				i;

	// sprite = NULL;
	sprite_to_display(data, &sprite, wall_ray->cardinal);
	get_sprite_x(ray, wall_ray, &sprite, &col.x_sprite);
	col.height = (int)(SCREEN_HEIGHT / wall_ray->dist);
	col.y_start = (SCREEN_HEIGHT - col.height) / 2;
	col.y_end = col.y_start + col.height;
	i = col.y_start;
	while (i < col.y_end)
	{
		col.y_sprite = ((i - col.y_start) * sprite.y) / col.height;
		// printf("%d = ((%d - %d) * %d) / %d\n", col.x_sprite, i, col.y_start, sprite.y, col.height);
		// printf("col.color: %d = %p + %d * %d + %d * (%d / 8)\n", col.color, sprite.addr, col.y_sprite, sprite.len_line, col.x_sprite, sprite.bit_per_pixel);
		col.color = *((int *)(sprite.addr + col.y_sprite * sprite.len_line + col.x_sprite * (sprite.bit_per_pixel / 8)));
		put_pixel(data->img, x, i, col.color);
		i++;
	}
}
