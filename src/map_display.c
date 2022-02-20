#include "map.h"

static void	static_ft_put_tile_to_image(t_data *data, int x, int y)
{
	int	i;

	if (data->map[y][x] == WALL)
		i = WALL_IMAGE;
	else if (data->map[y][x] == EXIT)
		i = EXIT_IMAGE;
	else if (data->map[y][x] == LOOT)
		i = LOOT_IMAGE;
	else
		i = SPACE_IMAGE;
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i]->img,
		x * data->img_size, y * data->img_size);
}

static void	static_ft_create_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == START)
			{
				data->p_x = x;
				data->p_y = y;
			}
			else if (data->map[y][x] == LOOT)
				data->loot_count += 1;
			if (data->map[y][x] != SPACE)
				static_ft_put_tile_to_image(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_iterate_map(t_data *data, int tile)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			ft_put_tile(data, x, y, tile);
			data->mwidth = x;
			x++;
		}
		data->mheight = y;
		y++;
	}
}

void	ft_display_map(t_data *data)
{
	ft_iterate_map(data, SPACE_IMAGE);
	static_ft_create_map(data);
	ft_put_countbar(data);
	ft_put_player(data);
	set_enemies(data);
}
