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

void	check_syntax(char **file)
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

void	check_horizontal_wall(char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (file[i] != ' ' && file[i] != '1')
			ft_exit(ERR_MAP, EXIT_FAILURE);
	}
}

bool	check_arround(char **file, int i, int j)
{
	// int	valid;

	
	if (i > 0 && j > 0 && file[i][j] == '0' && 
	((file[i][j + 1] != '0' && file[i][j + 1] != '1') || (file[i][j - 1] != '0' && file[i][j - 1] != '1') || (file[i + 1][j] != '0' && file[i + 1][j] != '1') || (file[i - 1][j] != '0' && file[i - 1][j] != '1') ))
	{
		ft_printf("i = %d, j = %d\n", i, j);
		return (true);
	}
	return (false);
}

void	check_wall(int height, char **file)
{
	int	i;
	int	j;

	(void)height;
	// check_horizontal_wall(file[0]);
	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (i > 0 && j > 0 && file[i][j] == '0' && ((file[i][j + 1] != '0' && file[i][j + 1] != '1') || (file[i][j - 1] != '0' && file[i][j - 1] != '1') || (file[i + 1][j] != '0' && file[i + 1][j] != '1') || (file[i - 1][j] != '0' && file[i - 1][j] != '1') ))
				{
					ft_printf("i = %d, j = %d\n", i, j);
					ft_exit(ERR_MAP, EXIT_FAILURE);
				}
		}
	}
	// check_horizontal_wall(file[height]);
}

static void	check_map(t_data **data, char **file)
{
	check_syntax(file);
	check_wall((*data)->height, file);
	// check_horizontal_wall(data, file);

}

void	get_map(t_data **data, char **file)
{
	(*data)->height = count_line(file);
	check_map(data, file);
	// extract_map(data, file);
}
