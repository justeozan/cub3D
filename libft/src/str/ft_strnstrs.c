/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:20:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 15:48:55 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strnstrs(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	len_s1 = ft_strlen(s1);
	if (!s2[j])
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && j < len && i + j < len_s1)
			j++;
		if (j == len)
			count++;
		i++;
	}
	return (count);
}

