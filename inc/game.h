#ifndef GAME_H
# define GAME_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "exit.h"
# include "map.h"
# include "enemy.h"
# include "random.h"
# include "timer.h"
# include "player.h"

# define INTERVAL 3

void	ft_start_game(t_data *data);

#endif