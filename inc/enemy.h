#ifndef ENEMY_H
# define ENEMY_H
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "random.h"
# include "map.h"
# include "menu.h"

# define MAXTRYS 100

void	set_enemies(t_data *data);
void	move_enemies(t_data *data);
void	enemy_move_horizontal(t_data *data);
void	enemy_move_vertical(t_data *data);

#endif