#include "../../includes/cub3D.h"

static int	count_line(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

// static void	extract_map(t_data **data, char **file)
// {
// 	int	i;
// 	int	nb_lines;
// 	int	nb_col;

// 	i = 0;
// 	nb_lines = count_line(file);
// 	// nb_col = count_col(file);
// 	(*data)->matrix = gc_malloc(sizeof(t_matrix *) * nb_lines, MATRIX);
// }

// void	check_vertical_wall(t_data **data, char **file)
// {
// 	int	i;

// 	i = 0;
// 	while ()
// }

static void	check_syntax(char **file)
{
	int	i;
	int	j;
	int	count;
	int	valid;

	i = -1;
	count = 0;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			valid = 0;
			if (file[i][j] == ' ' || file[i][j] == '0' || file[i][j] == '1')
				valid = 1;
			else if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'W' || file[i][j] == 'E')
			{
				valid = 1;
				count++;
			}
			if (!valid || count > 1)
				ft_exit(ERR_MAP, EXIT_FAILURE);
		}
	}
}

// static void	check_corner_wall(char *file)
// {
// 	int	i;

// 	i = -1;
// 	while (file[++i])
// 	{
// 		if (file[i] != ' ' && file[i] != '1')
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

static inline void	check_around(char **file, int i, int j)
{
	if (file[i][j] == '0')
	{
		if (!file[i][j + 1] || !file[i][j + 1] || !file[i][j - 1] || !file[i - 1][j])
			ft_exit(ERR_MAP, EXIT_FAILURE);
		if (file[i][j + 1] == ' ')
			ft_exit(ERR_MAP, EXIT_FAILURE);
		if (file[i][j - 1] == ' ')
			ft_exit(ERR_MAP, EXIT_FAILURE);
		if (file[i + 1][j] == ' ')
			ft_exit(ERR_MAP, EXIT_FAILURE);
		if (file[i - 1][j] == ' ')
			ft_exit(ERR_MAP, EXIT_FAILURE);
	}
}

static void	check_wall(int height, char **file)
{
	int	i;
	int	j;

	ft_printf("height = %d\n", height);
	// check_horizontal_wall(file[0]);
	// check_horizontal_wall(file[height - 1]);
	// check_vertical_wall(file, height);
	i = 0;
	while (file[++i] && i < height - 1)
	{
		j = 1;
		while (file[i][j] && i > 0 && j > 0)
			check_around(file, i, j++);
	}
}

static void	check_map(t_data **data, char **file)
{
	check_syntax(file);
	print_file(&(*data)->file[6]);
	check_wall((*data)->height, file);
	// check_horizontal_wall(data, file);

}

void	get_map(t_data **data, char **file)
{
	(*data)->height = count_line(file);
	check_map(data, file);
	// extract_map(data, file);
}
