/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:19 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 13:57:38 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief	Initialize the data structure
*/
t_data	*init_struct(void)
{
	t_data	*data;

	data = gc_calloc(1, sizeof(t_data), DATA);
	if (!data)
		return (ft_exit(ERR_MALLOC), NULL);
	return (data);
}
