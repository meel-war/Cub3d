/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/30 14:56:43 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
			if (hub->map->map[y][x] == '0')
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
