/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/24 17:09:03 by pribolzi         ###   ########.fr       */
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
	close(fd);
}

void put_pixel(t_hub *hub, int y, int x, int type)
{
	int i;
	int j;

	j = 0;
	if (type == 1)
	{
		while (j < 64)
		{
			i = 0;
			while (i < 64)
			{
				mlx_pixel_put(hub->mlx, hub->win, x + i, y + j, 0xFF0000);
				i++;
			}
			j++;
		}
	}
	else
	{
		while (j < 64)
		{
			i = 0;
			while (i < 64)
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
				put_pixel(hub, y * 64, x * 64, 1);
			if (hub->map->map[y][x] == '0')
				put_pixel(hub, y * 64, x * 64, 0);
			x++;
		}
		y++;
	}
}

void minimap(t_hub *hub, char *file)
{
	stock_map(hub, file);
	init_minimap(hub);
}