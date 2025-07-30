#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_color
{
    int f_r;
    int f_g;
    int f_b;
    int c_r;
    int c_g;
    int c_b;
}       t_color;

typedef struct s_map
{
    char **map;
    char *N;
    char *S;
    char *W;
    char *E;
	int	p_x;
	int p_y;
	int height;
    t_color *color;
}       t_map;

typedef struct s_hub
{
    void *mlx;
    void *win;
    void *img;
    t_map *map;
}              t_hub;

void	map_features_init(char *file_name, t_hub *hub);
void 	get_height(char *file_name, t_hub *hub);
void init_minimap(t_hub *hub);
void stock_map(char *file_name, t_hub *hub);

#endif