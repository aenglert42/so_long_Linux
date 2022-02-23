#include "so_long.h"
#include "exit.h"
#include "initialize.h"
#include "map.h"
#include "game.h"

static bool	static_ft_is_valid_filetype(char *filepath, char *filetype)
{
	int		pathlen;
	int		typelen;
	char	*fileending;

	pathlen = strlen(filepath);
	typelen = strlen(filetype);
	fileending = filepath + pathlen - typelen;
	if (!ft_strcmp_n(fileending, filetype, typelen))
		return (true);
	return (false);
}

static void	static_preinitialize_data_struct(t_data *data)
{
	data->imgs[0] = NULL;
	data->mlx = NULL;
	data->win = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*filepath;

	static_preinitialize_data_struct(&data);
	if (argc > 2)
		ft_exit_error(NULL, "01");
	if (argc < 2)
		ft_exit_error(NULL, "001");
	filepath = argv[1];
	if (!static_ft_is_valid_filetype(filepath, ".ber"))
		ft_exit_error(NULL, "000000001");
	ft_read_map(&data, filepath);
	ft_initialize(&data);
	ft_start_game(&data);
	return (EXIT_SUCCESS);
}
