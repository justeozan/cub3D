/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:09:37 by avialle-          #+#    #+#             */
/*   Updated: 2024/07/24 16:09:42 by avialle-         ###   ########.fr       */
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
