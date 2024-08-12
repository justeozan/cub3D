#include "../../includes/cub3D.h"

t_data	*init_mlx()
{
	t_data	*data;

	data = gc_calloc(1, sizeof(t_data), DATA);
	if (!data)
		return (ft_exit(ERR_MALLOC, EXIT_FAILURE), NULL);
	return (data);
}
