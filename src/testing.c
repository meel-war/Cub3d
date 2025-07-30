/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/30 15:02:02 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		while (j < 32)
		{
			i = 0;
			while (i < 32)
			{
				mlx_pixel_put(hub->mlx, hub->win, x + i, y + j, 0xFF0000);
				i++;
			}
			j++;
		}
	}
	else
	{
		while (j < 32)
		{
			i = 0;
			while (i < 32)
			{
				mlx_pixel_put(hub->mlx, hub->win, x + i, y + j, 0xFF00);
				i++;
			}
			j++;
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
				put_pixel(hub, y * 32, x * 32, 1);
			if (hub->map->map[y][x] == '0' || hub->map->map[y][x] == 'P')
				put_pixel(hub, y * 32, x * 32, 0);
			x++;
		}
		y++;
	}
}

int handle_key(int keycode, t_hub *hub)
{
	if (keycode == KEY_ESC)
		exit(0);
	(void)hub;
	return (0);
}

void minimap(t_hub *hub)
{
	init_minimap(hub);
	mlx_key_hook(hub->win, handle_key, hub);
}
