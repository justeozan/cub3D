/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avg38 <avg38@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:10 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 00:11:25 by avg38            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	*parse_line_map(char *str)
{
	int		last_non_space;
	char	*new_line;
	int		len;
	int		i;
	int		j;

	i = -1;
	len = 0;
	last_non_space = -1;
	while (str[++i] && str[i] != '\n')
	{
		len++;
		if (str[i] != ' ')
			last_non_space = i;
	}
	new_line = gc_malloc(sizeof(char) * (last_non_space + 2), TMP);
	if (!new_line)
		return (NULL);
	i = -1;
	j = -1;
	while (++i <= last_non_space)
		new_line[++j] = str[i];
	new_line[++j] = '\0';
	return (new_line);
}

static char	*parse_line(char *str)
{
	char	*new_line;
	int		len;
	int		i;
	int		j;

	i = -1;
	len = 0;
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t')
			len++;
	new_line = gc_malloc(sizeof(char) * len + 3, TMP);
	if (!new_line)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '\n' && str[i] != ' ')
		new_line[++j] = str[i];
	new_line[++j] = ' ';
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			new_line[++j] = str[i];
	new_line[++j] = '\0';
	return (new_line);
}

static int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static char	**delete_whitespaces(char **file)
{
	int	line;
	int	i;
	int	j;

	i = -1;
	line = 0;
	while (file[++i])
	{
		while (ft_isempty(file[i]) > 0)
			i++;
		if (!file[i])
			break ;
		j = 0;
		while (file[i][j] == ' ')
			j++;
		if (ft_isalpha(file[i][j]))
			file[line] = gc_strdup(parse_line(&file[i][j]), TMP);
		else
			file[line] = gc_strdup(parse_line_map(file[i]), TMP);
		line++;
	}
	file[line] = NULL;
	while (file[line])
		free(file[line++]);
	return (file);
}

/***************************************
 * @file	parse_file.c
 * @brief	Parse the map file
 * @param	fd: the file descriptor
 * @return	The file without whitespaces, NULL if an error occured
***************************************/
char	**get_file(int fd)
{
	char	**file;
	int		i;

	file = gc_malloc(sizeof(char *) * 2, TMP); // REVIEW - mettre calloc a la place
	if (!file)
		ft_exit(ERR_MALLOC);
	i = -1;
	file[++i] = get_next_line(fd);
	if (!file[i])
		ft_exit(ERR_FILE_2);
	while (file[i])
	{
		i++;
		file = gc_realloc(file, i, sizeof(char *) * (i + 1), TMP);
		if (!file)
			ft_exit(ERR_MALLOC);
		file[i] = get_next_line(fd);
	}
	check_file_format(file);
	return (delete_whitespaces(file));
}
