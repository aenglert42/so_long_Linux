#include "map.h"

void	ft_put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[data->player.side]->img,
		data->player.x * data->img_size, data->player.y * data->img_size);
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
	int x;
	
	x = 0;
	while (x <= data->mwidth)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgs[BLACK_IMAGE]->img,
			x * data->img_size, (data->mheight + 1) * data->img_size);
		x++;
	}
}
