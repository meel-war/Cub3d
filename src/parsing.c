/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meel-war <meel-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:08:56 by meel-war          #+#    #+#             */
/*   Updated: 2025/07/30 17:17:02 by meel-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_elements(char **map)
{
	int	i;
	int	j;
	int	cardinal;

	cardinal = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'S'
				&& map[j][i] != 'N' && map[j][i] != 'E' && map[j][i] != 'W'
				&& map[j][i] != '\n')
				return (1);
			if (map[j][i] == 'S' || map[j][i] == 'N' || map[j][i] == 'E'
				|| map[j][i] == 'W')
				cardinal++;
			if (cardinal > 1 || cardinal == 0)
				return (2);
			i++;
		}
		j++;
	}
	return (0);
}

void	parse_map(t_hub *hub)
{
	int	error;

	error = 0;
	error = check_elements(hub->map->map);
	
	if (error)
	{
		if (error == 1)
			ft_putstr_fd("Error\nMap: contains unknown element", 2);
		else if (error == 2)
			ft_putstr_fd("Error\nMap: must contain exactly 1 player", 2);
		free_all(hub);
	}
}
