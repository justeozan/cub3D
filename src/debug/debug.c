#include "../../includes/cub3D.h"

inline void	print_data(t_data *data)
{
	ft_printf("\n-DATA STRUCTURE-\n");
	ft_printf("NO: %s\n", data->no);
	ft_printf("SO: %s\n", data->so);
	ft_printf("WE: %s\n", data->we);
	ft_printf("EA: %s\n", data->ea);
	ft_printf("F: %d\n", data->f);
	ft_printf("C: %d\n", data->c);
}

inline void	print_matrix(t_matrix **matrix, int height)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n-MATRIX STRUCTURE-\n");
	while (i < height)
	{
		j = 0;
		while (j < matrix[i][j].width - 1)
		{
			ft_printf("x: %d, y: %d, wall: %d, player: %c\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].wall, matrix[i][j].player);
			j++;
		}
		ft_printf("\n");
		i++;
	}
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
