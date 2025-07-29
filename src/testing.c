/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meel-war <meel-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/29 15:41:16 by meel-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void put_pixel(t_hub *hub, int y, int x, int type)
{
	int i;
	int j;

	j = 0;
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