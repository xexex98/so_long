/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_and_pec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:41 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/21 17:50:35 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

t_map	*init_map(t_map *map)
{
	map->ee = 0;
	map->pp = 0;
	map->cc = 0;
	map->i = 0;
	map->j = 0;
	map->columns = 0;
	map->len = 0;
	map->lines = 1;
	map->fd = 0;
	map->line = NULL;
	return (map);
}

void	map_pec_num(char	*line, t_map *map)
{
	while (map->line[map->j])
	{
		if (map->line[map->j] == 'E')
			map->ee++;
		if (map->line[map->j] == 'P')
			map->pp++;
		if (map->line[map->j] == 'C')
			map->cc++;
		map->j++;
	}
	map->j = 0;
	return ;
}

int	map_pec_size(t_map	*map)
{
	if (map->ee < 1 || map->pp != 1 || map->cc < 1)
	{
		ft_putstr("Wrong P, E, C num!");
		return (0);
	}
	if (map->len - 1 == map->lines)
	{
		ft_putstr("Square map!");
		return (0);
	}
	return (1);
}

int	map_checker(char *mapf)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (-1);
	init_map(map);
	map->fd = open(mapf, O_RDONLY);
	if (map->fd < 0)
	{
		ft_putstr("No map file!");
		return (0);
	}
	map->line = get_next_line(map->fd);
	map->len = ft_strlen(map->line);
	map->columns = map->len - 1;
	if (free_map(map, mapf) == 1)
	{
		printf("\n%i", map->columns);
		printf("\n%i", map->lines);
		return (1);
	}
	else
		return (0);
}

int	free_map(t_map *map, char *mapf)
{
	if (map_name(mapf) == 1 && map_top(map->line, map) == 1
		&& map_mid_end(map->line, map) == 1 && map_pec_size(map) == 1)
	{
		free(map);
		close(map->fd);
		return (1);
	}
	else
	{
		close(map->fd);
		free(map);
		return (0);
	}
}