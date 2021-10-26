/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:26 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 20:39:29 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	ft_initialize_buffer_with(char *buffer, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
}

static void	static_ft_set_height(t_data *data)
{
	data->wheight = 0;
	while (data->map[data->wheight] != NULL)
		data->wheight += 1;
	data->wheight *= data->img_size;
	data->wheight += COUNTBAR;
}

static void	static_ft_set_width(t_data *data)
{
	int	len;

	len = ft_strlen(*data->map);
	data->wwidth = len * data->img_size;
}

void	ft_initialize(t_data *data)
{
	data->p_side = PLAYER_IMAGE;
	data->loot_count = 0;
	data->move_count = 0;
	data->img_size = TILE_SIZE;
	static_ft_set_width(data);
	static_ft_set_height(data);
	while ((data->wwidth > SCREENWIDTH
			|| data->wheight > SCREENHEIGHT - WINDOWBAR - COUNTBAR)
		&& data->img_size > PIXELLIMIT)
	{
		data->img_size /= 2;
		static_ft_set_width(data);
		static_ft_set_height(data);
	}
}
