#include "../includes/cub3D.h"

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	
	if (!ft_strnstr2(args[1], ".cub", 4))
		return (false);
	return (true);
}

char *parse_line(char *str)
{
	int i;
	int j;
	int len;
	char *new_line;

	i = -1;
	len = 0;
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t')
			len++;
	new_line = gc_malloc(sizeof(char) * len + 3, TMP);
	if (!new_line)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '\n' && str[i] != ' ')
		new_line[++j] = str[i];
	new_line[++j] = ' ';
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			new_line[++j] = str[i];
	// new_line[++j] = '\n';
	new_line[++j] = '\0';
	return (new_line);
}

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char **delete_whitespaces(char **file)
{
	int	i;
	int	j;
	int	line;

	i = 0;
	line = 0;
	while (file[i])
	{
		while (ft_isempty(file[i]) > 0)
			i++;
		if (!file[i])
			break;
		j = 0;
		while (file[i][j] == ' ')
			j++;
		file[line] = gc_strdup(parse_line(&file[i][j]), TMP);
		line++;
		i++;
	}
	file[line] = NULL;
	while (file[line])
		free(file[line++]);
	return (file);
}

static char **get_file(int fd)
{
	char	**file;
	char	**tmp;
	int		capacity;
	int		i;
	
	capacity = 10;
	file = gc_malloc(sizeof(char *) * capacity, TMP);
	if (!file)
		return (NULL);
	i = 0;
	file[i] = get_next_line(fd);
	while (file[i])
	{
		i++;
		if (i >= capacity - 1)
		{
			capacity *= 2;
			tmp = gc_realloc(file, sizeof(char *) * (capacity / 2), sizeof(char *) * capacity, TMP);
			if (!tmp)
				return (ft_exit(ERR_MALLOC, EXIT_FAILURE), NULL);
			file = tmp;
		}
		file[i] = get_next_line(fd);
	}
	return (delete_whitespaces(file));
}

void	get_textures_and_colors(t_data *data, char **file)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (file[i][0] == 'F' || file[i][0] == 'C')
			parse_colors(data, file[i]);
		else if (file[i][0] == 'N' || file[i][0] == 'S' || file[i][0] == 'W' || file[i][0] == 'E')
			parse_texture(data, file[i]);
		i++;
	}
}

t_data	*parse(int ac, char	**args)
{
	int		fd;
	t_data	*data;

	if (!check_args(ac, args))
		ft_exit(ERR_ARGS, EXIT_FAILURE);
	fd = open(args[1], O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE, EXIT_FAILURE);
	data = (t_data *)gc_calloc(sizeof(t_data), 1, DATA);
	if (!data)
		ft_exit(ERR_MALLOC, EXIT_FAILURE);
	data->file = get_file(fd);
	close(fd);
	print_file(data->file);
	get_textures_and_colors(data, data->file);
	// check_map(file);
	// parse_textures(file);
	print_structs(data, data->matrix);
	return (data);
}
