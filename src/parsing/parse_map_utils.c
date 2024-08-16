#include "../../includes/cub3D.h"

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
