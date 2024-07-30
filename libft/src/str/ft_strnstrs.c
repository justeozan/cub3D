/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:09:37 by avialle-          #+#    #+#             */
/*   Updated: 2024/07/30 10:53:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// bool	ft_strnstrs(char **s1, char *s2, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		k;
// 	size_t	len_s1;
// 	int		count;

// 	k = -1;
// 	i = 0;
// 	count = 0;
// 	if (!s2[0])
// 		return (0);
// 	while (s1[++k])
// 	{
// 		len_s1 = ft_strlen(s1[k]);
// 		while (s1[k][i])
// 		{
// 			j = 0;
// 			while (s2[j] == s1[k][i + j] && j < len && i + j < len_s1)
// 				j++;
// 			if (j == len)
// 				count++;
// 			i++;
// 		}
// 	}
// 	return (count);
// }

bool	ft_strnstrs(char **s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len_s1;
	int		count;

	i = -1;
	count = 0;
	while (s1[++i] && s2[0])
	{
		len_s1 = ft_strlen(s1[i]);
		j = -1;
		while (s1[i][++j])
		{
			k = 0;
			while (s2[k] == s1[i][j + k] && k < len && j + k < len_s1)
				k++;
			if (k == len)
				count++;
		}
	}
	ft_printf("count = %d\n", count);
	if (count != 1)
		return (false);
	return (true);
}
