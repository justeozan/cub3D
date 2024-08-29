/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:15:50 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 16:53:13 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

/**
 * @brief	Put the pixel in the screen with the color
 * @param	img: the image structure that contains the data of the screen
 * @param	col: the column of the pixel in the screen
 * @param	line: the line of the pixel in the screen
 * @param	color: the color of the pixel
 * @note	We calculate the offset of the pixel in the screen and we put the color in the pixel.
 * @details	We check if the pixel is in the screen, if it is we put the color in the pixel.
 */
static void	put_pixel(t_image img, int col, int line, int color)
{
	int	offset;

	offset = (img.len_line * line) + (img.bit_per_pixel * col / 8);
	if (col >= 0 && col < SCREEN_WIDTH && line >= 0 && line < SCREEN_HEIGHT)
		*((int *)(img.addr + offset)) = color;
}

/**
 * @brief	Getting the sprite on the x column that we need to display
 * @param	ray: the structure that contains the data of the ray
 * @param	wall_ray: the structure that contains the data of the wall hit by the ray
 * @param	sprite: the structure that contains the data of the sprite
 * @param	x: the x position of the column (sprite) in the screen (x_sprite before)
 * @note	We get the sprite that we need to display, then we get the x position of the sprite
 * and we calculate the height of the sprite in the screen. Then we calculate the start and
 * end position of the sprite in the screen. And we iterate through the sprite and put the pixel
 * of the sprite in the screen.
 */
static void	get_sprite_x(t_ray *ray, t_dda *wall, t_sprites *sprite, int *x)
{
	double	wall_hit_pos;

	if (wall->cardinal == NORTH || wall->cardinal == SOUTH)
		wall_hit_pos = ray->true_pos.x + wall->dist * ray->dir.x;
	else
		wall_hit_pos = ray->true_pos.y + wall->dist * ray->dir.y;
	wall_hit_pos -= floor(wall_hit_pos);
	*x = (int)(wall_hit_pos * (double)sprite->x);
}

/**
 * @brief	Getting the sprite that we need to display
 * @param	data: the structure that contains all the data of the game
 * @param	sprite: the structure that contains the data of the sprite
 * @param	cardinal: the cardinal of the sprite that we need to display
 * @note	We iterate through the sprites and we get the sprite that we need to display.
 */
static void	sprite_to_display(t_data *data, t_sprites *sprite, t_cardinal point)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->sprites[i].cardinal == point)
		{
			*sprite = data->sprites[i];
			break ;
		}
	}
}

/**
 * @brief	Draw the floor and the ceiling of the screen
 * @param	data: the structure that contains all the data of the game
 * @param	img: the image structure that contains the data of the screen
 * @note	We iterate through the screen and we put the color of the floor 
 * and the ceiling in the screen.
 * @details For the ceiling we iterate through the half of the screen and 
 * for the floor we iterate through the other half of the screen.
 */
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

	sprite_to_display(data, &sprite, wall_ray->cardinal);
	get_sprite_x(ray, wall_ray, &sprite, &col.x_sprite);
	col.height = (int)(SCREEN_HEIGHT / wall_ray->dist);
	col.y_start = (SCREEN_HEIGHT - col.height) / 2;
	col.y_end = col.y_start + col.height;
	i = col.y_start;
	while (i < col.y_end)
	{
		col.y_sprite = ((i - col.y_start) * sprite.y) / col.height;
		if (sprite.cardinal == NORTH || sprite.cardinal == WEST)
			col.color = *((int *)(sprite.addr + col.y_sprite
						* sprite.len_line + (sprite.x - col.x_sprite - 1)
						* (sprite.bit_per_pixel / 8)));
		else
			col.color = *((int *)(sprite.addr + col.y_sprite
						* sprite.len_line + col.x_sprite
						* (sprite.bit_per_pixel / 8)));
		put_pixel(data->img, x, i, col.color);
		i++;
	}
}
