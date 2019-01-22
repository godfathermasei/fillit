/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teterino.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:58:07 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/16 16:58:09 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fill_the_shape(t_teterino *new, char *line)
{
	int		i;
	int		j;
	int		num;

	i = -1;
	num = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (*(line++) == '#')
			{
				new->shape[num][0] = i;
				new->shape[num++][1] = j;
			}
		line++;
	}
}

t_teterino		*create_teterino(char *line)
{
	t_teterino	*new;

	new = (t_teterino*)malloc(sizeof(t_teterino));
	if (!new)
		return (0);
	fill_the_shape(new, line);
	if (!check_shape(new))
	{
		free(new);
		return (0);
	}
	new->next = 0;
	new->letter = 'A';
	return (new);
}

void			move_all_of_shape_to_left_top_corner(t_teterino *head)
{
	int			min;
	t_teterino	*tmp;
	int			i;

	tmp = head;
	while (tmp)
	{
		i = 0;
		min = tmp->shape[i][0];
		while (++i < 4)
			if (min > tmp->shape[i][0])
				min = tmp->shape[i][0];
		i = -1;
		while (++i < 4)
			tmp->shape[i][0] -= min;
		i = 0;
		min = tmp->shape[i][1];
		while (++i < 4)
			if (min > tmp->shape[i][1])
				min = tmp->shape[i][1];
		i = -1;
		while (++i < 4)
			tmp->shape[i][1] -= min;
		tmp = tmp->next;
	}
}

int				add_new_teterino(t_teterino **head, t_teterino *new)
{
	char		let;
	t_teterino	*tmp;

	if (!new)
		return (0);
	let = 'A';
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
		{
			tmp = tmp->next;
			let++;
		}
		tmp->next = new;
		new->letter = let + 1;
	}
	else
	{
		*head = new;
		new->letter = let;
	}
	return (1);
}

void			rm_teterino(t_teterino **head)
{
	t_teterino	*next;

	if (!*head || !head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		free(*head);
		(*head) = next;
	}
}
