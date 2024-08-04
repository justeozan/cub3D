#include "../../includes/cub3D.h"

inline void	print_data(t_data *data)
{
	ft_printf("\n-DATA STRUCTURE-\n");
	ft_printf("NO: %s\n", data->no);
	ft_printf("SO: %s\n", data->so);
	ft_printf("WE: %s\n", data->we);
	ft_printf("EA: %s\n", data->ea);
	ft_printf("F: %d (%d,%d,%d)\n", data->f, (data->f >> 16) & 0xFF,
		(data->f >> 8) & 0xFF, data->f & 0xFF);
	ft_printf("C: %d (%d,%d,%d)\n", data->c, (data->c >> 16) & 0xFF,
		(data->c >> 8) & 0xFF, data->c & 0xFF);
}

inline void	print_file(char **file)
{
	int	i;

	i = -1;
	ft_printf("\n-FILE CONTENT-\n");
	while (file[++i])
	{
		if (i < 10)
			ft_printf("%d  |%s\n", i, file[i]);
		else
			ft_printf("%d |%s\n", i, file[i]);
	}
}

inline void	print_map(char **map, int height)
{
	int	i;

	i = 0;
	ft_printf("\n-MAP CONTENT-\n");
	while (i < height)
	{
		if (i + 1 < 10)
			ft_printf("%d  |%s\n", i + 1, map[i]);
		else
			ft_printf("%d |%s\n", i + 1, map[i]);
		i++;
	}
}
