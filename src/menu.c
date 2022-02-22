#include "menu.h"

static int	static_ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_exit_program(data);
	return (EXIT_SUCCESS);
}

void	show_menu(t_data *data, char *str)
{
	int		len;

	data->timer = OFF; //magic number
	len = 10 * CHARWIDTH;
	ft_put_countbar(data);
	ft_iterate_map(data, BLACK_IMAGE);
	mlx_string_put(data->mlx, data->win, (data->mwidth / 2) * data->img_size - len, (data->mheight / 2) * data->img_size,
			ORANGE, str);
	mlx_string_put(data->mlx, data->win, (data->mwidth / 2) * data->img_size - len, (data->mheight / 2) * data->img_size
		+ CHARHEIGHT, ORANGE, "Press ESC to exit.");
	mlx_hook(data->win, KeyPress, KeyPressMask, static_ft_key_hook, data);
	// mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_exit_program, data);
	mlx_loop(data->mlx);
}