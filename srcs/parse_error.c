
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:58:44 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/21 20:52:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_ant(t_lem *l)// OK
{
	next_line(&*l);
	parse_comment(&*l);
	if (l->f & 0xFFFFFFFE || !(ft_isnumber(l->s, ft_strlen(l->s))))
		ft_error_info(INFO, "ant_error");
	if (!(l->ant = ft_atoi(l->s)))
		ft_error_info(INFO, "no_ant");
	return (1);
}

int		check_room(t_lem *l)
{
	int i;
	i = 0;
	next_line(&*l);
	while (!ft_strchr(l->s, '-'))
	{
		parse_comment(&*l);
		if (ft_strchr(l->s, '-'))
			break;
		if (l->s[0] == 'L')
			next_line(&*l);
		else if (search_sharp(l))
		{
			next_line(&*l);
		}
		else if (!room_count_word(l->s, ' '))
		{
			ft_error_info(INFO, l->s);
		}
		parse_room(&*l, 0);
		next_line(&*l);
	}
	return (1);
}

int		check_pipe(t_lem *l)
{
	// int i = 0;
	while (ft_strchr(l->s, '-'))
	{
		// printf("%d)%s\n", i++, l->s);
		parse_comment(&*l);
		if (ft_count_word(l->s, '-') != 2 || ft_strchr(l->s, ' '))
			ft_error_info(INFO, "pipe_error");
		parse_pipe(&*l);
		next_line(&*l);
		// printf("OO%s\n", l->s)s;
		printf("Xx\n%s\nxX\n", l->map);
	}
	return (1);
}

void	malloc_ptr_pipe(t_lem *l)
{
	t_room		*tmp;

	tmp = *l->room_list;
	while (tmp)
	{
		tmp->pipe = malloc(sizeof(void*) * l->nb_room);
		ft_bzero(tmp->pipe, sizeof(void*));
		tmp = tmp->next;
	}
}

void	check_error(t_lem *l)
{	
	check_ant(&*l) ? l->f += ANT : 0;
	check_room(&*l);
	printf("%s\n", l->map);
	ft_test_room_list(l->room_list);
	malloc_ptr_pipe(&*l);
	printf("%s\n", l->map);
	check_pipe(&*l);
	ft_test_room_pipe(l->room_list);
	ft_error_info(INFO, "END_PARSING_ERROR !");
}
