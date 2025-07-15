#include "../include/Cub3d.h"

void	check_format(char *file_name)
{
	
}

int main(int ac, char **av)
{
    t_hub *hub;

    if(ac != 2)
    {
        ft_putstr_fd("\033[1;31m🛑 -> ./cub3d map/level.cub \033[0m\n", 2);
        return(0);
    }
    check_format(av[1]);

    return(0);
}