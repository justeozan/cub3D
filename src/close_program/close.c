/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sei <sei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 19:19:05 by sei              ###   ########.fr       */
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
	t_data	*data;
	t_gc_id	id;

	id = -1;
	print_error_msg(str);
	while (++id <= TMP)
		gc_clear(id, free);
	data = set_get_data(NULL);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	id = -1;
	while (++id < 4)
		if (data->sprites[id].reference)
			mlx_destroy_image(data->mlx.mlx_ptr, data->sprites[id].reference);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
		mlx_destroy_display(data->mlx.mlx_ptr);
	exit(EXIT_FAILURE);
}

/***************************************
 * @brief	Close the program with a success code (0)
 * 			And print no message.
 * 			Example: close_program();
***************************************/
int	close_program(void)
{
	t_data	*data;
	t_gc_id	id;

	id = -1;
	while (++id <= TMP)
		gc_clear(id, free);
	data = set_get_data(NULL);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	id = -1;
	while (++id < 4)
		if (data->sprites[id].reference)
			mlx_destroy_image(data->mlx.mlx_ptr, data->sprites[id].reference);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
		mlx_destroy_display(data->mlx.mlx_ptr);
	return (exit(EXIT_SUCCESS), 0);
}
