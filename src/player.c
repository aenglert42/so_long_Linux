#include "player.h"

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

void	ft_move_player(t_data **data, int direction)
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
