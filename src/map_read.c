/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:09 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:58:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	static_exit_from_read(char **map, char *errorflag)
{
	free(map);
	exit_error(NULL, errorflag);
}

int	count_lines(char *filepath)
{
	int		fd;
	char	*line;
	int		linecount;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		exit_error(NULL, "00000000001");
	linecount = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		linecount++;
		free(line);
		line = ft_gnl(fd);
	}
	if (close(fd) == -1)
		exit_error(NULL, "000000000001");
	return (linecount);
}

void	replace_char1_with_char2(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
}

void	read_map(t_data *data, char *filepath)
{
	int		fd;
	int		numberoflines;
	int		y;

	numberoflines = count_lines(filepath);
	data->map = malloc(sizeof(char *) * (numberoflines + 1));
	if (data->map == NULL)
		exit_error(NULL, "0000000001");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		static_exit_from_read(data->map, "00000000001");
	y = 0;
	while (y < numberoflines)
	{
		data->map[y] = ft_gnl(fd);
		if (data->map[y] == NULL)
			exit_error(data, "0000000001");
		replace_char1_with_char2(data->map[y], '\n', '\0');
		y++;
	}
	data->map[numberoflines] = NULL;
	if (close(fd) == -1)
		static_exit_from_read(data->map, "000000000001");
	check_map(data, numberoflines);
}
