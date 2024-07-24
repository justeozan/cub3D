/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:20:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 14:37:04 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr2(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	if (!s2[j])
		return ((char *)s1);
	while (s1[i] && i < len_s1)
	{
		j = 0;
		while (s2[j] == s1[i + j] && j < len && i + j < len_s1)
			j++;
		if (j == len && !s1[i + j])
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	if (!s2[j])
		return ((char *)s1);
	while (s1[i] && i < len_s1)
	{
		j = 0;
		while (s2[j] == s1[i + j] && j < len && i + j < len_s1)
			j++;
		if (j == len)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}