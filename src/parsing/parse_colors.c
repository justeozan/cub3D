#include "../includes/cub3D.h"

static void	save_color(t_data *data, char c, char *line)
{
	if (c == 'F')
	{
		data->f = gc_strdup(line, DATA);
		if (!data->f)
			ft_exit(ERR_MALLOC, EXIT_FAILURE);
	}
	else if (c == 'C')
	{
		data->c = gc_strdup(line, DATA);
		if (!data->c)
			ft_exit(ERR_MALLOC, EXIT_FAILURE);
	}
}

static void	check_format_color(char *line, int start)
{
	int	i;
	int	nbr_comma;

	nbr_comma = 0;
	i = start;
	while (line[i])
	{
		if (line[i] != ',' && !ft_isdigit(line[i]))
			ft_exit(ERR_COLOR, EXIT_FAILURE);
		else if (line[i] == ',')
			nbr_comma++;
		i++;
	}
	if (nbr_comma != 2)
		ft_exit(ERR_COLOR, EXIT_FAILURE);
}

void	parse_colors(t_data *data, char *line)
{
	char	**color;
	int		rgb[3];
	int		i;

	if ((data->f && line[0] == 'F') || (data->c && line[0] == 'C'))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
	check_format_color(line, 3);
	color = gc_split(&line[3], ',', TMP);
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
	save_color(data, line[0], &line[3]);
}
