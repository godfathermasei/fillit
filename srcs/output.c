/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:45:41 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/18 12:45:43 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error_open_message(void)
{
	ft_putstr_fd("Can't open this file\n", 2);
}

void	print_error_wrong_pieces_message(void)
{
	ft_putstr_fd("error\n", 1);
}

void	print_usage(void)
{
	ft_putstr_fd("usage: /fillit file_with_tetris_pieces\n", 1);
}

void	print_solved_map(char **map, int map_size)
{
	int i;
	int	j;

	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
		{
			ft_putchar(map[i][j]);
		}
		ft_putchar('\n');
	}
}
