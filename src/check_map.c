#include "../includes/cub3D.h"

static bool	check_one_texture(char *file, char *direction)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	(void)*direction; //!
	close(fd);
	return 0; //!
}

static bool	check_textures(char *file)
{
	if (!check_one_texture(file, "NO"))
		return 0; //!
	return 1; //!
}

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	
	if (!ft_strnstr(args[1], ".cub", 4))
		return (false);
	return (true);
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
			tmp = realloc(file, sizeof(char *) * capacity);
			if (!tmp)
				return (free_2d(tmp), NULL);
			file = tmp;
		}
		file[i] = get_next_line(fd);
	}
	return (file);
}

bool	check_map(int ac, char	**args)
{
	int fd;
	if (!check_args(ac, args))
		ft_exit(ERR_ARGS, EXIT_FAILURE);
	fd = open(args[1], O_RDONLY);
	if (fd < 1)
		return (ft_exit(ERR_FILE, EXIT_FAILURE), false);
	close(fd);
	if (!check_textures(args[1]))
		return (ft_exit(ERR_TEXTURE, EXIT_FAILURE), false);
	return (true);
}

// void	check_args(int ac, char	**args)
// {
	// if (!check_args(ac, av))
	// 	return (print_error("args error: format: ./cub3D <map_name.cub>"), ft_exit());
	// if (!check_map(av[1]))
	// 	return (print_error("Map error"), ft_exit());
// }