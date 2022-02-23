#include "game.h"

static int	static_ft_key_hook(int keycode, t_data **data)
{
	(*data)->timer = ON;
	if (keycode == ESC_KEY)
		ft_exit_program(*data);
	else if (keycode == W_KEY || keycode == UP_KEY)
		ft_move_player(data, UP);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		(*data)->player.side = PLAYER_L_IMAGE;
		ft_put_player(*data);
		ft_move_player(data, LEFT);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		ft_move_player(data, DOWN);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		(*data)->player.side = PLAYER_IMAGE;
		ft_put_player(*data);
		ft_move_player(data, RIGHT);
	}
	if (!((*data)->counter % 3)) //magic number
		move_enemies(*data);
	(*data)->counter++;
	return (0);
}

void	ft_start_game(t_data *data)
{
	data->move_count_str = ft_strjoin("movements ", ft_itoa(data->move_count)); //free on exit
	ft_load_images(data);
	data->win = mlx_new_window(data->mlx, data->window.width, data->window.height,
			"so_long");
	ft_display_map(data);
	mlx_string_put(data->mlx, data->win, COUNTBAR / 2, (data->grid.height + 1) * data->img_size + COUNTBAR * 2 / 3,
			ORANGE, data->move_count_str);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_exit_program, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, static_ft_key_hook, &data);
	mlx_loop_hook(data->mlx, timer, data);
	mlx_loop(data->mlx);
}
