/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:45:52 by pribolzi          #+#    #+#             */
/*   Updated: 2025/07/30 16:21:10 by pribolzi         ###   ########.fr       */
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

void print_character(t_hub *hub)
{
	int pixel_x = (int)(hub->hero->p_x * 64);
	int pixel_y = (int)(hub->hero->p_y * 64);

	printf("%f %f\n", hub->hero->p_x, hub->hero->p_y);
	mlx_pixel_put(hub->mlx, hub->win, pixel_x, pixel_y, 0x000000);
	mlx_pixel_put(hub->mlx, hub->win, pixel_x + 1, pixel_y, 0x000000);
	mlx_pixel_put(hub->mlx, hub->win, pixel_x - 1, pixel_y, 0x000000);
	mlx_pixel_put(hub->mlx, hub->win, pixel_x, pixel_y + 1, 0x000000);
	mlx_pixel_put(hub->mlx, hub->win, pixel_x, pixel_y - 1, 0x000000);
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
	put_edge(hub, y, x);
}

void update_minimap(t_hub *hub)
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

void print_minimap(t_hub *hub)
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
			if (hub->map->map[y][x] == 'P')
			{
				hub->hero->p_x = x + 0.5f;
				hub->hero->p_y = y + 0.5f;
				print_character(hub);
			}
			x++;
		}
		y++;
	}
}

int check_collision(t_hub *hub, float f_x, float f_y)
{
	int x = (int)(f_x);
	int y = (int)(f_y);

	if (hub->map->map[y][x] == '1')
		return (1);
	return (0);
}

int handle_key(int keycode, t_hub *hub)
{
	if (keycode == KEY_ESC)
		free_all(hub);
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (!check_collision(hub, hub->hero->p_x - MV_SPEED, hub->hero->p_y))
			hub->hero->p_x -= MV_SPEED;
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (!check_collision(hub, hub->hero->p_x, hub->hero->p_y - MV_SPEED))
			hub->hero->p_y -= MV_SPEED;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (!check_collision(hub, hub->hero->p_x + MV_SPEED, hub->hero->p_y))
			hub->hero->p_x += MV_SPEED;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (!check_collision(hub, hub->hero->p_x, hub->hero->p_y + MV_SPEED))
			hub->hero->p_y += MV_SPEED;
	}
	update_minimap(hub);
	print_character(hub);
	return (0);
}

void minimap(t_hub *hub)
{
	print_minimap(hub);
	mlx_key_hook(hub->win, handle_key, hub);
}
