/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:28:32 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/23 18:28:38 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_size_of_map(t_teterino *head)
{
	int	i;
	int map_size;

	i = 0;
	map_size = 0;
	while (head && ++map_size < 26)
		head = head->next;
	map_size *= 4;
	while (i * i < map_size)
		i++;
	map_size = i;
	return (map_size);
}

static char	**create_map(int map_size)
{
	char		**map;
	int			i;
	int			j;

	map = (char**)malloc(sizeof(char*) * map_size);
	i = -1;
	while (++i < map_size)
		map[i] = (char*)malloc(sizeof(char) * map_size);
	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
			map[i][j] = '.';
	}
	return (map);
}

static void	delete_map(char ***map, int map_size)
{
	int i;

	if (!*map || !map)
		return ;
	i = -1;
	while (++i < map_size)
		free((*map)[i]);
	free(*map);
}

void		solve(t_teterino *head)
{
	char		**map;
	int			map_size;

	map_size = get_size_of_map(head);
	map = create_map(map_size);
	while (!try_with_this_map(map, head, map_size))
	{
		delete_map(&map, map_size);
		map_size++;
		map = create_map(map_size);
	}
	print_solved_map(map, map_size);
	delete_map(&map, map_size);
}
