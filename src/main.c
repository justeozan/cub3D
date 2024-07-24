/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:04 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 14:04:52 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	
	if (!check(ac, av))
		return (EXIT_FAILURE);
	
	
	return (0);
}

void ceci_est_un_test(void)
{
	ft_printf("test");
}