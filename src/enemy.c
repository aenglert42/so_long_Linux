#include "enemy.h"

static void	static_put_enemy(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[ENEMY_IMAGE]->img,
		data->e_x * data->img_size, data->e_y * data->img_size);
}

static bool static_is_valid_enemy_pos(t_data *data, int x, int y)
{
	if (data->map[y][x] == SPACE)
		return (true);
	return (false);
}

static void	static_move_enemy(t_data *data, int dx, int dy)
{
	ft_put_space(data, data->e_x, data->e_y);
	data->e_x += dx;
	data->e_y += dy;
	static_put_enemy(data);
}

// static void	static_move_vertical(t_data *data)
// {

// }

// static void	static_move_horizontal(t_data *data)
// {

// }

// void	move_enemies(t_data *data)
// {
// 	int direction;
// 	int count;

// 	count = 0;
// 	while (count < MAXTRYS)
// 	{
// 		direction = generate_random_number_from_1_to_max(data, 2);
// 		ft_printf("direction: %d\n", direction);
// 		// if (direction == UP)
// 		// {
// 		// 	if (static_is_valid_enemy_pos(data, data->e_x, data->e_y - 1))
// 		// 	{
// 		// 		static_move_enemy(data, 0, -1);
// 		// 		break ;
// 		// 	}
// 		// }
// 		// else if (direction == LEFT)
// 		// {
// 		// 	// (*data)->p_side = PLAYER_L_IMAGE;
// 		// 	// ft_put_player(*data);
// 		// 	if (static_is_valid_enemy_pos(data, data->e_x - 1, data->e_y))
// 		// 	{
// 		// 		static_move_enemy(data, -1, 0);
// 		// 		break ;
// 		// 	}
// 		// }
// 		// else if (direction == DOWN)
// 		// {
// 		// 	if (static_is_valid_enemy_pos(data, data->e_x, data->e_y + 1))
// 		// 	{
// 		// 		static_move_enemy(data, 0, 1);
// 		// 		break ;
// 		// 	}
// 		// }
// 		// else if (direction == RIGHT)
// 		// {
// 		// 	// (*data)->p_side = PLAYER_IMAGE;
// 		// 	// ft_put_player(*data);
// 		// 	if (static_is_valid_enemy_pos(data, data->e_x + 1, data->e_y))
// 		// 	{
// 		// 		static_move_enemy(data, 1, 0);
// 		// 		break ;
// 		// 	}
// 		// }
// 		count ++;
// 	}
// }

void	move_enemies(t_data *data)
{
	data = data + 0; // remove;
	int direction;
	int count;

	count = 0;
	while (count < MAXTRYS)
	{
		direction = generate_random_number_from_1_to_max(data, 4);
		// ft_printf("direction: %d\n", direction);
		if (direction == UP)
		{
			if (static_is_valid_enemy_pos(data, data->e_x, data->e_y - 1))
			{
				static_move_enemy(data, 0, -1);
				break ;
			}
		}
		else if (direction == LEFT)
		{
			// (*data)->p_side = PLAYER_L_IMAGE;
			// ft_put_player(*data);
			if (static_is_valid_enemy_pos(data, data->e_x - 1, data->e_y))
			{
				static_move_enemy(data, -1, 0);
				break ;
			}
		}
		else if (direction == DOWN)
		{
			if (static_is_valid_enemy_pos(data, data->e_x, data->e_y + 1))
			{
				static_move_enemy(data, 0, 1);
				break ;
			}
		}
		else if (direction == RIGHT)
		{
			// (*data)->p_side = PLAYER_IMAGE;
			// ft_put_player(*data);
			if (static_is_valid_enemy_pos(data, data->e_x + 1, data->e_y))
			{
				static_move_enemy(data, 1, 0);
				break ;
			}
		}
		count ++;
	}
}

void	set_enemies(t_data *data)
{
	int 	x;
	int 	y;
	int		count;

	generate_seed(data);
	data->e_status = false;
	count = 0;
	while(count < MAXTRYS)
	{
		x = generate_random_number_from_1_to_max(data, data->mwidth - 1);
		y = generate_random_number_from_1_to_max(data, data->mheight - 1);
		if (static_is_valid_enemy_pos(data, x, y))
		{
			data->e_status = true;
			data->e_x = x;
			data->e_y = y;
			break ;
		}
		count ++;
	}
	if (data->e_status)
		static_put_enemy(data);
}
