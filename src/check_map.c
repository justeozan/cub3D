#include "../includes/cub3D.h"

static void	check_one_texture(char **file, char *direction, int len_dir)
{
	int		i;
	int		j;
	char	*texture;
	int		fd_texture;

	i = -1;
	j = 0;
	while (file[++i])
	{
		while (file[i][j] == ' ')
			j++;
		if (ft_strnstr(file[i], direction, len_dir))
		{
			while (file[i][j] == ' ')
				j++;
			texture = gc_strdup(&file[i][j], TMP);
			fd_texture = open(texture, O_RDONLY);
			if (fd_texture < 1 || !ft_strnstr(&file[i][j], ".xpm", len_dir))
				ft_exit(ERR_TEXTURE, EXIT_FAILURE);
		}
	}
}

static bool	check_textures(char **file)
{
	check_one_texture(file, "SO ", 3);
	check_one_texture(file, "WE ", 3);
	check_one_texture(file, "EA ", 3);
	check_one_texture(file, "F ", 2);
	check_one_texture(file, "C ", 2);
}

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	
	if (!ft_strnstr2(args[1], ".cub", 4))
		return (false);
	return (true);
}

bool	check_map(int ac, char	**args)
{
	int		fd;
	char	**file;
	if (!check_args(ac, args))
		ft_exit(ERR_ARGS, EXIT_FAILURE);
	fd = open(args[1], O_RDONLY);
	if (fd < 1)
		return (ft_exit(ERR_FILE, EXIT_FAILURE), false);
	file = getfile(fd);
	close(fd);
	check_textures(file);
	check_colors(file);
	return (true);
}

// void	check_args(int ac, char	**args)
// {
	// if (!check_args(ac, av))
	// 	return (print_error("args error: format: ./cub3D <map_name.cub>"), ft_exit());
	// if (!check_map(av[1]))
	// 	return (print_error("Map error"), ft_exit());
// }