#include "game.h"

static void	static_display_new_movementcount(t_data **data)
{
	ft_put_countbar(*data);
	free((*data)->move_count_str);
	(*data)->move_count_str = ft_strjoin("movements ", ft_itoa((*data)->move_count)); // free?
	mlx_string_put((*data)->mlx, (*data)->win, COUNTBAR / 2, ((*data)->mheight + 1) * (*data)->img_size + COUNTBAR * 2 / 3,
			ORANGE, (*data)->move_count_str);
}

static void	static_ft_execute_movement(t_data **data, int dx, int dy)
{
	(*data)->move_count += 1;
	static_display_new_movementcount(data);
	ft_put_space(*data, (*data)->p_x, (*data)->p_y);
	(*data)->p_x += dx;
	(*data)->p_y += dy;
	if ((*data)->map[(*data)->p_y][(*data)->p_x] == LOOT)
	{
		(*data)->map[(*data)->p_y][(*data)->p_x] = SPACE;
		ft_put_space(*data, (*data)->p_x, (*data)->p_y);
		(*data)->loot_count -= 1;
	}
	else if ((*data)->e_x == (*data)->p_x && (*data)->e_y == (*data)->p_y)
		show_menu(*data, "You lost!");
	else if ((*data)->map[(*data)->p_y][(*data)->p_x] == EXIT)
	{
		ft_put_player(*data);
		show_menu(*data, "You won!");
		// ft_printf("You finished the game with %d movements.\n", (*data)->move_count);
		// ft_exit_program(*data);
	}
	ft_put_player(*data);
}

static bool	st_ft_val_move(t_data **data, int dx, int dy)
{
	char	c;

	c = (*data)->map[(*data)->p_y + dy][(*data)->p_x + dx];
	if (c == WALL)
		return (false);
	else if (c == EXIT && (*data)->loot_count != 0)
		return (false);
	else
		return (true);
}

static void	static_ft_move_player(t_data **data, int direction)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (direction == UP)
		dy = -1;
	else if (direction == DOWN)
		dy = 1;
	else if (direction == LEFT)
		dx = -1;
	else if (direction == RIGHT)
		dx = 1;
	if (st_ft_val_move(data, dx, dy))
		static_ft_execute_movement(data, dx, dy);
}

static int	static_ft_key_hook(int keycode, t_data **data)
{
	(*data)->timer = ON;
	if (keycode == ESC_KEY)
		ft_exit_program(*data);
	else if (keycode == W_KEY || keycode == UP_KEY)
		static_ft_move_player(data, UP);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		(*data)->p_side = PLAYER_L_IMAGE;
		ft_put_player(*data);
		static_ft_move_player(data, LEFT);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		static_ft_move_player(data, DOWN);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		(*data)->p_side = PLAYER_IMAGE;
		ft_put_player(*data);
		static_ft_move_player(data, RIGHT);
	}
	if (!((*data)->counter % 3)) //magic number
		move_enemies(*data);
	(*data)->counter++;
	return (0);
}

void	ft_start_game(t_data *data)
{
	data->move_count_str = ft_strjoin("movements ", ft_itoa(data->move_count)); //free on exit
//	ft_printf("movements: 0\n");
	// data->mlx = mlx_init();
	ft_load_images(data);
	data->win = mlx_new_window(data->mlx, data->wwidth, data->wheight,
			"so_long");
	ft_display_map(data);
	mlx_string_put(data->mlx, data->win, COUNTBAR / 2, (data->mheight + 1) * data->img_size + COUNTBAR * 2 / 3,
			ORANGE, data->move_count_str);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_exit_program, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, static_ft_key_hook, &data);
	mlx_loop_hook(data->mlx, timer, data);
	mlx_loop(data->mlx);
}
