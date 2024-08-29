/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 16:00:44 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_image(t_image *img, t_mlx mlx)
{
	img->img_ptr = mlx_new_image(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img_ptr)
		ft_exit(ERR_INIT_2);
	after_mlx_init(3);
	img->addr = mlx_get_data_addr
		(img->img_ptr, &img->bit_per_pixel, &img->len_line, &img->endian);
	if (!img->addr)
		ft_exit(ERR_INIT_3);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_exit(ERR_INIT_1);
	after_mlx_init(1);
	gc_add(mlx->mlx_ptr, MLX);
	mlx->win_ptr = mlx_new_window
		(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!mlx->win_ptr)
		ft_exit(ERR_INIT_4);
	after_mlx_init(2);
}
