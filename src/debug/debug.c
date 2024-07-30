#include "../../includes/cub3D.h"

inline void	print_data(t_data *data)
{
	ft_printf("\n-DATA STRUCTURE-\n");
	ft_printf("NO: %s\n", data->no);
	ft_printf("SO: %s\n", data->so);
	ft_printf("WE: %s\n", data->we);
	ft_printf("EA: %s\n", data->ea);
	ft_printf("F: %s\n", data->f);
	ft_printf("C: %s\n", data->c);
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
			ft_printf("x: %d\n", matrix[i][j].x);
			ft_printf("y: %d\n", matrix[i][j].y);
			ft_printf("wall: %d\n", matrix[i][j].wall);
			ft_printf("player: %c\n\n", matrix[i][j].player);
			j++;
		}
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
