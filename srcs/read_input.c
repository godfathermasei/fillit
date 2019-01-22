/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:12:18 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/16 16:12:21 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			count_boards(t_teterino *teteri, int x, int y)
{
	int res;
	int i;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		if (ft_int_abs(x - teteri->shape[i][0])\
			+ ft_int_abs(y - teteri->shape[i][1]) == 1)
			res++;
	}
	return (res);
}

int					check_shape(t_teterino *teteri)
{
	int i;
	int count_b;

	i = -1;
	count_b = 0;
	while (++i < 4)
		count_b += count_boards(teteri, teteri->shape[i][0],\
			teteri->shape[i][1]);
	if (count_b < 6)
		return (0);
	return (1);
}

static int			check_input(char *line, int ret)
{
	int i;
	int count;

	count = 0;
	if (ret != 21 && ret != 20)
		return (0);
	while (*line && *line != '\n')
	{
		i = -1;
		while (++i < 4)
		{
			if (*line != '.' && *line != '#')
				return (0);
			if (*(line++) == '#')
				count++;
		}
		if (*(line++) != '\n')
			return (0);
	}
	if (count != 4)
		return (0);
	return (1);
}

static t_teterino	*remove_teterino(t_teterino **head)
{
	rm_teterino(head);
	return (0);
}

t_teterino			*read_file(int fd)
{
	char		buff[22];
	int			ret;
	int			count_pieces;
	t_teterino	*head;
	int			last_ret;

	count_pieces = -1;
	head = 0;
	while ((ret = read(fd, buff, 21)) && (++count_pieces < 26))
	{
		buff[ret] = '\0';
		if (!check_input(buff, ret))
			return (remove_teterino(&head));
		if (!add_new_teterino(&head, create_teterino(buff)))
			return (remove_teterino(&head));
		last_ret = ret;
	}
	if (last_ret != 20)
		return (remove_teterino(&head));
	return (head);
}
