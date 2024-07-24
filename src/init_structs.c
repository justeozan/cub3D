
#include "../includes/cub3D.h"



// void	navigate_whitespace

void	init_structs(char **file, )
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		while (file[i][j])
		{
			if (file[i][j] == " ")
			i++;
			while (ft_isalpha(file[i][j]))
		}

	}
}