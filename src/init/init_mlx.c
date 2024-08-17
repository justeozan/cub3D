/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 00:13:59 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_image(t_image *img, t_mlx mlx)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->img_ptr = mlx_new_image(mlx.mlx_ptr, SCREEN_HEIGHT, SCREEN_WIDTH);
	if (!img->img_ptr)
		ft_exit(ERR_INIT_2);
	img->addr = mlx_get_data_addr
		(img->img_ptr, &img->bit_per_pixel, &img->len_line, &img->endian);
	if (!img->addr)
		ft_exit(ERR_INIT_3);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_exit(ERR_INIT_1);
	mlx->win_ptr = mlx_new_window
		(mlx->mlx_ptr, SCREEN_HEIGHT, SCREEN_WIDTH, "cub3D");
}