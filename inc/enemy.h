#ifndef ENEMY_H
# define ENEMY_H
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "random.h"
# include "map.h"
# include "menu.h"
# include "utils.h"

# define MAXTRYS 100

void	set_enemies(t_data *data);
void	move_enemy(t_data *data);
void	enemy_move_horizontal(t_data *data);
void	enemy_move_vertical(t_data *data);
bool	is_valid_enemy_position(t_data *data, int x, int y);

#endif