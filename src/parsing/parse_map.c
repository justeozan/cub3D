#include "../../includes/cub3D.h"

// static t_matrix	**extract_map(t_matrix **matrix, int height, char **file)
// {
// 	int	i;
// 	int	j;
// 	int	nb_col;

// 	i = -1;
// 	matrix = gc_malloc(sizeof(t_matrix *) * height, MATRIX);
// 	if (!matrix)
// 		ft_exit(ERR_MALLOC, EXIT_FAILURE);
// 	while (++i < height)
// 	{
// 		j = -1;
// 		nb_col = ft_strlen(file[i]);
// 		matrix[i] = gc_malloc(sizeof(t_matrix) * nb_col, MATRIX);
// 		if (!matrix[i])
// 			ft_exit(ERR_MALLOC, EXIT_FAILURE);
// 		while (++j < nb_col)
// 		{
// 			matrix[i][j].width = nb_col;
// 			matrix[i][j].x = i;
// 			matrix[i][j].y = j;
// 			matrix[i][j].player = '0';
// 			if (file[i][j] == '1')
// 				matrix[i][j].wall = 1;
// 			if (file[i][j] == 'N' || file[i][j] == 'S'
// 				|| file[i][j] == 'W' || file[i][j] == 'E')
// 				matrix[i][j].player = file[i][j];
// 		}
// 	}
// 	return (matrix);
// }

// static void	check_syntax(char **file)
// {
// 	int	i;
// 	int	j;
// 	int	count;
// 	int	valid;

// 	i = -1;
// 	count = 0;
// 	while (file[++i])
// 	{
// 		j = -1;
// 		while (file[i][++j])
// 		{
// 			valid = 0;
// 			if (file[i][j] == ' ' || file[i][j] == '0' || file[i][j] == '1')
// 				valid = 1;
// 			else if (file[i][j] == 'N' || file[i][j] == 'S'
// 				|| file[i][j] == 'W' || file[i][j] == 'E')
// 			{
// 				valid = 1;
// 				count++;
// 			}
// 			if (!valid || count > 1)
// 				ft_exit(ERR_MAP, EXIT_FAILURE);
// 		}
// 	}
// 	if (count != 1)
// 		ft_exit(ERR_MAP, EXIT_FAILURE);
// }

// static void	check_horizontal_wall(char **file, int height)
// {
// 	int	i;

// 	i = -1;
// 	while (file[0][++i])
// 	{
// 		if (file[0][i] != ' ' && file[0][i] != '1')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 	}
// 	i = -1;
// 	while (file[height - 1][++i])
// 	{
// 		if (file[height - 1][i] != ' ' && file[height - 1][i] != '1')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 	}
// }

// static void	check_vertical_wall(char **file, int height)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (file[++i] && i < height - 1)
// 	{
// 		j = 0;
// 		while (file[i][j] == ' ')
// 			j++;
// 		if (file[i][j] != '1')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 	}
// 	i = -1;
// 	while (file[++i] && i < height - 1)
// 	{
// 		j = ft_strlen(file[i]) - 1;
// 		while (file[i][j] == ' ')
// 			j--;
// 		if (file[i][j] != '1')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 	}
// }

// static inline void	check_around(char **file, int height, int i, int j)
// {
// 	if (file[i][j] == '0')
// 	{
// 		if (i == height - 1 || i == 0)
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 		if (!file[i][j + 1] || !file[i][j + 1] || !file[i][j - 1] || !file[i - 1][j])
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 		if (file[i][j + 1] == ' ')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 		if (file[i][j - 1] == ' ')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 		if (file[i + 1][j] == ' ')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 		if (file[i - 1][j] == ' ')
// 			ft_exit(ERR_MAP, EXIT_FAILURE);
// 	}
// }

// static void	check_wall(int height, char **file)
// {
// 	int	i;
// 	int	j;

// 	check_horizontal_wall(file, height);
// 	check_vertical_wall(file, height);
// 	i = 0;
// 	while (file[++i] && i < height - 1)
// 	{
// 		j = 0;
// 		while (file[i][++j] && j < ft_strlen(file[i]) - 1)
// 			check_around(file, height, i, j);
// 	}
// }

// static void	check_map(t_data **data, char **file)
// {
// 	check_syntax(file);
// 	check_wall((*data)->height, file);
// }

// void	check_data(t_data **data)
// {
// 	if (!(*data)->no || !(*data)->so || !(*data)->we
// 		|| !(*data)->ea || !(*data)->f || !(*data)->c)
// 		ft_exit(ERR_DATA, EXIT_FAILURE);
// }

// void	get_map(t_data **data, char **file)
// {
// 	check_data(data);
// 	(*data)->height = count_line(file);
// 	check_map(data, file);
// 	(*data)->matrix = extract_map((*data)->matrix, (*data)->height, file);
// }

// =============================================

void	get_map(t_data **data, char **file)
{
	(void)data;
	(void)file;
}