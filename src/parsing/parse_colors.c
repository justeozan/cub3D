#include "../includes/cub3D.h"

static void	check_format_color(char *line)
{
	int	i;
	int	nbr_comma;

	nbr_comma = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] != ',' && !ft_isdigit(line[i]))
			ft_exit(ERR_COLOR, EXIT_FAILURE);
		else if (line[i] == ',')
			nbr_comma++;
	}
	if (nbr_comma != 2)
		ft_exit(ERR_COLOR, EXIT_FAILURE);
}

void	parse_colors(t_data *data, char *line)
{
	char	**color;
	int		rgb[3];
	int		i;

	if ((data->colors.floor && line[0] == 'F')
			|| (data->colors.ceiling && line[0] == 'C'))
		ft_exit(ERR_SPRITES, EXIT_FAILURE);
	check_format_color(&line[2]);
	color = gc_split(&line[2], ',', TMP);
	if (!color)
		ft_exit(ERR_MALLOC, EXIT_FAILURE);
	i = -1;
	while (++i < 3)
	{
		if (!color[i])
			ft_exit(ERR_COLOR, EXIT_FAILURE);
		rgb[i] = ft_atoi(color[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_exit(ERR_COLOR, EXIT_FAILURE);
	}
	if (line[0] == 'F')
		data->colors.floor = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	else if (line[0] == 'C')
		data->colors.ceiling = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
}
