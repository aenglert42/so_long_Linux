#include "map.h"

void	ft_put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[data->p_side]->img,
		data->p_x * data->img_size, data->p_y * data->img_size);
}

void	ft_put_space(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[SPACE_IMAGE]->img,
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
