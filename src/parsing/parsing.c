#include "../includes/cub3D.h"

static bool	check_args(int ac, char	**args)
{
	if (ac != 2)
		return (false);
	if (!ft_strnstr2(args[1], ".cub", 4))
		return (false);
	return (true);
}



void	get_textures_and_colors(t_data *data, char **file)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (file[i][0] == 'F' || file[i][0] == 'C')
			parse_colors(data, file[i]);
		else if (file[i][0] == 'N' || file[i][0] == 'S'
			|| file[i][0] == 'W' || file[i][0] == 'E')
			parse_texture(data, file[i]);
		i++;
	}
}

t_data	*parse(int ac, char	**args)
{
	t_data	*data;
	int		fd;

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
	ft_printf("la\n");
	get_textures_and_colors(data, data->file);
	get_map(&data, &(data->file[6]));
	print_data(data);
	// print_matrix(data-<matrix);
	return (data);
}
