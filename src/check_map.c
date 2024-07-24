#include "../includes/cub3D.h"

static bool	check_one_texture(char *file, char *direction)
{
	int	fd;
	
	fd = open(file, O_RDONLY);

	close(fd);
}

static bool	check_textures(char *file)
{
	if (!check_one_texture(file, "NO"))
}

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	
	if (!ft_strnstr(args[1], ".cub", 4))
		return (false);
	return (true);
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