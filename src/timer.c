#include "timer.h"

int	timer(t_data *data)
{
	if (data->timer == OFF) //magic number
		return (EXIT_SUCCESS);
	data->timer++;
	if (data->timer == 1000)
	{
		move_enemies(data);
	}
	else if (data->timer == 3000)
	{
		data->timer = 0;
	}
	return (EXIT_SUCCESS);
}
