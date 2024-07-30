#include "../../includes/cub3D.h"

static void	init_matrix(char **file, t_matrix **matrix)
{
	int	x_len;
	int	y_len;

	find_len(file, &x_len, &y_len);
}

void	init_structs(t_data *data, t_matrix *matrix)
{
	t_matrix	**matrix;

	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
	init_matrix(data->file, &matrix);
}
