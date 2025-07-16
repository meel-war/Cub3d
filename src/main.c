#include "../include/Cub3d.h"

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

void	check_format(char *file_name)
{
    if(check_dot(file_name))
    {
        ft_putstr_fd("\033[1;31m🛑 -> Wrong map format, it must be .cub \033[0m\n", 2);
        exit(1);
    }
}

int main(int ac, char **av)
{
    t_hub *hub;

    (void)hub;
    if(ac != 2)
    {
        ft_putstr_fd("\033[1;31m🛑 -> ./cub3d map/level.cub \033[0m\n", 2);
        return(1);
    }
    check_format(av[1]);

    return(0);
}