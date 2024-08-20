/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:15:40 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/20 05:45:20 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// TODO - Add comments

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = 1;
	else if (keycode == XK_s)
		data->keys.s = 1;
	else if (keycode == XK_a)
		data->keys.a = 1;
	else if (keycode == XK_d)
		data->keys.d = 1;
	else if (keycode == XK_Left)
		data->keys.left = 1;
	else if (keycode == XK_Right)
		data->keys.right = 1;
	else if (keycode == XK_Escape)
		close_program();
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = 0;
	else if (keycode == XK_s)
		data->keys.s = 0;
	else if (keycode == XK_a)
		data->keys.a = 0;
	else if (keycode == XK_d)
		data->keys.d = 0;
	else if (keycode == XK_Left)
		data->keys.left = 0;
	else if (keycode == XK_Right)
		data->keys.right = 0;
	return (0);
}
