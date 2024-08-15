#include "../../includes/cub3D.h"

inline void	print_data(t_data *data)
{
	ft_printf("\n-DATA STRUCTURE-\n");
	ft_printf(CYAN "NO:" RESET " %s\n" , data->no);
	ft_printf(CYAN "SO:" RESET " %s\n" , data->so);
	ft_printf(CYAN "WE:" RESET " %s\n" , data->we);
	ft_printf(CYAN "EA:" RESET " %s\n" , data->ea);
	ft_printf(BLUE "F:" RESET " %d (%d,%d,%d)\n", data->colors.floor, (data->colors.floor >> 16) & 0xFF,
		(data->colors.floor >> 8) & 0xFF, data->colors.floor & 0xFF);
	ft_printf(BLUE "C:" RESET " %d (%d,%d,%d)\n" , data->colors.ceiling, (data->colors.ceiling >> 16) & 0xFF,
		(data->colors.ceiling >> 8) & 0xFF, data->colors.ceiling & 0xFF);
	ft_printf("\n");
}

inline void	print_file(char **file)
{
	int	i;

	i = -1;
	ft_printf("\n-FILE CONTENT-\n");
	while (file[++i])
	{
		if (i < 10)
			ft_printf("%d  |%s", i, file[i]);
		else
			ft_printf("%d |%s", i, file[i]);
	}
	ft_printf("\n");
}

inline void	print_file_without_spaces(char **file)
{
	int	i;

	i = -1;
	ft_printf("\n-FILE CONTENT-\n");
	while (file[++i])
	{
		if (i < 10)
			ft_printf("%d  |%s\n", i, file[i]);
		else
			ft_printf("%d |%s\n", i, file[i]);
	}
	ft_printf("\n");
}

inline void	print_map(char **map, int height, int width)
{
	int	i;

	i = 0;
	ft_printf("\n-MAP CONTENT-\n");
	ft_printf(YELLOW "h:" RESET " %d\n", height);
	ft_printf(YELLOW "w:" RESET " %d\n", width);
	while (i < height)
	{
		if (i + 1 < 10)
			ft_printf("%d  |%s\n", i + 1, map[i]);
		else
			ft_printf("%d |%s\n", i + 1, map[i]);
		i++;
	}
}
