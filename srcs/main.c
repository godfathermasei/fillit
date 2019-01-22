/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:56:22 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/16 16:00:13 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_teterino	*all_pieces;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
		{
			print_error_open_message();
			return (0);
		}
		all_pieces = read_file(fd);
		if (!all_pieces)
		{
			print_error_wrong_pieces_message();
			return (0);
		}
		move_all_of_shape_to_left_top_corner(all_pieces);
		solve(all_pieces);
		rm_teterino(&all_pieces);
	}
	else
		print_usage();
	return (0);
}
