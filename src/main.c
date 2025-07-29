#include "../include/cub3d.h"

int check_cub(char *file_name, char *cub)
{
    int i;

    i = 0;
    while(cub[i])
    {
        if(cub[i] != file_name[i])
            return(1);
        i++;
    }
    if(file_name[i] != '\0')
        return(1);
    return(0);
}

int check_dot(char *file_name)
{
    while(*file_name)
    {
        if(*file_name == '.')
        {
            if(check_cub(file_name, ".cub"))
                return(1);
        }
        file_name++;
    }
    return (0);
}

void	check_format_cub(char *file_name)
{
    if(check_dot(file_name))
    {
        ft_putstr_fd("\033[1;31m🛑ERROR -> Wrong map format, it must be .cub \033[0m\n", 2);
        exit(1);
    }
    if(open(file_name, O_RDONLY) < 0)
    {
        ft_putstr_fd("\033[1;31m🛑ERROR -> file doesn't exist\n\033[0m\n", 2);
        exit(1);
    }
}

void free_all(t_hub *hub)
{
    if(hub->map && hub)
    {
        if(hub->map->color)
            free(hub->map->color);
        free_tab(hub->map->map);
        free(hub->map->E);
        free(hub->map->N);
        free(hub->map->S);
        free(hub->map->W);
        free(hub->map);
    }
    if(hub)
        free(hub);
    exit(0);
}

t_hub *allocate_to_default(void)
{
    t_hub *hub;
    hub = malloc(sizeof(t_hub));
    if(!hub)
        free_all(hub);
    ft_memset(hub, 0, sizeof(t_hub));
    hub->map = malloc(sizeof(t_map));
    if (!hub->map)
        free_all(hub);
    ft_memset(hub->map, 0, sizeof(t_map));
    hub->map->color = malloc(sizeof(t_color));
    if (!hub->map->color)
        free_all(hub);
    ft_memset(hub->map->color, 0, sizeof(t_color));
    return(hub);
}

int main(int ac, char **av)
{
    t_hub *hub;

    if(ac != 2)
    {
        ft_putstr_fd("\033[1;31m🛑ERROR -> ./cub3d map/level.cub \033[0m\n", 2);
        return(1);
    }
    check_format_cub(av[1]);
    hub = allocate_to_default();
	if (!(hub->mlx = mlx_init()))
		return (1);
	if (!(hub->win = mlx_new_window(hub->mlx, 1920, 1080, "cub3d")))
		return (1);
    map_features_init(av[1], hub);
    init_minimap(hub);
	mlx_loop(hub->mlx);
    free_all(hub);
    return(0);
}