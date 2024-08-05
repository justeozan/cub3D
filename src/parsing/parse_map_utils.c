/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sei <sei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:14:52 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/05 08:24:56 by sei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// static bool	walls_present(char **map, int height, int width)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (++i < height)
// 	{
// 		j = -1;
// 		while (++j < width)
// 		{
// 			while (map[i][j] == ' ')
// 				j++;
// 			if (map[i][j] != '1')
// 				return (false);
// 			while (map[i][j] == '1')
// 				j++;
// 			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
// 					|| map[i][j] == 'W' || map[i][j] == 'E')
// 				while (map[i][j] == '0'  || map[i][j] == 'N' || map[i][j] == 'S'
// 						|| map[i][j] == 'W' || map[i][j] == 'E')
// 					j++;
// 			if (map[i][j] != '1')
// 				return (false);
// 		}
// 	}
// 	return (true);
// }


// static bool extrem_line_is_good(char *line)
// {
// 	while (*line)
// 	{
// 		if (*line != '1' && *line != ' ')
// 			return (false);
// 		line++;
// 	}
// 	return (true);
// }

// static bool line_is_good(char *l)
// {
// 	int	nb_player;

// 	nb_player = 0;
// 	while (*l)
// 	{
// 		while (*l == ' ')
// 			l++;
// 		if (*l != '1')
// 			return (false);
// 		while (*l == '1')
// 			l++;
// 		if (*l == '0' || ft_strchr("NSWE", *l))
// 		{
// 			while (*l == '0' || ft_strchr("NSWE", *l))
// 			{
// 				if (ft_strchr("NSWE", *l))
// 					nb_player++;
// 				l++;
// 			}
// 			if (*l && *l != '1')
// 				return (ft_printf("la, c = %c\n", *l), false);
// 		}
// 	}
// 	ft_printf("nb_player = %d\n", nb_player);
// 	return (nb_player == 1);
// }

static bool	check_map(char **map, int height, int width)
{
	int i;
	int	nb_player;
	
	nb_player = 0;
	i = -1;
	while (++i < 2)
	{
		// if (i == 0 || i == height - 1)
		// 	if (!extrem_line_is_good(map[i], width))
		// 		return (false);
		// else
		if (!line_is_good(map[i], width, &nb_player))
			return (ft_printf("error final at line = %d\n", i), false);
		i++;
	}
	// ft_printf("nb_player = %d\n", nb_player);
	(void)width;
	(void)height;
	// ft_printf("strchr = %s, bool = %d\n", ft_strchr("0NSWE", map[1][9]), ft_strchr("0NSWE", map[1][9]) != NULL);
	// ft_printf("strchr = %s, bool = %d\n", ft_strchr("0NSWE", map[0][0]), ft_strchr("0NSWE", map[0][0]) != NULL);
	
	// if (!extrem_line_is_good(map[0], width)
	// 	|| !extrem_line_is_good(map[height - 1], width))
	// 	return (false);
	// if (!walls_present(map, height, width)
	// 	|| !map_is_consistent(map, height, width))
	// if (!line_is_good)
	// 	return (false);
	return (true);
}
