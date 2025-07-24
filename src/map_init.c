/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meel-war <meel-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:36:11 by meel-war          #+#    #+#             */
/*   Updated: 2025/07/23 18:51:30 by meel-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_features_init(char *file_name, t_hub *hub)
{
	int fd_file;
	char *line;
	char **color_v;
	
	fd_file = open(file_name, O_RDONLY);
	while((line = get_next_line(fd_file)))
	{
		color_v = NULL;
		if(!ft_strncmp(line, "NO", 2))
			 hub->map->N = ft_strdup(line + 3);
		if(!ft_strncmp(line, "SO", 2))
			 hub->map->S = ft_strdup(line + 3);
		if(!ft_strncmp(line, "WE", 2))
			 hub->map->W = ft_strdup(line + 3);
		if(!ft_strncmp(line, "EA", 2))
			 hub->map->E = ft_strdup(line + 3);
		if(!ft_strncmp(line, "F", 1))
		{
			color_v = ft_split(line + 2, ',');
			hub->map->color->f_r = ft_atoi(color_v[0]);
			hub->map->color->f_g = ft_atoi(color_v[1]);
			hub->map->color->f_b = ft_atoi(color_v[2]);
		}
		if(!ft_strncmp(line, "C", 1))
		{
			color_v = ft_split(line + 2, ',');
			hub->map->color->c_r = ft_atoi(color_v[0]);
			hub->map->color->c_g = ft_atoi(color_v[1]);
			hub->map->color->c_b = ft_atoi(color_v[2]);
		}
		free(line);
		if(color_v)
			free_tab(color_v);
	}
	ft_printf("NORD: %s\nSUD: %s\nOUEST: %s\nEST: %s\nCeiling: %d %d %d\n\nFloor: %d %d %d", hub->map->N, hub->map->S, hub->map->W, hub->map->E, hub->map->color->f_r, hub->map->color->f_g, hub->map->color->f_b, hub->map->color->c_r, hub->map->color->c_g, hub->map->color->c_b);
}

// void get_height(char *file_name, t_hub *hub)
// {
// 	char *line;
// 	int fd_file;
// 	int flag = 0;
// 	int i;

// 	fd_file = open(file_name, O_RDONLY);
// 	// while(line = get_next_line(fd_file))
// 	// {
// 	// 	if(line[i])
// 	// }
// }
