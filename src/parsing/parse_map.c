#include "../../includes/cub3D.h"

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
	data->map = map;
}