#include "../../includes/cub3D.h"

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
		if (j != 0 && l[j - 1] == '1' && ft_strchr("0NSWE", l[j]) != NULL)
		{
			while (l[j] && ft_strchr("0NSWE", l[j]) != NULL)
			{
				if (ft_strchr("NSWE", l[j]) != NULL)
					(*nb_player)++;
				j++;
			}
			if (!l[j] || l[j] == ' ')
				return (false);
		}
		else
			return (false);
	}
	return (*nb_player <= 1);
}

static bool	check_map(char **map, int height, int width)
{
	int i;
	int	nb_player;
	
	nb_player = 0;
	i = -1;
	while (++i < height)
		if (!line_is_good(map[i], width, &nb_player))
			return (ft_printf("nb_player = %d\nerror final at line = %d\n", nb_player, i), false);
	if (nb_player != 1)
		return (false);
	(void)width;
	(void)height;
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

	if (!data->no || !data->so || !data->we || !data->ea)
		ft_exit(ERR_SPRITES, EXIT_FAILURE);
	if (!data->c || !data->f)
		ft_exit(ERR_COLOR, EXIT_FAILURE);
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
	if (!data->map[0])
		ft_exit(ERR_MAP, EXIT_FAILURE);
}
