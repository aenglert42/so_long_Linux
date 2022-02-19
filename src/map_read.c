#include "map.h"

static void	static_ft_exit_from_read(char **map, char *errorflag)
{
	free(map);
	ft_exit_error(NULL, errorflag);
}

int	ft_count_lines(char *filepath)
{
	int		fd;
	char	*line;
	int		linecount;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_exit_error(NULL, "00000000001");
	linecount = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		linecount++;
		free(line);
		line = ft_gnl(fd);
	}
	if (close(fd) == -1)
		ft_exit_error(NULL, "000000000001");
	return (linecount);
}

void	ft_replace_char1_with_char2(char *str, char c1, char c2)
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

void	ft_read_map(t_data *data, char *filepath)
{
	int		fd;
	int		numberoflines;
	int		y;

	numberoflines = ft_count_lines(filepath);
	data->map = malloc(sizeof(char *) * (numberoflines + 1));
	if (data->map == NULL)
		ft_exit_error(NULL, "0000000001");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		static_ft_exit_from_read(data->map, "00000000001");
	y = 0;
	while (y < numberoflines)
	{
		data->map[y] = ft_gnl(fd);
		if (data->map[y] == NULL)
			ft_exit_error(data, "0000000001");
		ft_replace_char1_with_char2(data->map[y], '\n', '\0');
		y++;
	}
	data->map[numberoflines] = NULL;
	if (close(fd) == -1)
		static_ft_exit_from_read(data->map, "000000000001");
	ft_check_map(data, numberoflines);
}
