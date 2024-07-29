#include "../../includes/cub3D.h"

void	check_double_texture(t_data *data, char *line)
{
	if ((data->no && line[0] == 'N') || (data->so && line[0] == 'N')
		|| (data->we && line[0] == 'W') || (data->ea && line[0] == 'E'))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
}

void	check_xpm(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (!ft_strnstr(line, ".xpm\n", 5))
		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	ft_printf("fd = %d\n", fd);
	if (fd < 1)
		ft_exit(ERR_FILE, EXIT_FAILURE);
	close(fd);
}

void	save_texture(t_data *data, char *texture, char dir)
{
	if (dir == 'N')
		data->no = gc_strdup(texture, TEXTURE);
	else if (dir == 'S')
		data->so = gc_strdup(texture, TEXTURE);
	else if (dir == 'W')
		data->we = gc_strdup(texture, TEXTURE);
	else if (dir == 'E')
		data->ea = gc_strdup(texture, TEXTURE);
	if ((!data->no && dir == 'N') || (!data->so && dir == 'S')
		|| (!data->we && dir == 'W') || (!data->ea && dir == 'E'))
		ft_exit(ERR_MALLOC, EXIT_FAILURE);
}

void	parse_texture(t_data *data, char *line)
{
	char	dir;

	check_double_texture(data, line);
	check_xpm(line);
	dir = line[0];
	ft_printf("dir = %c\n", dir);
	ft_printf("line = %s\n", &line[3]);
	check_file(&line[3]);
	save_texture(data, &line[3], dir);
}
