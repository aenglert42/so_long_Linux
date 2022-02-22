#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>

# define TILE_SIZE 32
// # define SCREENWIDTH 1280
// # define SCREENHEIGHT 800
# define WINDOWBAR 64
# define COUNTBAR 32
# define PIXELLIMIT 3
# define EXIT_PATH "./img/exit.xpm"
# define LOOT_PATH "./img/poo32x32.xpm"
# define PLAYER_PATH "./img/fly_right32x32.xpm"
# define PLAYER_L_PATH "./img/fly_left32x32.xpm"
# define SPACE_PATH "./img/space.xpm"
# define WALL_PATH "./img/wall.xpm"
# define BLACK_PATH "./img/black.xpm"
# define ENEMY_PATH "./img/sperm32x32.xpm"

typedef enum e_timer
{
	ON = -1,
	OFF = -2,
}	t_timer;

typedef enum e_x11events
{
	KeyPress = 2,
	DestroyNotify = 17,
}	t_x11events;

typedef enum e_x11masks
{
	KeyPressMask = 1L << 0,
	StructureNotifyMask = 1L << 17,
}	t_x11masks;

typedef enum e_key
{
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	ESC_KEY = 65307,
}	t_key;

typedef enum e_map
{
	WALL = '1',
	LOOT = 'C',
	SPACE = '0',
	START = 'P',
	EXIT = 'E',
}	t_map;

typedef enum e_imgnr
{
	PLAYER_IMAGE,
	SPACE_IMAGE,
	WALL_IMAGE,
	LOOT_IMAGE,
	EXIT_IMAGE,
	PLAYER_L_IMAGE,
	BLACK_IMAGE,
	ENEMY_IMAGE,
	IMAGES,
}	t_imgnr;

typedef enum e_color
{
	RED = 0x00FF0000,
	ORANGE = 0x00FF8000,
	YELLOW = 0x00FFFF00,
	GREEN = 0x0000FF00,
	CYAN = 0x0000FFFF,
	BLUE = 0x000000FF,
	MAGENTA = 0x00FF00FF,
	BLACK = 0x00000000,
	GREY = 0x00808080,
	WHITE = 0x00FFFFFF,
}	t_color;

typedef struct s_img
{
	void	*img;
	int		iwidth;
	int		iheight;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

// typedef struct s_rand
// {
// 	unsigned int	number;
// 	unsigned char	modifier;
// }				t_rand;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		sheight;
	int		swidth;
	int		wheight;
	int		wwidth;
	int		mheight;
	int		mwidth;
	t_img	*imgs[IMAGES];
	int		img_size;
	int		p_x;
	int		p_y;
	int		p_side;
	int		move_count;
	char	*move_count_str;
	int		loot_count;
	int		e_x;
	int		e_y;
	bool	e_status;
	unsigned int	rand;
	int		timer;
}	t_data;

#endif