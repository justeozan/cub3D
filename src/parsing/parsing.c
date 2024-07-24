#include "../includes/cub3D.h"



// static void	check_one_texture(char **file, char *direction)
// {
// 	int		i;
// 	int		j;
// 	char	*texture;
// 	int		fd_texture;

// 	i = -1;
// 	while (file[++i])
// 	{
// 		j = 0;
// 		while (file[i][j] == ' ')
// 			j++;
// 		if (ft_strnstr(file[i], direction, 3))
// 		{
// 			j += 3;
// 			while (file[i][j] == ' ')
// 				j++;
// 			texture = gc_strdup(&file[i][j], TMP);
// 			fd_texture = open(texture, O_RDONLY);
// 			ft_printf("fd = %d, j = %d, texture = %s\n", fd_texture, j, texture);
// 			if (fd_texture < 1 || !ft_strnstr2(&file[i][j], ".xpm", 4))
// 				ft_exit(ERR_TEXTURE, EXIT_FAILURE);
// 		}
// 	}
// }

// static void	check_textures(char **file)
// {
// 	int	i;
// 	if (!ft_strnstrs(file, "NO ", 3) || !ft_strnstrs(file, "SO ", 3)
// 		|| !ft_strnstrs(file, "WE ", 3) || !ft_strnstrs(file, "EA ", 3))
// 		ft_exit(ERR_TEXTURE, EXIT_FAILURE);
// 	i = 0;
// 	while (file[i])
// 		check_one_texture(file, "NO ");
// }

// static bool	check_colors(char **file)
// {
	
// }

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	
	if (!ft_strnstr2(args[1], ".cub", 4))
		return (false);
	return (true);
}


// bool	check_map(int ac, char	**args)
// {
// 	int		fd;
// 	char	**file;
// 	if (!check_args(ac, args))
// 		ft_exit(ERR_ARGS, EXIT_FAILURE);
// 	fd = open(args[1], O_RDONLY);
// 	if (fd < 1)
// 		return (ft_exit(ERR_FILE, EXIT_FAILURE), false);
// 	file = get_file(fd);
// 	close(fd);
// 	check_textures(file);
// 	// check_color(file, "F ");
// 	// check_color(file, "C ");
// 	return (true);
// }

// void	check_args(int ac, char	**args)
// {
	// if (!check_args(ac, av))
	// 	return (print_error("args error: format: ./cub3D <map_name.cub>"), ft_exit());
	// if (!check_map(av[1]))
	// 	return (print_error("Map error"), ft_exit());
// }

// =====================================

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
	// ft_printf("len = %d\n", len);
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
	new_line[++j] = '\n';
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
			tmp = gc_realloc(file, capacity / 2, sizeof(char *) * capacity, TMP);
			if (!tmp)
				return (ft_exit(ERR_MALLOC, EXIT_FAILURE), NULL);
			file = tmp;
		}
		file[i] = get_next_line(fd);
	}
	return (delete_whitespaces(file));
}

void	parse_textures(char **file)
{
	
}

bool	parse(int ac, char	**args)
{
	int		fd;
	char	**file;

	if (!check_args(ac, args))
		ft_exit(ERR_ARGS, EXIT_FAILURE);
	fd = open(args[1], O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE, EXIT_FAILURE);
	file = get_file(fd);
	close(fd);
	
	/*Affichage*/
	// for (int i = 0; file[i]; i++)
	// 	ft_printf("%s", file[i]);
	
	parse_textures(file);
	// check_color(file, "F ");
	// check_color(file, "C ");
	return (true);
}