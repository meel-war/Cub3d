/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meel-war <meel-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:36:11 by meel-war          #+#    #+#             */
/*   Updated: 2025/07/29 15:40:32 by meel-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int is_empty_line(char *line)
{
	int flag;

	flag = 1;
	while(*line)
	{
		if(!ft_isspace(*line))
			return(0);
		line++;
	}
	return(1);
}

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
		else if(!ft_strncmp(line, "SO", 2))
			 hub->map->S = ft_strdup(line + 3);
		else if(!ft_strncmp(line, "WE", 2))
			 hub->map->W = ft_strdup(line + 3);
		if(!ft_strncmp(line, "EA", 2))
			 hub->map->E = ft_strdup(line + 3);
		 else if(!ft_strncmp(line, "F", 1))
		{
			color_v = ft_split(line + 2, ',');
			hub->map->color->f_r = ft_atoi(color_v[0]);
			hub->map->color->f_g = ft_atoi(color_v[1]);
			hub->map->color->f_b = ft_atoi(color_v[2]);
			free_tab(color_v);
		}
		else if(!ft_strncmp(line, "C", 1))
		{
			color_v = ft_split(line + 2, ',');
			hub->map->color->c_r = ft_atoi(color_v[0]);
			hub->map->color->c_g = ft_atoi(color_v[1]);
			hub->map->color->c_b = ft_atoi(color_v[2]);
			free_tab(color_v);
		}
		free(line);
	}
	close(fd_file);
	get_height(file_name, hub);
	stock_map(file_name, hub);
}

int is_config_line(char *line)
{
	while(*line && ft_isspace(*line))
		line++;
	if(!ft_strncmp(line, "NO", 2))
		return(1);
	if(!ft_strncmp(line, "SO", 2))
		return(1);
	if(!ft_strncmp(line, "WE", 2))
		return(1);
	if(!ft_strncmp(line, "EA", 2))
		return(1);
	if(*line == 'C')
		return(1);
	if(*line == 'F')
		return(1);
	return(0);
}

void get_height(char *file_name, t_hub *hub)
{
	char *line;
	int fd_file;
	int i;
	int in_map;

	i = 0;
	fd_file = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd_file)))
	{
		i = 0;
		in_map = 0;
		while(line[i] && ft_isspace(line[i]))
			i++;
		if(!in_map && !is_config_line(line + i) && *line != '\0')
			in_map = 1;
		if(in_map && !is_empty_line(line) && *line != '\0')
			hub->map->height++;
		free(line);
	}
	close(fd_file);
}

void stock_map(char *file_name, t_hub *hub)
{
	char *line;
	int fd_file;
	int i;
	int in_map;
	int j;
	
	j = 0;
	fd_file = open(file_name, O_RDONLY);
	hub->map->map = malloc(sizeof(char *) * (hub->map->height + 1));
	if(!hub->map->map)
		exit(1);
	while ((line = get_next_line(fd_file)))
	{
		i = 0;
		in_map = 0;
		while(line[i] && ft_isspace(line[i]))
			i++;
		if(!in_map && !is_config_line(line + i) && *line != '\0')
			in_map = 1;
		if(in_map && !is_empty_line(line) && *line != '\0')
			hub->map->map[j++] = ft_strdup(line);
		free(line);
	}
	close(fd_file);
}
