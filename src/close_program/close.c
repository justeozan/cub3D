/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avg38 <avg38@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 03:04:11 by avg38            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	print_error_msg(char *str)
{
	ft_printf(RED"%s\n"RESET, str);
}

// void	ft_exit(char *str, int error_code)
// {
// 	print_error_msg(str);
// 	gc_clear(TMP, free);
// 	gc_clear(DATA, free);
// 	gc_clear(MAP, free);
// 	gc_clear(SPRITES, free);
// 	exit(error_code);
// }

/***************************************
 * @file	error.c
 * @brief	Exit the program with an failure code (1)
 * 			And print the error message.
 * 			Example: ft_exit(ERR_MALLOC);
 * @param	str: the error message to print
 * @note	The error message must be defined in the error messages section.
 * @details	The previous function had an error code as a parameter,
 * 			prototype: ft_exit(char *str, int error_code);
***************************************/
void	ft_exit(char *str)
{
	t_gc_id	id;

	id = -1;
	print_error_msg(str);
	while (++id <= TMP)
		gc_clear(id, free);
	exit(EXIT_FAILURE);
}

/***************************************
 * @brief	Close the program with a success code (0)
 * 			And print no message.
 * 			Example: close_program();
***************************************/
int	close_program(void)
{
	t_gc_id	id;

	id = -1;
	while (++id <= TMP)
		gc_clear(id, free);
	return (exit(EXIT_SUCCESS), 0);
}
