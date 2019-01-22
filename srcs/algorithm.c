/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:55:28 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/24 15:55:30 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_placeable(char **map, t_teterino *t, int m_s, int i[2])
{
	int x;

	x = -1;
	if (!map || !t)
		return (0);
	while (++x < 4)
	{
		if ((t->shape[x][0] + i[0] < m_s) && (t->shape[x][1] + i[1] < m_s))
		{
			if (map[t->shape[x][0] + i[0]][t->shape[x][1] + i[1]] != '.')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

static void	delete_teterino_from_map(char **map, t_teterino *teteri,\
	int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map[teteri->shape[i][0] + x][teteri->shape[i][1] + y] = '.';
}

static void	place_teterino(char **map, t_teterino *teteri, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 4)
		map[teteri->shape[i][0] + x][teteri->shape[i][1] + y] = teteri->letter;
}

int			try_with_this_map(char **map, t_teterino *head, int map_size)
{
	int		i[2];

	if (!head)
		return (1);
	i[0] = -1;
	while (++i[0] < map_size)
	{
		i[1] = -1;
		while (++i[1] < map_size)
			if (is_placeable(map, head, map_size, i))
			{
				place_teterino(map, head, i[0], i[1]);
				if (try_with_this_map(map, head->next, map_size))
					return (1);
				else
					delete_teterino_from_map(map, head, i[0], i[1]);
			}
	}
	return (0);
}
