/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avg38 <avg38@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 03:47:38 by avg38            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_image(t_image *img, t_mlx mlx)
{
	img->img_ptr = mlx_new_image(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT); //REVIEW - Check if gc_add is needed.
	if (!img->img_ptr)
		ft_exit(ERR_INIT_2);
	gc_add(img->img_ptr, MLX);
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
	gc_add(mlx->mlx_ptr, MLX);
	mlx->win_ptr = mlx_new_window
		(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	gc_add(mlx->win_ptr, MLX);
}
