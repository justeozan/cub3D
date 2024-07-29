/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:10:14 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/29 17:06:33 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*=== Includes ===*/

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

/*=== Color ===*/

# define RESET	"\033[0m"
# define RED	"\033[0;31m"
# define WHITE	"\033[37m"
# define GREEN	"\033[32m"

/*=== Error messages ===*/

# define ERR_MALLOC "Error: Memory allocation failed with malloc.\n"
# define ERR_ARGS "Error: args format: ./cub3D <map_name.cub>"
# define ERR_FILE "Error: bad fd"
# define ERR_TEXTURE "Error: texture(s) file(s) missing or has bad format"
# define COLOR_FORMAT_ERROR "Error\nInvalid color format.\n"

/*=== Structures ===*/
enum e_gc_id
{
	DATA,
	MATRIX,
	TEXTURE,
	TMP
};
typedef struct s_matrix
{
	int	x;
	int	y;
	int	wall;
	int	xproj;
	int	yproj;
	int	zproj;
}	t_matrix;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_matrix	*matrix;
	char		**file;
}	t_data;
/*=== Fonctions ===*/
// check_map.c
bool	check_map(int ac, char	**args);

// PARSING

// parse_colors.c
void	parse_colors(t_data *data, char *line);

// error.c
void	parse_texture(t_data *data, char *line);

// error.c
void	print_error_msg(char *str);
void	ft_exit(char *str, int error_code);
t_data	*parse(int ac, char	**args);

#endif
