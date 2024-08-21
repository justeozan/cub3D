/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:21 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/21 02:17:41 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	new_sprites(t_sprites *sprite, t_mlx *mlx)
{
	sprite->reference = mlx_xpm_file_to_image(mlx->mlx_ptr,
			sprite->path, &sprite->x, &sprite->y);
	printf("x = %d, y = %d\n", sprite->x, sprite->y);
	if (!sprite->reference)
		ft_exit(ERR_INIT_4);
	sprite->addr = (unsigned char *)mlx_get_data_addr
		(sprite->reference, &sprite->bit_per_pixel,
			&sprite->len_line, &sprite->endian);
	if (!sprite->addr)
		ft_exit(ERR_INIT_5);
}

/***************************************
 * @brief	Initialize the sprites of the game
 * @param	data: the structure that contains all the data of the game
 * @param	mlx: the structure that contains all the mlx data
 * @note	The mlx needed to be initialized before this function.
 * And here we initialize the sprites with the path of the textures.
***************************************/
void	init_sprites(t_data *data, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
		new_sprites(&data->sprites[i], mlx);
}
