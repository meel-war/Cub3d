/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/28 17:06:45 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void stock_map(t_hub *hub, char *file)
{
	int	i;
	int fd;

	fd = open(file, O_RDONLY);
	hub->map->map = malloc(sizeof(char *) * (hub->map->height + 1));
	i = 0;
	while ((hub->map->map[i] = get_next_line(fd)))
	{
		if (!hub->map->map[i])
			break ;
		i++;
	}
	hub->map->map[i] = NULL;
	close(fd);
}

void put_edge(t_hub *hub, int y, int x)
{
	int i = 0;
	int j = 0;
	
	while (i < 64)
	{
		mlx_pixel_put(hub->mlx, hub->win, x + i, y, 0x000000);
		i++;
	}
	while (j < 64)
	{
		mlx_pixel_put(hub->mlx, hub->win, x, y + j, 0x000000);
		j++;
	}
}

void put_character(t_hub *hub, int y, int x)
{
	hub->map->p_x = x / 64;
	hub->map->p_y = y / 64;
	mlx_pixel_put(hub->mlx, hub->win, x + 32, y + 32, 0x000000);
}

void put_pixel(t_hub *hub, int y, int x, int type)
{
	int i;
	int j;

	j = -1;
	if (type == 1)
	{
		while (++j < 64)
		{
			i = -1;
			while (++i < 64)
				mlx_pixel_put(hub->mlx, hub->win, x + i, y + j, 0xFF0000);
		}
	}
	else
	{
		while (++j < 64)
		{
			i = -1;
			while (++i < 64)
				mlx_pixel_put(hub->mlx, hub->win, x + i, y + j, 0xFF00);
		}
	}
	if (hub->map->map[y / 64][x / 64] == 'P')
		put_character(hub, y, x);
	put_edge(hub, y, x);
}

void init_minimap(t_hub *hub)
{
	int y;
	int x;

	y = 0;
	while (hub->map->map[y])
	{
		x = 0;
		while (hub->map->map[y][x])
		{
			if (hub->map->map[y][x] == '1')
				put_pixel(hub, y * 64, x * 64, 1);
			else if (hub->map->map[y][x] == '0' || hub->map->map[y][x] == 'P')
				put_pixel(hub, y * 64, x * 64, 0);
			x++;
		}
		y++;
	}
}

int handle_key(int keycode, t_hub *hub)
{
	if (keycode == KEY_ESC)
		exit(0);
	// if (keycode == KEY_A || keycode == KEY_LEFT)
	// 	movement_left(hub);
	// else if (keycode == KEY_W || keycode == KEY_UP)
	// 	movement_up(hub);
	// else if (keycode == KEY_D || keycode == KEY_RIGHT)
	// 	movement_right(hub);
	// else if (keycode == KEY_S || keycode == KEY_DOWN)
	// 	movement_down(hub);
	return (0);
}

void minimap(t_hub *hub, char *file)
{
	stock_map(hub, file);
	init_minimap(hub);
	mlx_key_hook(hub->win, handle_key, hub);
}