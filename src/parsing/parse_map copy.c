/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:14:52 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/04 16:31:45 by ozasahin         ###   ########.fr       */
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

static bool line_is_good(char *l, int width, int *nb_player)
{
	int	j;

	j = -1;
	while (++j < width)
	{
		while (j < width && (l[j] == ' ' || l[j] == '1'))
			j++;
		if (j == width || !l[j])
			break ;
		// if (l[j] != '1')
		// 	return (ft_printf("error 1, j = %d, c = %c\n", j, l[j]), false);
		// while (l[j] == '1')
		// 	j++;
		if (l[j - 1] == '1' && ft_strchr("0NSWE", l[j]) != NULL)
		{
			while (l[j] && ft_strchr("0NSWE", l[j]) != NULL)
			{
				ft_printf("c = %c, strchr = %s, bool = %d\n", l[j], ft_strchr("0NSWE", l[j]), ft_strchr("0NSWE", l[j]) != NULL);
				if (ft_strchr("NSWE", l[j]) != NULL)
				{
					(*nb_player)++;
					ft_printf("nb_player = %d\n", *nb_player);
				}
				j++;
			}
			if (l[j] && l[j] == ' ')
				return (ft_printf("error 2, j = %d, c = %c, c-1 = %c\n", j, l[j], l[j-1]), false);
			// while (j < width && l[j] == '1')
			// 	j++;
		}
		else
			return (ft_printf("error 1, j = %d, c = %c, c-1 = %c\n", j, l[j], l[j-1]), false);
	}
	return (*nb_player <= 1);
}

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

void	get_size_map(t_data *data, char **file)
{
	int i;
	int j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (j > data->width)
		{
			data->width = j;
		}
		i++;
	}
	data->height = i;
}

void	get_map(t_data *data, char **file)
{
	char	**map;
	int	i;

	map = NULL;
	get_size_map(data, file);
	map = (char **)gc_malloc(sizeof(char *) * (size_t)(data->height), MAP);
	if (!map)
		ft_exit(ERR_MALLOC, EXIT_FAILURE);
	i = 0;
	while (i < data->height)
	{
		map[i] = (char *)gc_malloc(sizeof(char) * (size_t)(data->width + 1), MAP);
		if (!map[i])
			ft_exit(ERR_MALLOC, EXIT_FAILURE);
		ft_strlcpy(map[i], file[i], (size_t)(data->width + 1));
		i++;
	}
	if (!check_map(map, data->height, data->width))
		ft_exit(ERR_MAP, EXIT_FAILURE);
	data->map = map;
}
