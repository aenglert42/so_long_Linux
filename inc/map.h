#ifndef MAP_H
# define MAP_H
# include "../libft/inc/libft.h"
# include "exit.h"
# include "initialize.h"
# include "so_long.h"
# include "enemy.h"

int		ft_count_lines(char *filepath);
void	ft_read_map(t_data *data, char *filepath);
void	ft_check_map(t_data *data, int numberoflines);
void	ft_display_map(t_data *data);
void	ft_put_space(t_data *data, int x, int y);
void	ft_put_tile(t_data *data, int x, int y, int tile);
void	ft_put_player(t_data *data);
void	ft_put_countbar(t_data *data);
void	ft_check_setup(char **map, char *errorflag, int columns, int lines);
void	ft_load_images(t_data *data);
void	ft_iterate_map(t_data *data, int tile);

#endif