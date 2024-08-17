/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:21 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:05:55 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	new_sprites(t_data *data, t_mlx *mlx)
{
	data->sprites->reference = mlx_xpm_file_to_image(mlx->mlx_ptr,
			data->sprites->path, &data->sprites->x, &data->sprites->y);
	if (!data->sprites->reference)
		ft_exit(ERR_INIT_4);
	data->sprites->addr = mlx_get_data_addr
		(data->sprites->reference, &data->sprites->bit_per_pixel,
			&data->sprites->len_line, &data->sprites->endian);
	if (!data->sprites->addr)
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
	while (data->sprites[++i].path)
		new_sprites(data, mlx);
}
