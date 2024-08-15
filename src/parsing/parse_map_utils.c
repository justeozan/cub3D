#include "../../includes/cub3D.h"

// bool	is_complete_wall(char *line, int width)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < width)
// 		if (line[i] != '1')
// 			return (false);
// 	return (true);
// }

// void	replace_space_by_wall(char **map, int height, int width)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < height)
// 	{
// 		if (is_complete_wall(map[i], width))
// 			continue ;
// 		if (map[i][0] == ' ')
// 			map[i][0] = '1';
// 		if (map[i][width - 1] == ' ')
// 			map[i][width - 1] = '1';
// 	}
// }

void	replace_space_by_wall(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
		}
	}
}
