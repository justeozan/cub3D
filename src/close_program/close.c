/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 16:51:03 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_data	*set_get_data(t_data *data)
{
	static t_data	*data_ptr;

	if (data)
		data_ptr = data;
	return (data_ptr);
}

int	after_mlx_init(int i)
{
	static bool	after_mlx_init;

	if (i)
		after_mlx_init = i;
	return (after_mlx_init);
}

/***************************************
 * @brief	Print the error message in red color
 * @param	str: the error message to print
***************************************/
static void	print_error_msg(char *str)
{
	ft_printf(RED"%s\n"RESET, str);
}

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

	print_error_msg(str);
	data = set_get_data(NULL);
	if (after_mlx_init(0) == 3)
		if (data->img.img_ptr)
			mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	id = -1;
	if (after_mlx_init(0) == 4)
		while (++id < 4)
			if (data->sprites[id].reference)
				mlx_destroy_image(data->mlx.mlx_ptr, data->sprites[id].reference);
	if (after_mlx_init(0) == 2)
		if (data->mlx.win_ptr)
			mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (after_mlx_init(0) == 1)
		if (data->mlx.mlx_ptr)
			mlx_destroy_display(data->mlx.mlx_ptr);
	id = -1;
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
	t_data	*data;
	t_gc_id	id;

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
	id = -1;
	while (++id <= TMP)
		gc_clear(id, free);
	return (exit(EXIT_SUCCESS), 0);
}
