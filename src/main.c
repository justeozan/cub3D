/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:04 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/17 11:44:53 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	if (!check_args(av))
		return (print_error("args error: format: ./cub3D <map_name.cub>"), ft_exit());
	if (!check_map(av[1]))
		return (print_error("Map error"), ft_exit());
	
	
}
