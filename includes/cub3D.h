/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:10:14 by ozasahin          #+#    #+#             */
/*   Updated: 2024/07/24 11:33:49 by avialle-         ###   ########.fr       */
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

/*=== Structures ===*/
/*=== Fonctions ===*/
// check_map.c
bool	check_map(int ac, char	**args);

// error.c
void	print_error_msg(char *str);
void	ft_exit(char *str, int error_code);

#endif
