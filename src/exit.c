/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:40:32 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:48:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	static_print_errormessage(char *errorflag)
{
	char	*errormessage[ERRORS];
	int		msglen;
	int		i;

	errormessage[ERROR1] = "Too many arguments!\n";
	errormessage[ERROR2] = "No map-file!\n";
	errormessage[ERROR3] = "Map is not rectangular!\n";
	errormessage[ERROR4] = "Map is not surrounded by walls!\n";
	errormessage[ERROR5] = "Invalid number of starting positions!\n";
	errormessage[ERROR6] = "Map does not have an exit!\n";
	errormessage[ERROR7] = "Map does not have a collectible!\n";
	errormessage[ERROR8] = "Invalid or empty map-file!\n";
	errormessage[ERROR9] = "Malloc failed!\n";
	errormessage[ERROR10] = "Open failed!\n";
	errormessage[ERROR11] = "Close failed!\n";
	errormessage[ERROR12] = "Failed to load image!\n";
	write(STDERR_FILENO, "Error\n", 6);
	i = 1;
	while (errorflag[i] != '\0')
	{
		msglen = ft_strlen(errormessage[i]);
		if (errorflag[i] == '1')
			write(STDERR_FILENO, errormessage[i], msglen);
		i++;
	}
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	destroy_mlx(t_data *data)
{
	int	i;

	i = 0;
	while (data->imgs[i] != NULL && i < IMAGES)
	{
		if (data->mlx != NULL && data->imgs[i]->img != NULL)
		{
			mlx_destroy_image(data->mlx, data->imgs[i]->img);
			free(data->imgs[i]);
		}
		i++;
	}
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
}

void	exit_error(t_data *data, char *errorflag)
{	
	if (data != NULL && data->map != NULL)
		free_map(data->map);
	if (data != NULL)
		destroy_mlx(data);
	static_print_errormessage(errorflag);
	exit(EXIT_FAILURE);
}

int	exit_program(t_data *data)
{	
	if (data->map != NULL)
		free_map(data->map);
	destroy_mlx(data);
	free(data->move_count_str);
	exit(EXIT_SUCCESS);
}
