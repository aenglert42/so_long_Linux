#ifndef PLAYER_H
# define PLAYER_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "exit.h"
# include "map.h"
# include "enemy.h"
# include "random.h"
# include "timer.h"
# include "utils.h"

void	ft_move_player(t_data **data, int direction);

#endif