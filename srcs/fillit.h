/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:48:51 by apavlov           #+#    #+#             */
/*   Updated: 2018/11/14 14:50:44 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include "fcntl.h"

typedef struct	s_teterino
{
	int					shape[4][2];
	char				letter;
	struct s_teterino	*next;
}				t_teterino;

void			print_error_open_message(void);
void			print_error_wrong_pieces_message(void);
void			print_usage(void);
void			print_happy_message(void);
void			print_solved_map(char **map, int map_size);

t_teterino		*read_file(int fd);
int				check_shape(t_teterino *teteri);

t_teterino		*create_teterino(char *line);
int				add_new_teterino(t_teterino **head, t_teterino *new);
void			rm_teterino(t_teterino **head);
void			move_all_of_shape_to_left_top_corner(t_teterino *head);
void			solve(t_teterino *head);

int				try_with_this_map(char **map, t_teterino *head, int map_size);

#endif
