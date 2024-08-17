/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:15:50 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 05:37:29 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	put_pixel(t_image *img, int col, int line, int color)
{
	int	offset;

	offset = (img->len_line * line) + (img->bit_per_pixel * col / 8);
	if (col >= 0 && col < SCREEN_WIDTH && line >= 0 && line < SCREEN_HEIGHT)
		*((int *)(img->addr + offset)) = color;
}

void	print_frame(t_data *data) // TODO - code
{
	(void)data;
}
