#include "../../includes/cub3D.h"

static void	check_texture(char **file, char *direction)
{
	int		i;
	int		j;
	char	*texture;
	int		fd_texture;

	i = -1;
	while (file[++i])
	{
		j = 0;
		while (file[i][j] == ' ')
			j++;
		if (ft_strnstr(file[i], direction, 3))
		{
			j += 3;
			while (file[i][j] == ' ')
				j++;
			texture = gc_strdup(&file[i][j], TMP);
			fd_texture = open(texture, O_RDONLY);
			ft_printf("fd = %d, j = %d, texture = %s\n", fd_texture, j, texture);
			if (fd_texture < 1 || !ft_strnstr2(&file[i][j], ".xpm", 4))
				ft_exit(ERR_TEXTURE, EXIT_FAILURE);
		}
	}
}

static void	check_textures(char **file)
{
	int	i;
	if (!ft_strnstrs(file, "NO ", 3) || !ft_strnstrs(file, "SO ", 3)
		|| !ft_strnstrs(file, "WE ", 3) || !ft_strnstrs(file, "EA ", 3))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
	i = 0;
}

void	check_double_texture(t_data *data, char *line)
{
	if ((data->no && line[0] == 'N') || (data->so && line[0] == 'N')
		|| (data->we && line[0] == 'W') || (data->ea && line[0] == 'E'))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
}

void	find_xpm(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (!ft_strnstr(line, ".xpm\n", 5))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
}

void	test_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE, EXIT_FAILURE);
}

void	save_texture(t_data *data, char *texture, char direction)
{
	if (direction == 'N')
		data->no = gc_strdup(texture, TEXTURE);
	else if (direction == 'S')
		data->so = gc_strdup(texture, TEXTURE);
	else if (direction == 'W')
		data->we = gc_strdup(texture, TEXTURE);
	else if (direction == 'E')
		data->ea = gc_strdup(texture, TEXTURE);
}

void	parse_texture(t_data *data, char *line)
{
	char	*texture;
	char	direction;

	check_double_texture(data, line);
	find_xpm(line);
	test_file(&line[3]);
	direction = line[0];
	save_texture(data, &line[3], direction);
}