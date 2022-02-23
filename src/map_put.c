/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:44:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:44:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_put_enemy(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[ENEMY_IMAGE]->img,
		data->enemy.x * data->img_size, data->enemy.y * data->img_size);
}

void	ft_put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->imgs[data->player.side]->img, data->player.x * data->img_size,
		data->player.y * data->img_size);
}

void	ft_put_space(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[SPACE_IMAGE]->img,
		x * data->img_size, y * data->img_size);
}

void	ft_put_tile(t_data *data, int x, int y, int tile)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[tile]->img,
		x * data->img_size, y * data->img_size);
}

void	ft_put_countbar(t_data *data)
{
	int	x;

	x = 0;
	while (x <= data->grid.width)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgs[BLACK_IMAGE]->img, x * data->img_size,
			(data->grid.height + 1) * data->img_size);
		x++;
	}
}
