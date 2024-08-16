#include "../includes/cub3D.h"

static void check_presence_colors(t_data *data)
{
	if (data->colors.floor == -1)
		ft_exit(ERR_COLOR_F);
	if (data->colors.ceiling == -1)
		ft_exit(ERR_COLOR_C);
}

static void check_presence_sprites(t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!data->sprites[i].path)
			ft_exit(ERR_SPRITES_2);
		i++;
	}
}

static void	get_data(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (file[i][0] == 'F' || file[i][0] == 'C')
			parse_colors(data, file[i]);
		else if (file[i][0] == 'N' || file[i][0] == 'S'
			|| file[i][0] == 'W' || file[i][0] == 'E')
			parse_sprites(data, file[i]);
		i++;
	}
	check_presence_colors(data);
	check_presence_sprites(data);
}

void	parse(char	**av, t_data *data)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE);
	data->file = get_file(fd);
	close(fd);
	get_data(data, data->file);
	get_map(data, &(data->file[6]));
	replace_space_by_wall(data->mappy.content,
		data->mappy.height, data->mappy.width);
	print_data(data);
	print_map(data->mappy.content, data->mappy.height);
}
