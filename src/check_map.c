#include "../includes/cub3D.h"

static bool	check_args(int ac, char	**args)
{
	int fd;

	if (ac != 2)
	if (!ft_strnstr(args[1], ".cub\0", 5))
		return (false);
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		return (close(fd), false);
	return (true);
}

bool	check_map(int ac, char	**args)
{
	if (!check_args(ac, args))
		ft_exit("Error: args format: ./cub3D <map_name.cub>", EXIT_FAILURE);
	return (true);
}

// void	check_args(int ac, char	**args)
// {
	// if (!check_args(ac, av))
	// 	return (print_error("args error: format: ./cub3D <map_name.cub>"), ft_exit());
	// if (!check_map(av[1]))
	// 	return (print_error("Map error"), ft_exit());
// }