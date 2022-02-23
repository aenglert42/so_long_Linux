/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:32:36 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:39:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_delta(t_data *data, int direction)
{
	data->dx = 0;
	data->dy = 0;
	if (direction == UP)
		data->dy = -1;
	else if (direction == DOWN)
		data->dy = 1;
	else if (direction == LEFT)
		data->dx = -1;
	else if (direction == RIGHT)
		data->dx = 1;
}

void	display_movementcount(t_data *data)
{
	mlx_string_put(data->mlx, data->win, COUNTBAR / 2,
		(data->grid.height + 1) * data->img_size + COUNTBAR * 2 / 3,
		ORANGE, data->move_count_str);
}
