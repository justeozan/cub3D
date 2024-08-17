/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:52 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:08:23 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/***************************************
 * @brief Check if the colors are present in the file
***************************************/
static void	check_presence_colors(t_data *data)
{
	if (data->colors.floor == -1)
		ft_exit(ERR_COLOR_F);
	if (data->colors.ceiling == -1)
		ft_exit(ERR_COLOR_C);
}

/***************************************
 * @brief Check if the sprites are present in the file
 * @param data THe struct that contains the sprites
***************************************/
static void	check_presence_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->sprites[i].path)
			ft_exit(ERR_SPRITES_2);
		i++;
	}
}

/***************************************
 * @brief Get the data from the file, the colors and the sprites.
 * @param data The struct that contains the data
 * @param file The file that contains the data
 * @note Get the colors and the sprites from the without withespaces file.
***************************************/
static void	get_data(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (file[i][0] == 'F' || file[i][0] == 'C')
			parse_colors(data, file[i]);
		else if (file[i][0] == 'N' || file[i][0] == 'S'
			|| file[i][0] == 'W' || file[i][0] == 'E')
			parse_sprites(data, file[i]);
		i++;
	}
	check_presence_colors(data);
	check_presence_sprites(data);
}

/***************************************
 * @brief	Parse the map file
***************************************/
void	parse(char	**av, t_data *data)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE);
	data->file = get_file(fd);
	close(fd);
	get_data(data, data->file);
	get_map(data, &(data->file[6]));
	replace_space_by_wall(data->map.content,
		data->map.height, data->map.width);
	// print_data(data);
	// print_map(data->map.content, data->map.height);
}
