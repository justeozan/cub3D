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

inline void	print_matrix(t_matrix *matrix)
{
	ft_printf("\n-MATRIX STRUCTURE-\n");
	ft_printf("x: %d\n", matrix->x);
	ft_printf("y: %d\n", matrix->y);
	ft_printf("wall: %d\n", matrix->wall);
	ft_printf("xproj: %d\n", matrix->xproj);
	ft_printf("yproj: %d\n", matrix->yproj);
	ft_printf("zproj: %d\n", matrix->zproj);
}

inline void	print_file(char **file)
{
	int	i;

	i = -1;
	ft_printf("\n-FILE CONTENT-\n");
	while (file[++i])
		ft_printf("|%s\n", file[i]);
}