/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:19 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:09:20 by ozasahin         ###   ########.fr       */
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
