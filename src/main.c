/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:04 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 15:12:35 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	char	**file;
	int		fd;
	int		i;

	if (ac != 2)
		exit(EXIT_FAILURE);
	file = NULL;
	fd = open(av[1], O_RDONLY);
	file = get_file(fd);
	close(fd);
	i = 0;
	while (file[i])
		ft_printf("%s", file[i++]);
	// if (!check_map(ac, av))
	// 	return (1);
	return (0);
}

void ceci_est_un_test(void)
{
	ft_printf("test");
}