#include "enemy.h"

static void	static_put_enemy(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[ENEMY_IMAGE]->img,
		data->enemy.x * data->img_size, data->enemy.y * data->img_size);
}

static bool static_is_valid_enemy_pos(t_data *data, int x, int y)
{
	if (data->map[y][x] == SPACE)
		return (true);
	else if (data->map[y][x] == START && data->timer != OFF)
		return (true);
	return (false);
}

static void	static_move_enemy(t_data *data, int dx, int dy)
{
	ft_put_space(data, data->enemy.x, data->enemy.y);
	data->enemy.x += dx;
	data->enemy.y += dy;
	static_put_enemy(data);
}


static void	static_enemy_move_random(t_data *data)
{
	int direction;
	int count;

	count = 0;
	while (count < MAXTRYS)
	{
		direction = generate_random_number_from_1_to_max(data, 4);
		// ft_printf("direction: %d\n", direction);
		if (direction == UP)
		{
			if (static_is_valid_enemy_pos(data, data->enemy.x, data->enemy.y - 1))
			{
				static_move_enemy(data, 0, -1);
				break ;
			}
		}
		else if (direction == LEFT)
		{
			// (*data)->side = PLAYER_L_IMAGE;
			// ft_put_player(*data);
			if (static_is_valid_enemy_pos(data, data->enemy.x - 1, data->enemy.y))
			{
				static_move_enemy(data, -1, 0);
				break ;
			}
		}
		else if (direction == DOWN)
		{
			if (static_is_valid_enemy_pos(data, data->enemy.x, data->enemy.y + 1))
			{
				static_move_enemy(data, 0, 1);
				break ;
			}
		}
		else if (direction == RIGHT)
		{
			// (*data)->side = PLAYER_IMAGE;
			// ft_put_player(*data);
			if (static_is_valid_enemy_pos(data, data->enemy.x + 1, data->enemy.y))
			{
				static_move_enemy(data, 1, 0);
				break ;
			}
		}
		count ++;
	}
}

void	enemy_move_vertical(t_data *data)
{
	int direction;

	direction = data->player.y - data->enemy.y;
	if (direction > 0)
	{
		if (static_is_valid_enemy_pos(data, data->enemy.x, data->enemy.y + 1))
			static_move_enemy(data, 0, 1);
		else
			static_enemy_move_random(data);
	}
	else if (direction < 0)
	{
		if (static_is_valid_enemy_pos(data, data->enemy.x, data->enemy.y - 1))
			static_move_enemy(data, 0, -1);
		else
			static_enemy_move_random(data);
	}
	else
		enemy_move_horizontal(data);
}

void	enemy_move_horizontal(t_data *data)
{
	int direction;

	direction = data->player.x - data->enemy.x;
	if (direction > 0)
	{
		if (static_is_valid_enemy_pos(data, data->enemy.x + 1, data->enemy.y))
			static_move_enemy(data, 1, 0);
		else
			static_enemy_move_random(data);
	}
	else if (direction < 0)
	{
		if (static_is_valid_enemy_pos(data, data->enemy.x - 1, data->enemy.y))
			static_move_enemy(data, -1, 0);
		else
			static_enemy_move_random(data);
	}
	else
		enemy_move_vertical(data);
}

void	move_enemies(t_data *data)
{
	int direction;

	if (data->enemy.status == false)
		return ;
	direction = generate_random_number_from_1_to_max(data, 2);
	if (direction % 2)
		enemy_move_horizontal(data);
	else
		enemy_move_vertical(data);
	if (data->enemy.x == data->player.x && data->enemy.y == data->player.y)
		show_menu(data, "You lost!");
}

void	set_enemies(t_data *data)
{
	int 	x;
	int 	y;
	int		count;

	generate_seed(data);
	data->enemy.status = false;
	count = 0;
	while(count < MAXTRYS)
	{
		x = generate_random_number_from_1_to_max(data, data->mwidth - 1);
		y = generate_random_number_from_1_to_max(data, data->mheight - 1);
		if (static_is_valid_enemy_pos(data, x, y))
		{
			data->enemy.status = true;
			data->enemy.x = x;
			data->enemy.y = y;
			break ;
		}
		count ++;
	}
	if (data->enemy.status)
		static_put_enemy(data);
}
