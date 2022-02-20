#ifndef RANDOM_H
# define RANDOM_H
# include "../libft/includes/libft.h"
# include "so_long.h"

void	generate_seed(t_data *data);
unsigned int generate_random_number_from_1_to_max(t_data *data, int max);

#endif