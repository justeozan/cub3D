/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:04 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 15:33:53 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	if (check_map(ac, av))
		return (1);
	return (0);
}

void ceci_est_un_test(void)
{
	ft_printf("test");
}