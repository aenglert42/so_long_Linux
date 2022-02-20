#include "random.h"

static unsigned long static_sum_of_digits(unsigned long z)
{
	unsigned long sum;

	sum = 0;
	while (z > 0)
	{
		sum += z % 10;
		z /= 10;
	}
	return sum;
}

// unsigned int static_generate_number(t_data *data)
// {
// 	int modifier1;
// 	int modifier2;

// 	mlx_mouse_get_pos(data->mlx, data->win, &modifier1, &modifier2);
// 	data->rand = data->rand * modifier1;
// 	data->rand = data->rand + modifier2;
// 	return (data->rand);
// }

// unsigned int generate_random_number_from_1_to_max(t_data *data, int max)
// {
// 	unsigned int number;

// 	number = static_generate_number(data);
// 	number = number % 10;
// 	// ft_printf("number4: %u\n", number);
// 	while (number >= (unsigned int) max)
// 		number /= 2;
// 	return (number + 1);
// }

static unsigned static_myrand(unsigned short lfsr)
{
	unsigned bit;
	
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}

unsigned int generate_random_number_from_1_to_max(t_data *data, int max)
{
	data->rand = static_myrand(data->rand);
	return (data->rand % max + 1);
}

void generate_seed(t_data *data)
{
	unsigned long seed;

	seed = (unsigned long)&seed;
	seed = static_sum_of_digits(seed);
	data->rand = ((unsigned int)seed);
	// ft_printf("rand: %d\n", data->rand);
}