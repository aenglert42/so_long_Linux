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

void	enemy_move_vertical(t_data *data)
{
	int direction;

	direction = data->p_y - data->e_y;
	if (direction > 0)
	{
		if (static_is_valid_enemy_pos(data, data->e_x, data->e_y + 1))
			static_move_enemy(data, 0, 1);
	}
	else if (direction < 0)
	{
		if (static_is_valid_enemy_pos(data, data->e_x, data->e_y - 1))
			static_move_enemy(data, 0, -1);
	}
	else
		enemy_move_horizontal(data);
}

void	enemy_move_horizontal(t_data *data)
{
	int direction;

	direction = data->p_x - data->e_x;
	if (direction > 0)
	{
		if (static_is_valid_enemy_pos(data, data->e_x + 1, data->e_y))
			static_move_enemy(data, 1, 0);
	}
	else if (direction < 0)
	{
		if (static_is_valid_enemy_pos(data, data->e_x - 1, data->e_y))
			static_move_enemy(data, -1, 0);
	}
	else
		enemy_move_vertical(data);
}

void	move_enemies(t_data *data)
{
	int direction;

	if (data->e_status == false)
		return ;
	direction = generate_random_number_from_1_to_max(data, 2);
	// ft_printf("direction: %d\n", direction);
	// ft_printf("odd: %d\n", direction % 2);
	if (direction % 2)
		enemy_move_horizontal(data);
	else
		enemy_move_vertical(data);
	if (data->e_x == data->p_x && data->e_y == data->p_y)
		show_menu(data, "You lost!");
}

// void	move_enemies_random(t_data *data)
// {
// 	int direction;
// 	int count;

// 	count = 0;
// 	while (count < MAXTRYS)
// 	{
// 		direction = generate_random_number_from_1_to_max(data, 4);
// 		// ft_printf("direction: %d\n", direction);
// 		if (direction == UP)
// 		{
// 			if (static_is_valid_enemy_pos(data, data->e_x, data->e_y - 1))
// 			{
// 				static_move_enemy(data, 0, -1);
// 				break ;
// 			}
// 		}
// 		else if (direction == LEFT)
// 		{
// 			// (*data)->p_side = PLAYER_L_IMAGE;
// 			// ft_put_player(*data);
// 			if (static_is_valid_enemy_pos(data, data->e_x - 1, data->e_y))
// 			{
// 				static_move_enemy(data, -1, 0);
// 				break ;
// 			}
// 		}
// 		else if (direction == DOWN)
// 		{
// 			if (static_is_valid_enemy_pos(data, data->e_x, data->e_y + 1))
// 			{
// 				static_move_enemy(data, 0, 1);
// 				break ;
// 			}
// 		}
// 		else if (direction == RIGHT)
// 		{
// 			// (*data)->p_side = PLAYER_IMAGE;
// 			// ft_put_player(*data);
// 			if (static_is_valid_enemy_pos(data, data->e_x + 1, data->e_y))
// 			{
// 				static_move_enemy(data, 1, 0);
// 				break ;
// 			}
// 		}
// 		count ++;
// 	}
// }

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
